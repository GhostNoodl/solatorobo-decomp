#include "ov000/VObj.h"

extern "C" {

void MessageQueue021cb980_Push0f(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 0xf, a, b);
}

void MessageQueue021cb980_Push10(VObj *self, s32 a) {
    self->vfunc_0c(0, 0x10, a, 0);
}

void MessageQueue021cb980_Push11(VObj *self, s32 a) {
    self->vfunc_0c(0, 0x11, a, 0);
}

void MessageQueue021cb980_Push12(VObj *self, s32 a, s32 b, s32 c) {
    self->vfunc_0c(0, 0x12, (a << 16) | (b << 8) | c, 0);
}

void MessageQueue021cb980_Push13(VObj *self, s32 a, s32 b) {
    self->vfunc_0c(0, 0x13, a, b);
}

}
