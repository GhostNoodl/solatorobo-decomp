#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021fc7c0(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    self->pos.y += 0x4000;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    self->unk_40->flags |= 0x100000000ULL;
    FLD(u8, FLD(u8 *, self, 0x4c), 0x18) |= 2;
}

void func_ov009_021fc834(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        self->unk_38->unk_c2_0 = 0;
        self->unk_40->state++;
        break;
    case 1:
        if (Ov009_GameIdle()) {
            self->unk_38->unk_c2_0 = 1;
            func_ov000_02198360(self->unk_40, 4, 0);
        }
        break;
    }
}

}
