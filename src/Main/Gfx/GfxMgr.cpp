#include "Main/Gfx/GfxMgr.h"
#include "Main/Res/ResLoader.h"

extern "C" {

extern u8 data_02097ce4[];


extern void GfxMgr_Init(GfxMgr *mgr);
extern void *GfxMgr_AllocCharBlock(GfxMgr *mgr, void *arg1, void *arg2, void *arg3);
extern void *func_0203a984(GfxMgr *mgr, void *arg1, void *arg2);
extern VramBlock *GfxMgr_FreeBlock(GfxMgr *mgr, VramBlock *block);
extern ResList *ResMgr_LoadArcListSync(const char *name);
extern void *ResList_FindType1(ResList *list, const char *name);

void *func_02039720(void) {
    return data_02097ce4;
}

void *func_0203972c(void *arg1, void *arg2) {
    return func_0203a984(gGfxMgr, arg1, arg2);
}

void GfxMgr_Create(void) {
    GfxMgr *mgr;
    int j;
    int i;
    if (gGfxMgr != NULL) {
        return;
    }
    gGfxMgr = (GfxMgr *)Heap_AllocLo(sizeof(GfxMgr), 4);
    GfxMgr_Init(gGfxMgr);
    mgr = gGfxMgr;
    for (i = 0; i < 10; i++) {
        mgr->fonts[i] = NULL;
        for (j = 0; j < 9; j++) {
            if (i == data_020827f8[j].index) {
                mgr->fonts[i] = (GfxFont *)ResList_FindType1(ResMgr_LoadArcListSync(data_020827f8[j].name), data_020827f8[j].name);
                mgr->fontHeights[i] = mgr->fonts[i]->res->info[6];
            }
        }
    }
}

void *VramBlock_AllocChar(void *arg1, void *arg2, void *arg3) {
    return GfxMgr_AllocCharBlock(gGfxMgr, arg1, arg2, arg3);
}

VramBlock *VramBlock_Free(VramBlock *block) {
    return GfxMgr_FreeBlock(gGfxMgr, block);
}

VramBlock *GfxMgr_AllocPoolBlock(GfxMgr *mgr, VramPool *pool, u32 size) {
    int i;
    u32 mask;
    VramBlock *block;
    int count;
    VramBlock *spare;
    block = pool->blocks;
    if (size == 0) {
        size = 0x20;
    }
    count = pool->numBlocks;
    // One variable for the alignment and then its mask (round cmA); a separate align local swaps the
    // registers of i and the alignment.
    mask = 0x20 << pool->alignShift;
    spare = block;
    for (i = 0; i < count; i++, spare++) {
        if (spare->size == 0) {
            break;
        }
    }
    if (i == pool->numBlocks) {
        return NULL;
    }
    mask -= 1;
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
