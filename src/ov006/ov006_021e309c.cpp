#include "ov006/Caption.h"

typedef struct ov006_Unk021e309c {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    ov006_Model *unk10;
    ov006_Caption *unk14;
    ov006_Caption *unk18[3];
} ov006_Unk021e309c;

extern "C" {

static inline void ov006_Caption_Draw(ov006_Caption *self) {
    if (self->unk4) {
        const ov006_CaptionEntry *e = &data_ov006_021eb824[self->unk20];
        ov006_Anim *anim = self->unk28;
        s32 x;
        s32 y;
        s32 w;
        s32 bx;
        s32 by;
        s32 h;
        w = e->unk2;
        x = self->unk8 + self->unk18;
        w -= *(int *)anim->unk44;
        y = self->unkC + self->unk1C;
        h = e->unk4;
        h -= *(int *)anim->unk48;
        bx = self->unk10;
        bx += 0x80;
        bx += w >> 1;
        by = self->unk14;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->unk28, 90);
        if (self->unk24 != NULL) {
            ov006_Model_SetPos(self->unk24, 2, x << 12, y << 12);
            ov006_Model_PlayPart(self->unk24, e->unk0);
        }
    }
}

// The same draw with a different statement and declaration order; the loop's copy is scheduled this way.
static inline void ov006_Caption_Draw2(ov006_Caption *self) {
    if (self->unk4) {
        s32 x;
        s32 y;
        const ov006_CaptionEntry *e;
        ov006_Anim *anim;
        s32 w;
        s32 bx;
        s32 by;
        s32 h;
        e = &data_ov006_021eb824[self->unk20];
        anim = self->unk28;
        x = self->unk8 + self->unk18;
        y = self->unkC + self->unk1C;
        w = e->unk2;
        w -= *(int *)anim->unk44;
        h = e->unk4;
        h -= *(int *)anim->unk48;
        bx = self->unk10;
        bx += 0x80;
        bx += w >> 1;
        by = self->unk14;
        by += 0x60;
        by += h >> 1;
        VCALL(anim, 20, x + bx, y + by);
        VCALL(self->unk28, 90);
        if (self->unk24 != NULL) {
            ov006_Model_SetPos(self->unk24, 2, x << 12, y << 12);
            ov006_Model_PlayPart(self->unk24, e->unk0);
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
    i = c->unk20;
    x = self->unk8;
    y = self->unkC;
    c->unk8 = x - (data_ov006_021eb824[i].unk2 >> 1);
    c->unkC = y - ((data_ov006_021eb824[i].unk4 / 2) + 0x20);
    ov006_Caption_Draw(self->unk14);
    for (i = 0; i < 3; i++) {
        c = self->unk18[i];
        if (c == NULL) {
            continue;
        }
        e = &data_ov006_021eb824[c->unk20];
        {
            int h = e->unk4 / 2;
            int w = e->unk2;
            c->unk8 = x - (w >> 1);
            c->unkC = y - (12 - i * 14 + h);
        }
        ov006_Caption_Draw2(self->unk18[i]);
    }
    ov006_Model_SetPos(self->unk10, 2, x << 12, y << 12);
    ov006_Model_PlayPart(self->unk10, 9);
}

}
