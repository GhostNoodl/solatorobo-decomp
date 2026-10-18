#include "ov000/VObj.h"

extern "C" {

void func_ov000_0216f23c(void *p, s32 a);
extern void *data_ov000_021ccd44;
void func_ov000_02180bfc(void *p);

void func_ov000_021721c8(void *self) {
    func_ov000_0216f23c((u8 *)self + 8, 1);
    if (data_ov000_021ccd44 != NULL) {
        func_ov000_02180bfc(data_ov000_021ccd44);
    }
}

void func_ov000_021721f4(VObj *self) {
    self->vfunc_0c(0, 5, 0, 0);
}

void func_ov000_02172218(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 6, b, (a << 16) | c);
}

void func_ov000_02172240(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 7, a, b);
}

void func_ov000_02172264(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 8, c, (a << 16) | b);
}


void func_ov000_02172288(VObj *self, s32 flag, s32 a) {
    if (flag) {
        self->vfunc_0c(0, 9, a, 0);
    } else {
        self->vfunc_0c(0, 10, a, 0);
    }
}
}
