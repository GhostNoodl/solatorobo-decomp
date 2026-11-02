#include "ov011/ov011.h"

struct Ov011E40b {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

struct Ov011Mgr3 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40b *arr8;
    Ov011List *list;
    void *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_20[0x8];
    u8 unk_28[0xb8];
};

extern "C" {

void *Ov003Vt_021f7d2c_Ctor(void *p);

extern void *data_02097e4c;
extern const VecFx32 data_ov011_022072b4;

void func_ov011_0220121c(void *o, s32 a);
void *__cxa_vec_new(u32 count, u32 size, u32 hdr, void *ctor, void *dtor);
Ov011E40b *func_ov011_021fc0a0(Ov011E40b *self);
BOOL func_ov011_02201f28(void *self, u16 id, const VecFx32 *off, s16 c, s16 d, s16 e);
void func_ov011_02202464(void *self);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

static inline Ov011Npc *Ov011_Find(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : (Ov011Npc *)ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Ov011_NodeOk(Ov011Node *p) {
    if (p != NULL) {
        Ov011Npc *o = Ov011_Find(p->id);
        if (o != NULL && func_ov011_02201244(o)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov011_021fbe08(Ov011Mgr3 *self) {
    Ov011Node *head = self->list->head;
    Actor *actor = self->list->actor;
    switch (self->state) {
    case 0: {
        Ov011Node *p;
        s32 n = 0;
        s16 cnt;
        s32 i;
        Actor *a;
        VecFx32 v;
        VecFx32 w;
        for (p = head; p != NULL; p = p->next) {
            if (Ov011_NodeOk(p) == TRUE) {
                n++;
            }
        }
        cnt = n;
        self->count = cnt;
        self->arr8 = (Ov011E40b *)__cxa_vec_new(self->count, 0x40, 8, (void *)func_ov011_021fc0a0, (void *)func_ov011_021fb66c);
        i = 0;
        for (p = head; p != NULL; p = p->next) {
            Ov011Npc *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                u16 id = o->id;
                Ov011E40b *e = &self->arr8[i];
                e->b0 = 0;
                e->b1 = 0;
                e->unk_02 = id;
                e->unk_04 = 0;
                e->mover.v08();
                func_ov011_0220121c(o, 0);
                i++;
            }
        }
        *(Ov011Blk12 *)&v = *(const Ov011Blk12 *)&data_ov011_022072b4;
        a = self->list->actor;
        func_ov011_02201f28(self->unk_28, a->id, &v, cnt, 0x1000, 0x2333);
        func_ov011_02202464(self->unk_28);
        w.x = a->pos.x;
        w.y = a->pos.y;
        w.z = a->pos.z;
        func_02049f44(data_02097e4c, 0x44, &w, 0);
        self->state = 1;
        break;
    }
    case 1: {
        Ov011Node *p;
        long x;
        long y;
        long z;
        self->timer++;
        if (self->timer >= 0x32) {
            self->flags |= 0x10;
        }
        x = actor->pos.x;
        y = actor->pos.y;
        z = actor->pos.z;
        for (p = head; p != NULL; p = p->next) {
            Ov011Npc *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                o->pos.x = x;
                o->pos.y = y + 0x6800;
                o->pos.z = z;
            }
        }
        break;
    }
    }
}

#pragma force_active on
Ov011E40b *func_ov011_021fc0a0(Ov011E40b *self) {
    Ov003Vt_021f7d2c_Ctor(&self->mover);
    return self;
}
#pragma force_active reset
}

#ifdef NONMATCHING
// Status (round drA): func_ov011_021fc0b8 is 26 / 17 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: one move-constant-loads step: the list-removal zero is hoisted past the n !=
// NULL guard (refusing it under gdb gives 0 / 0). History: docs/MATCHING.md rounds hzR, hzZ, raG, hzA, svC, cvA
// (search for the address); the full list is docs/UNMATCHED.md.
// func_ov011_021fc0b8: 13 raw / 3 register-masked diffs, real signature (self only).
// In case 2 the ROM keeps the 1 passed as on in sl and sets the list-removal zero in the inner preheader; this draft hoists the zero further.
// Rounds hzZ/hzR: the whole difference is one refused step of the move-constant-loads pass (the removal zero, inner
// preheader to the n != NULL guard); forcing that refusal in the compiler gives 0 / 0. See docs/MATCHING.md.
// Round raG: rule C (0x526470) only decides whether a moved zero reuses an equal constant or gets a new load;
// it never refuses a step (0x5264f0 fails only when the target block has no instructions at all). A reused
// single-def zero is itself a move candidate when its block is visited, so an enum zero local (declared at the
// top of Remove, in the loop body, or before the if) just starts the same walk (26 / 3).
// Round hzA: refusal (d), a zero whose vreg has two definitions, is never moved (checked: an enum local with a
// second def stays exactly where its first def is), but no honest source puts such a def between the guard and the loop.

struct Ov011Slot {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    s16 timer;
    u8 unk_06[0x2];
    Ov011E38 obj;
};

struct Ov011Chr;

struct Ov011Ctl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011Slot *slots;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_20[0x8];
    u8 chr[0x4];
};

struct Ov011Msg {
    s32 a;
    s32 b;
    s32 c;
};

struct Ov011Msg2 {
    s32 a;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 pad;
    s16 x;
    s16 y;
};

extern "C" {

extern const VecFx32 data_ov011_02207278;
void Ov003Mover_SetSpeed(void *p, s32 a);
void Ov003Mover_SetMaxDist(void *p, s32 a);
void func_ov003_021d7c08(void *p, VecFx32 *v);
VecFx32 *Ov003Mover_GetDir(void *p);
u16 Ov003Vec_Pitch(VecFx32 *v);
u16 Ov003Vec_Yaw(VecFx32 *v);
BOOL Ov003Mover_Start(void *p, VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e);
void func_ov011_022011fc(void *a, s32 b);
void func_ov011_022011c8(void *a, s32 b);
s32 Rand_PlusMinus(s32 max);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov011_02202488(void *self, s16 v);
void func_ov011_022024ac(void *self, s16 v);
VecFx32 func_ov011_022024d4(const void *self);
Ov011LNode *func_ov011_021fa790(Ov011LNode *head, Ov011LNode *item);
void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
BOOL func_ov000_021b4738(void *pl);
}

static inline Ov011Slot *Ov011Ctl_Find(Ov011Ctl *self, u16 id) {
    Ov011Slot *r = NULL;
    if (self->slots != NULL) {
        s32 j;
        for (j = 0; j < self->count; j++) {
            if (id == self->slots[j].id) {
                r = &self->slots[j];
            }
        }
    }
    return r;
}

static inline void Ov011Ent_Remove(Ov011Ent *e, void *k) {
    if (e->active) {
        Ov011PNode *n;
        for (n = e->nodes; n != NULL; n = n->next) {
            if (k == n) {
                e->nodes = (Ov011PNode *)func_ov011_021fa790((Ov011LNode *)e->nodes, (Ov011LNode *)n);
                if (n != NULL) {
                    Heap_Free(n);
                }
                e->settled = 0;
                e->blend = 0;
                break;
            }
        }
    }
}

static inline void Ov011_Send(u16 id, s32 a, s32 b) {
    Ov011Msg m;
    m.a = a;
    m.b = b;
    ActorMgr_SendMsg(id, 0xffff, 0xe, 1, 0xc, &m);
}

static inline void Ov011_Send2(u16 id) {
    Ov011Msg2 m;
    m.a = 2;
    m.b0 = 0;
    m.b1 = 1;
    m.x = 0x1000;
    m.y = 0x1000;
    ActorMgr_SendMsg(id, 0xffff, 0xe, 1, 0xc, &m);
}

static inline void Ov011Slot_Kill(Ov011Slot *s) {
    s->b0 = 1;
    s->b1 = 1;
    s->id = 0;
    s->timer = 0;
    s->obj.v08();
}

static inline BOOL Ov011_PlBusy(void) {
    void *pl = func_ov000_0219bf90();
    if (pl != NULL && !func_ov000_021b4738(pl)) {
        return FALSE;
    }
    return TRUE;
}

static inline void Ov011_Act(Ov011Ctl *self, Ov011Npc *a, BOOL on) {
    func_ov011_0220121c(a, on);
    func_ov011_022011fc(a, on);
    {
        Ov011Ent *ent = self->ent;
        Ov011Ent_Remove(ent, func_ov011_02201254(a));
    }
    func_ov011_02201214(a, NULL);
}
extern "C" {

void func_ov011_021fc0b8(Ov011Ctl *self) {
    s32 i;
    Ov011Npc *a;
    Ov011Node *n;
    Ov011List *list;
    for (i = 0; i < self->count; i++) {
        if (self->slots[i].b1) {
            continue;
        }
        a = Ov011_FindNpc(self->slots[i].id);
        if (a == NULL) {
                        Ov011Slot *s = &self->slots[i];
            s->b0 = 1;
            s->b1 = 1;
            s->id = 0;
            s->timer = 0;
            s->obj.v08();

        } else {
            if (!self->slots[i].b0) {
                Actor *o = self->list->actor;
                s32 x = o->pos.x;
                s32 y = o->pos.y;
                s32 z = o->pos.z;
                y += 0x6800;
                a->pos.x = x;
                a->pos.y = y;
                a->pos.z = z;
                continue;
            }
            {
                VecFx32 *p = (VecFx32 *)self->slots[i].obj.v10();
                a->pos.x = p->x;
                a->pos.y = p->y;
                a->pos.z = p->z;
            }
            if (self->slots[i].timer <= 0x50) {
                VecFx32 v = data_ov011_02207278;
                VecFx32 w;
                ActorSub48 *m;
                if (self->slots[i].timer == 0x50) {
                    Ov003Mover_SetSpeed(&self->slots[i].obj, 0x66);
                    Ov003Mover_SetMaxDist(&self->slots[i].obj, 0x948);
                    func_ov011_022011fc(a, 0);
                    func_02049f44(data_02097e4c, 0x2f, (VecFx32 *)self->slots[i].obj.v10(), 0);
                    v.x = Rand_PlusMinus(0x1000);
                    v.z = Rand_PlusMinus(0x1000);
                }
                m = ((Actor *)func_ov000_0219bf90())->hit;
                w.x = m->check.x;
                w.y = m->check.y;
                w.z = m->check.z;
                VEC_Add(&w, &v, &w);
                w.y += 0x1000;
                func_ov003_021d7c08(&self->slots[i].obj, &w);
                if (self->slots[i].timer == 0x50) {
                    VecFx32 t = *(VecFx32 *)self->slots[i].obj.v10();
                    EffectObj *e = func_02065f88(0x192, &t);
                    VecFx32 d = *Ov003Mover_GetDir(&self->slots[i].obj);
                    e->SetRotXYZ(Ov003Vec_Pitch(&d), Ov003Vec_Yaw(&d), 0);
                    e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
                }
                continue;
            }
            func_ov000_021987b8(a->hit, 1, 0, 0);
            if (!(a->hit->unk_50 & 0x60000000)) {
                continue;
            }
            {
                VecFx32 p;
                u16 ang;
                EffectObj *e;
                Camera *q;
                p.x = a->pos.x;
                p.y = a->pos.y;
                p.z = a->pos.z;
                func_ov011_022011c8(a, 0);
                p.y -= a->hit->radius;
                ang = Ov003Vec_Yaw(Ov003Mover_GetDir(&self->slots[i].obj)) + 0x7fff;
                e = func_02065f88(0x67, &p);
                e->SetRotXYZ(0, ang, 0);
                e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
                func_02049f44(data_02097e4c, 0x1a, &p, 0);
                q = &data_ov000_021ccd54->cam.base;
                if (q != NULL) {
                    q->shakeX = 1;
                    q->shakeY = 1;
                    q->shakeZ = 1;
                    q->shakeTime = 10;
                    q->shakeLen = 10;
                    q->shakeCur = 10;
                }
                            Ov011Slot *s = &self->slots[i];
            s->b0 = 1;
            s->b1 = 1;
            s->id = 0;
            s->timer = 0;
            s->obj.v08();

            }
        }
    }
    n = self->list->head;
    list = self->list;
    switch (self->state) {
    case 0: {
        s32 cnt = 0;
        for (; n != NULL; n = n->next) {
            if (Ov011_NodeOk(n) == TRUE) {
                cnt++;
            }
        }
        func_ov011_02202488(self->chr, cnt);
        self->state = 1;
        break;
    }
    case 1:
        self->timer++;
        if (self->timer >= 50) {
            self->timer = 0;
            self->state = 2;
        }
        break;
    case 2: {
        s16 cnt = 0;
        Ov011Slot *found;
        { s32 j; for (j = 0; j < self->count; j++) {
            if (!self->slots[j].b0) {
                cnt++;
            }
        } }
        func_ov011_022024ac(self->chr, cnt);
        BOOL on;
        found = NULL;
        on = TRUE;
        for (; n != NULL; n = n->next) {
            Ov011Slot *s;
            a = Ov011_FindNpc(n->id);
            s = Ov011Ctl_Find(self, a->id);
            if (s != NULL && !s->b0) {
                found = s;
                Ov011_Act(self, a, on);
                break;
            }
        }
        {
            VecFx32 c;
            VecFx32 pp;
            Actor *pl;
            c = func_ov011_022024d4(self->chr);
            pl = (Actor *)func_ov000_0219bf90();
            pp.x = pl->pos.x;
            pp.y = pl->pos.y;
            pp.z = pl->pos.z;
            found->b0 = 1;
            Ov003Mover_Start(&found->obj, &pp, &c, 0x14, 0x11f, 1);
            self->state = 3;
            func_02049f44(data_02097e4c, 0x35, &c, 0);
        }
        break;
    }
    case 3: {
        BOOL ok;
        self->timer++;
        if (self->timer < 50) {
            return;
        }
        ok = TRUE;
        { s32 j; for (j = 0; j < self->count; j++) {
            if (!self->slots[j].b0) {
                ok = FALSE;
                self->state = 2;
            }
        } }
        if (ok) {
            self->state = 5;
        }
        self->timer = 0;
        break;
    }
    case 5: {
        BOOL ok = TRUE;
        { s32 j; for (j = 0; j < self->count; j++) {
            if (!self->slots[j].b1) {
                ok = FALSE;
            }
        } }
        if (!ok) {
            return;
        }
        if (self->timer == 0) {
            Actor *act = list->actor;
            Ov011_Send(act->id, 1, 0);
            Ov011_Send2(act->id);
        } else if (self->timer == 30) {
            Ov011_Send(list->actor->id, 1, 1);
        } else if (self->timer > 150) {
            self->flags |= 2;
        } else {
            void *pl = func_ov000_0219bf90();
            if (pl == NULL || func_ov000_021b4738(pl)) {
                self->flags |= 2;
            }
        }
        self->timer++;
        break;
    }
    }
}
}
#endif
