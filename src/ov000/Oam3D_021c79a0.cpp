#include "types.h"

typedef struct {
    u32 attr01;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Oam021c79a0;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} ImgAttr021c79a0;

extern "C" {

extern u32 data_ov000_021ca5dc[];
void func_02043064(const Oam021c79a0 *attr, u32 *w, u32 *h);
void func_ov000_021c7af8(void *p, s32 x, s32 y, s32 z);
void func_ov000_021c7f88(void *p, s32 x, s32 y, s32 z);
void func_ov000_021c8120(void *p, s32 x, s32 y, s32 z);

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x40004a8)
#define REG_TEXPLTT_BASE (*(vu32 *)0x40004ac)

void func_ov000_021c79a0(BOOL alt, s32 x, s32 y, s32 z, s32 unused, const Oam021c79a0 *oam,
                         const ImgAttr021c79a0 *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx) {
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
    fmt = data_ov000_021ca5dc[(oam->attr01 << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    REG_TEXPLTT_BASE = (plttBase + pal) >> (4 - (fmt == 2));
    {
    void *c = (void *)ctx;
    if (alt) {
        func_ov000_021c8120(c, x - 0x7f000, y - 0x60000, z);
    } else {
        func_ov000_021c7af8(c, x - 0x7f000, y - 0x60000, z);
        func_ov000_021c7f88(c, x - 0x7f000, y - 0x60000, z);
    }
    }
}

}
