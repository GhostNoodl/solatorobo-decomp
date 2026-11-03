#include "Main/Gfx/FieldMsg.h"
#include "ov000/TextList.h"

extern "C" {
extern char data_ov000_021cc9e9[];
BOOL Obj02152e5c_LoadModel(void *self);
void func_ov000_0215ec44(UiPanel *self);
void Obj0215e8b0_LoadModel(UiPanel *self);

static inline TextWin *TextWin_New(void) {
    TextWin *win = (TextWin *)Heap_Alloc(0xb8);
    if (win != NULL) {
        *(const u32 **)win = data_0208ba70;
        TextWin_Init(win);
    }
    return win;
}

static inline void TextList_SetText(TextList *self, u32 text) {
    TextWin *win;
    {
        void *saved = data_02097dd0->cur;
        TextWin *p;
        data_02097dd0->cur = data_02097dd0->heapHi;
        p = self->panelText;
        if (p != NULL) {
            if (p != NULL) {
                p->unk_vf04();
            }
            self->panelText = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->panelText = TextWin_New();
    self->panelText->font = 8;
    win = self->panelText;
    win->str = text;
    win->unk_4c = Text_Measure(win->font, win->spacing, win->str, &win->width, &win->height, (s8)win->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = win->font;
    self->panelText->noVram = 1;
    self->panelText->unk_4_8 = 0x1e;
    self->panelText->flag24 = 1;
    *(u32 *)((u8 *)self->panelText + 4) |= 0x400000; // bit 22 of the flags word
    self->panelText->rendering = 1;
}

static inline ListRow *TextList_GetRow(TextList *self, s32 n) {
    ListRow *p;
    s32 i;
    for (p = self->rows, i = 0; p != NULL; p = p->next, i++) {
        if (i == n) {
            break;
        }
    }
    return p;
}

void Ov000Vt_021ccadc_Setup(TextList *self) {
    ListRow *p;
    UiPanel *o;

    self->slideMode = 1;
    {
        s32 z = self->posZ;
        self->slideX = -0x100;
        self->slideY = 0;
        self->slideZ = z;
    }
    p = TextList_GetRow(self, 0);
    self->cur = p;
    if (p != NULL) {
        self->rowWidth = p->width;
    }
    if (Obj02152e5c_LoadModel(self)) {
        TexObj_SelectImage(self->model, 0, 4);
    }
    self->cur = self->rows;
    o = (UiPanel *)Heap_Alloc(0x2c);
    if (o != NULL) {
        func_ov000_0215ec44(o);
    }
    self->panel = o;
    o->width = self->panelWidth << 12;
    Obj0215e8b0_LoadModel(self->panel);
    if (self->panelText != NULL) {
        return;
    }
    {
        u32 t = (u32)data_ov000_021cc9e9;
        TextList_SetText(self, t);
    }
}
}
