#include "fs_private.h"

#pragma force_active on

BOOL FSi_GetFileLengthIfProc(FSFile *file, u32 *length);
BOOL FSi_GetFilePositionIfProc(FSFile *file, u32 *position);

int FS_ReadFile(FSFile *file, void *buffer, int length) {
    FSArgumentForReadFile arg[1];

    file->argument = arg;
    arg->buffer = buffer;
    arg->length = (u32)length;
    {
        if (FSi_SendCommand(file, FS_COMMAND_READFILE, TRUE)) {
            length = (int)arg->length;
        } else if (file->error == FS_RESULT_INVALID_PARAMETER) {
            length = -1;
        } else {
            length = (int)arg->length;
        }
        return length;
    }
}

int FS_ReadFileAsync(FSFile *file, void *buffer, int length) {
    u32 end, pos;

    if (FSi_GetFilePositionIfProc(file, &pos) && FSi_GetFileLengthIfProc(file, &end) && (pos + length > end)) {
        length = (int)(end - pos);
    }
    {
        FSArgumentForReadFile *arg = (FSArgumentForReadFile *)file->arg.reserved2;
        file->argument = arg;
        arg->buffer = buffer;
        arg->length = (u32)length;
        (void)FSi_SendCommand(file, FS_COMMAND_READFILE, FALSE);
    }
    return length;
}


int FS_WriteFile(FSFile *file, const void *buffer, int length) {
    FSArgumentForWriteFile arg[1];

    file->argument = arg;
    arg->buffer = buffer;
    arg->length = (u32)length;
    {
        if (FSi_SendCommand(file, FS_COMMAND_WRITEFILE, TRUE)) {
            length = (int)arg->length;
        } else if (file->error == FS_RESULT_INVALID_PARAMETER) {
            length = -1;
        } else {
            length = (int)arg->length;
        }
        return length;
    }
}

