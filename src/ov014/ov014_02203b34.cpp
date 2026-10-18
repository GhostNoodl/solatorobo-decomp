#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_02203c00(Ov014Actor *self);
extern void func_ov014_02204134(Ov014Actor *self);
extern void func_ov014_0220446c(Ov014Actor *self);

void func_ov014_02203b34(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        func_ov014_02203c00(self);
        break;
    case 10:
    case 11:
    case 12:
        func_ov014_02204134(self);
        break;
    case 20:
    case 21:
        func_ov014_0220446c(self);
        break;
    case 30:
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

}
