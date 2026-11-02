#include "ov006/Gauge.h"
#include "nitro/fx.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

static inline void ov006_TextWin_SetScreenPos(TextWin *a, s32 x, s32 y) {
    a->unk_vf20(x + 0x80, y);
}

void func_ov006_021e1180(ov006_Gauge *self) {
    s32 x;
    s32 y;
    if (!self->unk4) {
        return;
    }
    x = self->x;
    y = self->y + 0x10;
    ov006_TextWin_SetScreenPos(self->text, x + 0x28 - ((s32)self->text->width >> 1), y + 0x54);
    self->text->Render();
    ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
    Model_PlayPart(self->model, (u16)(self->unk10 + 2));
    ov006_Model_SetPos(self->model, 2, (x + (s16)(FX_Whole(FX_Mul(self->unk8, 0x4b000)) - 0x4b) + 0x50) << 12, y << 12);
    Model_PlayPart(self->model, 7);
    ov006_Model_SetPos(self->model, 2, (x + 0x50) << 12, y << 12);
    Model_PlayPart(self->model, 6);
}

}
