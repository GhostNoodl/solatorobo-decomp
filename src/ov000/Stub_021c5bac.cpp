#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x18];
    s32 unk_18;
    u8 unk_1c[0x14];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    u16 unk_3c;
    s32 unk_40;
    u8 unk_44;
} Obj021c5bac;

extern "C" {

void func_ov000_021c5bac(Obj021c5bac *self) {
    self->unk_18 = 0xf;
    self->unk_30 = 0;
    self->unk_34 = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
}

}
