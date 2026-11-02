#include "ov000/VObj.h"
#include "ov000/MsgBox.h"
#include "Main/Sys/FieldState.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void func_ov000_021bc3ec(FieldFade *fade, s32 mode, s32 duration);
void func_ov000_021bc458(FieldFade *fade);
void MsgRes_Reset_0204bfcc(MsgRes *res);
void MsgRes_OpenLocalized(MsgRes *res, const char *arc, const char *name);
BOOL MsgRes_Bind(MsgRes *res);
s32 MsgRes_GetLines(MsgRes *res, u16 id, char **out, s32 d);
void TextWin_Init(TextWin *win);
void TwScene_Init(SlideWin *win);

static inline BOOL Fade021633ac_Done(void) {
    return data_ov000_021ccd70->state == 0 ? TRUE : FALSE;
}

static inline MsgRes *MsgRes_New(const char *arc, const char *name) {
    MsgRes *o = (MsgRes *)Heap_Alloc(sizeof(MsgRes));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208b318);
        o->Clear();
        VOBJ_SET_VTABLE(o, data_0208ba30);
        MsgRes_Reset_0204bfcc(o);
    }
    MsgRes_OpenLocalized(o, arc, name);
    return o;
}

BOOL MsgBox_Update(MsgBox *self) {
    BOOL ret = TRUE;
    SlideWin *o;
    switch (self->state) {
    case 0:
        func_ov000_021bc3ec(data_ov000_021ccd70, 3, 0xa000);
        self->res = MsgRes_New(self->arcName, self->name);
        self->state = 1;
    case 1:
        if (self->res->Load()) {
            self->state = 2;
        }
        break;
    case 2:
        MsgRes_Bind(self->res);
        self->numLines = MsgRes_GetLines(self->res, self->msgId, &self->text, 1);
        o = (SlideWin *)Heap_Alloc(sizeof(SlideWin));
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208ba70);
            TextWin_Init(o);
            VOBJ_SET_VTABLE(o, data_0208bbc8);
            TwScene_Init(o);
        }
        self->win = o;
        o->font = 8;
        {
            s32 a = self->numLines;
            SlideWin *p = self->win;
            p->text = self->text;
            p->unk_b70 = 0;
            p->numLines = a;
        }
        self->win->mode = 4;
        if (self->unk_10) {
            self->win->unk_bc_7 = 1;
        }
        self->win->rendering = 1;
        self->state = 3;
        break;
    case 3:
        if (!self->win->unk_vf8c()) {
            func_ov000_021bc458(data_ov000_021ccd70);
            self->state = 4;
        }
        break;
    case 4:
        if (Fade021633ac_Done()) {
            ret = FALSE;
        }
        break;
    }
    return ret;
}
}
