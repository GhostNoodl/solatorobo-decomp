#include "Main/Gfx/Gfx3D.h"

extern "C" {



void func_02043064(const OamShape *attr, u32 *w, u32 *h) {
    OamShape shape = *attr & 0xc000c000;
    u16 shapeBit = (u16)((shape & 0xc000) >> 14);
    u16 sizeBit = (u16)((shape & 0xc0000000) >> 30);
    int ws = data_02082898[shapeBit][sizeBit];
    int hs = data_020828c8[shapeBit][sizeBit];
    *w = ws;
    *h = hs;
}

void func_020430b8(int w, int h, int *ws, int *hs) {
    int i;
    for (i = 0; i < 32; i++) {
        if (w <= (8 << i)) {
            break;
        }
    }
    *ws = i;
    for (i = 0; i < 32; i++) {
        if (h <= (8 << i)) {
            break;
        }
    }
    *hs = i;
}




#ifdef NONMATCHING
typedef struct GfxOamBits {
    u32 y : 8;
    u32 rsMode : 2;
    u32 objMode : 2;
    u32 mosaic : 1;
    u32 colorMode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 unk_19 : 3;
    u32 flipH : 1;
    u32 flipV : 1;
    u32 size : 2;
    u32 charNo : 10;
    u32 priority : 2;
    u32 cParam : 4;
    u32 attr3 : 16;
} GfxOamBits;

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void G3_TexCoord(int s, int t) {
    u32 v = (u16)(s16)(s >> 8) | ((u16)(s16)(t >> 8) << 16);
    NNS_G3dGeBufferOP_N(0x22, &v, 1);
}

static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}

static inline void Gfx_GetOamShift(const OamShape *sp, u32 *w, u32 *h) {
    u16 shapeBit = (u16)((u32)(*sp & 0xc000) >> 14);
    u16 sizeBit = (u16)((u32)(*sp & 0xc0000000) >> 30);
    *w = data_02082898[shapeBit][sizeBit];
    *h = data_020828c8[shapeBit][sizeBit];
}

// func_02043100 (round frD): 109 / 63, 110 / 62 with branch targets and pool offsets masked
// (was 122 / 66, 123 / 63): `s0` declared after `h`/`w` (tools/declsweep.py single move).
void func_02043100(int x, int y, int z, u32 color, const GfxOamAttr *oam, const GfxOamTex *tex, u32 texBase, u32 plttBase, const void *mtx) {
    int trans[3];
    int scale[3];
    const GfxOamBits *o = (const GfxOamBits *)oam;
    OamShape shape;
    int ox;
    u16 name;
    int h;
    int w;
    int oy;
    u32 addr;
    int fmt;
    int s1;
    int t0;
    int t1;
    int s0;
    u32 pal;
    u32 ws;
    u32 hs;
    shape = oam->attr01 & 0xc000c000;
    name = o->charNo;
    h = data_02075614[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
    w = data_0207562c[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
    ox = o->x;
    if (ox > 0xff) {
        ox |= ~0xff;
    }
    oy = o->y;
    if (oy > 0x7f) {
        oy |= ~0xff;
    }
    y += oy << 12;
    x += ox << 12;
    if ((y >> 12) + h <= 0) {
        return;
    }
    if ((y >> 12) - h >= 0x100) {
        return;
    }
    addr = texBase + (name << (((s32)(tex->mapping & 0x700000) >> 20) + 5));
    Gfx_GetOamShift(&shape, &ws, &hs);
    G3_Cmd1(0x2a, (tex->fmt << 26) | (addr >> 3) | 0x40000000 | (ws << 20) | (hs << 23) | (tex->unk_10 << 29));
    s0 = 0;
    t0 = y < 0 ? 0 : 0x800;
    s1 = w << 12;
    if (o->flipH) {
        s1 = -0x800;
        s0 = (w << 12) - 0x800;
    }
    t1 = t0 + (h << 12);
    if (o->flipV) {
        int tmp = t0;
        t0 = t1 - 0x1000;
        t1 = tmp - 0x1000;
    }
    fmt = data_02082884[o->colorMode];
    if (tex->extPltt != 0) {
        pal = (u16)o->cParam << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)o->cParam << 5;
    }
    G3_Cmd1(0x2b, (plttBase + pal) >> (4 - (fmt == 2 ? 1 : 0)));
    trans[0] = x;
    trans[1] = y;
    trans[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, trans, 3);
    scale[0] = w << 12;
    scale[1] = h << 12;
    scale[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    if (mtx != NULL) {
        NNS_G3dGeBufferOP_N(0x19, mtx, 12);
    }
    G3_Cmd1(0x20, color);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(s0, t1);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(s1, t1);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(s1, t0);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(s0, t0);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}
#endif

}
