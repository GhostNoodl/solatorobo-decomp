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
} Oam0215a8c8;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr0215a8c8;

typedef struct {
    u8 pad[0xd8];
    const void *dl;
    u32 dlSize;
} DL0215a8c8;

extern "C" {

extern u32 data_ov000_021c9880[];
void func_02043064(const Oam0215a8c8 *attr, u32 *w, u32 *h);
void NNS_G3dGeSendDL(const void *src, u32 szByte);
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

static inline void Draw0215a8c8(s32 x, s32 y, s32 z, const Oam0215a8c8 *oam, const ImgAttr0215a8c8 *img, u32 charBase, u32 plttBase, const void *ctx) {
    u16 charName;
    s32 shift;
    DL0215a8c8 *c = (DL0215a8c8 *)ctx;
    u32 v[3];
    u32 one;
    u32 w;
    u32 h;
    u32 fmt;
    u32 pal;
    s32 ox;
    s32 oy;

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
    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
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
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    v[0] = x - 0x80000;
    v[1] = y - 0x60000;
    v[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, v, 3);
    NNS_G3dGeSendDL(c->dl, c->dlSize);
    one = 1;
    NNS_G3dGeBufferOP_N(0x12, &one, 1);
}

void func_ov000_0215a8c8(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const Oam0215a8c8 *oam,
                         const ImgAttr0215a8c8 *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx) {
    if (skip) {
        return;
    }
    Draw0215a8c8(x, y, z, oam, img, charBase, plttBase, ctx);
}

}
