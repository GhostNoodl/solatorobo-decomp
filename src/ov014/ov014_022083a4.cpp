#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov003_021daab0(void *p);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_022083a4(Ov014Actor *self) {
    u8 *g;
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov003_021daab0(FLD(void *, self, 0xd8));
    g = (u8 *)data_ov000_021ccd54;
    FLD(u8, g, 0x18c) = 0;
    FLD(u8, g, 0x18d) = 0;
    FLD(u8, g, 0x18e) = 0;
    FLD(u8, g, 0x18f) = 0;
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    self->v08();
}

}
