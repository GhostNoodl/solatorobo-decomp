#include "Main/Gfx/FieldMsg.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
#include "ov000/UiObj.h"

extern "C" {
extern UiLabelStyle data_02fe0188[];
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
void func_02041c20(void *model, s32 a, void *b);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        TextWin_Init(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
}

void UiLabel_SetText(UiLabel *self, u32 text) {
    UiLabelStyle *e;
    TextWin *win;
    if (self->model != NULL) {
        return;
    }
    e = &data_02fe0188[self->style];
    if (self->bits.altFrame ? TRUE : FALSE) {
        MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = ResMgr_GetArcList(self->model->name);
        void *b = ResList_FindType2(a, self->model->unk_04c);
        TexObj_SetRes((Model *)self->model, b);
    }
    self->model->flags |= 2;
    TexObj_SelectImage((Model *)self->model, 0, e->part);
    func_02041c20(self->model, e->part, self);
    win = TextWin_New();
    self->text = win;
    win->font = 4;
    SetText(self->text, text);
    self->text->color0 = 0x77df;
    self->text->color1 = 0x67e;
    self->text->noVram = 1;
    self->text->flag24 = 1;
    self->text->flags |= 0x400000;
    self->text->unk_78 = 0x9000;
    self->text->unk_4_30 = 1;
    self->text->rendering = 1;
    self->height = e->height >> 12;
}

}
