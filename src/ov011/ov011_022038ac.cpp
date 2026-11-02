#include "ov011/ov011.h"

struct Ov011Rot {
    u16 x, y, z;
};

struct Ov011PathEnt {
    VecFx32 a;
    u16 dur0;
    s16 spd0;
    VecFx32 b;
    u16 dur1;
    s16 spd1;
    VecFx32 c;
    u16 dur2;
    s16 spd2;
};

extern "C" {

s32 Rand_PlusMinus(s32 max);
extern const VecFx32 data_02092a50;
extern const VecFx32 data_02092a38;
extern const Ov011PathEnt data_ov011_022076a0[];
extern u8 data_ov011_02207598[];
Actor *func_ov000_0219be1c(s32 kind, VecFx32 *pos, Ov011Rot *rot, u16 a, u16 b);

u32 Rand_UpTo(u32 max);

void func_ov011_022038ac(Ov011Act7cf8 *self) {
    VecFx32 d;
    VecFx32 v;
    Ov011Rot r;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        switch ((u8)self->unk_1a) {
        default:
            self->moveYaw = Rand_UpTo(0xffff);
            d.x = 0;
            break;
        case 1:
            self->moveYaw = Rand_UpTo(0x7fff) + 0x4000;
            d.x = -0x4000;
            break;
        case 2:
            self->moveYaw = Rand_UpTo(0x7fff) + 0xc000;
            d.x = 0x4000;
            break;
        }
        {
            self->speed = 0xcd;
            self->unk_84.x = FX_Mul(OV011_COS(self->moveYaw), 0x2000);
            self->unk_84.y = FX_Mul(OV011_SIN(self->moveYaw), 0x2000);
            self->unk_84.z = 0;
            self->unk_f0.x = FX_Mul(self->unk_84.x, 0x9000);
            self->unk_f0.y = FX_Mul(self->unk_84.y, 0x9000);
            self->unk_f0.z = FX_Mul(self->unk_84.z, 0x9000);
        }
        self->unk_84.x += d.x;
        self->unk_f0.x += d.x;
        self->unk_84.z = Rand_PlusMinus(0x2000) - 0x12000;
        self->unk_f0.z = self->unk_84.z;
        self->fsm->st++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 0x4b) {
            self->speed = 0x29;
            self->fsm->timer = 0;
            self->fsm->st++;
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
                Actor *o;
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
        if (self->fsm->timer > 0x41) {
            self->moveYaw += (u16)(Rand_PlusMinus(0x1000) + 0x8000);
            self->unk_84.x = FX_Mul(OV011_COS(self->moveYaw), 0x16000);
            self->unk_84.y = FX_Mul(OV011_SIN(self->moveYaw), 0x16000);
            self->unk_84.z = -0x12000;
            self->speed = 0x3d;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 3:
        st->timer++;
        if (st->timer == 0xf) {
            self->speed = 0xcd;
        }
        if (self->fsm->timer > 0x41) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
    d.x = self->unk_84.x - self->unk_f0.x;
    d.y = self->unk_84.y - self->unk_f0.y;
    d.z = self->unk_84.z - self->unk_f0.z;
    VEC_MultAdd(self->speed, &d, &self->unk_f0, &self->unk_f0);
    Ov011_MulVec33(&self->unk_f0, NNS_G3dGlbGetInvV(), &d);
    VEC_Add(&d, &data_02092a50, &self->pos);
    {
        const s32 *b = (const s32 *)&data_02092a38;
        const s32 *a = (const s32 *)&data_02092a50;
        self->rot_y = FX_Atan2(b[0] - a[0], b[2] - a[2]);
    }
}

}
