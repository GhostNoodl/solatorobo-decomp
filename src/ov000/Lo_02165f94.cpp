#include "ov000/LoCommon.h"

extern "C" {

extern u8 NNS_G3dGlb[];
extern u8 data_02092844[];
extern u8 data_02092800[];
extern u8 *data_ov000_021ccd54;
extern u8 *data_02097dc8;
void MTX_LookAt(void *a, void *b, void *c, void *d);
void MIi_CpuCopyFast(void *a, void *b, s32 c);
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

typedef struct LoAnimC {
    u8 rgb[4];
    u8 pad[0x84];
    u8 *frames[0x20];
    u8 cnt;
    u8 pad2;
    u16 state;
    u16 idx;
    u16 timer;
    u16 period;
} LoAnimC;

static inline BOOL LoAnimValid(LoAnimC *p) {
    if (p == NULL || p->state == 0) {
        return FALSE;
    }
    return TRUE;
}

u8 *func_ov000_02165f94(void *self) {
    LoAnimC *p = LFLD(LoAnimC *, LFLD(u8 *, self, 0x30), 0xcdc);
    u8 *g = data_ov000_021ccd54;
    if (!LoAnimValid(p)) {
        return g + 0xca;
    }
    if (LFLD(u16, data_02097dc8, 0x12) & 2) {
        p->timer = p->period;
        p->idx = 0;
    }
    p->timer++;
    if (p->timer >= p->period) {
        p->timer = 0;
        u16 i = p->idx;
        if ((u16)(i - 2) < p->cnt) {
            p->idx -= 2;
        } else if (i != 0) {
            p->idx = 0;
        } else {
            p->state = 0xffff;
        }
    }
    p->rgb[0] = g[0xca];
    p->rgb[1] = g[0xcb];
    p->rgb[2] = p->frames[p->idx][8];
    return p->rgb;
}

typedef struct Item0216607c Item0216607c;

typedef struct {
    u8 pad_00[0xb];
    u8 count;
    u8 pad_0c[0xc];
    Item0216607c *items;
} Node0216607c;

struct Item0216607c {
    Node0216607c *node;
    u8 pad_04[8];
    s32 a;
    s32 b;
    u8 key;
    u8 pad_15[3];
};

typedef struct {
    u32 unk_00;
    Item0216607c **list;
} Slot0216607c;

typedef struct {
    u8 pad_00[8];
    u8 count;
    u8 pad_09[0xc7f];
    Slot0216607c *slots;
    u8 pad_c8c[0x28];
    Item0216607c *cur;
} Ctx0216607c;

Node0216607c *func_ov000_0216607c(void *self, Node0216607c *node, u8 *outIdx, BOOL deep) {
    Ctx0216607c *ctx = LFLD(Ctx0216607c *, self, 0x30);
    Item0216607c **lst;
    u8 i;
    u8 k;
    for (i = 0; i < node->count; i++) {
        if (ctx->cur->key == node->items[i].key) {
            *outIdx = i;
            return node;
        }
    }
    if (deep) {
        Slot0216607c *slot = &ctx->slots[ctx->cur->key];
        u8 n = ctx->count;
        // A hand-rotated loop: the list load sits after the entry check, as in the target.
        i = 0;
        if (i < n) {
            lst = slot->list;
            do {
                Item0216607c *it = lst[i];
                if (it != NULL && it->a == node->items->a && it->b == node->items->b) {
                    Node0216607c *nd = it->node;
                    for (k = 0; k < nd->count; k++) {
                        if (&nd->items[k] == it) {
                            *outIdx = k;
                            return it->node;
                        }
                    }
                }
            } while (++i < n);
        }
    }
    return NULL;
}

}

