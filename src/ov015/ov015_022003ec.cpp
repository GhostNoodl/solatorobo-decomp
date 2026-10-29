#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

void func_ov015_0220064c(u8 *self, u8 *a, u8 *b);
void func_ov015_0220a058(u8 *b, Ov015Vec *out);
void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015Vec *v);
void func_ov015_02207c30(u8 *p);
BOOL func_ov015_02209790(u8 *self, s32 a);

struct Ov015Bits8a0 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
};

BOOL func_ov015_022003ec(u8 *self, u8 *a, u8 *b, u8 *c) {
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
        if ((FLD(s32, self, 0xc) >> 32) % 10 == 0) {
            FLD(u8, c, 0x9d) = 1;
            FLD(u8, c, 0x9e) = 10;
            FLD(u8, c, 0x9f) = 10;
            FLD(Ov015Bits8a0, c, 0xa0).b2 = 1;
            FLD(Ov015Bits8a0, c, 0xa0).b3 = 1;
            FLD(Ov015Bits8a0, c, 0xa0).b4 = 0;
            FLD(u8, c, 0x159) = 1;
            FLD(u8, c, 0x15a) = 10;
            FLD(u8, c, 0x15b) = 10;
            FLD(Ov015Bits8a0, c, 0x15c).b2 = 1;
            FLD(Ov015Bits8a0, c, 0x15c).b3 = 1;
            FLD(Ov015Bits8a0, c, 0x15c).b4 = 0;
        }
    }
    if (g->unk_28 == 3) {
        func_ov015_021fd00c(c, 3, &FLD(Ov015Vec, b, 0x40));
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
        func_ov015_021fd00c(c, 0, &FLD(Ov015Vec, b, 0x40));
    }
    {
        Ov015VecC t(FLD(Ov015VecC, b, 0x40));
        t.y += 0x8000;
        FLD(Ov015VecC, a, 0xd4c) = t;
    }
    if (FLD(u8 *, self, 0x4) != NULL) {
        if (g->unk_00 > 0x96000) {
            FLD(s32, FLD(u8 *, self, 0x4), 0xd4) = 1;
            {
                u8 *p = FLD(u8 *, self, 0x24);
                u.x = FLD(s32, p, 0xd08);
                u.y = FLD(s32, p, 0xd0c);
                u.z = FLD(s32, p, 0xd10);
            }
            VCALL(FLD(u8 *, self, 0x4))->v18(&u);
        } else {
            VCALL(FLD(u8 *, self, 0x4))->v08(0);
        }
    }
    func_ov015_02207c30(a);
    func_ov015_02209790(b, 1);
    FLD(s32, self, 0xc) += 0x1000;
    if (FLD(s32, self, 0xc) > 0x70000000) FLD(s32, self, 0xc) = 0x70000000;
    return ok;
}


extern u8 *data_02097dc8;
extern void *data_02097e4c;
void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
Ov015V *func_02065f88(s32 id, void *pos);
void func_ov015_02200a18(u8 *self, Ov015Stat *g);
s32 func_ov015_022090bc(u8 *p);
s32 func_ov015_02200d50(u8 *self, Ov015Stat *g, s32 v);
s32 func_ov015_02200ec8(u8 *self, Ov015Stat *g, s32 v);

struct Ov015Cam0c {
    u8 pad[0x24];
    Ov015Vec pos;
};

