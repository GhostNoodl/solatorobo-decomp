#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220beb4;
extern VecFx32 data_ov013_0220b3f8;
extern VecFx32 data_ov013_0220b404;
extern ActorEx *ActorEx_Ctor(ActorEx *self);
extern void func_ov000_02194758(void *self);
extern Ov003Actor *func_ov000_0219bf90(void);

void func_ov013_0220a940(Ov003Actor *self) {
    Model0218fe1c *s;
    ActorSub40 *q;
    u8 v;
    Actor_Move(self, 0);
    s = self->model;
    v = s->alpha;
    if (v > 1) {
        v -= 2;
    } else if (v != 0) {
        v -= 1;
    }
    s->alpha = v;
    q = self->fsm;
    q->timer++;
    if (q->timer > 0xf) {
        func_ov000_02198360(self->fsm, 0x15, 0);
    }
}

#pragma force_active on
Ov013ActEx_0220a9a8 *Ov013ActEx_0220a9a8_Ctor(Ov013ActEx_0220a9a8 *self) {
    ActorEx_Ctor(self);
    *(void **)self = &data_ov013_0220beb4;
    self->unk_ce = 0;
    self->unk_d0 = 0;
    self->unk_d4 = 0;
    return self;
}
#pragma force_active reset

void Ov013ActEx_0220a9a8_Start(Ov013ActEx_0220a9a8 *self) {
    Ov003Actor *pl;
    EffectObj *fx;
    func_ov000_02194758(self);
    func_ov000_02198360(self->fsm, 1, 0);
    self->unk_ce = 600;
    self->hit->radius = 0x1b33;
    self->unk_d0 = 0x1000;
    self->target = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->target = pl->id;
    }
    fx = func_02065f88(0x38c, &self->pos);
    if (fx == NULL) {
        return;
    }
    fx->SetScale(&data_ov013_0220b3f8);
    fx->AddPos(&data_ov013_0220b404);
    self->unk_bc = fx->id;
}
extern void func_0203f364(void *p);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);

static inline Ov003Actor *Ov013_FindActorA(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov013_0220aa7c(Ov013ActEx_0220a9a8 *self) {
    Ov003Actor *t;
    switch (self->fsm->st) {
    case 0:
        if (self->unk_d4 != 0) {
            EffectObj *fx;
            s32 k = 0x1b33;
            self->hit->radius = FX_Mul(self->unk_d4, k);
            self->unk_d0 = FX_Mul(self->unk_d4, 0x1000);
            fx = func_020657b0(data_0214a420, self->unk_bc);
            if (fx != NULL) {
                VecFx32 v;
                s32 d = self->unk_d4;
                v.x = FX_Mul(d, 0x1000);
                v.z = v.x;
                v.y = FX_Mul(d, k - 0x1000);
                fx->SetScale(&v);
            }
        }
        self->fsm->st++;
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        break;
    case 1: {
        Ov003Actor *pl = func_ov000_0219bf90();
        if (pl == NULL || func_ov000_021b4738(pl)) {
            self->unk_ce = 1;
        }
        self->unk_ce--;
        if (self->unk_ce == 0) {
            func_ov000_02198360(self->fsm, 10, 0);
            return;
        }
        break;
    }
    }
    t = Ov013_FindActorA(self->target);
    if (t == NULL) {
        return;
    }
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, (u16)(1 << (t->id >> 12)), NULL, 0,
                        self->hit->radius, self->unk_d0, 0x25f, 0x1000);
}

}
