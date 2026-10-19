#include "Main/Res/ResLoader.h"

void func_0203584c(ResLoader *loader) {
    loader->req.index = 0;
    loader->state = 0;
    ResRequest_Init(&loader->req);
    if (!OS_IsThreadTerminated(loader)) {
        OS_DestroyThread(loader);
    }
}

u8 *func_02035890(ResRing *ring) {
    u8 *result;
    u32 readPos;
    int readOff;
    int writeOff;
    u32 bufSize;
    u32 writePos;
    readPos = ring->readPos;
    result = NULL;
    if (readPos != 0) {
        bufSize = ring->bufSize;
        readOff = readPos % bufSize;
        writePos = ring->writePos;
        writeOff = writePos % bufSize;
        if (writeOff < readOff || writeOff - readOff >= ring->blockSize || readPos == writePos) {
            result = ring->buf + readOff;
        }
    } else {
        result = ring->buf;
    }
    return result;
}

// The clamp is written out in both branches; the target keeps them as two blocks.
u32 func_02035904(ResRing *ring) {
    u32 size;
    u32 max;
    if (ring->readPos != 0) {
        size = ring->total - ring->readPos;
        max = ring->blockSize;
        if (size > max) {
            size = max;
        }
    } else {
        size = ring->total;
        max = ring->bufSize;
        if (size > max) {
            size = max;
        }
    }
    return size;
}
