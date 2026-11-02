#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

BOOL func_02054f10(void *a, s32 b);
BOOL func_0203e63c(void *p);
BOOL func_ov000_021580e8(UiList *self);

static inline BOOL TextReady(TextWin *t) {
    if (t->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(t->unk_6c)) {
        t->unk_6c = NULL;
    } else {
        return t->noVram ? FALSE : TRUE;
    }
    return TRUE;
}

static inline BOOL LabelReady(UiLabel *q) {
    BOOL r = TRUE;
    if (q->text && !TextReady(q->text)) {
        r = FALSE;
    }
    if (q->model && !func_02054f10(q->model, 0xffff)) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_02157fc0(UiList021cb4a8 *self) {
    BOOL ok = func_ov000_021580e8(self);
    if (self->unk_d4 && !LabelReady(self->unk_d4)) {
        ok = FALSE;
    }
    if (self->unk_d8 && !LabelReady(self->unk_d8)) {
        ok = FALSE;
    }
    return ok;
}

}
