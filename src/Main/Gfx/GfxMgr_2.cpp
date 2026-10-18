#include "Main/Gfx/GfxMgr.h"

extern "C" {


extern u8 data_02097ce4[];
extern const u8 data_02082798[0x60];

extern void *func_0203dec8(u32 size, int align);
extern void func_02016fa0(const void *src, void *dst, u32 size);
extern void func_02019294(const void *addr, u32 size);
extern void func_02016d1c(u32 value, void *dst, u32 size);
extern void func_02014304(const void *src, u32 offset, u32 size);
extern void func_0201439c(const void *src, u32 offset, u32 size);
extern void func_02014450(const void *src, u32 offset, u32 size);
extern void func_02014504(const void *src, u32 offset, u32 size);
extern u16 func_0203bdb0(GfxSys *obj, int a, int b);
extern void *func_0203bc20(GfxSys *obj, u32 size, int a);
extern void func_0203df40(void *ptr);
extern void func_020435e8(GfxPltt *src, void *dst, u32 size);


VramBlock *func_0203994c(GfxMgr *mgr, VramBlock *block) {
    VramBlock *prev;
    VramBlock *next;
    block->addr -= block->pad;
    ((u32 *)block)[4] = 0;
    prev = block->prev;
    if (prev != NULL && !prev->used) {
        VramBlock *old = block;
        if (block->next != NULL) {
            block->next->prev = prev;
        }
        block->prev->next = block->next;
        block->prev->size += block->size;
        block->size = 0;
        block = block->prev;
        old->addr = 0;
        old->prev = NULL;
        old->next = NULL;
    }
    next = block->next;
    if (next != NULL && !next->used) {
        if (next->next != NULL) {
            next->next->prev = block;
        }
        block->size += block->next->size;
        block->next->size = 0;
        next = block->next;
        block->next = next->next;
        next->addr = 0;
        next->prev = NULL;
        next->next = NULL;
    }
    return block->next;
}

void func_02039a34(GfxMgr *mgr) {
    int i;
    VramBlock *block;
    mgr->unk_004 = 0;
    mgr->unk_008 = 0;
    mgr->unk_00c = 0;
    mgr->unk_00e = 0;
    mgr->unk_010 = 0;
    mgr->unk_012 = 0;
    for (i = 0; i < 10; i++) {
        mgr->fonts[i] = NULL;
        mgr->fontHeights[i] = 0;
    }
    mgr->unk_046 = 0;
    mgr->unk_000 = -1;
    func_02016fa0(data_02082798, data_02097ce4, 0x60);
    func_02019294(data_02097ce4, 0x60);
    mgr->plttSlots[0] = func_0203bdb0(data_02097d48, 3, 4);
    func_02014304(data_02082798, mgr->plttSlots[0] << 5, 0x60);
    mgr->plttSlots[1] = func_0203bdb0(data_02097d48, 3, 5);
    func_0201439c(data_02082798, mgr->plttSlots[1] << 5, 0x60);
    mgr->plttSlots[2] = func_0203bdb0(data_02097d48, 3, 0);
    func_02014450(data_02082798, mgr->plttSlots[2] << 5, 0x60);
    mgr->plttSlots[3] = func_0203bdb0(data_02097d48, 3, 2);
    func_02014504(data_02097ce4, mgr->plttSlots[3] << 5, 0x60);
    mgr->unk_658 = 0;
    mgr->unk_65c = 0;
    mgr->unk_650 = func_0203bc20(data_02097d48, 0x4000, 0);
    mgr->unk_654 = func_0203bc20(data_02097d48, 0x4000, 1);

    block = (VramBlock *)func_0203dec8(0x80 * sizeof(VramBlock), 4);
    func_02016d1c(0, block, 0x80 * sizeof(VramBlock));
    block->addr = 0x20;
    block->size = 0x4000 - 0x20;
    block->prev = NULL;
    block->next = NULL;
    ((u32 *)block)[4] = 0;
    mgr->pools[0].blocks = block;
    mgr->pools[0].alignShift = 2;
    mgr->pools[0].numBlocks = 0x80;

    block = (VramBlock *)func_0203dec8(0x80 * sizeof(VramBlock), 4);
    func_02016d1c(0, block, 0x80 * sizeof(VramBlock));
    block->addr = 0x20;
    block->size = 0x4000 - 0x20;
    block->prev = NULL;
    block->next = NULL;
    ((u32 *)block)[4] = 0;
    mgr->unk_678 = 0x14;
    mgr->pools[1].alignShift = 2;
    mgr->pools[1].blocks = block;
    mgr->pools[1].numBlocks = 0x80;
    mgr->unk_67c = NULL;
    mgr->unk_680 = 0;
    mgr->unk_67a = 0x16;
}

void func_02039c54(GfxMgr *mgr, int mode) {
    VramBlock *block;
    block = mgr->pools[0].blocks;
    do {
        if (block->used) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->unk_69c[0] = 0;
    mgr->unk_69c[1] = 0;
    mgr->unk_69c[2] = 0;
    mgr->unk_69c[3] = 0;
    if (mgr->unk_67c != NULL) {
        func_0203df40(mgr->unk_67c);
        mgr->unk_67c = NULL;
    }
    mgr->unk_680 = 0;
    func_02019294(data_02097ce4, 0x60);
    mgr->plttSlots[0] = func_0203bdb0(data_02097d48, 3, 4);
    func_02014304(data_02082798, mgr->plttSlots[0] << 5, 0x60);
    mgr->plttSlots[1] = func_0203bdb0(data_02097d48, 3, 5);
    func_0201439c(data_02082798, mgr->plttSlots[1] << 5, 0x60);
    mgr->plttSlots[2] = func_0203bdb0(data_02097d48, 3, 0);
    func_02014450(data_02082798, mgr->plttSlots[2] << 5, 0x60);
    mgr->plttSlots[3] = func_0203bdb0(data_02097d48, 3, 2);
    func_02014504(data_02097ce4, mgr->plttSlots[3] << 5, 0x60);
    mgr->unk_65c = 0;
    if (mode != 2) {
        mgr->unk_650 = func_0203bc20(data_02097d48, 0x4000, 0);
        mgr->unk_654 = func_0203bc20(data_02097d48, 0x4000, 1);
    }
    mgr->unk_650 = NULL;
    mgr->unk_654 = NULL;
}

void func_02039e0c(GfxMgr *mgr) {
    VramBlock *block;
    GfxPltt *pltt;
    int id;
    mgr->unk_046 = 0;
    mgr->unk_012 = 0;
    block = mgr->pools[0].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->pools[0].alignShift = ((int)(*(volatile u32 *)0x04000000 & 0x300010) >> 20) & 3;
    mgr->pools[1].alignShift = ((int)(*(volatile u32 *)0x04001000 & 0x300010) >> 20) & 3;
    pltt = &data_02097d48->pltt;
    id = pltt->id;
    if (mgr->unk_000 != id) {
        func_02016fa0(data_02082798, data_02097ce4, 0x60);
        func_020435e8(pltt, data_02097ce4, 0x60);
        mgr->unk_000 = id;
        func_02019294(data_02097ce4, 0x60);
        func_02014450(data_02097ce4, mgr->plttSlots[2] << 5, 0x60);
    }
    mgr->unk_69c[0] = 0;
    mgr->unk_69c[1] = 0;
    mgr->unk_69c[2] = 0;
    mgr->unk_69c[3] = 0;
    if (mgr->unk_67c != NULL) {
        func_0203df40(mgr->unk_67c);
        mgr->unk_67c = NULL;
    }
    mgr->unk_680 = 0;
}

void func_02039f84(GfxMgr *mgr) {
    VramBlock *block;
    GfxPltt *pltt;
    int id;
    mgr->unk_046 = 0;
    mgr->unk_012 = 0;
    block = mgr->pools[0].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->pools[0].alignShift = ((int)(*(volatile u32 *)0x04000000 & 0x300010) >> 20) & 3;
    mgr->pools[1].alignShift = ((int)(*(volatile u32 *)0x04001000 & 0x300010) >> 20) & 3;
    pltt = &data_02097d48->pltt;
    id = pltt->id;
    if (mgr->unk_000 != id) {
        func_02016fa0(data_02082798, data_02097ce4, 0x60);
        func_020435e8(pltt, data_02097ce4, 0x60);
        mgr->unk_000 = id;
        func_02019294(data_02097ce4, 0x60);
        func_02014450(data_02097ce4, mgr->plttSlots[2] << 5, 0x60);
    }
}

}
