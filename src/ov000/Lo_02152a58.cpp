#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);
void LoTextHolder_SetText(void *dst, void *src);
BOOL Model_IsReady(void *a, s32 b);
BOOL Vram_IsTransferDone(void *p);
void Obj0215eab4_Draw(void *p);

static inline BOOL LoResDone(TextWin *o) {
    if (o->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone(o->unk_6c)) {
        o->unk_6c = NULL;
    } else {
        return o->noVram ? FALSE : TRUE;
    }
    return TRUE;
}


BOOL UiObj_IsLoaded(UiObj *self) {
    BOOL ok = TRUE;
    if (self->model && !Model_IsReady(self->model, 0xffff)) {
        ok = FALSE;
    }
    if (self->title && !LoResDone(self->title)) {
        ok = FALSE;
    }
    if (self->caption && !LoResDone(self->caption)) {
        ok = FALSE;
    }
    return ok;
}

}
