#include "ov013/ov013.h"

extern "C" {

extern char data_ov013_0220be7c[];
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218d988(Ov013Actor *self, Ov013Actor *t, s32 a);

void func_ov013_02206ca8(Ov013Actor *self) {
    Ov013Actor *t;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220be7c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    t = func_ov000_0218d240(self);
    if (t != NULL) {
        func_ov000_0218d988(self, t, 0xcd);
    }
}

}
