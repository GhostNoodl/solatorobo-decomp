#include "Main/Gfx/FieldMsg.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits0215d758;

extern "C" {
extern u16 data_ov000_021cabe0[];
extern void *ResName_BattleCells;
extern void *ArcPath_MenuBattle;
extern void *gMsgRes;
void *ResMgr_GetArcList(void *a);
void *ResList_FindType2(void *a, void *b);
void TexObj_SetAllOamFuncs(void *model, void *fn);
u32 MsgRes_GetString(void *a, s32 b);
void *func_ov000_02154128(u8 *self, void *req, void *buf, u16 *count);

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

void Lo021cae48_Setup(Lo021cae48 *self) {
    u16 *ent = &data_ov000_021cabe0[self->style * 2];
    u8 *m;
    void *res;
    TextWin *win;
    m = (u8 *)Heap_Alloc(0x160);
    if (m) {
        void *arc_;
        void *name_;
        name_ = ResName_BattleCells;
        arc_ = ArcPath_MenuBattle;
        PlttRes_Init_02041218((struct PlttRes *)(m + 0x88));
        TexObj_Init((Model *)m, (const char *)name_, 0);
        STD_CopyString((char *)m + 0x2c, (const char *)arc_);
    }
    self->digits = (Model *)(m);
    TexObj_SetRes(self->digits, ResList_FindType2(ResMgr_GetArcList(m + 0x2c), (u8 *)self->digits + 0x4c));
    self->digits->flags |= 2;
    TexObj_SelectImage(self->digits, 0, 6);
    if (self->style != 4) {
        TexObj_SelectImage(self->digits, 0, ent[0]);
    }
    TexObj_SetAllOamFuncs((u8 *)self->digits, (void *)func_ov000_02154128);
    res = gMsgRes;
    win = TextWin_New();
    self->label = win;
    win->font = 4;
    SetText(self->label, MsgRes_GetString(res, ent[1]));
    self->label->unk_2c = 0;
    self->label->color0 = 0x77df;
    self->label->color1 = 0x67e;
    self->label->noVram = 1;
    self->label->flag24 = 1;
    *(u32 *)((u8 *)self->label + 4) |= 0x400000;
    self->label->unk_78 = 0x9000;
    self->label->unk_4_30 = 1;
    self->label->rendering = 1;
    self->color = 0x4cc2;
    self->width = 0x60;
    self->height = 0xe;
    self->busy = 1;
}
}
