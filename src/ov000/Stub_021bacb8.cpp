#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    u16 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
} Obj021bacb8;

extern "C" {

void func_ov000_021bacb8(Obj021bacb8 *self, u16 a) {
    self->unk_00 = 0;
    self->unk_04 = 1;
    self->unk_08 = a;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_2c = 0;
    self->unk_28 = 0;
    self->unk_24 = 0;
    self->unk_20 = 0;
    self->unk_1c = 0;
}

}
