#include "nitro/fx.h"

typedef struct {
    u8 pad[0x84];
    MtxFx33 mtx;
} Obj02190758;

#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {

static inline void RotZYX(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL any = FALSE;
    rz = rot[2];
    ry = rot[1];
    rx = rot[0];
    MTX_Identity33_(m);
    if (rz != 0) {
        MTX_RotZ33_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY33_(&t, SC(ry));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
        }
    }
}

static inline void RotYXZ(MtxFx33 *m, const u16 *rot) {
    MtxFx33 t;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL any = FALSE;
    ry = rot[1];
    rz = rot[2];
    rx = rot[0];
    MTX_Identity33_(m);
    if (ry != 0) {
        MTX_RotY33_(m, SC(ry));
        any = TRUE;
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
            any = TRUE;
        }
    }
    if (rz != 0) {
        if (any) {
            MTX_RotZ33_(&t, SC(rz));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, SC(rz));
        }
    }
}

void func_ov000_02190758(Obj02190758 *self, const u16 *rot, BOOL order) {
    if (order == 0) {
        RotZYX(&self->mtx, rot);
    } else {
        RotYXZ(&self->mtx, rot);
    }
}

}
