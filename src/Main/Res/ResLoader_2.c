#include "Main/Res/ResLoader.h"

void func_0203584c(ResLoader *loader) {
    loader->req.index = 0;
    loader->state = 0;
    ResRequest_Init(&loader->req);
    if (!func_020187fc(loader)) {
        func_020186a8(loader);
    }
}

// Non-matching
#ifdef NONMATCHING
u8 *func_02035890(ResRing *ring) {
    u32 readPos = ring->readPos;
    u8 *result = NULL;
    if (readPos != 0) {
        int readOff = readPos % ring->bufSize;
        u32 writePos = ring->writePos;
        int writeOff = writePos % ring->bufSize;
        if (writeOff < readOff || writeOff - readOff >= ring->blockSize || readPos == writePos) {
            result = ring->buf + readOff;
        }
    } else {
        result = ring->buf;
    }
    return result;
}
#endif

// Non-matching
#ifdef NONMATCHING
u32 func_02035904(ResRing *ring) {
    u32 size;
    u32 max;
    if (ring->readPos != 0) {
        size = ring->total - ring->readPos;
        max = ring->blockSize;
    } else {
        size = ring->total;
        max = ring->bufSize;
    }
    if (size > max) {
        size = max;
    }
    return size;
}
#endif
