#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

BOOL UiObj_IsLoaded(UiObj *self);
BOOL Model_IsReady(void *p, s32 a);


BOOL UiList_IsLoaded(UiList *self) {
    BOOL r = UiObj_IsLoaded(self);
    if (self->unk_b4 != NULL && !Model_IsReady(self->unk_b4, 0xffff)) {
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
