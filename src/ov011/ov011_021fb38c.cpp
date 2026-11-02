#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

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

static inline void Ov011Ent_LerpD(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b4 = 1;
        e->unk_28 = to;
        e->unk_24 = from;
        e->unk_2c = (e->unk_28 - e->unk_24) / frames;
    }
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

static inline Ov011PNode *Ov011Ent_Find2(Ov011Ent *e, void *k) {
    Ov011PNode *n;
    Ov011PNode *r = NULL;
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

extern "C" {

u32 func_ov011_02201244(void *self);
void *func_ov011_02201254(void *self);

void func_ov011_021fb38c(Ov011Mgr *self) {
    Ov011Node *n;
    Ov011Ent *e;
    Ov011Obj *owner = self->list->actor;
    if (self->state == 0) {
        Ov011Ent_LerpD(self->unk_18, 0x2000 + 0x4800, 0x2000, 40);
        Ov011Ent_LerpB(self->unk_18, 0x3800 - 0x3333, 0x3333, 40);
        Ov011Ent_LerpC(self->unk_18, 0x71c, 0x71c, 40);
        self->state++;
        return;
    }
    for (n = self->list->head; n != NULL; n = n->next) {
        Ov011Obj *a = Ov011_FindActor(n->id);
        if (func_ov011_02201244(a)) {
            e = self->unk_18;
            if (Ov011Ent_Find(e, func_ov011_02201254(a)) != NULL) {
                Ov011PNode *p = Ov011Ent_Find2(e, func_ov011_02201254(a));
                VecFx32 r;
                VecFx32 o;
                VecFx32 v;
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
        }
    }
    if (Ov011Ent_AllDone(self->unk_18)) {
        self->flags |= 4;
    }
}
}
