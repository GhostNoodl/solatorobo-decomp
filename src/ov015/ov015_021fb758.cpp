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
