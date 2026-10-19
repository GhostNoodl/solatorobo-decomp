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
} Oam021ce048;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr021ce048;

extern "C" {

extern u32 data_ov006_021eb708[];
void func_02043064(const Oam021ce048 *attr, u32 *w, u32 *h);
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

void func_ov006_021ce048(void *self, s32 x, s32 y, s32 z, s32 unused, Oam021ce048 *oam,
                         const ImgAttr021ce048 *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs) {
    s32 mv[3];
    s32 tv[3];
    s32 sv[3];
    u32 fmt;
    u32 pal;
    u32 h;
    u32 w;
    s32 shift;
    u16 charName;
    s32 ox;
    s32 oy;

    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    ox = ofs[0];
    oy = ofs[1];
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    oam->pal = 1;
    fmt = data_ov006_021eb708[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    G3Cmd1(0x10, 3);
    mv[0] = ox & -0x1000;
    mv[1] = oy & -0x1000;
    mv[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, mv, 3);
    G3Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tv[0] = x - 0x80000;
    tv[1] = y - 0x60000;
    tv[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, tv, 3);
    sv[0] = 0x100000;
    sv[1] = 0xc0000;
    sv[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, sv, 3);
    G3Cmd1(0x40, 1);
    G3Cmd1(0x20, 0x7fba);
    G3Cmd1(0x22, 0xc000000);
    G3Cmd2(0x23, 0x10000000, 0);
    G3Cmd1(0x22, 0xc001000);
    G3Cmd2(0x23, 0x10001000, 0);
    G3Cmd1(0x20, 0x7fff);
    G3Cmd1(0x22, 0x1000);
    G3Cmd2(0x23, 0x1000, 0);
    G3Cmd1(0x22, 0);
    G3Cmd2(0x23, 0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3Cmd1(0x12, 1);
}

}
