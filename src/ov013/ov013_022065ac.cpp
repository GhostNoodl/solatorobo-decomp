#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov013_0220bb20;
extern char data_ov013_0220b360[];
extern void func_ov000_02194074(void *self);
extern void func_ov003_021db244(Ov013Actor *self);
extern void func_ov003_021dae44(Ov013Actor *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern void *func_020657b0(void *a, s32 b);
extern Ov013Actor *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov013Actor *self, const void *p);

Ov013Actor *func_ov013_022065ac(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220bb20;
    FLD(u8, self, 0xf4) = 0;
    FLD(u16, self, 0xf6) = 0;
    return self;
}

void func_ov013_022065d8(Ov013Actor *self, u16 a) {
    FLD(u16, self, 0xf6) = a;
}

void func_ov013_022065e0(Ov013Actor *self, u8 a) {
    FLD(u8, self, 0xf4) = a;
}

void func_ov013_022065e8(Ov013Actor *self) {
    func_ov003_021db244(self);
    if (FLD(u16, self, 0xf6) != 0) {
        self->rot[1] += FLD(u16, self, 0xf6);
    } else {
        self->rot[1] = FX_Atan2(self->unk_9c, self->unk_a4);
    }
    if (FLD(u8, self, 0xf4) != 0 && FLD(s32, self, 0xbc) != 0) {
        void *p = func_020657b0(data_0214a420, FLD(s32, self, 0xbc));
        if (p != NULL) {
            FLD(s32, p, 0xc8) = -1;
        }
    }
}

Ov013Actor *func_ov013_0220664c(Ov013Actor *self) {
    func_ov003_021dae44(self);
    return self;
}

Ov013Actor *func_ov013_02206660(Ov013Actor *self) {
    func_ov003_021dae44(self);
    func_0203de1c(self);
    return self;
}

void func_ov013_0220667c(Ov013Actor *self) {
    Ov013Sub48 *m;
    Ov013Sub44 *n;
    Ov013Actor *p;
    func_ov003_021d112c(self);
    self->pos.x = -0x3000;
    self->pos.y = 0x5333;
    self->pos.z = -0xe000;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_48, 0x5c), 0, -0x1800, 0x5800);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    self->unk_48->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    Ov013_VecSet(&FLD(Ov013Vec, self->unk_44, 0xc), 0, -0x1800, 0x5800);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    self->unk_93_4 = 1;
    self->unk_b6 = 0x5a;
    FLD(u16, self, 0xfe) = 0x1000;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov013_0220b360);
        FLD(u16, self, 0xfe) = 0x1800;
    }
}

}
