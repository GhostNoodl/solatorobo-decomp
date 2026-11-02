#include "ov014/ov014.h"

struct Ov014Mtx33 {
    s32 m[9];
};

static inline s32 Ov014y_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov014y_Abs(s32 x) {
    return x < 0 ? -x : x;
}

extern "C" {


extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void func_ov014_02215ffc(Ov014ActEx_022152e8 *self);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern void Interp_SinLerpVec(VecFx32 *out, s32 t, const VecFx32 *a, const VecFx32 *b);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern void Ov003Pickup_Update(Actor *self, s32 a);

static inline void Ov014z_Set(VecFx32 *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
void Ov014ActEx_022152e8_StateThrown(Ov014ActEx_022152e8 *self) {
    Ov014Mtx33 m;
    VecFx32 v0;
    VecFx32 v1;
    VecFx32 v2;
    VecFx32 n;
    Ov014Mtx33 t;
    Ov003Actor *o;
    Ov003Actor *p;
    ActorSub40 *st;
    o = Target_Get(self->targetObj);
    p = Actor_GetTarget(self);
    if (o == NULL) {
        History_SetState(self->fsm, 0x15, 0);
        return;
    }
    if (o->kind == 0x1000) {
        func_ov014_02215ffc(self);
        return;
    }
    self->unk_3c->unk_14 = self->unk_ec << 1;
    st = self->fsm;
    switch (st->st) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        u16 f;
        set = FALSE;
        Model0218fe1c_SetAnimSpeed(self->model, 0);
        ry = self->rot_y;
        rz = self->rot_z;
        rx = self->rot_x;
        MTX_Identity33_((MtxFx33 *)&m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_((MtxFx33 *)&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_((MtxFx33 *)&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotZ33_((MtxFx33 *)&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        Ov014z_Set(&v0, 0, Rand_UpTo(0x2000), 0x1000);
        self->unk_dc = self->pos;
        VEC_Add(&v0, &self->pos, &self->unk_d0);
        f = 0;
        if (Rand_UpTo(1) == 0) {
            f = 0x2d;
        }
        self->unk_f0 = f;
        Effect_SpawnId(0x69, &self->pos)->SetScaleAll(0x1800);
        SndMgr_PlayAt(data_02097e4c, 0x82, &self->pos, 0);
        SndMgr_PlayAt(data_02097e4c, 0x57, &self->pos, 0);
        self->fsm->timer = 0x3c;
        self->fsm->st++;
    }
    case 1: {
        s32 k = FX_Div(self->fsm->timer << 12, 0x3c000);
        Interp_SinLerpVec(&self->pos, k, &self->unk_d0, &self->unk_dc);
        self->rot_x = (Ov014y_FxMul64(k, -0x1800000) + 0x1fff000) >> 12;
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->fsm->timer = 0x1e;
        self->fsm->st++;
        break;
    }
    case 2:
        if (st->timer < 0xf) {
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        }
        if (self->fsm->timer == 0xf) {
            EffectObj *e;
            EffectObj *e2;
            FieldState *g;
            e = Effect_SpawnId(0x66, &self->pos);
            e->SetScaleAll(0x2800);
            e->SetRot(&self->rot);
            e2 = Effect_SpawnId(0x3ea, &self->pos);
            e2->SetScaleAll(0x3800);
            e2->SetRot(&self->rot);
            g = data_ov000_021ccd54;
            g->cam.base.shakeX = 1;
            g->cam.base.shakeY = 1;
            g->cam.base.shakeZ = 1;
            g->cam.base.shakeTime = 0x14;
            g->cam.base.shakeLen = 10;
            g->cam.base.shakeCur = 10;
            SndMgr_PlayAt(data_02097e4c, 0x29, &self->pos, 0);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->fsm->timer = 0x28;
        self->fsm->st++;
        break;
    case 3:
        if (p != NULL) {
            Actor_TurnToActor(self, p, 0x400);
        }
        self->pos.y -= 0x52;
        self->unk_ec = 0x3000;
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        self->unk_84 = p->pos;
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10: {
        s32 r;
        u16 a;
        v1.x = OV014_SIN(self->rot_y);
        v1.z = OV014_COS(self->rot_y);
        v1.y = 0;
        v1.y -= 0x2000;
        VEC_Normalize(&v1, &v1);
        VEC_MultAdd(self->unk_e8, &v1, &self->pos, &self->pos);
        if ((self->unk_e8 += 0x10) > 0x666) {
            self->unk_e8 = 0x666;
        }
        r = self->rot_x - 0x3f;
        if (r < 0) {
            r = 0;
        }
        self->rot_x = r;
        a = Ov014y_FxMul64(FX_Div(self->unk_f0 << 12, 0x5a000), 0xffff000) >> 12;
        self->rot_z = Ov014y_FxMul64(OV014_SIN(a), 0xfff000) >> 12;
        self->unk_f0++;
        self->unk_f0 %= 0x5aU;
        Actor_TurnToPos(self, &self->unk_84, 0x29);
        if (self->pos.y >= self->unk_84.y + 0x2800) {
            break;
        }
        SndMgr_PlayAt(data_02097e4c, 0x50, &self->pos, 0);
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 11: {
        s32 r;
        u16 a;
        s32 sp;
        if (!(self->hit->unk_50 & 0x40000000)) {
            if ((self->unk_e8 += 0x21) > 0x666) {
                self->unk_e8 = 0x666;
            }
        } else {
            self->unk_e8 >>= 1;
        }
        v2.x = OV014_SIN(self->rot_y);
        v2.y = 0;
        v2.z = OV014_COS(self->rot_y);
        VEC_MultAdd(self->unk_e8, &v2, &self->pos, &self->pos);
        sp = self->unk_e8;
        self->speed = FX_Mul(v2.x, sp);
        self->velY = FX_Mul(v2.y, sp);
        self->friction = FX_Mul(v2.z, sp);
        self->pos.y -= 0xcd;
        if (self->pos.y < 0x1000) {
            self->pos.y = 0x1000;
        }
        Actor_TurnToPos(self, &self->unk_84, 0x29);
        r = self->rot_x - 0x8f;
        if (r < 0) {
            r = 0;
        }
        self->rot_x = r;
        a = Ov014y_FxMul64(FX_Div(self->unk_f0 << 12, 0x5a000), 0xffff000) >> 12;
        self->rot_z = Ov014y_FxMul64(OV014_SIN(a), 0xfff000) >> 12;
        self->unk_f0++;
        self->unk_f0 %= 0x5aU;
        if (self->fsm->timer % 3 == 0) {
            u16 mask = 0xffff;
            mask &= (u16)~(1 << (self->kind >> 12));
            if (o != NULL) {
                mask &= (u16)~(1 << ((u16)(o->id & 0xf000) >> 12));
            }
            Hit_ApplyInArea(self, o, self->targetObj->unk_08, self->targetObj->unk_0a, mask, NULL, 0,
                                self->unk_ec, 0x1000, 0x64, 0x1000);
        }
        st = self->fsm;
        st->timer++;
        if (st->timer >= 0x96) {
            self->fsm->st = 0x14;
            self->fsm->timer = 0;
        }
        break;
    }
    case 0x14: {
        s32 sp;
        ActorSub44 *q4;
        Model0218fe1c *m38;
        self->unk_ec = 0x1000;
        VEC_Normalize((VecFx32 *)&self->speed, &n);
        self->moveYaw = FX_Atan2(n.x, n.z) - 0x7fff;
        sp = self->unk_e8;
        self->speed = FX_Mul(Rand_PlusMinus(0x333) + 0x1000, sp);
        self->friction = 0xf33;
        self->gravity = 0x52;
        self->velY = 0x333;
        self->hit->unk_30 = 0x60000000;
        q4 = self->unk_44;
        q4->unk_22_0 = 1;
        q4->unk_22_1 = 1;
        m38 = self->model;
        {
            s32 x = FX_Mul(m38->scale.x, 0x800);
            s32 y = FX_Mul(m38->scale.y, 0x800);
            s32 z = FX_Mul(m38->scale.z, 0x800);
            m38->scale.x = x;
            m38->scale.y = y;
            m38->scale.z = z;
        }
        SndMgr_PlayAt(data_02097e4c, 0xf, &self->pos, 0);
        self->fsm->st++;
        self->fsm->timer = 0x14;
    }
    case 0x15: {
        s16 k;
        Actor_Move(self, 0);
        k = Model0218fe1c_GetAnimCtrl(self->model, 0)->speed - 0x29;
        if (k < 0) {
            k = 0;
        }
        Model0218fe1c_SetAnimSpeed(self->model, k);
        if (k < 0x800) {
            u16 rz;
            s32 d;
            self->rot_y += (u16)FX_Mul(k, 0x200);
            rz = self->rot_z;
            if (rz < 0x3fff) {
                d = 0x71c - rz;
                if (Ov014y_Abs(d) > 0x80) {
                    self->rot_z += (u16)(Ov014y_FxMul64(d << 12, 0x19a) >> 12);
                }
            } else {
                d = 0xf8e4 - rz;
                if (Ov014y_Abs(d) > 0x80) {
                    self->rot_z += (u16)(Ov014y_FxMul64(d << 12, 0x19a) >> 12);
                }
            }
        }
        if (self->fsm->timer < 10 && !(self->fsm->timer & 8)) {
            Model0218fe1c *m38 = self->model;
            m38->color = 0x7fff;
            m38->color2 = 0x7fff;
            m38->blend = 2;
            m38->blendMax = 1;
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        History_SetState(self->fsm, 0x15, 0);
        self->radius = Ov014y_FxMul64(self->radius, 0xb33);
        self->height = Ov014y_FxMul64(self->height, 0xb33);
        Ov003Pickup_Update(self, 0);
        break;
    }
    }
    Body_Update(self->hit, 0, 0, 0);
}

}
