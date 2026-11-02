#include "ov015/ov015.h"

extern "C" {

s32 func_ov015_02200bf4(Ov015Obj34 *self, Ov015Stat *b, s32 c);
s32 func_ov015_022090f0(Ov015FishInfo *p);

void func_ov015_02200a18(Ov015Obj34 *self, Ov015Stat *b) {
    s32 spd = self->unk_1c;
    s32 pos = b->unk_24;
    switch (b->unk_28) {
    case 3:
        spd = -0x666;
        if ((self->unk_0c >> 12) % 20 == 0) {
            EffectObj *e;
            SndMgr_PlayVolume(data_02097e4c, 0x59, -1, -1, -1);
            // m[3] as a byte offset from the matrix: a field path folds to one constant and changes the code.
            e = Effect_SpawnId(0x325, &FLD(Ov015Vec, &self->ship->nodeMtx, 0x24));
            e->SetScaleXYZ(0x800, 0x800, 0x800);
            e->unk_d4 = 2;
        }
        if (pos <= 0) {
            pos = 0;
            b->unk_28 = pos;
        }
        break;
    case 2:
        spd = -0x3000;
        if (--self->unk_14 <= 0) {
            self->unk_14 = 0;
            b->unk_28 = 0;
        }
        break;
    case 1:
        if (pos >= 0x64000 && b->unk_08 != 3) {
            b->unk_28 = 3;
            SndMgr_PlayVolume(data_02097e4c, 0x1b, -1, -1, -1);
        } else if (pos < 0x46000) {
            b->unk_28 = 0;
        }
        if ((self->unk_0c >> 12) % 10 == 0) {
            SndMgr_PlayVolume(data_02097e4c, 0x59, -1, -1, -1);
        }
        spd = func_ov015_02200bf4(self, b, spd);
        break;
    case 0:
        if (pos > 0x46000) {
            b->unk_28 = 1;
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
    b->unk_24 = pos;
}

s32 func_ov015_02200bf4(Ov015Obj34 *self, Ov015Stat *b, s32 c) {
    BOOL flag = TRUE;
    s32 base;
    s32 q, d, na, nb, ax, bx;
    Ov015Info38 *o;
    if (b->unk_14 == 1) flag = FALSE;
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
    } else if (b->unk_1c != 0) {
        s32 t3 = b->unk_14;
        s32 t4 = b->unk_10;
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
                SndMgr_PlayVolume(data_02097e4c, 0x48, -1, -1, -1);
            }
        } else {
            v += 0x7b;
            if ((self->unk_0c >> 12) % 5 == 0) {
                SndMgr_PlayVolume(data_02097e4c, 2, -1, -1, -1);
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
