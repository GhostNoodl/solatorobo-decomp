#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_02202fe8(Ov014Actor *self);
extern void func_ov014_022033a8(Ov014Actor *self);
extern void func_ov014_022038b8(Ov014Actor *self);

void func_ov014_02202f1c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
    case 1:
    case 2:
        func_ov014_02202fe8(self);
        break;
    case 10:
    case 11:
    case 12:
        func_ov014_022033a8(self);
        break;
    case 20:
    case 21:
    case 22:
        func_ov014_022038b8(self);
        break;
    case 30:
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

}
