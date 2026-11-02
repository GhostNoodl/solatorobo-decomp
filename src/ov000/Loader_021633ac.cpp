#include "ov000/VObj.h"
#include "ov000/MsgBox.h"
#include "Main/Sys/FieldState.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
void func_ov000_021bc3ec(FieldFade *fade, s32 mode, s32 duration);
void func_ov000_021bc458(FieldFade *fade);
void func_0204bfcc(MsgRes *res);
void func_0204bfe4(MsgRes *res, const char *arc, const char *name);
BOOL func_0204c030(MsgRes *res);
s32 func_0204c08c(MsgRes *res, u16 id, char **out, s32 d);
void func_0204c7d0(TextWin *win);
void func_02050f70(SlideWin *win);

static inline BOOL Fade021633ac_Done(void) {
    return data_ov000_021ccd70->state == 0 ? TRUE : FALSE;
}

static inline MsgRes *MsgRes_New(const char *arc, const char *name) {
    MsgRes *o = (MsgRes *)Heap_Alloc(sizeof(MsgRes));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208b318);
        o->Clear();
        VOBJ_SET_VTABLE(o, data_0208ba30);
        func_0204bfcc(o);
    }
    func_0204bfe4(o, arc, name);
    return o;
}

BOOL func_ov000_021633ac(MsgBox *self) {
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
        func_0204c030(self->res);
        self->numLines = func_0204c08c(self->res, self->msgId, &self->text, 1);
        o = (SlideWin *)Heap_Alloc(sizeof(SlideWin));
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208ba70);
            func_0204c7d0(o);
            VOBJ_SET_VTABLE(o, data_0208bbc8);
            func_02050f70(o);
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
