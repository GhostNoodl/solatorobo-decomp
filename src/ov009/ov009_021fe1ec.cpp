#include "ov009/ov009.h"
#include "nitro/mi.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {


void Ov009ActVt_022165f8_State20(Ov009ActVt_022165f8 *self) {
    ActorSub40 *st = self->fsm;
    if (st->st != 0) {
        return;
    }
    st->timer++;
    if (st->timer > 0x50) {
        History_SetState(self->fsm, 1, 0);
    }
    VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
    self->speed = FX_Mul(self->speed, 0xf33);
    self->velY = FX_Mul(self->velY, 0xf33);
    self->friction = FX_Mul(self->friction, 0xf33);
    Body_Update(self->hit, 0, 0, 0);
}

extern char data_ov009_02216ab6[];
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);

void Ov009ActVt_022165f8_StateIdle(Ov009ActVt_022165f8 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab6, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        self->hit->unk_30 = 0x40000000;
        self->fsm->st++;
    case 1:
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        self->speed = FX_Mul(self->speed, 0xe66);
        self->velY = FX_Mul(self->velY, 0xe66);
        self->friction = FX_Mul(self->friction, 0xe66);
        Body_Update(self->hit, 1, 0, 0);
        break;
    }
}

extern BOOL Actor_DespawnIfFar(Ov003Actor *self);
void Ov009ActVt_022165f8_StateMove(Ov009ActVt_022165f8 *self) {
    VecFx32 d;
    VecFx32 e;
    VecFx32 t;
    s32 s;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab6, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        self->fsm->st++;
    }
    t = self->unk_b8;
    d.x = t.x - self->pos.x;
    d.y = t.y - self->pos.y;
    d.z = t.z - self->pos.z;
    VEC_Normalize(&d, &d);
    s = self->unk_b0->unk_00;
    if (self->unk_f0 != 0) {
        s >>= 1;
    }
    d.x = FX_Mul(d.x, s);
    d.y = FX_Mul(d.y, s);
    d.z = FX_Mul(d.z, s);
    d.y -= d.y >> 2;
    e.x = d.x - self->speed;
    e.y = d.y - self->velY;
    e.z = d.z - self->friction;
    VEC_MultAdd(0x171, &e, &self->vel, &self->vel);
    VEC_Add(&self->pos, &self->vel, &self->pos);
    if (self->pos.y - t.y < 0x4800) {
        Body_Update(self->hit, 1, 0, 0);
    }
    Actor_DespawnIfFar(self);
}

#define OV009_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

