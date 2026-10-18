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
static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    func_0202a3ec(cmd, &v, 1);
}

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_0202a3ec(cmd, v, 3);
}

static inline void G3_TexCoord(int s, int t) {
    G3_Cmd1(0x22, (u16)(s16)(s >> 8) | ((u16)(s16)(t >> 8) << 16));
}

static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    func_0202a3ec(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    G3_Cmd1(0x25, (u16)x | ((u16)y << 16));
}

void func_02043100(int x, int y, int z, u32 color, const GfxOamAttr *oam, const GfxOamTex *tex, u32 texBase, u32 plttBase, const void *mtx) {
    OamShape shape = oam->attr01 & 0xc000c000;
    int ox = (oam->attr01 << 7) >> 23;
    int oy;
    u32 name = (oam->attr23 << 22) >> 22;
    int shapeBit = (shape & 0xc000) >> 14;
    int sizeBit = (u32)(shape & 0xc0000000) >> 30;
    int h;
    int w;
    u32 addr;
    int fmt;
    int s0;
    int s1;
    int t0;
    int t1;
    int sw;
    int sh;
    u32 pal;
    if (ox > 0xff) {
        ox |= ~0xff;
    }
    oy = oam->attr01 & 0xff;
    if (oy > 0x7f) {
        oy |= ~0xff;
    }
    h = data_02075614[shapeBit][sizeBit];
    w = data_0207562c[shapeBit][sizeBit];
    y += oy << 12;
    x += ox << 12;
    if ((y >> 12) + h <= 0) {
        return;
    }
    if ((y >> 12) - h >= 0x100) {
        return;
    }
    addr = texBase + (name << (((tex->mapping & 0x700000) >> 20) + 5));
    {
        u16 sb = (u16)((shape & 0xc000) >> 14);
        u16 zb = (u16)((shape & 0xc0000000) >> 30);
        G3_Cmd1(0x2a, (tex->fmt << 26) | (addr >> 3) | 0x40000000 | (data_02082898[sb][zb] << 20) | (data_020828c8[sb][zb] << 23) | (tex->unk_10 << 29));
    }
    sw = w << 12;
    sh = h << 12;
    s0 = 0;
    t0 = y < 0 ? 0 : 0x800;
    s1 = sw;
    if ((oam->attr01 << 3) >> 31) {
        s1 = -0x800;
        s0 = sw - 0x800;
    }
    t1 = t0 + (h << 12);
    if ((oam->attr01 << 2) >> 31) {
        int tmp = t0;
        t0 = t1 - 0x1000;
        t1 = tmp - 0x1000;
    }
    fmt = data_02082884[(oam->attr01 << 18) >> 31];
    if (tex->extPltt != 0) {
        pal = (u16)((oam->attr23 << 16) >> 28) << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)((oam->attr23 << 16) >> 28) << 5;
    }
    G3_Cmd1(0x2b, (plttBase + pal) >> (4 - (fmt == 2 ? 1 : 0)));
    G3_Vec(0x1c, x, y, z);
    G3_Vec(0x1b, sw, sh, 0x1000);
    if (mtx != NULL) {
        func_0202a3ec(0x19, mtx, 12);
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
    func_0202a3ec(0x41, NULL, 0);
}
#endif

}
