#include "ov000/VObj.h"

extern "C" {

void func_ov000_02172390(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 0xf, a, b);
}

void func_ov000_021723b4(VObj *self, s32 a) {
    self->vfunc_0c(0, 0x10, a, 0);
}

void func_ov000_021723d8(VObj *self, s32 a) {
    self->vfunc_0c(0, 0x11, a, 0);
}

void func_ov000_021723fc(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 0x12, (a << 16) | (b << 8) | c, 0);
}

void func_ov000_0217242c(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 0x13, a, b);
}

}
