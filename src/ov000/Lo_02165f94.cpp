#include "ov000/FieldCam.h"
#include "ov000/LoCommon.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "Main/Sys/Pad.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MapCtx.h"
#include "nitro/mi.h"

extern "C" {

extern u8 NNS_G3dGlb[];
extern u8 data_02092844[];
extern u8 data_02092800[];
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

static inline BOOL LoAnimValid(LoAnimC *p) {
    if (p == NULL || p->state == 0) {
        return FALSE;
    }
    return TRUE;
}

u8 *func_ov000_02165f94(Lo021cb6b0 *self) {
    LoAnimC *p = self->unk_30->anim;
    FieldState *g = data_ov000_021ccd54;
    if (!LoAnimValid(p)) {
        return g->unk_ca.c;
    }
    if (data_02097dc8->trig & 2) {
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
    p->rgb[0] = g->unk_ca.c[0];
    p->rgb[1] = g->unk_ca.c[1];
    p->rgb[2] = p->frames[p->idx]->slot;
    return p->rgb;
}

Node0216607c *func_ov000_0216607c(Lo021cb6b0 *self, Node0216607c *node, u8 *outIdx, BOOL deep) {
    Ctx0216607c *ctx = self->unk_30;
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
// Status (round drA): func_ov000_02166180 is 27 / 0 (raw / register-masked, dsi/1.3 with the project flags); this is
// the best clean draft. Blocker: register-only: oams and the j value swap (the j value is an IRO temp, numbered
// below every user variable). History: docs/MATCHING.md rounds dgB, bgL, bgN, raB, raF, mtA, cvA (search for the
// address); the full list is docs/UNMATCHED.md.
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
// Round bgY: the busy-list header at p->0xcdc is LoAnimC (02165f94's type: frames at 0x88, cnt at 0x108,
// state at 0x10a), so the draft now uses it instead of a private Hdr6180 (27 / 0, same code). Testing the
// flag through 02165f94's LoAnimValid inline is 62 (busy = ...; the ROM's moveq/movne/and #0xff needs the
// if/else on a u8) or 652 (if (!LoAnimValid(..)) busy = FALSE; else ...).
// Round rgB: tools/vnum.sh: oams is a user local (node 145, band 7) and the j value is a CSE temp (node 88, band 4;
// j lives in memory because &j goes to 0216607c). Searching only merges/renumberings that touch these two (single
// moves, and pair renumberings at every 4th position) finds nothing. Moving oams to a lower band also fails: a
// split web (o or ob reused in the first loop) is 345-357, and a Parts struct for r's pos/oams pair at 0xc/0x10 (fields
// or a struct copy, first loop or both loops) is 111-357, because oams then takes r7 and the whole function shifts.

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Ent6180;

extern "C" {
typedef struct { s8 dx; s8 dy; u16 hf : 1; u16 vf : 1; u16 idx : 4; } Dir2_6180;
extern const Dir2_6180 data_ov000_021c9b40[];
extern const s8 data_ov000_021c9b41[];
Robo021ca458 *func_ov000_0219bf90(void);

static inline void SetXY6180(MapOam *o, u16 x, u16 y) {
    o->w0.x = x;
    o->w0.y = y & 0x1ff;
}

#define PUTM(o, X, Y) if ((X) < 8 || (X) > 0xf8 || (Y) < 8 || (Y) > 0xb8) { SetXY6180(o, 0, 0xc0); } else { SetXY6180(o, X, Y); }
static inline MapOam *OamAt6180(MapOam *o, u32 j) {
    return &o[j];
}

static inline u32 PalIdx6180(Ctx0216607c *p) {
    return p->oams[0].w1.pal;
}

static inline Node0216607c *FindNode6180(Lo021cb6b0 *self, u8 c, u8 d) {
    Ctx0216607c *q = self->unk_30;
    u8 n = q->count;
    Node0216607c *e = q->nodes;
    u32 s;
    for (s = 0; s < n; s = (u8)(s + 1), e++) {
        if (c == e->a && d == e->b) {
            return e;
        }
    }
    return NULL;
}

static inline Node0216607c *GetNode6180(Lo021cb6b0 *self, u8 d) {
    Ctx0216607c *q = self->unk_30;
    if (d >= q->count) {
        return NULL;
    }
    return &q->nodes[d];
}

void func_ov000_02166180(Lo021cb6b0 *self) {
    s16 y;
    Item0216607c *e;
    MapOam *oams;
    s32 oy;
    LoAnimC *h;
    u8 sec;
    MapOam *o;
    s32 ox;
    MapPart *pt;
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
    Node0216607c *nd;
    s16 x;
    FieldState *g;
    Ctx0216607c *p;
    Node0216607c *r;
    Node0216607c *en;
    s32 yy;
    Robo021ca458 *pl;
    s8 *pal;
    MapOam *ob;
    FieldCam *cam;
    Slot0216607c *anim;
    u8 d;
    s32 off;
    u8 i;
    u8 busy;
    Item0216607c *it;


    p = self->unk_30;
    tbl2 = (Ent6180 *)data_0214a424->slots;
    kind = p->cur->key;
    anim = &p->slots[kind];
    g = data_ov000_021ccd54;
    if (p->anim == NULL || p->anim->state == 0) {
        busy = FALSE;
    } else {
        busy = TRUE;
    }
    ox = p->ox;
    oy = p->oy;
    pal = p->pltt->maps[2];
    p->markCount = 0;
    SetXY6180(&p->unk_0c, 0, 0xc0);
    for (i = 0; i < p->count; i++) {
        s32 ex;
        s32 ey;
        MapPos *pos;
        e = anim->list[i];
        if (e == NULL) {
            continue;
        }
        ex = e->a - (ox >> 12);
        ey = e->b - (oy >> 12);
        r = e->node;
        if (busy) {
            f = r == p->sel;
        } else {
            f = r->a == g->unk_ca.c[1] && r->b == g->unk_ca.c[2];
        }
        if (f) {
            for (j = 0; j < r->nPart; j++) {
                pt = &r->parts[j];
                pos = pt->pos;
                o = pt->oam;
                xx = pos->x + ex; yy = pos->y + ey; PUTM(o, xx, yy)
                o->w1.pal = pal[PalIdx6180(p)];
            }
        }
        oams = r->oam;
        pos = r->pos;
        for (j = 0; j < r->n; j++) {
            yy = pos[j].y;
            xx = pos[j].x;
            yy += ey;
            xx += ex;
            if (xx < 8 || xx > 0xf8 || yy < 8 || yy > 0xb8) {
                SetXY6180(OamAt6180(oams, j), 0, 0xc0);
            } else {
                SetXY6180(OamAt6180(oams, j), xx, yy);
            }
            if (r->a == g->unk_ca.c[1] && r->b == g->unk_ca.c[2]) {
                xx = ex - 4; yy = ey - 4; PUTM(&p->unk_0c, xx, yy)
                p->unk_0c.w1.pal = *(p->palMap + PalIdx6180(p) - 2);
                OamAt6180(oams, j)->w1.pal = pal[PalIdx6180(p)];
            } else if (r->f0) {
                OamAt6180(oams, j)->w1.pal = *(p->palMap + PalIdx6180(p) + 2);
            } else if (r->f2) {
                OamAt6180(oams, j)->w1.pal = *(p->palMap + PalIdx6180(p) + 1);
            } else {
                OamAt6180(oams, j)->w1.pal = p->palMap[PalIdx6180(p)];
            }
        }
    }
    if (busy) {
        h = self->unk_30->anim;
        for (i = 0; i < h->cnt; i++) {
            r = h->frames[i];
            off = (i == h->cnt - 1) ? 0 : 2;
            for (j = 0; j < r->nPart; j++) {
                o = r->parts[j].oam;
                o->w1.pal = (pal + off)[PalIdx6180(p)];
            }
            oams = r->oam;
            for (j = 0; j < r->n; j++) {
                oams[j].w1.pal = (pal + off)[PalIdx6180(p)];
            }
        }
        nd = func_ov000_0216607c(self, h->frames[0], &j, TRUE);
        if (nd != NULL) {
            k = p->markCount++;
            o = &p->marks[k];
            *o = p->unk_1c;
            it = &nd->items[j];
            xx = it->a - (ox >> 12) - 4; yy = it->b - (oy >> 12) - 0xc; PUTM(o, xx, yy)
            o->w0.raw = (o->w0.raw & 0x3fff3fff) | 0x40000000;
            o->w1.pal = *(p->palMap + PalIdx6180(p) - 2);
        }
    } else {
        for (i = 0; i < 2; i++) {
            if (tbl2[i].a == 0xff || tbl2[i].a == 2) {
                continue;
            }
            if (LFLD(u8, p, 4) != tbl2[i].b) {
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
            nd = func_ov000_0216607c(self, en, &j, FALSE);
            if (nd == NULL) {
                continue;
            }
            k = p->markCount++;
            o = &p->marks[k];
            *o = p->unk_1c;
            if (p->sel->f3) {
                continue;
            }
            it = &nd->items[j];
            xx = it->a - (ox >> 12) - 4; yy = it->b - (oy >> 12) - 0xc; PUTM(o, xx, yy)
            switch (tbl2[i].a) {
            case 0:
            case 1:
                o->w0.raw = (o->w0.raw & 0x3fff3fff) | 0x40000000;
                o->w1.pal = *(p->palMap + PalIdx6180(p) - 2);
                break;
            }
        }
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL && p->sel != NULL) {
        cam = &data_ov000_021ccd54->cam;
        if (!p->sel->f3) {
            xx = p->unk_0c.w0.x;
            yy = p->unk_0c.w0.y;
            pa = pl->rot_y;
            ca = FieldCam_GetYaw(cam);
            a = ca - pa;
        } else {
            a = 0x8000 - pl->rot_y;
            xx = 0x7c;
            yy = 0x64;
        }
        sec = ((a + 0x1000) / 0x2000) & 7;
        x = xx + data_ov000_021c9b40[sec].dx;
        y = yy + data_ov000_021c9b41[sec * 4];
        ob = &p->unk_14;
        ob->w1.pal = *(p->palMap + PalIdx6180(p) - 2);
        SetXY6180(ob, x, y);
        ob->w0.hf = data_ov000_021c9b40[sec].hf;
        ob->w0.vf = data_ov000_021c9b40[sec].vf;
        ob->w1.tile = p->tiles[data_ov000_021c9b40[sec].idx];
    }
}

}
#endif
