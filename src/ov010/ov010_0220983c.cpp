#include "ov010/ov010.h"

struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
};

extern "C" {

extern u8 data_ov010_022102a0[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_0220983c(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220984c(Ov010Trig *self, u16 a) {
    self->unk_06 = a;
    self->b1 = 1;
}

Ov010Trig *func_ov010_02209860(Ov010Trig *self) {
    self->vtbl = data_ov010_022102a0;
    func_ov000_02198328((u8 *)self + 0x20);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_02209898(void *self) {
    FLD(void *, self, 0) = data_ov010_022102a0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_022098c0(void *self) {
    FLD(void *, self, 0) = data_ov010_022102a0;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

}
