#include "ov006/Anim.h"

typedef struct ov006_Unk021e13c8 {
    u8 unk0[0x20];
    ov006_Anim *unk20;
} ov006_Unk021e13c8;

extern "C" {

void func_ov006_021e13c8(ov006_Unk021e13c8 *self, int a) {
    if (self->unk20 == NULL) {
        return;
    }
    VCALL(self->unk20, 08);
    self->unk20->unk28 = 3;
    self->unk20->unk2C = 4;
    self->unk20->unk34 = 0;
    ov006_Anim_Start(self->unk20, a);
    func_0204ca14(self->unk20, 8);
    self->unk20->unk4 |= 4;
}

}
