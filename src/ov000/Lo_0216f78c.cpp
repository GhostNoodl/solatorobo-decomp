#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0216f23c(void *p, s32 a);

void func_ov000_0216f78c(VObj *self) {
    u8 buf[0x10];
    self->vfunc_1c();
    while (self->vfunc_14(buf, 1)) {
        self->vfunc_10(buf);
    }
    func_ov000_0216f23c((u8 *)self + 8, 0);
}

}
