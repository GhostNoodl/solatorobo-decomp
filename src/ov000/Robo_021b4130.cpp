#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 7;
    u32 b7 : 2;
    u32 rest : 23;
} Bits24_021b4130;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} Bits22_021b4130;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 rest : 13;
} Bits2c_021b4130;

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

struct Obj021b4130 {
    u8 unk_00[0x68];
    s32 unk_68;
    u8 unk_6c[0x12];
    u16 unk_7e;
    u8 unk_80[0x6dc];
    VecFx32 unk_75c;
    u8 unk_768[0x30c];
    VecFx32 unk_a74;
    u8 unk_a80[0x24];
    VecFx32 unk_aa4;
    u8 unk_ab0[0x6c];
    u16 unk_b1c;
    u8 unk_b1e[0x4];
    Bits22_021b4130 unk_b22;
    Bits24_021b4130 unk_b24;
    u8 unk_b28[0x4];
    Bits2c_021b4130 unk_b2c;
};

void func_ov000_021b4130(Obj021b4130 *self, BOOL flag) {
    VecFx32 v;
    MtxFx43 m;
    u8 *a;
    u8 *o;
    a = FindActor_021b4130(self->unk_b1c);
    if (a == NULL) {
        return;
    }
    o = LFLD(u8 *, a, 0x4c);
    switch (self->unk_b24.b7) {
    default:
        MTX_Identity43_(&m);
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa50, &m);
            VEC_Add(&self->unk_a74, &self->unk_aa4, &v);
            v.x = FX_Mul(v.x, 0x800);
            v.y = FX_Mul(v.y, 0x800);
            v.z = FX_Mul(v.z, 0x800);
            if (o != NULL) {
                LFLD(Bits18_021b4130, o, 0x18).b0 = 0;
            }
            if (self->unk_b22.b3) {
                v.y -= (FX_SinCosTable_[((u16)(LFLD(u16, data_ov000_021ccd68, 0xa) << 9) >> 4) * 2] + 0x1400) >> 2;
                v.x += FX_SinCosTable_[(self->unk_7e >> 4) * 2] >> 1;
                v.z += FX_SinCosTable_[(self->unk_7e >> 4) * 2 + 1] >> 1;
            } else if (self->unk_b2c.b1) {
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
            } else if (self->unk_b2c.b0) {
                u16 r = self->unk_7e;
                s32 sn = FX_SinCosTable_[(r >> 4) * 2];
                s32 cs = FX_SinCosTable_[(r >> 4) * 2 + 1];
                s32 d = LFLD(s32, a, 0x64);
                sn = FX_Mul(d, sn);
                cs = FX_Mul(d, cs);
                v.x += sn;
                v.z += cs;
                v.y -= 0x800;
            } else if (self->unk_b2c.b2) {
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
        func_01ffc9fc(&v, &v, self->unk_7e);
        VEC_Add(&v, &self->unk_75c, &v);
        LFLD(VecFx32, o, 0x44) = v;
        return;
    case 1:
        if (flag) {
            MI_Copy48B((u8 *)self + 0xa80, o + 0x20);
            return;
        }
        VecSet_021b4130(&v, 0xccd, self->unk_68 >> 1, 0xccd);
        func_01ffc9fc(&v, &v, self->unk_7e);
        VEC_Add(&v, &self->unk_75c, &v);
        LFLD(VecFx32, o, 0x44) = v;
        return;
    }
}

}
