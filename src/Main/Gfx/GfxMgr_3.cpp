#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern VramBlock *func_02039844(GfxMgr *mgr, VramPool *pool, u32 size);
extern void func_0203aab0(GfxMgr *mgr, void *arg);
extern void func_0203acb8(GfxMgr *mgr, void *arg);

VramBlock *func_0203a408(GfxMgr *mgr, int width, int height, BOOL temporary) {
    VramBlock *block;
    u32 size = (((width + 7) >> 3) * ((height + 7) >> 3)) << 5;
    if (data_020827f8[mgr->unk_004].mode == 4) {
        block = func_02039844(mgr, &mgr->pools[0], size);
        block->kind = 4;
    } else {
        block = func_02039844(mgr, &mgr->pools[1], size);
        block->kind = 3;
    }
    block->temporary = temporary;
    block->unk_10_2 = 0;
    block->unk_10_29 = 1;
    block->unk_10_30 = 1;
    block->unk_14 = 0;
    return block;
}

GfxCell *func_0203a4a4(GfxMgr *mgr) {
    return &mgr->cells[mgr->unk_046++];
}

void *func_0203a4c0(GfxMgr *mgr) {
    return &mgr->fonts[mgr->unk_004]->res;
}

void func_0203a4d4(GfxMgr *mgr, void *arg) {
    mgr->unk_658 = (u32)arg;
}

void func_0203a4dc(GfxMgr *mgr, void *arg) {
    mgr->unk_65c = (u32)arg;
}

static inline bool GfxSys_IsFlag(GfxSys *sys) {
    return sys->unk_a30_4 ? TRUE : FALSE;
}

void func_0203a4e4(GfxMgr *mgr, void *arg) {
    switch (data_020827f8[mgr->unk_004].mode) {
    case 0:
        break;
    case 1:
        if (data_02097d48->state == 2 && !GfxSys_IsFlag(data_02097d48)) {
            break;
        }
        func_0203aab0(mgr, arg);
        break;
    case 2:
        if (data_02097d48->state == 2 && !data_02097d48->unk_a30_4) {
            func_0203aab0(mgr, arg);
        }
        break;
    case 3:
    case 4:
        if (data_02097d48->state == 1) {
            func_0203acb8(mgr, arg);
        }
        break;
    }
}

}
