#include "ov011/ov011.h"

extern "C" {

void func_ov003_021d0edc(void *self);

#pragma force_active on
void func_ov011_022071b4(void **self) {
    ((void (*)(void *)) * (void **)((u8 *)*self + 0x7c))(self);
}

void *func_ov011_022071c8(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_022071dc(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov011_022071f8(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_0220720c(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov011_02207228(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov011_0220723c(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
#pragma force_active reset
}
