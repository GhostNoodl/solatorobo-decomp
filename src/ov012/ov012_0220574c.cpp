#include "ov012/ov012.h"

extern "C" {

BOOL Ov012ActExVt_0220b1e8_Draw(Ov012ActExVt_0220b1e8 *self) {
    BOOL r;
    if (!(self->unk_d0 & 0x100000)) {
        self->mdl.trans.x = self->pos.x;
        self->mdl.trans.y = self->pos.y;
        self->mdl.trans.z = self->pos.z;
        Obj02190758_SetRot(&self->mdl, &self->rot_x, 0);
        r = Model021903b4_Draw(&self->mdl);
        if (r && self->unk_3c != NULL && self->hit != NULL) {
            ActorSub48 *m = self->hit;
            u8 v;
            self->unk_3c->unk_10 = self->pos.y - m->check.y;
            v = 1;
            if (m->unk_54 & 0x10000) {
                v = 3;
            }
            {
                ActorShadow *n = self->unk_3c;
                n->unk_18_4 = n->unk_18_0;
                n->unk_18_0 = v;
            }
            Shadow_Draw(self->unk_3c, &self->pos);
        }
    } else {
        r = ActorEx_Draw(self);
    }
    return r;
}

void Ov012ActExVt_0220b1e8_Animate(Ov012ActExVt_0220b1e8 *self) {
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40((u8 *)self + 0x24));
    }
    if (!(self->unk_d0 & 0x100000)) {
        Model0218fe1c_UpdateAnim(&self->mdl, func_0203db40((u8 *)self + 0x24));
    }
}
}

extern "C" {
extern char data_ov012_0220b0a7[];
void Ov012ActExVt_0220b1e8_Start(Ov012ActExVt_0220b1e8 *self) {
    ActorEx_Start(self);
    self->unk_d0 = 0;
    self->unk_2f8 = 1;
    self->unk_d4 = self->unk_18;
    if (self->unk_d4) {
        ActorSub48 *m;
        ActorSub44 *n;
        self->unk_d0 = 0x100000;
        self->model->visible = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
        m = self->hit;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
    } else {
        self->model->visible = 0;
        Model0218fe1c_SetRes(&self->mdl, &self->unk_d8, 0, 1);
        self->mdl.scale.x = 0x2800;
        self->mdl.scale.y = 0x2800;
        self->mdl.scale.z = 0x2800;
        self->mdl.visible = 1;
        Obj02190758_SetRot(&self->mdl, &self->rot_x, 0);
        Model0218fe1c_SetAnim(&self->mdl, data_ov012_0220b0a7, 0x1000, 0);
        Model0218fe1c_SetLoop(&self->mdl);
    }
    History_SetState(self->fsm, 0xb, 0);
}
}

extern "C" {
extern void Ov012ActExVt_0220b1e8_HitNearby(Ov012ActExVt_0220b1e8 *self);
extern void func_ov012_02206508(Ov012ActExVt_0220b1e8 *self);
extern void func_ov012_02206098(Ov012ActExVt_0220b1e8 *self);
extern const VecFx32 data_ov012_0220a84c[];

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov012_Dist84(Actor *self) {
    s64 sq;
    s32 dx = self->pos.x - self->unk_84.x;
    s32 dz = self->pos.z - self->unk_84.z;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov012_Sqrt2(sq);
}

void Ov012ActExVt_0220b1e8_StateThrown(Ov012ActExVt_0220b1e8 *self) {
    VecFx32 v;
    u8 b;
    Ov003Actor *g;
    Ov003Actor *pl;
    VecFx32 pp;
    g = (Ov003Actor *)Target_Get(self->targetObj);
    if (g != NULL) {
    {
        ActorSub48 *m = g->hit;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
        }
    }
    if (g->kind == 0x1000) {
        func_ov012_02206098(self);
        return;
    }
    pl = Actor_GetTarget(self);
    pp = pl->pos;
    switch (self->fsm->st) {
    case 0: {
        s32 d;
        u16 a;
        ActorSub48 *m = self->hit;
        m->unk_50 = 0;
        m->unk_54 = 0;
        m->unk_58 = 0;
        if (self->unk_d4 == 0) {
            d = Ov012_Dist84(self);
            a = FX_Atan2(d, self->unk_84.y - self->pos.y);
            self->speed = FX_Mul(OV012_SIN(a), 0x400);
            self->velY = FX_Mul(OV012_COS(a), 0x400);
            self->fsm->st++;
        } else {
            self->fsm->st = 10;
        }
        break;
    }
    case 1:
        Actor_TurnToPos(self, &self->unk_84, 0x1000);
        Actor_MoveToPos(self, &self->unk_84, 0);
        Ov012ActExVt_0220b1e8_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_84) <= 0x800) {
            ActorSub48 *m;
            ActorSub44 *n;
            EffectObj *o;
            self->unk_d0 = 0x100000;
            self->mdl.visible = 0;
            self->model->visible = 1;
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            o = Effect_SpawnId(0x57c, &self->pos);
            o->SetScaleAll(0x2000);
            o = Effect_SpawnId(0x6b, &self->pos);
            o->SetScaleAll(0x2000);
            SndMgr_PlayAt(data_02097e4c, 0x1a, &self->pos, 0);
            SndMgr_PlayVolume(data_02097e4c, 0x4f, 0x6e, -1, -1);
            func_ov012_02206508(self);
            self->fsm->st = 10;
        }
        if (self->hit->unk_50 & 0x60000000) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    case 10: {
        s32 d;
        u16 a;
        Vec_RotateY(&v, &data_ov012_0220a84c[self->unk_d4], self->rot_y);
        VEC_Add(&v, &self->pos, &self->unk_84);
        d = Ov012_Dist84(self);
        a = FX_Atan2(d, self->unk_84.y - self->pos.y);
        self->speed = Ov012_FxMul64d(OV012_SIN(a), 0x2b8);
        self->velY = Ov012_FxMul64d(OV012_COS(a), 0x2b8);
        b = 1;
        ActorMgr_SendToKindOthers(0x5c03, self->kind, 6, 1, 1, &b);
        self->fsm->st++;
        break;
    }
    case 11: {
        ActorSub40 *s;
        Actor_TurnToPos(self, &self->unk_84, 0x7b);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov012ActExVt_0220b1e8_HitNearby(self);
        s = self->fsm;
        s->timer++;
        if (s->timer > self->unk_d4 * 0x28 + 100) {
            self->fsm->st++;
        }
        if (self->fsm->timer == 0x1e) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        break;
    }
    case 12: {
        s32 d;
        u16 a;
        self->unk_84 = pp;
        d = Ov012_Dist84(self);
        a = FX_Atan2(d, pp.y - self->pos.y);
        self->speed = Ov012_FxMul64d(OV012_SIN(a), 0x333);
        self->velY = Ov012_FxMul64d(OV012_COS(a), 0x333);
        SndMgr_Stop(data_02097e4c, 0x4f);
        self->fsm->st++;
        break;
    }
    case 13:
        Actor_TurnToPos(self, &self->unk_84, 0x19a);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov012ActExVt_0220b1e8_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x60000000) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
    } else {
        History_SetState(self->fsm, 0x15, 0);
    }
}
}
