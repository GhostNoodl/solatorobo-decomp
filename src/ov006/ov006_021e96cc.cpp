#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Rot021e96cc {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e96cc;

typedef struct ov006_Col021e96cc {
    u8 unk0[0x50];
    u32 unk50;
    u8 unk54[0x20];
    VecFx32 pos;
    VecFx32 nrm;
} ov006_Col021e96cc;

typedef struct ov006_Car021e96cc {
    u8 unk0[0x48];
    ov006_Col021e96cc *col;
    u8 unk4C[0x24];
    VecFx32 pos;
    VecFx32 unk7C;
    u8 unk88[0x14];
    VecFx32 vel;
    u8 unkA8[4];
    s8 *unkAC;
    u8 unkB0[0xec];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 14;
    u8 unk19E;
    u8 unk19F;
    s32 speed;
    u8 unk1A4[9];
    u8 unk1AD;
    ov006_Rot021e96cc look;
    u8 unk1B4[6];
    ov006_Rot021e96cc rot;
    VecFx32 unk1C0;
    u8 unk1CC[0x28];
    u8 unk1F4;
    u8 unk1F5[0x2c];
    u8 unk221;
} ov006_Car021e96cc;

extern "C" {

extern void *data_02097e4c;
extern char data_ov006_021ec4ad[];
extern char data_ov006_021ec4e0[];
void *func_02065f88(s32 id, VecFx32 *pos);
void *func_02066774(const char *a, const char *b, const char *c, VecFx32 *pos);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
void func_ov000_021987b8(ov006_Col021e96cc *col, s32 a, VecFx32 *b, VecFx32 *c);
void func_ov000_02198e34(ov006_Col021e96cc *col, ov006_Rot021e96cc *out, VecFx32 *v, s32 a);
ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx);
ov006_SlotSub *func_ov006_021dab98(ov006_Slot *self);

#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]
#define MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline void ov006_MidTo(u16 *out, u16 *a, u16 *b) {
    u16 d = *b;
    d -= *a;
    if (d > 0x8000) {
        d = -d;
        *out = *a - (d >> 1);
    } else {
        *out = *a + (d >> 1);
    }
}

static inline void ov006_RotYX(MtxFx33 *m, const ov006_Rot021e96cc *rot) {
    MtxFx33 t;
    BOOL any = FALSE;
    u16 ry;
    u16 rx;
    ry = rot->y;
    rx = rot->x;
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
        }
    }
}

static inline void ov006_Approach(VecFx32 *cur, const VecFx32 *tgt, fx32 k) {
    VecFx32 d;
    d.x = tgt->x - cur->x;
    d.y = tgt->y - cur->y;
    d.z = tgt->z - cur->z;
    VEC_MultAdd(k, &d, cur, cur);
}

void func_ov006_021e96cc(ov006_Car021e96cc *self) {
    VecFx32 v;
    MtxFx33 m;
    VecFx32 p;
    s32 f;
    s8 kind;

    v.z = MUL(self->speed, 0x3800);
    v.x = 0;
    v.y = 0;
    ov006_RotYX(&m, &self->rot);
    MTX_MultVec33(&v, &m, &v);
    ov006_Approach(&self->vel, &v, 0xf33);
    if (self->vel.y <= 1 && self->vel.y >= -1) {
        self->vel.y = 0;
    }
    VEC_Add(&self->unk1C0, &self->vel, &self->unk1C0);
    if (self->unk1F4 != 0) {
        self->unk1F4--;
    }
    f = 0;
    func_ov000_021987b8(self->col, f, &self->unk1C0, &self->unk7C);
    if (self->col->unk50 == 0) {
        return;
    }
    if (self->speed < 0x266) {
        self->speed -= 0xc;
    } else {
        ov006_Rot021e96cc a;
        ov006_Rot021e96cc b;
        kind = self->unkAC[8];
        func_ov000_02198e34(self->col, &a, &self->vel, 0);
        func_ov000_02198e34(self->col, &b, &self->vel, 1);
        switch (kind) {
        case 0:
            f += 0x148;
        case 1:
            f += 0x148;
        case 2:
            self->look.y = a.y;
            f += 0x2e1;
            self->look.x = a.x;
            break;
        case 3:
            f += 0x148;
        case 4:
            f += 0x148;
        case 5:
            f += 0x2e1;
            u16 bx = b.x;
            ov006_MidTo(&self->look.y, &a.y, &b.y);
            ov006_MidTo(&self->look.x, &a.x, &bx);
            break;
        case 6:
            f += 0x148;
        case 7:
            f += 0x148;
        case 8:
            self->look.y = b.y;
            f += 0x2e1;
            self->look.x = b.x;
            break;
        }
        {
            u16 dd = a.y - self->rot.y;
            if (dd > 0x8000) {
                dd = -dd;
            }
            self->speed -= self->speed * dd / 0x8000;
        }
        if (data_ov006_021ec860->unk1C == 0 && self->unk19E != data_ov006_021ec884->unk5) {
            if ((func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5))->unk3 & 3) < (u32)self->unk1AD) {
                f = 0;
            }
        }
        if (f != 0) {
            self->speed -= MUL(self->speed, f);
        }
        if (self->unk1F4 == 0) {
            if (data_ov006_021ec884->unk13D == 0) {
                if (++self->unk221 > 99) {
                    self->unk221 = 99;
                }
            }
            if (self->unk19C_0 & 1) {
                BOOL c = FALSE;
                if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
                    c = TRUE;
                }
                if (!c && data_ov006_021ec884->unk13D == 0) {
                    ov006_Col021e96cc *col = self->col;
                    s32 nx = col->nrm.x;
                    s32 ny = col->nrm.y;
                    s32 nz = col->nrm.z;
                    p = col->pos;
                    if ((col->unk50 & 0xf0f0f0) == 0x90b0c0) {
                        void *e = func_02066774(data_ov006_021ec4ad, data_ov006_021ec4e0, data_ov006_021ec4e0, &self->pos);
                        if (e != NULL) {
                            ((u8 *)e)[0x28] = 0;
                            VCALL(e, 34, b.x, b.y, 0);
                            VCALL(e, 0C, 0x3ccd);
                        }
                        if (self->unk19E == data_ov006_021ec884->unk5) {
                            func_02049f44(data_02097e4c, 0x35, &p, 0);
                        }
                    } else {
                        void *e = func_02065f88(0x66, &p);
                        if (e != NULL) {
                            VCALL(e, 34, FX_AcosIdx(ny), FX_Atan2(nx, nz), 0);
                        }
                        if (self->unk19E == data_ov006_021ec884->unk5) {
                            func_02049f44(data_02097e4c, 0x52, &p, 0);
                        }
                    }
                }
            }
            self->unk1F4 = 5;
        }
    }
    if (self->speed < 0xcd) {
        self->speed = 0xcd;
    }
}

}
