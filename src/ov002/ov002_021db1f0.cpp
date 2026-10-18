#include "ov002/ov002.h"

extern "C" {

static inline BOOL func_ov002_021db1f0_is5(void *t) {
    return FIELD(t, 4, s32) == 5 ? TRUE : FALSE;
}
void func_ov002_021db1f0(void *self) {
    switch (FIELD(self, 0x18, s32)) {
    case 0:
        FIELD(FIELD(self, 0xc, void *), 0xc, u32) &= ~2;
        FIELD(FIELD(self, 0x10, void *), 0xc, u32) &= ~2;
        FIELD(self, 0x18, s32) = 1;
        break;
    case 1:
        break;
    case 2:
        if (func_ov002_021db1f0_is5(FIELD(self, 0xc, void *)) && func_ov002_021db1f0_is5(FIELD(self, 0x10, void *))) {
            FIELD(self, 0x18, s32) = 3;
        }
        break;
    case 3:
        break;
    }
    FIELD(self, 0xc, VObject *)->v0x1c();
    FIELD(self, 0x10, VObject *)->v0x1c();
}

}
