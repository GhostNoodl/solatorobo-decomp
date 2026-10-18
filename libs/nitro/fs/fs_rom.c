#include "fs_private.h"

#pragma force_active on

typedef FSResult (*FS_ARCHIVE_READ_FUNC)(FSArchive *, void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *, const void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(FSFile *, FSCommandType);
typedef void (*MIDmaCallback)(void *);

typedef struct CARDRomRegion {
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct FSiRomStatics {
    u32 default_dma_no;
    u32 card_lock_id;
} FSiRomStatics;

extern FSiRomStatics data_0208eaa0;
extern FSArchive data_0208eaa8;
extern BOOL data_0208eb04;
extern const char data_0208af48[];
extern const char data_0208af4c[];

#define FS_RESULT_PERMISSION_DENIED 9
#define FS_ARCHIVE_PROC_WRITEFILE      (1 << FS_COMMAND_WRITEFILE)
#define FS_ARCHIVE_PROC_OPENFILEDIRECT (1 << FS_COMMAND_OPENFILEDIRECT)
#define FS_ARCHIVE_PROC_ACTIVATE       (1 << FS_COMMAND_ACTIVATE)
#define FS_ARCHIVE_PROC_IDLE           (1 << FS_COMMAND_IDLE)

const void *CARD_GetOwnRomHeader(void);
void CARD_Init(void);
void CARD_LockRom(u16 lock_id);
void CARD_UnlockRom(u16 lock_id);
BOOL CARD_IsPulledOut(void);
void func_0200d6d4(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL is_async);
s32 OS_GetLockID(void);
int STD_CompareString(const char *a, const char *b);
void FS_InitArchive(FSArchive *arc);
BOOL FS_RegisterArchiveName(FSArchive *arc, const char *name, u32 name_len);
void FS_NotifyArchiveAsyncEnd(FSArchive *arc, FSResult ret);
BOOL FS_SetCurrentDirectory(const char *path);
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
void FS_SetArchiveProc(FSArchive *arc, FS_ARCHIVE_PROC_FUNC proc, u32 flags);
BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);
u32 FS_LoadArchiveTables(FSArchive *p_arc, void *p_mem, u32 max_size);
void func_0200f180(void);

static inline const CARDRomRegion *CARD_GetRomRegionFNT(void) {
    return (const CARDRomRegion *)((const u8 *)CARD_GetOwnRomHeader() + 0x40);
}

static inline const CARDRomRegion *CARD_GetRomRegionFAT(void) {
    return (const CARDRomRegion *)((const u8 *)CARD_GetOwnRomHeader() + 0x48);
}

BOOL FSi_IsUnreadableRomOffset(FSArchive *arc, u32 offset) {
    BOOL ret = FALSE;
    if ((STD_CompareString(FS_GetArchiveName(arc), data_0208af48) == 0) && !OS_IsRunOnTwl()) {
        const u8 *header = (const u8 *)CARD_GetOwnRomHeader();
        if (offset >= (*(const u16 *)(header + 0x92) << 19)) {
            ret = TRUE;
        }
    }
    return ret;
}

void FSi_OnRomReadDone(void *arc) {
    FS_NotifyArchiveAsyncEnd((FSArchive *)arc, CARD_IsPulledOut() ? FS_RESULT_ERROR : FS_RESULT_SUCCESS);
}

FSResult FSi_ReadRomCallback(FSArchive *arc, void *buffer, u32 offset, u32 length) {
    func_0200d6d4(data_0208eaa0.default_dma_no, (const void *)offset, buffer, length, FSi_OnRomReadDone, arc, TRUE);
    return FS_RESULT_PROC_ASYNC;
}

FSResult FSi_RomArchiveProc(FSFile *file, FSCommandType cmd) {
    switch (cmd) {
    case FS_COMMAND_ACTIVATE:
        CARD_LockRom((u16)data_0208eaa0.card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_IDLE:
        CARD_UnlockRom((u16)data_0208eaa0.card_lock_id);
        return FS_RESULT_SUCCESS;
    case FS_COMMAND_OPENFILEDIRECT:
        if (FSi_IsUnreadableRomOffset(file->arc, file->arg.words[0])) {
            return FS_RESULT_PERMISSION_DENIED;
        }
        return FS_RESULT_PROC_DEFAULT;
    case FS_COMMAND_WRITEFILE:
        return FS_RESULT_UNSUPPORTED;
    case FS_COMMAND_READFILE:
    case FS_COMMAND_SEEKDIR:
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}

FSResult func_0201100c(FSFile *file, FSCommandType cmd) {
    (void)file;
    switch (cmd) {
    case FS_COMMAND_WRITEFILE:
        return FS_RESULT_UNSUPPORTED;
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}

FSResult FSi_ReadDummyCallback(FSArchive *arc, void *buffer, u32 offset, u32 length) {
    (void)arc;
    (void)buffer;
    (void)offset;
    (void)length;
    return FS_RESULT_UNSUPPORTED;
}

FSResult FSi_WriteDummyCallback(FSArchive *arc, const void *buffer, u32 offset, u32 length) {
    (void)arc;
    (void)buffer;
    (void)offset;
    (void)length;
    return FS_RESULT_UNSUPPORTED;
}

BOOL func_02011030(FSArchive *arc) {
    (void)arc;
    return FALSE;
}

void FSi_InitRomArchive(u32 default_dma_no) {
    CARD_Init();
    data_0208eaa0.default_dma_no = default_dma_no;
    data_0208eaa0.card_lock_id = (u32)OS_GetLockID();
    FS_InitArchive(&data_0208eaa8);
    (void)FS_RegisterArchiveName(&data_0208eaa8, data_0208af48, 3);
    if (OS_GetBootType() == 1) {
        const CARDRomRegion *fnt = CARD_GetRomRegionFNT();
        const CARDRomRegion *fat = CARD_GetRomRegionFAT();
        FS_SetArchiveProc(&data_0208eaa8, FSi_RomArchiveProc,
                      FS_ARCHIVE_PROC_WRITEFILE | FS_ARCHIVE_PROC_ACTIVATE | FS_ARCHIVE_PROC_IDLE | FS_ARCHIVE_PROC_OPENFILEDIRECT);
        if ((fnt->offset != 0xFFFFFFFF) && (fnt->offset != 0) && (fat->offset != 0xFFFFFFFF) && (fat->offset != 0)) {
            (void)FS_LoadArchive(&data_0208eaa8, 0, fat->offset, fat->length, fnt->offset, fnt->length, FSi_ReadRomCallback, NULL);
        }
    } else {
        (void)func_02011030(&data_0208eaa8);
    }
    if (!FS_IsArchiveLoaded(&data_0208eaa8)) {
        FS_SetArchiveProc(&data_0208eaa8, func_0201100c, (u32)~0);
        (void)FS_LoadArchive(&data_0208eaa8, 0, 0, 0, 0, 0, FSi_ReadDummyCallback, FSi_WriteDummyCallback);
    }
    (void)FS_SetCurrentDirectory(data_0208af4c);
}

u32 FS_TryLoadTable(void *p_mem, u32 max_size) {
    return FS_LoadArchiveTables(&data_0208eaa8, p_mem, max_size);
}

BOOL FS_CreateFileFromRom(FSFile *file, u32 offset, u32 size) {
    return FS_OpenFileDirect(file, &data_0208eaa8, offset, offset + size, 0xFFFF);
}

void FS_Init(u32 default_dma_no) {
    if (!data_0208eb04) {
        data_0208eb04 = TRUE;
        FSi_InitRomArchive(default_dma_no);
        func_0200f180();
    }
}

BOOL FS_IsAvailable(void) {
    return data_0208eb04;
}
