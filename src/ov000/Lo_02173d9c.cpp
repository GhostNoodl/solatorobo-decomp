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
} Oam02173d9c;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr02173d9c;

typedef struct {
    u8 pad[0x40];
    s32 x;
    s32 y;
} Ctx02173d9c;

extern "C" {

extern u32 data_ov000_021c9c08[];
void func_02043064(const Oam02173d9c *attr, u32 *w, u32 *h);
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

static inline void G3_Cmd1(u32 cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void G3_Vec(u32 cmd, u32 x, u32 y, u32 z) {
    u32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd2(u32 cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

// ctx is volatile so that it is loaded from the stack where it is first used, as in the target.
void func_ov000_02173d9c(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const Oam02173d9c *oam,
                         const ImgAttr02173d9c *img, u32 charBase, u32 plttBase, s32 unused2, const Ctx02173d9c *volatile ctx) {
    const Ctx02173d9c *c;
    s32 px;
    u32 pal;
    u32 h;
    s32 py;
    u32 w;
    s32 shift;
    u32 fmt;
    u16 charName;

    c = ctx;
    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    fmt = data_ov000_021c9c08[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    px = c->x & ~0xfff;
    py = c->y & ~0xfff;
    G3_Cmd1(0x10, 3);
    G3_Vec(0x1c, px, py, 0);
    G3_Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x - 0x80000, y - 0x60000, z);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x20, 0x2214);
    G3_Cmd1(0x22, 0xc000000);
    G3_Cmd2(0x23, 0x10000000, 0);
    G3_Cmd1(0x22, 0xc001000);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x20, 0x7fff);
    G3_Cmd1(0x22, 0x1000);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x22, 0);
    G3_Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

}
