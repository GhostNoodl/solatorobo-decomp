#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_021950e8(Ov009Actor *self, u8 *msg);
extern void func_ov000_02194758(Ov009Actor *self);
extern void *func_ov000_02199ba0(void *p);

void func_ov009_02214360(Ov009Actor *self, u8 *msg) {
    if (msg[5] == 6) {
        FLD(u8, self, 0xce) = msg[8];
        self->unk_30 |= 1 << msg[5];
        msg[5] = 0;
    }
    func_ov000_021950e8(self, msg);
}

void func_ov009_0221439c(Ov009Actor *self) {
    u8 *p;
    func_ov000_02194758(self);
    FLD(u16, self, 0xd0) = 0;
    p = (u8 *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (p != NULL) {
        FLD(u16, self, 0xd2) = FLD(u16, p, 0xc);
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
