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

struct Ov010Tmr {
    void *vtbl;
    u8 on;
    u8 unk_05;
    u16 unk_06;
    s32 unk_08;
};

extern "C" {

extern u8 data_ov010_02210260[];

BOOL func_ov010_0220a030(Ov010Trig *self) {
    return self->b0;
}

void func_ov010_0220a040(Ov010Trig *self, u16 a, s32 b, s32 c, s32 d, u16 e, u16 f) {
    self->b1 = 1;
    self->unk_0a = a;
    self->unk_1c = b;
    self->unk_14 = c;
    self->unk_18 = d;
    self->unk_06 = e;
    self->unk_08 = f;
}

Ov010Tmr *func_ov010_0220a078(Ov010Tmr *self) {
    self->vtbl = data_ov010_02210260;
    self->on = 0;
    return self;
}

void *func_ov010_0220a090(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    return self;
}

void *func_ov010_0220a0b8(void *self) {
    FLD(void *, self, 0) = data_ov010_02210260;
    ((Ov010V *)self)->v0c();
    func_0203de1c(self);
    return self;
}

BOOL func_ov010_0220a0e8(Ov010Tmr *self, s32 a) {
    self->on = 1;
    self->unk_06 = 0;
    self->unk_08 = a;
    return 1;
}

void func_ov010_0220a104(Ov010Tmr *self) {
    if (self->on) {
        self->on = 0;
    }
}

}
