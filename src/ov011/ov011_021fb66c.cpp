#include "ov011/ov011.h"

struct Ov011E40 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[0x3];
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

class Ov011Mgr2 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40 *arr8;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u8 unk_18[0xf];
    u8 unk_27;
    u8 unk_28[0xb8];
    u8 unk_e0[0x4];
};

typedef void (Ov011Mgr2::*Ov011Mgr2Fn)();

struct Ov011Mgr2Entry {
    s32 key;
    Ov011Mgr2Fn fn;
};

static inline s32 Ov011Ent_GetA(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_24;
    }
    return 0;
}

static inline s32 Ov011Ent_GetB(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_0c;
    }
    return 0;
}

static inline u16 Ov011Ent_GetC(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_18;
    }
    return 0;
}

static inline void Ov011Ent_LerpA(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b4 = 1;
        Ov011_SetLerp(&e->unk_24, from, to, frames);
    }
}

static inline void Ov011Ent_LerpB(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b2 = 1;
        Ov011_SetLerp(&e->unk_0c, from, to, frames);
    }
}

static inline void Ov011Ent_LerpC(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b3 = 1;
        Ov011_SetLerp(&e->unk_18, from, to, frames);
    }
}

static inline void Ov011Ent_RestoreA(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpA(e, e->unk_24, to, frames);
    }
}

static inline void Ov011Ent_RestoreB(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpB(e, e->unk_0c, to, frames);
    }
}

static inline void Ov011Ent_RestoreC(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpC(e, (u16)e->unk_18, to, frames);
    }
}

extern "C" {

extern const Ov011Mgr2Entry data_ov011_022072d8[];
void func_ov003_021d79ec(void *p);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, u8 a);
void func_ov011_0220205c(void *p);
void func_ov011_02202130(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_02202ff0(void *p);

void *func_ov011_021fb66c(Ov011E40 *self) {
    func_ov003_021d79ec(&self->mover);
    return self;
}

static inline void Ov011Mgr2_Reset(Ov011Mgr2 *self) {
    u32 saved;
    self->b1 = 0;
    self->count = 0;
    self->unk_04 = -1;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x40, 8, func_ov011_021fb66c);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021da48c(&self->state, 0);
    func_ov011_0220205c(self->unk_28);
    func_ov011_02202fbc(self->unk_e0);
}

void func_ov011_021fb684(Ov011Mgr2 *self) {
    u32 i;
    s32 j;
    u8 key;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    if (self->list->head == NULL) {
        Ov011Mgr2_Reset(self);
        self->b1 = 0;
        if (self->ent == NULL) {
            return;
        }
        Ov011Ent_RestoreA(self->ent, 0x2000, 1);
        Ov011Ent_RestoreB(self->ent, 0x3333, 1);
        Ov011Ent_RestoreC(self->ent, 0x71c, 1);
        return;
    }
    key = self->unk_27;
    for (i = 0; i < 4; i++) {
        if (key == data_ov011_022072d8[i].key && *(s32 *)&data_ov011_022072d8[i].fn != 0) {
            (self->*data_ov011_022072d8[i].fn)();
            break;
        }
    }
    func_ov003_021da40c(&self->state);
    func_ov011_02202130(self->unk_28);
    func_ov011_02202ff0(self->unk_e0);
    for (j = 0; j < self->count; j++) {
        Ov011E40 *p = &self->arr8[j];
        if (p->b0) {
            p->unk_04++;
        }
        p->mover.v0c();
    }
}

void func_ov011_021fb8d4(Ov011Mgr2 *self, s32 a, Ov011List *list, Ov011Ent *ent) {
    if (!self->b0) {
        return;
    }
    self->b1 = 1;
    self->unk_04 = a;
    self->list = list;
    self->ent = ent;
    if (a == 0) {
        func_ov003_021da48c(&self->state, 3);
    } else if (a == 1) {
        func_ov003_021da48c(&self->state, 2);
    }
}

void func_ov011_021fb92c(Ov011Mgr2 *self) {
    Ov011Mgr2_Reset(self);
}


static inline BOOL Ov011Ent_Done4(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b4;
    }
    return r;
}

static inline BOOL Ov011Ent_Done2(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b2;
    }
    return r;
}

static inline BOOL Ov011Ent_Done3(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->b0) {
        r = !e->b3;
    }
    return r;
}

static inline BOOL Ov011Ent_AllDone(Ov011Ent *e) {
    if (!Ov011Ent_Done4(e)) {
        return FALSE;
    }
    if (!Ov011Ent_Done2(e)) {
        return FALSE;
    }
    if (!Ov011Ent_Done3(e)) {
        return FALSE;
    }
    return TRUE;
}

