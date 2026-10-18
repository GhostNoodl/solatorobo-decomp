#include "fs_private.h"

#pragma force_active on

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);

BOOL FS_ConvertPathToFileID(FSFileID *p_fileid, const char *path) {
    BOOL retval = FALSE;
    u32 baseid = 0;
    char relpath[FS_ARCHIVE_FULLPATH_MAX];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc) {
        FSFile file[1];
        FSArgumentForFindPath arg[1];
        FS_InitFile(file);
        file->arc = arc;
        file->argument = arg;
        arg->baseid = baseid;
        arg->relpath = relpath;
        arg->target_is_directory = FALSE;
        if (FSi_SendCommand(file, FS_COMMAND_FINDPATH, TRUE)) {
            p_fileid->arc = arc;
            p_fileid->file_id = arg->target_id;
            retval = TRUE;
        }
    }
    return retval;
}

BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id) {
    FSArgumentForOpenFileDirect arg[1];

    file->arc = arc;
    file->argument = arg;
    arg->id = id;
    arg->top = image_top;
    arg->bottom = image_bottom;
    arg->mode = 0;
    return FSi_SendCommand(file, FS_COMMAND_OPENFILEDIRECT, TRUE);
}

BOOL FS_OpenFileFast(FSFile *file, FSFileID id) {
    BOOL retval = FALSE;

    if (id.arc) {
        FSArgumentForOpenFileFast arg[1];
        file->arc = id.arc;
        file->argument = arg;
        arg->id = id.file_id;
        arg->mode = 0;
        retval = FSi_SendCommand(file, FS_COMMAND_OPENFILEFAST, TRUE);
    }
    return retval;
}

BOOL FS_OpenFileEx(FSFile *file, const char *path, u32 mode) {
    BOOL retval = FALSE;
    u32 baseid = 0;
    char relpath[FS_ARCHIVE_FULLPATH_MAX];
    FSArchive *arc = FS_NormalizePath(path, &baseid, relpath);

    if (arc) {
        FSArgumentForOpenFile arg[1];
        FS_InitFile(file);
        file->argument = arg;
        file->arc = arc;
        arg->baseid = baseid;
        arg->relpath = relpath;
        arg->mode = mode;
        if (FSi_SendCommand(file, FS_COMMAND_OPENFILE, TRUE)) {
            retval = TRUE;
        } else {
            file->arc = NULL;
        }
    }
    return retval;
}

BOOL FS_CloseFile(FSFile *file) {
    return FSi_SendCommand(file, FS_COMMAND_CLOSEFILE, TRUE);
}

BOOL FS_SetSeekCache(FSFile *file, void *buf, u32 buf_size) {
    FSArgumentForSetSeekCache arg[1];

    file->argument = arg;
    arg->buf = buf;
    arg->buf_size = buf_size;
    return FSi_SendCommand(file, FS_COMMAND_SETSEEKCACHE, TRUE);
}

u32 FS_GetFileLength(FSFile *file) {
    u32 length = 0;

    if (!FSi_GetFileLengthIfProc(file, &length)) {
        FSArgumentForGetFileLength arg[1];
        file->argument = arg;
        arg->length = 0;
        if (FSi_SendCommand(file, FS_COMMAND_GETFILELENGTH, TRUE)) {
            length = arg->length;
        }
    }
    return length;
}

u32 FS_GetFilePosition(FSFile *file) {
    u32 position = 0;

    if (!FSi_GetFilePositionIfProc(file, &position)) {
        FSArgumentForGetFilePosition arg[1];
        file->argument = arg;
        arg->position = 0;
        if (FSi_SendCommand(file, FS_COMMAND_GETFILEPOSITION, TRUE)) {
            position = arg->position;
        }
    }
    return position;
}

BOOL FS_SeekFile(FSFile *file, int offset, u32 from) {
    FSArgumentForSeekFile arg[1];

    file->argument = arg;
    arg->offset = offset;
    arg->from = from;
    return FSi_SendCommand(file, FS_COMMAND_SEEKFILE, TRUE);
}

