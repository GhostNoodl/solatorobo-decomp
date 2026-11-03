#include "ov015/ov015.h"


namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

extern const s32 data_ov015_02212524[];

u8 Gfx3DState_NextPolyId(void *p);

static inline void Ov015b_Place(Ov015Hud *self, s32 z, const s32 *v) {
    s32 x = v[0];
    self->mdl0->unk_150 = z;
    Ov015Model_SetPos(self->mdl0, x, v[1]);
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
    NNS_G3dGeBufferOP_N(0x12, (unsigned int *)&v, 1);
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
    NNS_G3dGeBufferOP_N(0x1b, (unsigned int *)s, 3);
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
    NNS_G3dGeBufferOP_N(0x12, (unsigned int *)&pop, 1);
}


void func_ov015_021fb758(Ov015Hud *self) {
    VecFx32 off = {0, 0, 0};
    s32 trans[3];
    s32 mtxMode;
    s32 texParam;
    u32 polyAttr;
    s32 sc;
    Ov015Stat *g = &Dup::data_ov015_0221332c;
    s32 a = data_ov015_0221332c.unk_10;
    switch (self->unk_10) {
    case 3:
        if (self->frame % 30 > 0xf) {
            self->mdl0->unk_150 = -0x1666;
            Ov015Model_SetPos(self->mdl0, 0, 0);
            Ov015Model_PlayPart(self->mdl0, 5, 0);
        }
        break;
    case 1:
    case 2:
        if (g->unk_08 == 3) {
            func_ov015_021fcb1c(self);
            break;
        }
        if (self->frame % 20 > 10) {
            self->mdl0->unk_150 = -0x1666;
            Ov015Model_SetPos(self->mdl0, data_ov015_02212524[0x21], data_ov015_02212524[0x22]);
            Ov015Model_PlayPart(self->mdl0, 6, 0);
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
    self->mdl0->unk_150 = -0x2000;
    Ov015Model_SetPosV(self->mdl0, &off);
    Ov015Model_PlayPart(self->mdl0, 0, 0);
    self->mdl0->unk_150 = -0x1fe0;
    Ov015Model_PlayPart(self->mdl0, 1, 0);
    Gfx3D_SendDL(gGfxSys->unk_8b0, 1);
    mtxMode = 2;
    NNS_G3dGeBufferOP_N(0x10, (unsigned int *)&mtxMode, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    texParam = 0x20000000;
    NNS_G3dGeBufferOP_N(0x2a, (unsigned int *)&texParam, 1);
    polyAttr = 0x1f00c0 | (Gfx3DState_NextPolyId(gGfxSys->unk_8b0) << 24);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    trans[0] = 0;
    trans[1] = 0x97000;
    trans[2] = -0x1fc0;
    NNS_G3dGeBufferOP_N(0x1c, (unsigned int *)trans, 3);
    sc = FX_Mul(FX_Div(g->unk_24, 0x64000), 0x6e000);
    if (self->unk_10 == 3) {
        Ov015b_Quad(sc, 0x201c, 0x2a1f);
    } else if (self->unk_10 == 1) {
        if (self->frame % 10 < 5) {
            Ov015b_Quad(sc, 0x201c, 0x2a1f);
        } else {
            Ov015b_Quad(sc, 0x27f, 0x3bf);
        }
    } else {
        Ov015b_Quad(sc, 0x27f, 0x3bf);
    }
    Ov015b_PopMtx(1);
    Ov015Model_SetPos(self->mdl0, -0x79000, Ov015c_Sub(0x97000, sc) - 0x60000);
    Ov015Model_PlayPart(self->mdl0, 0x11, 0);
    if (self->unk_10 == 1) {
        s32 t;
        s32 x;
        s32 y;
        self->mdl0->unk_150 = -0x199a;
        x = off.x;
        y = off.y;
        t = FX_Div((30 - self->frame % 30) << 12, 0x1e000);
        t = 0x1000 - FX_Mul(t, t);
        x -= FX_Mul(t, 0x4000);
        Ov015Model_SetPos(self->mdl0, x, y);
        Ov015Model_PlayPart(self->mdl0, 0x15, 0);
    }
    if (self->unk_0c == 1) {
        u8 k = self->frame % 30;
        self->mdl0->color = 0x1f | (k << 5) | (k << 10);
    }
    self->mdl0->unk_150 = -0x1666;
    Ov015Model_SetPos(self->mdl0, 0, -0x34000);
    Ov015Model_PlayPart(self->mdl0, 0x10, 0);
    Ov015Model_SetPos(self->mdl0, 0, -0x30000);
    Ov015Model_PlayPart(self->mdl0, 0xf, 0);
    Ov015Model_SetPos(self->mdl0, 0, -0x30000);
    Ov015Model_PlayPart(self->mdl0, 0xe, 0);
    self->mdl0->color = 0x7fff;
}
}

// func_ov015_021fc40c (rounds bgM, bgO, bgR, bgT). Each arm stores the whole b offset (SetV); the ROM's shared
// b stores are tail merging. The arm zeros stay in the arms because the per-case indices are set before the Bob
// table walk (pressure 11 on the walk back to the case head), and g (the Ov015Stat pointer) is live across the
// blink test, which keeps the FX_Mul zero in that block. In the alpha block, the old alpha goes to its own local
// and the model passed to the PlayPart inline is read into m (round bgO).
extern "C" {

void func_0204b420(void *p);


extern const VecFx32 data_ov015_02212584;
extern const VecFx32 data_ov015_02212590;
void func_ov000_021c8408(s32 idx, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);

// The bits of Model::flags (ov000's ModelFlags).
struct Ov015cFlags {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 rest : 25;
};

static inline u8 Ov015c_SetAlpha(Model *m, u8 a) {
    u8 old = ((Ov015cFlags *)&m->flags)->alpha;
    ((Ov015cFlags *)&m->flags)->alpha = a;
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

void func_ov015_021fc40c(Ov015Hud *self, s32 mode) {
    VecFx32 c;
    VecFx32 a;
    VecFx32 b;
    VecFx32 v2;
    VecFx32 v;
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
        cnt = self->frame;
        n = cnt % 20;
        Ov015c_SetV(&b, -Ov015c_Bob(n), 0, 0);
        break;
    case 3:
        blinkIdx = 2;
        alphaIdx = 0x17;
        mainIdx = 8;
        Ov015c_SetV(&a, 0x3c000, -0x1c000, 0);
        cnt = self->frame;
        n = cnt % 20;
        Ov015c_SetV(&b, Ov015c_Bob(n), 0, 0);
        break;
    case 4:
        blinkIdx = 4;
        alphaIdx = 0x19;
        mainIdx = 9;
        Ov015c_SetV(&a, 0, 0x1a000, 0);
        cnt = self->frame;
        n = cnt % 20;
        Ov015c_SetV(&b, 0, Ov015c_Bob(n), 0);
        break;
    default:
        return;
    }
    n = self->unk_1c;
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
        self->mdl0->unk_150 = -0x1666;
        Ov015Model_SetPosV(self->mdl0, &c);
        Ov015Model_PlayPart(self->mdl0, blinkIdx, 0);
    }
    if (self->unk_20 <= 0) {
        u32 al;
        u8 old;
        Model *m;
        n = self->frame % 20;
        al = (u8)(FX_Mul(FX_SinCosTable_[(FX_Mul(0x7fff, FX_Div(n << 12, 0x14000)) >> 4) * 2], 0x3c000) >> 12);
        if (al > 30) {
            al = 30;
        }
        old = Ov015c_SetAlpha(self->mdl0, al);
        Ov015Model_SetPos(self->mdl0, 0, -0x1c000);
        self->mdl0->unk_150 = -0x1666;
        m = self->mdl0;
        Ov015Model_PlayPart(m, alphaIdx, 0);
        self->mdl0->unk_150 = -0x199a;
        Ov015Model_PlayPart(self->mdl0, 0x16, 0);
        ((Ov015cFlags *)&self->mdl0->flags)->alpha = old;
    }
    VEC_Add((VecFx32 *)&b, (VecFx32 *)&a, (VecFx32 *)&a);
    if (flip) {
        self->mdl0->flags |= 0x20000;
    }
    Ov015Model_SetPosV(self->mdl0, &a);
    Ov015Model_PlayPart(self->mdl0, mainIdx, 0);
    self->mdl0->flags &= ~0x20000;
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
    cnt = self->frame;
    self->mdl1->unk_150 = -0x199a;
    VEC_Add((VecFx32 *)&c, (VecFx32 *)&data_ov015_02212584, (VecFx32 *)&v);
    Ov015Model_SetPosV(self->mdl1, &v);
    Ov015Model_PlayPart(self->mdl1, 0x10, 0);
    if (cnt % 8 < 4) {
        VEC_Add((VecFx32 *)&c, (VecFx32 *)&data_ov015_02212590, (VecFx32 *)&v2);
        self->mdl0->unk_150 = -0x1ccd;
        Ov015Model_SetPosV(self->mdl0, &v2);
        Ov015Model_PlayPart(self->mdl0, 0xd, 0);
    }
}

}
