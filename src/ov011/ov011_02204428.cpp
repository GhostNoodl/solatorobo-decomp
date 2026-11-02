#include "ov011/ov011.h"

extern "C" {

extern const VecFx32 data_02092a50;
extern const VecFx32 data_02092a38;
extern char data_ov011_022075d4[];
s32 Rand_PlusMinus(s32 max);
Actor *func_ov000_0219be1c(s32 id, VecFx32 *pos, u16 *rot, u16 a, u16 b);

void Ov011Act7c4c_StateIdle(Ov011Act7c4c *self) {
    VecFx32 v;
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        s->timer++;
        if (s->timer > 0xf0) {
            self->unk_fe = 0;
            self->model->alpha = 0x1f;
            self->fsm->timer = 0;
            self->fsm->st = 10;
        } else {
            u8 a = self->fsm->timer >> 2;
            if (a >= 0x1f) {
                a = 0x1f;
            }
            self->model->alpha = a;
            self->speed = 0x29;
        }
        break;
    case 10:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            EffectObj *e;
            self->unk_104 = self->unk_84;
            if (self->unk_fe & 1) {
                self->unk_104.x += 0x5800;
            } else {
                self->unk_104.x -= 0x5800;
            }
            self->unk_104.y += 0x2000;
            self->unk_104.z += 0x800;
            self->unk_100 = 0;
            self->target_id = 0xffff;
            Ov011_MulVec33(&self->unk_104, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &data_02092a50, &v);
            e = func_02065f88(0x389, &v);
            if (e != NULL) {
                self->unk_100 = e->id;
                e->SetScaleAll(0x4800);
                e->speed = 0x1ccd;
            }
            self->fsm->st++;
            self->fsm->timer = 0x14;
        }
        break;
    case 11:
        if (self->fsm->timer != 0) {
            self->fsm->timer--;
        }
        if (self->unk_100 != 0) {
            EffectObj *e = func_020657b0(data_0214a420, self->unk_100);
            if (e != NULL) {
                if (self->fsm->timer == 0) {
                    e->state = 4;
                    self->unk_100 = 0;
                } else {
                    Ov011_MulVec33(&self->unk_104, NNS_G3dGlbGetInvV(), &v);
                    VEC_Add(&v, &data_02092a50, &v);
                    e->SetPos(&v);
                }
            }
        }
        if (self->fsm->timer == 0) {
            Robo021ca458 *pl = (Robo021ca458 *)func_ov000_0219bf90();
            if (pl != NULL) {
                VecFx32 d;
                u16 rot[3];
                Actor *r;
                d = pl->unk_af0;
                d.y += 0x3000;
                d.x -= self->unk_104.x;
                d.y -= self->unk_104.y;
                d.z -= self->unk_104.z;
                VEC_Normalize(&d, &d);
                rot[0] = FX_Atan(-d.y);
                rot[1] = FX_Atan2(d.x, d.z);
                rot[2] = 0;
                if (self->unk_fe & 1) {
                    rot[1] += 0x4000;
                } else {
                    rot[1] -= 0x4000;
                }
                r = func_ov000_0219be1c(0x4804, &self->unk_104, rot, self->id, pl->id);
                if (r != NULL) {
                    r->unk_60 = data_ov011_022075d4;
                }
            }
            self->unk_fe++;
            if (self->unk_fe >= 0x12) {
                self->fsm->timer = 0x78;
                self->fsm->st = 0x14;
            } else {
                if (self->unk_fe == 6 || self->unk_fe == 0xc) {
                    self->fsm->timer = 0x5a;
                } else {
                    self->fsm->timer = 0xa;
                }
                self->fsm->st = 10;
            }
        }
        break;
    case 0x14:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            Ov011_VecSet(&self->unk_84, 0, 0x1e000, -0x12000);
            self->speed = 0x29;
            self->fsm->timer = 0x96;
            self->fsm->st++;
        }
        break;
    case 0x15:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
    v.x = self->unk_84.x - self->unk_f0.x;
    v.y = self->unk_84.y - self->unk_f0.y;
    v.z = self->unk_84.z - self->unk_f0.z;
    VEC_MultAdd(self->speed, &v, &self->unk_f0, &self->unk_f0);
    Ov011_VecSet(&v, 0, 0, 0);
    if (self->unk_fc != 0) {
        self->unk_fc--;
        Ov011_VecSet(&v, Rand_PlusMinus(0x800), Rand_PlusMinus(0x800), Rand_PlusMinus(0x800));
    }
    VEC_Add(&v, &self->unk_f0, &v);
    Ov011_MulVec33(&v, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
    {
        const s32 *b = (const s32 *)&data_02092a38;
        const s32 *a = (const s32 *)&data_02092a50;
        self->rot_y = FX_Atan2(b[0] - a[0], b[2] - a[2]);
    }
}
}
