#include "Main/Effect/Effect.h"

extern "C" {

BOOL func_0206aad4(EffectPartSet *s, EffectPartSlot *slot) {
    EffectPtcl *p;
    s32 rate = slot->rate;
    for (p = s->ptcls; p != NULL; p = p->next) {
        p->speed += rate;
    }
    return TRUE;
}

BOOL func_0206ab04(EffectPartSet *s, EffectPartSlot *slot) {
    return FALSE;
}

#define EFF_G3_REG(addr) (*(volatile u32 *)(addr))

static inline void EffG3_Translate(s32 x, s32 y, s32 z) {
    EFF_G3_REG(0x04000470) = x;
    EFF_G3_REG(0x04000470) = y;
    EFF_G3_REG(0x04000470) = z;
}

static inline void EffG3_Vtx(s16 x, s16 y, s16 z) {
    EFF_G3_REG(0x0400048c) = (u32)(u16)x | ((u32)(u16)y << 16);
    EFF_G3_REG(0x0400048c) = (u32)(u16)z;
}

extern const u16 data_02082bdc[];

void func_0206ab0c(EffectPartSet *s) {
    EffectPartSlot *slot;
    EffectVec v;
    s16 x0;
    s16 y0;
    s16 z0;
    s16 x1;
    s16 y1;
    s16 z1;
    s16 x2;
    s16 y2;
    s16 z2;
    int i;
    NNS_G3dGlbFlushP();
    EFF_G3_REG(0x040004a4) = 0x1f00c0;
    EFF_G3_REG(0x040004a8) = 0x20000000;
    EFF_G3_REG(0x04000440) = 2;
    for (i = 0; i < 4 && s->slots[i].used; i++) {
        slot = &s->slots[i];
        EFF_G3_REG(0x04000444) = 0;
        if (slot->unk_10 == 0) {
            VEC_Add(&slot->vec2, &s->pos, &v);
        } else if (slot->unk_10 == 1) {
            v = slot->vec2;
        } else {
            v.x = 0;
            v.y = 0;
            v.z = 0;
        }
        EffG3_Translate(v.x, v.y, v.z);
        switch (slot->type) {
        case 0:
        case 2:
        case 4:
            x0 = 0;
            y0 = 0;
            z0 = 0;
            z1 = slot->vec.z;
            y1 = slot->vec.y;
            x1 = slot->vec.x;
            x2 = x1;
            y2 = y1;
            z2 = z1;
            break;
        case 1:
        case 3:
            x0 = 0;
            y0 = 0;
            z0 = 0;
            x1 = 0;
            y1 = 0;
            z1 = 0x400;
            x2 = 0x400;
            y2 = 0;
            z2 = 0;
            break;
        }
        EFF_G3_REG(0x04000500) = 0;
        EFF_G3_REG(0x04000480) = data_02082bdc[i];
        EffG3_Vtx(x0, y0, z0);
        EffG3_Vtx(x1, y1, z1);
        EffG3_Vtx(x2, y2, z2);
        EFF_G3_REG(0x04000504) = 0;
        EFF_G3_REG(0x04000448) = 1;
    }
}

}
