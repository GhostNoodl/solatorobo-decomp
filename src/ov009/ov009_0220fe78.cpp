#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_0220fe78(Ov009Actor *self) {
    func_ov003_021d3524(self);
    func_ov000_0218d988(self, func_ov000_0218d240(self), self->unk_b0->unk_02);
}

}
