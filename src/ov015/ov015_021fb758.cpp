#include "ov015/ov015.h"

struct Ov015bVec {
    s32 x;
    s32 y;
    s32 z;
};

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

extern const s32 data_ov015_02212524[];

void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02043d20(void *p, s32 a);
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 n);
s32 FX_Div(s32 a, s32 b);
void func_ov015_021fcb1c(void *self);
void func_ov015_021fc40c(void *self, s32 a);

static inline void *Ov015b_GetPart(void *self, int idx) {
    if (idx >= FLD(s32, self, 0x80)) {
        return NULL;
    }
    return FLD(u8 *, self, 0x78) + idx * 0x28;
}

static inline void Ov015b_PlayPart(void *model, int idx) {
    void *res = FLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015b_GetPart(model, idx);
    if (part != NULL && FLD(void *, part, 0x4) != NULL) {
        anim = FLD(void *, FLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline s32 Ov015b_Sub(s32 a, s32 b) {
    return a - b;
}

static inline void Ov015b_SetPos(void *m, s32 x, s32 y) {
    FLD(s32, m, 0xfc) = x;
    FLD(s32, m, 0x100) = y;
}

static inline void Ov015b_Place(u8 *self, s32 z, const s32 *v) {
    s32 x = v[0];
    FLD(s32, FLD(void *, self, 0x24), 0x150) = z;
    Ov015b_SetPos(FLD(void *, self, 0x24), x, v[1]);
}

static inline void Ov015b_SetPosV(void *m, const Ov015bVec *v) {
    FLD(s32, m, 0xfc) = v->x;
    FLD(s32, m, 0x100) = v->y;
}

static inline void Ov015b_Begin(u32 prim) {
    u32 v = prim;
    NNS_G3dGeBufferOP_N(0x40, &v, 1);
}
static inline void Ov015b_Color(u32 c) {
    u32 v = c;
    NNS_G3dGeBufferOP_N(0x20, &v, 1);
}
static inline void Ov015b_Vtx(s32 x, s32 y, s32 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}
static inline void Ov015b_VtxXY(s32 x, s32 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}
static inline void Ov015b_End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}
static inline void Ov015b_PopMtx(s32 n) {
    s32 v = n;
    NNS_G3dGeBufferOP_N(0x12, &v, 1);
}
static inline void Ov015b_Quad(s32 sc, u32 c1, u32 c2) {
    s32 s[3];
    u32 beg;
    u32 k1;
    u32 vtx[2];
    u32 v2;
    u32 k2;
    u32 v3;
    u32 v4;
    u32 k3;
    u32 v5;
    u32 v6;
    s32 pop;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    s[0] = 0x7000;
    s[1] = sc;
    s[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, s, 3);
    beg = 3;
    NNS_G3dGeBufferOP_N(0x40, &beg, 1);
    k1 = c1;
    NNS_G3dGeBufferOP_N(0x20, &k1, 1);
    vtx[0] = 0;
    vtx[1] = 0;
    NNS_G3dGeBufferOP_N(0x23, vtx, 2);
    v2 = 0xf0000000;
    NNS_G3dGeBufferOP_N(0x25, &v2, 1);
    k2 = c2;
    NNS_G3dGeBufferOP_N(0x20, &k2, 1);
    v3 = 0x800;
    NNS_G3dGeBufferOP_N(0x25, &v3, 1);
    v4 = 0xf0000800;
    NNS_G3dGeBufferOP_N(0x25, &v4, 1);
    k3 = c1;
    NNS_G3dGeBufferOP_N(0x20, &k3, 1);
    v5 = 0x1000;
    NNS_G3dGeBufferOP_N(0x25, &v5, 1);
    v6 = 0xf0001000;
    NNS_G3dGeBufferOP_N(0x25, &v6, 1);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    pop = 1;
    NNS_G3dGeBufferOP_N(0x12, &pop, 1);
}


void func_ov015_021fb758(u8 *self) {
    Ov015bVec off = {0, 0, 0};
    s32 trans[3];
    s32 mtxMode;
    s32 texParam;
    u32 polyAttr;
    s32 sc;
    Ov015Stat *g = &Dup::data_ov015_0221332c;
    s32 a = data_ov015_0221332c.unk_10;
    switch (FLD(s32, self, 0x10)) {
    case 3:
        if (FLD(s32, self, 0x8) % 30 > 0xf) {
            FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
            Ov015b_SetPos(FLD(void *, self, 0x24), 0, 0);
            Ov015b_PlayPart(FLD(void *, self, 0x24), 5);
        }
        break;
    case 1:
    case 2:
        if (g->unk_08 == 3) {
            func_ov015_021fcb1c(self);
            break;
        }
        if (FLD(s32, self, 0x8) % 20 > 10) {
            FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
            Ov015b_SetPos(FLD(void *, self, 0x24), data_ov015_02212524[0x21], data_ov015_02212524[0x22]);
            Ov015b_PlayPart(FLD(void *, self, 0x24), 6);
        }
        break;
    case 0:
        if (g->unk_08 == 3) {
            func_ov015_021fcb1c(self);
        } else {
            func_ov015_021fc40c(self, a);
        }
        break;
    }
    FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x2000;
    Ov015b_SetPosV(FLD(void *, self, 0x24), &off);
    Ov015b_PlayPart(FLD(void *, self, 0x24), 0);
    FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1fe0;
    Ov015b_PlayPart(FLD(void *, self, 0x24), 1);
    func_02043d20(data_02097d48 + 0x8b0, 1);
    mtxMode = 2;
    NNS_G3dGeBufferOP_N(0x10, &mtxMode, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    texParam = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    polyAttr = 0x1f00c0 | (func_02043d48(data_02097d48 + 0x8b0) << 24);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    trans[0] = 0;
    trans[1] = 0x97000;
    trans[2] = -0x1fc0;
    NNS_G3dGeBufferOP_N(0x1c, trans, 3);
    sc = Ov015_FxMul(FX_Div(g->unk_24, 0x64000), 0x6e000);
    if (FLD(s32, self, 0x10) == 3) {
        Ov015b_Quad(sc, 0x201c, 0x2a1f);
    } else if (FLD(s32, self, 0x10) == 1) {
        if (FLD(s32, self, 0x8) % 10 < 5) {
            Ov015b_Quad(sc, 0x201c, 0x2a1f);
        } else {
            Ov015b_Quad(sc, 0x27f, 0x3bf);
        }
    } else {
        Ov015b_Quad(sc, 0x27f, 0x3bf);
    }
    Ov015b_PopMtx(1);
    Ov015b_SetPos(FLD(void *, self, 0x24), -0x79000, Ov015b_Sub(0x97000, sc) - 0x60000);
    Ov015b_PlayPart(FLD(void *, self, 0x24), 0x11);
    if (FLD(s32, self, 0x10) == 1) {
        s32 t;
        s32 x;
        s32 y;
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x199a;
        x = off.x;
        y = off.y;
        t = FX_Div((30 - FLD(s32, self, 0x8) % 30) << 12, 0x1e000);
        t = 0x1000 - Ov015_FxMul(t, t);
        x -= Ov015_FxMul(t, 0x4000);
        Ov015b_SetPos(FLD(void *, self, 0x24), x, y);
        Ov015b_PlayPart(FLD(void *, self, 0x24), 0x15);
    }
    if (FLD(s32, self, 0xc) == 1) {
        u8 k = FLD(s32, self, 0x8) % 30;
        FLD(u16, FLD(void *, self, 0x24), 0x154) = 0x1f | (k << 5) | (k << 10);
    }
    FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
    Ov015b_SetPos(FLD(void *, self, 0x24), 0, -0x34000);
    Ov015b_PlayPart(FLD(void *, self, 0x24), 0x10);
    Ov015b_SetPos(FLD(void *, self, 0x24), 0, -0x30000);
    Ov015b_PlayPart(FLD(void *, self, 0x24), 0xf);
    Ov015b_SetPos(FLD(void *, self, 0x24), 0, -0x30000);
    Ov015b_PlayPart(FLD(void *, self, 0x24), 0xe);
    FLD(u16, FLD(void *, self, 0x24), 0x154) = 0x7fff;
}
}

// func_ov015_021fc40c (rounds bgM, bgO, bgR, bgT). Each arm stores the whole b offset (SetV); the ROM's shared
// b stores are tail merging. The arm zeros stay in the arms because the per-case indices are set before the Bob
// table walk (pressure 11 on the walk back to the case head), and g (the Ov015Stat pointer) is live across the
// blink test, which keeps the FX_Mul zero in that block. In the alpha block, the old alpha goes to its own local
// and the model passed to the PlayPart inline is read into m (round bgO).
extern "C" {

void func_0204b420(void *p);

struct Ov015cVec {
    s32 x;
    s32 y;
    s32 z;
};

extern const Ov015cVec data_ov015_02212584;
extern const Ov015cVec data_ov015_02212590;
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
s32 FX_Div(s32 a, s32 b);
void MTX_Identity22_(void *m);
void MTX_ScaleApply22(void *src, void *dst, s32 x, s32 y);
void VEC_Add(const Ov015cVec *a, const Ov015cVec *b, Ov015cVec *o);
void func_ov000_021c8408(void);

static inline void *Ov015c_GetPart(void *self, int idx) {
    if (idx >= FLD(s32, self, 0x80)) {
        return NULL;
    }
    return FLD(u8 *, self, 0x78) + idx * 0x28;
}

static inline void Ov015c_PlayPart(void *model, int idx, int flag) {
    void *res = FLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015c_GetPart(model, idx);
    if (part != NULL && FLD(void *, part, 0x4) != NULL) {
        anim = FLD(void *, FLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, flag);
}

static inline s32 Ov015c_Sin(s32 t) {
    return FX_SinCosTable_[(Ov015_FxMul(t, 0x3fff000) >> 16) * 2];
}

static inline s32 Ov015c_SinIdx(s32 idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline s32 Ov015c_Sin2(s32 t) {
    return Ov015c_SinIdx(Ov015_FxMul(t, 0x3fff000) >> 16);
}

static inline void Ov015c_SetV(Ov015cVec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Ov015c_Sub(s32 a, s32 b) {
    return a - b;
}

static inline void Ov015c_SetPosV(void *m, const Ov015cVec *v) {
    FLD(s32, m, 0xfc) = v->x;
    FLD(s32, m, 0x100) = v->y;
}

static inline void Ov015c_SetPos(void *m, s32 x, s32 y) {
    FLD(s32, m, 0xfc) = x;
    FLD(s32, m, 0x100) = y;
}

struct Ov015cFlags {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 rest : 25;
};

static inline u8 Ov015c_SetAlpha(void *m, u8 a) {
    u8 old = FLD(Ov015cFlags, m, 0x6c).alpha;
    FLD(Ov015cFlags, m, 0x6c).alpha = a;
    return old;
}

static inline s32 Ov015c_Bob(s32 n) {
    if (n < 5) {
        return 0;
    }
    if (n < 10) {
        return 0x6aaa;
    }
    if (n < 15) {
        return 0xd554;
    }
    return 0x14000;
}

void func_ov015_021fc40c(void *self, s32 mode) {
    Ov015cVec c;
    Ov015cVec a;
    Ov015cVec b;
    Ov015cVec v2;
    Ov015cVec v;
    s32 blinkIdx;
    s32 n;
    BOOL flip = FALSE;
    s32 alphaIdx;
    s32 cnt;
    BOOL blink;
    s32 mainIdx;
    Ov015Stat *g = &data_ov015_0221332c;
    switch (mode) {
    case 2:
        blinkIdx = 3;
        alphaIdx = 0x18;
        mainIdx = 8;
        flip = TRUE;
        Ov015c_SetV(&a, -0x3c000, -0x1c000, 0);
        cnt = FLD(s32, self, 0x8);
        n = cnt % 20;
        Ov015c_SetV(&b, -Ov015c_Bob(n), 0, 0);
        break;
    case 3:
        blinkIdx = 2;
        alphaIdx = 0x17;
        mainIdx = 8;
        Ov015c_SetV(&a, 0x3c000, -0x1c000, 0);
        cnt = FLD(s32, self, 0x8);
        n = cnt % 20;
        Ov015c_SetV(&b, Ov015c_Bob(n), 0, 0);
        break;
    case 4:
        blinkIdx = 4;
        alphaIdx = 0x19;
        mainIdx = 9;
        Ov015c_SetV(&a, 0, 0x1a000, 0);
        cnt = FLD(s32, self, 0x8);
        n = cnt % 20;
        Ov015c_SetV(&b, 0, Ov015c_Bob(n), 0);
        break;
    default:
        return;
    }
    n = FLD(s32, self, 0x1c);
    blink = FALSE;
    if (n < 12) {
        if (n % 6 < 3) {
            blink = TRUE;
        }
    } else if (n <= 30) {
        blink = TRUE;
    }
    if (blink) {
        Ov015c_SetV(&c, 0, -0x1d000, 0);
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
        Ov015c_SetPosV(FLD(void *, self, 0x24), &c);
        Ov015c_PlayPart(FLD(void *, self, 0x24), blinkIdx, 0);
    }
    if (FLD(s32, self, 0x20) <= 0) {
        u32 al;
        u8 old;
        void *m;
        n = FLD(s32, self, 0x8) % 20;
        al = (u8)(Ov015_FxMul(FX_SinCosTable_[(Ov015_FxMul(0x7fff, FX_Div(n << 12, 0x14000)) >> 4) * 2], 0x3c000) >> 12);
        if (al > 30) {
            al = 30;
        }
        old = Ov015c_SetAlpha(FLD(void *, self, 0x24), al);
        Ov015c_SetPos(FLD(void *, self, 0x24), 0, -0x1c000);
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1666;
        m = FLD(void *, self, 0x24);
        Ov015c_PlayPart(m, alphaIdx, 0);
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x199a;
        Ov015c_PlayPart(FLD(void *, self, 0x24), 0x16, 0);
        FLD(Ov015cFlags, FLD(void *, self, 0x24), 0x6c).alpha = old;
    }
    VEC_Add(&b, &a, &a);
    if (flip) {
        FLD(u32, FLD(void *, self, 0x24), 0x6c) |= 0x20000;
    }
    Ov015c_SetPosV(FLD(void *, self, 0x24), &a);
    Ov015c_PlayPart(FLD(void *, self, 0x24), mainIdx, 0);
    FLD(u32, FLD(void *, self, 0x24), 0x6c) &= ~0x20000;
    {
        s32 p = g->unk_14;
        s32 q = g->unk_10;
        if (!((p == 3 && q == 2) || (p == 2 && q == 3) || (p == 4 && q == 4) || (p != 1 && p != 0 && q == 1))) {
            return;
        }
    }
    if (g->unk_18 < 0x1e000) {
        return;
    }
    Ov015c_SetV(&c, 0, -0x34000, 0);
    c.y -= 0x10000;
    cnt = FLD(s32, self, 0x8);
    FLD(s32, FLD(void *, self, 0x28), 0x150) = -0x199a;
    VEC_Add(&c, &data_ov015_02212584, &v);
    Ov015c_SetPosV(FLD(void *, self, 0x28), &v);
    Ov015c_PlayPart(FLD(void *, self, 0x28), 0x10, 0);
    if (cnt % 8 < 4) {
        VEC_Add(&c, &data_ov015_02212590, &v2);
        FLD(s32, FLD(void *, self, 0x24), 0x150) = -0x1ccd;
        Ov015c_SetPosV(FLD(void *, self, 0x24), &v2);
        Ov015c_PlayPart(FLD(void *, self, 0x24), 0xd, 0);
    }
}

}
