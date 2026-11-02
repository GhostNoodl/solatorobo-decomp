#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

BOOL func_ov000_021580e8(UiList *self);
BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);

static inline BOOL LoSubReady(TextWin *p) {
    if (p->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(p->unk_6c)) {
        p->unk_6c = NULL;
    } else {
        return p->noVram == 0 ? TRUE : FALSE;
    }
    return TRUE;
}

void func_ov000_02158da8(Lo021cb3a8 *self) {
    if ((void *)self->str != NULL) {
        Heap_FreeHi(self->str);
        self->str = NULL;
    }
    HEAP_DELETE(TextWin *, self->text, p->unk_vf04());
}

BOOL func_ov000_02158e14(Lo021cb3a8 *self) {
    BOOL r = func_ov000_021580e8(self);
    TextWin *p = self->text;
    if (p != NULL && !LoSubReady(p)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02158e80(Lo021cb3a8 *self, s32 n, s32 b) {
    s8 old = self->cursor;
    self->cursor = old - (s8)n;
    self->unk_b0 = old;
    if (self->cursor < 0) {
        self->cursor = 0;
    }
    self->vfunc_bc(self->cursor - self->unk_b0, b);
    self->unk_a2 = 4;
}

}
