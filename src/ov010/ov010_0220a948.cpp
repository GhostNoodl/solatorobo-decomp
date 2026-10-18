#include "ov010/ov010.h"

extern "C" {

static inline void Ov010_0220a948_Set(void *self, u16 c, u16 d, s32 mode, s32 a, s32 b) {
    FLD(u16, self, 0xd0) = c;
    FLD(u16, self, 0xd2) = d;
    FLD(s32, self, 0xdc) = mode;
    FLD(s32, self, 0xe0) = a;
    FLD(s32, self, 0xe4) = b;
}

void func_ov010_0220a948(void *self, s32 mode, s32 a, s32 b, u16 c, u16 d) {
    switch (mode) {
    case 0:
        Ov010_0220a948_Set(self, c, d, mode, a, 0);
        break;
    case 1:
        Ov010_0220a948_Set(self, c, d, mode, 0, b);
        break;
    }
}

}
