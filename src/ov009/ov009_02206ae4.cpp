#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_0203f2b8(void *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern s32 func_02049afc(void *mgr, s32 id);

extern VecFx32 data_ov009_02215f98[];
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_0204a058(void *mgr, s32 a, s32 b, s32 c);

extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern BOOL func_ov000_021b4738(Ov003Actor *a);

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);

struct Ov009Rot {
    s16 x;
    s16 y;
    s16 z;
};

void Ov009ActVt_022178f0_Update(Ov009ActVt_022178f0 *self) {
    Ov003Actor *a;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->fsm->current != 1) {
        return;
    }
    self->unk_b6++;
    self->unk_93_4 = 1;
    if (self->unk_b6 <= 0xdc) {
        return;
    }
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
    }
    self->fsm->flags |= 0x4000;
    self->unk_b6 = 0;
}

void func_ov009_02206bb4(Ov009ActVt_022178f0 *self) {
    VecFx32 d;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        self->unk_10c = func_02049afc(data_02097e4c, 0x3f);
        self->fsm->st++;
        break;
    case 1:
        st->timer++;
        if (st->timer >= 0x1e0) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        d.x = self->unk_f0.x - self->pos.x;
        d.y = self->unk_f0.y - self->pos.y;
        d.z = self->unk_f0.z - self->pos.z;
        VEC_MultAdd(0x3d, &d, &self->pos, &self->pos);
        break;
    }
}

void func_ov009_02206c84(Ov009ActVt_022178f0 *self) {
    VecFx32 t;
    Ov009Rot r;
    Ov003Actor *a;
    Ov003Actor *o;
    EffectObj *e;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        a = func_ov000_0219bf90();
        if (a != NULL) {
            self->target = a->id;
        }
        VEC_Add(&self->pos, &data_ov009_02215f98[self->unk_108], &t);
        r.y = FX_Atan2(t.x - a->pos.x, t.z - a->pos.z) + 0x7800;
        r.x = 0;
        r.z = 0;
        o = func_ov000_0219be1c(0x480b, &t, &r, self->id, self->target);
        if (o == NULL) {
            return;
        }
        o->unk_18 = 5;
        e = func_02065f88(0x325, &self->pos);
        e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
        e->AddPos(&data_ov009_02215f98[self->unk_108]);
        self->fsm->st++;
        break;
    case 1:
        st->timer++;
        if (st->timer <= 0x3c) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_0204a058(data_02097e4c, self->unk_10c, 0x14, 0x1c2);
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
}

void func_ov009_02206e30(Ov009ActVt_022178f0 *self) {
    VecFx32 d;
    ActorSub40 *st;
    EffectObj *e;
    VecFx32 *v = &self->vel;
    switch (self->fsm->st) {
    case 0:
        v->x = 0;
        v->y = -0x48;
        v->z = 0x50;
        VEC_Add(&self->pos, v, &self->pos);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0xf) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 1:
        d.x = 0 - v->x;
        d.y = -0x133 - v->y;
        d.z = 0x19a - v->z;
        VEC_MultAdd(0x66, &d, v, v);
        VEC_Add(&self->pos, v, &self->pos);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x104) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
    if (!(self->fsm->timer & 0x3f)) {
        s32 a;
        s32 b;
        e = func_02065f88(0x325, &self->pos);
        e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
        e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
        a = Rand_UpTo(0x4000);
        b = Rand_UpTo(0x4000);
        e->AddPosXYZ(-0x3800, a + 0x2800, -0x3000 - b);
    }
}

void func_ov009_0220703c(Ov009ActVt_022178f0 *self) {
    VecFx32 d;
    ActorSub40 *st = self->fsm;
    VecFx32 *t = &self->unk_fc;
    Ov003Actor *a;
    if (st->timer != 0) {
        st->timer--;
    }
    if (st->timer == 0) {
        self->fsm->timer = 0x4b;
        *t = self->unk_f0;
        t->x += Rand_PlusMinus(0x8cd);
        t->y += Rand_PlusMinus(0x8cd);
        t->z += Rand_PlusMinus(0x8cd);
    }
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
    if (self->unk_10c < 0) {
        return;
    }
    a = func_ov000_0219bf90();
    if (a != NULL && !func_ov000_021b4738(a)) {
        return;
    }
    SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
    self->unk_10c = -1;
}

void func_ov009_02207164(Ov009ActVt_022178f0 *self) {
    VecFx32 p;
    Ov009Rot r;
    Ov003Actor *t;
    Ov003Actor *o;
    EffectObj *e;
    u16 ang;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    p = t->pos;
    if (p.z - self->pos.z < -0x14000) {
        func_ov000_02198360(self->fsm, 1, 0);
        return;
    }
    if (p.z > self->pos.z) {
        self->unk_108 = 0;
        ang = Rand_UpTo(0xc00) - 0x200;
    } else {
        self->unk_108++;
        if (self->unk_108 >= 3) {
            self->unk_108 = 1;
        }
        ang = -Rand_UpTo(0xc00);
    }
    VEC_Add(&self->pos, &data_ov009_02215f98[self->unk_108], &p);
    r.y = ang + (FX_Atan2(p.x - t->pos.x, p.z - t->pos.z) + 0x8000);
    r.x = 0;
    r.z = 0;
    o = func_ov000_0219be1c(0x480b, &p, &r, self->id, self->target);
    if (o != NULL) {
        o->unk_18 = 5;
        e = func_02065f88(0x325, &self->pos);
        e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
        e->AddPos(&data_ov009_02215f98[self->unk_108]);
    }
    func_ov000_02198360(self->fsm, 1, 0);
}

extern const u16 data_ov009_02215ef0[3];
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_0203f364(ActorSub48 *p);
void func_ov009_02207314(Ov009ActVt_022178f0 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        self->unk_fc.y = y;
        self->unk_fc.x = x;
        self->unk_fc.z = z;
        self->unk_fc.y -= Rand_UpTo(0x2800) + 0x800;
        self->unk_fc.z += Rand_UpTo(0x1c00) + 0x800;
        if (self->unk_10a > 2) {
            self->unk_10a = 2;
        }
        *self->hp = data_ov009_02215ef0[self->unk_10a];
        self->unk_10a++;
        if (self->unk_10a > 2) {
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x480b, 0x15);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            if (self->unk_44 != NULL) {
                ActorSub44 *s44 = self->unk_44;
                s44->unk_22_0 = 0;
                s44->unk_22_1 = 0;
            }
            if (self->hit != NULL) {
                ActorSub48 *s48 = self->hit;
                s48->unk_9a_0 = 0;
                s48->unk_9a_3 = 0;
                func_0203f364(s48);
            }
        }
        self->fsm->st++;
    }
    case 1: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            if (self->unk_10a > 2) {
                ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x480b, 0x15);
                self->unk_93_4 = 0;
                self->unk_ea_6 = 1;
                self->fsm->timer = 0;
                self->fsm->st = 10;
                func_ov003_021d6a3c(self, 0, 0, 1);
                return;
            }
            func_ov000_02198360(self->fsm, 1, 0);
        }
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
        break;
    }
    case 10:
        self->vfunc_50();
        if (self->fsm->timer == 1) {
            EffectObj *e = func_02065f88(0x325, &self->pos);
            s32 a;
            s32 b;
            e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
            e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
            a = Rand_UpTo(0x4000);
            b = Rand_UpTo(0x4000);
            e->AddPosXYZ(-0x3000, a + 0x1800, -0x1800 - b);
        }
        break;
    }
}

}
