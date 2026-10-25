// fs_romfat.c's read-only tables: the command table FSi_ROMFAT_TranslateCommand dispatches the
// synchronous FS commands through, and the archive interface FS_LoadArchive mounts the ROM archive
// with (its unused slots are NULL). Both are made of symbol references; written as asm blocks so
// they land in main's .text with the other read-only data (see libs/msl/ctype.c).

void FSi_ReadFileCommand(void);
void FSi_WriteFileCommand(void);
void FSi_SeekDirCommand(void);
void FSi_ReadDirCommand(void);
void FSi_FindPathCommand(void);
void FSi_GetPathCommand(void);
void FSi_OpenFileFastCommand(void);
void FSi_OpenFileDirectCommand(void);
void FSi_CloseFileCommand(void);
void FSi_ROMFAT_ReadFile(void);
void FSi_ROMFAT_WriteFile(void);
void FSi_ROMFAT_SeekDirectory(void);
void FSi_ROMFAT_ReadDirectory(void);
void FSi_ROMFAT_FindPath(void);
void FSi_ROMFAT_GetPath(void);
void FSi_ROMFAT_OpenFileFast(void);
void FSi_ROMFAT_OpenFileDirect(void);
void FSi_ROMFAT_CloseFile(void);
void FSi_ROMFAT_Activate(void);
void FSi_ROMFAT_Idle(void);
void FSi_ROMFAT_Suspend(void);
void FSi_ROMFAT_Resume(void);
void FSi_ROMFAT_OpenFile(void);
void FSi_ROMFAT_SeekFile(void);
void FSi_ROMFAT_GetFileLength(void);
void FSi_ROMFAT_GetFilePosition(void);
void FSi_ROMFAT_Unmount(void);
void FSi_ROMFAT_GetArchiveCaps(void);
void FSi_ROMFAT_GetPathInfo(void);
void FSi_ROMFAT_GetArchiveResource(void);
void FSi_ROMFAT_OpenDirectory(void);
void FSi_ROMFAT_CloseDirectory(void);

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
