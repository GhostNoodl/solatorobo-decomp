#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

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

struct Ov011KeyVal {
    s32 key;
    s32 val;
};
extern const Ov011KeyVal data_ov011_02207380[];
void func_ov011_021fb8d4(void *a, s32 b, void *c, void *d);

void func_ov011_021fdfd8(Ov011Scene *self) {
    Ov011Node *n;
    switch (self->seq.state) {
    case 0: {
        u8 key = self->seq.unk_13;
        s32 v = -1;
        u32 i;
        for (i = 0; i < 2; i++) {
            s32 k = data_ov011_02207380[i].key;
            if (k == key) {
                v = data_ov011_02207380[i].val;
            }
        }
        func_ov011_021fb8d4(&self->mgr2, v, self, &self->ent);
        self->seq.state = 1;
        break;
    }
    case 1: {
        BOOL r = FALSE;
        if (self->mgr2.b0) {
            r = !self->mgr2.b1;
        }
        if (r) {
            self->seq.state = 2;
            self->b2 = 1;
        }
        break;
    }
    case 2:
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
        break;
    }
}

}
