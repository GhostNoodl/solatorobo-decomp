#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

void func_ov015_0220064c(u8 *self, u8 *a, u8 *b);
void func_ov015_0220a058(u8 *b, Ov015Vec *out);
void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015Vec *v);
void func_ov015_02207c30(u8 *p);
void func_ov015_02209790(u8 *self, s32 a);

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

}
