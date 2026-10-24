#include "ov006/Caption.h"

extern "C" {

// Same caption draw as the inline in ov006_021e1bb4.cpp, with the statements
// in the order that reproduces the target's scheduling.
void func_ov006_021e0b80(ov006_Caption *self) {
    if (self->unk4) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->unk20];
        ov006_Anim *anim = self->unk28;
        s32 x;
        s32 y;
        s32 bx = self->unk10;
        s32 by = self->unk14;
        bx += 0x80;
        x = self->unk8 + self->unk18;
        y = self->unkC + self->unk1C;
        s32 w = e->unk2;
        w -= *(int *)anim->unk44;
        s32 h = e->unk4;
        bx += w >> 1;
        h -= *(int *)anim->unk48;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->unk28, 90);
        if (self->unk24 != NULL) {
            ov006_Model_SetPos(self->unk24, 2, x << 12, y << 12);
            ov006_Model_PlayPart(self->unk24, e->unk0);
        }
    }
}

}
