#include "ov011/ov011.h"

struct Ov011Rot {
    u16 x, y, z;
};

struct Ov011PathEnt {
    Ov011Vec a;
    u16 dur0;
    s16 spd0;
    Ov011Vec b;
    u16 dur1;
    s16 spd1;
    Ov011Vec c;
    u16 dur2;
    s16 spd2;
};

extern "C" {

s32 Rand_PlusMinus(s32 max);
s32 *NNS_G3dGlbGetInvV(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
void VEC_Normalize(const Ov011Vec *a, Ov011Vec *b);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);
u16 FX_Atan(s32 x);
u16 FX_Atan2(s32 y, s32 x);
extern const Ov011Vec data_02092a50;
extern const Ov011Vec data_02092a38;
extern const Ov011PathEnt data_ov011_022076a0[];
extern u8 data_ov011_02207598[];
extern void *data_ov000_021ccd64;
void *func_ov000_0219bf90(void);
Ov011Obj *func_ov000_0219be1c(s32 kind, Ov011Vec *pos, Ov011Rot *rot, u16 a, u16 b);
void func_ov000_0218bed8(void *mgr, s32 a, void *self);

static inline void Ov011_MulVec33(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}


s32 Rand_UpTo(s32 max);

void func_ov011_022038ac(Ov011Act7cf8 *self) {
    Ov011Vec d;
    Ov011Vec v;
    Ov011Rot r;
    Ov011Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        switch ((u8)self->unk_1a) {
        default:
            self->unk_98 = Rand_UpTo(0xffff);
            d.x = 0;
            break;
        case 1:
            self->unk_98 = Rand_UpTo(0x7fff) + 0x4000;
            d.x = -0x4000;
            break;
        case 2:
            self->unk_98 = Rand_UpTo(0x7fff) + 0xc000;
            d.x = 0x4000;
            break;
        }
        {
            self->unk_9c = 0xcd;
            self->unk_84.x = Ov011_FxMul(OV011_COS(self->unk_98), 0x2000);
            self->unk_84.y = Ov011_FxMul(OV011_SIN(self->unk_98), 0x2000);
            self->unk_84.z = 0;
            self->unk_f0.x = Ov011_FxMul(self->unk_84.x, 0x9000);
            self->unk_f0.y = Ov011_FxMul(self->unk_84.y, 0x9000);
            self->unk_f0.z = Ov011_FxMul(self->unk_84.z, 0x9000);
        }
        self->unk_84.x += d.x;
        self->unk_f0.x += d.x;
        self->unk_84.z = Rand_PlusMinus(0x2000) - 0x12000;
        self->unk_f0.z = self->unk_84.z;
        self->unk_40->state++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 0x4b) {
            self->unk_9c = 0x29;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        d.x = self->unk_84.x - self->unk_f0.x;
        d.y = self->unk_84.y - self->unk_f0.y;
        d.z = self->unk_84.z - self->unk_f0.z;
        VEC_MultAdd(0x19a, &d, &self->unk_f0, &self->unk_f0);
        break;
    case 2:
        st->timer++;
        if (st->timer == 0x32 && (self->unk_1a & 0x100)) {
            Ov011Player *pl = (Ov011Player *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Obj *o;
                v.x = pl->unk_af0.x;
                v.y = pl->unk_af0.y;
                v.z = pl->unk_af0.z;
                v.y += 0x3000;
                v.x -= self->unk_f0.x;
                v.y -= self->unk_f0.y;
                v.z -= self->unk_f0.z;
                VEC_Normalize(&v, &v);
                r.x = FX_Atan(-v.y);
                r.y = FX_Atan2(v.x, v.z);
                r.z = 0;
                o = func_ov000_0219be1c(0x4805, &self->unk_f0, &r, self->id, pl->id);
                if (o != NULL) {
                    o->unk_60 = data_ov011_02207598;
                }
            }
        }
        if (self->unk_40->timer > 0x41) {
            self->unk_98 += (u16)(Rand_PlusMinus(0x1000) + 0x8000);
            self->unk_84.x = Ov011_FxMul(OV011_COS(self->unk_98), 0x16000);
            self->unk_84.y = Ov011_FxMul(OV011_SIN(self->unk_98), 0x16000);
            self->unk_84.z = -0x12000;
            self->unk_9c = 0x3d;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 3:
        st->timer++;
        if (st->timer == 0xf) {
            self->unk_9c = 0xcd;
        }
        if (self->unk_40->timer > 0x41) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
    d.x = self->unk_84.x - self->unk_f0.x;
    d.y = self->unk_84.y - self->unk_f0.y;
    d.z = self->unk_84.z - self->unk_f0.z;
    VEC_MultAdd(self->unk_9c, &d, &self->unk_f0, &self->unk_f0);
    Ov011_MulVec33(&self->unk_f0, NNS_G3dGlbGetInvV(), &d);
    VEC_Add(&d, &data_02092a50, &self->pos);
    {
        const s32 *b = (const s32 *)&data_02092a38;
        const s32 *a = (const s32 *)&data_02092a50;
        self->rot[1] = FX_Atan2(b[0] - a[0], b[2] - a[2]);
    }
}

}
