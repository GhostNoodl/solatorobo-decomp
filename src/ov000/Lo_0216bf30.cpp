#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 timer;
    s32 unk_04;
    VObj *obj;
} LoTimedObj;

typedef struct {
    u8 pad[0x360];
    LoTimedObj objs[10];
} LoTimedHost;

extern void *data_ov000_021ccd54;
extern u8 *data_02097d48;
void *func_ov000_0219bf90(void *self);
void VEC_Add(void *a, void *b, void *c);
BOOL func_0203dc9c(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

void func_ov000_0216bf30(void *self) {
    s32 i;
    LFLD(s32, self, 0) = 0x1000;
    for (i = 0; i < 0x10; i++) {
        u8 *e = (u8 *)self + i * 0x24;
        LFLD(s32, e, 4) = -1;
        LFLD(u8, e, 8) = 0;
    }
    LFLD(s32, self, 0x244) = 0;
    LFLD(s32, self, 0x248) = 0;
    LFLD(s32, self, 0x24c) = 0;
    LFLD(s32, self, 0x250) = 0;
    MI_CpuFill8((u8 *)self + 0x254, 0, 0x108);
    LFLD(s32, self, 0x35c) = 0;
}

void func_ov000_0216bf90(void *self) {
    s32 i;
    func_ov000_0216bcbc(self);
    for (i = 0; i < 10; i++) {
        if (LFLD(VObj *, (u8 *)self + i * 12, 0x368) != NULL && --LFLD(s32, (u8 *)self + i * 12, 0x360) == 0) {
            LO_FREE_V((u8 *)self + i * 12, 0x368);
        }
    }
}

typedef struct {
    void *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad2c[0xb];
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u8 pad50[0x20];
    s32 unk_70;
    u16 unk_74;
    u16 unk_76;
} LoText0216c018;

typedef struct {
    s32 a;
    s32 b;
} LoPair0216c018;

extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
extern LoPair0216c018 data_ov000_021c9bb4[];
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
void func_ov000_0216bae4(void *p, s32 b);
u8 *func_02066c58(void);
void func_ov000_0216bf18(void);

static inline LoText0216c018 *NewText0216c018(void) {
    LoText0216c018 *t = (LoText0216c018 *)func_0203dd9c(0xb8);
    if (t != NULL) {
        t->vtbl = data_0208ba70;
        func_0204c7d0(t);
    }
    return t;
}

static inline void SetText0216c018(LoText0216c018 *t, char *str) {
    t->unk_24 = (s32)str;
    t->unk_4c = func_0204c4fc(t->unk_28, t->unk_38, t->unk_24, &t->unk_44, &t->unk_48, t->unk_37 != 0);
    LFLD(s32, data_02097ce0, 4) = t->unk_28;
}

static inline BOOL HasPending0216c018(u8 *self) {
    return LFLD(s32, self, 0x244) != LFLD(s32, self, 0x248) ? TRUE : FALSE;
}

static inline u8 *GetCur0216c018(u8 *self) {
    return self + 4 + LFLD(s32, self, 0x244) * 0x24;
}

void func_ov000_0216c018(void *obj) {
    u8 *self = (u8 *)obj;
    s32 sc;
    LoPair0216c018 *tbl;
    u8 *s;
    s32 i;
    s32 n;
    u8 *e;
    if (!HasPending0216c018(self)) {
        return;
    }
    n = LFLD(s32, self, 0x248) - LFLD(s32, self, 0x244);
    if (n < 0) {
        n += 16;
    }
    sc = LO_FX_MUL(n << 12, 0x400);
    LFLD(s32, self, 0) = sc;
    if (sc < 0x1000) {
        LFLD(s32, self, 0) = 0x1000;
    } else if (sc > 0x3000) {
        LFLD(s32, self, 0) = 0x3000;
    }
    if (LFLD(void *, self, 0x35c) != NULL ? TRUE : FALSE) {
        return;
    }
    e = GetCur0216c018(self);
    tbl = data_ov000_021c9bb4;
    for (i = 0; i < 6; i++) {
        if (!(LFLD(u32, self + i * 0x2c, 0x254) & 1)) {
            break;
        }
    }
    s = i == 6 ? NULL : self + 0x254 + i * 0x2c;
    if (s == NULL) {
        return;
    }
    LFLD(s32, s, 0) = 3;
    LFLD(s32, s, 4) = LFLD(s32, e, 0);
    LFLD(s32, s, 0xc) = 0;
    LFLD(s32, s, 0x10) = 0;
    LFLD(s32, s, 0x1c) = 0;
    LFLD(s32, s, 0x20) = 0;
    LFLD(s32, s, 0x24) = 0;
    if (LFLD(s8, e, 4) != 0) {
        LFLD(LoText0216c018 *, s, 8) = NewText0216c018();
        LFLD(LoText0216c018 *, s, 8)->unk_28 = 4;
        SetText0216c018(LFLD(LoText0216c018 *, s, 8), (char *)e + 4);
        LFLD(LoText0216c018 *, s, 8)->unk_74 = 0x7fff;
        LFLD(LoText0216c018 *, s, 8)->unk_76 = 0x3b7f;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x40;
        LFLD(LoText0216c018 *, s, 8)->unk_70 = -0x1000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x1000000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x400000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 0x40000000;
        LFLD(LoText0216c018 *, s, 8)->flags |= 4;
        func_0204ca70(LFLD(LoText0216c018 *, s, 8));
    } else {
        LFLD(void *, s, 8) = NULL;
    }
    func_ov000_0216bae4(self + 0x360 + tbl[LFLD(s32, s, 4)].a * 12, 0);
    func_ov000_0216bae4(self + 0x360 + tbl[LFLD(s32, s, 4)].b * 12, 0);
    if (LFLD(s32, s, 4) == 7) {
        LFLD(u8 *, s, 0x24) = func_02066c58();
        LFLD(void *, LFLD(u8 *, s, 0x24), 0x1c0) = (void *)func_ov000_0216bf18;
        LFLD(s32, LFLD(u8 *, s, 0x24), 0xcc) = 0x7fffffff;
        LFLD(s32, LFLD(u8 *, s, 0x24), 0xc8) = -1;
    }
    if (LFLD(void *, self, 0x24c) == NULL) {
        LFLD(void *, self, 0x24c) = s;
    } else {
        LFLD(void *, LFLD(u8 *, self, 0x250), 0x28) = s;
    }
    LFLD(void *, self, 0x250) = s;
    LFLD(void *, self, 0x35c) = s;
    LFLD(s32, self + LFLD(s32, self, 0x244) * 0x24, 4) = -1;
    LFLD(u8, self + LFLD(s32, self, 0x244) * 0x24, 8) = 0;
    if (++LFLD(s32, self, 0x244) >= 16) {
        LFLD(s32, self, 0x244) = 0;
    }
}

}