#ifdef NONMATCHING
// func_ov000_02166180: 27 / 0 (raw / register-masked), real signature, register colouring only.
// Rounds g6180, g6180b and vphase3 draft; round dgB reuses pos for the part's position pointer
// (was a separate ps), which gives pos the ROM's sl. Round bgL reuses r for the busy block's node
// and i for the busy and else loops (was n and m), which fixes the busy block. Left: oams/j and the
// &oams[j] address in the first oams loop; the colouring model needs the j value temp numbered above
// g/p and oams below ey, which no declaration order gives.
// Round bgN: with all three nodes free, every zero-miss numbering has the j value above g (130..145)
// and oams in the temp range below the &oams[j] temp. Toys show the j value is an IRO temp whenever
// it is used across blocks (named copies `jx = j`, u8 or s32, are turned into a temp too), and IRO
// temps are numbered below every user variable, so this needs a different structure, not an order.
// Round raB: 27 / 0. The second loop's OAM entries are reached through an OamAt6180 accessor
// (u32 index; a u8 index gives 31). That makes the j value the newest temp and gives &oams[j] the ROM's
// r8. Left: oams (r3, ROM sb) and the j value (sb, ROM r3) are swapped. bgN's placement search on the
// new graph still needs oams numbered among the temps (below &oams[j]) and the j value above g: a reused
// pointer (o or a fresh ob) for oams changes the code (360+), a PosAt accessor too gives 27 or 79.
// This file's .text ends at 0x02166180, so the function belongs here once it matches.
// Round raC (27 / 0): oams/pos from Oams/Poss getters, or the busy loop on o so oams has one
// definition, leave oams a user variable (node 145), so the jkH temp rule does not apply here.

typedef struct {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 3;
    u32 hf : 1;
    u32 vf : 1;
    u32 sz : 2;
} Oam0_6180;

typedef struct {
    u32 tile : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 hi : 16;
} Oam1_6180;

typedef struct {
    Oam0_6180 w0;
    Oam1_6180 w1;
} Oam6180;

typedef struct {
    u32 f0 : 1;
    u32 f1 : 1;
    u32 f2 : 1;
    u32 f3 : 2;
    u32 a : 8;
    u32 b : 8;
} RBits6180;

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
} QBits6180;

typedef struct {
    s32 x;
    s32 y;
} Pos6180;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Ent6180;

typedef struct {
    u8 pad_00[0x88];
    u8 *nodes[32];
    u8 count;
} Hdr6180;

