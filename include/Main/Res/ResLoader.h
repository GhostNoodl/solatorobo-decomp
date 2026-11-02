#ifndef MAIN_RES_RESLOADER_H
#define MAIN_RES_RESLOADER_H

#include "Main/Res/ResMgr.h"
#include "nitro/os.h"
#include "nitro/os_alloc.h"
#include "nitro/mi_uncomp_stream.h"

#ifdef __cplusplus
extern "C" {
#endif

// Background thread that decompresses files as their data streams into a ring buffer.

typedef struct ResRing {
    /* 0x00 */ u8 *buf;
    /* 0x04 */ u32 bufSize;
    /* 0x08 */ u32 blockSize;
    /* 0x0c */ u16 numBlocks;
    /* 0x0e */ u16 flags; // bit 0: buf was allocated
    /* 0x10 */ u32 total;
    /* 0x14 */ u32 readPos;
    /* 0x18 */ u32 writePos;
} ResRing; // size 0x1c

typedef struct ResLoader {
    /* 0x000 */ OSThread thread;
    /* 0x0c0 */ u8 stack[0x300];
    /* 0x3c0 */ u8 state;
    /* 0x3c4 */ ResRequest req;
    /* 0x3f0 */ ResRing ring;
} ResLoader;


extern void *Heap_AllocHi(u32 size, u32 align);
extern void *Heap_AllocLo(u32 size, u32 align);

static inline u32 ResRing_GetWriteSize(ResRing *ring) {
    u32 size = ring->total - ring->writePos;
    if (size > ring->blockSize) {
        size = ring->blockSize;
    }
    return size;
}

static inline u8 *ResRing_GetWritePtr(ResRing *ring) {
    u8 *dst = NULL;
    u32 offset = ring->writePos % ring->bufSize;
    if (ring->readPos < ring->total) {
        if (ring->readPos - ring->writePos >= ring->blockSize) {
            dst = ring->buf + offset;
        }
    } else {
        dst = ring->buf + offset;
    }
    return dst;
}

#define RES_RING_FILL_FUNC(name, readFunc, CtxType)      \
    static inline void name(ResRing *ring, void *ctx) {   \
        u32 size;                                         \
        u8 *dst;                                          \
        while (TRUE) {                                    \
            size = ResRing_GetWriteSize(ring);            \
            if (size == 0) {                              \
                break;                                    \
            }                                             \
            dst = ResRing_GetWritePtr(ring);              \
            if (dst == NULL) {                            \
                continue;                                 \
            }                                             \
            readFunc((CtxType *)ctx, dst, size);          \
            ring->writePos += size;                       \
        }                                                 \
    }

RES_RING_FILL_FUNC(ResRing_FillLZ, MI_ReadUncompLZ8, MIUncompContextLZ)
RES_RING_FILL_FUNC(ResRing_FillHuff, MI_ReadUncompRL8, MIUncompContextRL)

static inline void ResRing_Init(ResRing *ring) {
    ring->buf = NULL;
    ring->blockSize = 0;
    ring->numBlocks = 0;
    ring->total = 0;
    ring->readPos = 0;
    ring->writePos = 0;
    ring->flags = 0;
}

static inline void ResRequest_Init(ResRequest *req) {
    req->unk_00 = 0;
    req->unk_04 = 0;
    req->entries = NULL;
    req->data = NULL;
    req->index = 0;
    req->name.str[0] = '\0';
}

static inline void ResRing_Setup(ResRing *ring, void *buf, u32 blockSize, u16 numBlocks) {
    u32 size = blockSize * numBlocks;
    ring->blockSize = blockSize;
    ring->numBlocks = numBlocks;
    ring->bufSize = size;
    if (buf != NULL) {
        ring->buf = (u8 *)buf;
        return;
    }
    ring->buf = (u8 *)Heap_AllocHi(size, 4);
    ring->flags = (ring->flags & ~1) | 1;
}

void func_02035450(struct ResLoader *loader);

#ifdef __cplusplus
}
#endif

#endif
