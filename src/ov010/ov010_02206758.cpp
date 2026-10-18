#include "ov010/ov010.h"

extern "C" {
extern void func_ov010_02206784(void *self);
extern void func_ov010_02206974(void *self);

void func_ov010_02206758(void *self) {
    switch (FLD(u8, self, 0x171)) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}
}
