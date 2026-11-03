#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Sys/Pad.h"

extern "C" {


static inline BOOL Lo_Active021597dc(Lo021cb3a8 *self) {
    return self->busy ? FALSE : TRUE;
}

static inline BOOL Lo_Settled021597dc(Lo021cb3a8 *self) {
    BOOL r = FALSE;
    if (self->topItem == self->unk_a4 && self->unk_b3 == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy021597dc(Lo021cb3a8 *self) {
    return Lo_Settled021597dc(self) ? FALSE : TRUE;
}

// The list input handler of Lo_02155770.cpp without the item and sub-menu cases.
void Lo021cb3a8_HandleInput(Lo021cb3a8 *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active021597dc(self)) {
        return;
    }
    if (self->topItem == self->unk_a4 && self->hidden) {
        self->busy = 1;
        self->state = 1;
        return;
    }
    if (self->items == NULL) {
        return;
    }
    if (self->flag2) {
        return;
    }
    if (self->hidden) {
        return;
    }
    cont = gPad->cur;
    trig = gPad->trig;
    if (cont == 0) {
        self->unk_b3 = 0;
    }
    self->unk_b2--;
    if (self->unk_9e == 0) {
        if (self->unk_b2 < (self->unk_b3 >> 1)) {
            self->unk_b2 = 0;
            if (cont & 0x40) {
                self->vfunc_ac(1, 0);
            } else if (cont & 0x80) {
                self->vfunc_b4(1, 0);
            } else {
                if (self->itemCount > self->rows && (self->flags & 0x10000)) {
                    if (cont & 0x200) {
                        self->vfunc_b0(self->rows, 0);
                    } else if (cont & 0x100) {
                        self->vfunc_b8(self->rows, 0);
                    }
                }
                self->unk_b3 = 0;
            }
        } else if (trig & 3) {
            self->unk_b3 = 0;
        }
    }
    if (Lo_Busy021597dc(self)) {
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            self->flags |= 2;
        }
        return;
    }
}

}
