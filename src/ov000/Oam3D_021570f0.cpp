#include "types.h"

typedef struct {
    u32 attr01;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Oam021570f0;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr021570f0;

extern "C" {

extern u32 data_ov000_021c9880[];
void func_02043064(const Oam021570f0 *attr, u32 *w, u32 *h);
void func_ov000_0215724c(void *p, s32 x, s32 y, s32 z);
void func_ov000_021577a0(void *p, s32 x, s32 y, s32 z);
void func_ov000_0215793c(void *p, s32 x, s32 y, s32 z);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

void func_ov000_021570f0(BOOL alt, s32 x, s32 y, s32 z, s32 unused, const Oam021570f0 *oam,
                         const ImgAttr021570f0 *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx) {
    void *c = (void *)ctx;
    s32 shift;
    u16 charName;
    u32 h;
    u32 w;
    u32 fmt;
    u32 pal;
    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    func_02043064(oam, &w, &h);
    REG_TEXIMAGE_PARAM = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | (img->plttUse << 29);
    fmt = data_ov000_021c9880[(oam->attr01 << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    if (!alt) {
        func_ov000_0215724c(c, x - 0x7f000, y - 0x60000, z);
        func_ov000_021577a0(c, x - 0x7f000, y - 0x60000, z);
    } else {
        func_ov000_0215793c(c, x - 0x7f000, y - 0x60000, z);
    }
}

}
