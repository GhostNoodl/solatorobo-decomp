#include "ov000/VObj.h"
#include "ov000/MessageQueue.h"
#include "Main/Sys/FieldState.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Res/MsgRes.h"

extern "C" {

extern u8 data_0208ba70[];
extern u8 data_0208bbc8[];
BOOL func_ov000_02184498(FieldState *p);
s32 func_0204c08c(MsgRes *res, u16 id, char **out, s32 max);
void *Heap_Alloc(u32 size);
void func_0204c7d0(TextWin *win);
void func_02050f70(SlideWin *win);

static inline void SlideWin_SetText(SlideWin *e, char *text, s32 numLines) {
    e->text = text;
    e->unk_b70 = 0;
    e->numLines = numLines;
}

static inline BOOL IsFlag(void) {
    return data_ov000_021ccd70->flag0 == 1 ? TRUE : FALSE;
}

BOOL func_ov000_02170188(ListBuffer021cb940 *self, MsgRes *msg, u32 arg) {
    FieldState *p;
    char *text;
    u16 hi;
    s32 numLines;
    SlideWin *e;
    p = data_ov000_021ccd54;
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
    if (func_020658cc(data_0214a420, 0x2712) || func_020658cc(data_0214a420, 0x2713) || func_020658cc(data_0214a420, 0x191)) {
        return FALSE;
    }
    if (IsFlag()) {
        return FALSE;
    }
    hi = arg >> 16;
    numLines = func_0204c08c(msg, arg, &text, 1);
    e = (SlideWin *)Heap_Alloc(sizeof(SlideWin));
    if (e != NULL) {
        VOBJ_SET_VTABLE(e, data_0208ba70);
        func_0204c7d0(e);
        VOBJ_SET_VTABLE(e, data_0208bbc8);
        func_02050f70(e);
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