extern "C" {
extern u8 *data_0214a424;
typedef struct { s8 dx; s8 dy; u16 hf : 1; u16 vf : 1; u16 idx : 4; } Dir2_6180;
extern const Dir2_6180 data_ov000_021c9b40[];
extern const s8 data_ov000_021c9b41[];
u8 *func_ov000_0219bf90(void);
u16 func_0204bfa8(void *cam);

static inline void SetXY6180(Oam6180 *o, u16 x, u16 y) {
    o->w0.x = x;
    o->w0.y = y & 0x1ff;
}

#define PUTM(o, X, Y) if ((X) < 8 || (X) > 0xf8 || (Y) < 8 || (Y) > 0xb8) { SetXY6180(o, 0, 0xc0); } else { SetXY6180(o, X, Y); }
static inline Oam6180 *OamAt6180(Oam6180 *o, u32 j) {
    return &o[j];
}

static inline BOOL Busy6180(u8 *self) {
    u8 *h = LFLD(u8 *, LFLD(u8 *, self, 0x30), 0xcdc);
    return h != NULL && LFLD(u16, h, 0x10a) != 0;
}

static inline u32 PalIdx6180(u8 *p) {
    return LFLD(Oam6180, p, 0x2c).w1.pal;
}

static inline u8 *FindNode6180(u8 *self, u8 c, u8 d) {
    u8 *q = LFLD(u8 *, self, 0x30);
    u8 n = q[8];
    u8 *e = LFLD(u8 *, q, 0xc84);
    u32 s;
    for (s = 0; s < n; s = (u8)(s + 1), e += 0x1c) {
        if (c == LFLD(RBits6180, e, 0).a && d == LFLD(RBits6180, e, 0).b) {
            return e;
        }
    }
    return NULL;
}

static inline u8 *GetNode6180(u8 *self, u8 d) {
    u8 *q = LFLD(u8 *, self, 0x30);
    if (d >= q[8]) {
        return NULL;
    }
    return LFLD(u8 *, q, 0xc84) + d * 0x1c;
}

void func_ov000_02166180(u8 *self) {
    s16 y;
    u8 *e;
    Oam6180 *oams;
    s32 oy;
    Hdr6180 *h;
    u8 sec;
    Oam6180 *o;
    s32 ox;
    u8 *pt;
    u16 a;
    u8 j;
    u8 kind;
    Ent6180 *tbl2;
    u16 ca;
    u16 pa;
    BOOL f;
    s32 xx;
    u8 k;
    u8 c;
    u8 *nd;
    s16 x;
    u8 *g;
    u8 *p;
    u8 *r;
    u8 *en;
    s32 yy;
    u8 *pl;
    s8 *pal;
    Oam6180 *ob;
    u8 *cam;
    u8 *anim;
    u8 d;
    s32 off;
    u8 i;
    u8 busy;
    u8 *it;


    p = LFLD(u8 *, self, 0x30);
    tbl2 = (Ent6180 *)(data_0214a424 + 0x60c);
    kind = LFLD(u8 *, p, 0xcb4)[0x14];
    anim = LFLD(u8 *, p, 0xc88) + kind * 8;
    g = data_ov000_021ccd54;
    if (LFLD(u8 *, p, 0xcdc) == NULL || LFLD(u16, LFLD(u8 *, p, 0xcdc), 0x10a) == 0) {
        busy = FALSE;
    } else {
        busy = TRUE;
    }
    ox = LFLD(s32, p, 0xcbc);
    oy = LFLD(s32, p, 0xcc0);
    pal = LFLD(s8 *, LFLD(u8 *, p, 0xc8c), 0x58);
    p[2] = 0;
    SetXY6180(&LFLD(Oam6180, p, 0xc), 0, 0xc0);
    for (i = 0; i < p[8]; i++) {
        s32 ex;
        s32 ey;
        Pos6180 *pos;
        e = LFLD(u8 **, anim, 4)[i];
        if (e == NULL) {
            continue;
        }
        ex = LFLD(s32, e, 0xc) - (ox >> 12);
        ey = LFLD(s32, e, 0x10) - (oy >> 12);
        r = LFLD(u8 *, e, 0);
        if (busy) {
            f = r == LFLD(u8 *, p, 0xcb8);
        } else {
            f = LFLD(RBits6180, r, 0).a == g[0xcb] && LFLD(RBits6180, r, 0).b == g[0xcc];
        }
        if (f) {
            for (j = 0; j < r[0xa]; j++) {
                pt = LFLD(u8 *, r, 0x14) + j * 0x14;
                pos = LFLD(Pos6180 *, pt, 0);
                o = LFLD(Oam6180 *, pt, 4);
                xx = pos->x + ex; yy = pos->y + ey; PUTM(o, xx, yy)
                o->w1.pal = pal[PalIdx6180(p)];
            }
        }
        oams = LFLD(Oam6180 *, r, 0x10);
        pos = LFLD(Pos6180 *, r, 0xc);
        for (j = 0; j < r[9]; j++) {
            yy = pos[j].y;
            xx = pos[j].x;
            yy += ey;
            xx += ex;
            if (xx < 8 || xx > 0xf8 || yy < 8 || yy > 0xb8) {
                SetXY6180(OamAt6180(oams, j), 0, 0xc0);
            } else {
                SetXY6180(OamAt6180(oams, j), xx, yy);
            }
            if (LFLD(RBits6180, r, 0).a == g[0xcb] && LFLD(RBits6180, r, 0).b == g[0xcc]) {
                xx = ex - 4; yy = ey - 4; PUTM(&LFLD(Oam6180, p, 0xc), xx, yy)
                LFLD(Oam6180, p, 0xc).w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) - 2);
                OamAt6180(oams, j)->w1.pal = pal[PalIdx6180(p)];
            } else if (LFLD(RBits6180, r, 0).f0) {
                OamAt6180(oams, j)->w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) + 2);
            } else if (LFLD(RBits6180, r, 0).f2) {
                OamAt6180(oams, j)->w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) + 1);
            } else {
                OamAt6180(oams, j)->w1.pal = LFLD(s8 *, p, 0xc90)[PalIdx6180(p)];
            }
        }
    }
    if (busy) {
        h = LFLD(Hdr6180 *, LFLD(u8 *, self, 0x30), 0xcdc);
        for (i = 0; i < h->count; i++) {
            r = h->nodes[i];
            off = (i == h->count - 1) ? 0 : 2;
            for (j = 0; j < r[0xa]; j++) {
                o = LFLD(Oam6180 *, LFLD(u8 *, r, 0x14) + j * 0x14, 4);
                o->w1.pal = (pal + off)[PalIdx6180(p)];
            }
            oams = LFLD(Oam6180 *, r, 0x10);
            for (j = 0; j < r[9]; j++) {
                oams[j].w1.pal = (pal + off)[PalIdx6180(p)];
            }
        }
        nd = (u8 *)func_ov000_0216607c(self, (Node0216607c *)h->nodes[0], &j, TRUE);
        if (nd != NULL) {
            k = p[2]++;
            o = &((Oam6180 *)(p + 0x64c))[k];
            *o = LFLD(Oam6180, p, 0x1c);
            it = LFLD(u8 *, nd, 0x18) + j * 0x18;
            xx = LFLD(s32, it, 0xc) - (ox >> 12) - 4; yy = LFLD(s32, it, 0x10) - (oy >> 12) - 0xc; PUTM(o, xx, yy)
            LFLD(u32, o, 0) = (LFLD(u32, o, 0) & 0x3fff3fff) | 0x40000000;
            o->w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) - 2);
        }
    } else {
        for (i = 0; i < 2; i++) {
            if (tbl2[i].a == 0xff || tbl2[i].a == 2) {
                continue;
            }
            if (p[4] != tbl2[i].b) {
                continue;
            }
            c = tbl2[i].c;
            d = tbl2[i].d;
            if (c != 0xff) {
                en = FindNode6180(self, c, d);
            } else {
                en = GetNode6180(self, d);
            }
            if (en == NULL) {
                continue;
            }
            nd = (u8 *)func_ov000_0216607c(self, (Node0216607c *)en, &j, FALSE);
            if (nd == NULL) {
                continue;
            }
            k = p[2]++;
            o = &((Oam6180 *)(p + 0x64c))[k];
            *o = LFLD(Oam6180, p, 0x1c);
            if (LFLD(QBits6180, LFLD(u8 *, p, 0xcb8), 0).b3) {
                continue;
            }
            it = LFLD(u8 *, nd, 0x18) + j * 0x18;
            xx = LFLD(s32, it, 0xc) - (ox >> 12) - 4; yy = LFLD(s32, it, 0x10) - (oy >> 12) - 0xc; PUTM(o, xx, yy)
            switch (tbl2[i].a) {
            case 0:
            case 1:
                LFLD(u32, o, 0) = (LFLD(u32, o, 0) & 0x3fff3fff) | 0x40000000;
                o->w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) - 2);
                break;
            }
        }
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL && LFLD(u8 *, p, 0xcb8) != NULL) {
        cam = data_ov000_021ccd54 + 0xf4;
        if (!LFLD(QBits6180, LFLD(u8 *, p, 0xcb8), 0).b3) {
            xx = LFLD(Oam6180, p, 0xc).w0.x;
            yy = LFLD(Oam6180, p, 0xc).w0.y;
            pa = LFLD(u16, pl, 0x7e);
            if (LFLD(u16, cam, 0x40) != 0) {
                ca = LFLD(u16, cam, 0x44);
            } else {
                ca = func_0204bfa8(cam);
            }
            a = ca - pa;
        } else {
            a = 0x8000 - LFLD(u16, pl, 0x7e);
            xx = 0x7c;
            yy = 0x64;
        }
        sec = ((a + 0x1000) / 0x2000) & 7;
        x = xx + data_ov000_021c9b40[sec].dx;
        y = yy + data_ov000_021c9b41[sec * 4];
        ob = &LFLD(Oam6180, p, 0x14);
        ob->w1.pal = *(LFLD(s8 *, p, 0xc90) + PalIdx6180(p) - 2);
        SetXY6180(ob, x, y);
        ob->w0.hf = data_ov000_021c9b40[sec].hf;
        ob->w0.vf = data_ov000_021c9b40[sec].vf;
        ob->w1.tile = LFLD(u16, p + data_ov000_021c9b40[sec].idx * 2, 0x24);
    }
}

}
#endif
