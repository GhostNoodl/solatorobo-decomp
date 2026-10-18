#include "ov006/ov006.h"
#include <nitro/fx.h>

typedef struct ov006_Flags021eab60 {
    u16 b0 : 1;
    u16 rest : 15;
} ov006_Flags021eab60;

typedef struct ov006_Obj021eab60 {
    u8 unk0[0x18];
    u16 unk18;
    u8 unk1A[0x3e];
    void *unk58;
    u8 unk5C[0x14];
    VecFx32 pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk82[0x4a];
    ov006_Flags021eab60 unkCC;
} ov006_Obj021eab60;

extern "C" {

void func_0203f9dc(void *obj, MtxFx43 *m);
void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab);

#define OV006_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV006_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov006_021eab60(ov006_Obj021eab60 *self) {
    BOOL set;
    u16 rz;
    u16 ry;
    u16 rx;
    MtxFx43 m;
    MtxFx43 t;

    {
        u16 d = self->unk18;
        if (d == 0) {
            d = 0xff00;
        }
        self->rotZ += d;
    }
    self->unkCC.b0 = 1;
    set = FALSE;
    ry = self->rotY;
    rz = self->rotZ;
    rx = self->rotX;
    MTX_Identity43_(&m);
    if (ry != 0) {
        MTX_RotY43_(&m, OV006_SIN(ry), OV006_COS(ry));
        set = TRUE;
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV006_SIN(rx), OV006_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV006_SIN(rx), OV006_COS(rx));
            set = TRUE;
        }
    }
    if (rz != 0) {
        if (set) {
            MTX_RotZ43_(&t, OV006_SIN(rz), OV006_COS(rz));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotZ43_(&m, OV006_SIN(rz), OV006_COS(rz));
            set = TRUE;
        }
    }
    m.m[3][0] = self->pos.x;
    m.m[3][1] = self->pos.y;
    m.m[3][2] = self->pos.z;
    func_0203f9dc(self->unk58, &m);
}

}
