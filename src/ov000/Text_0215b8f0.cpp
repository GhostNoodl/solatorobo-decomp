#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u32 lo : 13;
    u32 alpha : 8;
    u32 hi : 11;
} Flags0215b8f0;

extern "C" {
u8 Gfx3DState_NextPolyId(void *p);
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);

void func_ov000_0215b8f0(LoBase021cafc0_021cb0b8 *self, s32 unused, VecFx32 *pos) {
    GfxSys *g;
    UiListItem *node;
    s32 i;
    s32 a;
    s32 x0;
    s32 y0;
    s32 lh;
    g = data_02097d48;
    node = self->items;
    i = 0;
    lh = self->vfunc_40();
    a = Gfx3DState_NextPolyId(g->unk_8b0);
    x0 = self->vfunc_30() + (self->width >> 1);
    y0 = self->vfunc_34();
    if (node == NULL) {
        return;
    }
    do {
        VObj *o;
        if (node->label == NULL) {
            func_ov000_02153c48(node, ((void *)self->font), 0, 0, 0);
        }
        node->label->vfunc_14();
        LFLD(s32, node->label, 0x70) = self->posZ - 0x100;
        LFLD(u32, node->label, 0x4) |= 0x200000;
        LFLD(Flags0215b8f0, node->label, 0x4).alpha = (u8)a;
        o = node->label;
        o->vfunc_20(x0 + (pos->x >> 12) - (LFLD(s32, o, 0x44) >> 1), y0 + (pos->y >> 12) + lh * i);
        node->label->vfunc_90();
        node = (UiListItem *)((u8 *)node->next);
        i++;
    } while (node != NULL);
}
}
