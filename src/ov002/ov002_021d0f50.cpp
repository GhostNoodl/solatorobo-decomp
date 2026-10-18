#include "ov002/ov002.h"

extern "C" {

static inline bool ov002_Task50_getFlag1(Task50 *self) {
    return self->flag1;
}

void func_ov002_021d0f50(Task50 *self) {
    switch (self->unk_08) {
    case 8:
        if (func_ov002_isMode4() || func_ov002_isMode4b()) {
            func_0203c9e8(0x3f, -1);
            func_0203cb78(0xa000, 0, -1);
        }
        if (self->unk_3c != NULL) {
            FIELD(self->unk_3c, 0xc, u32) &= ~2;
        }
        if (self->unk_40 != NULL) {
            FIELD(self->unk_40, 0xc, u32) &= ~2;
        }
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        if (self->unk_3c != NULL) {
            FIELD(self->unk_3c, 0xc, u32) |= 2;
        }
        if (self->unk_40 != NULL) {
            FIELD(self->unk_40, 0xc, u32) |= 2;
        }
        break;
    }
    if (self->unk_3c != NULL) {
        if (self->v0x54()) {
            BOOL f = ov002_Task50_getFlag1(self);
            if (!f) {
                FIELD(self->unk_3c, 0xc, u32) &= ~4;
                goto done;
            }
        }
        FIELD(self->unk_3c, 0xc, u32) |= 4;
    done:
        ((VObject *)self->unk_3c)->v0x1c();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x1c();
    }
}

}
