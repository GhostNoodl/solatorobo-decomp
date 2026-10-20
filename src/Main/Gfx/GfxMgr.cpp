#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern u8 data_02097ce4[];


extern void *func_0203dec8(u32 size, int align);
extern void func_02039a34(GfxMgr *mgr);
extern void *func_0203a408(GfxMgr *mgr, void *arg1, void *arg2, void *arg3);
extern void *func_0203a984(GfxMgr *mgr, void *arg1, void *arg2);
extern VramBlock *func_0203994c(GfxMgr *mgr, VramBlock *block);
extern ResList *func_02035934(const char *name);
extern void *func_02034cec(ResList *list, const char *name);

void *func_02039720(void) {
    return data_02097ce4;
}

void *func_0203972c(void *arg1, void *arg2) {
    return func_0203a984(data_02097ce0, arg1, arg2);
}

void func_02039750(void) {
    GfxMgr *mgr;
    int j;
    int i;
    if (data_02097ce0 != NULL) {
        return;
    }
    data_02097ce0 = (GfxMgr *)func_0203dec8(sizeof(GfxMgr), 4);
    func_02039a34(data_02097ce0);
    mgr = data_02097ce0;
    for (i = 0; i < 10; i++) {
        mgr->fonts[i] = NULL;
        for (j = 0; j < 9; j++) {
            if (i == data_020827f8[j].index) {
                mgr->fonts[i] = (GfxFont *)func_02034cec(func_02035934(data_020827f8[j].name), data_020827f8[j].name);
                mgr->fontHeights[i] = mgr->fonts[i]->res->info[6];
            }
        }
    }
}

void *func_020397fc(void *arg1, void *arg2, void *arg3) {
    return func_0203a408(data_02097ce0, arg1, arg2, arg3);
}

VramBlock *func_02039828(VramBlock *block) {
    return func_0203994c(data_02097ce0, block);
}

VramBlock *func_02039844(GfxMgr *mgr, VramPool *pool, u32 size) {
    u32 align;
    u32 mask;
    int i;
    u32 shift;
    VramBlock *block;
    VramBlock *spare;
    int count;
    block = pool->blocks;
    if (size == 0) {
        size = 0x20;
    }
    count = pool->numBlocks;
    i = 0x20;
    if ((u32)pool & 3) i = 0x20;
    align = i << pool->alignShift;
    spare = block;
    for (i = 0; i < count; i++, spare++) {
        if (spare->size == 0) {
            break;
        }
    }
    if (i == pool->numBlocks) {
        return NULL;
    }
    mask = align - 1;
    do {
        u32 pad = ((block->addr + mask) & ~mask) - block->addr;
        u32 need = size + pad;
        if (!block->used && block->size >= need) {
            u32 rest = block->size - need;
            if (rest > 0x10) {
                spare->size = rest;
                spare->addr = block->addr + need;
                spare->prev = block;
                spare->next = block->next;
                if (spare->next != NULL) {
                    spare->next->prev = spare;
                }
                block->size = need;
                block->next = spare;
            }
            block->addr += pad;
            block->used = TRUE;
            block->pad = pad;
            return block;
        }
        block = block->next;
    } while (block != NULL);
    return NULL;
}

}
