#ifndef OV006_ANIM_H
#define OV006_ANIM_H

#include "ov006/ov006.h"
#include "Main/Gfx/FieldMsg.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/TextWin.h"

/* Owns a text window at 0x28. */
typedef struct ov006_TextHolder {
    u8 unk0[0x28];
    TextWin *unk28;
} ov006_TextHolder;

#ifdef __cplusplus
extern "C" {
#endif

void TextWin_InitLines(TextWin *win, u32 n);

#ifdef __cplusplus
}
#endif

static inline void ov006_TextWin_Start(TextWin *s, int a) {
    s->str = a;
    s->unk_4c = Text_Measure(s->font, s->spacing, s->str, &s->width, &s->height, (s8)s->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = s->font;
}

static inline void ov006_TextHolder_Play(ov006_TextHolder *self, int a, int b) {
    if (self->unk28 == NULL) {
        return;
    }
    self->unk28->unk_vf08();
    self->unk28->font = 7;
    self->unk28->unk_2c = b;
    self->unk28->unk_34 = 0;
    ov006_TextWin_Start(self->unk28, a);
    TextWin_InitLines(self->unk28, 0x10);
    self->unk28->flags |= 4;
}

#endif
