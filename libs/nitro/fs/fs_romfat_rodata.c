// fs_romfat.c's read-only tables: the command table FSi_ROMFAT_TranslateCommand dispatches the
// synchronous FS commands through, and the archive interface FS_LoadArchive mounts the ROM archive
// with (its unused slots are NULL). Both are made of symbol references; written as asm blocks so
// they land in main's .text with the other read-only data (see libs/msl/ctype.c).

#include "fs_private.h"

// Defined in fs_romfat.c / fs_romfat_2.c; only pointers to them are needed here.
typedef struct FSDirectoryEntryInfo FSDirectoryEntryInfo;
typedef struct FSPathInfo FSPathInfo;
typedef struct FSArchiveResourceEx FSArchiveResourceEx;

FSResult FSi_ReadFileCommand(FSFile *file);
FSResult FSi_WriteFileCommand(FSFile *file);
FSResult FSi_SeekDirCommand(FSFile *file);
FSResult FSi_ReadDirCommand(FSFile *file);
FSResult FSi_FindPathCommand(FSFile *p_dir);
FSResult FSi_GetPathCommand(FSFile *file);
FSResult FSi_OpenFileFastCommand(FSFile *file);
FSResult FSi_OpenFileDirectCommand(FSFile *file);
FSResult FSi_CloseFileCommand(FSFile *file);
FSResult FSi_ROMFAT_ReadFile(FSArchive *arc, FSFile *file, void *buffer, u32 *length);
FSResult FSi_ROMFAT_WriteFile(FSArchive *arc, FSFile *file, const void *buffer, u32 *length);
FSResult FSi_ROMFAT_SeekDirectory(FSArchive *arc, FSFile *file, u32 id, u32 position);
FSResult FSi_ROMFAT_ReadDirectory(FSArchive *arc, FSFile *file, FSDirectoryEntryInfo *info);
FSResult FSi_ROMFAT_FindPath(FSArchive *arc, u32 base_dir_id, const char *path, u32 *target_id, BOOL target_is_directory);
FSResult FSi_ROMFAT_GetPath(FSArchive *arc, FSFile *file, BOOL is_directory, char *buffer, u32 *length);
FSResult FSi_ROMFAT_OpenFileFast(FSArchive *arc, FSFile *file, u32 id, u32 mode);
FSResult FSi_ROMFAT_OpenFileDirect(FSArchive *arc, FSFile *file, u32 top, u32 bottom, u32 *id);
FSResult FSi_ROMFAT_CloseFile(FSArchive *arc, FSFile *file);
void FSi_ROMFAT_Activate(FSArchive *arc);
void FSi_ROMFAT_Idle(FSArchive *arc);
void FSi_ROMFAT_Suspend(FSArchive *arc);
void FSi_ROMFAT_Resume(FSArchive *arc);
FSResult FSi_ROMFAT_OpenFile(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);
FSResult FSi_ROMFAT_SeekFile(FSArchive *arc, FSFile *file, int *offset, u32 from);
FSResult FSi_ROMFAT_GetFileLength(FSArchive *arc, FSFile *file, u32 *length);
FSResult FSi_ROMFAT_GetFilePosition(FSArchive *arc, FSFile *file, u32 *position);
void FSi_ROMFAT_Unmount(FSArchive *arc);
FSResult FSi_ROMFAT_GetArchiveCaps(FSArchive *arc, u32 *caps);
FSResult FSi_ROMFAT_GetPathInfo(FSArchive *arc, u32 baseid, const char *path, FSPathInfo *info);
FSResult FSi_ROMFAT_GetArchiveResource(FSArchive *arc, FSArchiveResourceEx *resource);
FSResult FSi_ROMFAT_OpenDirectory(FSArchive *arc, FSFile *file, u32 baseid, const char *path, u32 mode);
FSResult FSi_ROMFAT_CloseDirectory(FSArchive *arc, FSFile *file);

#pragma force_active on

// static FSResult (*const command_table[13])(FSFile *): the command handlers, with
// FSi_CloseFileCommand in the last five slots.
void data_02070f2c(void);
// static const FSArchiveInterface FSiArchiveRomFatInterface (64 slots)
void FSiArchiveRomFatInterface(void);

asm void data_02070f2c(void) {
    dcd FSi_ReadFileCommand
    dcd FSi_WriteFileCommand
    dcd FSi_SeekDirCommand
    dcd FSi_ReadDirCommand
    dcd FSi_FindPathCommand
    dcd FSi_GetPathCommand
    dcd FSi_OpenFileFastCommand
    dcd FSi_OpenFileDirectCommand
    dcd FSi_CloseFileCommand
    dcd FSi_CloseFileCommand
    dcd FSi_CloseFileCommand
    dcd FSi_CloseFileCommand
    dcd FSi_CloseFileCommand
}

asm void FSiArchiveRomFatInterface(void) {
    dcd FSi_ROMFAT_ReadFile
    dcd FSi_ROMFAT_WriteFile
    dcd FSi_ROMFAT_SeekDirectory
    dcd FSi_ROMFAT_ReadDirectory
    dcd FSi_ROMFAT_FindPath
    dcd FSi_ROMFAT_GetPath
    dcd FSi_ROMFAT_OpenFileFast
    dcd FSi_ROMFAT_OpenFileDirect
    dcd FSi_ROMFAT_CloseFile
    dcd FSi_ROMFAT_Activate
    dcd FSi_ROMFAT_Idle
    dcd FSi_ROMFAT_Suspend
    dcd FSi_ROMFAT_Resume
    dcd FSi_ROMFAT_OpenFile
    dcd FSi_ROMFAT_SeekFile
    dcd FSi_ROMFAT_GetFileLength
    dcd FSi_ROMFAT_GetFilePosition
    dcd 0
    dcd FSi_ROMFAT_Unmount
    dcd FSi_ROMFAT_GetArchiveCaps
    dcd 0
    dcd 0
    dcd 0
    dcd FSi_ROMFAT_GetPathInfo
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd FSi_ROMFAT_GetArchiveResource
    dcd 0
    dcd 0
    dcd 0
    dcd FSi_ROMFAT_OpenDirectory
    dcd FSi_ROMFAT_CloseDirectory
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
    dcd 0
}

#pragma force_active reset
