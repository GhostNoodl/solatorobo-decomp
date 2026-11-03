#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {


void Lo021cb3a8_CursorDown(Lo021cb3a8 *self, s32 n, s32 b) {
    s8 old = self->cursor;
    s16 max = self->itemCount;
    s32 m = self->rows;
    self->unk_b0 = old;
    if (max > m) {
        self->cursor = old + (s8)n;
        if (self->cursor + m > max) {
            self->cursor = max - m;
        }
    }
    self->vfunc_bc(self->cursor - self->unk_b0, b);
    self->unk_a2 = 4;
}

void Lo021cb3a8_PageDown(Lo021cb3a8 *self, s32 n, s32 b) {
    s8 old = self->cursor;
    self->unk_b0 = old;
    if (self->flags & 0x20000) {
        self->cursor = old + (s8)n;
        if (self->cursor + self->rows > self->itemCount) {
            self->cursor = self->itemCount - self->rows;
        }
    }
    self->vfunc_bc(self->cursor - self->unk_b0, b);
    self->unk_a2 = 8;
}

}
