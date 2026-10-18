#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0219bf90(void);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_022137ac(Ov009Actor *self) {
    u8 *p;
    Ov009Actor *a;
    func_ov003_021d112c(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    FLD(s32, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(s32, self, 0xf8) = 0;
    self->unk_b6 = 0x78;
}

}
