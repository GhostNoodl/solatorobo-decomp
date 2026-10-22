#include "ov002/ov002.h"

typedef struct Oam8d00 {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
    u32 chr : 10;
    u32 a2 : 22;
} Oam8d00;

extern "C" {

// OAM callback that draws a two-digit number. div, x, chr and k are locals passed as unused
// register/stack parameters (the locals-as-parameters lever); see docs/MATCHING.md round ovmid7.
Oam8d00 *func_ov002_021d8d00(void *m, u16 *cell, Oam8d00 *oam, u16 *num, u32 div, s32 x, u32 chr, s32 k) {
    u16 n = *num;
    Oam8d00 *last = &oam[n - 1];
    if (*cell == 6) {
        u32 val;
        s32 y;
        BOOL shown = FALSE;
        chr = last->chr;
        val = FIELD(FIELD(cell, 0x8, u8 *), 0xa8, u16);
        div = 1;
        for (k = 1; k < 2; k++) {
            div *= 10;
        }
        n = 0;
        y = FIELD(m, 0x100, s32);
        x = FIELD(m, 0xfc, s32);
        if (val >= 100) {
            val = 99;
        }
        for (k = 2; k > 0; k--) {
            u32 d = val / div;
            if ((k == 1 && !shown) || shown || d != 0) {
                oam[n].x = (u16)x;
                oam[n].y = (u16)y & 0x1ff;
                oam[n].chr = chr - d;
                n++;
                shown = TRUE;
            }
            val -= d * div;
            div /= 10;
            x += 8;
        }
    }
    *num = n;
    return oam;
}

}
