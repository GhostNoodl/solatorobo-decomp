#include "ov011/ov011.h"

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011Small6 {
    Ov011Bit01 f;
    u8 pad;
    u16 a;
    u16 b;
};

struct Ov011Small4 {
    Ov011Bit01 f;
    u8 pad;
    u16 a;
};

extern "C" {

extern u8 data_ov011_0220726e[];
void func_ov003_021d112c(void *self);
void func_ov000_02198328(void *p);
void func_ov011_02201510(void *p);
void func_ov011_02201c18(void *p);
void func_ov011_02202edc(void *p);
void func_ov011_02202c54(void *p);
BOOL func_ov011_021fd4d8(void *p, void *owner);
BOOL func_020621c4(void);
void func_ov003_021d6bac(void *p, void *data);

void func_ov011_021fef00(Ov011Actor *self) {
    u8 *p;
    u8 *q;
    func_ov003_021d112c(self);
    p = (u8 *)func_0203dd9c(0x23c);
    if (p != NULL) {
        FLD(Ov011Bit01, p, 0x10).b0 = 0;
        func_ov000_02198328(p + 0x20);
        func_ov011_02201510(p + 0x34);
        func_ov000_02198328(p + 0xc8);
        func_ov011_02201c18(p + 0xdc);
        func_ov011_02202edc(p + 0x194);
        FLD(Ov011Bit01, p, 0xb4).b0 = 0;
        func_ov000_02198328(p + 0x1c0);
        FLD(Ov011Bit01, p, 0x1b4).b0 = 0;
        func_ov000_02198328(p + 0x1f0);
        FLD(Ov011Bit01, p, 0x1d4).b0 = 0;
        FLD(Ov011Bit01, p, 0x204).b0 = 0;
        FLD(Ov011Bit01, p, 0).b0 = 0;
    }
    FLD(u8 *, self, 0x100) = p;
    func_ov011_021fd4d8(p, self);
    q = (u8 *)func_0203dd9c(0x3c);
    if (q != NULL) {
        func_ov000_02198328(q);
        func_ov011_02202c54(q + 0x14);
    }
    FLD(u8 *, self, 0x104) = q;
    FLD(void *, self, 0x108) = func_0203dd9c(6);
    FLD(void *, self, 0x10c) = func_0203dd9c(4);
    {
        u8 *s = FLD(u8 *, self, 0x104);
        func_ov003_021da48c(s, 0);
        FLD(s32, s, 0x38) = 0;
    }
    {
        Ov011Small6 *s = FLD(Ov011Small6 *, self, 0x108);
        s->f.b0 = 0;
        s->f.b1 = 0;
        s->a = 0x1000;
        s->b = 0x1000;
    }
    {
        Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
        s->f.b0 = 0;
        s->f.b1 = 0;
        s->f.b2 = 1;
        s->a = 0;
    }
    self->unk_48->unk_30 = 0x60000000;
    self->unk_90 = FLD(u16, func_ov000_0219bf90(), 0xc);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov011_0220726e);
    }
    FLD(u8, self, 0x15) = 2;
}

extern void *data_02097e4c;
extern const char *const data_ov011_02207258[];
extern void func_0204a028(void *a, s32 b, Ov011Vec *c, s32 d);
extern void func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov003_021d1c00(Ov011Actor *self, u8 *msg);

BOOL func_ov011_021ff084(Ov011Actor *self, u8 *msg) {
    if (msg[5] == 0xe) {
        switch (FLD(s32, msg, 0x8)) {
        case 1: {
            Ov011Sub40 *st;
            s32 sub = FLD(s32, msg, 0xc);
            if (sub == 0) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 0) {
                    st->flags |= 2;
                    func_0204a028(data_02097e4c, 9, &self->pos, -2);
                }
            } else if (sub == 1) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 1) {
                    st->flags |= 4;
                    func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
                }
            } else if (sub == 2) {
                st = FLD(Ov011Sub40 *, self, 0x104);
                if (st->unk_13 == 2) {
                    st->flags |= 8;
                }
            }
            break;
        }
        case 2: {
            u8 *p = FLD(u8 *, self, 0x108);
            if (p != NULL) {
                FLD(u8, p, 0) = msg[0xc];
                FLD(s16, p, 2) = FLD(s16, msg, 0xe);
                FLD(s16, p, 4) = FLD(s16, msg, 0x10);
            }
            break;
        }
        case 3:
            if (msg[0xc] != 0) {
                Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
                s->f.b0 = 1;
                s->f.b1 = 1;
                s->f.b2 = 1;
                s->a = 0;
            } else {
                Ov011Small4 *s = FLD(Ov011Small4 *, self, 0x10c);
                s->f.b0 = 0;
                s->f.b1 = 0;
                s->f.b2 = 0;
                s->a = 0;
                func_ov000_02190cb0(self->unk_38, data_ov011_02207258[0], 0x1000, 0);
                func_ov000_021915a0(self->unk_38);
            }
            break;
        }
        self->unk_30 |= 1 << msg[5];
        msg[5] = 0;
        return TRUE;
    }
    return func_ov003_021d1c00(self, msg);
}

}

