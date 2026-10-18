#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void func_ov000_02182590(void *p);

void func_ov000_0216e894(void *self) {
    if (LBIT(self, 0).b13 == 1) {
        return;
    }
    LBIT(self, 0).b13 = 1;
    if (LBIT(self, 0).b14 == 1) {
        LFLD(s32, self, 0xc) = 1;
    } else if (LBIT(self, 0).b10 == 1) {
        LFLD(s32, self, 0xc) = 2;
    } else {
        LFLD(s32, self, 0xc) = 3;
    }
    if (LBIT(self, 0).b6 != 1) {
        return;
    }
    func_ov000_0219bf90();
    if (!func_ov000_021b4738()) {
        s32 v = LFLD(s32, self, 0x1c);
        u8 *g;
        if (v > 0xffff) {
            v = 0xffff;
        }
        func_020627fc(LFLD(s32, self, 0xc));
        func_0206280c(v);
        g = data_ov000_021ccd54;
        g[0xac] = 1;
        func_ov000_02182590(g + 0xac);
    }
    LFLD(s32, self, 4) = 9;
}

}
