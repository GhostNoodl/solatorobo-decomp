#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern void func_ov000_021984f4(void *p, int a, int b);
extern void func_ov000_0219864c(ActorSub48 *p, VecFx32 *a, u16 *b);

void func_ov003_021d6cf4(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov003_021d6d14(Ov003Actor *self) {
    if (self->hit != NULL) {
        func_ov000_0219864c(self->hit, 0, 0);
    }
}

void func_ov003_021d6d34() {

}

void func_ov003_021d6d38() {

}

void func_ov003_021d6d3c() {

}

void func_ov003_021d6d40() {

}

void func_ov003_021d6d44() {

}

void func_ov003_021d6d48() {

}

void func_ov003_021d6d4c() {

}

void func_ov003_021d6d50() {

}

void func_ov003_021d6d54(Ov003Actor *self) {
    self->vfunc_54();
}

void func_ov003_021d6d68(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void func_ov003_021d6d88(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void func_ov003_021d6dac(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void Ov003ActVt_021f7c0c_Start(Ov003Actor *self) {
    func_ov003_021d112c(self);
    if (self->unk_1a != 0) {
        self->fsm->flags |= 0x100000000ULL;
    }
}

}
