#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d6350(void *self) {
    s32 x = FIELD(self, 0x40, s32);
    s32 v = 0;
    if (x < 0x1000000) {
        v = x + 0x8000;
    }
    FIELD(self, 0x40, s32) = v;
    x = FIELD(self, 0x44, s32);
    if (x >= 0x1000000) {
        x = 0;
    } else {
        x += 0x8000;
    }
    FIELD(self, 0x44, s32) = x;
}

}
