#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

void func_ov015_0220064c(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b);
void func_ov015_0220a058(Ov015Fish *b, Ov015Vec *out);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015Vec *v);
void func_ov015_02207c30(Ov015Ship *p);
BOOL func_ov015_02209790(Ov015Fish *self, s32 a);

BOOL func_ov015_022003ec(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b, Ov015CamPair *c) {
    Ov015Vec v;
    Ov015Vec w;
    Ov015Vec u;
    BOOL ok = TRUE;
    Ov015Stat *g;
    s32 m;
    s32 n;
    g = &Dup::data_ov015_0221332c;
    if (data_ov015_0221332c.unk_00 >= 0x3e8000) {
        ok = FALSE;
        g->unk_30 = ok;
    }
    if (g->unk_00 < 0x1000) {
        ok = FALSE;
        g->unk_30 = TRUE;
    }
    if (!ok) return ok;
    func_ov015_0220064c(self, a, b);
    m = g->unk_14;
    n = g->unk_10;
    if ((m == 3 && n == 2) || (m == 2 && n == 3) || (m == 4 && n == 4) || (m != 1 && m != 0 && n == 1)) {
        if ((self->unk_0c >> 32) % 10 == 0) {
            c->cam0.unk_99 = 1;
            c->cam0.unk_9a = 10;
            c->cam0.unk_9b = 10;
            c->cam0.unk_9c.b2 = 1;
            c->cam0.unk_9c.b3 = 1;
            c->cam0.unk_9c.b4 = 0;
            c->cam1.unk_99 = 1;
            c->cam1.unk_9a = 10;
            c->cam1.unk_9b = 10;
            c->cam1.unk_9c.b2 = 1;
            c->cam1.unk_9c.b3 = 1;
            c->cam1.unk_9c.b4 = 0;
        }
    }
    if (g->unk_28 == 3) {
        func_ov015_021fd00c(c, 3, &b->unk_40);
    } else if (g->unk_08 == 3) {
        func_ov015_0220a058(b, &v);
        {
            s32 y = v.y;
            if (y < 0) y = 0;
            v.y = y;
        }
        func_ov015_021fd00c(c, 2, &v);
    } else if (g->unk_08 == 4) {
        func_ov015_0220a058(b, &w);
        func_ov015_021fd00c(c, 4, &w);
    } else {
        func_ov015_021fd00c(c, 0, &b->unk_40);
    }
    {
        Ov015VecC t(*(Ov015VecC *)&b->unk_40);
        t.y += 0x8000;
        *(Ov015VecC *)&a->unk_d4c = t;
    }
    if (self->unk_04 != NULL) {
        if (g->unk_00 > 0x96000) {
            FLD(s32, self->unk_04, 0xd4) = 1;
            {
                Ov015Ship *p = self->unk_24;
                u.x = p->unk_d08.x;
                u.y = p->unk_d08.y;
                u.z = p->unk_d08.z;
            }
            VCALL(self->unk_04)->v18(&u);
        } else {
            VCALL(self->unk_04)->v08(0);
        }
    }
    func_ov015_02207c30(a);
    func_ov015_02209790(b, 1);
    self->unk_0c += 0x1000;
    if (self->unk_0c > 0x70000000) self->unk_0c = 0x70000000;
    return ok;
}


extern u8 *data_02097dc8;
extern void *data_02097e4c;
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
Ov015V *func_02065f88(s32 id, void *pos);
void func_ov015_02200a18(Ov015Obj34 *self, Ov015Stat *g);
s32 func_ov015_022090bc(Ov015FishInfo *p);
s32 func_ov015_02200d50(Ov015Obj34 *self, Ov015Stat *g, s32 v);
s32 func_ov015_02200ec8(Ov015Obj34 *self, Ov015Stat *g, s32 v);

