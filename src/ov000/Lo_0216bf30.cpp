#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/FieldMsg.h"
#include "ov000/LoTicker.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

void func_ov000_0216bf30(LoTicker *self) {
    s32 i;
    self->speed = 0x1000;
    for (i = 0; i < 0x10; i++) {
        self->msgs[i].kind = -1;
        self->msgs[i].text[0] = 0;
    }
    self->read = 0;
    self->write = 0;
    self->head = NULL;
    self->tail = NULL;
    MI_CpuFill8(self->slots, 0, sizeof(self->slots));
    self->cur = NULL;
}

void func_ov000_0216bf90(LoTicker *self) {
    s32 i;
    func_ov000_0216bcbc(self);
    for (i = 0; i < 10; i++) {
        if (self->res[i].win != NULL && --self->res[i].count == 0) {
            HEAP_DELETE(TextWin *, self->res[i].win, p->unk_vf04());
        }
    }
}

void func_0204ca70(TextWin *win);
void func_ov000_0216bf18(NNSG3dRS *rs);

static inline TextWin *NewText0216c018(void) {
    TextWin *t = (TextWin *)Heap_Alloc(0xb8);
    if (t != NULL) {
        *(const u32 **)t = data_0208ba70;
        func_0204c7d0(t);
    }
    return t;
}

static inline void SetText0216c018(TextWin *t, char *str) {
    t->str = (u32)str;
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, (s8)t->unk_37 != 0);
    data_02097ce0->unk_004 = t->font;
}

static inline BOOL HasPending0216c018(LoTicker *self) {
    return self->read != self->write ? TRUE : FALSE;
}

static inline LoTickerMsg *GetCur0216c018(LoTicker *self) {
    return &self->msgs[self->read];
}

void func_ov000_0216c018(LoTicker *self) {
    s32 sc;
    const LoTickerIcons *tbl;
    LoTickerSlot *s;
    s32 i;
    s32 n;
    LoTickerMsg *e;
    if (!HasPending0216c018(self)) {
        return;
    }
    n = self->write - self->read;
    if (n < 0) {
        n += 16;
    }
    sc = LO_FX_MUL(n << 12, 0x400);
    self->speed = sc;
    if (sc < 0x1000) {
        self->speed = 0x1000;
    } else if (sc > 0x3000) {
        self->speed = 0x3000;
    }
    if (self->cur != NULL ? TRUE : FALSE) {
        return;
    }
    e = GetCur0216c018(self);
    tbl = data_ov000_021c9bb4;
    for (i = 0; i < 6; i++) {
        if (!(self->slots[i].flags & 1)) {
            break;
        }
    }
    s = i == 6 ? NULL : &self->slots[i];
    if (s == NULL) {
        return;
    }
    s->flags = 3;
    s->kind = e->kind;
    s->t = 0;
    s->drop = 0;
    s->base = 0;
    s->timer = 0;
    s->eff = NULL;
    if (e->text[0] != 0) {
        s->text = NewText0216c018();
        s->text->font = 4;
        SetText0216c018(s->text, e->text);
        s->text->color0 = 0x7fff;
        s->text->color1 = 0x3b7f;
        s->text->flags |= 0x40;
        s->text->posZ = -0x1000;
        s->text->flags |= 0x1000000;
        s->text->flags |= 0x400000;
        s->text->flags |= 0x40000000;
        s->text->flags |= 4;
        func_0204ca70(s->text);
    } else {
        s->text = NULL;
    }
    func_ov000_0216bae4(&self->res[tbl[s->kind].a], NULL);
    func_ov000_0216bae4(&self->res[tbl[s->kind].b], NULL);
    if (s->kind == 7) {
        s->eff = func_02066c58();
        s->eff->initCallback = func_ov000_0216bf18;
        s->eff->loopStart = 0x7fffffff;
        s->eff->loopCount = -1;
    }
    if (self->head == NULL) {
        self->head = s;
    } else {
        self->tail->next = s;
    }
    self->tail = s;
    self->cur = s;
    self->msgs[self->read].kind = -1;
    self->msgs[self->read].text[0] = 0;
    if (++self->read >= 16) {
        self->read = 0;
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


static inline BOOL IsCur0216c310(LoTicker *self) {
    return self->cur != NULL ? TRUE : FALSE;
}

static inline void Release0216c310(LoTextHolder *slot) {
    if (slot->win != NULL && --slot->count == 0) {
        HEAP_DELETE(TextWin *, slot->win, p->unk_vf04());
    }
}

static inline BOOL IsCurNode0216c310(LoTicker *self, LoTickerSlot *n) {
    return self->cur == n ? TRUE : FALSE;
}

void func_ov000_0216c310(LoTicker *self) {
    s32 s;
    s32 m;
    s32 r;
    s32 y;
    LoTickerSlot *h;
    LoTextHolder *slA;
    LoTextHolder *slB;
    LoTickerSlot *prev;
    LoTickerSlot *n;
    LoTickerSlot *next;
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
                if (EffectMgr_Contains(data_0214a420, n->eff)) {
                    n->eff->SetScaleXYZ(0x1000, 0x1000, 0x1000);
                    n->eff->SetPosXYZ((n->x << 12) - 0x51000, -((n->y << 12) - 0x5b000), -0x400);
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
                HEAP_DELETE(TextWin *, n->text, p->unk_vf04());
                if (n->eff != NULL && EffectMgr_Contains(data_0214a420, n->eff)) {
                    n->eff->state = 4;
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
