#include "ov011/ov011.h"

extern "C" {

#pragma force_active on
void func_ov011_021fd4a4(Ov011Sub1b4 *self) {
    self->b1 = 0;
    self->id = 0xffff;
    self->ent = NULL;
    func_ov003_021da48c(&self->seq, 1);
}
#pragma force_active reset

extern BOOL func_ov000_02198360(void *p, u8 value, BOOL force);
extern BOOL func_ov011_02201578(void *p);
extern BOOL func_ov011_021fa720(void *e, s32 a, s32 b, s32 c, s32 d);

BOOL func_ov011_021fd4d8(Ov011Scene *self, Ov011Obj *owner) {
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 1;
    self->unk_04 = 0;
    self->actor = owner;
    self->head = NULL;
    func_ov003_021da48c(&self->seq, 1);
    self->ring.b0 = 1;
    self->ring.idx = 0;
    self->ring.cap = 0x10;
    self->ring.buf = (s32 *)Heap_AllocArray(self->ring.cap * 4);
    self->ring.count = 0;
    func_ov011_02201578(&self->fx);
    self->mgr2.b0 = 1;
    self->mgr2.b1 = 0;
    self->mgr2.count = 0;
    self->mgr2.unk_04 = -1;
    self->mgr2.arr8 = NULL;
    self->mgr2.list = NULL;
    self->mgr2.ent = NULL;
    func_ov003_021da48c(&self->mgr2.state, 0);
    self->s1b4.b0 = 1;
    self->s1b4.b1 = 0;
    self->s1b4.id = 0;
    self->s1b4.scene = NULL;
    self->s1b4.ent = NULL;
    func_ov000_02198360(&self->s1b4.seq, 2, 0);
    self->mgr.unk_04 = -1;
    self->mgr.b0 = 1;
    self->mgr.arr8 = NULL;
    self->mgr.arrC = NULL;
    self->mgr.count = 0;
    self->mgr.b1 = 0;
    self->mgr.ids = NULL;
    self->mgr.list = NULL;
    self->mgr.unk_18 = NULL;
    func_ov003_021da48c(&self->mgr.state, 0);
    func_ov011_021fa720(&self->ent, 1, 0x3333, 0x71c, 0x2000);
    return TRUE;
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov011_021fd638 is 56 / 34 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the Ov011Ent_Remove zero is hoisted to the entry (move-constant-loads 82 -> 9),
// plus the ring loop's Ov011_FxMul temps and ang colouring. History: docs/MATCHING.md rounds bigM, hzR, cvZ, raF,
// hzA, svC, cvA (search for the address); the full list is docs/UNMATCHED.md.
// func_ov011_021fd638: 56 raw diffs (round raF's draft, landed by round hzA). Two problems, as in
// func_ov011_021fc0b8 (src/ov011/ov011_021fc0a0.cpp), which shares Ov011Ent_Remove:
// (1) the Remove zero (e->unk_08 = 0) is hoisted to the function entry, where the ROM builds it in the
// inner loop's preheader (mov r7, #0 after the guard); refusing the move-constant-loads step 82 -> 9
// in the compiler (rounds hzR/cvZ) leaves 22 / 0 masked. (2) the ring loop's Ov011_FxMul temps and the
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
extern const Ov011Vec data_ov011_02207284;

void func_ov011_021fdb28(Ov011Scene *self);
BOOL func_ov003_021d7814(void *p);
void func_ov003_021d7800(void *p);
void *func_ov011_02201254(void *self);
void func_ov011_02201214(void *self, void *a);
Ov011PNode *func_ov011_021fa790(Ov011PNode *head, Ov011PNode *item);
void Heap_Free(void *p);
Ov011Node *func_ov011_021fdadc(Ov011Node *head, Ov011Node *n);
void func_ov011_02201758(void *p);
void func_ov011_021fb684(void *p);
void func_ov011_021fa8c8(void *p);
void Ov003Vec_RotY(Ov011Vec *out, const Ov011Vec *in, s32 angle);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);

static inline void Ov011Ent_Remove(Ov011Ent *e, void *k) {
    Ov011PNode *n;
    if (e->b0) {
        for (n = e->unk_04; n != NULL; n = n->next) {
            if (k == n) {
                e->unk_04 = func_ov011_021fa790(e->unk_04, n);
                if (n != NULL) {
                    Heap_Free(n);
                }
                e->b1 = 0;
                e->unk_08 = 0;
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
    key = s->seq.unk_13;
    for (i = 0; i < 5; i++) {
        if (key == data_ov011_02207308[i].key && *(s32 *)&data_ov011_02207308[i].fn != 0) {
            (s->*data_ov011_02207308[i].fn)();
            break;
        }
    }
    func_ov003_021da40c(&s->seq);
}

static inline void Ov011_MoveTo(Ov011PNode *n, const Ov011Vec *v, s32 t) {
    Ov011Vec dv;
    dv.x = v->x - n->v.x;
    dv.y = v->y - n->v.y;
    dv.z = v->z - n->v.z;
    VEC_MultAdd(t, &dv, &n->v, &n->v);
}

static inline s32 Ov011Ent_Count(Ov011Ent *e) {
    s32 cnt = 0;
    Ov011PNode *n;
    if (e->b0) {
        for (n = e->unk_04; n != NULL; n = n->next) {
            cnt++;
        }
    }
    return cnt;
}


#define E (self->ent)

void func_ov011_021fd638(Ov011Scene *self) {
    Ov011Node *next;
    Ov011Node *n;
    if (!self->b0) {
        return;
    }
    func_ov011_021fdb28(self);
    n = self->head;
    while (n != NULL) {
        next = n->next;
        if (!func_ov003_021d7814(n)) {
            Ov011Obj *a = Ov011_FindActor(n->id);
            if (a != NULL) {
                Ov011Ent_Remove(&self->ent, func_ov011_02201254(a));
                func_ov011_02201214(a, NULL);
            }
            self->head = func_ov011_021fdadc(self->head, n);
            func_ov003_021d7800(n);
        }
        n = next;
    }
    {
        u32 i;
        u8 key = self->seq.unk_13;
        for (i = 0; i < 10; i++) {
            if (key == data_ov011_022073a0[i].key && *(s32 *)&data_ov011_022073a0[i].fn != 0) {
                (((Ov011Top *)self)->*data_ov011_022073a0[i].fn)();
                break;
            }
        }
    }
    func_ov011_02201758(&self->fx);
    func_ov011_021fb684(&self->mgr2);
    Ov011Sub1b4_Update(&self->s1b4);
    func_ov011_021fa8c8(&self->mgr);
    {

    s32 d;
    s32 st;
    if (!E.b0) {
        return;
    }
    if (E.b3) {
        E.unk_18 += E.unk_20;
        st = E.unk_20;
        d = E.unk_1c - E.unk_18;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.unk_18 = E.unk_1c;
            E.b3 = 0;
        }
    }
    if (E.b2) {
        E.unk_0c += E.unk_14;
        st = E.unk_14;
        d = E.unk_10 - E.unk_0c;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.unk_0c = E.unk_10;
            E.b2 = 0;
        }
    }
    if (E.b4) {
        E.unk_24 += E.unk_2c;
        st = E.unk_2c;
        d = E.unk_28 - E.unk_24;
        if ((d < 0 ? -d : d) <= (st < 0 ? -st : st)) {
            E.unk_24 = E.unk_28;
            E.b4 = 0;
        }
    }
    {
        s32 cnt = Ov011Ent_Count(&E);
        s32 i = 0;
        Ov011PNode *n;
        for (n = E.unk_04; n != NULL; n = n->next) {
            u16 ang = E.unk_30 + (u16)(i * (0xffff / cnt));
            s32 sc;
            s32 y = E.unk_24;
            sc = E.unk_0c;
            Ov011Vec v;
            if (E.unk_34 != 0) {
                if (E.unk_34 == 1) {
                    ang = 0xffff - ang;
                }
            }
            Ov003Vec_RotY(&v, &data_ov011_02207284, ang);
            v.x = Ov011_FxMul(v.x, sc);
            v.z = Ov011_FxMul(v.z, sc);
            v.y = y;
            i++;
            if (E.b1) {
                n->v = v;
            } else {
                Ov011_MoveTo(n, &v, E.unk_08);
            }
        }
    }
    {
        Ov011Ent *e = &E;
        if (!e->b1) {
            e->unk_08 += 0x29;
            if (e->unk_08 >= 0x1000) {
                e->b1 = 1;
                e->unk_08 = 0x1000;
            }
        }
    }
    self->ent.unk_30 += (u16)self->ent.unk_18;
    }
}

}
#undef E
#endif
