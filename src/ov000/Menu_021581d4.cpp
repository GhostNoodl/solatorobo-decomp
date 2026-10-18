#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_021581d4(VObj *self, s32 delta, s32 arg) {
    s8 old;
    s32 total;
    s32 vis;
    s32 scroll;
    s32 zero;
    u8 *node;
    old = LFLD(s8, self, 0xb1);
    vis = LFLD(s32, self, 0x20);
    total = LFLD(s16, self, 0x9c);
    LFLD(s8, self, 0xb0) = old;
    LFLD(s8, self, 0xb1) = old + (s8)delta;
    zero = 0;
    scroll = zero;
    if (total <= vis) {
        if (LFLD(s8, self, 0xb1) >= total) {
            LFLD(s8, self, 0xb1) = total - 1;
        } else if (LFLD(s8, self, 0xb1) >= vis) {
            LFLD(s8, self, 0xb1) = vis - 1;
        }
    } else {
        node = LFLD(u8 *, self, 0x98);
        if (LFLD(s16, node, 4) + vis >= total) {
            if (LFLD(s8, self, 0xb1) >= vis) {
                LFLD(s8, self, 0xb1) = vis - 1;
            }
        } else {
            scroll = LFLD(s8, self, 0xb1) - (vis - 2);
            if (scroll > 0) {
                if (scroll + LFLD(s16, node, 4) + vis <= total) {
                    LFLD(s8, self, 0xb1) = vis - 2;
                } else {
                    LFLD(s8, self, 0xb1) = vis - 1;
                    scroll = total - (LFLD(s16, node, 4) + vis);
                }
            } else {
                scroll = zero;
            }
        }
    }
    self->vfunc_bc(scroll, arg);
    LFLD(s16, self, 0xa2) = 4;
}
}
