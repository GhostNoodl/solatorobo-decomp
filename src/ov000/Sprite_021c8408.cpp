#include "ov000/LoCommon.h"

typedef union {
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
        u32 charNo : 10;
        u32 priority : 2;
        u32 cParam : 4;
        u32 pad : 16;
    };
    struct {
        u32 attr01;
        u32 attr23;
    };
} Oam021c8408;

typedef struct {
    u8 pad0[8];
    u32 fmt;
    u32 extPltt;
    u32 unk_10;
    int mapping;
} Tex021c8408;

extern "C" {
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void func_02043064(const void *attr, u32 *w, u32 *h);
extern const int data_ov000_021ca614[];

extern const u8 data_020755e4[];
#define TBL_W ((const u16 (*)[4])(data_020755e4 + 0x48))
#define TBL_H ((const u16 (*)[4])(data_020755e4 + 0x30))

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void G3_TexImageParam(int fmt, int gen, int s, int t, int rep, int flip, int pltt0, u32 addr) {
    u32 v = pltt0 << 29;
    v |= addr >> 3 | fmt << 26 | gen << 30 | s << 20 | t << 23 | rep << 16 | flip << 18;
    NNS_G3dGeBufferOP_N(0x2a, &v, 1);
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

static inline void G3_TexCoord(int s, int t) {
    u32 v = (u16)(s16)(s >> 8) | ((u16)(s16)(t >> 8) << 16);
    NNS_G3dGeBufferOP_N(0x22, &v, 1);
}

void func_ov000_021c8408(void *self, int x, int y, int z, u16 color, const Oam021c8408 *oam, const Tex021c8408 *tex, u32 texBase, u32 plttBase, const void *mtx) {
    int shapeBit;
    int sizeBit;
    u32 ws;
    int sw;
    int sh;
    int ox;
    u32 pal;
    u32 hs;
    int shape;
    int oy;
    int w;
    int h;
    int fmt;
    ox = oam->x;
    if (ox > 0xff) {
        ox |= ~0xff;
    }
    oy = oam->y;
    if (oy > 0x7f) {
        oy |= ~0xff;
    }
    func_02043064(oam, &ws, &hs);
    shape = oam->attr01 & 0xc000c000;
    shapeBit = (shape & 0xc000) >> 14;
    sizeBit = (u32)(shape & 0xc0000000) >> 30;
    w = TBL_W[shapeBit][sizeBit];
    h = TBL_H[shapeBit][sizeBit];
    fmt = tex->fmt;
    G3_TexImageParam(fmt, 1, ws, hs, 0, 0, tex->unk_10, texBase + (oam->charNo << (((tex->mapping & 0x700000) >> 20) + 5)));
    fmt = data_ov000_021ca614[oam->colorMode];
    if (tex->extPltt != 0) {
        pal = (u16)oam->cParam << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->cParam << 5;
    }
    G3_Cmd1(0x2b, (plttBase + pal) >> (4 - (fmt == 2 ? 1 : 0)));
    sw = (8 << ws) << 12;
    sh = (8 << hs) << 12;
    G3_Cmd1(0x10, 3);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    G3_Cmd1(0x10, 2);
    G3_Vec(0x1c, x, y, z);
    if (mtx != NULL) {
        NNS_G3dGeBufferOP_N(0x1a, mtx, 9);
    }
    G3_Vec(0x1c, ox << 12, oy << 12, 0);
    G3_Vec(0x1b, w << 12, h << 12, 0x1000);
    G3_Cmd1(0x20, color);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(0, 0);
    G3_Vtx(0, 0, 0);
    G3_TexCoord(0, sh);
    G3_VtxXY(0, 0x1000);
    G3_TexCoord(sw, sh);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(sw, 0);
    G3_VtxXY(0x1000, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
