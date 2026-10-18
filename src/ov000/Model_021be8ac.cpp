#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

typedef struct {
    u8 pad_00[0x68];
    s32 unk_68;
    u8 pad_6c[0xc];
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    u8 pad_84[8];
    Model *unk_8c;
    u8 pad_90[4];
    s32 unk_94;
} Obj021be8ac;

extern "C" {

void func_ov000_021be8ac(Obj021be8ac *self) {
    s32 x;
    s32 y;
    if (self->unk_68 != 10) {
        return;
    }
    x = (self->unk_78 >> 12) - 0x80;
    y = (self->unk_7c >> 12) - 0x60 + (self->unk_94 >> 12);
    self->unk_8c->unk_150 = self->unk_80;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    Model_PlayPart(self->unk_8c, 4);
}

}
