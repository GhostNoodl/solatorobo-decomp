#include "ov006/Anim.h"

typedef struct ov006_Unk021e13c8 {
    u8 unk0[0x20];
    TextWin *unk20;
} ov006_Unk021e13c8;

extern "C" {

void func_ov006_021e13c8(ov006_Unk021e13c8 *self, int a) {
    if (self->unk20 == NULL) {
        return;
    }
    self->unk20->unk_vf08();
    self->unk20->font = 3;
    self->unk20->unk_2c = 4;
    self->unk20->unk_34 = 0;
    ov006_TextWin_Start(self->unk20, a);
    TextWin_InitLines(self->unk20, 8);
    self->unk20->flags |= 4;
}

}
