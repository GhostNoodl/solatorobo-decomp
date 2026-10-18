#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ce10c(VObject *self) {
    void *m;
    FIELD(self, 0x4, u32) &= ~2;
    if (self->v0x28()) {
        return;
    }
    m = func_0203dd9c(0x160);
    if (m != NULL) {
        char *nm = data_ov002_021ef3f9;
        char *file = data_ov002_021ef3e4;
        if (nm) {
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, nm, 0);
            STD_CopyString((u8 *)m + 0x2c, file);
        }
    }
    FIELD(self, 0x3c, void *) = m;
    func_020417e0(FIELD(self, 0x3c, void *), func_02034d88(func_02035f30(data_ov002_021ef3e4, data_ov002_021ef3f9, 2), data_ov002_021ef3f9));
    FIELD(FIELD(self, 0x3c, void *), 0x6c, u32) |= 2;
    func_02041d9c(FIELD(self, 0x3c, void *), 0, 0);
    {
        void *p = FIELD(self, 0x3c, void *);
        FIELD(p, 0xfc, s32) = 0;
        FIELD(p, 0x100, s32) = 0;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x150, s32) = -0x1fe66;
    FIELD(self, 0x2c, s32) = 0;
    func_ov000_02173648(self);
    FIELD(self, 0x4c, u8) = 0;
    FIELD(self, 0x4d, u8) = 0;
    FIELD(self, 0x4e, u8) = 3;
}

}
