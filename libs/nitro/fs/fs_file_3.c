#include "fs_private.h"

#pragma force_active on

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);

BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode);
u32 FS_GetFileLength(FSFile *file);
u32 FS_GetFilePosition(FSFile *file);

BOOL FS_OpenFile(FSFile *file, const char *path) {
    return FS_OpenFileEx(file, path, 1);
}

u32 FS_GetLength(FSFile *file) {
    return FS_GetFileLength(file);
}

u32 FS_GetPosition(FSFile *file) {
    return FS_GetFilePosition(file);
}