#ifdef NONMATCHING
// func_ov000_0216c310: 121 / 27 (raw / register-masked), 103 / 8 with branch targets and pool offsets masked.
// Round bgG's clean redraft (no permuter temporaries; the earlier best had __typeof__ noise and was 124 / 27).
// The 8 masked lines are scheduling around the IsCurNode test and m - 0x80000 that follow from the colouring:
// the ROM colours n, next, y before self and the two loop-invariant temps (data_02071060 and self + 0x360);
// ours pushes self last in simplify (pass 5, alone) and colours it first. No single degree offset, forced
// low/high node or declaration order (24 orders, block-scope y/s/m/r/h) changes that.
// Round mcA: 103 / 8 -> 68 / 8 (pool-masked; 105 / 10 -> 68 / 10 by tools' count). Each released slot goes through
// a named `sl` local instead of straight into the inline (so it is a user variable, numbered by declaration,
// not an inline parameter), with the locals declared s, m, r, y, h, sl, prev, n, next. The masked lines are unchanged.
// Round hzS: 68 / 10 -> 66 / 10. The second slot reused `sl`, so its web was a compiler temp (@411, frC's split-
// counter rule); separate slA/slB locals make both user variables. 400 random orders of the ten locals give no
// better score. Left: the ROM pops y between next and self (y is still blocked in the sweep that frees the
// self + 0x360 and data_02071060 temps); ours frees y in that sweep.
// Round qpG (gdb trace of mwcc): the `movne r0, ip` (ROM `movne r0, #0`) is post-allocation local CSE turning a
// constant move into a copy of ip, which holds the rematerialised high-word zero of LO_FX_MUL(s, 0x88000). ip gets it
// because the pre-allocation scheduler runs the multiply block in pressure mode (38 values live in, mostly hoisted
// cheap constants that local CSE will not merge in a loop preheader) and puts ldr [self, #0x35c] before the umull.
// Loop forms, multiply spellings and moving m after the IsCurNode test give no gain; see docs/MATCHING.md, qpG.
// This file's .text ends at 0x0216c310, so the function belongs here once it matches.
extern "C" {

extern void *data_0214a420;
extern const s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
BOOL func_02065748(void *p, VObj *obj);

static inline BOOL IsCur0216c310(u8 *self) {
    return LFLD(void *, self, 0x35c) != NULL ? TRUE : FALSE;
}

static inline void Release0216c310(u8 *slot) {
    if (LFLD(VObj *, slot, 8) != NULL && --LFLD(s32, slot, 0) == 0) {
        LO_FREE_V(slot, 8);
    }
}

static inline BOOL IsCurNode0216c310(u8 *self, u8 *n) {
    return LFLD(u8 *, self, 0x35c) == n ? TRUE : FALSE;
}

void func_ov000_0216c310(void *self) {
    s32 s;
    s32 m;
    s32 r;
    s32 y;
    u8 *h;
    u8 *slA;
    u8 *slB;
    u8 *prev;
    u8 *n;
    u8 *next;
    prev = NULL;
    for (n = LFLD(u8 *, self, 0x24c); n != NULL; n = next) {
        next = LFLD(u8 *, n, 0x28);
        if (LFLD(u32, n, 0) & 4) {
            if (IsCur0216c310((u8 *)self)) {
                LFLD(s32, n, 0x10) += LO_FX_MUL(LFLD(s32, self, 0), 0x400);
            } else if (++LFLD(s32, n, 0x20) > 0x3c) {
                LFLD(s32, n, 0x10) += LO_FX_MUL(LFLD(s32, self, 0), 0x800);
            }
            y = LFLD(s32, n, 0x10);
        } else {
            y = 0;
        }
        if (n != NULL) {
            if (LFLD(u32, n, 0) & 2) {
                LFLD(s32, n, 0xc) += LFLD(s32, self, 0);
                r = FX_Div(LFLD(s32, n, 0xc), 0x10000);
                if (r >= 0x1000) {
                    LFLD(u32, n, 0) &= ~2;
                    LFLD(u32, n, 0) |= 4;
                    LFLD(s32, n, 0xc) = 0x10000;
                    LFLD(s32, n, 0x1c) = prev != NULL ? LFLD(s32, prev, 0x10) & 0x7ffff000 : 0;
                    r = 0x1000;
                }
                s = FX_SinCosTable_[(r << 14 >> 16) * 2];
            } else {
                s = 0x1000;
            }
            m = LO_FX_MUL(s, 0x88000) - 0x80000;
            if (IsCurNode0216c310((u8 *)self, n) && y > 0x8000) {
                LFLD(void *, self, 0x35c) = NULL;
            }
            LFLD(s32, n, 0x14) = m >> 12;
            LFLD(s32, n, 0x18) = (0x24000 - y) >> 12;
            if (LFLD(s32, n, 4) == 7 && LFLD(VObj *, n, 0x24) != NULL) {
                if (func_02065748(data_0214a420, LFLD(VObj *, n, 0x24))) {
                    LFLD(VObj *, n, 0x24)->vfunc_14(0x1000, 0x1000, 0x1000);
                    LFLD(VObj *, n, 0x24)->vfunc_1c((LFLD(s32, n, 0x14) << 12) - 0x51000, -((LFLD(s32, n, 0x18) << 12) - 0x5b000), -0x400);
                } else {
                    LFLD(VObj *, n, 0x24) = NULL;
                }
            }
            if (LFLD(s32, n, 0x18) < -0x10) {
                h = LFLD(u8 *, self, 0x24c);
                if (h == LFLD(u8 *, self, 0x250)) {
                    LFLD(void *, self, 0x250) = NULL;
                    LFLD(void *, self, 0x24c) = NULL;
                } else {
                    LFLD(void *, self, 0x24c) = LFLD(void *, h, 0x28);
                }
                slA = (u8 *)self + 0x360 + data_ov000_021c9bb4[LFLD(s32, n, 4)].a * 12;
                Release0216c310(slA);
                slB = (u8 *)self + 0x360 + data_ov000_021c9bb4[LFLD(s32, n, 4)].b * 12;
                Release0216c310(slB);
                LFLD(s32, n, 4) = -1;
                LFLD(u32, n, 0) = 0;
                LFLD(void *, n, 0x28) = NULL;
                LO_FREE_V(n, 8);
                if (LFLD(VObj *, n, 0x24) != NULL && func_02065748(data_0214a420, LFLD(VObj *, n, 0x24))) {
                    LFLD(s32, LFLD(VObj *, n, 0x24), 0x1c) = 4;
                }
                LFLD(VObj *, n, 0x24) = NULL;
                n = NULL;
            }
        }
        prev = n;
    }
}

}
#endif
