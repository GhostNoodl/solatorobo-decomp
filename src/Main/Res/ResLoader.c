#include "Main/Res/ResLoader.h"

// Decompresses the requested file into the ring buffer, then waits for the next request.
void func_02035450(ResLoader *loader) {
    ResRequest *req = NULL;
    ResFileEntry *entry = NULL;
    u8 lzCtx[0x14];
    u8 huffCtx[0x10];
    ResRing *ring;
    while (TRUE) {
        switch (loader->state) {
        case 1:
            req = &loader->req;
            entry = &req->entries[req->index];
            loader->state = 2;
        case 2:
            break;
        default:
            continue;
        }
        // The comma expression gives ring the callee-saved register the original uses.
        ring = (0, &loader->ring);
        if (ring != NULL) {
            switch (entry->attr2 & 0xf0) {
            case 0x10:
                MI_InitUncompContextLZ(lzCtx, req->data, &entry->attr2);
                ResRing_FillLZ(ring, lzCtx);
                break;
            case 0x30:
                MI_InitUncompContextRL(huffCtx, req->data, &entry->attr2);
                ResRing_FillHuff(ring, huffCtx);
                break;
            }
        }
        loader->state = 3;
    }
}

ResLoader *func_0203562c(ResLoader *loader) {
    ResRing_Init(&loader->ring);
    loader->state = 0;
    ResRequest_Init(&loader->req);
    return loader;
}

// The original keeps numBlocks in a register and multiplies: constant propagation was off here.
#pragma push
#pragma opt_propagation off
void func_02035670(ResLoader *loader) {
    u32 blockSize;
    u16 numBlocks;
    void *buf;
    OS_CreateThread(loader, (void (*)(void *))func_02035450, loader, loader->stack + sizeof(loader->stack), sizeof(loader->stack), 0x12);
    OS_SetThreadStackWarningOffset(loader, 0x4c);
    blockSize = 0x2000;
    numBlocks = 3;
    if (!OS_IsRunOnTwl()) {
        blockSize = 0x1540;
        buf = OS_AllocFromHeap(0, data_02097dd0->unk_0c, 0x3fc0);
    } else {
        buf = func_0203dec8(0x6000, 4);
    }
    ResRing_Setup(&loader->ring, buf, blockSize, numBlocks);
}
#pragma pop

BOOL func_02035740(ResLoader *loader, ResRequest *req) {
    BOOL result = FALSE;
    if (loader->state == 0) {
        loader->state = 1;
        loader->req.unk_00 = req->unk_00;
        loader->req.unk_04 = req->unk_04;
        loader->req.entries = req->entries;
        loader->req.data = req->data;
        loader->req.name = req->name;
        loader->req.unk_28 = req->unk_28;
        loader->req.index = req->index;
        if (OS_IsThreadTerminated(loader)) {
            OS_CreateThread(loader, (void (*)(void *))func_02035450, loader, loader->stack + sizeof(loader->stack), sizeof(loader->stack), 0x12);
            OS_SetThreadStackWarningOffset(loader, 0x4c);
        }
        OS_WakeupThreadDirect(loader);
        result = TRUE;
    }
    return result;
}

void func_0203581c(ResLoader *loader) {
    loader->state = 0;
    ResRequest_Init(&loader->req);
    OS_SleepThreadDirect(loader, NULL);
}
