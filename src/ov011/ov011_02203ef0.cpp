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

void func_ov011_02203ef0(Ov011Act7e50 *self) {
    VecFx32 d;
    VecFx32 v;
    Ov011Rot r;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        self->unk_f0 = data_ov011_022076a0[self->unk_1a].a;
        self->unk_84 = data_ov011_022076a0[self->unk_1a].b;
        self->speed = data_ov011_022076a0[self->unk_1a].spd0;
        st->st++;
        break;
    case 1: {
        s16 i = self->unk_1a;
        st->timer++;
        if (st->timer > data_ov011_022076a0[i].dur0) {
            self->speed = data_ov011_022076a0[self->unk_1a].spd1;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 2:
    case 3: {
        s16 i = self->unk_1a;
        st->timer++;
        if (st->timer > data_ov011_022076a0[i].dur1) {
            self->fsm->timer = 0;
            self->fsm->st++;
            break;
        }
        {
            u16 t = self->fsm->timer;
            if (t == 10 || t == 0x19 || t == 0x28) {
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
        }
        break;
    }
    case 4:
        self->unk_84 = data_ov011_022076a0[self->unk_1a].c;
        self->speed = data_ov011_022076a0[self->unk_1a].spd2;
        st->st++;
    case 5: {
        s16 i;
        st = self->fsm;
        i = self->unk_1a;
        st->timer++;
        if (st->timer > data_ov011_022076a0[i].dur2) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
    }
    d.x = self->unk_84.x - self->unk_f0.x;
    d.y = self->unk_84.y - self->unk_f0.y;
    d.z = self->unk_84.z - self->unk_f0.z;
    VEC_MultAdd(self->speed, &d, &self->unk_f0, &self->unk_f0);
    d.x = 0;
    d.y = 0;
    d.z = 0;
    if (self->unk_fc != 0) {
        self->unk_fc--;
        Ov011_VecSet(&d, Rand_PlusMinus(0x800), Rand_PlusMinus(0x800), Rand_PlusMinus(0x800));
    }
    VEC_Add(&d, &self->unk_f0, &d);
    Ov011_MulVec33(&d, NNS_G3dGlbGetInvV(), &d);
    VEC_Add(&d, &data_02092a50, &self->pos);
    {
        const s32 *b = (const s32 *)&data_02092a38;
        const s32 *a = (const s32 *)&data_02092a50;
        self->rot_y = FX_Atan2(b[0] - a[0], b[2] - a[2]);
    }
}

}
