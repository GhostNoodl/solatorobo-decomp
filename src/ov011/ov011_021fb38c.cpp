#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

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

static inline void Ov011Ent_LerpD(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->active) {
        e->heightLerp = 1;
        e->heightTo = to;
        e->height = from;
        e->heightStep = (e->heightTo - e->height) / frames;
    }
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

static inline Ov011PNode *Ov011Ent_Find2(Ov011Ent *e, void *k) {
    Ov011PNode *n;
    Ov011PNode *r = NULL;
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

extern "C" {


void func_ov011_021fb38c(Ov011Mgr *self) {
    Ov011Node *n;
    Ov011Ent *e;
    Actor *owner = self->list->actor;
    if (self->state == 0) {
        Ov011Ent_LerpD(self->ent, 0x2000 + 0x4800, 0x2000, 40);
        Ov011Ent_LerpB(self->ent, 0x3800 - 0x3333, 0x3333, 40);
        Ov011Ent_LerpC(self->ent, 0x71c, 0x71c, 40);
        self->state++;
        return;
    }
    for (n = self->list->head; n != NULL; n = n->next) {
        Ov011Npc *a = Ov011_FindNpc(n->id);
        if (func_ov011_02201244(a)) {
            e = self->ent;
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
    if (Ov011Ent_AllDone(self->ent)) {
        self->flags |= 4;
    }
}
}
