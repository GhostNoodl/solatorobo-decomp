#include "ov000/VObj.h"
#include "ov000/MsgBox.h"
#include "Main/Sys/FieldState.h"

extern "C" {
extern u8 TextWin_vtbl[];
extern u8 MainVt_0208bbc8_vtbl[];
void FieldFade_Start(FieldFade *fade, s32 mode, s32 duration);
void FieldFade_End(FieldFade *fade);
void MsgRes_Reset_0204bfcc(MsgRes *res);
void MsgRes_OpenLocalized(MsgRes *res, const char *arc, const char *name);
BOOL MsgRes_Bind(MsgRes *res);
s32 MsgRes_GetLines(MsgRes *res, u16 id, char **out, s32 d);
void TextWin_Init(TextWin *win);
void TwScene_Init(SlideWin *win);

static inline BOOL Fade021633ac_Done(void) {
    return gFieldFade->state == 0 ? TRUE : FALSE;
}

static inline MsgRes *MsgRes_New(const char *arc, const char *name) {
    MsgRes *o = (MsgRes *)Heap_Alloc(sizeof(MsgRes));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, ResHandle_vtbl);
        o->Clear();
        VOBJ_SET_VTABLE(o, MainVt_0208ba30_vtbl);
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
        FieldFade_Start(gFieldFade, 3, 0xa000);
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
            VOBJ_SET_VTABLE(o, TextWin_vtbl);
            TextWin_Init(o);
            VOBJ_SET_VTABLE(o, MainVt_0208bbc8_vtbl);
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
            FieldFade_End(gFieldFade);
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
