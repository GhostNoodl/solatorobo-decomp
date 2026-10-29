#include "Main/Gfx/Gfx3D.h"

extern "C" {

typedef struct GfxCamParam {
    /* 0x00 */ int unk_00;
    /* 0x04 */ int unk_04;
    /* 0x08 */ u16 unk_08;
    /* 0x0a */ u16 unk_0a;
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ int unk_10;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 unk_15;
    /* 0x16 */ u8 unk_16;
} GfxCamParam;

void func_020434e0(GfxCamParam *p) {
    p->unk_10 = 0x22000;
    p->unk_0e = 0x182e;
    p->unk_08 = 0x182e - 0x1380;
    p->unk_0a = 0xf4d;
    p->unk_14 = 4;
    p->unk_15 = 3;
    p->unk_0c = 0x1555;
    p->unk_00 = 0x19a;
    p->unk_04 = 0xc8000;
    p->unk_16 = 1;
}

typedef struct GfxCamPos {
    int v[9];
} GfxCamPos;

GfxCamPos *func_02043548(GfxCamPos *p) {
    p->v[0] = 0;
    p->v[1] = 0;
    p->v[2] = 0;
    p->v[3] = 0;
    p->v[4] = 0;
    p->v[5] = 0;
    p->v[6] = 0;
    p->v[7] = 0x1000;
    p->v[8] = 0;
    return p;
}


static inline void GfxLightVec_Set(GfxLightVec *v, s16 x, s16 y, s16 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}


static inline void GfxLight_Apply(GfxLight *light) {
    int i;
    for (i = 0; i < 4; i++) {
        NNS_G3dGlbLightVector(i, light->dirs[i].x, light->dirs[i].y, light->dirs[i].z);
        NNS_G3dGlbLightColor(i, light->colors[i]);
    }
    NNS_G3dGlbMaterialColorDiffAmb(light->diffuse, light->ambient, TRUE);
    NNS_G3dGlbMaterialColorSpecEmi(light->specular, light->emission, TRUE);
}

void func_02043578(GfxLight *light) {
    GfxLight_Apply(light);
}

static inline int FX_MulC(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

void func_020435e8(GfxPltt *pltt, u16 *buf, u32 size) {
    u32 i;
    int v;
    switch (pltt->id) {
    case -1:
        return;
    case 0:
        for (i = 0; i < size / 2; i++) {
            u16 c = buf[i];
            int b = ((c & 0x7c00) >> 10) << 12;
            int r = (c & 0x1f) << 12;
            int g = ((c & 0x3e0) >> 5) << 12;
            v = (FX_MulC(b, 0x1d3) + (FX_MulC(r, 0x4c9) + FX_MulC(g, 0x964))) >> 12;
            buf[i] = v | (v << 5) | (v << 10);
        }
        DC_FlushRange(buf, size);
        return;
    case 1:
        func_020436f8(pltt, buf, size);
        return;
    }
}

void func_020436f8(GfxPltt *pltt, u16 *buf, u32 size) {
    u32 i;
    int y;
    for (i = 0; i < size / 2; i++) {
        u16 c = buf[i];
        int b = ((c & 0x7c00) >> 10) << 12;
        int r = (c & 0x1f) << 12;
        int g = ((c & 0x3e0) >> 5) << 12;
        y = FX_MulC(b, 0x1d3) + (FX_MulC(r, 0x4c9) + FX_MulC(g, 0x964));
        buf[i] = (FX_MulC(y, 0xf0e) >> 12) | ((FX_MulC(y, 0xc8b) >> 12) << 5) | ((FX_MulC(y, 0x964 - 0x49) >> 12) << 10);
    }
    DC_FlushRange(buf, size);
}


static inline void GfxLight_Init(GfxLight *light) {
    int i;
    for (i = 0; i < 4; i++) {
        GfxLightVec *v = &light->dirs[i];
        v->x = 0xfd7;
        v->y = -0xfd7;
        v->z = -0xfd7;
        light->colors[i] = 0x7fff;
    }
    light->diffuse = 0x7fff;
    light->ambient = 0;
    light->specular = 0;
    light->emission = 0;
}

void func_02043858(Gfx3DState *st) {
    GfxLight_Init(&st->light);
    st->unk_134 = -1;
    st->unk_138 = 0;
    *(u8 *)st = 0;
    st->unk_17c = 0;
    st->polyId = 30;
    st->unk_002 = 6;
    st->unk_003 = 2;
}

void func_020438e8(Gfx3DState *st) {
    st->polyId = 30;
    st->unk_002 = 6;
    st->unk_003 = 2;
}

static inline void G3X_AlphaTest(BOOL enable, int ref) {
    if (enable) {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 4;
        REG_ALPHA_TEST_REF = ref;
    } else {
        REG_DISP3DCNT &= 0xcffb;
    }
}

static inline void G3X_AlphaBlend(BOOL enable) {
    if (enable) {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    } else {
        REG_DISP3DCNT &= 0xcff7;
    }
}

static inline void G3X_AntiAlias(BOOL enable) {
    if (enable) {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 0x10;
    } else {
        REG_DISP3DCNT &= 0xcfef;
    }
}

static inline void G3X_EdgeMarking(BOOL enable) {
    if (enable) {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 0x20;
    } else {
        REG_DISP3DCNT &= 0xcfdf;
    }
}

static inline void G3X_SetShading(int mode) {
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | (mode << 1);
}

static inline void G3X_SetFogColor(u16 color, u16 alpha) {
    REG_FOG_COLOR = color | (alpha << 16);
}

void func_02043904(Gfx3DState *st) {
    int i;
    REG_DISP3DCNT &= 0xcffb;
    st->alphaTest = FALSE;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    st->alphaBlend = TRUE;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 0x10;
    st->antiAlias = TRUE;
    st->fogOffset = 0x7d80;
    st->fogMode = 0;
    st->fogSlope = 5;
    G3X_SetFog(FALSE, 0, 5, st->fogOffset);
    st->fogColor = 0;
    st->fog = FALSE;
    st->fogAlpha = 0x1f;
    G3X_SetFogColor(0, 0x1f);
    for (i = 0; i < 0x20; i++) {
        st->fogTable[i] = i * 0x7f / 0x1f;
    }
    G3X_SetFogTable(st->fogTable);
    st->shading = 0;
    G3X_SetShading(0);
    MIi_CpuCopyFast(data_02082958, st->toonTable, sizeof(st->toonTable));
    G3X_SetToonTable(data_02082958);
    st->edgeMarking = FALSE;
    st->unk_000_5 = FALSE;
    REG_DISP3DCNT &= 0xcfdf;
    MIi_CpuCopyFast(data_02082900, st->edgeTable, sizeof(st->edgeTable));
    G3X_SetEdgeColorTable(data_02082900);
    st->clearColor = 0;
    st->clearPolyId = 0x3f;
    G3X_SetClearColor(0, 0x1f, 0x7fff, 0x3f, TRUE);
    for (i = 0; i < 4; i++) {
        st->light.dirs[i].x = 0xfd7;
        st->light.dirs[i].y = -0xfd7;
        st->light.dirs[i].z = -0xfd7;
        st->light.colors[i] = 0x7fff;
    }
    st->light.diffuse = 0x7fff;
    st->light.ambient = 0;
    st->light.specular = 0;
    st->light.emission = 0;
    MTX_OrthoW(0, 0xc0000, 0, 0x100000, 0, 0x20000, 0x400000, st->unk_13c);
}

void func_02043b20(Gfx3DState *st) {
    if (st->alphaTest) {
        G3X_AlphaTest(TRUE, st->alphaRef);
    } else {
        G3X_AlphaTest(FALSE, 0);
    }
    G3X_AlphaBlend(st->alphaBlend);
    G3X_AntiAlias(st->antiAlias);
    if (st->fog) {
        G3X_SetFogColor(st->fogColor, st->fogAlpha);
        G3X_SetFogTable(st->fogTable);
        G3X_SetFog(TRUE, st->fogMode, st->fogSlope, st->fogOffset);
    } else {
        G3X_SetFog(FALSE, st->fogMode, st->fogSlope, st->fogOffset);
    }
    if (st->shading == 0) {
        G3X_SetShading(0);
    } else {
        G3X_SetShading(1);
    }
    G3X_SetToonTable(st->toonTable);
    if (st->edgeMarking) {
        REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 0x20;
        G3X_SetEdgeColorTable(st->edgeTable);
    } else {
        REG_DISP3DCNT &= 0xcfdf;
    }
    G3X_SetClearColor(st->clearColor, 0x1f, 0x7fff, st->clearPolyId, TRUE);
    GfxLight_Apply(&st->light);
}

void func_02043d20(Gfx3DState *st, BOOL flush) {
    NNS_G3dGeSendDL(data_02fe00e8, 100);
    if (flush) {
        NNS_G3dGeFlushBuffer();
    }
}

int func_02043d48(Gfx3DState *st) {
    u8 id = st->polyId;
    if (id < 0x3f) {
        st->polyId = id + 1;
    }
    return id;
}

int func_02043d60(Gfx3DState *st, int n) {
    u8 id = st->polyId;
    st->polyId = id + n;
    if (st->polyId > 0x3f) {
        st->polyId = 0x3f;
    }
    return id;
}

int func_02043d84(Gfx3DState *st) {
    u8 id = st->unk_002;
    if (id < 0x13) {
        st->unk_002 = id + 1;
    }
    return id;
}

int func_02043d9c(Gfx3DState *st) {
    u8 id = st->unk_003;
    if (id < 5) {
        st->unk_003 = id + 1;
    }
    return id;
}

void func_02043db4(int idx, int x, int y, u32 color) {
    int scale[3];
    u32 c;
    scale[0] = x;
    scale[1] = y;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    c = color;
    NNS_G3dGeBufferOP_N(0x20, &c, 1);
    NNS_G3dGeSendDL(data_0208b3d0[idx], data_020828f8[idx]);
}

void *func_02043e1c(u32 size) {
    return func_0203de84(size, 4);
}

void func_02043e2c(void *ptr) {
    func_0203df0c(ptr);
}




}
