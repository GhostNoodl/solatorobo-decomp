#include "ov011/ov011.h"



typedef void (Ov011Mgr2::*Ov011Mgr2Fn)();

struct Ov011Mgr2Entry {
    s32 key;
    Ov011Mgr2Fn fn;
};

static inline s32 Ov011Ent_GetA(Ov011Ent *e) {
    if (e->active) {
        return e->height;
    }
    return 0;
}

static inline s32 Ov011Ent_GetRadius(Ov011Ent *e) {
    if (e->active) {
        return e->radius;
    }
    return 0;
}

static inline u16 Ov011Ent_GetC(Ov011Ent *e) {
    if (e->active) {
        return e->spin;
    }
    return 0;
}

static inline void Ov011Ent_LerpA(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->active) {
        e->heightLerp = 1;
        Ov011_SetLerp(&e->height, from, to, frames);
    }
}

static inline void Ov011Ent_LerpB(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->active) {
        e->radiusLerp = 1;
        Ov011_SetLerp(&e->radius, from, to, frames);
    }
}

static inline void Ov011Ent_LerpC(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->active) {
        e->spinLerp = 1;
        Ov011_SetLerp(&e->spin, from, to, frames);
    }
}

static inline void Ov011Ent_RestoreA(Ov011Ent *e, s32 to, s32 frames) {
    if (e->active) {
        Ov011Ent_LerpA(e, e->height, to, frames);
    }
}

static inline void Ov011Ent_RestoreB(Ov011Ent *e, s32 to, s32 frames) {
    if (e->active) {
        Ov011Ent_LerpB(e, e->radius, to, frames);
    }
}

static inline void Ov011Ent_RestoreC(Ov011Ent *e, s32 to, s32 frames) {
    if (e->active) {
        Ov011Ent_LerpC(e, (u16)e->spin, to, frames);
    }
}

extern "C" {

extern const Ov011Mgr2Entry data_ov011_022072d8[];
void *Ov003Vt_021f7d2c_Dtor(void *p);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void Ov011Chr_Reset_0220205c(void *p);
void Ov011Chr_Update(void *p);
void Ov011Mov_Stop_02202fbc(void *p);
void Ov011Mov_Update(void *p);

void *Ov011E40_Dtor(Ov011E40 *self) {
    Ov003Vt_021f7d2c_Dtor(&self->mover);
    return self;
}

static inline void Ov011Mgr2_Reset(Ov011Mgr2 *self) {
    void *saved;
    self->b1 = 0;
    self->count = 0;
    self->unk_04 = -1;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x40, 8, Ov011E40_Dtor);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov003ActorSub40_ForceState(&self->state, 0);
    Ov011Chr_Reset_0220205c(self->unk_28);
    Ov011Mov_Stop_02202fbc(&self->mov);
}

void Ov011Mgr2_Update(Ov011Mgr2 *self) {
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
    Ov003ActorSub40_ApplyFlags(&self->state);
    Ov011Chr_Update(self->unk_28);
    Ov011Mov_Update(&self->mov);
    for (j = 0; j < self->count; j++) {
        Ov011E40 *p = &self->arr8[j];
        if (p->b0) {
            p->unk_04++;
        }
        p->mover.v0c();
    }
}

void Ov011Mgr2_Start(Ov011Mgr2 *self, s32 a, Ov011List *list, Ov011Ent *ent) {
    if (!self->b0) {
        return;
    }
    self->b1 = 1;
    self->unk_04 = a;
    self->list = list;
    self->ent = ent;
    if (a == 0) {
        Ov003ActorSub40_ForceState(&self->state, 3);
    } else if (a == 1) {
        Ov003ActorSub40_ForceState(&self->state, 2);
    }
}

void func_ov011_021fb92c(Ov011Mgr2 *self) {
    Ov011Mgr2_Reset(self);
}


static inline BOOL Ov011Ent_Done4(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->active) {
        r = !e->heightLerp;
    }
    return r;
}

static inline BOOL Ov011Ent_Done2(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->active) {
        r = !e->radiusLerp;
    }
    return r;
}

static inline BOOL Ov011Ent_Done3(Ov011Ent *e) {
    BOOL r = FALSE;
    if (e->active) {
        r = !e->spinLerp;
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
    if (e->active) {
        for (n = e->nodes; n != NULL; n = n->next) {
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
    if (e->active) {
        e->heightLerp = 0;
        e->height = y;
        for (n = e->nodes; n != NULL; n = n->next) {
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

void ActorMgr_SendMsg(u16 a, u16 b, u8 c, BOOL d, u32 e, const void *f);
extern const VecFx32 data_ov011_0220729c;
extern const VecFx32 data_ov011_022072a8;

static inline void Ov011_SendB(u16 id, s32 kind, s16 x, s16 y) {
    Ov011ArgB b;
    b.kind = kind;
    b.b0 = 0;
    b.b1 = 0;
    b.x = x;
    b.y = y;
    ActorMgr_SendMsg(id, 0xffff, 0xe, 1, 0xc, &b);
}

static inline void Ov011Ent_Lerp2(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->radius;
    if (e->active) {
        e->radiusLerp = 1;
        Ov011_SetLerp(&e->radius, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp2X(Ov011Ent *e, s32 frames) {
    s32 c = e->radius;
    if (e->active) {
        s32 to;
        e->radiusLerp = 1;
        to = 0x4cd;
        (&e->radius)[1] = to;
        (&e->radius)[0] = c;
        (&e->radius)[2] = ((&e->radius)[1] - (&e->radius)[0]) / frames;
    }
}

static inline void Ov011Ent_RestoreB2(Ov011Ent *e, s32 to, s32 frames) {
    if (e->active) {
        Ov011Ent_Lerp2(e, to, frames);
    }
}

static inline void Ov011_Attach(Ov011PNode *p, Actor *owner, Actor *a) {
    VecFx32 v;
    VecFx32 o;
    VecFx32 r;
    v.x = p->v.x;
    v.y = p->v.y;
    v.z = p->v.z;
    o.x = owner->pos.x;
    o.y = owner->pos.y;
    o.z = owner->pos.z;
    VEC_Add(&v, &o, &r);
    a->pos.x = r.x;
    a->pos.y = r.y;
    a->pos.z = r.z;
}

void func_ov011_021fb9b8(Ov011Mgr2 *self, Actor *owner) {
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
            if (Ov011Npc_IsTracking(Ov011_FindNpc(n->id))) {
                any = TRUE;
            }
        }
        if (!any) {
            Ov011Mgr2_Reset(self);
            self->b1 = 0;
        }
        {
            VecFx32 a = data_ov011_0220729c;
            VecFx32 b = data_ov011_022072a8;
            Ov011Mov_Stop_02202fbc(&self->mov);
            Ov011Mov_Start(&self->mov, &a, &b, 0x500, 0x80);
        }
        if (self->ent->active) {
            Ov011Ent_Lerp2X(self->ent, 0x2d);
        }
        Ov011_SendB(owner->id, 2, 0x1000, 0x1000);
        self->state = 1;
    }
    case 1: {
        ok = TRUE;
        for (n = head; n != NULL; n = n->next) {
            Ov011Npc *a = Ov011_FindNpc(n->id);
            if (Ov011Npc_IsTracking(a)) {
                s32 y;
                Ov011Ent *e;
                if (Ov011Mov_GetPos(&self->mov)->y > 0x6800) {
                    y = 0x6800;
                } else {
                    y = Ov011Mov_GetPos(&self->mov)->y;
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
            self->flags |= 8;
        }
        break;
    }
    }
}

}
