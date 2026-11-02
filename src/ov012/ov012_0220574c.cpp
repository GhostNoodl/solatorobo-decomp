#include "ov012/ov012.h"

extern "C" {

BOOL func_ov012_0220574c(Ov003Actor *self) {
    BOOL r;
    if (!(FLD(u32, self, 0xd0) & 0x100000)) {
        FLD(s32, self, 0x288) = self->pos.x;
        FLD(s32, self, 0x28c) = self->pos.y;
        FLD(s32, self, 0x290) = self->pos.z;
        func_ov000_02190758((u8 *)self + 0x210, &self->rot_x, 0);
        r = func_ov000_021903b4((u8 *)self + 0x210);
        if (r && self->unk_3c != NULL && self->hit != NULL) {
            ActorSub48 *m = self->hit;
            u8 v;
            FLD(s32, self->unk_3c, 0x10) = self->pos.y - m->check.y;
            v = 1;
            if (m->unk_54 & 0x10000) {
                v = 3;
            }
            {
                Ov012Nib *n = &FLD(Ov012Nib, self->unk_3c, 0x18);
                n->hi = n->lo;
                n->lo = v;
            }
            func_ov000_02191c24(self->unk_3c, &self->pos);
        }
    } else {
        r = func_ov000_02194c08(self);
    }
    return r;
}

void func_ov012_02205818(Ov003Actor *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40((u8 *)self + 0x24));
    }
    if (!(FLD(u32, self, 0xd0) & 0x100000)) {
        func_ov000_02190a80((u8 *)self + 0x210, func_0203db40((u8 *)self + 0x24));
    }
}
}

extern "C" {
extern char data_ov012_0220b0a7[];
void func_ov012_02205864(Ov003Actor *self) {
    func_ov000_02194758(self);
    FLD(u32, self, 0xd0) = 0;
    FLD(u8, self, 0x2f8) = 1;
    FLD(u8, self, 0xd4) = self->unk_18;
    if (FLD(u8, self, 0xd4)) {
        ActorSub48 *m;
        ActorSub44 *n;
        FLD(u32, self, 0xd0) = 0x100000;
        self->model->visible = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->hit;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
    } else {
        self->model->visible = 0;
        func_ov000_0218ffdc((u8 *)self + 0x210, (u8 *)self + 0xd8, 0, 1);
        FLD(s32, self, 0x2b8) = 0x2800;
        FLD(s32, self, 0x2bc) = 0x2800;
        FLD(s32, self, 0x2c0) = 0x2800;
        FLD(Ov012Flags, self, 0x2d2).b0 = 1;
        func_ov000_02190758((u8 *)self + 0x210, &self->rot_x, 0);
        func_ov000_02190cb0((u8 *)self + 0x210, data_ov012_0220b0a7, 0x1000, 0);
        func_ov000_021915a0((u8 *)self + 0x210);
    }
    func_ov000_02198360(self->fsm, 0xb, 0);
}
}

extern "C" {
extern void func_ov012_022065d8(Ov003Actor *self);
extern void func_ov012_02206508(Ov003Actor *self);
extern void func_ov012_02206098(Ov003Actor *self);
extern const VecFx32 data_ov012_0220a84c[];

static inline s32 Ov012_FxMul64d(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 Ov012_Dist84(Ov003Actor *self) {
    s64 sq;
    s32 dx = self->pos.x - self->unk_84.x;
    s32 dz = self->pos.z - self->unk_84.z;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov012_Sqrt2(sq);
}

void func_ov012_02205990(Ov003Actor *self) {
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
            func_0203f364(m);
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
        if (FLD(u8, self, 0xd4) == 0) {
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
        func_ov012_022065d8(self);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_84) <= 0x800) {
            ActorSub48 *m;
            ActorSub44 *n;
            EffectObj *o;
            FLD(u32, self, 0xd0) = 0x100000;
            FLD(Ov012Flags, self, 0x2d2).b0 = 0;
            self->model->visible = 1;
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            o = func_02065f88(0x57c, &self->pos);
            o->SetScaleAll(0x2000);
            o = func_02065f88(0x6b, &self->pos);
            o->SetScaleAll(0x2000);
            func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
            func_02049a48(data_02097e4c, 0x4f, 0x6e, -1, -1);
            func_ov012_02206508(self);
            self->fsm->st = 10;
        }
        if (self->hit->unk_50 & 0x60000000) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    case 10: {
        s32 d;
        u16 a;
        func_01ffc9fc(&v, &data_ov012_0220a84c[FLD(u8, self, 0xd4)], self->rot_y);
        VEC_Add(&v, &self->pos, &self->unk_84);
        d = Ov012_Dist84(self);
        a = FX_Atan2(d, self->unk_84.y - self->pos.y);
        self->speed = Ov012_FxMul64d(OV012_SIN(a), 0x2b8);
        self->velY = Ov012_FxMul64d(OV012_COS(a), 0x2b8);
        b = 1;
        func_ov000_0219bd20(0x5c03, self->kind, 6, 1, 1, &b);
        self->fsm->st++;
        break;
    }
    case 11: {
        ActorSub40 *s;
        Actor_TurnToPos(self, &self->unk_84, 0x7b);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        func_ov012_022065d8(self);
        s = self->fsm;
        s->timer++;
        if (s->timer > FLD(u8, self, 0xd4) * 0x28 + 100) {
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
        func_02049de8(data_02097e4c, 0x4f);
        self->fsm->st++;
        break;
    }
    case 13:
        Actor_TurnToPos(self, &self->unk_84, 0x19a);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        func_ov012_022065d8(self);
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x60000000) {
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
    } else {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}
}
