#include "types.h"
#include "ov000/ObjLayouts.h"

extern "C" {

s32 FX_Div(s32 a, s32 b);

void func_ov000_021c403c(LoBase021ccb54_021ccbe0 *self, s32 sel) {
    s32 vis;
    s32 n;
    s32 half;
    s32 i;
    s32 j;
    ListRow *item;
    n = self->unk_98;
    vis = self->rows;
    if (sel > n - 1) {
        sel = n - 1;
    }
    half = (vis - 1) / 2;
    if (n < vis) {
        self->unk_9c = 0;
    } else {
        s32 top = sel - half;
        if (top < 0) {
            self->unk_9c = 0;
        } else if (top > n - vis) {
            self->unk_9c = n - vis;
        } else {
            self->unk_9c = top;
        }
    }
    self->unk_a8 = sel;
    item = self->unk_94;
    if (item == NULL) {
        self->unk_a0 = NULL;
    } else {
        for (i = 0; item != NULL; item = item->next, i++) {
            if (i == sel) {
                break;
            }
        }
        self->unk_a0 = item;
        self->unk_ac = 7;
        for (j = sel - 1; j >= self->unk_9c; j--) {
            self->unk_ac += (u16)item->height;
            item = item->prev;
        }
    }
    if (self->unk_98 < self->rows) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->rows << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
}

}
