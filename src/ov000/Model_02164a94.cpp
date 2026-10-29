#include "ov000/LoCommon.h"

extern "C" {

extern char data_0214b105[];
extern char *data_0208cca0;
extern char data_ov000_021cb8e0[];
extern char data_ov000_021cb8f1[];
extern char data_ov000_021cb8fd[];
extern char data_ov000_021cb909[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
void *func_02035d5c(const char *a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *model, void *fn);
void func_02041c18(void *model, void *arg);
void *func_ov000_021640fc(void *self, void *a, void *oam, u16 *cnt);

static inline void *NewModel(char *nm) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
        }
    }
    return m;
}

void func_ov000_02164a94(u8 *self) {
    char buf[0x20];
    void *a;
    void *b;
    s32 *pp;
    s32 saved;
    u8 *m;
    func_02035d5c(data_0214b105);
    a = func_02035d5c(data_0208cca0);
    func_0206e900(buf, data_ov000_021cb8e0);
    b = func_02035d5c(buf);
    LFLD(s32, self, 0x50) = LFLD(s32, data_0214a424, 0x20);
    pp = &LFLD(s32, data_02097d48, 0x9e4);
    saved = *pp;
    *pp = -1;
    m = (u8 *)NewModel(data_ov000_021cb8f1);
    LFLD(void *, self, 0x28) = m;
    func_020417e0(LFLD(void *, self, 0x28), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x28), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb8fd);
    LFLD(void *, self, 0x2c) = m;
    func_020417e0(LFLD(void *, self, 0x2c), func_02034d88(b, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x2c), 2, 0xffff);
    m = (u8 *)NewModel(data_ov000_021cb909);
    LFLD(void *, self, 0x24) = m;
    func_020417e0(LFLD(void *, self, 0x24), func_02034d88(a, m + 0x4c));
    func_02041d9c(LFLD(void *, self, 0x24), 2, 0xffff);
    func_02041c5c(LFLD(void *, self, 0x24), (void *)func_ov000_021640fc);
    func_02041c18(LFLD(void *, self, 0x24), self);
    *pp = saved;
}

}

#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 a0;
    u16 a1;
    u16 a2;
} OamAttr02164c50;

typedef struct {
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 rest : 16;
} OamW2_02164c50;

