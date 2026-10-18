#include "ov008/ov008.h"
// OAM attributes as 32-bit bitfields (GXOamAttr).
struct Ov008Oam {
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
    u32 _3 : 16;
};
struct Ov008GlyphInfo {
    u16 type;
    u16 unk_02;
    u32 unk_04;
    u32 base;
};
extern "C" {

Ov008Oam *func_ov008_021cd26c(void *a, Ov008GlyphInfo *info, Ov008Oam *oam, u16 *n) {
    u16 cnt = *n;
    Ov008Oam *last = &oam[cnt - 1];
    if (info->type == 2) {
        u32 c = last[0].charNo;
        s32 delta = c - last[-1].charNo;
        u32 val = info->base;
        if (val >= 10) {
            s32 x = last[0].x;
            if (x > 0xff) {
                x |= ~0xff;
            }
            last[0].charNo = c - (val % 10) * delta;
            last[0].x = (u16)(x + 6);
            last[-1].charNo = c - (val / 10) * delta;
            last[-1].x = (u16)(x - 6);
            last[-1].y = last[0].y;
            oam = &last[-1];
            cnt = 2;
        } else {
            last[0].charNo = c - (val % 10) * delta;
            oam = last;
            cnt = 1;
        }
    }
    *n = cnt;
    return oam;
}

Ov008Oam *func_ov008_021cd3dc(void *a, Ov008GlyphInfo *info, Ov008Oam *oam, u16 *n) {
    u16 cnt = *n;
    Ov008Oam *last = &oam[cnt - 1];
    if (info->type == 6) {
        u32 c = last->charNo;
        u32 b = info->base;
        oam->x = 0;
        oam->y = 0;
        oam->charNo = c - b;
        cnt = 1;
    }
    *n = cnt;
    return oam;
}

}