extern VecFx32 data_ov009_02215cd0;
extern VecFx32 data_ov009_02215cdc;
extern VecFx32 data_ov009_02215ce8;
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Vec_RotateY(VecFx32 *dst, VecFx32 *src, u16 angle);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, const VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline Ov003Actor *Ov009_FindActor(void *mgr, u16 id) {
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

void Ov009ActVt_022165f8_StateAttack(Ov009ActVt_022165f8 *self) {
    Ov003Actor *tgt;
    ActorSub40 *st;
    EffectObj *e;
    VecFx32 v;
    if (!Ov009_GameIdle()) {
        return;
    }
    tgt = Ov009_FindActor(data_ov000_021ccd68, self->target);
    if (tgt == NULL) {
        History_SetState(self->fsm, 1, 0);
        return;
    }
    switch (self->unk_f4) {
    case 0x5013:
        st = self->fsm;
        switch (st->st) {
        case 0:
            Model0218fe1c_SetAnimSpeed(self->model, 0x2800);
            v = tgt->pos;
            v.x = self->pos.x - v.x;
            v.y = self->pos.y - v.y;
            v.z = self->pos.z - v.z;
            VEC_Normalize(&v, &v);
            v.y = 0x1800;
            VEC_MultAdd(0x1000, &v, &self->pos, &v);
            self->unk_b8 = v;
            SndMgr_PlayAtPitch(data_02097e4c, 0x71, &self->pos, -2);
            self->fsm->st++;
            break;
        case 1:
            if (tgt->hit == NULL || !(tgt->hit->unk_50 & 0x20000000)) {
                History_SetState(st, 1, 0);
                return;
            }
            st->timer++;
            if (st->timer > 0x32) {
                Model0218fe1c_SetAnimSpeed(self->model, 0x3000);
                v = tgt->pos;
                v.y += self->centerY;
                v.x = v.x - self->pos.x;
                v.y = v.y - self->pos.y;
                v.z = v.z - self->pos.z;
                VEC_Normalize(&v, &v);
                self->speed = OV009_FXMUL_K(v.x, 0x400);
                self->velY = OV009_FXMUL_K(v.y, 0x400);
                self->friction = OV009_FXMUL_K(v.z, 0x400);
                self->rot_x = 0x1000;
                self->fsm->timer = 0;
                self->fsm->st++;
                e = Effect_SpawnId(0x3ea, &self->pos);
                e->AddPos(&data_ov009_02215ce8);
                e->SetScaleAll(0x3000);
                e->SetRotXYZ(0x1000, self->rot_y, 0x8000);
                e->speed = 0x1800;
                self->unk_f8 = e->id;
                return;
            }
            self->rot_x = Angle_Approach(0x1000, self->rot_x, 0x19a, 1, 0x8000);
            v = self->unk_b8;
            v.x = v.x - self->pos.x;
            v.y = v.y - self->pos.y;
            v.z = v.z - self->pos.z;
            self->speed = OV009_FXMUL_K(v.x, 0x52);
            self->velY = OV009_FXMUL_K(v.y, 0x52);
            self->friction = OV009_FXMUL_K(v.z, 0x52);
            self->velY -= self->velY >> 2;
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
            Body_Update(self->hit, 1, 0, 0);
            Actor_TurnToActor(self, tgt, 0x400);
            break;
        case 2:
            st->timer++;
            if (st->timer > 0xf) {
                Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
                self->fsm->timer = 0;
                self->fsm->st++;
            }
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
            Body_Update(self->hit, 0, 0, 0);
            v.y = self->centerY;
            v.x = 0;
            v.z = 0;
            Hit_ApplyInArea(self, self, 0x1e, 0x20, 2, &v, 0, self->radius, 0, 100, 0x1000);
            e = Effect_Find_020657b0(data_0214a420, self->unk_f8);
            if (e == NULL) {
                self->unk_f8 = 0;
                return;
            }
            VEC_Add(&self->pos, &data_ov009_02215ce8, &v);
            e->SetPos(&v);
            break;
        case 3:
            st->timer++;
            if (st->timer > 0x1e) {
                History_SetState(self->fsm, 1, 0);
            }
            self->speed = OV009_FXMUL_K(self->speed, 0xa66);
            self->velY = OV009_FXMUL_K(self->velY, 0xa66);
            self->friction = OV009_FXMUL_K(self->friction, 0xa66);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
            Body_Update(self->hit, 1, 0, 0);
            self->rot_x = Angle_Approach(0, self->rot_x, 0xcd, 1, 0x8000);
            break;
        }
        break;
    case 0x5045:
        st = self->fsm;
        switch (st->st) {
        case 0: {
            s32 r;
            v = self->pos;
            r = Geom_SnapToGround(&v, 0x1800, -0xa000);
            if (r != -0x1000) {
                s32 ty = v.y + 0x1800;
                s32 d;
                self->pos.y += OV009_FXMUL_K(ty - self->pos.y, 0xcd);
                d = self->pos.y - ty;
                if (d < 0) {
                    d = -d;
                }
                if (d <= 0x19a) {
                    r = -0x1000;
                }
            }
            if (r != -0x1000) {
                st = self->fsm;
                st->timer++;
                if (st->timer <= 0x78) {
                    return;
                }
            }
            Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
            self->fsm->timer = 0;
            self->fsm->st++;
            break;
        }
        case 1: {
            u8 i;
            for (i = 0; i < 2; i++) {
                e = Effect_SpawnId(0x322, &self->pos);
                v.x = 0xb33;
                v.y = 0x1b33;
                v.z = 0;
                if (i == 1) {
                    v.x = -v.x;
                }
                Vec_RotateY(&v, &v, self->rot_y);
                e->AddPos(&v);
                e->SetScaleAll(0x800);
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
            }
            self->unk_f8 = e->id;
            SndMgr_PlayAt(data_02097e4c, 0x7a, &self->pos, 0);
            self->fsm->st++;
            break;
        }
        case 2:
            if (Effect_Find_020657b0(data_0214a420, self->unk_f8) != NULL) {
                return;
            }
            e = Effect_SpawnId(0x321, &self->pos);
            e->AddPos(&data_ov009_02215cd0);
            e->SetScaleAll(0x19a);
            MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
            e->alpha = FX_Div(0x10000, 0x1f000);
            self->unk_f8 = e->id;
            SndMgr_PlayAtPitch(data_02097e4c, 0x79, &self->pos, -10);
            self->fsm->st++;
            break;
        case 3:
            e = Effect_Find_020657b0(data_0214a420, self->unk_f8);
            if (e != NULL) {
                s32 s = e->scale.x;
                e->SetScaleAll(s + 0x333);
                if (s + 0x333 >= 0x2800) {
                    Model0218fe1c *m = self->model;
                    m->color = 0x7c00;
                    m->color2 = 0x7c00;
                    m->blend = 0x3d;
                    m->blendMax = 0x3c;
                    self->fsm->st++;
                }
            }
            self->unk_94_1 = 1;
            break;
        case 4:
            st->timer++;
            if (st->timer > 0x3c) {
                EffectMgr_Kill(data_0214a420, self->unk_f8);
                e = Effect_SpawnId(0x322, &self->pos);
                e->AddPos(&data_ov009_02215cdc);
                e->SetScaleAll(0xccd);
                self->unk_f8 = e->id;
                Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
                self->fsm->timer = 0;
                self->fsm->st++;
            }
            if (Hit_ApplyInArea(self, self, 0x3c, 0x11, 2, &data_ov009_02215cd0, 0, 0x2800, 0, 0x322, 0xccd)) {
                VecFx32 p;
                p = ActorMgr_FindPlayer()->pos;
                SndMgr_PlayAt(data_02097e4c, 0x77, &p, 0);
            }
            self->unk_94_1 = 1;
            break;
        case 5:
            if (Effect_Find_020657b0(data_0214a420, self->unk_f8) != NULL) {
                return;
            }
            self->unk_f8 = 0;
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
            break;
        }
        break;
    }
}

}
