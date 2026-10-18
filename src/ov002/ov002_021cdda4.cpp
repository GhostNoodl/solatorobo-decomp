#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cdda4(void *self) {
    switch (FIELD(self, 0x8, s32)) {
    case 8:
        FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~2;
        FIELD(FIELD(self, 0x44, void *), 0xc, u32) &= ~2;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 2;
        FIELD(FIELD(self, 0x44, void *), 0xc, u32) |= 2;
        break;
    }
    if (!func_ov002_isCurrent021ccd40(self)) {
        return;
    }
    if (FIELD(self, 0x40, void *) != NULL) {
        BOOL a = FALSE;
        BOOL b = FALSE;
        BOOL c = FALSE;
        if (!data_ov000_021ccd34) {
            BOOL t = !FIELD(self, 0x4, Bits32).b0;
            if (t) {
                c = TRUE;
            }
        }
        if (c) {
            if (((VObject *)self)->v0x54()) {
                b = TRUE;
            }
        }
        if (b) {
            if (!FIELD(self, 0x4, Bits32).b2) {
                a = TRUE;
            }
        }
        if (a) {
            FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~4;
        } else {
            FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 4;
        }
        FIELD(self, 0x40, VObject *)->v0x1c();
    }
    if (FIELD(self, 0x44, void *) != NULL) {
        FIELD(self, 0x44, VObject *)->v0x1c();
    }
}

}
