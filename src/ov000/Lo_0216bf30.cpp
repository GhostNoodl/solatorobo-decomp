#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

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

extern u8 *data_02097d48;
Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
void func_ov000_0216c018(void *self);
struct LoHost0216c310;
void func_ov000_0216c310(struct LoHost0216c310 *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

struct Obj0216bf30 {
    s32 unk_00;
    u8 unk_04[0x240];
    s32 unk_244;
    s32 unk_248;
    s32 unk_24c;
    s32 unk_250;
    u8 unk_254[0x108];
    s32 unk_35c;
};

void func_ov000_0216bf30(Obj0216bf30 *self) {
    s32 i;
    self->unk_00 = 0x1000;
    for (i = 0; i < 0x10; i++) {
        u8 *e = (u8 *)self + i * 0x24;
        LFLD(s32, e, 4) = -1;
        LFLD(u8, e, 8) = 0;
    }
    self->unk_244 = 0;
    self->unk_248 = 0;
    self->unk_24c = 0;
    self->unk_250 = 0;
    MI_CpuFill8((u8 *)self + 0x254, 0, 0x108);
    self->unk_35c = 0;
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
void func_ov000_0216bf18(void *self);

static inline LoText0216c018 *NewText0216c018(void) {
    LoText0216c018 *t = (LoText0216c018 *)Heap_Alloc(0xb8);
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
// Status (round drA): func_ov000_0216c310 is 65 / 22 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: colouring order (the ROM pops y between next and self) plus the post-allocation
// CSE movne r0, ip; the 65 / 10 drafts need fake parameters. History: docs/MATCHING.md rounds mcA, hzS, qpG, pmA,
// nmA, mtA, cvA (search for the address); the full list is docs/UNMATCHED.md.
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
// Round pmA: not a block-boundary problem. Every loop block starts at 35-38 live (preheader constants), so no
// split can reach normal mode; list permutations of the multiply block and `m -= 0x80000` after the test
// (173 / 27) do not help either.
// Round bgW: 176 / 24 -> 65 / 23 (raw / aligned-masked, scratch bgW/sa.sh) with `m` computed after the IsCurNode
// test (qpG's form): the multiply then leaves the pressure-mode test block, the ip zero and `movne r0, ip` go and
// the length is the ROM's. The ROM interleaves the umull with the test (ldr 0x35c after the adds) and puts only
// the `- 0x80000` after `strgt`, which is the split form (`m = LO_FX_MUL(s, 0x88000);` before the test,
// `(m - 0x80000) >> 12` after it): that brings the ip zero back (173 / 27), with any IsCurNode spelling
// (`== n`, if/else returns, if/else result variable: 173-185). What is left is the self/y colouring (r6/sb
// against the ROM's r7/r6) of rounds bgG/hzS and the interleave.
// This file's .text ends at 0x0216c310, so the function belongs here once it matches.
extern "C" {

extern void *data_0214a420;
BOOL func_02065748(void *p, VObj *obj);

typedef struct LoSlot0216c310 LoSlot0216c310;
struct LoSlot0216c310 {
    u32 flags;
    s32 kind;
    VObj *obj;
    s32 t;
    s32 drop;
    s32 x;
    s32 y;
    s32 base;
    s32 timer;
    VObj *eff;
    LoSlot0216c310 *next;
};

struct LoHost0216c310 {
    s32 speed;
    u8 unk_04[0x240];
    s32 unk_244;
    s32 unk_248;
    LoSlot0216c310 *head;
    LoSlot0216c310 *tail;
    LoSlot0216c310 slots[6];
    LoSlot0216c310 *cur;
    LoTimedObj res[10];
};

static inline BOOL IsCur0216c310(LoHost0216c310 *self) {
    return self->cur != NULL ? TRUE : FALSE;
}

static inline void Release0216c310(LoTimedObj *slot) {
    if (slot->obj != NULL && --slot->timer == 0) {
        HEAP_DELETE_VOBJ(slot->obj);
    }
}

static inline BOOL IsCurNode0216c310(LoHost0216c310 *self, LoSlot0216c310 *n) {
    return self->cur == n ? TRUE : FALSE;
}

void func_ov000_0216c310(LoHost0216c310 *self) {
    s32 s;
    s32 m;
    s32 r;
    s32 y;
    LoSlot0216c310 *h;
    LoTimedObj *slA;
    LoTimedObj *slB;
    LoSlot0216c310 *prev;
    LoSlot0216c310 *n;
    LoSlot0216c310 *next;
    prev = NULL;
    for (n = self->head; n != NULL; n = next) {
        next = n->next;
        if (n->flags & 4) {
            if (IsCur0216c310(self)) {
                n->drop += LO_FX_MUL(self->speed, 0x400);
            } else if (++n->timer > 0x3c) {
                n->drop += LO_FX_MUL(self->speed, 0x800);
            }
            y = n->drop;
        } else {
            y = 0;
        }
        if (n != NULL) {
            if (n->flags & 2) {
                n->t += self->speed;
                r = FX_Div(n->t, 0x10000);
                if (r >= 0x1000) {
                    n->flags &= ~2;
                    n->flags |= 4;
                    n->t = 0x10000;
                    n->base = prev != NULL ? prev->drop & 0x7ffff000 : 0;
                    r = 0x1000;
                }
                s = FX_SinCosTable_[(r << 14 >> 16) * 2];
            } else {
                s = 0x1000;
            }
            if (IsCurNode0216c310(self, n) && y > 0x8000) {
                self->cur = NULL;
            }
            m = LO_FX_MUL(s, 0x88000) - 0x80000;
            n->x = m >> 12;
            n->y = (0x24000 - y) >> 12;
            if (n->kind == 7 && n->eff != NULL) {
                if (func_02065748(data_0214a420, n->eff)) {
                    n->eff->vfunc_14(0x1000, 0x1000, 0x1000);
                    n->eff->vfunc_1c((n->x << 12) - 0x51000, -((n->y << 12) - 0x5b000), -0x400);
                } else {
                    n->eff = NULL;
                }
            }
            if (n->y < -0x10) {
                h = self->head;
                if (h == self->tail) {
                    self->tail = NULL;
                    self->head = NULL;
                } else {
                    self->head = h->next;
                }
                slA = &self->res[data_ov000_021c9bb4[n->kind].a];
                Release0216c310(slA);
                slB = &self->res[data_ov000_021c9bb4[n->kind].b];
                Release0216c310(slB);
                n->kind = -1;
                n->flags = 0;
                n->next = NULL;
                HEAP_DELETE_VOBJ(n->obj);
                if (n->eff != NULL && func_02065748(data_0214a420, n->eff)) {
                    LFLD(s32, n->eff, 0x1c) = 4;
                }
                n->eff = NULL;
                n = NULL;
            }
        }
        prev = n;
    }
}

}
#endif
