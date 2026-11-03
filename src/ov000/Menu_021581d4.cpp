#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

void UiList021cb4a8_CursorDown(UiList021cb4a8 *self, s32 delta, s32 arg) {
    s8 old;
    s32 total;
    s32 vis;
    s32 scroll;
    s32 zero;
    UiListItem *node;
    old = self->cursor;
    vis = self->rows;
    total = self->itemCount;
    self->unk_b0 = old;
    self->cursor = old + (s8)delta;
    zero = 0;
    scroll = zero;
    if (total <= vis) {
        if (self->cursor >= total) {
            self->cursor = total - 1;
        } else if (self->cursor >= vis) {
            self->cursor = vis - 1;
        }
    } else {
        node = self->topItem;
        if (node->index + vis >= total) {
            if (self->cursor >= vis) {
                self->cursor = vis - 1;
            }
        } else {
            scroll = self->cursor - (vis - 2);
            if (scroll > 0) {
                if (scroll + node->index + vis <= total) {
                    self->cursor = vis - 2;
                } else {
                    self->cursor = vis - 1;
                    scroll = total - (node->index + vis);
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
