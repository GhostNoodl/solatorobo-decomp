#include "ov000/VObj.h"
#include "ov000/MessageQueue.h"
#include "Main/Sys/FieldState.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Res/MsgRes.h"

extern "C" {

extern u8 TextWin_vtbl[];
extern u8 MainVt_0208bbc8_vtbl[];
BOOL func_ov000_02184498(FieldState *p);
s32 MsgRes_GetLines(MsgRes *res, u16 id, char **out, s32 max);
void *Heap_Alloc(u32 size);
void TextWin_Init(TextWin *win);
void TwScene_Init(SlideWin *win);

static inline void SlideWin_SetText(SlideWin *e, char *text, s32 numLines) {
    e->text = text;
    e->unk_b70 = 0;
    e->numLines = numLines;
}

static inline BOOL IsFlag(void) {
    return gFieldFade->flag0 == 1 ? TRUE : FALSE;
}

BOOL ListBuffer021cb940_OpenWindow(ListBuffer021cb940 *self, MsgRes *msg, u32 arg) {
    FieldState *p;
    char *text;
    u16 hi;
    s32 numLines;
    SlideWin *e;
    p = gSceneCmd;
    if ((u32)(p->unk_98 - 0x11) > 2) {
        return FALSE;
    }
    if (self->state != 3) {
        return FALSE;
    }
    if (self->win != NULL) {
        return FALSE;
    }
    if (!func_ov000_02184498(p)) {
        return FALSE;
    }
    if (EffectMgr_FindByKey(gEffectMgr, 0x2712) || EffectMgr_FindByKey(gEffectMgr, 0x2713) || EffectMgr_FindByKey(gEffectMgr, 0x191)) {
        return FALSE;
    }
    if (IsFlag()) {
        return FALSE;
    }
    hi = arg >> 16;
    numLines = MsgRes_GetLines(msg, arg, &text, 1);
    e = (SlideWin *)Heap_Alloc(sizeof(SlideWin));
    if (e != NULL) {
        VOBJ_SET_VTABLE(e, TextWin_vtbl);
        TextWin_Init(e);
        VOBJ_SET_VTABLE(e, MainVt_0208bbc8_vtbl);
        TwScene_Init(e);
    }
    self->win = e;
    e->font = 8;
    SlideWin_SetText(self->win, text, numLines);
    self->win->mode = hi & 0xf;
    self->win->rendering = 1;
    self->state = 4;
    return TRUE;
}

}
