#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

static inline void Ov011Ent_Lerp2(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->radius;
    if (e->active) {
        e->radiusLerp = 1;
        Ov011_SetLerp(&e->radius, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp3(Ov011Ent *e, s32 to, s32 frames) {
    u16 c = e->spin;
    if (e->active) {
        e->spinLerp = 1;
        Ov011_SetLerp(&e->spin, c, to, frames);
    }
}

static inline void Ov011Ent_Lerp4(Ov011Ent *e, s32 to, s32 frames) {
    s32 c = e->height;
    if (e->active) {
        e->heightLerp = 1;
        Ov011_SetLerp(&e->height, c, to, frames);
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

extern "C" {


u32 func_ov011_02201244(void *self);
void *func_ov011_02201254(void *self);


#pragma force_active on
void func_ov011_021fe1d4(Ov011Scene *self) {
    Ov011Node *n;
    switch (self->seq.state) {
    case 0:
        if (self->s1b4.b0) {
            Ov011Obj *o = self->actor;
            self->s1b4.b1 = 1;
            self->s1b4.id = o->id;
            self->s1b4.scene = self;
            self->s1b4.ent = &self->ent;
            func_ov000_02198360(&self->s1b4.seq, 2, 0);
        }
        self->seq.state = 1;
        break;
    case 1: {
        BOOL r = FALSE;
        if (self->s1b4.b0) {
            r = !self->s1b4.b1;
        }
        if (r) {
            self->seq.state = 2;
            self->b2 = 1;
        }
        break;
    }
    }
    for (n = self->head; n != NULL; n = n->next) {
        Ov011Obj *a = Ov011_FindActor(n->id);
        if (func_ov011_02201244(a)) {
            Ov011Obj *owner = self->actor;
            if (Ov011Ent_Find(&self->ent, func_ov011_02201254(a)) != NULL) {
                Ov011PNode *p = Ov011Ent_Find(&self->ent, func_ov011_02201254(a));
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
}
#pragma force_active reset
}
