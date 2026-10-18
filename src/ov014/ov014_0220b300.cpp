#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_0220d274(Ov014Actor *self);
extern void func_ov003_021d4fd8(Ov014Actor *self);

void func_ov014_0220b300(Ov014Actor *self) {
    func_ov014_0220d274(self);
}

void func_ov014_0220b30c(Ov014Actor *self) {
    func_ov003_021d4fd8(self);
}

void func_ov014_0220b318(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, FLD(u8 *, self, 0x4c), 0) = 0xf;
    }
    func_ov003_021d5900(self);
}

}
