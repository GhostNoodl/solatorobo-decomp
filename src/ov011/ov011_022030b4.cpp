#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
extern const char data_ov011_02207bd8[];
u16 ActorGroup_CountKind(void *g, u16 id);
void Actor_TurnToActor(void *self, void *target, s32 c);
void func_ov000_021911c8(void *a, s32 b);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
Ov011V *func_02065f88(s32 id, VecFx32 *v);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);
void func_ov000_0218d7e8(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);

void Ov011ActVt_02207b34_Update(Ov003Actor *self) {
    BOOL ok;
    void *g;
    if (!Ov011_GameIdle()) {
        return;
    }
    self->unk_93_4 = 1;
    ok = TRUE;
    g = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
    if (g != NULL && ActorGroup_CountKind(g, 0x5807) >= 1) {
        ok = FALSE;
    }
    if (ok) {
        Ov003Actor *pl;
        self->target = 0xffff;
        pl = (Ov003Actor *)func_ov000_0219bf90();
        if (pl == NULL) {
            return;
        }
        self->target = pl->id;
        self->fsm->flags |= 0x4000;
    } else {
        func_ov003_021d1e8c(self);
    }
}

void func_ov011_022031a0(Ov003Actor *self) {
    ActorSub40 *s;
    u8 a;
    s32 v;
    self->unk_ee_2 = 1;
    self->vfunc_64();
    s = self->fsm;
    if (s->current == 1) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        return;
    }
    a = self->unk_3c->unk_19;
    v = self->unk_3c->unk_14;
    if (a == 0xff) {
        a = 15;
    }
    if (s->st == 10) {
        v += FX_Mul(0x6000 - v, 0x333);
        if (a >= 25) {
            a = 25;
        } else {
            a++;
        }
    } else if (s->st == 20) {
        void *t;
        if (a <= 15) {
            a = 15;
        } else {
            a--;
            v += FX_Mul(self->radius * 2 - v, 0x59a);
            self->unk_94_1 = 1;
        }
        t = Ov011_FindActor(self->target);
        if (t != NULL) {
            Actor_TurnToActor(self, t, 0x400);
        }
    }
    self->unk_3c->unk_14 = v;
    self->unk_3c->unk_19 = a;
}

void func_ov011_022032fc(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void func_ov011_02203320(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov011_02207bd8, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->model->visible = 0;
        self->fsm->st++;
        break;
    case 1: {
        Ov011V *p;
        if (++s->timer <= 120) {
            return;
        }
        func_02049a48(data_02097e4c, 50, 100, -1, -1);
        p = func_02065f88(50 + 0x358, &self->pos);
        p->v14(0x1666, 0x1666, 0x1666);
        p->v24(0, 0x1000, 0);
        self->model->visible = 1;
        self->model->alpha = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 2:
        if (++s->timer > 60) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            self->model->alpha = 0x1f;
            func_ov000_02198360(self->fsm, 1, 0);
        } else if (self->fsm->timer > 30) {
            u8 v = self->model->alpha + 1;
            if (v > 0x1f) {
                v = 0x1f;
            }
            self->model->alpha = v;
        }
        break;
    }
}

void func_ov011_022034fc(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
    }
    func_ov003_021d5348(self);
}

void func_ov011_02203534(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        if (*self->hp == 0) {
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x5807, 0x15);
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4803, 0x15);
        }
    }
    func_ov003_021d5900(self);
}

void func_ov011_022035b8(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Ov011V *p;
        self->unk_3c->unk_14 = self->radius * 2;
        self->unk_3c->unk_19 = 0xff;
        p = func_02065f88(0x69, &self->pos);
        if (p != NULL) {
            p->v0c(0x2400);
            p->v24(0, 0x1000, 0);
        }
    }
    func_ov003_021d6054(self);
}

void Ov011ActVt_02207a88_Start(Ov003Actor *self) {
    func_ov003_021d112c(self);
    func_ov000_0218d7e8(self, 0xb);
}

void func_ov011_02203654(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        self->speed = 0x59a;
        self->velY = 0;
        self->gravity = 5;
        self->friction = 0x1400 - 0x59a;
        self->moveYaw = self->rot_y;
        func_ov000_02190cb0(self->model, data_ov011_02207bd8, 0x1000, 0);
        func_ov000_021911c8(self->model, 0x2000);
        func_02049a48(data_02097e4c, 0x29, -1, -1, -1);
        self->fsm->st++;
        break;
    case 1:
        if (++s->timer > 60) {
            self->gravity = 0x29;
            func_ov000_02198360(self->fsm, 4, 0);
        }
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        break;
    }
}

Ov003Actor *Ov011ActVt_02207b34_Dtor(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207b34_DtorDelete(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207a88_Dtor(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov003Actor *Ov011ActVt_02207a88_DtorDelete(Ov003Actor *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

void Ov011Act7cf8_Start(Ov011Act7cf8 *self) {
    void *saved;
    func_ov003_021d112c(self);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        void *p = self->hit;
        if (p != NULL) {
            func_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    data_02097dd0->cur = saved;
    Ov011_VecSet(&self->unk_44->unk_0c, 0, -0x333, -self->radius >> 1);
    self->unk_f0.x = 0;
    self->unk_f0.y = 0;
    self->unk_f0.z = 0;
    self->unk_84.x = 0;
    self->unk_84.y = 0;
    self->unk_84.z = 0;
    self->unk_ea_6 = 1;
}

void func_ov011_0220386c(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    u64 f = s->flags;
    if (f == 0) {
        return;
    }
    if ((f & 0x200000) == 0) {
        return;
    }
    func_ov000_02198360(s, 0x15, 0);
}

}
