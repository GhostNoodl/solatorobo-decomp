#include "ov009/ov009.h"

extern "C" {

extern void func_ov003_021d4fd8(Ov009Actor *self);

void func_ov009_022117ac(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0xfc) = FLD(u8, FLD(u8 *, self, 0x100) + FLD(u8, self, 0xfc) * 16, 0xc);
        FLD(u8, self, 0xfe) = 0;
    }
    func_ov003_021d4fd8(self);
}

}
