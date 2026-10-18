#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

typedef struct {
    u8 pad_00[0x28];
    s32 state;
    u8 pad_2c[4];
    Model *unk_30;
} Obj021b8db4;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    u16 unk_10;
    u16 unk_12;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
} Obj021b8e80;

extern "C" {

void func_02042f40(s32 a);

void func_ov000_021b8db4(Obj021b8db4 *self) {
    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
        break;
    case 8:
    case 9:
    case 12:
    case 13:
    case 14: {
        Model *m;
        func_02042f40(1);
        m = self->unk_30;
        if (m != NULL) {
            Model_PlayPart(m, 0);
        }
        break;
    }
    }
}

void func_ov000_021b8e80(Obj021b8e80 *self, s32 a, u16 b) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 1;
    self->unk_0c = a;
    self->unk_10 = b;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
}

}