extern "C" {

void *func_0203de84(u32 size, u32 align);
void *func_0203dd9c(u32 size);
void MI_CpuFill8(void *dst, u32 value, u32 size);
void func_02041218(void *res);
void func_02040be0(void *res, void *src);
void func_02040d14(void *res, s32 a, s32 b);
void func_02040d94(void *res, void *a, s32 b, s32 c);
void func_02040dd8(void *res, s32 a, s32 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
struct Out_52e4;
struct Def_52e4;
void func_ov000_021652e4(void *self, u8 *p, struct Out_52e4 *rec, const struct Def_52e4 *e);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void *LoModelGetCell(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        return LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
}

typedef struct { u8 pad[6]; u8 n6; u8 n7; } Ent02164c50;
static inline u8 *Next02164c50(u8 *e) {
    u8 *q = e + 8;
    if (((Ent02164c50 *)e)->n6 != 0) {
        q += ((Ent02164c50 *)e)->n6 * 0x14;
    }
    if (((Ent02164c50 *)e)->n7 != 0) {
        q += ((Ent02164c50 *)e)->n7 * 0xc;
    }
    return q;
}

void func_ov000_02164c50(u8 *self, u8 *arg) {
    u8 *p;
    void *m;
    u8 *buf;
    u16 base;
    void *cell;
    OamAttr02164c50 *oa;
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x3c) = 0;
    p = (u8 *)func_0203de84(0xce0, 4);
    LFLD(u8 *, self, 0x30) = p;
    MI_CpuFill8(p, 0, 0xce0);
    p[0] = 1;
    LFLD(u16, p, 0x4) = LFLD(u16, arg, 0x8);
    p[8] = arg[0xa];
    p[2] = 0;
    m = func_0203dd9c(0x64);
    if (m != NULL) {
        func_02041218(m);
    }
    LFLD(void *, p, 0xc8c) = m;
    func_02040be0(m, LFLD(void *, self, 0x24));
    buf = LFLD(u8 *, LFLD(void *, p, 0xc8c), 0x30);
    LFLD(u16, p, 0xc94) = 2;
    LFLD(u16, p, 0xc96) = 4;
    {
        u8 *r = LFLD(u8 *, p, 0xc8c);
        LFLD(u16, r, 0x34) = 2;
        LFLD(void *, r, 0x38) = p + 0xc94;
        func_02040d14(LFLD(void *, p, 0xc8c), 0, LFLD(u16, r, 0x34) << 5);
    }
    func_02040d94(LFLD(void *, p, 0xc8c), buf + 0x40, 0, 0x20);
    func_02040d94(LFLD(void *, p, 0xc8c), buf + 0x80, 0x20, 0x20);
    func_02040dd8(LFLD(void *, p, 0xc8c), 2, 1);

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 2);
    base = LFLD(u16, LFLD(void *, self, 0x24), 0xf4);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    LFLD(s32, p, 0xc90) = LFLD(s32, LFLD(void *, LFLD(void *, self, 0x24), 0xec), 0x58);
    *(OamAttr02164c50 *)(p + 0x2c) = *oa;
    LFLD(OamW2_02164c50, p, 0x30).tile += base;
    p[1]++;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 3);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0xc) = *oa;
    LFLD(OamW2_02164c50, p, 0x10).tile += base;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xc);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0x14) = *oa;
    LFLD(OamW2_02164c50, p, 0x18).tile += base;
    LFLD(OamW2_02164c50, p, 0x18).prio = LFLD(OamW2_02164c50, p, 0x10).prio;
    LFLD(u16, p, 0x24) = base + LFLD(OamW2_02164c50, oa, 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xd);
    LFLD(u16, p, 0x26) = base + LFLD(OamW2_02164c50, LFLD(void *, cell, 0x4), 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xe);
    LFLD(u16, p, 0x28) = base + LFLD(OamW2_02164c50, LFLD(void *, cell, 0x4), 0x4).tile;

    cell = LoModelGetCell(LFLD(void *, self, 0x24), 0xb);
    oa = LFLD(OamAttr02164c50 *, cell, 0x4);
    *(OamAttr02164c50 *)(p + 0x1c) = *oa;
    LFLD(OamW2_02164c50, p, 0x20).prio = 2;
    LFLD(OamW2_02164c50, p, 0x20).tile += base;

    {
        u16 n1 = 0;
        u16 n2 = 0;
        s32 i;
        s32 j;
        s32 k;
        u8 *e = arg + 0xc;
        for (i = 0; i < p[8]; i++) {
            u8 *s;
            n1 += e[6];
            n2 += e[7];
            for (j = 0, s = e + 8; j < e[6]; j++, s += 0x14) {
                p[9] = p[9] < s[0x10] ? s[0x10] : p[9];
            }
            e = Next02164c50(e);
        }
        p[9]++;
        {
            u32 sz = n2 * 0x14;
            LFLD(void *, p, 0xc7c) = func_0203de84(sz, 4);
            MI_CpuFill8(LFLD(void *, p, 0xc7c), 0, sz);
        }
        {
            u32 sz = n1 * 0x18;
            LFLD(void *, p, 0xc80) = func_0203de84(sz, 4);
            MI_CpuFill8(LFLD(void *, p, 0xc80), 0, sz);
        }
        LFLD(void *, p, 0xc84) = func_0203de84(p[8] * 0x1c, 4);
        MI_CpuFill8(LFLD(void *, p, 0xc84), 0, p[8] * 0x1c);
        LFLD(void *, p, 0xc88) = func_0203de84(p[9] << 3, 4);
        MI_CpuFill8(LFLD(void *, p, 0xc88), 0, p[9] << 3);
        for (k = 0; k < p[9]; k++) {
            LFLD(void *, LFLD(u8 *, p, 0xc88) + k * 8, 4) = func_0203de84(p[8] << 2, 4);
            MI_CpuFill8(LFLD(void *, LFLD(u8 *, p, 0xc88) + k * 8, 4), 0, p[8] << 2);
        }
    }
    {
        u8 i;
        u8 *e = arg + 0xc;
        for (i = 0; i < p[8]; i++) {
            u32 off = i * 0x1c;
            LFLD(u32, LFLD(u8 *, p, 0xc84) + off, 0) = LFLD(u32, e, 0);
            LFLD(u8, LFLD(u8 *, p, 0xc84) + off, 8) = i;
            func_ov000_021652e4(self, p, (struct Out_52e4 *)(LFLD(u8 *, p, 0xc84) + off), (const struct Def_52e4 *)e);
            e = Next02164c50(e);
        }
    }
}

}

