#include "ov006/Caption.h"

typedef struct ov006_Lbl021e1bb4 {
    u8 unk0[0xb0];
    int unkB0;
    int unkB4;
    int unkB8;
} ov006_Lbl021e1bb4;

typedef struct ov006_Unk021e1bb4 {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    u8 unk10[0x14];
    ov006_Caption *unk24;
    ov006_Model *unk28;
    ov006_Lbl021e1bb4 *unk2C;
} ov006_Unk021e1bb4;

extern "C" {

void func_ov006_021dc578(ov006_Lbl021e1bb4 *self);

static inline void ov006_Caption_Draw(ov006_Caption *self) {
    if (self->unk4) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->unk20];
        ov006_Anim *anim = self->unk28;
        s32 x;
        s32 y;
        s32 w = e->unk2;
        s32 bx = self->unk10;
        s32 by = self->unk14;
        w -= *(int *)anim->unk44;
        s32 h = e->unk4;
        h -= *(int *)anim->unk48;
        bx += 0x80;
        by += 0x60;
        x = self->unk8 + self->unk18;
        y = self->unkC + self->unk1C;
        bx += w >> 1;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->unk28, 90);
        if (self->unk24 != NULL) {
            ov006_Model_SetPos(self->unk24, 2, x << 12, y << 12);
            ov006_Model_PlayPart(self->unk24, e->unk0);
        }
    }
}


static inline void ov006_Lbl_SetPos(ov006_Lbl021e1bb4 *o, int x, int y, int z) {
    o->unkB0 = x;
    o->unkB4 = y;
    o->unkB8 = z;
}

void func_ov006_021e1bb4(ov006_Unk021e1bb4 *self) {
    s32 x;
    s32 y;
    if (!self->unk4) {
        return;
    }
    {
        ov006_Caption *c = self->unk24;
        int h = data_ov006_021eb824[c->unk20].unk4 / 2;
        int w = data_ov006_021eb824[c->unk20].unk2;
        x = self->unk8;
        y = self->unkC;
        c->unk8 = x - (w >> 1);
        c->unkC = y - (h + 0x50);
    }
    ov006_Caption_Draw(self->unk24);
    ov006_Lbl_SetPos(self->unk2C, (x + 0x80) << 12, (y + 0x5d) << 12, self->unk2C->unkB8);
    func_ov006_021dc578(self->unk2C);
    ov006_Model_SetPos(self->unk28, 2, x << 12, y << 12);
    ov006_Model_PlayPart(self->unk28, 8);
}

}
