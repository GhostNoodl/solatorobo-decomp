#include "ov006/Model.h"
#include "nitro/fx.h"
#include "Main/Gfx/TextWin.h"

typedef struct ov006_Gauge021e1180 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[2];
    fx32 unk8;
    fx32 unkC;
    int unk10;
    s32 x;
    s32 y;
    Model *model;
    TextWin *anim;
} ov006_Gauge021e1180;

extern "C" {

static inline void ov006_TextWin_SetScreenPos(TextWin *a, s32 x, s32 y) {
    a->unk_vf20(x + 0x80, y);
}

void func_ov006_021e1180(ov006_Gauge021e1180 *self) {
    s32 x;
    s32 y;
    if (!self->unk4) {
        return;
    }
    x = self->x;
    y = self->y + 0x10;
    ov006_TextWin_SetScreenPos(self->anim, x + 0x28 - ((s32)self->anim->width >> 1), y + 0x54);
    self->anim->Render();
    ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
    Model_PlayPart(self->model, (u16)(self->unk10 + 2));
    ov006_Model_SetPos(self->model, 2, (x + (s16)(FX_Whole(FX_Mul(self->unk8, 0x4b000)) - 0x4b) + 0x50) << 12, y << 12);
    Model_PlayPart(self->model, 7);
    ov006_Model_SetPos(self->model, 2, (x + 0x50) << 12, y << 12);
    Model_PlayPart(self->model, 6);
}

}