#ifdef NONMATCHING
// func_ov000_021652e4: 156 raw / 56 register-masked (round rtF), real four-argument signature
// (the only caller, func_ov000_021652a8, passes four), no fake parameters, comma or one-element
// array forms (the cxxperm drafts at 91 / 46 needed seven fake parameters). What is left is the
// spill-slot order (target: i, tbl, y0, x0, row at sp+0..0x10) and colouring in the parts loop.
// Round frA: 137 / 37. Oam_52e4 is now two attribute words (a01, and this file's OamW2 type for
// a23). The front end hoists one half of tmpl into a struct-typed temp, which gets a memory slot,
// so the frame is the target's 0x44 (was 0x3c).
// Round frB: 117 / 27, spill slots now the target's (i, tbl, y0, x0, row). The ?: for tbl made
// a compiler temp (numbered before every user variable) that took the first spill slot; with
// if/else assignments tbl is a user variable, and declaring row, x0, y0, tbl, i in that order
// gives the ascending node order (reverse declaration) the ROM shows. Left: colouring and
// scheduling in the parts loop (all 120 orders of col/h/j/k/rx and the col-loop block locals
// give 117 / 27).
// Round frC: 100 / 27. `he` (the hit-def walk pointer) was declared at its first use, so it was the
// last user variable and got the lowest node; declared first it is numbered above col/h/j/k/rx,
// which fixes the hit loop's colours. The parts loop is still off (the &oam[k]/pos temps and the
// post-allocation schedule).
// Round bgN: 76 / 27. The parts loop's `oam`/`pos` were block locals (the lowest user variables);
// declared at function level between `p` and `pe` (only that slot, of 132) they fix the pe/oam
// colours. Left: the col loop (rx, tbl + ry * 3, &oam[k], col) and the sx/sy block's schedule; a
// node-renumbering beam search finds no single moves under 28 wrong, so it is not one temp.

// Round bgW: 89 / 25 (raw / aligned-masked). Not moved; the 25 masked lines are the col loop's
// `tbl[ry * 3 + rx]` / `[sp]` reload placement and the sx/sy block, as bgN described.

extern "C" {

extern u8 data_ov000_021c9b60[];
extern u8 data_ov000_021c9b72[];
extern u8 data_ov000_021c9b7b[];
extern u8 data_ov000_021c9b69[];
extern s8 data_ov000_021c9acc[];
extern u8 data_ov000_021c9a9c[];
s32 FX_Div(s32 a, s32 b);

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 3;
    u32 hf : 1;
    u32 vf : 1;
    u32 c : 2;
} OamA01_52e4;

typedef struct {
    OamA01_52e4 a01;
    OamW2_02164c50 a23;
} Oam_52e4;

typedef struct {
    s32 x;
    s32 y;
} Pos_52e4;

typedef struct {
    Pos_52e4 *pos;
    Oam_52e4 *oam;
    s32 x;
    s32 y;
    u8 c[4];
} Part_52e4;

typedef struct {
    void *owner;
    s32 a;
    s32 b;
    s32 x;
    s32 y;
    u8 c;
    u8 pad[3];
} Hit_52e4;

typedef struct {
    s32 x;
    s32 y;
    u8 c[4];
} PartDef_52e4;

typedef struct {
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    u8 c;
    u8 pad[3];
} HitDef_52e4;

typedef struct Def_52e4 {
    u8 pad0[4];
    u8 w;
    u8 h;
    u8 nHit;
    u8 nPart;
    HitDef_52e4 hits[1];
} Def_52e4;


typedef struct Out_52e4 {
    u8 pad0[4];
    u16 unk_04;
    u8 w;
    u8 h;
    u8 slot;
    u8 n;
    u8 nPart;
    u8 nHit;
    Pos_52e4 *pos;
    Oam_52e4 *oam;
    Part_52e4 *parts;
    Hit_52e4 *hits;
} Out_52e4;

#define D_CNT_52e4 LFLD(u8, d, 1)
#define D_OAM_52e4(i) (&((Oam_52e4 *)((u8 *)d + 0x2c))[i])
#define D_POS_52e4(i) (&((Pos_52e4 *)((u8 *)d + 0x65c))[i])

