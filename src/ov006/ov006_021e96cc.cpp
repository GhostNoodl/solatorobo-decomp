#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {

extern char data_ov006_021ec4ad[];
extern char data_ov006_021ec4e0[];
void func_ov000_021987b8(ActorSub48 *col, s32 a, VecFx32 *b, Rot16 *c);
void func_ov000_02198e34(ActorSub48 *col, Rot16 *out, VecFx32 *v, s32 a);
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

static inline void ov006_RotYX(MtxFx33 *m, const Rot16 *rot) {
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

void func_ov006_021e96cc(Ov006Racer *self) {
    VecFx32 v;
    MtxFx33 m;
    VecFx32 p;
    s32 f;
    s8 kind;

    v.z = MUL(self->runSpeed, 0x3800);
    v.x = 0;
    v.y = 0;
    ov006_RotYX(&m, &self->look2);
    MTX_MultVec33(&v, &m, &v);
    ov006_Approach(&self->vel, &v, 0xf33);
    if (self->vel.y <= 1 && self->vel.y >= -1) {
        self->vel.y = 0;
    }
    VEC_Add(&self->unk_1c0, &self->vel, &self->unk_1c0);
    if (self->unk_1f4 != 0) {
        self->unk_1f4--;
    }
    f = 0;
    func_ov000_021987b8(self->hit, f, &self->unk_1c0, &self->rot);
    if (self->hit->unk_50 == 0) {
        return;
    }
    if (self->runSpeed < 0x266) {
        self->runSpeed -= 0xc;
    } else {
        Rot16 a;
        Rot16 b;
        kind = self->prm->unk_08;
        func_ov000_02198e34(self->hit, &a, &self->vel, 0);
        func_ov000_02198e34(self->hit, &b, &self->vel, 1);
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
            u16 dd = a.y - self->look2.y;
            if (dd > 0x8000) {
                dd = -dd;
            }
            self->runSpeed -= self->runSpeed * dd / 0x8000;
        }
        if (data_ov006_021ec860->unk1C == 0 && self->idx != data_ov006_021ec884->unk5) {
            if ((func_ov006_021dab98(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5))->unk3 & 3) < (u32)self->rank) {
                f = 0;
            }
        }
        if (f != 0) {
            self->runSpeed -= MUL(self->runSpeed, f);
        }
        if (self->unk_1f4 == 0) {
            if (data_ov006_021ec884->unk13D == 0) {
                if (++self->unk_21e[3] > 99) {
                    self->unk_21e[3] = 99;
                }
            }
            if (self->unk_19c_0 & 1) {
                BOOL c = FALSE;
                if (self->unk_19f > data_ov006_021ec884->info->unkB) {
                    c = TRUE;
                }
                if (!c && data_ov006_021ec884->unk13D == 0) {
                    ActorSub48 *col = self->hit;
                    s32 nx = col->unk_80;
                    s32 ny = col->unk_84;
                    s32 nz = col->unk_88;
                    p = col->unk_74;
                    if ((col->unk_50 & 0xf0f0f0) == 0x90b0c0) {
                        void *e = Effect3D_Create(data_ov006_021ec4ad, data_ov006_021ec4e0, data_ov006_021ec4e0, &self->pos);
                        if (e != NULL) {
                            ((u8 *)e)[0x28] = 0;
                            VCALL(e, 34, b.x, b.y, 0);
                            VCALL(e, 0c, 0x3ccd);
                        }
                        if (self->idx == data_ov006_021ec884->unk5) {
                            func_02049f44(data_02097e4c, 0x35, &p, 0);
                        }
                    } else {
                        void *e = func_02065f88(0x66, &p);
                        if (e != NULL) {
                            VCALL(e, 34, FX_AcosIdx(ny), FX_Atan2(nx, nz), 0);
                        }
                        if (self->idx == data_ov006_021ec884->unk5) {
                            func_02049f44(data_02097e4c, 0x52, &p, 0);
                        }
                    }
                }
            }
            self->unk_1f4 = 5;
        }
    }
    if (self->runSpeed < 0xcd) {
        self->runSpeed = 0xcd;
    }
}

}
