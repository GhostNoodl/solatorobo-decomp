#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

BOOL func_ov000_02152a58(void *self);
BOOL func_ov000_021580e8(void *self);
BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);
void func_ov000_0215429c(void *self);
void func_ov000_0215f0ec(void *p, s32 a);

static inline BOOL LoSubReady(void *p) {
    if (LFLD(void *, p, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, p, 0x6c))) {
        LFLD(void *, p, 0x6c) = NULL;
    } else {
        return LBIT(p, 4).b6 == 0 ? TRUE : FALSE;
    }
    return TRUE;
}

void func_ov000_02158da8(Lo021cb3a8 *self) {
    if ((void *)self->str != NULL) {
        Heap_FreeHi(self->str);
        self->str = NULL;
    }
    LO_FREE_V(self, 0xec);
}

BOOL func_ov000_02158e14(Lo021cb3a8 *self) {
    BOOL r = func_ov000_021580e8(self);
    void *p = self->unk_ec;
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
