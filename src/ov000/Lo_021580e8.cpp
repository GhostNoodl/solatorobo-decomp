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

struct Obj021580e8 {
    u8 unk_00[0xb4];
    void *unk_b4;
};

BOOL func_ov000_021580e8(Obj021580e8 *self) {
    BOOL r = func_ov000_02152a58(self);
    if (self->unk_b4 != NULL && !func_02054f10(self->unk_b4, 0xffff)) {
        r = FALSE;
    }
    return r;
}

void func_ov000_02158120(LoBase021caac8_021cb2a8 *self, s32 delta, s32 arg) {
    s8 sel = self->unk_b1;
    s32 off = 0;
    self->unk_b0 = sel;
    self->unk_b1 = self->unk_b1 - (s8)delta;
    if (self->unk_9c <= self->unk_20) {
        if (self->unk_b1 <= 0) {
            self->unk_b1 = 0;
        }
    } else if (LFLD(s16, self->unk_98, 4) == 0) {
        if (self->unk_b1 <= 0) {
            self->unk_b1 = 0;
        }
    } else {
        off = self->unk_b1 - 1;
        if (off < 0) {
            if (off + LFLD(s16, self->unk_98, 4) >= 0) {
                self->unk_b1 = 1;
            } else {
                self->unk_b1 = 0;
                off = -LFLD(s16, self->unk_98, 4);
            }
        } else {
            off = 0;
        }
    }
    self->vfunc_bc(off, arg);
    self->unk_a2 = 4;
}

}
