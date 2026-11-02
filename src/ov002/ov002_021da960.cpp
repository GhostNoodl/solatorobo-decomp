#include "ov002/ov002.h"

extern "C" {


BOOL func_ov000_021903b4(void *a);

void func_ov002_021da960(void *self) {
    u8 *w = FIELD(self, 0x4, u8 *);
    u8 *cam = FIELD(w, 0x8c, u8 *);
    u8 *q;
    u8 *n;
    NNS_G3dGlb.camPos = FIELD(cam, 0x0, VecFx32);
    NNS_G3dGlb.camUp = FIELD(cam, 0x18, VecFx32);
    NNS_G3dGlb.camTarget = FIELD(cam, 0xc, VecFx32);
    MTX_LookAt((VecFx32 *)cam, (VecFx32 *)(cam + 0x18), (VecFx32 *)(cam + 0xc), (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MTX_PerspectiveW(FX_SINCOS(0x2aa), FX_SINCOS(0x2ab), 0x1548, 0x333, 0x19000, 0x1000, (MtxFx44 *)data_02092800);
    NNS_G3dGlb.flag &= ~0x50;
    q = FIELD(w, 0x4, u8 *);
    if (q[0x5c] != 0) {
        MI_Copy36B(q + 0x2c, FIELD(q, 0x8, u8 *) + 0x84);
        FIELD(FIELD(q, 0x8, u8 *), 0x78, VecFx32) = FIELD(q, 0x18, VecFx32);
        FIELD(FIELD(q, 0x8, u8 *), 0xa8, VecFx32) = FIELD(q, 0x50, VecFx32);
        func_ov000_021903b4(FIELD(q, 0x8, void *));
        MI_Copy36B(q + 0x2c, FIELD(q, 0x10, u8 *) + 0x84);
        FIELD(FIELD(q, 0x10, u8 *), 0x78, VecFx32) = FIELD(q, 0x18, VecFx32);
        FIELD(FIELD(q, 0x10, u8 *), 0xa8, VecFx32) = FIELD(q, 0x50, VecFx32);
        func_ov000_021903b4(FIELD(q, 0x10, void *));
    }
    for (n = FIELD(w, 0x6c, u8 *); n != NULL; n = FIELD(n, 0x70, u8 *)) {
        if (n[0x4a] == 2) {
            FIELD(n, 0xac, s32) = FIELD(n, 0xa8, u16) <= FIELD(w, 0x8a, u16) ? 2 : 1;
        }
        ((VObject *)n)->v0x10();
    }
    if (FIELD(self, 0x8, VObject *) != NULL) {
        FIELD(self, 0x8, VObject *)->v0x14();
    }
}


void func_ov002_021dab58(void *self, s32 mode) {
    VObject *p;
    if (FIELD(self, 0x8, void *) != NULL && FIELD(self, 0xc, s32) == mode) {
        return;
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 0x8, VObject *));
        HEAP_POP(saved);
    }
    switch (mode) {
    case 0:
        p = (VObject *)Heap_Alloc(0x24);
        if (p != NULL) {
            FIELD(p, 0x4, s32) = 0;
            *(VFunc **)p = data_ov002_021eff74;
            FIELD(p, 0x8, s32) = 0;
            FIELD(p, 0xc, s32) = 0;
            FIELD(p, 0x10, s32) = 0;
            FIELD(p, 0x14, s32) = 0;
            FIELD(p, 0x18, s32) = 0;
            FIELD(p, 0x1c, s32) = 0;
            FIELD(p, 0x20, u8) = 0;
        }
        FIELD(self, 0x8, VObject *) = p;
        FIELD(p, 0x4, s32) = FIELD(self, 0x4, s32);
        FIELD(self, 0x8, VObject *)->v0x8();
        break;
    case 1:
        p = (VObject *)Heap_Alloc(0x38);
        if (p != NULL) {
            FIELD(p, 0x4, s32) = 0;
            *(VFunc **)p = data_ov002_021eff50;
            FIELD(p, 0x8, s32) = 1;
            FIELD(p, 0xc, s32) = -1;
            FIELD(p, 0x10, s32) = 0;
            FIELD(p, 0x14, s32) = 0;
            FIELD(p, 0x18, s32) = 0;
            FIELD(p, 0x20, s32) = 0;
            FIELD(p, 0x24, s32) = 0;
            FIELD(p, 0x34, s32) = 0;
        }
        FIELD(self, 0x8, VObject *) = p;
        FIELD(p, 0x4, s32) = FIELD(self, 0x4, s32);
        FIELD(self, 0x8, VObject *)->v0x8();
        break;
    case 2:
        break;
    case 3:
        break;
    }
    FIELD(self, 0xc, s32) = mode;
}

}
