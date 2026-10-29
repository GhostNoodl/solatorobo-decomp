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
extern void *func_ov000_02198328(void *p);
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

extern void *data_ov000_021ccd68;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov010_0220dbc0(s32 p);
extern u16 *func_ov010_0220da74(s32 p, Ov010Vec *pos, s32 b, s32 c, s32 d, u16 e, u16 f);

static inline u8 *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov010_Activate(u8 *a) {
    if (FLD(u8, a, 0x14) == 1) {
        return;
    }
    if (!FLD(Ov010Flags8, a, 0xce).b0) {
        FLD(Ov010Flags8, a, 0xce).b0 = 1;
        FLD(Ov010Flags8, a, 0xce).b2 = 1;
        func_ov003_021da48c(a + 0x158, 2);
    }
}

void func_ov010_022093b0(Ov010Trig *self) {
    u8 *a;
    if (!self->b0) {
        return;
    }
    switch (FLD(u16, self, 0x1c)) {
    case 0: {
        Ov010Vec p;
        func_ov010_0220dbc0(self->unk_0c);
        a = Ov010_FindActor(self->unk_06);
        if (a == NULL) {
            FLD(u16, self, 0x1c) = 3;
            return;
        }
        p = FLD(Ov010Vec, a, 0x70);
        self->unk_0a = *func_ov010_0220da74(self->unk_0c, &p, FLD(s32, self, 0x18), FLD(s32, self, 0x10), FLD(s32, self, 0x14), self->unk_06, self->unk_08);
        FLD(u16, self, 0x1c) = 1;
        break;
    }
    case 1:
        a = Ov010_FindActor(self->unk_0a);
        if (a == NULL) {
            FLD(u16, self, 0x1c) = 3;
            return;
        }
        if (FLD(u8, a, 0x14) == 1) {
            return;
        }
        Ov010_Activate(a);
        FLD(u16, self, 0x1c) = 2;
        break;
    case 2:
        a = Ov010_FindActor(self->unk_0a);
        if (a != NULL && FLD(Ov010Flags8, a, 0xce).b0) {
            return;
        }
        FLD(u16, self, 0x1c) = 3;
        break;
    case 3:
        ((Ov010V *)self)->v0c();
        break;
    }
}

}
