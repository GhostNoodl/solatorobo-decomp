#include "ov010/ov010.h"
extern "C" {
extern void func_ov000_02198360(void *a, s32 b, s32 c);

void func_ov010_02202838(void *self) {
    void *m = FLD(void *, self, 0x40);
    switch (FLD(u8, m, 0x13)) {
    case 0x20:
        if (FLD(Ov010Flags8, self, 0xce).b0) {
            func_ov000_02198360(m, 0x21, 1);
        }
        break;
    case 0x21:
        FLD(u16, self, 0xd0)++;
        if (FLD(u16, self, 0xd0) > 0x3c) {
            FLD(u16, self, 0xd0) = 0;
            func_ov000_02198360(m, 0x22, 1);
        }
        break;
    case 0x22:
        FLD(u16, self, 0xd0)++;
        if (FLD(u16, self, 0xd0) > 0x3c) {
            FLD(u16, self, 0xd0) = 0;
            func_ov000_02198360(m, 0x23, 1);
        }
        break;
    }
}

void func_ov010_022028ec(void *self) {
    void *m = FLD(void *, self, 0x40);
    switch (FLD(u8, m, 0x13)) {
    case 0x20:
        if (FLD(Ov010Flags8, self, 0xce).b0) {
            func_ov000_02198360(m, 0x21, 1);
        }
        break;
    case 0x21:
        FLD(u16, self, 0xd0)++;
        if (FLD(u16, self, 0xd0) > 0x28) {
            FLD(u16, self, 0xd0) = 0;
            func_ov000_02198360(m, 0x22, 1);
        }
        break;
    case 0x22:
        FLD(u16, self, 0xd0)++;
        if (FLD(u16, self, 0xd0) > 0x64) {
            FLD(u16, self, 0xd0) = 0;
            func_ov000_02198360(m, 0x23, 1);
        }
        break;
    }
}

void func_ov010_022029a0(void *self) {
}
}
