#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Anim021e1180 {
    void *vtbl;
    u8 unk4[0x40];
    s32 unk44;
} ov006_Anim021e1180;

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
    ov006_Model *model;
    ov006_Anim021e1180 *anim;
} ov006_Gauge021e1180;

extern "C" {

static inline void ov006_Anim_SetScreenPos(ov006_Anim021e1180 *a, s32 x, s32 y) {
    VCALL(a, 20, x + 0x80, y);
}

void func_ov006_021e1180(ov006_Gauge021e1180 *self) {
    s32 x;
    s32 y;
    if (!self->unk4) {
        return;
    }
    x = self->x;
    y = self->y + 0x10;
    ov006_Anim_SetScreenPos(self->anim, x + 0x28 - (self->anim->unk44 >> 1), y + 0x54);
    VCALL(self->anim, 90);
    ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
    ov006_Model_PlayPart(self->model, (u16)(self->unk10 + 2));
    ov006_Model_SetPos(self->model, 2, (x + (s16)(FX_Whole(FX_Mul(self->unk8, 0x4b000)) - 0x4b) + 0x50) << 12, y << 12);
    ov006_Model_PlayPart(self->model, 7);
    ov006_Model_SetPos(self->model, 2, (x + 0x50) << 12, y << 12);
    ov006_Model_PlayPart(self->model, 6);
}

}
