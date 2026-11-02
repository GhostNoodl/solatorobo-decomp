#include "ov011/ov011.h"

extern "C" {

#pragma force_active on
void Ov011Sub1b4_Reset(Ov011Sub1b4 *self) {
    self->b1 = 0;
    self->id = 0xffff;
    self->ent = NULL;
    Ov003ActorSub40_ForceState(&self->seq, 1);
}
#pragma force_active reset

extern BOOL Ov011Fx_Init(void *p);
extern BOOL Ov011Ent_Init(Ov011Ent *e, s32 a, s32 b, s32 c, s32 d);

BOOL Ov011Scene_Init(Ov011Scene *self, Actor *owner) {
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 1;
    self->unk_04 = 0;
    self->actor = owner;
    self->head = NULL;
    Ov003ActorSub40_ForceState(&self->seq, 1);
    self->ring.b0 = 1;
    self->ring.idx = 0;
    self->ring.cap = 0x10;
    self->ring.buf = (s32 *)Heap_AllocArray(self->ring.cap * 4);
    self->ring.count = 0;
    Ov011Fx_Init(&self->fx);
    self->mgr2.b0 = 1;
    self->mgr2.b1 = 0;
    self->mgr2.count = 0;
    self->mgr2.unk_04 = -1;
    self->mgr2.arr8 = NULL;
    self->mgr2.list = NULL;
    self->mgr2.ent = NULL;
    Ov003ActorSub40_ForceState(&self->mgr2.state, 0);
    self->s1b4.b0 = 1;
    self->s1b4.b1 = 0;
    self->s1b4.id = 0;
    self->s1b4.scene = NULL;
    self->s1b4.ent = NULL;
    History_SetState(&self->s1b4.seq, 2, 0);
    self->mgr.unk_04 = -1;
    self->mgr.b0 = 1;
    self->mgr.arr8 = NULL;
    self->mgr.arrC = NULL;
    self->mgr.count = 0;
    self->mgr.b1 = 0;
    self->mgr.ids = NULL;
    self->mgr.list = NULL;
    self->mgr.ent = NULL;
    Ov003ActorSub40_ForceState(&self->mgr.state, 0);
    Ov011Ent_Init(&self->ent, 1, 0x3333, 0x71c, 0x2000);
    return TRUE;
}

}

#ifdef NONMATCHING
// Status (round drA): Ov011Scene_Update is 56 / 34 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the Ov011Ent_Remove zero is hoisted to the entry (move-constant-loads 82 -> 9),
// plus the ring loop's FX_Mul temps and ang colouring. History: docs/MATCHING.md rounds bigM, hzR, cvZ, raF,
// hzA, svC, cvA (search for the address); the full list is docs/UNMATCHED.md.
// Ov011Scene_Update: 56 raw diffs (round raF's draft, landed by round hzA). Two problems, as in
// Ov011Ctl_Update (src/ov011/ov011_021fc0a0.cpp), which shares Ov011Ent_Remove:
// (1) the Remove zero (e->unk_08 = 0) is hoisted to the function entry, where the ROM builds it in the
// inner loop's preheader (mov r7, #0 after the guard); refusing the move-constant-loads step 82 -> 9
// in the compiler (rounds hzR/cvZ) leaves 22 / 0 masked. (2) the ring loop's FX_Mul temps and the
// ang value are coloured differently (round bigM). See docs/MATCHING.md.
class Ov011Top {
public:
    u8 b0 : 1;
    u8 b1 : 7;
};

typedef void (Ov011Top::*Ov011TopFn)();
typedef void (Ov011Sub1b4::*Ov011Sub1b4Fn)();

struct Ov011TopEntry {
    s32 key;
    Ov011TopFn fn;
};

struct Ov011Sub1b4Entry {
    s32 key;
    Ov011Sub1b4Fn fn;
};

