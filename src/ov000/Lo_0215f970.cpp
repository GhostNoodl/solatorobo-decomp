#include "types.h"

typedef struct {
    u32 y : 8;
    u32 attr0hi : 8;
    u32 x : 9;
    u32 attr1hi : 7;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Oam0215f970;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr0215f970;

typedef struct {
    u8 pad_00[8];
    s32 w;
    s32 h;
    u8 pad_10[8];
} Entry0215f970;

typedef struct {
    u32 flags;
    s32 idx;
    u8 pad_08[0xc];
    s32 split;
} Ctx0215f970;

extern "C" {

extern u32 data_ov000_021c9880[];
extern Entry0215f970 data_02fe0188[];
void func_02043064(const Oam0215f970 *attr, u32 *w, u32 *h);
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

static inline void G3Cmd1(u32 op, u32 v) {
    u32 a = v;
    NNS_G3dGeBufferOP_N(op, &a, 1);
}

static inline void G3Cmd2(u32 op, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(op, v, 2);
}

static inline void G3Vec(u32 op, s32 x, s32 y, s32 z) {
    u32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(op, v, 3);
}

#define G3TexCoord(s, t) G3Cmd1(0x22, ((u16)(s16)(t) << 16) | (u16)(s16)(s))
#define G3VtxXY(x, y) G3Cmd1(0x25, (u16)(s16)(x) | ((u16)(s16)(y) << 16))
#define G3Vtx(x, y, z) G3Cmd2(0x23, (u16)(s16)(x) | ((u16)(s16)(y) << 16), (u16)(s16)(z))

// ctx0 is read through a const view of the stack parameter: that read is not copy-propagated to
// ctx's uses, so ctx0 is loaded from the stack after the skip check, as in the target.
void func_ov000_0215f970(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const Oam0215f970 *oam,
                         const ImgAttr0215f970 *img, u32 charBase, u32 plttBase, s32 unused2, const Ctx0215f970 *ctx0) {
    const Ctx0215f970 *ctx;
    s32 split;
    Entry0215f970 *e;
    s32 sw;
    u32 fmt;
    s32 sh;
    u32 h;
    u32 w;
    s32 oy;
    s32 shift;
    u32 pal;
    s32 ox;

    if (skip) {
        return;
    }
    ctx = *(const Ctx0215f970 *const *)&ctx0;
    e = &data_02fe0188[ctx->idx];
    ox = oam->x;
    if (ox > 0xff) {
        ox |= ~0xff;
    }
    x += ox << 12;
    oy = oam->y;
    if (oy > 0x7f) {
        oy |= ~0xff;
    }
    y += oy << 12;
    pal = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (pal << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | (img->plttUse << 29);
    fmt = data_ov000_021c9880[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    split = ctx->split;
    sw = e->w;
    sh = e->h;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3Vec(0x1c, x - 0x80000, y - 0x60000, z);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3Vec(0x1c, 0, 0, 0);
    G3Vec(0x1b, sw, sh, 0x1000);
    G3Cmd1(0x40, 1);
    G3TexCoord(0, 0);
    G3Vtx(0, 0, 0);
    G3TexCoord(0, sh >> 8);
    G3VtxXY(0, 0x1000);
    G3TexCoord(sw >> 8, sh >> 8);
    G3VtxXY(0x1000, 0x1000);
    G3TexCoord(sw >> 8, 0);
    G3VtxXY(0x1000, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3Vec(0x1c, (split << 12) - sw, 0, 0);
    G3Vec(0x1b, sw, sh, 0x1000);
    G3Cmd1(0x40, 1);
    G3TexCoord(sw >> 8, 0);
    G3Vtx(0, 0, 0);
    G3TexCoord(sw >> 8, sh >> 8);
    G3VtxXY(0, 0x1000);
    G3TexCoord((sw * 2) >> 8, sh >> 8);
    G3VtxXY(0x1000, 0x1000);
    G3TexCoord((sw * 2) >> 8, 0);
    G3VtxXY(0x1000, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3Cmd1(0x12, 1);
    G3Cmd1(0x12, 1);
}

}
