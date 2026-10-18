#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern void func_ov000_0218ffdc(Ov009Sub38 *m, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov009Sub38 *m, u16 *rot, s32 a);
extern void func_ov000_021903b4(Ov009Sub38 *m);
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL func_ov009_02207d98(Ov009Multi *self) {
    BOOL r = func_ov003_021d16cc(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        func_ov000_021903b4(&self->models[i]);
    }
    return r;
}

}
