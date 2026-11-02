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
    Model *unk28;
    ov006_Lbl021e1bb4 *unk2C;
} ov006_Unk021e1bb4;

extern "C" {

void func_ov006_021dc578(ov006_Lbl021e1bb4 *self);

static inline void ov006_Caption_Draw(ov006_Caption *self) {
    if (self->visible) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->kind];
        TextWin *anim = self->label;
        s32 x;
        s32 y;
        s32 w = e->width;
        s32 bx = self->textX;
        s32 by = self->textY;
        w -= anim->width;
        s32 h = e->height;
        h -= anim->height;
        bx += 0x80;
        by += 0x60;
        x = self->x + self->ofsX;
        y = self->y + self->ofsY;
        bx += w >> 1;
        by += h >> 1;
        anim->unk_vf20(x + bx, y + by);
        self->label->Render();
        if (self->model != NULL) {
            ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
            Model_PlayPart(self->model, e->part);
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
        int h = data_ov006_021eb824[c->kind].height / 2;
        int w = data_ov006_021eb824[c->kind].width;
        x = self->unk8;
        y = self->unkC;
        c->x = x - (w >> 1);
        c->y = y - (h + 0x50);
    }
    ov006_Caption_Draw(self->unk24);
    ov006_Lbl_SetPos(self->unk2C, (x + 0x80) << 12, (y + 0x5d) << 12, self->unk2C->unkB8);
    func_ov006_021dc578(self->unk2C);
    ov006_Model_SetPos(self->unk28, 2, x << 12, y << 12);
    Model_PlayPart(self->unk28, 8);
}

}
