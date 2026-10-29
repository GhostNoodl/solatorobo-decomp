#include "ov011/ov011.h"

#ifdef NONMATCHING
// func_ov011_021ff24c: 26 / 0 (raw / aligned register-masked, round raF; 56 / 0 in round raD; 61 / 4 at the
// end of ov011_021fef00.cpp in round qpJ, 114 / 4 in round ovreg).
// The read-only list and ring accessors take const pointers (F24c_Count, F24c_Active,
// F24c_CountBusy, the ring readers and F24c_GetRing), so their b0 tests are const reads, and the final
// `F24c_SetState(..., 5)` reloads self->unk_100 instead of reusing `l`. Then SetState's plain b0 read is not CSE'd
// with Count's const read across the count loop (jkF/jkG), the flag byte is re-read as in the ROM, `l` is not live
// across the search loop, and the &data_ov000_021ccd68 pool load is hoisted into fp. All three are needed: a
// non-const Count, a plain GetRing read or `F24c_SetState(l, 5)` gives 360+ / 53+. `cnt` declared before `nd`.
// Round raD moved the draft here from the end of ov011_021fef00.cpp: func_ov011_021ff084 there needs a const view
// of the 0x02207258 block (its name-pointer load is hoisted above the `s->a = 0` store; non-const gives 6 / 6),
// while this function needs a non-const one (the ROM interleaves the three +0x20 loads with their stores; const
// gives 61 / 4). MWCC decides this per declared object, not per lvalue (a const member, a const-struct cast, CFLD
// or `*(const char *const *)&...` in 021ff084 all stay at 6), so no single declaration in one TU gives both.
// Round raF: 26 / 0. The busy-count walk keeps its flag in a CountBusy local set in both arms of an if/else
// (it was a nested F24c_NodeBusy inline returning TRUE/FALSE). The nested inline's result is numbered after
// CountBusy's n/nd; the ROM's flag comes before them, as an outer-inline local does (56 -> 29). Declaring
// RingAt's head first gives k the ROM's sb (28). The same rule for RingSize: its count read is written in place
// (an outer-inline local) instead of a nested F24c_RingCount call, which gives the count the ROM's r2 (26).
// Left: register colouring of the ring loop only (head, p and pos share r3 in the ROM; ours r8/fp). The
// colour model wants the head load numbered after the late u16 narrowing temps, which no @ object can be.
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

// The .rodata block at 0x02207258 (defined in ov011_022077c0.cpp): four resource-name pointers, a zero
// rotation, a scale and a zero position. Read here through a non-const view, as in ov011_021ffb58.cpp and
// ov011_0220068c.cpp.
struct Ov011ResTbl {
    const char *name[4];
    s16 rot[3];
    s16 scale[4];
    u16 pad;
    Ov011Vec pos;
};

extern "C" {
extern Ov011ResTbl data_ov011_02207258;
}

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
    u16 head;
    u16 k = i;
    const s32 *p = NULL;
    if (r->f.b0 && r->count > i) {
        u16 pos;
        head = r->head;
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

static inline u32 F24c_CountBusy(const F24cList *l) {
    u32 n = 0;
    if (l->f.b0) {
        Ov011Node *nd;
        for (nd = l->head; nd != NULL; nd = nd->next) {
            BOOL busy;
            void *a;
            if (nd != NULL && (a = Ov011_FindActor(nd->id)) != NULL && func_ov011_02201244(a)) {
                busy = TRUE;
            } else {
                busy = FALSE;
            }
            if (busy) {
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
    u32 n = 0;
    if (r->f.b0) {
        n = r->count;
    }
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
    FLD(s32, self, 0xf4) = data_ov011_02207258.pos.x;
    FLD(s32, self, 0xf8) = data_ov011_02207258.pos.y;
    FLD(s32, self, 0xfc) = data_ov011_02207258.pos.z;
    func_ov011_021fd638(FLD(void *, self, 0x100));
}
}
#endif

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov011_022078e1[];
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02198360(void *a, s32 b, s32 c);
s32 func_02040528(s32 max);

void func_ov011_021ff8fc(Ov011Actor *self) {
    Ov011Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov011_022078e1, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_38->unk_c2_0 = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov011V *p;
        if (++s->timer > 100) {
            func_02049a48(data_02097e4c, 50, 100, -1, -1);
            p = func_02065f88(50 + 0x358, &self->pos);
            p->v14(0x1666, 0x1666, 0x1666);
            p->v24(0, 0x1000, 0);
            self->unk_38->unk_c2_0 = 1;
            FLD(u8, self->unk_38, 0xbe) = 0;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        } else {
            u16 t = self->unk_40->timer;
            if (t <= 75 && t % 15 == 0) {
                s32 x;
                s32 z;
                s32 a;
                s32 b;
                p = func_02065f88(0x398 - 15, &self->pos);
                p->v14(0x1666, 0x1666, 0x1666);
                x = self->unk_64;
                z = FLD(s32, self, 0x6c);
                a = func_02040528(x);
                b = func_02040528(z);
                p->v24(a, z + 0x1000 + b, x);
            }
        }
        break;
    }
    case 2:
        if (++s->timer > 60) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            FLD(u8, self->unk_38, 0xbe) = 0x1f;
            func_ov000_02198360(self->unk_40, 1, 0);
        } else if (self->unk_40->timer > 30) {
            u8 v = FLD(u8, self->unk_38, 0xbe) + 1;
            if (v > 0x1f) {
                v = 0x1f;
            }
            FLD(u8, self->unk_38, 0xbe) = v;
        }
        break;
    }
}

}
