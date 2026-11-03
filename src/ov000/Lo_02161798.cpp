#include "ov000/ObjLayouts.h"
#include "ov000/ModelPart.h"


extern "C" {
void func_02041c18(Model *m, s32 a);

void func_ov000_02161798(Lo021cacd8 *self, s32 a1, s32 *pos, s32 a3) {
    s32 x;
    s32 y;
    s32 w;
    s32 n;
    if (self->unk_84 == NULL) {
        return;
    }
    x = (pos[0] >> 12) - 0x80;
    y = (pos[1] >> 12) - 0x65;
    Model_SetPos(self->unk_84, (x - 8) << 12, y << 12);
    func_02041c18(self->unk_84, self->count);
    Model_PlayPart(self->unk_84, 6);
    Model_SetPos(self->unk_84, x << 12, y << 12);
    Model_PlayPart(self->unk_84, 8);
    w = 10;
    for (n = self->max / 10; n != 0; n /= 10) {
        w += 8;
    }
    Model_SetPos(self->unk_84, (x + w) << 12, y << 12);
    func_02041c18(self->unk_84, self->max);
    Model_PlayPart(self->unk_84, 6);
}

}
