#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern Ov009Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);

void func_ov009_021facf0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x5401, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x541f, 0x15);
        self->unk_ea_10 = 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_021fad54(Ov009Actor *self) {
    Ov009Actor *a;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x1000, 0x1001);
    }
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    self->unk_c8 = 0x50000;
}

}
