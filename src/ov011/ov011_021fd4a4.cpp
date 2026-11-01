#include "ov011/ov011.h"

extern "C" {

struct Ov011Fd4a4 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad0 : 6;
    u8 pad1;
    u16 id;
    u32 pad4;
    s32 unk_08;
    u8 sub[1];
};

#pragma force_active on
void func_ov011_021fd4a4(Ov011Fd4a4 *self) {
    self->b1 = 0;
    self->id = 0xffff;
    self->unk_08 = 0;
    func_ov003_021da48c(self->sub, 1);
}
#pragma force_active reset

struct Ov011Fd4d8Bits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

extern BOOL func_ov000_02198360(void *p, u8 value, BOOL force);
extern BOOL func_ov011_02201578(void *p);
extern BOOL func_ov011_021fa720(void *e, s32 a, s32 b, s32 c, s32 d);

#define BITS4d8(off) FLD(Ov011Fd4d8Bits, self, off)

BOOL func_ov011_021fd4d8(u8 *self, s32 a) {
    BITS4d8(0).b0 = 1;
    BITS4d8(0).b1 = 0;
    BITS4d8(0).b2 = 1;
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = a;
    FLD(s32, self, 0xc) = 0;
    func_ov003_021da48c(self + 0x20, 1);
    BITS4d8(0x10).b0 = 1;
    FLD(u16, self, 0x12) = 0;
    FLD(u16, self, 0x14) = 0x10;
    FLD(void *, self, 0x18) = func_0203dddc(FLD(u16, self, 0x14) * 4);
    FLD(s32, self, 0x1c) = 0;
    func_ov011_02201578(self + 0x34);
    BITS4d8(0xb4).b0 = 1;
    BITS4d8(0xb4).b1 = 0;
    FLD(u16, self, 0xb6) = 0;
    FLD(s32, self, 0xb8) = -1;
    FLD(s32, self, 0xbc) = 0;
    FLD(s32, self, 0xc0) = 0;
    FLD(s32, self, 0xc4) = 0;
    func_ov003_021da48c(self + 0xc8, 0);
    BITS4d8(0x1b4).b0 = 1;
    BITS4d8(0x1b4).b1 = 0;
    FLD(u16, self, 0x1b6) = 0;
    FLD(s32, self, 0x1b8) = 0;
    FLD(s32, self, 0x1bc) = 0;
    func_ov000_02198360(self + 0x1c0, 2, 0);
    FLD(s32, self, 0x1d8) = -1;
    BITS4d8(0x1d4).b0 = 1;
    FLD(s32, self, 0x1dc) = 0;
    FLD(s32, self, 0x1e0) = 0;
    FLD(u16, self, 0x1d6) = 0;
    BITS4d8(0x1d4).b1 = 0;
    FLD(s32, self, 0x1e4) = 0;
    FLD(s32, self, 0x1e8) = 0;
    FLD(s32, self, 0x1ec) = 0;
    func_ov003_021da48c(self + 0x1f0, 0);
    func_ov011_021fa720(self + 0x204, 1, 0x3333, 0x71c, 0x2000);
    return TRUE;
}

}

#ifdef NONMATCHING
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

class Ov011Sub1b4 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01[0xb];
    u8 timer[0x13];
    u8 key;
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

void func_ov011_021fdb28(u8 *self);
BOOL func_ov003_021d7814(void *p);
void func_ov003_021d7800(void *p);
void *func_ov011_02201254(void *self);
void func_ov011_02201214(void *self, void *a);
Ov011PNode *func_ov011_021fa790(Ov011PNode *head, Ov011PNode *item);
void func_0203de1c(void *p);
Ov011Node *func_ov011_021fdadc(Ov011Node *head, Ov011Node *n);
void func_ov011_02201758(void *p);
void func_ov011_021fb684(void *p);
void func_ov011_021fa8c8(void *p);
void func_ov003_021d9cd0(Ov011Vec *out, const Ov011Vec *in, s32 angle);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);

static inline void Ov011Ent_Remove(Ov011Ent *e, void *k) {
    Ov011PNode *n;
    if (e->b0) {
        for (n = e->unk_04; n != NULL; n = n->next) {
            if (k == n) {
                e->unk_04 = func_ov011_021fa790(e->unk_04, n);
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

static inline void Ov011Sub1b4_Update(Ov011Sub1b4 *s) {
    u32 i;
    u8 key;
    if (!s->b0) {
        return;
    }
    if (!s->b1) {
        return;
    }
    key = s->key;
    for (i = 0; i < 5; i++) {
        if (key == data_ov011_02207308[i].key && *(s32 *)&data_ov011_02207308[i].fn != 0) {
            (s->*data_ov011_02207308[i].fn)();
            break;
        }
    }
    func_ov003_021da40c(s->timer);
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


#define E FLD(Ov011Ent, self, 0x204)

void func_ov011_021fd638(u8 *self) {
    Ov011Node *next;
    Ov011Node *n;
    if (!FLD(Ov011Top, self, 0).b0) {
        return;
    }
    func_ov011_021fdb28(self);
    n = FLD(Ov011Node *, self, 0xc);
    while (n != NULL) {
        next = n->next;
        if (!func_ov003_021d7814(n)) {
            void *a = Ov011_FindActor(n->id);
            if (a != NULL) {
                Ov011Ent_Remove(&FLD(Ov011Ent, self, 0x204), func_ov011_02201254(a));
                func_ov011_02201214(a, NULL);
            }
            FLD(Ov011Node *, self, 0xc) = func_ov011_021fdadc(FLD(Ov011Node *, self, 0xc), n);
            func_ov003_021d7800(n);
        }
        n = next;
    }
    {
        u32 i;
        u8 key = FLD(u8, self, 0x33);
        for (i = 0; i < 10; i++) {
            if (key == data_ov011_022073a0[i].key && *(s32 *)&data_ov011_022073a0[i].fn != 0) {
                (((Ov011Top *)self)->*data_ov011_022073a0[i].fn)();
                break;
            }
        }
    }
    func_ov011_02201758(self + 0x34);
    func_ov011_021fb684(self + 0xb4);
    Ov011Sub1b4_Update((Ov011Sub1b4 *)(self + 0x1b4));
    func_ov011_021fa8c8(self + 0x1d4);
    {

    s32 d;
    s32 st;
    if (!E.b0) {
        return;
    }
    if (E.b3) {
        E.unk_18 += FLD(s32, &E, 0x20);
        st = FLD(s32, &E, 0x20);
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
            func_ov003_021d9cd0(&v, &data_ov011_02207284, ang);
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
    FLD(u16, self, 0x234) += (u16)FLD(s32, self, 0x21c);
    }
}

}
#undef E
#endif
