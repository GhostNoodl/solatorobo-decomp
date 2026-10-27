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

void func_ov003_021d79d0(void *p);

extern void *data_02097e4c;
extern const Ov011Vec data_ov011_022072b4;

BOOL func_ov011_02201244(u8 *o);
void func_ov011_0220121c(u8 *o, s32 a);
void *__cxa_vec_new(u32 count, u32 size, u32 hdr, void *ctor, void *dtor);
void *func_ov011_021fb66c(void *self);
void *func_ov011_021fc0a0(void *self);
void func_ov011_02201f28(void *self, u16 id, const Ov011Vec *off, s16 c, s16 d, s16 e);
void func_ov011_02202464(void *self);
void func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);

static inline u8 *Ov011_Find(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov011_NodeOk(Ov011Node *p) {
    if (p != NULL) {
        u8 *o = Ov011_Find(p->id);
        if (o != NULL && func_ov011_02201244(o)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov011_021fbe08(Ov011Mgr3 *self) {
    Ov011Node *head = self->list->head;
    u8 *actor = (u8 *)self->list->actor;
    switch (self->state) {
    case 0: {
        Ov011Node *p;
        s32 n = 0;
        s16 cnt;
        s32 i;
        u8 *a;
        Ov011Vec v;
        Ov011Vec w;
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
            u8 *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                u16 id = FLD(u16, o, 0xc);
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
        a = (u8 *)self->list->actor;
        func_ov011_02201f28(self->unk_28, FLD(u16, a, 0xc), &v, cnt, 0x1000, 0x2333);
        func_ov011_02202464(self->unk_28);
        w.x = FLD(s32, a, 0x70);
        w.y = FLD(s32, a, 0x74);
        w.z = FLD(s32, a, 0x78);
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
        x = FLD(s32, actor, 0x70);
        y = FLD(s32, actor, 0x74);
        z = FLD(s32, actor, 0x78);
        for (p = head; p != NULL; p = p->next) {
            u8 *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                FLD(s32, o, 0x70) = x;
                FLD(s32, o, 0x74) = y + 0x6800;
                FLD(s32, o, 0x78) = z;
            }
        }
        break;
    }
    }
}

#pragma force_active on
void *func_ov011_021fc0a0(void *self) {
    func_ov003_021d79d0((u8 *)self + 8);
    return self;
}
#pragma force_active reset
}

#ifdef NONMATCHING
// func_ov011_021fc0b8: 13 raw / 3 register-masked diffs, real signature (self only).
// In case 2 the ROM keeps the 1 passed as on in sl and sets the list-removal zero inside the inner loop; this draft hoists the zero instead.

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

extern const Ov011Vec data_ov011_02207278;
void func_ov003_021d7c90(void *p, s32 a);
void func_ov003_021d7c78(void *p, s32 a);
void func_ov003_021d7c08(void *p, Ov011Vec *v);
Ov011Vec *func_ov003_021d7bd4(void *p);
s32 func_ov003_021d9c74(Ov011Vec *v);
s32 func_ov003_021d9c38(Ov011Vec *v);
void func_ov003_021d7a44(void *p, Ov011Vec *a, Ov011Vec *b, s32 c, s32 d, s32 e);
void func_ov011_022011fc(void *a, s32 b);
void func_ov011_022011c8(void *a, s32 b);
void func_ov011_02201214(void *a, void *b);
void *func_ov011_02201254(void *self);
s32 func_02040528(s32 max);
Ov011V *func_02065f88(s32 id, Ov011Vec *pos);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov011_02202488(void *self, s16 v);
void func_ov011_022024ac(void *self, s16 v);
Ov011Vec func_ov011_022024d4(const void *self);
Ov011LNode *func_ov011_021fa790(Ov011LNode *head, Ov011LNode *item);
void func_ov000_0219bdb0(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
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
    if (e->b0) {
        Ov011PNode *n;
        for (n = e->unk_04; n != NULL; n = n->next) {
            if (k == n) {
                e->unk_04 = (Ov011PNode *)func_ov011_021fa790((Ov011LNode *)e->unk_04, (Ov011LNode *)n);
                if (n != NULL) {
                    func_0203de1c(n);
                }
                e->b1 = 0;
                e->unk_08 = 0;
                break;
            }
        }
    }
}

static inline void Ov011_Send(u16 id, s32 a, s32 b) {
    Ov011Msg m;
    m.a = a;
    m.b = b;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &m);
}

static inline void Ov011_Send2(u16 id) {
    Ov011Msg2 m;
    m.a = 2;
    m.b0 = 0;
    m.b1 = 1;
    m.x = 0x1000;
    m.y = 0x1000;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &m);
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

static inline void Ov011_Act(Ov011Ctl *self, u8 *a, BOOL on) {
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
    u8 *a;
    Ov011Node *n;
    Ov011List *list;
    for (i = 0; i < self->count; i++) {
        if (self->slots[i].b1) {
            continue;
        }
        a = (u8 *)Ov011_FindActor(self->slots[i].id);
        if (a == NULL) {
                        Ov011Slot *s = &self->slots[i];
            s->b0 = 1;
            s->b1 = 1;
            s->id = 0;
            s->timer = 0;
            s->obj.v08();

        } else {
            if (!self->slots[i].b0) {
                void *o = self->list->actor;
                s32 x = FLD(s32, o, 0x70);
                s32 y = FLD(s32, o, 0x74);
                s32 z = FLD(s32, o, 0x78);
                y += 0x6800;
                FLD(s32, a, 0x70) = x;
                FLD(s32, a, 0x74) = y;
                FLD(s32, a, 0x78) = z;
                continue;
            }
            {
                Ov011Vec *p = (Ov011Vec *)self->slots[i].obj.v10();
                FLD(s32, a, 0x70) = p->x;
                FLD(s32, a, 0x74) = p->y;
                FLD(s32, a, 0x78) = p->z;
            }
            if (self->slots[i].timer <= 0x50) {
                Ov011Vec v = data_ov011_02207278;
                Ov011Vec w;
                void *m;
                if (self->slots[i].timer == 0x50) {
                    func_ov003_021d7c90(&self->slots[i].obj, 0x66);
                    func_ov003_021d7c78(&self->slots[i].obj, 0x948);
                    func_ov011_022011fc(a, 0);
                    func_02049f44(data_02097e4c, 0x2f, (Ov011Vec *)self->slots[i].obj.v10(), 0);
                    v.x = func_02040528(0x1000);
                    v.z = func_02040528(0x1000);
                }
                m = FLD(void *, func_ov000_0219bf90(), 0x48);
                w.x = FLD(s32, m, 0x68);
                w.y = FLD(s32, m, 0x6c);
                w.z = FLD(s32, m, 0x70);
                VEC_Add(&w, &v, &w);
                w.y += 0x1000;
                func_ov003_021d7c08(&self->slots[i].obj, &w);
                if (self->slots[i].timer == 0x50) {
                    Ov011Vec t = *(Ov011Vec *)self->slots[i].obj.v10();
                    Ov011V *e = func_02065f88(0x192, &t);
                    Ov011Vec d = *func_ov003_021d7bd4(&self->slots[i].obj);
                    e->v34(func_ov003_021d9c74(&d), func_ov003_021d9c38(&d), 0);
                    e->v14(0x1ccd, 0x1ccd, 0x1ccd);
                }
                continue;
            }
            func_ov000_021987b8(FLD(void *, a, 0x48), 1, 0, 0);
            if (!(FLD(u32, FLD(void *, a, 0x48), 0x50) & 0x60000000)) {
                continue;
            }
            {
                Ov011Vec p;
                u16 ang;
                Ov011V *e;
                u8 *q;
                p.x = FLD(s32, a, 0x70);
                p.y = FLD(s32, a, 0x74);
                p.z = FLD(s32, a, 0x78);
                func_ov011_022011c8(a, 0);
                p.y -= FLD(s32, FLD(void *, a, 0x48), 0x38);
                ang = func_ov003_021d9c38(func_ov003_021d7bd4(&self->slots[i].obj)) + 0x7fff;
                e = func_02065f88(0x67, &p);
                e->v34(0, ang, 0);
                e->v14(0x1ccd, 0x1ccd, 0x1ccd);
                func_02049f44(data_02097e4c, 0x1a, &p, 0);
                q = (u8 *)data_ov000_021ccd54 + 0xf4;
                if (q != NULL) {
                    FLD(Ov011Flags8, q, 0x9c).b2 = 1;
                    FLD(Ov011Flags8, q, 0x9c).b3 = 1;
                    FLD(Ov011Flags8, q, 0x9c).b4 = 1;
                    FLD(u8, q, 0x99) = 10;
                    FLD(u8, q, 0x9a) = 10;
                    FLD(u8, q, 0x9b) = 10;
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
            a = (u8 *)Ov011_FindActor(n->id);
            s = Ov011Ctl_Find(self, FLD(u16, a, 0xc));
            if (s != NULL && !s->b0) {
                found = s;
                Ov011_Act(self, a, on);
                break;
            }
        }
        {
            Ov011Vec c;
            Ov011Vec pp;
            void *pl;
            c = func_ov011_022024d4(self->chr);
            pl = func_ov000_0219bf90();
            pp.x = FLD(s32, pl, 0x70);
            pp.y = FLD(s32, pl, 0x74);
            pp.z = FLD(s32, pl, 0x78);
            found->b0 = 1;
            func_ov003_021d7a44(&found->obj, &pp, &c, 0x14, 0x11f, 1);
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
            void *act = list->actor;
            Ov011_Send(FLD(u16, act, 0xc), 1, 0);
            Ov011_Send2(FLD(u16, act, 0xc));
        } else if (self->timer == 30) {
            Ov011_Send(FLD(u16, list->actor, 0xc), 1, 1);
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
