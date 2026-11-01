#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bits18_021b4130;

extern "C" {
extern u8 *data_ov000_021ccd68;
void *func_ov000_0218e640(void *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u16 angle);

static inline void VecSet_021b4130(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline u8 *FindActor_021b4130(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov000_021b4130(Robo021ca458 *self, BOOL flag) {
    VecFx32 v;
    MtxFx43 m;
    u8 *a;
    u8 *o;
    a = FindActor_021b4130(self->unk_b1c);
    if (a == NULL) {
        return;
    }
    o = LFLD(u8 *, a, 0x4c);
    switch (self->unk_b24_7) {
    default:
        MTX_Identity43_(&m);
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa50, &m);
            VEC_Add(&LFLD(VecFx32, self, 0xa74), &LFLD(VecFx32, self, 0xaa4), &v);
            v.x = FX_Mul(v.x, 0x800);
            v.y = FX_Mul(v.y, 0x800);
            v.z = FX_Mul(v.z, 0x800);
            if (o != NULL) {
                LFLD(Bits18_021b4130, o, 0x18).b0 = 0;
            }
            if (self->unk_b22_3) {
                v.y -= (FX_SinCosTable_[((u16)(LFLD(u16, data_ov000_021ccd68, 0xa) << 9) >> 4) * 2] + 0x1400) >> 2;
                v.x += FX_SinCosTable_[(self->rot_y >> 4) * 2] >> 1;
                v.z += FX_SinCosTable_[(self->rot_y >> 4) * 2 + 1] >> 1;
            } else if (self->unk_b2c_1) {
                VecFx32 t;
                t.x = LFLD(s32, a, 0x64) >> 1;
                t.y = 0;
                t.z = 0;
                MTX_MultVec33(&t, (MtxFx33 *)&m, &t);
                VEC_Add(&v, &t, &v);
                v.y -= 0x1800;
                if (o != NULL) {
                    LFLD(Bits18_021b4130, o, 0x18).b0 = 1;
                }
            } else if (self->unk_b2c_0) {
                u16 r = self->rot_y;
                s32 sn = FX_SinCosTable_[(r >> 4) * 2];
                s32 cs = FX_SinCosTable_[(r >> 4) * 2 + 1];
                s32 d = LFLD(s32, a, 0x64);
                sn = FX_Mul(d, sn);
                cs = FX_Mul(d, cs);
                v.x += sn;
                v.z += cs;
                v.y -= 0x800;
            } else if (self->unk_b2c_2) {
                VecFx32 t;
                t.x = LFLD(s32, a, 0x64);
                t.y = -0xc00;
                t.z = 0;
                MTX_MultVec33(&t, (MtxFx33 *)&m, &t);
                VEC_Add(&v, &t, &v);
                if (o != NULL) {
                    LFLD(Bits18_021b4130, o, 0x18).b0 = 1;
                }
            }
        } else {
            VecSet_021b4130(&v, self->unk_75c.x, self->unk_75c.y + self->unk_68, self->unk_75c.z);
        }
        m.m[3][0] = v.x;
        m.m[3][1] = v.y;
        m.m[3][2] = v.z;
        MI_Copy48B(&m, o + 0x20);
        return;
    case 0:
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa50, o + 0x20);
            return;
        }
        VecSet_021b4130(&v, -0xccd, self->unk_68 >> 1, 0xccd);
        func_01ffc9fc(&v, &v, self->rot_y);
        VEC_Add(&v, &self->unk_75c, &v);
        LFLD(VecFx32, o, 0x44) = v;
        return;
    case 1:
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa80, o + 0x20);
            return;
        }
        VecSet_021b4130(&v, 0xccd, self->unk_68 >> 1, 0xccd);
        func_01ffc9fc(&v, &v, self->rot_y);
        VEC_Add(&v, &self->unk_75c, &v);
        LFLD(VecFx32, o, 0x44) = v;
        return;
    }
}

}
