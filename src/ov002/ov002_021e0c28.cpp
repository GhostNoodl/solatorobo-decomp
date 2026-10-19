#include "ov002/ov002.h"

typedef struct ov002_Anim021e0c28 {
    void *vtbl;
    u32 unk4;
    u8 unk8[0x1c];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[4];
    u16 unk34;
    u8 unk36;
    s8 unk37;
    s32 unk38;
    u8 unk3C[8];
    u8 unk44[4];
    u8 unk48[4];
    s32 unk4C;
} ov002_Anim021e0c28;

typedef struct ov002_Caption021e0c28 {
    void *vtbl;
    ov002_Anim021e0c28 *anim;
    s32 text;
    s32 x;
    s32 y;
    s32 nextX;
    s32 nextY;
    s32 unk1C;
    s32 fromX;
    s32 fromY;
    s32 toX;
    s32 toY;
    s32 timer;
    u8 mode;
} ov002_Caption021e0c28;

extern "C" {

extern VFunc data_0208ba70[];

void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca14(ov002_Anim021e0c28 *a, int b);

static inline ov002_Anim021e0c28 *ov002_Anim_New(void) {
    ov002_Anim021e0c28 *anim = (ov002_Anim021e0c28 *)func_0203dd9c(0xb8);
    if (anim != NULL) {
        *(VFunc **)anim = data_0208ba70;
        func_0204c7d0(anim);
    }
    return anim;
}

static inline void ov002_Anim_Start(ov002_Anim021e0c28 *s, s32 a) {
    s->unk24 = a;
    s->unk4C = func_0204c4fc(s->unk28, s->unk38, s->unk24, s->unk44, s->unk48, s->unk37 != 0 ? TRUE : FALSE);
    FIELD(data_02097ce0, 0x4, s32) = s->unk28;
}


static inline void ov002_Caption_Lerp(ov002_Caption021e0c28 *self) {
    s32 t;
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;
    t = FX_Div(8 - self->timer, 8);
    dx = self->toX - self->fromX;
    x = self->fromX + (FX_MUL(dx << 12, t) >> 12);
    self->x = x;
    dy = self->toY - self->fromY;
    y = self->fromY + (FX_MUL(dy << 12, t) >> 12);
    self->y = y;
}

void func_ov002_021e0c28(ov002_Caption021e0c28 *self) {
    if (self->anim == NULL) {
        return;
    }
    ((VObject *)self->anim)->v0x8c();
    if (self->timer >= 0) {
    switch (self->mode) {
    case 1:
    case 2:
        ov002_Caption_Lerp(self);
        break;
    case 3:
        ov002_Caption_Lerp(self);
        if (self->timer == 0) {
            s32 text = self->text;
            if (text != 0) {
                if (self->anim == NULL) {
                    self->anim = ov002_Anim_New();
                }
                ((VObject *)self->anim)->v0x8();
                self->anim->unk28 = 3;
                self->anim->unk2C = 0;
                self->anim->unk34 = 1;
                ov002_Anim_Start(self->anim, text);
                func_0204ca14(self->anim, 8);
                self->anim->unk4 |= 4;
            }
            self->text = 0;
            self->fromX = self->x;
            self->fromY = self->y;
            self->toX = self->nextX;
            self->toY = self->nextY;
            self->mode = 2;
            self->timer = 8;
        }
        break;
    }
    self->timer--;
    } else {
        self->timer = 0;
    }
}

}
