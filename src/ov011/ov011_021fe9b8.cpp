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


struct Ov011KeyVal {
    s32 key;
    s32 val;
};
extern const Ov011KeyVal data_ov011_02207390[];

void func_ov011_021fe9b8(Ov011Scene *self) {
    Ov011Node *n;
    switch (self->seq.st) {
    case 0: {
        u8 key = self->seq.current;
        s32 v = -1;
        u32 i;
        for (i = 0; i < 2; i++) {
            s32 k = data_ov011_02207390[i].key;
            if (k == key) {
                v = data_ov011_02207390[i].val;
            }
        }
        if (self->mgr.b0) {
            self->mgr.b1 = 1;
            self->mgr.unk_04 = v;
            self->mgr.list = self;
            self->mgr.ent = &self->ent;
            Ov003ActorSub40_ForceState(&self->mgr.state, 1);
        }
        self->seq.st = 1;
        break;
    }
    case 1: {
        BOOL r = FALSE;
        if (self->mgr.b0) {
            r = !self->mgr.b1;
        }
        if (r) {
            self->seq.st = 2;
            self->b2 = 1;
        }
        break;
    }
    case 2:
        for (n = self->head; n != NULL; n = n->next) {
            Ov011Npc *a = Ov011_FindNpc(n->id);
            if (Ov011Npc_IsTracking(a)) {
                Actor *owner = self->actor;
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
