#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_021950e8(Ov009Obj *self, u8 *msg);
extern void func_ov000_02194758(Ov009Obj *self);
extern void *Target_Get(void *p);

void func_ov009_02214360(Ov009ActExVt_0221828c *self, u8 *msg) {
    if (msg[5] == 6) {
        FLD(u8, self, 0xce) = msg[8];
        self->unk_30 |= 1 << msg[5];
        msg[5] = 0;
    }
    func_ov000_021950e8(self, msg);
}

void Ov009ActExVt_0221828c_Start(Ov009ActExVt_0221828c *self) {
    u8 *p;
    func_ov000_02194758(self);
    self->unk_d0 = 0;
    p = (u8 *)Target_Get(self->unk_4c);
    if (p != NULL) {
        self->unk_d2 = FLD(u16, p, 0xc);
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
