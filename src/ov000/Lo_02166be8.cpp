#include "ov000/LoCommon.h"
#include "ov000/CmdQueue.h"

typedef struct {
    s32 x;
    s32 y;
} Pos02166be8;

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
} Bits02166be8;

extern "C" {

extern u8 *data_ov000_021ccd6c;
extern u8 data_ov000_021c9a9c[];
extern CmdQueue *data_ov000_021ccd54;
extern u8 data_02097d78[];
void *func_ov000_0219bf90(void);
void func_ov000_021658e8(void *self);
u8 *func_ov000_02165f94(void *self);
void *func_ov000_02165e2c(void *self, void *area);
void func_ov000_02164c50(void *self, void *tgt);
void func_ov000_02166180(void *self);
s32 FX_Div(s32 a, s32 b);

static inline BOOL CmdQueue_Has02166be8(CmdQueue *q, s32 kind) {
    s32 i;
    for (i = q->unk_90; i != q->index;) {
        if (q->kinds[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL IsMode0_02166be8(void) {
    if (LFLD(s32, data_02097d78, 0xc) == 0 && LFLD(s32, data_02097d78, 0) == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL IsMode1_02166be8(void) {
    if (LFLD(s32, data_02097d78, 0xc) == 1) {
        return TRUE;
    }
    return LFLD(s32, data_02097d78, 0) == 1 ? TRUE : FALSE;
}

static inline s32 FxMulS64_02166be8(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Skip02166be8(void) {
    BOOL skip = FALSE;
    if (func_ov000_0219bf90() == NULL) {
        skip = TRUE;
    }
    if (CmdQueue_Has02166be8(data_ov000_021ccd54, 9) || CmdQueue_Has02166be8(data_ov000_021ccd54, 10)) {
        skip = TRUE;
    }
    return skip;
}

void func_ov000_02166be8(u8 *self) {
    u8 *area;
    u8 *rgb;
    s32 k;
    s32 sq;
    u8 *tgt;
    u8 *w;
    s32 dx;
    s32 dz;
    s32 ox;
    u8 *ctx = data_ov000_021ccd6c;
    u8 *e;
    tgt = LFLD(u8 *, ctx, 0xc);
    Pos02166be8 c = LFLD(Pos02166be8, data_ov000_021c9a9c, 0x28);
    k = 0x1000;
    switch (LFLD(s32, self, 0x34)) {
    case 4:
        func_ov000_021658e8(self);
        if (Skip02166be8()) {
            return;
        }
        if (tgt == NULL) {
            return;
        }
        func_ov000_02164c50(self, tgt);
        LFLD(s32, self, 0x34) = 8;
        return;
    case 3:
        tgt = NULL;
    case 8:
        if (tgt == NULL || LFLD(u16, LFLD(u8 *, self, 0x30), 4) != LFLD(u16, tgt, 8)) {
            LFLD(s32, self, 0x38) -= 0x1000;
        } else {
            LFLD(s32, self, 0x38) += 0x1000;
        }
        LFLD(s32, self, 0x3c) = FX_Div(LFLD(s32, self, 0x38), k);
        if (LFLD(s32, self, 0x3c) < 0) {
            LFLD(s32, self, 0x38) = 0;
            LFLD(s32, self, 0x3c) = 0;
            LFLD(s32, self, 0x34) = 4;
            return;
        }
        if (LFLD(s32, self, 0x3c) > 0x1000) {
            LFLD(s32, self, 0x38) = k;
            LFLD(s32, self, 0x3c) = k;
            LFLD(s32, self, 0x34) = 7;
        }
        return;
    case 7: {
        rgb = func_ov000_02165f94(self);
        w = LFLD(u8 *, self, 0x30);
        k = 0x19a;
        if (LFLD(void *, w, 0xcb8) == NULL || !LFLD(Bits02166be8, LFLD(void *, w, 0xcb8), 0).b3) {
            if (tgt == NULL || LFLD(u16, w, 4) != LFLD(u16, tgt, 8)) {
                LFLD(s32, self, 0x34) = 3;
                return;
            }
        } else {
            if (Skip02166be8() || tgt == NULL || LFLD(u16, LFLD(u8 *, self, 0x30), 4) != LFLD(u16, tgt, 8)) {
                LFLD(s32, self, 0x34) = 4;
                return;
            }
        }
        LFLD(s32, w, 0xcc4) += 0x1000;
        LFLD(s32, w, 0xcc8) = FX_Div(LFLD(s32, w, 0xcc4), 0x20000);
        if (LFLD(s32, w, 0xcc8) >= 0x1000) {
            LFLD(s32, w, 0xcc4) = 0;
            LFLD(s32, w, 0xcc8) = 0x1000;
        }
        LFLD(s32, w, 0xcd4) += 0x1000;
        LFLD(s32, w, 0xcd8) = FX_Div(LFLD(s32, w, 0xcd4), 0x40000);
        if (LFLD(s32, w, 0xcd8) >= 0x1000) {
            LFLD(s32, w, 0xcd4) = 0;
            LFLD(s32, w, 0xcd8) = 0x1000;
        }
        LFLD(s32, w, 0xccc) += 0x1000;
        LFLD(s32, w, 0xcd0) = FX_Div(LFLD(s32, w, 0xccc), 0x40000);
        if (LFLD(s32, w, 0xcd0) >= 0x1000) {
            LFLD(s32, w, 0xccc) = 0;
            LFLD(s32, w, 0xcd0) = 0x1000;
        }
        if (IsMode0_02166be8() || IsMode1_02166be8()) {
            u8 idx = rgb[2];
            u8 *w2 = LFLD(u8 *, self, 0x30);
            area = idx >= w2[8] ? NULL : LFLD(u8 *, w2, 0xc84) + idx * 0x1c;
            if (area != LFLD(u8 *, w, 0xcb8)) {
                LFLD(s32, w, 0xcc4) = 0;
                LFLD(s32, w, 0xcc8) = 0;
                if (LFLD(void *, w, 0xcdc) == NULL) {
                    LFLD(s32, w, 0xccc) = 0;
                    LFLD(s32, w, 0xcd0) = 0;
                }
            }
            LFLD(u8 *, w, 0xcb8) = area;
            if (area == NULL) {
                return;
            }
            e = (u8 *)func_ov000_02165e2c(self, area);
            if (e != LFLD(u8 *, w, 0xcb4)) {
                if (e == NULL || LFLD(u8 *, w, 0xcb4) == NULL) {
                    if (!CmdQueue_Has02166be8(data_ov000_021ccd54, 0x14)) {
                        k = 0x1000;
                    }
                }
                LFLD(u8 *, w, 0xcb4) = e;
                LFLD(s32, w, 0xcc4) = 0;
                LFLD(s32, w, 0xcc8) = 0;
                LFLD(s32, w, 0xccc) = 0;
                LFLD(s32, w, 0xcd0) = 0;
            }
            w[0] = 0;
        }
        e = LFLD(u8 *, w, 0xcb4);
        if (e == NULL) {
            return;
        }
        dz = ((LFLD(s32, e, 0x10) - c.y) << 12) - LFLD(s32, w, 0xcc0);
        ox = LFLD(s32, w, 0xcbc);
        dx = ((LFLD(s32, e, 0xc) - c.x) << 12) - ox;
        { s64 t = (s64)dx * dx; t += (s64)dz * dz; sq = (s32)((t + 0x800) >> 12); }
        if (sq < 0x100) {
            k = 0x1000;
        }
        LFLD(s32, w, 0xcbc) = ox + FxMulS64_02166be8(k, dx);
        LFLD(s32, w, 0xcc0) += FxMulS64_02166be8(k, dz);
        func_ov000_02166180(self);
        break;
    }
    case 10:
        break;
    }
}

}

#ifdef NONMATCHING
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
#include "ov000/Vec.h"

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
    u8 b0 : 2;
    u8 b2 : 1;
} PlBits715c;

typedef struct {
    u32 b0 : 4;
    u32 b4 : 1;
} QBits715c;

typedef struct {
    u32 b0 : 5;
    u32 a : 8;
    u32 b : 8;
} RBits715c;

extern "C" {
extern void *data_02097d48;
typedef struct { s8 x; s8 y; } Ofs715c;
extern Ofs715c data_ov000_021c9ae4[];
void *func_0203bbfc(void *a, s32 b);
BOOL NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);
void DC_FlushRange(const void *addr, u32 size);
void func_02041080(void *a, s32 b, s32 c, s32 d);

static inline void SetXY715c_b(Oam715c *o, u16 x, u16 y) {
    o->w0.x = x;
    o->w0.y = y & 0x1ff;
}
static inline BOOL Busy715c(u8 *self) {
    u8 *h = LFLD(u8 *, LFLD(u8 *, self, 0x30), 0xcdc);
    if (h == NULL || LFLD(u16, h, 0x10a) == 0) return FALSE;
    return TRUE;
}

static inline s32 Lerp715c(s32 a, s32 b, s32 s) { return LO_FX_MUL(b - a, s) + a; }
void func_ov000_0216715c(u8 *self, u8 *p) {
    u8 ii;
    s32 s;
    s32 y0;
    u8 *r;
    s32 ox;
    s32 oy;
    u8 *pt;
    u8 *q;
    s32 x1;
    u8 j;
    u8 *e;
    void *mgr;
    u8 *pal;
    u16 *d;
    u8 *pl;
    u8 *g;
    u8 c;
    u8 kind;
    u8 *e2;
    s32 x0;
    u8 *anim;
    s32 y1;
    BOOL f_0;
    u8 i;
    BOOL f_1;
    kind = LFLD(u8 *, p, 0xcb4)[0x14];
    anim = LFLD(u8 *, p, 0xc88) + kind * 8;
    Oam715c oam = LFLD(Oam715c, p, 0x2c);
    g = (u8 *)data_ov000_021ccd54;
    mgr = func_0203bbfc(data_02097d48, 1);
    ox = LFLD(s32, p, 0xcbc);
    oy = LFLD(s32, p, 0xcc0);
    oam.w1.pal = LFLD(s8 *, p, 0xc90)[oam.w1.pal];
    if (p[2] != 0 && LFLD(s32, p, 0xcd8) > 0x800) {
        NNS_G2dEntryOamManagerOam(mgr, p + 0x64c, p[2]);
    }
    pl = (u8 *)func_ov000_0219bf90();
    if (pl != NULL) {
        NNS_G2dEntryOamManagerOam(mgr, p + 0xc, 1);
        if (LFLD(PlBits715c, pl, 0xb28).b0 == 0) {
            f_1 = TRUE;
            if (LFLD(PlBits715c, pl, 0xb28).b2 != 1) {
                f_1 = FALSE;
            }
            if (!f_1 && p[0] == 0 && LFLD(u8 *, p, 0xcb8) != NULL && !LFLD(QBits715c, LFLD(u8 *, p, 0xcb8), 0).b4) {
                NNS_G2dEntryOamManagerOam(mgr, p + 0x14, 1);
            }
        }
    }
    for (i = 0; i < p[8]; i++) {
        e = LFLD(u8 **, anim, 4)[i];
        if (e == NULL) {
            continue;
        }
        r = LFLD(u8 *, e, 0);
        s32 k = (LO_FX_MUL(FX_SinCosTable_[((LFLD(s32, p, 0xcd0) << 15) >> 16) * 2], 0xd000) >> 12) + 3;
        if (k >= 0xf) {
            k = 0xf;
        }
        pal = LFLD(u8 *, p, 0xc8c);
        if (Busy715c(self)) {
            d = LFLD(u16 *, pal, 0x30) + 0x10;
            d[2] = d[k];
            DC_FlushRange(d, 0x20);
            func_02041080(LFLD(void *, p, 0xc8c), 2, 2, 1);
            if (r == LFLD(u8 *, p, 0xcb8)) {
                f_0 = TRUE;
            } else {
                f_0 = FALSE;
            }
        } else {
            if (g[0xcb] == LFLD(RBits715c, r, 0).a && g[0xcc] == LFLD(RBits715c, r, 0).b) {
                f_0 = TRUE;
            } else {
                f_0 = FALSE;
            }
        }
        if (f_0) {
            d = LFLD(u16 *, pal, 0x30);
            d[2] = d[k];
            DC_FlushRange(d, 0x20);
            func_02041080(LFLD(void *, p, 0xc8c), 2, 1, 1);
            pt = LFLD(u8 *, r, 0x14);
            for (j = 0; j < r[0xa]; j++, pt += 0x14) {
                c = pt[0x13];
                if (c != 0xff) {
                    if (kind != pt[0x11]) {
                        continue;
                    }
                    ii = pt[0x12];
                    if (ii >= p[8]) {
                        continue;
                    }
                    e2 = LFLD(u8 **, anim, 4)[ii];
                    if (e2 == NULL) {
                        continue;
                    }
                    q = LFLD(u8 *, LFLD(u8 *, e2, 0), 0x14) + c * 0x14;
                    x0 = LFLD(s32, e, 0xc) + LFLD(s32, pt, 8) - (ox >> 12) + data_ov000_021c9ae4[pt[0x10]].x;
                    y0 = LFLD(s32, e, 0x10) + LFLD(s32, pt, 0xc) - (oy >> 12) + data_ov000_021c9ae4[pt[0x10]].y;
                    s = FX_SinCosTable_[((LFLD(s32, p, 0xcc8) << 14) >> 16) * 2];
                    x1 = LFLD(s32, e2, 0xc) + LFLD(s32, q, 8) - (ox >> 12) + data_ov000_021c9ae4[q[0x10]].x;
                    y1 = LFLD(s32, e2, 0x10) + LFLD(s32, q, 0xc) - (oy >> 12) + data_ov000_021c9ae4[q[0x10]].y;
                    x0 <<= 12;
                    y0 <<= 12;
                    x1 = Lerp715c(x0, x1 << 12, s);
                    y1 = Lerp715c(y0, y1 << 12, s);
                    SetXY715c_b(&oam, x1 >> 12, y1 >> 12);
                    NNS_G2dEntryOamManagerOam(mgr, &oam, 1);
                }
                NNS_G2dEntryOamManagerOam(mgr, LFLD(void *, LFLD(u8 *, r, 0x14) + j * 0x14, 4), 1);
            }
        }
        NNS_G2dEntryOamManagerOam(mgr, LFLD(void *, r, 0x10), r[9]);
    }
}

}
#endif
