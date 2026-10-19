// Built at a lower optimization level than the game code.
#pragma optimization_level 3

#include "ov004/dsprot.h"

#pragma force_active on

u8 func_ov004_021cd7dc(Rc4 *c) {
    u32 i = (c->i + 1 + c->x) & 0xff;
    u8 a = c->s[i];
    u32 j = (c->x + (a + c->j)) & 0xff;
    u8 b = c->s[j];
    c->i = i;
    c->j = j;
    c->s[j] = a;
    c->s[i] = b;
    return c->s[(a + b) & 0xff];
}

s32 func_ov004_021cd834(Rc4 *c, u8 *src, u8 *dst, u32 len) {
    u32 i;
    u8 prev = 0;
    if (len & 3) {
        return prev - 1;
    }
    for (i = 0; i < len; i += 4) {
        u8 *s = src + i;
        u8 *d;
        switch (DSPROT_FN(Ov004ClassifyFn, 0)(*(u32 *)(src + i))) {
            case 1:
                s[3] ^= 1;
            case 2: {
                u32 w = *(u32 *)s;
                d = dst + i;
                *(u32 *)(dst + i) = ((w & 0xff000000) ^ 0x1000000) | (((w & 0xffffff) + 0xc82) & 0xffffff);
                break;
            }
            case 3:
                *(u32 *)s ^= 0x1000000;
            default:
                dst[i] = c->x = s[0] ^ DSPROT_FN(Ov004NextFn, 3)(c);
                d = dst + i;
                d[1] = c->x = s[1] ^ DSPROT_FN(Ov004NextFn, 3)(c);
                d[2] = c->x = s[2] ^ DSPROT_FN(Ov004NextFn, 3)(c);
                break;
        }
        prev = d[3] = prev ^ s[3];
        c->x -= prev;
    }
    return 0;
}

#pragma force_active reset
