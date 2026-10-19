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
} Oam0214fcfc;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr0214fcfc;

typedef struct {
    u8 pad[0xd8];
    const void *dl;
    u32 dlSize;
} DL0214fcfc;

extern "C" {

extern u32 data_ov000_021c9848[];
void func_02043064(const Oam0214fcfc *attr, u32 *w, u32 *h);
void NNS_G3dGeSendDL(const void *src, u32 szByte);
void NNS_G3dGeBufferOP_N(u32 op, const void *args, u32 num);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

static inline void G3Cmd2(u32 op, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(op, v, 2);
}

static inline void G3Cmd1(u32 op, u32 v) {
    u32 a = v;
    NNS_G3dGeBufferOP_N(op, &a, 1);
}

static inline void Draw0214fcfc(s32 x, s32 y, s32 z, const Oam0214fcfc *oam, const ImgAttr0214fcfc *img, u32 charBase, u32 plttBase, const void *mtx) {
    s32 sv[3];
    s32 tv[3];
    u32 w;
    u32 h;
    u16 charName;
    s32 shift;
    u32 fmt;
    u32 pal;

    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    fmt = data_ov000_021c9848[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tv[0] = x - 0x80000;
    tv[1] = y - 0x60000;
    tv[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, tv, 3);
    sv[0] = 0x100000;
    sv[1] = 0x13000;
    sv[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, sv, 3);
    if (mtx != NULL) {
        NNS_G3dGeBufferOP_N(0x19, mtx, 12);
    }
    G3Cmd1(0x20, 0x7fff);
    G3Cmd1(0x40, 1);
    G3Cmd1(0x22, 0x1300000);
    G3Cmd2(0x23, 0x10000000, 0);
    G3Cmd1(0x22, 0x1300020);
    G3Cmd1(0x25, 0x10001000);
    G3Cmd1(0x22, 0x20);
    G3Cmd1(0x25, 0x1000);
    G3Cmd1(0x22, 0);
    G3Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3Cmd1(0x12, 1);
}

void func_ov000_0214fcfc(void *self, s32 x, s32 y, s32 z, s32 unused, const Oam0214fcfc *oam,
                         const ImgAttr0214fcfc *img, u32 charBase, u32 plttBase, const void *mtx) {
    Draw0214fcfc(x, y, z, oam, img, charBase, plttBase, mtx);
}

}
