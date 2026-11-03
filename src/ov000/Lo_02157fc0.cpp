#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

BOOL Model_IsReady(void *a, s32 b);
BOOL Vram_IsTransferDone(void *p);
BOOL UiList_IsLoaded(UiList *self);

static inline BOOL TextReady(TextWin *t) {
    if (t->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone(t->unk_6c)) {
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
    if (q->model && !Model_IsReady(q->model, 0xffff)) {
        r = FALSE;
    }
    return r;
}

BOOL UiList021cb4a8_IsLoaded(UiList021cb4a8 *self) {
    BOOL ok = UiList_IsLoaded(self);
    if (self->unk_d4 && !LabelReady(self->unk_d4)) {
        ok = FALSE;
    }
    if (self->unk_d8 && !LabelReady(self->unk_d8)) {
        ok = FALSE;
    }
    return ok;
}

}
