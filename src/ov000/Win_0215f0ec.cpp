#include "Main/Gfx/FieldMsg.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
#include "ov000/UiObj.h"

extern "C" {
extern UiLabelStyle UiLabel_StyleTable[];
extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;
void TexObj_SetOamFuncArg(void *model, s32 a, void *b);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = TextWin_vtbl;
        TextWin_Init(win);
    }
    return win;
}

static inline void SetText(TextWin *win, u32 text) {
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = win->font;
}

void UiLabel_SetText(UiLabel *self, u32 text) {
    UiLabelStyle *e;
    TextWin *win;
    if (self->model != NULL) {
        return;
    }
    e = &UiLabel_StyleTable[self->style];
    if (self->bits.altFrame ? TRUE : FALSE) {
        MODEL_NEW(self->model, ResName_WifiCells, ArcPath_MenuWifi);
    } else {
        MODEL_NEW(self->model, ResName_CommonCells, ArcPath_Menu);
    }
    {
        ResList *a = ResMgr_GetArcList(self->model->name);
        void *b = ResList_FindType2(a, self->model->unk_04c);
        TexObj_SetRes((Model *)self->model, b);
    }
    self->model->flags |= 2;
    TexObj_SelectImage((Model *)self->model, 0, e->part);
    TexObj_SetOamFuncArg(self->model, e->part, self);
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
