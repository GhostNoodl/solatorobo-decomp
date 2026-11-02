#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Heap_FreeHi(void *p);
BOOL func_ov000_02152a58(void *self);
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

void func_ov000_02158f30(Lo021cb3a8 *self, s32 n, s32 b) {
    s8 old = self->unk_b1;
    s16 max = self->unk_9c;
    s32 m = self->unk_20;
    self->unk_b0 = old;
    if (max > m) {
        self->unk_b1 = old + (s8)n;
        if (self->unk_b1 + m > max) {
            self->unk_b1 = max - m;
        }
    }
    self->vfunc_bc(self->unk_b1 - self->unk_b0, b);
    self->unk_a2 = 4;
}

void func_ov000_02158f98(Lo021cb3a8 *self, s32 n, s32 b) {
    s8 old = self->unk_b1;
    self->unk_b0 = old;
    if (self->unk_0c & 0x20000) {
        self->unk_b1 = old + (s8)n;
        if (self->unk_b1 + self->unk_20 > self->unk_9c) {
            self->unk_b1 = self->unk_9c - self->unk_20;
        }
    }
    self->vfunc_bc(self->unk_b1 - self->unk_b0, b);
    self->unk_a2 = 8;
}

}
