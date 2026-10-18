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
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
};

extern "C" {

extern u8 data_ov010_022102c0[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_02209568(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_02209578(Ov010Trig *self, s32 a, s32 b, s32 c, u16 d, u16 e) {
    self->b1 = 1;
    self->unk_18 = a;
    self->unk_10 = b;
    self->unk_14 = c;
    self->unk_06 = d;
    self->unk_08 = e;
}

Ov010Trig *func_ov010_022095a8(Ov010Trig *self) {
    self->vtbl = data_ov010_022102c0;
    func_ov000_02198328((u8 *)self + 0xc);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_022095e0(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02209608(void *self) {
    FLD(void *, self, 0) = data_ov010_022102c0;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02209638(Ov010Trig *self, s32 a) {
    FLD(s32, self, 8) = a;
    self->b0 = 1;
    func_ov003_021da48c((u8 *)self + 0xc, 0);
    return TRUE;
}

void func_ov010_02209664(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

}
