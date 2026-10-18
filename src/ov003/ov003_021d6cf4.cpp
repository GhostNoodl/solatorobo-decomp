#include "types.h"

typedef void (*VFunc)(void *);

typedef struct {
    u32 unk_00;
    u64 flags;
} Ov003ActorState;

#define V(n) virtual void v##n();

class Ov003Actor {
public:
    V(00) V(04) V(08) V(0c) V(10) V(14) V(18) V(1c) V(20) V(24) V(28) V(2c) V(30) V(34) V(38) V(3c)
    V(40) V(44) V(48) V(4c) V(50) V(54) V(58) V(5c) V(60) V(64) V(68) V(6c) V(70)
    u8 unk_04[0x16];
    s16 unk_1a;
    u8 unk_1c[0x24];
    Ov003ActorState *state;
    void *unk_44;
    void *unk_48;
    u8 unk_4c[0xa2];
    u16 unk_ee_0 : 2;
    u16 unk_ee_2 : 2;
    u16 unk_ee_4 : 1;
    u16 unk_ee_5 : 1;
};

extern "C" {

extern void func_ov000_021984f4(void *p, int a, int b);
extern void func_ov000_0219864c(void *p, int a, int b);
extern void func_ov003_021d112c(Ov003Actor *self);

void func_ov003_021d6cf4(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov003_021d6d14(Ov003Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
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
    self->v54();
}

void func_ov003_021d6d68(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov003_021d6d88(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov003_021d6dac(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->v64();
}

void func_ov003_021d6dd0(Ov003Actor *self) {
    func_ov003_021d112c(self);
    if (self->unk_1a != 0) {
        self->state->flags |= 0x100000000ULL;
    }
}

}
