#include "ov011/ov011.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd64;
extern Ov011Vec data_02092a50;
extern Ov011Vec data_02092a38;
extern char data_ov011_022075d4[];
s32 *NNS_G3dGlbGetInvV(void);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);
void VEC_Normalize(const Ov011Vec *src, Ov011Vec *dst);
u16 FX_Atan(s32 x);
u16 FX_Atan2(s32 y, s32 x);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
Ov011V *func_020657b0(void *mgr, s32 h);
s32 func_02040528(s32 max);
void *func_ov000_0219be1c(s32 id, Ov011Vec *pos, u16 *rot, u16 a, u16 b);
void func_ov000_0218bed8(void *mgr, s32 a, void *self);

static inline void Ov011_MulVec33(const Ov011Vec *v, const s32 *m, Ov011Vec *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

void func_ov011_02204428(Ov011Actor *self) {
    Ov011Vec v;
    Ov011Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        s->timer++;
        if (s->timer > 0xf0) {
            FLD(u16, self, 0xfe) = 0;
            FLD(u8, self->unk_38, 0xbe) = 0x1f;
            self->unk_40->timer = 0;
            self->unk_40->state = 10;
        } else {
            u8 a = self->unk_40->timer >> 2;
            if (a >= 0x1f) {
                a = 0x1f;
            }
            FLD(u8, self->unk_38, 0xbe) = a;
            self->unk_9c = 0x29;
        }
        break;
    case 10:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            Ov011V *e;
            FLD(Ov011Vec, self, 0x104) = self->unk_84;
            if (FLD(u16, self, 0xfe) & 1) {
                FLD(s32, self, 0x104) += 0x5800;
            } else {
                FLD(s32, self, 0x104) -= 0x5800;
            }
            FLD(s32, self, 0x108) += 0x2000;
            FLD(s32, self, 0x10c) += 0x800;
            FLD(s32, self, 0x100) = 0;
            FLD(u16, self, 0xde) = 0xffff;
            Ov011_MulVec33(&FLD(Ov011Vec, self, 0x104), NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e != NULL) {
                FLD(s32, self, 0x100) = FLD(s32, e, 0x24);
                e->v0c(0x4800);
                FLD(s32, e, 0x3c) = 0x1ccd;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0x14;
        }
        break;
    case 11:
        if (self->unk_40->timer != 0) {
            self->unk_40->timer--;
        }
        if (FLD(s32, self, 0x100) != 0) {
            Ov011V *e = func_020657b0(data_0214a420, FLD(s32, self, 0x100));
            if (e != NULL) {
                if (self->unk_40->timer == 0) {
                    FLD(s32, e, 0x1c) = 4;
                    FLD(s32, self, 0x100) = 0;
                } else {
                    Ov011_MulVec33(&FLD(Ov011Vec, self, 0x104), NNS_G3dGlbGetInvV(), &v);
                    VEC_Add(&v, &data_02092a50, &v);
                    e->v18(&v);
                }
            }
        }
        if (self->unk_40->timer == 0) {
            Ov011Actor *pl = (Ov011Actor *)func_ov000_0219bf90();
            if (pl != NULL) {
                Ov011Vec d;
                u16 rot[3];
                void *r;
                d = FLD(Ov011Vec, pl, 0xaf0);
                d.y += 0x3000;
                d.x -= FLD(s32, self, 0x104);
                d.y -= FLD(s32, self, 0x108);
                d.z -= FLD(s32, self, 0x10c);
                VEC_Normalize(&d, &d);
                rot[0] = FX_Atan(-d.y);
                rot[1] = FX_Atan2(d.x, d.z);
                rot[2] = 0;
                if (FLD(u16, self, 0xfe) & 1) {
                    rot[1] += 0x4000;
                } else {
                    rot[1] -= 0x4000;
                }
                r = func_ov000_0219be1c(0x4804, &FLD(Ov011Vec, self, 0x104), rot, self->id, pl->id);
                if (r != NULL) {
                    FLD(char *, r, 0x60) = data_ov011_022075d4;
                }
            }
            FLD(u16, self, 0xfe)++;
            if (FLD(u16, self, 0xfe) >= 0x12) {
                self->unk_40->timer = 0x78;
                self->unk_40->state = 0x14;
            } else {
                if (FLD(u16, self, 0xfe) == 6 || FLD(u16, self, 0xfe) == 0xc) {
                    self->unk_40->timer = 0x5a;
                } else {
                    self->unk_40->timer = 0xa;
                }
                self->unk_40->state = 10;
            }
        }
        break;
    case 0x14:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            Ov011_VecSet(&self->unk_84, 0, 0x1e000, -0x12000);
            self->unk_9c = 0x29;
            self->unk_40->timer = 0x96;
            self->unk_40->state++;
        }
        break;
    case 0x15:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
    v.x = self->unk_84.x - FLD(s32, self, 0xf0);
    v.y = self->unk_84.y - FLD(s32, self, 0xf4);
    v.z = self->unk_84.z - FLD(s32, self, 0xf8);
    VEC_MultAdd(self->unk_9c, &v, &FLD(Ov011Vec, self, 0xf0), &FLD(Ov011Vec, self, 0xf0));
    Ov011_VecSet(&v, 0, 0, 0);
    if (FLD(u16, self, 0xfc) != 0) {
        FLD(u16, self, 0xfc)--;
        Ov011_VecSet(&v, func_02040528(0x800), func_02040528(0x800), func_02040528(0x800));
    }
    VEC_Add(&v, &FLD(Ov011Vec, self, 0xf0), &v);
    Ov011_MulVec33(&v, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
    {
        const s32 *b = (const s32 *)&data_02092a38;
        const s32 *a = (const s32 *)&data_02092a50;
        self->rot[1] = FX_Atan2(b[0] - a[0], b[2] - a[2]);
    }
}
}
