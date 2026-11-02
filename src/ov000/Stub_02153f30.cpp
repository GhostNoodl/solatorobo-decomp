#include "ov000/VObj.h"
#include "ov000/MsgEntry.h"

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

void func_ov000_02153f90(MsgEntry *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->id = 0;
    self->unk_08 = 0xffff;
    self->unk_0a = 0xffff;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = NULL;
    self->unk_20 = NULL;
    self->unk_24 = 0;
    self->prev = NULL;
    self->next = NULL;
}

}