static inline s32 Ov015B_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov015_0220064c(u8 *self, u8 *a, u8 *b) {
    u8 *pad = data_02097dc8;
    u16 trg = FLD(u16, pad, 0x12);
    u16 cont = FLD(u16, pad, 0x10);
    Ov015Stat *g = &data_ov015_0221332c;
    s32 dir;
    s32 lim;
    s32 mn;
    if (trg & 1) {
        FLD(s32, self, 0x10) = 6;
    } else {
        s32 t = FLD(s32, self, 0x10);
        FLD(s32, self, 0x10) = t > -0x3c ? t - 1 : -0x3c;
    }
    if (g->unk_28 == 3) {
        FLD(s32, self, 0x10) = -0x3c;
    }
    if (FLD(s32, self, 0x10) == 6) {
        func_02049a48(data_02097e4c, 0, 0x7f, -1, -1);
        func_02065f88(0x6d, &FLD(Ov015Cam0c, a + 0xcd4, 0).pos)->v14(0x800, 0x800, 0x800);
    }
    g->unk_1c = FLD(s32, self, 0x10) > 0;
    g->unk_1d = FLD(s32, self, 0x10) == 6;
    if (g->unk_1c) {
        g->unk_20 += 0x1000;
        if (g->unk_20 > 0x3e8000) {
            g->unk_20 = 0x3e8000;
        }
    } else {
        g->unk_20 = 0;
    }
    if (cont & 0x20) {
        FLD(u16, a, 0xd3a) = 2;
        dir = 3;
    } else if (cont & 0x10) {
        FLD(u16, a, 0xd3a) = 1;
        dir = 2;
    } else if (cont & 0x80) {
        FLD(u16, a, 0xd3a) = 3;
        dir = 4;
    } else {
        FLD(u16, a, 0xd3a) = 0;
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
    g->unk_08 = FLD(s32, b, 0xf4);
    g->unk_0c = FLD(s32, b, 0xdc);
    g->unk_10 = FLD(s32, b, 0xbc);
    func_ov015_02200a18(self, g);
    lim = func_ov015_022090bc(FLD(u8 *, self, 0x28) + 0xc0);
    mn = FLD(s32, FLD(u8 *, self, 0x30), 0x18);
    switch (FLD(s32, FLD(u8 *, self, 0x28), 0xf4)) {
    case 2:
        FLD(s32, self, 0x18) = func_ov015_02200d50(self, g, FLD(s32, self, 0x18));
        break;
    case 3: {
        s32 v = FLD(s32, self, 0x18);
        if (g->unk_28 == 0 && g->unk_1c) {
            v -= 0x1ec;
        } else {
            v = Ov015B_FxMul64(v, 0xe66);
        }
        FLD(s32, self, 0x18) = v;
        break;
    }
    case 4:
        FLD(s32, self, 0x18) = func_ov015_02200ec8(self, g, FLD(s32, self, 0x18));
        break;
    }
    if (FLD(s32, self, 0x18) < lim) {
        lim = FLD(s32, self, 0x18);
    }
    FLD(s32, self, 0x18) = lim;
    if (lim > mn) {
        mn = lim;
    }
    FLD(s32, self, 0x18) = mn;
    FLD(s16, a, 0xd3e) = -mn;
    if (FLD(u16, a, 0xd48) == 1) {
        s32 m = g->unk_14;
        s32 n = g->unk_10;
        BOOL ok = TRUE;
        if (!((m == 3 && n == 2) || (m == 2 && n == 3) || (m == 4 && n == 4) || (m != 1 && m != 0 && n == 1))) {
            if (g->unk_08 != 3) {
                ok = FALSE;
            }
        }
        {
            s32 v70 = FLD(s32, b, 0x70);
            FLD(u8, a, 0xd42) = (ok & (FLD(s32, self, 0x10) > -0x1e)) ? 1 : 0;
            FLD(s32, a, 0xd44) = v70;
        }
    }
    {
        s32 cur = g->unk_00;
        s32 nv = cur + FLD(s32, self, 0x18);
        if (nv < 0) {
            nv = 0;
        }
        if (nv > 0x3e8000) {
            nv = 0x3e8000;
        }
        g->unk_00 = nv;
        g->unk_04 = nv - cur;
        if (nv >= 0x2bc000 && (FLD(s32, self, 0xc) >> 12) % 60 == 0) {
            func_02049a48(data_02097e4c, 0x37, -1, -1, -1);
        }
    }
    g->unk_2c = FLD(s32, self, 0xc) >> 12;
    FLD(s32, b, 0xe8) = FLD(s32, self, 0xc);
}

}
