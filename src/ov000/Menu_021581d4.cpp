#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_021581d4(LoBase021caac8_021cb2a8 *self, s32 delta, s32 arg) {
    s8 old;
    s32 total;
    s32 vis;
    s32 scroll;
    s32 zero;
    u8 *node;
    old = self->unk_b1;
    vis = self->unk_20;
    total = self->unk_9c;
    self->unk_b0 = old;
    self->unk_b1 = old + (s8)delta;
    zero = 0;
    scroll = zero;
    if (total <= vis) {
        if (self->unk_b1 >= total) {
            self->unk_b1 = total - 1;
        } else if (self->unk_b1 >= vis) {
            self->unk_b1 = vis - 1;
        }
    } else {
        node = (u8 *)self->unk_98;
        if (LFLD(s16, node, 4) + vis >= total) {
            if (self->unk_b1 >= vis) {
                self->unk_b1 = vis - 1;
            }
        } else {
            scroll = self->unk_b1 - (vis - 2);
            if (scroll > 0) {
                if (scroll + LFLD(s16, node, 4) + vis <= total) {
                    self->unk_b1 = vis - 2;
                } else {
                    self->unk_b1 = vis - 1;
                    scroll = total - (LFLD(s16, node, 4) + vis);
                }
            } else {
                scroll = zero;
            }
        }
    }
    self->vfunc_bc(scroll, arg);
    self->unk_a2 = 4;
}
}