#ifdef NONMATCHING
// func_ov011_021ff24c: 61 / 4 here (raw / aligned register-masked, round qpJ; 114 / 4 in round ovreg, ovreg/f24c/c.cpp).
// The read-only list and ring accessors take const pointers (F24c_Count, F24c_Active, F24c_CountBusy, the ring
// readers and a new F24c_GetRing), so their b0 tests are const reads, and the final `F24c_SetState(..., 5)` reloads
// self->unk_100 instead of reusing `l`. Then SetState's plain b0 read is not CSE'd with Count's const read across
// the count loop (jkF/jkG), the flag byte is re-read as in the ROM, `l` is not live across the search loop, and
// the &data_ov000_021ccd68 pool load is hoisted into fp. All three are needed: a non-const Count, a plain
// GetRing read or `F24c_SetState(l, 5)` gives 360+ / 53+. Left: register colouring only (the ring loop's
// r6/r7/r8/sb/fp rotation and the two busy-count walks). `cnt` declared before `nd` gives 56 (68 after).
// In this TU data_ov011_02207258 is declared `const` (it is .rodata), so the last three copies are loaded
// before their stores (the 4 masked); with a non-const `extern u8 data_ov011_02207258[]` outside this TU the
// draft is 56 / 0. A const pointer or a vector copy of the +0x20 words does not change it (jkF's 021fff38).
struct F24cRing {
    Ov011Bit01 f;
    u8 pad;
    u16 head;
    u16 cap;
    u16 pad2;
    s32 *data;
    u32 count;
};

struct F24cList {
    Ov011Bit01 f;
    u8 pad[3];
    s32 state;
    u8 pad8[4];
    Ov011Node *head;
    F24cRing ring;
};

extern "C" {

BOOL func_ov003_021da03c(void *self);
u32 func_ov011_02201244(void *self);
void func_ov011_021fff38(void *self);
void func_ov011_0220023c(void *self);
void func_ov011_02200310(void *self);
void func_ov011_02202a38(void);
void func_ov011_021fd638(void *p);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *c);

static inline u32 F24c_Active(const F24cList *l) {
    u32 r = 0;
    if (l->f.b0) {
        r = l->f.b2;
    }
    return r;
}

static inline void F24c_SetState(F24cList *l, s32 st) {
    if (l->f.b0 && l->f.b2) {
        l->state = st;
        l->f.b2 = 0;
    }
}

static inline u32 F24c_Count(const F24cList *l) {
    u32 n = 0;
    if (l->f.b0) {
        Ov011Node *nd;
        for (nd = l->head; nd != NULL; nd = nd->next) {
            n++;
        }
    }
    return n;
}

static inline u32 F24c_RingCount(const F24cRing *r) {
    u32 n = 0;
    if (r->f.b0) {
        n = r->count;
    }
    return n;
}

static inline u16 F24c_RingCap(const F24cRing *r) {
    u16 c = 0;
    BOOL e = !r->f.b0;
    if (!e) {
        c = r->cap;
    }
    return c;
}

static inline u16 F24c_Idx(F24cRing *r, u16 k) {
    if (r->head < k) {
        return r->cap + (r->head - k);
    }
    return r->head - k;
}
static inline const s32 *F24c_RingAt(const F24cRing *r, u16 i) {
    u16 k = i;
    const s32 *p = NULL;
    if (r->f.b0 && r->count > i) {
        u16 head = r->head;
        u16 pos;
        if (i >= r->cap) {
            k = r->cap - 1;
        }
        if (head < k) {
            pos = r->cap + (head - k);
        } else {
            pos = head - k;
        }
        p = &r->data[pos];
    }
    return p;
}

