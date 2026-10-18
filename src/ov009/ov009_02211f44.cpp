#include "ov009/ov009.h"

extern "C" {

extern void func_0202a4c8(void *p, s32 a);

void func_ov009_02211f44(Ov009Actor *self) {
    u8 *p = FLD(u8 *, FLD(void *, self, 0x4), 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    if (FLD(u32, self, 0x8) & 0x10) {
        v = FLD(u8, self, 0xae);
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        func_0202a4c8(p + 4, 0);
    }
}

void func_ov009_02211f84(Ov009Actor *self) {
    FLD(void *, self, 0x24) = (void *)func_ov009_02211f44;
    self->unk_92 = 3;
}

}