void func_ov000_021652e4(void *self, u8 *d, Out_52e4 *o, const Def_52e4 *def) {
    const HitDef_52e4 *he;
    s32 col; Hit_52e4 *h; s32 j; s32 k; s32 rx;
    Oam_52e4 tmpl = *D_OAM_52e4(0);
    s32 row;
    s32 x0;
    s32 y0;
    const u8 *tbl;
    u8 i;
    Part_52e4 *p;
    Oam_52e4 *oam;
    Pos_52e4 *pos;
    const PartDef_52e4 *pe;
    if (def->w == 1) {
        if (def->h == 1) {
            tbl = data_ov000_021c9b60;
        } else {
            tbl = data_ov000_021c9b72;
        }
    } else {
        if (def->h == 1) {
            tbl = data_ov000_021c9b7b;
        } else {
            tbl = data_ov000_021c9b69;
        }
    }
    o->pos = D_POS_52e4(D_CNT_52e4);
    o->oam = D_OAM_52e4(D_CNT_52e4);
    o->n = 0;
    o->unk_04 = 0;
    o->w = def->w;
    o->h = def->h;
    x0 = -((o->w * 8) >> 1);
    y0 = -((o->h * 8) >> 1);
    for (row = 0; row < def->h; row++) {
        s32 ry = row == 0 ? 0 : (row == def->h - 1 ? 2 : 1);
        for (col = 0; col < def->w; col++) {
            rx = col == 0 ? 0 : (col == def->w - 1 ? 2 : 1);
            u8 t;
            k = o->n;
            Oam_52e4 *oam = o->oam;
            Pos_52e4 *pos = o->pos;
            oam[k] = tmpl;
            pos[k].x = x0 + col * 8;
            pos[k].y = y0 + row * 8;
            oam[k].a01.x = (u16)pos[k].x;
            t = (tbl[ry * 3 + rx]);
            oam[k].a01.y = (u16)pos[k].y & 0x1ff;
            oam[k].a23.tile += (t & ~0xc0) - 1;
            oam[k].a23.pal = LFLD(s8 *, d, 0xc90)[oam[k].a23.pal];
            if (t & 0x40) {
                oam[k].a01.hf = 1;
            }
            if (tbl[ry * 3 + rx] & 0x80) {
                oam[k].a01.vf = 1;
            }
            o->n++;
        }
    }
    D_CNT_52e4 += o->n;
    o->nPart = def->nPart;
    o->parts = &LFLD(Part_52e4 *, d, 0xc7c)[LFLD(u8, d, 6)];
    pe = (const PartDef_52e4 *)def->hits;
    if (def->nHit != 0) {
        pe = (const PartDef_52e4 *)&def->hits[def->nHit];
    }
    p = o->parts;
    for (i = 0; i < def->nPart; i++) {
        s32 ax;
        s32 ay;
        u8 t;
        p->pos = D_POS_52e4(D_CNT_52e4);
        pos = p->pos;
        p->oam = D_OAM_52e4(D_CNT_52e4);
        oam = p->oam;
        p->c[0] = pe->c[0];
        p->c[1] = pe->c[1];
        p->c[2] = pe->c[2];
        p->c[3] = pe->c[3];
        *oam = tmpl;
        ax = FX_Div(pe->x, 0x1000);
        ay = FX_Div(pe->y, 0x1000);
        ax = LO_FX_MUL(ax, 0x8000);
        p->x = ax >> 12;
        ay = LO_FX_MUL(ay, 0x8000);
        p->y = ay >> 12;
        {
        s32 sx = data_ov000_021c9acc[pe->c[0] * 2] + (ax >> 12);
        s32 sy = data_ov000_021c9acc[pe->c[0] * 2 + 1] + (ay >> 12);
        pos->y = sy;
        t = data_ov000_021c9a9c[pe->c[0]];
        pos->x = sx;
        }
        oam->a01.x = (u16)pos->x;
        oam->a01.y = (u16)pos->y & 0x1ff;
        oam->a23.tile += (t & ~0xc0) - 1;
        oam->a23.pal = LFLD(s8 *, d, 0xc90)[oam->a23.pal];
        if (t & 0x40) {
            oam->a01.hf = 1;
        }
        if (data_ov000_021c9a9c[pe->c[0]] & 0x80) {
            oam->a01.vf = 1;
        }
        p++;
        D_CNT_52e4 = D_CNT_52e4 + 1;
        pe = (const PartDef_52e4 *)((u8 *)pe + 0xc);
    }
    LFLD(u8, d, 6) += o->nPart;
    o->nHit = def->nHit;
    h = &LFLD(Hit_52e4 *, d, 0xc80)[LFLD(u8, d, 7)];
    o->hits = h;
    he = def->hits;
    for (j = 0; j < o->nHit; j++) {
        u8 c = he->c;
        LFLD(Hit_52e4 **, LFLD(u8 *, d, 0xc88) + c * 8, 4)[o->slot] = h;
        h->owner = o;
        h->a = he->a;
        h->c = c;
        h->b = he->b;
        {
            s32 hy;
            s32 hx = FX_Div(he->x, 0x1000);
            hy = FX_Div(he->y, 0x1000);
            h->x = (LO_FX_MUL(hx, 0x8000) >> 12) + 0x80;
            h->y = (LO_FX_MUL(hy, 0x8000) >> 12) + 0x58;
        }
        he += 1;
        h++;
    }
    LFLD(u8, d, 7) += o->nHit;
}

}
#endif
