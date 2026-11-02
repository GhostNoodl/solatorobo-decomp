#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/FieldMgr.h"

typedef struct {
    s32 x;
    s32 y;
} Pos02166be8;

extern "C" {

extern u8 data_ov000_021c9a9c[];
extern s32 data_02097d78[5];
Robo021ca458 *func_ov000_0219bf90(void);
void func_ov000_021658e8(void *self);
u8 *func_ov000_02165f94(void *self);
void *func_ov000_02165e2c(void *self, void *area);
void func_ov000_02164c50(void *self, void *tgt);
void func_ov000_02166180(void *self);
s32 FX_Div(s32 a, s32 b);

static inline BOOL FieldState_HasCmd(FieldState *q, s32 kind) {
    s32 i;
    for (i = q->head; i != q->tail;) {
        if (q->queue[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL IsMode0_02166be8(void) {
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL IsMode1_02166be8(void) {
    if (data_02097d78[3] == 1) {
        return TRUE;
    }
    return data_02097d78[0] == 1 ? TRUE : FALSE;
}

static inline s32 FxMulS64_02166be8(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Skip02166be8(void) {
    BOOL skip = FALSE;
    if (func_ov000_0219bf90() == NULL) {
        skip = TRUE;
    }
    if (FieldState_HasCmd(data_ov000_021ccd54, 9) || FieldState_HasCmd(data_ov000_021ccd54, 10)) {
        skip = TRUE;
    }
    return skip;
}

struct Obj02166be8 {
    u8 unk_00[0x30];
    Ctx0216607c *unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
};

void func_ov000_02166be8(Obj02166be8 *self) {
    Node0216607c *area;
    u8 *rgb;
    s32 k;
    s32 sq;
    u8 *tgt;
    Ctx0216607c *w;
    s32 dx;
    s32 dz;
    s32 ox;
    FieldMgr *ctx = data_ov000_021ccd6c;
    Item0216607c *e;
    tgt = (u8 *)ctx->unk_0c;
    Pos02166be8 c = LFLD(Pos02166be8, data_ov000_021c9a9c, 0x28);
    k = 0x1000;
    switch (self->unk_34) {
    case 4:
        func_ov000_021658e8(self);
        if (Skip02166be8()) {
            return;
        }
        if (tgt == NULL) {
            return;
        }
        func_ov000_02164c50(self, tgt);
        self->unk_34 = 8;
        return;
    case 3:
        tgt = NULL;
    case 8:
        if (tgt == NULL || self->unk_30->unk_04 != LFLD(u16, tgt, 8)) {
            self->unk_38 -= 0x1000;
        } else {
            self->unk_38 += 0x1000;
        }
        self->unk_3c = FX_Div(self->unk_38, k);
        if (self->unk_3c < 0) {
            self->unk_38 = 0;
            self->unk_3c = 0;
            self->unk_34 = 4;
            return;
        }
        if (self->unk_3c > 0x1000) {
            self->unk_38 = k;
            self->unk_3c = k;
            self->unk_34 = 7;
        }
        return;
    case 7: {
        rgb = func_ov000_02165f94(self);
        w = self->unk_30;
        k = 0x19a;
        if (w->sel == NULL || !w->sel->f3) {
            if (tgt == NULL || w->unk_04 != LFLD(u16, tgt, 8)) {
                self->unk_34 = 3;
                return;
            }
        } else {
            if (Skip02166be8() || tgt == NULL || self->unk_30->unk_04 != LFLD(u16, tgt, 8)) {
                self->unk_34 = 4;
                return;
            }
        }
        w->unk_cc4 += 0x1000;
        w->unk_cc8 = FX_Div(w->unk_cc4, 0x20000);
        if (w->unk_cc8 >= 0x1000) {
            w->unk_cc4 = 0;
            w->unk_cc8 = 0x1000;
        }
        w->unk_cd4 += 0x1000;
        w->unk_cd8 = FX_Div(w->unk_cd4, 0x40000);
        if (w->unk_cd8 >= 0x1000) {
            w->unk_cd4 = 0;
            w->unk_cd8 = 0x1000;
        }
        w->unk_ccc += 0x1000;
        w->unk_cd0 = FX_Div(w->unk_ccc, 0x40000);
        if (w->unk_cd0 >= 0x1000) {
            w->unk_ccc = 0;
            w->unk_cd0 = 0x1000;
        }
        if (IsMode0_02166be8() || IsMode1_02166be8()) {
            u8 idx = rgb[2];
            Ctx0216607c *w2 = self->unk_30;
            area = idx >= w2->count ? NULL : &w2->nodes[idx];
            if (area != w->sel) {
                w->unk_cc4 = 0;
                w->unk_cc8 = 0;
                if (w->anim == NULL) {
                    w->unk_ccc = 0;
                    w->unk_cd0 = 0;
                }
            }
            w->sel = area;
            if (area == NULL) {
                return;
            }
            e = (Item0216607c *)func_ov000_02165e2c(self, area);
            if (e != w->cur) {
                if (e == NULL || w->cur == NULL) {
                    if (!FieldState_HasCmd(data_ov000_021ccd54, 0x14)) {
                        k = 0x1000;
                    }
                }
                w->cur = e;
                w->unk_cc4 = 0;
                w->unk_cc8 = 0;
                w->unk_ccc = 0;
                w->unk_cd0 = 0;
            }
            w->unk_00 = 0;
        }
        e = w->cur;
        if (e == NULL) {
            return;
        }
        dz = ((e->b - c.y) << 12) - w->oy;
        ox = w->ox;
        dx = ((e->a - c.x) << 12) - ox;
        { s64 t = (s64)dx * dx; t += (s64)dz * dz; sq = (s32)((t + 0x800) >> 12); }
        if (sq < 0x100) {
            k = 0x1000;
        }
        w->ox = ox + FxMulS64_02166be8(k, dx);
        w->oy += FxMulS64_02166be8(k, dz);
        func_ov000_02166180(self);
        break;
    }
    case 10:
        break;
    }
}

}

#ifdef NONMATCHING
// Status (round drA): func_ov000_0216715c is 3 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: register-only: the outer sine (a codegen temp) is r1, the ROM r6 (a coalesce with
// f_0 or j, not a numbering). History: docs/MATCHING.md rounds bgS, bgU, raF, rgB, mtA, cvA (search for the
// address); the full list is docs/UNMATCHED.md.
// func_ov000_0216715c (round bgJ): 124 / 58 (113 / 45 with branch targets and pool offsets masked).
// Real signature (self, p), as LoTail in Lo_02164708.cpp calls it. The old draft's third
// parameter k stood in for a block-scope local plus f_0 set by if/else (see MATCHING.md, round bgJ).
// Left: the sine temp in r6, the oam/anim temps at entry, and inner-loop colouring.
// Round fxA: `s32 d = b - a; return LO_FX_MUL(d, s) + a;` in Lerp715c gives the ROM's smull
// operand order (difference in Rm, sine in Rs) and 116 / 66 (109 with branch targets and pool
// offsets masked), but the inner block's loads then schedule further from the ROM (masked 58 -> 66).
// Round frD: 112 / 53 (99 / 40 masked, from 113 / 45). The struct-typed `oam` template is
// declared at its first use (`Oam715c oam = LFLD(Oam715c, p, 0x2c);`, rule 3 of round frC) and
// `oy` after `r` (tools/declsweep.py --use, greedy).
// Round bgS: 3 / 0 (3 / 0 with branch targets and pool offsets masked), from 112 / 53. The lerp
// writes through an out pointer, `Lerp715c(&x0, x0, x1 << 12, s)`: a value stored through a
// pointer is not forwarded into the oam bit-field stores, so both lerps come before the
// read-modify-write of oam word 0, as in the ROM (MATCHING.md, round bgS). With fxA's `d`
// local, `oy` declared before `ox` (ox gets sp+0x14) and the r-field compares written field
// first, everything but the outer sine's register matches (ours r1, the ROM r6).
// Round bgU: tools/ramerge.py shows the ROM's sine shares f_0's live range (the only single
// coalesce that gives r6 with nothing else moving); no honest source for that found yet.
// Round rgB: tools/vnum.sh: the sine is a codegen temp, not an object. Every named copy of it (in s, x0, f_0 as
// s32, k reused, a new local, or written through an out-pointer Sin715c(&v, a) inline into any of these) is
// forwarded back (3 / 0). ramerge has no renumbering for it, only the merges with f_0 or j, so this is a coalesce
// (a copy into f_0's or j's register), not a band, and no band lever reaches it.
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
} Oam0_715c;

typedef struct {
    u32 lo : 12;
    u32 pal : 4;
    u32 hi : 16;
} Oam1_715c;

typedef struct {
    Oam0_715c w0;
    Oam1_715c w1;
} Oam715c;

typedef struct {
    u32 b0 : 4;
    u32 b4 : 1;
} QBits715c;

typedef struct {
    u32 b0 : 5;
    u32 a : 8;
    u32 b : 8;
} RBits715c;


typedef struct {
    s32 x;
    s32 y;
} Pos715c;

typedef struct {
    Pos715c *pos;
    Oam715c *oam;
    s32 x;
    s32 y;
    u8 ofs;
    u8 kind;
    u8 idx;
    u8 tgt;
} Link715c;

typedef struct {
    RBits715c bits;
    u8 unk_04[0x5];
    u8 count;
    u8 nlinks;
    u8 unk_0b[0x5];
    Oam715c *oams;
    Link715c *links;
} Part715c;

typedef struct {
    Part715c *part;
    u8 unk_04[0x8];
    s32 x;
    s32 y;
} Ent715c;

typedef struct {
    u8 unk_00[0x4];
    Ent715c **ents;
} Anim715c;

typedef struct {
    u8 unk_00[0x30];
    u16 *data;
} Pal715c;

typedef struct {
    u8 unk_00[0x10a];
    u16 state;
} Fade715c;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 count2;
    u8 unk_03[0x5];
    u8 count;
    u8 unk_09[0x3];
    Oam715c oamPl;
    Oam715c oamSel;
    u8 unk_1c[0x10];
    Oam715c oam;
    u8 unk_34[0x618];
    Oam715c oams[0x80];
    u8 unk_a4c[0x23c];
    Anim715c *anim;
    Pal715c *pal;
    s8 *palMap;
    u8 unk_c94[0x20];
    u8 *cur;
    Part715c *sel;
    s32 ox;
    s32 oy;
    s32 unk_cc4;
    s32 unk_cc8;
    s32 unk_ccc;
    s32 unk_cd0;
    s32 unk_cd4;
    s32 unk_cd8;
    Fade715c *fade;
} Work715c;

extern "C" {
typedef struct { s8 x; s8 y; } Ofs715c;
extern Ofs715c data_ov000_021c9ae4[];
void *func_0203bbfc(void *a, s32 b);
BOOL NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);
u32 func_02041080(void *a, s32 b, s32 c, s32 d);

static inline void SetXY715c_b(Oam715c *o, u16 x, u16 y) {
    o->w0.x = x;
    o->w0.y = y & 0x1ff;
}
static inline BOOL Busy715c(Lo021cb6b0 *self) {
    Fade715c *h = ((Work715c *)self->unk_30)->fade;
    if (h == NULL || h->state == 0) return FALSE;
    return TRUE;
}

static inline void Lerp715c(s32 *out, s32 a, s32 b, s32 s) { s32 d = b - a; *out = LO_FX_MUL(d, s) + a; }
void func_ov000_0216715c(Lo021cb6b0 *self, Work715c *p) {
    u8 ii;
    s32 s;
    s32 y0;
    Part715c *r;
    s32 oy;
    s32 ox;
    Link715c *pt;
    Link715c *q;
    s32 x1;
    u8 j;
    Ent715c *e;
    void *mgr;
    Pal715c *pal;
    u16 *d;
    Robo021ca458 *pl;
    FieldState *g;
    u8 c;
    u8 kind;
    Ent715c *e2;
    s32 x0;
    Anim715c *anim;
    s32 y1;
    BOOL f_0;
    u8 i;
    BOOL f_1;
    kind = p->cur[0x14];
    anim = p->anim + kind;
    Oam715c oam = p->oam;
    g = data_ov000_021ccd54;
    mgr = func_0203bbfc(data_02097d48, 1);
    ox = p->ox;
    oy = p->oy;
    oam.w1.pal = p->palMap[oam.w1.pal];
    if (p->count2 != 0 && p->unk_cd8 > 0x800) {
        NNS_G2dEntryOamManagerOam(mgr, p->oams, p->count2);
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        NNS_G2dEntryOamManagerOam(mgr, &p->oamPl, 1);
        if (pl->unk_b28_0 == 0) {
            f_1 = TRUE;
            if (pl->unk_b28_2 != 1) {
                f_1 = FALSE;
            }
            if (!f_1 && p->unk_00 == 0 && p->sel != NULL && !LFLD(QBits715c, p->sel, 0).b4) {
                NNS_G2dEntryOamManagerOam(mgr, &p->oamSel, 1);
            }
        }
    }
    for (i = 0; i < p->count; i++) {
        e = anim->ents[i];
        if (e == NULL) {
            continue;
        }
        r = e->part;
        s32 k = (LO_FX_MUL(FX_SinCosTable_[((p->unk_cd0 << 15) >> 16) * 2], 0xd000) >> 12) + 3;
        if (k >= 0xf) {
            k = 0xf;
        }
        pal = p->pal;
        if (Busy715c(self)) {
            d = pal->data + 0x10;
            d[2] = d[k];
            DC_FlushRange(d, 0x20);
            func_02041080(p->pal, 2, 2, 1);
            if (r == p->sel) {
                f_0 = TRUE;
            } else {
                f_0 = FALSE;
            }
        } else {
            if (r->bits.a == g->unk_ca.c[1] && r->bits.b == g->unk_ca.c[2]) {
                f_0 = TRUE;
            } else {
                f_0 = FALSE;
            }
        }
        if (f_0) {
            d = pal->data;
            d[2] = d[k];
            DC_FlushRange(d, 0x20);
            func_02041080(p->pal, 2, 1, 1);
            pt = r->links;
            for (j = 0; j < r->nlinks; j++, pt++) {
                c = pt->tgt;
                if (c != 0xff) {
                    if (kind != pt->kind) {
                        continue;
                    }
                    ii = pt->idx;
                    if (ii >= p->count) {
                        continue;
                    }
                    e2 = anim->ents[ii];
                    if (e2 == NULL) {
                        continue;
                    }
                    q = e2->part->links + c;
                    x0 = e->x + pt->x - (ox >> 12) + data_ov000_021c9ae4[pt->ofs].x;
                    y0 = e->y + pt->y - (oy >> 12) + data_ov000_021c9ae4[pt->ofs].y;
                    s = FX_SinCosTable_[((p->unk_cc8 << 14) >> 16) * 2];
                    x1 = e2->x + q->x - (ox >> 12) + data_ov000_021c9ae4[q->ofs].x;
                    y1 = e2->y + q->y - (oy >> 12) + data_ov000_021c9ae4[q->ofs].y;
                    x0 <<= 12;
                    y0 <<= 12;
                    Lerp715c(&x0, x0, x1 << 12, s);
                    Lerp715c(&y0, y0, y1 << 12, s);
                    SetXY715c_b(&oam, x0 >> 12, y0 >> 12);
                    NNS_G2dEntryOamManagerOam(mgr, &oam, 1);
                }
                NNS_G2dEntryOamManagerOam(mgr, r->links[j].oam, 1);
            }
        }
        NNS_G2dEntryOamManagerOam(mgr, r->oams, r->count);
    }
}

}
#endif
