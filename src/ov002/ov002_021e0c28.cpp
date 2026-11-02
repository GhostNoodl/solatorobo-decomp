#include "ov002/ov002.h"

extern "C" {

extern VFunc data_0208ba70[];

void func_0204c7d0(void *p);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_InitLines(Ov002Text2 *a, int b);

static inline Ov002Text2 *ov002_Anim_New(void) {
    Ov002Text2 *anim = (Ov002Text2 *)Heap_Alloc(0xb8);
    if (anim != NULL) {
        *(VFunc **)anim = data_0208ba70;
        func_0204c7d0(anim);
    }
    return anim;
}

static inline void ov002_Anim_Start(Ov002Text2 *s, s32 str) {
    s->str = str;
    s->unk_4c = Text_Measure(s->font, s->spacing, s->str, &s->width, &s->height, s->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = s->font;
}


static inline void ov002_Caption_Lerp(Ov002Caption *self) {
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

void func_ov002_021e0c28(Ov002Caption *self) {
    if (self->anim == NULL) {
        return;
    }
    self->anim->vfunc_8c();
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
                self->anim->vfunc_08();
                self->anim->font = 3;
                self->anim->unk_2c = 0;
                self->anim->unk_34 = 1;
                ov002_Anim_Start(self->anim, text);
                TextWin_InitLines(self->anim, 8);
                self->anim->flags |= 4;
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
