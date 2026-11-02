#include "ov015/ov015.h"

extern "C" {

void *func_02065f88(s32 id, void *pos);
s32 func_ov015_02200bf4(Ov015Obj34 *self, u8 *b, s32 c);
s32 func_ov015_022090f0(Ov015FishInfo *p);

void func_ov015_02200a18(Ov015Obj34 *self, u8 *b) {
    s32 spd = self->unk_1c;
    s32 pos = FLD(s32, b, 0x24);
    switch (FLD(s32, b, 0x28)) {
    case 3:
        spd = -0x666;
        if ((self->unk_0c >> 12) % 20 == 0) {
            Ov015V *e;
            func_02049a48(data_02097e4c, 0x59, -1, -1, -1);
            // m[3] as a byte offset from the matrix: a field path folds to one constant and changes the code.
            e = (Ov015V *)func_02065f88(0x325, &FLD(Ov015Vec, &self->ship->nodeMtx, 0x24));
            e->v14(0x800, 0x800, 0x800);
            FLD(s32, e, 0xd4) = 2;
        }
        if (pos <= 0) {
            pos = 0;
            FLD(s32, b, 0x28) = pos;
        }
        break;
    case 2:
        spd = -0x3000;
        if (--self->unk_14 <= 0) {
            self->unk_14 = 0;
            FLD(s32, b, 0x28) = 0;
        }
        break;
    case 1:
        if (pos >= 0x64000 && FLD(s32, b, 0x8) != 3) {
            FLD(s32, b, 0x28) = 3;
            func_02049a48(data_02097e4c, 0x1b, -1, -1, -1);
        } else if (pos < 0x46000) {
            FLD(s32, b, 0x28) = 0;
        }
        if ((self->unk_0c >> 12) % 10 == 0) {
            func_02049a48(data_02097e4c, 0x59, -1, -1, -1);
        }
        spd = func_ov015_02200bf4(self, b, spd);
        break;
    case 0:
        if (pos > 0x46000) {
            FLD(s32, b, 0x28) = 1;
            break;
        }
        spd = func_ov015_02200bf4(self, b, spd);
        break;
    }
    pos += spd;
    self->unk_1c = spd;
    if (pos < 0) {
        pos = 0;
    } else if (pos > 0x64000) {
        pos = 0x64000;
    }
    FLD(s32, b, 0x24) = pos;
}

s32 func_ov015_02200bf4(Ov015Obj34 *self, u8 *b, s32 c) {
    BOOL flag = TRUE;
    s32 base;
    s32 q, d, na, nb, ax, bx;
    Ov015Info38 *o;
    if (FLD(s32, b, 0x14) == 1) flag = FALSE;
    base = self->info->unk_30;
    d = func_ov015_022090f0(&self->fish->info) - base;
    if (d < 0x800) d = 0x800;
    q = d / 120;
    o = self->info;
    ax = o->unk_28;
    if (ax < 0) ax = -ax;
    na = -ax;
    bx = o->unk_2c;
    if (bx < 0) bx = -bx;
    nb = -bx;
    if (self->fish->stateId == 3) {
        c = na;
    } else if (FLD(u8, b, 0x1c) != 0) {
        s32 t3 = FLD(s32, b, 0x14);
        s32 t4 = FLD(s32, b, 0x10);
        if (!((t3 == 3 && t4 == 2) || (t3 == 2 && t4 == 3) || (t3 == 4 && t4 == 4) ||
            ((t3 != 1 && t3 != 0) && t4 == 1))) {
            self->unk_20 = 0;
            c = d;
        } else {
            if (c < 0x29) c = 0x29;
            if (self->unk_20 == 0) c = 0x29;
            c += q;
            self->unk_20 = self->unk_20 + 1;
        }
    } else if (self->unk_10 <= -5) {
        self->unk_20 = 0;
        c += nb;
        if (flag) {
            if (c < (na >> 1)) c = na >> 1;
        }
    }
    if (c <= d) d = c;
    if (d >= na) na = d;
    return na;
}

static inline s32 Ov015Stat_GetUnk14(Ov015Stat *g) {
    return g->unk_14;
}

s32 func_ov015_02200d50(Ov015Obj34 *self, Ov015Stat *g, s32 v) {
    s32 t3 = Ov015Stat_GetUnk14(g);
    s32 st = g->unk_28;
    s32 t4 = g->unk_10;
    u8 f = g->unk_1c;
    BOOL ok;
    switch (st) {
    case 3:
        v += 0x29;
        break;
    case 2:
        v = 0x999;
        break;
    default: {
        if (f) {
            if (v > 0) {
                v = 0;
            }
            v -= 0x52;
        } else {
            v += 0x7b;
        }
        {
            BOOL c;
            BOOL b;
            BOOL a;
            a = FALSE;
            ok = TRUE;
            c = TRUE;
            b = TRUE;
            if (t3 == 3 && t4 == 2) a = TRUE;
            if (!a) { if (!(t3 == 2 && t4 == 3)) b = FALSE; }
            if (!b) { if (!(t3 == 4 && t4 == 4)) c = FALSE; }
            if (!c) { if (t3 == 1 || t3 == 0 || t4 != 1) ok = FALSE; }
        }
        if (ok) {
            if (v > 0) {
                v = 0;
            }
            if ((self->unk_0c >> 12) % 20 == 0) {
                func_02049a48(data_02097e4c, 0x48, -1, -1, -1);
            }
        } else {
            v += 0x7b;
            if ((self->unk_0c >> 12) % 5 == 0) {
                func_02049a48(data_02097e4c, 2, -1, -1, -1);
            }
        }
        break;
    }
    }
    if (v < self->info->unk_1c) {
        v = self->info->unk_1c;
    }
    return v;
}

}
