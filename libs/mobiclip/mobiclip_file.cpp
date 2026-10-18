#include "mobiclip/mobiclip.h"

// MoStream implementation that reads from a NitroSDK FSFile. data_0208b2ac is its vtable.

extern "C" {

extern void func_0200eb50(void *file);
extern BOOL func_0200f00c(void *file, int offset, int origin);
extern int func_0200f038(void *file, void *buf, u32 size);
extern int func_0200f08c(void *file, void *buf, u32 size);
extern u32 func_0200f168(void *file);
extern u32 func_0200f174(void *file);

BOOL func_02034830(MoStream *stream, void *file) {
    stream->file = file;
    stream->length = func_0200f168(file);
    stream->position = func_0200f174(stream->file);
    stream->asyncPending = FALSE;
    return TRUE;
}

BOOL func_02034864(MoStream *stream, u32 offset) {
    if (stream->asyncPending == TRUE) {
        func_0200eb50(stream->file);
        stream->asyncPending = FALSE;
    }
    if (!func_0200f00c(stream->file, offset, 0)) {
        return FALSE;
    }
    stream->position = offset;
    return TRUE;
}

BOOL func_020348b4(MoStream *stream, void *buffer, u32 size) {
    if (stream->asyncPending == TRUE) {
        func_0200eb50(stream->file);
        func_0200f00c(stream->file, stream->position, 0);
        stream->asyncPending = FALSE;
    }
    if (func_0200f038(stream->file, buffer, size) == -1) {
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
    func_0200f00c(stream->file, pos & ~0x1ff, 0);
    if (func_0200f08c(stream->file, buffer, total) == -1) {
        return FALSE;
    }
    stream->position += size;
    stream->asyncPending = TRUE;
    return skip;
}

void func_0203499c(MoStream *stream) {
    if (stream->asyncPending == TRUE) {
        func_0200eb50(stream->file);
    }
    stream->asyncPending = FALSE;
}

void func_020349c4(MoStream *stream) {
    stream->WaitAsync();
}

void func_020349d8(MoStream *stream) {
}

}