static inline BOOL F24c_Valid(void *a) {
    void *pl;
    if (a == NULL) {
        return FALSE;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return FALSE;
    }
    if (FLD(u16, pl, 0xb1c) == FLD(u16, a, 0xc)) {
        return FALSE;
    }
    if (!(FLD(u32, FLD(void *, a, 0x48), 0x50) & 0x20000000)) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL F24c_NodeBusy(Ov011Node *nd) {
    void *a;
    if (nd != NULL && (a = Ov011_FindActor(nd->id)) != NULL && func_ov011_02201244(a)) {
        return TRUE;
    }
    return FALSE;
}

static inline u32 F24c_CountBusy(const F24cList *l) {
    u32 n = 0;
    if (l->f.b0) {
        Ov011Node *nd;
        for (nd = l->head; nd != NULL; nd = nd->next) {
            if (F24c_NodeBusy(nd)) {
                n++;
            }
        }
    }
    return n;
}

static inline const F24cRing *F24c_GetRing(const F24cList *l) {
    const F24cRing *r = NULL;
    if (l->f.b0) {
        r = &l->ring;
    }
    return r;
}

static inline BOOL F24c_Mode1(Ov011Actor *self) {
    BOOL r = FALSE;
    if (self->unk_40->unk_13 == 1) {
        r = TRUE;
    }
    return r;
}

static inline u32 F24c_RingSize(const F24cRing *r) {
    u32 c = F24c_RingCap(r);
    u32 n = F24c_RingCount(r);
    if (n <= c) {
        c = n;
    }
    return c;
}

static inline BOOL F24c_IsMove(s32 e) {
    if (e == 2) {
        return TRUE;
    }
    if (e == 3) {
        return TRUE;
    }
    return FALSE;
}

void func_ov011_021ff24c(Ov011Actor *self) {
    Ov011Vec v;
    if (!func_ov003_021da03c(self)) {
        FLD(u16, self, 0xb4) = 0;
        self->unk_b6 = 0;
        FLD(u16, self, 0xf2) = 0;
    } else {
        self->unk_93_4 = 1;
        self->unk_c4 = 0;
        BOOL ok = F24c_Mode1(self);
        if (ok) {
            ok = F24c_Active(FLD(F24cList *, self, 0x100));
        }
        if (ok) {
            F24cList *l = FLD(F24cList *, self, 0x100);
            const F24cRing *r;
            u16 lim;
            r = F24c_GetRing(l);
            lim = FLD(Ov011Bit01, self, 0xf0).b0 ? 0x78 : 0;
            if (F24c_Count(l) == 0) {
                self->unk_b6 = 0;
                FLD(Ov011Bit01, self, 0xf0).b0 = 0;
                FLD(u16, self, 0xf2) = 0;
                F24c_SetState(FLD(F24cList *, self, 0x100), 5);
                FLD(Ov011Bit01, self, 0xf0).b1 = 0;
            } else if (FLD(u16, self, 0xf2) >= lim) {
                u16 i;
                s16 found;
                s32 cnt = 0;
                Ov011Node *nd;
                for (i = 0; i < F24c_RingSize(r); i++) {
                    s32 e = *F24c_RingAt(r, i);
                    if (F24c_IsMove(e)) {
                        cnt++;
                    } else if (e == 4) {
                        break;
                    }
                }
                found = FALSE;
                FLD(Ov011Bit01, self, 0xf0).b0 = 0;
                FLD(u16, self, 0xf2) = 0;
                l = FLD(F24cList *, self, 0x100);
                if (l->f.b0) {
                    for (nd = l->head; nd != NULL; nd = nd->next) {
                        void *a = Ov011_FindActor(nd->id);
                        if (a != NULL && !func_ov011_02201244(a) && F24c_Valid(a)) {
                            found = TRUE;
                            break;
                        }
                    }
                }
                if (found) {
                    Ov011Small6 *s;
                    if (cnt == 0 || cnt >= 2) {
                        F24c_SetState(FLD(F24cList *, self, 0x100), 7);
                        FLD(Ov011Bit01, self, 0xf0).b1 = 0;
                    } else {
                        F24c_SetState(FLD(F24cList *, self, 0x100), 6);
                        FLD(Ov011Bit01, self, 0xf0).b1 = 1;
                    }
                    s = FLD(Ov011Small6 *, self, 0x108);
                    s->f.b0 = 0;
                    s->f.b1 = 1;
                    s->a = 0x1000;
                    s->b = 0x1000;
                } else if (F24c_CountBusy(FLD(F24cList *, self, 0x100)) == 0 ||
                           (cnt == 0 && F24c_CountBusy(FLD(F24cList *, self, 0x100)) != 5)) {
                    F24c_SetState(FLD(F24cList *, self, 0x100), 5);
                    FLD(Ov011Bit01, self, 0xf0).b1 = 0;
                } else if (cnt < 2) {
                    self->unk_40->flags |= 0x8000;
                    FLD(Ov011Bit01, self, 0xf0).b0 = 1;
                } else if (F24c_Count(FLD(F24cList *, self, 0x100)) != 5) {
                    F24c_SetState(FLD(F24cList *, self, 0x100), 5);
                    FLD(Ov011Bit01, self, 0xf0).b1 = 0;
                } else {
                    self->unk_40->flags |= 0x10000;
                }
            }
            FLD(u16, self, 0xf2)++;
        }
    }
    func_ov011_021fff38(self);
    func_ov011_0220023c(self);
    func_ov011_02200310(self);
    func_ov011_02202a38();
    {
        void *pl = func_ov000_0219bf90();
        if (pl != NULL) {
            VEC_Add(&self->pos, &FLD(Ov011Vec, self, 0xf4), &v);
            FLD(Ov011Vec, pl, 0xb90) = v;
            FLD(s32, pl, 0xb9c) = 0x4b8;
        }
    }
    FLD(s32, self, 0xf4) = FLD(s32, data_ov011_02207258, 0x20);
    FLD(s32, self, 0xf8) = FLD(s32, data_ov011_02207258, 0x24);
    FLD(s32, self, 0xfc) = FLD(s32, data_ov011_02207258, 0x28);
    func_ov011_021fd638(FLD(void *, self, 0x100));
}
}
#endif
