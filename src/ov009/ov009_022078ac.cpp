#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov009_022172af[];
extern void func_ov000_021903b4(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL func_ov009_022078ac(Ov009Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (r) {
        Ov009Vec p;
        p = self->pos;
        if (func_ov000_0219a2f4(&p, 0x2000, -0x5000) != -0x1000) {
            func_ov000_021903b4(&FLD(u8, self, 0x228));
        }
    }
    return r;
}

void func_ov009_02207910(Ov009Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80(&FLD(u8, self, 0x228), 0x1000);
}

}
