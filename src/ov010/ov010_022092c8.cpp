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
};

extern "C" {

extern u8 data_ov010_02210280[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

Ov010Trig *func_ov010_022092c8(Ov010Trig *self) {
    self->vtbl = data_ov010_02210280;
    func_ov000_02198328((u8 *)self + 0x1c);
    self->b0 = 0;
    self->b1 = 0;
    return self;
}

void *func_ov010_02209300(void *self) {
    FLD(void *, self, 0) = data_ov010_02210280;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_02209328(void *self) {
    FLD(void *, self, 0) = data_ov010_02210280;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_02209358(Ov010Trig *self, s32 a) {
    self->unk_0c = a;
    self->b0 = 1;
    self->unk_0a = 0xffff;
    func_ov003_021da48c((u8 *)self + 0x1c, 0);
    return TRUE;
}

void func_ov010_02209390(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

}
