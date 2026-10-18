#include "fs_private.h"

#pragma force_active on

typedef struct FSDirEntry {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry;

typedef struct FSROMFATArgReadDir {
    FSDirEntry *p_entry;
    BOOL skip_string;
} FSROMFATArgReadDir;

typedef FSResult (*FS_ARCHIVE_READ_FUNC)(FSArchive *, void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *, const void *, u32, u32);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(FSFile *, FSCommandType);

extern BOOL data_0208ea40;
extern FSArchive data_0208ea44;
extern const char data_0208af44[];

int STD_TSPrintf(char *dst, const char *fmt, ...);
void FS_InitArchive(FSArchive *arc);
BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);
void FS_SetArchiveProc(FSArchive *arc, FS_ARCHIVE_PROC_FUNC proc, u32 flags);
BOOL FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size, FS_ARCHIVE_READ_FUNC read_func, FS_ARCHIVE_WRITE_FUNC write_func);

FSResult func_02010cec(FSFile *file, FSCommandType cmd) {
    switch (cmd) {
    case FS_COMMAND_READDIR: {
        FSDirEntry *entry = ((FSROMFATArgReadDir *)&file->arg)->p_entry;
        FSArchive *arc = (FSArchive *)file->prop.dir.pos.pos;
        if (!arc) {
            entry->name_len = 0;
            entry->is_directory = 0;
            return FS_RESULT_FAILURE;
        } else {
            const char *name = FS_GetArchiveName(arc);
            entry->name_len = (u32)STD_GetStringLength(name) + 1;
            entry->is_directory = 1;
            if (!((FSROMFATArgReadDir *)&file->arg)->skip_string) {
                (void)STD_TSPrintf(entry->name, data_0208af44, name);
                entry->dir_id.arc = file->arc;
                entry->dir_id.own_id = 0;
                entry->dir_id.index = 0;
                entry->dir_id.pos = 0;
            }
            file->prop.dir.pos.pos = (u32)arc->next;
            return FS_RESULT_SUCCESS;
        }
    }
    case FS_COMMAND_SEEKDIR:
    case FS_COMMAND_FINDPATH:
    case FS_COMMAND_GETPATH:
    case FS_COMMAND_OPENFILEFAST:
        return FS_RESULT_UNSUPPORTED;
    default:
        return FS_RESULT_PROC_UNKNOWN;
    }
}

void func_02010db8(void) {
    OSIntrMode bak = OS_DisableInterrupts();
    if (!data_0208ea40 || !FS_IsArchiveLoaded(&data_0208ea44)) {
        FS_InitArchive(&data_0208ea44);
        FS_SetArchiveProc(&data_0208ea44, func_02010cec, (u32)~0);
        if (!FS_LoadArchive(&data_0208ea44, 0, 0, 0, 0, 0, NULL, NULL)) {
            OS_Terminate();
        }
        data_0208ea40 = TRUE;
    }
    (void)OS_RestoreInterrupts(bak);
}

BOOL FS_CreateFileFromMemory(FSFile *file, void *buf, u32 size) {
    func_02010db8();
    return FS_OpenFileDirect(file, &data_0208ea44, (u32)buf, (u32)buf + size, 0);
}
