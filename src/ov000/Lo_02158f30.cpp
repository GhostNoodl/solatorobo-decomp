#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);

static inline BOOL LoSubReady(void *p) {
    if (LFLD(void *, p, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, p, 0x6c))) {
        LFLD(void *, p, 0x6c) = NULL;
    } else {
        return LBIT(p, 4).b6 == 0 ? TRUE : FALSE;
    }
    return TRUE;
}

void func_ov000_02158f30(Lo021cb3a8 *self, s32 n, s32 b) {
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

void func_ov000_02158f98(Lo021cb3a8 *self, s32 n, s32 b) {
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