extern "C" {

extern const Ov011TopEntry data_ov011_022073a0[];
extern const Ov011Sub1b4Entry data_ov011_02207308[];
extern const VecFx32 data_ov011_02207284;

void Ov011Scene_SelectState(Ov011Scene *self);
BOOL Ov003_ActorExists(void *p);
void Ov003_FreeIfSet(void *p);
Ov011PNode *Ov011LNode_Remove(Ov011PNode *head, Ov011PNode *item);
Ov011Node *Ov011Link_Remove(Ov011Node *head, Ov011Node *n);
void Ov011Fx_Update(void *p);
void Ov011Mgr2_Update(void *p);
void Ov011Mgr_Update(void *p);
void Ov003Vec_RotY(VecFx32 *out, const VecFx32 *in, s32 angle);

static inline void Ov011Ent_Remove(Ov011Ent *e, void *k) {
    Ov011PNode *n;
    if (e->active) {
        for (n = e->nodes; n != NULL; n = n->next) {
            if (k == n) {
                e->nodes = Ov011LNode_Remove(e->nodes, n);
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

static inline void Ov011Sub1b4_Update(Ov011Sub1b4 *s) {
    u32 i;
    u8 key;
    if (!s->b0) {
        return;
    }
    if (!s->b1) {
        return;
    }
    key = s->seq.current;
    for (i = 0; i < 5; i++) {
        if (key == data_ov011_02207308[i].key && *(s32 *)&data_ov011_02207308[i].fn != 0) {
            (s->*data_ov011_02207308[i].fn)();
            break;
        }
    }
    Ov003ActorSub40_ApplyFlags(&s->seq);
}

static inline void Ov011_MoveTo(Ov011PNode *n, const VecFx32 *v, s32 t) {
    VecFx32 dv;
    dv.x = v->x - n->v.x;
    dv.y = v->y - n->v.y;
    dv.z = v->z - n->v.z;
    VEC_MultAdd(t, &dv, &n->v, &n->v);
}

static inline s32 Ov011Ent_Count(Ov011Ent *e) {
    s32 cnt = 0;
    Ov011PNode *n;
    if (e->active) {
        for (n = e->nodes; n != NULL; n = n->next) {
            cnt++;
        }
    }
    return cnt;
}


#define E (self->ent)

void Ov011Scene_Update(Ov011Scene *self) {
    Ov011Node *next;
    Ov011Node *n;
    if (!self->b0) {
        return;
    }
    Ov011Scene_SelectState(self);
    n = self->head;
    while (n != NULL) {
        next = n->next;
        if (!Ov003_ActorExists(n)) {
            Ov011Npc *a = Ov011_FindNpc(n->id);
            if (a != NULL) {
                Ov011Ent_Remove(&self->ent, func_ov011_02201254(a));
                func_ov011_02201214(a, NULL);
            }
            self->head = Ov011Link_Remove(self->head, n);
            Ov003_FreeIfSet(n);
        }
        n = next;
    }
    {
        u32 i;
        u8 key = self->seq.current;
        for (i = 0; i < 10; i++) {
            if (key == data_ov011_022073a0[i].key && *(s32 *)&data_ov011_022073a0[i].fn != 0) {
                (((Ov011Top *)self)->*data_ov011_022073a0[i].fn)();
                break;
            }
        }
    }
    Ov011Fx_Update(&self->fx);
    Ov011Mgr2_Update(&self->mgr2);
    Ov011Sub1b4_Update(&self->s1b4);
    Ov011Mgr_Update(&self->mgr);
    {

    s32 d;
    s32 st;
    if (!E.active) {
        return;
    }
    if (E.spinLerp) {
        E.spin += E.spinStep;
        st = E.spinStep;
        d = E.spinTo - E.spin;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.spin = E.spinTo;
            E.spinLerp = 0;
        }
    }
    if (E.radiusLerp) {
        E.radius += E.radiusStep;
        st = E.radiusStep;
        d = E.radiusTo - E.radius;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.radius = E.radiusTo;
            E.radiusLerp = 0;
        }
    }
    if (E.heightLerp) {
        E.height += E.heightStep;
        st = E.heightStep;
        d = E.heightTo - E.height;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.height = E.heightTo;
            E.heightLerp = 0;
        }
    }
    {
        s32 cnt = Ov011Ent_Count(&E);
        s32 i = 0;
        Ov011PNode *n;
        for (n = E.nodes; n != NULL; n = n->next) {
            u16 ang = E.angle + (u16)(i * (0xffff / cnt));
            s32 sc;
            s32 y = E.height;
            sc = E.radius;
            VecFx32 v;
            if (E.dir != 0) {
                if (E.dir == 1) {
                    ang = 0xffff - ang;
                }
            }
            Ov003Vec_RotY(&v, &data_ov011_02207284, ang);
            v.x = FX_Mul(v.x, sc);
            v.z = FX_Mul(v.z, sc);
            v.y = y;
            i++;
            if (E.settled) {
                n->v = v;
            } else {
                Ov011_MoveTo(n, &v, E.blend);
            }
        }
    }
    {
        Ov011Ent *e = &E;
        if (!e->settled) {
            e->blend += 0x29;
            if (e->blend >= 0x1000) {
                e->settled = 1;
                e->blend = 0x1000;
            }
        }
    }
    self->ent.angle += (u16)self->ent.spin;
    }
}

}
#undef E
#endif
