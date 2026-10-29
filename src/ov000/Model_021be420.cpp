#include "ov000/ModelPart.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad_00[0x68];
    s32 unk_68;
    u8 pad_6c[0xc];
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    u8 pad_84[4];
    s32 unk_88;
    Model *unk_8c;
    u8 pad_90[4];
    s32 unk_94;
} Obj021be420;

extern "C" {

extern u8 *data_02097d48;
int func_02043d48(void *p);

void func_ov000_021be420(Obj021be420 *self) {
    s32 x;
    s32 y;
    s32 a;
    if (self->unk_68 != 10) {
        return;
    }
    x = (self->unk_78 >> 12) - 0x80;
    y = (self->unk_7c >> 12) - 0x60 + (self->unk_94 >> 12);
    self->unk_8c->unk_150 = self->unk_80;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    a = FX_MUL(self->unk_88, 0x1f000) >> 12;
    MODEL_FLAGS(self->unk_8c)->unk_19 = 1;
    MODEL_FLAGS(self->unk_8c)->polygon_id = func_02043d48(data_02097d48 + 0x8b0);
    MODEL_FLAGS(self->unk_8c)->alpha = (u8)a;
    Model_PlayPart(self->unk_8c, 3);
}

}
