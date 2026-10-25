#include "ov006/Model.h"

typedef struct ov006_Marker2490 {
    void *vtbl;
    u16 state;
    u16 unk6;
    s16 timer;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} ov006_Marker2490;

typedef struct ov006_Unk021e2490 {
    void *vtbl;
    u8 unk4;
    s32 unk8;
    s32 unkC;
    ov006_Marker2490 markers[4];
    ov006_Model *unkA0;
} ov006_Unk021e2490;

typedef void *(*ov006_SeqFn16)(int a, u16 b);

static inline ov006_ModelPart *ov006_Model_GetPart16(ov006_Model *self, u16 idx) {
    if (idx >= self->numParts) {
        return NULL;
    }
    return &self->parts[idx];
}

static inline void ov006_Model_PlayPart16(ov006_Model *model, u16 idx) {
    ov006_ModelRes *res = model->unk28;
    ov006_ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov006_Model_GetPart16(model, idx);
    if (part != NULL && part->unk4 != NULL) {
        anim = part->unk4->unk30;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->unk4, **((ov006_Unk02023390 *)((ov006_SeqFn16)NNS_G2dGetAnimSequenceByIdx)(model->unk28->unkC, idx))->unkC);
    }
    func_02042628(model, anim, part, 0);
}

extern "C" {

void func_ov006_021e2490(ov006_Unk021e2490 *self) {
    int i;
    u32 x;
    u32 y;
    if (!self->unk4) {
        return;
    }
    x = self->unk8;
    y = self->unkC;
    for (i = 0; i < 4; i++) {
        ov006_Model_SetPos(self->unkA0, 2, x << 12, (y + i * 32) << 12);
        ov006_Model_PlayPart16(self->unkA0, i + 0x10);
    }
    for (i = 0; i < 4; i++) {
        ov006_Marker2490 *m = &self->markers[i];
        if (m->unkA) {
            m->unk10 = x + 0x1c;
            m->unk14 = y;
            ov006_Model_SetPos(self->unkA0, 2, ((x + 0x1c) + (m->unk18 >> 12)) << 12, (y + (m->unk1C >> 12)) << 12);
            ov006_Model_PlayPart16(self->unkA0, i + 0x14);
        }
    }
}

}
