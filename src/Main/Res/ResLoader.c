#include "Main/Res/ResLoader.h"

// Non-matching: registers of ring/size/dst are rotated.
#ifdef NONMATCHING
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
            loader->state = 2;
            entry = &req->entries[req->index];
        case 2:
            break;
        default:
            continue;
        }
        ring = &loader->ring;
        if (ring != NULL) {
            switch (entry->attr2 & 0xf0) {
            case 0x10:
                func_020174a8(lzCtx, req->data, &entry->attr2);
                ResRing_FillLZ(ring, lzCtx);
                break;
            case 0x30:
                func_02017484(huffCtx, req->data, &entry->attr2);
                ResRing_FillHuff(ring, huffCtx);
                break;
            }
        }
        loader->state = 3;
    }
}
#endif

ResLoader *func_0203562c(ResLoader *loader) {
    ResRing_Init(&loader->ring);
    loader->state = 0;
    ResRequest_Init(&loader->req);
    return loader;
}

// Non-matching
#ifdef NONMATCHING
void func_02035670(ResLoader *loader) {
    u32 blockSize;
    u16 numBlocks;
    void *buf;
    func_020184ac(loader, (void (*)(void *))func_02035450, loader, loader->stack + sizeof(loader->stack), sizeof(loader->stack), 0x12);
    func_02018988(loader, 0x4c);
    blockSize = 0x2000;
    numBlocks = 3;
    if (!func_02018d58()) {
        blockSize = 0x1540;
        buf = func_020197dc(0, data_02097dd0->unk_0c, 0x3fc0);
    } else {
        buf = func_0203dec8(0x6000, 4);
    }
    ResRing_Setup(&loader->ring, buf, blockSize, numBlocks);
}
#endif

// Non-matching
#ifdef NONMATCHING
BOOL func_02035740(ResLoader *loader, ResRequest *req) {
    BOOL result = FALSE;
    if (loader->state != 0) {
        return result;
    }
    loader->state = 1;
    loader->req.unk_00 = req->unk_00;
    loader->req.unk_04 = req->unk_04;
    loader->req.entries = req->entries;
    loader->req.data = req->data;
    loader->req.name = req->name;
    loader->req.unk_28 = req->unk_28;
    loader->req.index = req->index;
    if (func_020187fc(loader)) {
        func_020184ac(loader, (void (*)(void *))func_02035450, loader, loader->stack + sizeof(loader->stack), sizeof(loader->stack), 0x12);
        func_02018988(loader, 0x4c);
    }
    func_02018918(loader);
    return TRUE;
}
#endif

// Non-matching
#ifdef NONMATCHING
void func_0203581c(ResLoader *loader) {
    loader->state = 0;
    loader->req.unk_00 = 0;
    loader->req.unk_04 = 0;
    loader->req.entries = NULL;
    loader->req.data = NULL;
    loader->req.index = 0;
    loader->req.name.str[0] = '\0';
    func_02018810(loader);
}
#endif
