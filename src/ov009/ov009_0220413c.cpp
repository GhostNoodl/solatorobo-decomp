#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(Ov009Game54 *g, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_0220397c(Ov009Names *self, void *res);

void func_ov009_0220413c(Ov009Actor *self) {
    u8 *p;
    if (self->kind != 0x5810 && self->kind != 0x5811) {
        FLD(void *, self, 0xd8) = (void *)func_ov009_0220397c;
    }
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x503e:
        FLD(u16, self, 0xea) |= 0x400;
    case 0x504d:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5027:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        FLD(u16, self, 0xea) |= 0x400;
        break;
    }
    FLD(s32, self, 0xf8) = 0;
}

extern const Ov009Vec data_ov009_02215e24[];
struct Ov009Trail {
    u8 unk_00[0x10c];
    Ov009Vec trail[5];
};

void func_ov009_02204230(Ov009Actor *self) {
    s16 n;
    u8 i;
    s32 x, y, z;
    func_ov003_021d112c(self);
    FLD(u8, self, 0xf3) = 0;
    if (!(self->kind != 0x5810 && self->kind != 0x5811)) {
        FLD(u8, self, 0xf2) = 1;
        FLD(u16, self, 0xf6) = 0x50;
        FLD(s32, self, 0xfc) = 0x2000;
    } else {
        FLD(u8, self, 0xf2) = 0;
        FLD(s32, self, 0xfc) = 0x3000;
        self->unk_c8 = 0x16800;
        self->unk_cc = 0xc000;
    }
    n = self->unk_1a;
    if (n != 0) {
        if (n >= 10 && n < 15) {
            n = n - 10;
            FLD(u8, self, 0xf3) = 1;
            if (FLD(u8, self, 0xf2) == 1 && self->unk_18 != 0) {
                self->pos = data_ov009_02215e24[n];
            }
        }
        self->unk_18 = n;
    }
    FLD(u8, self, 0xf1) = self->unk_18;
    FLD(Ov009Vec, self, 0x100) = FLD(Ov009Vec, self->unk_38, 0xa8);
    x = FLD(Ov009Vec, data_ov009_02215d0c, 0x84).x;
    y = FLD(Ov009Vec, data_ov009_02215d0c, 0x84).y;
    z = FLD(Ov009Vec, data_ov009_02215d0c, 0x84).z;
    for (i = 0; i < 5; i++) {
        ((Ov009Trail *)self)->trail[i].x = x;
        ((Ov009Trail *)self)->trail[i].y = y;
        ((Ov009Trail *)self)->trail[i].z = z;
    }
    if (FLD(u8, self, 0xf2) != 1) {
        self->unk_48->unk_60 = 0x1000;
    } else {
        self->unk_48->unk_60 = -0x400;
        self->unk_48->unk_48 = 0x1000;
        Ov009Vec *dst = &FLD(Ov009Vec, self->unk_38, 0xa8);
        dst->x = x;
        dst->y = FLD(Ov009Vec, data_ov009_02215d0c, 0x84).y;
        dst->z = FLD(Ov009Vec, data_ov009_02215d0c, 0x84).z;
        self->pos.y += 0x2000;
        self->unk_ea_6 = 1;
        func_ov000_02198360(self->unk_40, 0x20, 0);
    }
    FLD(u8, self, 0xf0) = 0;
    self->unk_1c = 0x38e;
}

}
