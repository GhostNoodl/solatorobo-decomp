#include "ov000/VObj.h"

extern "C" {

void func_ov000_02153f30(VObj *self, s32 a) {
    self->vfunc_14(a);
    *(s32 *)((u8 *)self + 0x70) = a - 0x110;
    *(u32 *)((u8 *)self + 4) |= 0x200000;
}

void func_ov000_02153f60(VObj *self, s32 a) {
    self->vfunc_18(a);
    *(s32 *)((u8 *)self + 0x70) = a - 0x80;
    *(u32 *)((u8 *)self + 4) &= ~0x200000;
}

typedef struct {
    s32 unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    s32 unk_0c[9];
} Obj02153f90;

void func_ov000_02153f90(Obj02153f90 *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0xffff;
    self->unk_0a = 0xffff;
    self->unk_0c[0] = 0;
    self->unk_0c[1] = 0;
    self->unk_0c[2] = 0;
    self->unk_0c[3] = 0;
    self->unk_0c[4] = 0;
    self->unk_0c[5] = 0;
    self->unk_0c[6] = 0;
    self->unk_0c[7] = 0;
    self->unk_0c[8] = 0;
}

}
