#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"

extern "C" {
void func_02041c18(Model *m, u32 a);

void func_ov000_021c5d9c(Lo021cca40 *self) {
    s32 x;
    s32 y;
    if (self->built == 0) {
        return;
    }
    x = self->x >> 12;
    y = self->y >> 12;
    self->text->unk_vf20(x + 10, y + 2);
    self->text->posZ = self->z;
    self->text->Render();
    Model_SetPos(self->unk_34, (x + 2) << 12, (y - 0x5a) << 12);
    self->unk_34->unk_150 = self->z;
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 7);
    }

    Model_SetPos(self->unk_34, (x + 0x14) << 12, (y - 0x5c) << 12);
    self->unk_34->unk_150 = self->z;
    func_02041c18(self->unk_34, self->unk_3c);
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 6);
    }
    Model_SetPos(self->unk_34, (x + 0x42) << 12, (y - 0x5c) << 12);
    self->unk_34->unk_150 = self->z;
    func_02041c18(self->unk_34, self->unk_40);
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 6);
    }
}
}