static inline s32 Ov015B_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov015_0220064c(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b) {
    u8 *pad = data_02097dc8;
    u16 trg = FLD(u16, pad, 0x12);
    u16 cont = FLD(u16, pad, 0x10);
    Ov015Stat *g = &data_ov015_0221332c;
    s32 dir;
    s32 lim;
    s32 mn;
    if (trg & 1) {
        self->unk_10 = 6;
    } else {
        s32 t = self->unk_10;
        self->unk_10 = t > -0x3c ? t - 1 : -0x3c;
    }
    if (g->unk_28 == 3) {
        self->unk_10 = -0x3c;
    }
    if (self->unk_10 == 6) {
        func_02049a48(data_02097e4c, 0, 0x7f, -1, -1);
        // m[3] as a byte offset from the matrix: a field path folds to one constant and changes the code.
        func_02065f88(0x6d, &FLD(Ov015Vec, &a->unk_cd4, 0x24))->v14(0x800, 0x800, 0x800);
    }
    g->unk_1c = self->unk_10 > 0;
    g->unk_1d = self->unk_10 == 6;
    if (g->unk_1c) {
        g->unk_20 += 0x1000;
        if (g->unk_20 > 0x3e8000) {
            g->unk_20 = 0x3e8000;
        }
    } else {
        g->unk_20 = 0;
    }
    if (cont & 0x20) {
        a->unk_d3a = 2;
        dir = 3;
    } else if (cont & 0x10) {
        a->unk_d3a = 1;
        dir = 2;
    } else if (cont & 0x80) {
        a->unk_d3a = 3;
        dir = 4;
    } else {
        a->unk_d3a = 0;
        dir = 1;
    }
    if (g->unk_28 == 3) {
        dir = 1;
    }
    if (dir == 1) {
        g->unk_18 = 0;
    } else if (g->unk_14 == dir) {
        g->unk_18 = g->unk_18 + (g->unk_18 < 0x3e8000 ? 0x1000 : 0);
    } else {
        g->unk_18 = 0x1000;
    }
    g->unk_14 = dir;
    g->unk_08 = b->unk_f4;
    g->unk_0c = b->unk_c0.unk_1c;
    g->unk_10 = b->unk_bc;
    func_ov015_02200a18(self, g);
    lim = func_ov015_022090bc(&self->unk_28->unk_c0);
    mn = self->unk_30->unk_18;
    switch (self->unk_28->unk_f4) {
    case 2:
        self->unk_18 = func_ov015_02200d50(self, g, self->unk_18);
        break;
    case 3: {
        s32 v = self->unk_18;
        if (g->unk_28 == 0 && g->unk_1c) {
            v -= 0x1ec;
        } else {
            v = Ov015B_FxMul64(v, 0xe66);
        }
        self->unk_18 = v;
        break;
    }
    case 4:
        self->unk_18 = func_ov015_02200ec8(self, g, self->unk_18);
        break;
    }
    if (self->unk_18 < lim) {
        lim = self->unk_18;
    }
    self->unk_18 = lim;
    if (lim > mn) {
        mn = lim;
    }
    self->unk_18 = mn;
    a->unk_d3e = -mn;
    if (a->unk_d48 == 1) {
        s32 m = g->unk_14;
        s32 n = g->unk_10;
        BOOL ok = TRUE;
        if (!((m == 3 && n == 2) || (m == 2 && n == 3) || (m == 4 && n == 4) || (m != 1 && m != 0 && n == 1))) {
            if (g->unk_08 != 3) {
                ok = FALSE;
            }
        }
        {
            s32 v70 = b->unk_70;
            a->unk_d42 = (ok & (self->unk_10 > -0x1e)) ? 1 : 0;
            a->unk_d44 = v70;
        }
    }
    {
        s32 cur = g->unk_00;
        s32 nv = cur + self->unk_18;
        if (nv < 0) {
            nv = 0;
        }
        if (nv > 0x3e8000) {
            nv = 0x3e8000;
        }
        g->unk_00 = nv;
        g->unk_04 = nv - cur;
        if (nv >= 0x2bc000 && (self->unk_0c >> 12) % 60 == 0) {
            func_02049a48(data_02097e4c, 0x37, -1, -1, -1);
        }
    }
    g->unk_2c = self->unk_0c >> 12;
    b->unk_c0.unk_28 = self->unk_0c;
}

}
