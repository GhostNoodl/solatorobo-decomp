#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

BOOL func_ov000_02152a58(void *self);
BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);
void func_ov000_0215429c(void *self);

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


BOOL func_ov000_021580e8(UiList *self) {
    BOOL r = func_ov000_02152a58(self);
    if (self->unk_b4 != NULL && !func_02054f10(self->unk_b4, 0xffff)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02158120(UiList021cb4a8 *self, s32 delta, s32 arg) {
    s8 sel = self->cursor;
    s32 off = 0;
    self->unk_b0 = sel;
    self->cursor = self->cursor - (s8)delta;
    if (self->itemCount <= self->rows) {
        if (self->cursor <= 0) {
            self->cursor = 0;
        }
    } else if (self->topItem->index == 0) {
        if (self->cursor <= 0) {
            self->cursor = 0;
        }
    } else {
        off = self->cursor - 1;
        if (off < 0) {
            if (off + self->topItem->index >= 0) {
                self->cursor = 1;
            } else {
                self->cursor = 0;
                off = -self->topItem->index;
            }
        } else {
            off = 0;
        }
    }
    self->vfunc_bc(off, arg);
    self->unk_a2 = 4;
}

}
