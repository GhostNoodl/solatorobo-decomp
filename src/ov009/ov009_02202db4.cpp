#include "ov009/ov009.h"

extern "C" {

extern void *func_ov000_0219bf90(void);

void func_ov009_02202db4(Ov009Actor *self) {
    u16 *p;
    u16 v;
    Ov009Sub38 *m;
    func_ov003_021d1e8c(self);
    if (!self->unk_93_4) {
        return;
    }
    func_ov000_0219bf90();
    p = self->unk_50;
    v = self->unk_b0->unk_08;
    if (*p >= v) {
        return;
    }
    *p = v;
    m = self->unk_38;
    FLD(u16, m, 0xb6) = 0x14bf;
    FLD(u16, m, 0xb8) = 0x14bf;
    FLD(u16, m, 0xba) = 1;
    FLD(u16, m, 0xbc) = 0;
}

}
