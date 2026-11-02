#include "ov006/Caption.h"

typedef struct ov006_Unk021e309c {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    Model *unk10;
    ov006_Caption *unk14;
    ov006_Caption *unk18[3];
} ov006_Unk021e309c;

extern "C" {

static inline void ov006_Caption_Draw(ov006_Caption *self) {
    if (self->visible) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->kind];
        ov006_Anim *anim = self->label;
        s32 x;
        s32 y;
        s32 w;
        s32 bx;
        s32 by;
        s32 h;
        w = e->width;
        x = self->x + self->ofsX;
        w -= *(int *)anim->unk44;
        y = self->y + self->ofsY;
        h = e->height;
        h -= *(int *)anim->unk48;
        bx = self->textX;
        bx += 0x80;
        bx += w >> 1;
        by = self->textY;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->label, 90);
        if (self->model != NULL) {
            ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
            Model_PlayPart(self->model, e->part);
        }
    }
}

// The same draw with a different statement and declaration order; the loop's copy is scheduled this way.
static inline void ov006_Caption_Draw2(ov006_Caption *self) {
    if (self->visible) {
        s32 x;
        s32 y;
        const ov006_CaptionEntry *e;
        ov006_Anim *anim;
        s32 w;
        s32 bx;
        s32 by;
        s32 h;
        e = &data_ov006_021eb824[self->kind];
        anim = self->label;
        x = self->x + self->ofsX;
        y = self->y + self->ofsY;
        w = e->width;
        w -= *(int *)anim->unk44;
        h = e->height;
        h -= *(int *)anim->unk48;
        bx = self->textX;
        bx += 0x80;
        bx += w >> 1;
        by = self->textY;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->label, 90);
        if (self->model != NULL) {
            ov006_Model_SetPos(self->model, 2, x << 12, y << 12);
            Model_PlayPart(self->model, e->part);
        }
    }
}

void func_ov006_021e309c(ov006_Unk021e309c *self) {
    ov006_Caption *c;
    const ov006_CaptionEntry *e;
    s32 x;
    s32 y;
    int i;
    if (!self->unk4) {
        return;
    }
    c = self->unk14;
    i = c->kind;
    x = self->unk8;
    y = self->unkC;
    c->x = x - (data_ov006_021eb824[i].width >> 1);
    c->y = y - ((data_ov006_021eb824[i].height / 2) + 0x20);
    ov006_Caption_Draw(self->unk14);
    for (i = 0; i < 3; i++) {
        c = self->unk18[i];
        if (c == NULL) {
            continue;
        }
        e = &data_ov006_021eb824[c->kind];
        {
            int h = e->height / 2;
            int w = e->width;
            c->x = x - (w >> 1);
            c->y = y - (12 - i * 14 + h);
        }
        ov006_Caption_Draw2(self->unk18[i]);
    }
    ov006_Model_SetPos(self->unk10, 2, x << 12, y << 12);
    Model_PlayPart(self->unk10, 9);
}

}
