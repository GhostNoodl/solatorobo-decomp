#include "ov014/ov014.h"

extern "C" {

void func_ov014_02208d90(Ov014Actor *self) {
    FLD(u32, self, 0xd0) |= 0x1000;
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

}
