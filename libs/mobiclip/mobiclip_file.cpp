#include "mobiclip/mobiclip.h"

// MoStream implementation that reads from a NitroSDK FSFile. data_0208b2ac is its vtable.

extern "C" {

extern BOOL FS_WaitAsync(void *file);
extern BOOL FS_SeekFile(void *file, int offset, int origin);
extern int FS_ReadFile(void *file, void *buf, u32 size);
extern int FS_ReadFileAsync(void *file, void *buf, u32 size);
extern u32 FS_GetLength(void *file);
extern u32 FS_GetPosition(void *file);

BOOL func_02034830(MoStream *stream, void *file) {
    stream->file = file;
    stream->length = FS_GetLength(file);
    stream->position = FS_GetPosition(stream->file);
    stream->asyncPending = FALSE;
    return TRUE;
}

BOOL func_02034864(MoStream *stream, u32 offset) {
    if (stream->asyncPending == TRUE) {
        FS_WaitAsync(stream->file);
        stream->asyncPending = FALSE;
    }
    if (!FS_SeekFile(stream->file, offset, 0)) {
        return FALSE;
    }
    stream->position = offset;
    return TRUE;
}

BOOL func_020348b4(MoStream *stream, void *buffer, u32 size) {
    if (stream->asyncPending == TRUE) {
        FS_WaitAsync(stream->file);
        FS_SeekFile(stream->file, stream->position, 0);
        stream->asyncPending = FALSE;
    }
    if (FS_ReadFile(stream->file, buffer, size) == -1) {
        return FALSE;
    }
    stream->position += size;
    return TRUE;
}

u32 func_0203491c(MoStream *stream, void *buffer, u32 size) {
    u32 pos = stream->position;
    u32 skip = pos - (pos & ~0x1ff);
    u32 total = size + skip;
    if (total & 0x1ff) {
        total = (total & ~0x1ff) + 0x200;
    }
    FS_SeekFile(stream->file, pos & ~0x1ff, 0);
    if (FS_ReadFileAsync(stream->file, buffer, total) == -1) {
        return FALSE;
    }
    stream->position += size;
    stream->asyncPending = TRUE;
    return skip;
}

void func_0203499c(MoStream *stream) {
    if (stream->asyncPending == TRUE) {
        FS_WaitAsync(stream->file);
    }
    stream->asyncPending = FALSE;
}

void func_020349c4(MoStream *stream) {
    stream->WaitAsync();
}

void func_020349d8(MoStream *stream) {
}

}