static inline Ov011PNode *Ov011Ent_Find(Ov011Ent *e, void *k) {
    Ov011PNode *r = NULL;
    Ov011PNode *n;
    if (e->b0) {
        for (n = e->unk_04; n != NULL; n = n->next) {
            if (k == n) {
                r = n;
                break;
            }
        }
    }
    return r;
}

static inline void Ov011Ent_SetY(Ov011Ent *e, s32 y) {
    Ov011PNode *n;
    if (e->b0) {
        e->b4 = 0;
        e->unk_24 = y;
        for (n = e->unk_04; n != NULL; n = n->next) {
            n->v.y = y;
        }
    }
}

struct Ov011ArgB {
    s32 kind;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 x;
    s16 y;
    u8 pad2[2];
};

void func_ov000_0219bdb0(u16 a, u16 b, u8 c, s32 d, s32 e, void *f);
u32 func_ov011_02201244(void *self);
void *func_ov011_02201254(void *self);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);
BOOL func_ov011_02202f38(void *self, const Ov011Vec *pos, const Ov011Vec *vel, s32 scale, s32 accel);
Ov011Vec *func_ov011_02203028(void *self);
extern const Ov011Vec data_ov011_0220729c;
extern const Ov011Vec data_ov011_022072a8;

static inline void Ov011_SendB(u16 id, s32 kind, s16 x, s16 y) {
    Ov011ArgB b;
    b.kind = kind;
    b.b0 = 0;
    b.b1 = 0;
    b.x = x;
    b.y = y;
    func_ov000_0219bdb0(id, 0xffff, 0xe, 1, 0xc, &b);
}

static inline void Ov011Ent_Lerp2(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->unk_0c;
    if (e->b0) {
        e->b2 = 1;
        Ov011_SetLerp(&e->unk_0c, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp2X(Ov011Ent *e, s32 frames) {
    s32 c = e->unk_0c;
    if (e->b0) {
        s32 to;
        e->b2 = 1;
        to = 0x4cd;
        (&e->unk_0c)[1] = to;
        (&e->unk_0c)[0] = c;
        (&e->unk_0c)[2] = ((&e->unk_0c)[1] - (&e->unk_0c)[0]) / frames;
    }
}

static inline void Ov011Ent_RestoreB2(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_Lerp2(e, to, frames);
    }
}

static inline void Ov011_Attach(Ov011PNode *p, void *owner, void *a) {
    Ov011Vec v;
    Ov011Vec o;
    Ov011Vec r;
    v.x = p->v.x;
    v.y = p->v.y;
    v.z = p->v.z;
    o.x = FLD(s32, owner, 0x70);
    o.y = FLD(s32, owner, 0x74);
    o.z = FLD(s32, owner, 0x78);
    VEC_Add(&v, &o, &r);
    FLD(s32, a, 0x70) = r.x;
    FLD(s32, a, 0x74) = r.y;
    FLD(s32, a, 0x78) = r.z;
}

void func_ov011_021fb9b8(Ov011Mgr2 *self, void *owner) {
    BOOL any;
    BOOL ok;
    Ov011Node *head;
    Ov011Node *n;
    head = self->list->head;
    owner = self->list->actor;
    switch (self->state) {
    case 0: {
        any = FALSE;
        for (n = head; n != NULL; n = n->next) {
            if (func_ov011_02201244(Ov011_FindActor(n->id))) {
                any = TRUE;
            }
        }
        if (!any) {
            Ov011Mgr2_Reset(self);
            self->b1 = 0;
        }
        {
            Ov011Vec a = data_ov011_0220729c;
            Ov011Vec b = data_ov011_022072a8;
            func_ov011_02202fbc(self->unk_e0);
            func_ov011_02202f38(self->unk_e0, &a, &b, 0x500, 0x80);
        }
        if (self->ent->b0) {
            Ov011Ent_Lerp2X(self->ent, 0x2d);
        }
        Ov011_SendB(FLD(u16, owner, 0xc), 2, 0x1000, 0x1000);
        self->state = 1;
    }
    case 1: {
        ok = TRUE;
        for (n = head; n != NULL; n = n->next) {
            void *a = Ov011_FindActor(n->id);
            if (func_ov011_02201244(a)) {
                s32 y;
                Ov011Ent *e;
                if (func_ov011_02203028(self->unk_e0)->y > 0x6800) {
                    y = 0x6800;
                } else {
                    y = func_ov011_02203028(self->unk_e0)->y;
                    ok = FALSE;
                }
                Ov011Ent_SetY(self->ent, y);
                e = self->ent;
                if (Ov011Ent_Find(e, func_ov011_02201254(a)) != NULL) {
                    Ov011_Attach(Ov011Ent_Find(e, func_ov011_02201254(a)), owner, a);
                }
            }
        }
        if (ok && Ov011Ent_AllDone(self->ent)) {
            FLD(u64, self, 0x18) |= 8;
        }
        break;
    }
    }
}

}
