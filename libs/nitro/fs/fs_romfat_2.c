#include "fs_private.h"

#pragma force_active on

typedef struct FSROMFATArchiveContext {
    u32 base;                   // 0x00
    u32 fat;                    // 0x04
    u32 fat_size;               // 0x08
    u32 fnt;                    // 0x0c
    u32 fnt_size;               // 0x10
    u32 fat_bak;                // 0x14
    u32 fnt_bak;                // 0x18
    void *load_mem;             // 0x1c
    FSResult (*read_func)(FSArchive *, void *, u32, u32);        // 0x20
    FSResult (*write_func)(FSArchive *, const void *, u32, u32); // 0x24
    FSResult (*table_func)(FSArchive *, void *, u32, u32);       // 0x28
    FSResult (*proc)(FSFile *, FSCommandType);                   // 0x2c
    u32 proc_flag;              // 0x30
} FSROMFATArchiveContext;

typedef struct FSArchiveResourceEx {
    u64 totalSize;
    u64 availableSize;
    u32 maxFileHandles;
    u32 currentFileHandles;
    u32 maxDirectoryHandles;
    u32 currentDirectoryHandles;
    u32 bytesPerSector;
    u32 sectorsPerCluster;
    u32 totalClusters;
    u32 availableClusters;
} FSArchiveResourceEx;

typedef FSResult (*FS_ARCHIVE_READ_FUNC)(FSArchive *, void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *, const void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(FSFile *, FSCommandType);

#define CONTEXT(arc) ((FSROMFATArchiveContext *)(arc)->userdata)
extern const FSArchiveInterface FSiArchiveRomFatInterface; // fs_romfat_rodata.c

const void *CARD_GetRomHeader(void);
BOOL FS_MountArchive(FSArchive *arc, void *userdata, const FSArchiveInterface *vtbl);
BOOL FS_SuspendArchive(FSArchive *arc);
BOOL FS_ResumeArchive(FSArchive *arc);
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
BOOL FS_CloseFile(FSFile *file);
int FS_ReadFile(FSFile *file, void *dst, int len);
FSResult FSi_ROMFAT_GetFileLength(FSArchive *arc, FSFile *file, u32 *length);
FSResult FSi_ROMFAT_GetFilePosition(FSArchive *arc, FSFile *file, u32 *position);
u32 func_02010cc0(const FSArchive *arc, u32 pos);
BOOL FS_IsArchiveTableLoaded(volatile const FSArchive *arc);
void *FS_UnloadArchiveTables(FSArchive *arc);

FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResourceEx *resource) {
    const u8 *header = (const u8 *)CARD_GetRomHeader();
    resource->bytesPerSector = 0;
    resource->sectorsPerCluster = 0;
    resource->totalClusters = 0;
    resource->availableClusters = 0;
    resource->totalSize = *(const u32 *)(header + 0x80);
    resource->availableSize = 0;
    resource->maxFileHandles = 0x7FFFFFFF;
    resource->currentFileHandles = 0;
    resource->maxDirectoryHandles = 0x7FFFFFFF;
    resource->currentDirectoryHandles = 0;
    (void)arc;
    return FS_RESULT_SUCCESS;
}

FSResult FSi_ReadMemCallback(FSArchive *arc, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8((const void *)func_02010cc0(arc, pos), dst, size);
    return FS_RESULT_SUCCESS;
}

FSResult FSi_WriteMemCallback(FSArchive *arc, const void *src, u32 pos, u32 size) {
    MI_CpuCopy8(src, (void *)func_02010cc0(arc, pos), size);
    return FS_RESULT_SUCCESS;
}

BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func) {
    FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->reserved;
    context->base = base;
    context->fat_size = fat_size;
    context->fat = fat;
    context->fat_bak = fat;
    context->fnt_size = fnt_size;
    context->fnt = fnt;
    context->fnt_bak = fnt;
    context->read_func = read_func ? read_func : FSi_ReadMemCallback;
    context->write_func = write_func ? write_func : FSi_WriteMemCallback;
    context->load_mem = NULL;
    return FS_MountArchive(arc, context, &FSiArchiveRomFatInterface);
}

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length) {
    return (file->arc->vtbl == &FSiArchiveRomFatInterface) &&
           (FSi_ROMFAT_GetFileLength(file->arc, file, length) == FS_RESULT_SUCCESS);
}

BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *length) {
    return (file->arc->vtbl == &FSiArchiveRomFatInterface) &&
           (FSi_ROMFAT_GetFilePosition(file->arc, file, length) == FS_RESULT_SUCCESS);
}

void FS_SetArchiveProc(FSArchive *arc, FS_ARCHIVE_PROC_FUNC proc, u32 flags) {
    FSROMFATArchiveContext *context = (FSROMFATArchiveContext *)arc->reserved;
    if (!flags) {
        proc = NULL;
    } else if (!proc) {
        flags = 0;
    }
    context->proc = proc;
    context->proc_flag = flags;
}

u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size) {
    FSROMFATArchiveContext *context;
    u32 total_size;
    if ((p_mem != NULL) && FS_IsArchiveTableLoaded(p_arc)) {
        (void)FS_UnloadArchiveTables(p_arc);
    }
    context = CONTEXT(p_arc);
    total_size = (context->fat_size + context->fnt_size + 32 + 31) & ~31;
    if (total_size <= max_size) {
        u8 *p_cache = (u8 *)(((u32)p_mem + 31) & ~31);
        FSFile tmp;
        FS_InitFile(&tmp);
        if (FS_OpenFileDirect(&tmp, p_arc, context->fat, context->fat + context->fat_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (int)context->fat_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fat_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fat = (u32)p_cache;
        p_cache += context->fat_size;
        if (FS_OpenFileDirect(&tmp, p_arc, context->fnt, context->fnt + context->fnt_size, (u32)~0)) {
            if (FS_ReadFile(&tmp, p_cache, (int)context->fnt_size) < 0) {
                MI_CpuFill8(p_cache, 0x00, context->fnt_size);
            }
            (void)FS_CloseFile(&tmp);
        }
        context->fnt = (u32)p_cache;
        context->load_mem = p_mem;
        p_arc->flag |= FS_ARCHIVE_FLAG_TABLE_LOAD;
    }
    return total_size;
}

void *FS_UnloadArchiveTables(FSArchive *p_arc) {
    void *ret = NULL;
    if (FS_IsArchiveLoaded(p_arc)) {
        FSROMFATArchiveContext *context = CONTEXT(p_arc);
        BOOL bak_stat = FS_SuspendArchive(p_arc);
        if (FS_IsArchiveTableLoaded(p_arc)) {
            p_arc->flag &= ~FS_ARCHIVE_FLAG_TABLE_LOAD;
            ret = context->load_mem;
            context->fat = context->fat_bak;
            context->fnt = context->fnt_bak;
            context->load_mem = NULL;
        }
        if (bak_stat) {
            (void)FS_ResumeArchive(p_arc);
        }
    }
    return ret;
}

u32 func_02010cc0(const FSArchive *arc, u32 pos) {
    return CONTEXT(arc)->base + pos;
}

BOOL FS_IsArchiveTableLoaded(volatile const FSArchive *arc) {
    return (arc->flag & FS_ARCHIVE_FLAG_TABLE_LOAD) ? TRUE : FALSE;
}

u32 FS_GetFileImageTop(const FSFile *file) {
    return file->prop.file.top;
}
