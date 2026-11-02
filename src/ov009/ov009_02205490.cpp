#include "ov009/ov009.h"
#include "ov000/FieldCam.h"

extern "C" {

extern void *const data_ov009_02215d0c[];
extern void *data_02097e4c;
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, s32 angle);
extern void HitSphere_Link(ActorSub48 *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern BOOL func_ov000_0219aae8(Actor *a, Actor *b, u16 c, u8 d, u16 e, VecFx32 *f, void *g, s32 h, s32 i, s16 j, s32 k);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

static inline VecFx32 *Ov009_MaxScale(Ov009ActVt_02216bc8 *a) {
    return &a->unk_100;
}

// Read through a const view: MWCC does not merge it with the compare's read just before.
static inline s32 Ov009_MaxScaleX(const Ov009ActVt_02216bc8 *a) {
    return a->unk_100.x;
}

void Ov009ActVt_02216bc8_StateAttack2(Ov009ActVt_02216bc8 *self) {
    VecFx32 r;
    VecFx32 v1;
    VecFx32 v2;
    Ov003Actor *pl;
    s32 ply;
    ActorSub40 *st;
    EffectObj *o;
    ActorSub44 *s44;
    ActorSub48 *s48;
    s32 t;
    s32 h;
    VecFx32 s;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    pl = func_ov000_0219bf90();
    ply = pl->pos.y;
    st = self->fsm;
    switch (st->st) {
    case 0:
        st->timer = 0;
        if (self->unk_f2 != 0) {
            self->fsm->st = 10;
        } else {
            self->unk_84 = self->pos;
            func_ov000_0219a2f4(&self->unk_84, 0x1800, -0xa000);
            self->fsm->st++;
        }
    case 1:
        st = self->fsm;
        st->timer++;
        t = st->timer;
        if (t % 15 == 0) {
            o = func_02065f88(0x12c, &self->unk_84);
            o->AddPosXYZ(0, 0x800, 0);
            o->SetScaleAll(0x1800);
        }
        if (t == 0x32) {
            self->model->visible = 1;
            o = func_02065f88(0x192, &self->pos);
            o->SetRotXYZ(0x4000, 0, 0);
            EffectObj_AddSndCue(o, 0x54, 0);
            self->speed = 0;
            self->friction = 0;
            self->gravity = 0;
            self->velY = -0x666;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        v1 = self->pos;
        if (func_ov000_0219a2f4(&v1, 0x3800, -0xa000) != -0x1000) {
            v1.y += 0x2000;
        }
        self->pos.y += FX_Mul(v1.y - self->pos.y, 0x1000);
        VEC_Distance(&self->pos, &v1);
        break;
    case 2:
        s.x = self->model->scale.x + 0x19a;
        s.y = self->model->scale.y - 0xcd;
        s.z = s.x;
        if (s.x >= Ov009_MaxScale(self)->x) {
            s = *Ov009_MaxScale(self);
            EffectMgr_Kill(data_0214a420, self->unk_f8);
            self->unk_f8 = 0;
            o = func_02065f88(0x68, &self->pos);
            o->AddPosXYZ(0, 0x400, 0);
            o->alpha = FX_Div(0x1e000, 0x1f000);
            func_02049f44(data_02097e4c, 0x80, &self->pos, 0);
            s48 = self->hit;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            HitSphere_Link(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            func_ov000_021984f4(self->unk_44, 0, 0);
            func_ov000_02190cb0(self->model, (char *)data_ov009_02215d0c[9], 0x1000, 0);
            func_ov000_021915a0(self->model);
            self->fsm->st++;
        }
        self->model->scale = s;
        Actor_Move(self, 0);
        Actor_TurnToActor(self, pl, 0x1000);
        self->hit->unk_9a_5 = 1;
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        break;
    case 3:
        if (self->unk_f0 & 1) {
            st->timer++;
            if (st->timer > 0x32) {
                self->fsm->timer = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
        } else {
            func_ov000_02190cb0(self->model, (char *)data_ov009_02215d0c[3], 0x400, 0);
            self->fsm->st++;
        }
        break;
    case 4: {
        s16 c = self->model->anim_state;
        if (c >= 10) {
            st->timer = c;
            self->fsm->st = 0x1e;
        }
        if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 10:
        v2 = self->pos;
        if (func_ov000_0219a2f4(&v2, 0x3800, -0xa000) != -0x1000) {
            if (v2.y < ply) {
                v2.y = ply;
            }
            v2.y += 0x2000;
        }
        self->pos.y += FX_Mul(v2.y - self->pos.y, 0x1000);
        VEC_Distance(&self->pos, &v2);
        o = func_02065f88(0x389, &self->pos);
        o->SetScaleAll(0x3000);
        h = FieldCam_GetYaw(&data_ov000_021ccd54->cam);
        r.x = 0;
        r.y = 0;
        r.z = -0x800;
        func_01ffc9fc(&r, &r, h);
        o->AddPos(&r);
        self->model->visible = 1;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 11:
        st->timer++;
        if (st->timer < 0x32) {
            break;
        }
        h = self->model->scale.x + 0x266;
        if (h >= self->unk_100.x) {
            h = Ov009_MaxScaleX(self);
            o = func_02065f88(0x69, &self->pos);
            o->SetScaleAll(0xccd);
            func_02065f88(0x38a, &self->pos);
            s48 = self->hit;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            HitSphere_Link(s48);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        {
            Model0218fe1c *m = self->model;
            m->scale.x = h;
            m->scale.y = h;
            m->scale.z = h;
        }
        break;
    case 12: {
        u32 t2;
        st->timer++;
        t2 = st->timer;
        if (t2 == 10) {
            o = func_02065f88(0x322, &self->pos);
            self->unk_f8 = o->id;
            o->SetScaleAll(0x199a);
            EffectObj_AddSndCue(o, 0x7a, 0);
        }
        if (t2 >= 10) {
            if (*func_ov000_0219bf90()->hp != 0) {
                func_ov000_0219aae8(self, self, self->unk_f6, self->targetObj->unk_0a, 2, NULL, 0, 0x2333, 0, 6, 0x800);
            }
            if (func_020657b0(data_0214a420, self->unk_f8) == NULL) {
                self->unk_f8 = 0;
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                func_ov000_021984f4(self->unk_44, 0, 0);
                self->fsm->timer = 0x14;
                self->fsm->st = 0x1e;
            }
        }
        Actor_TurnToActor(self, pl, 0x400);
        break;
    }
    case 0x1e:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    if ((s32)self->fsm->st < 3) {
        self->unk_ea_0 = 3;
    }
    if (self->fsm->st < 0x1e) {
        self->unk_94_1 = 1;
    }
}

}
