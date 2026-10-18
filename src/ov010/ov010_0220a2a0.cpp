#include "ov010/ov010.h"

struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};

extern "C" {

extern u8 data_ov010_02210240[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

u8 func_ov010_0220a2a0(void *self) {
    return FLD(u8, self, 4);
}

Ov010Trig *func_ov010_0220a2a8(Ov010Trig *self) {
    self->vtbl = data_ov010_02210240;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    return self;
}

void *func_ov010_0220a2d8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a300(void *self) {
    FLD(void *, self, 0) = data_ov010_02210240;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_0220a330(Ov010Trig *self, s32 a) {
    self->unk_08 = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_0220a35c(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

}
