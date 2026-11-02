#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cdda4(Task021ef530 *self) {
    switch (self->state) {
    case 8:
        self->unk_40->flags &= ~2;
        self->unk_44->flags &= ~2;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        break;
    }
    if (!func_ov002_isCurrent021ccd40(self)) {
        return;
    }
    if (self->unk_40 != NULL) {
        BOOL a = FALSE;
        BOOL b = FALSE;
        BOOL c = FALSE;
        if (!data_ov000_021ccd34) {
            BOOL t = !self->unk_04_0;
            if (t) {
                c = TRUE;
            }
        }
        if (c) {
            if (self->vfunc_54()) {
                b = TRUE;
            }
        }
        if (b) {
            if (!self->unk_04_2) {
                a = TRUE;
            }
        }
        if (a) {
            self->unk_40->flags &= ~4;
        } else {
            self->unk_40->flags |= 4;
        }
        self->unk_40->vfunc_1c();
    }
    if (self->unk_44 != NULL) {
        self->unk_44->vfunc_1c();
    }
}

}
