#include "types.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline void SetFlag02177240(VObj *self) {
    u8 *p = LFLD(u8 *, self, 0x4c);
    if (p != NULL) {
        LFLD(u32, p, 0xc) |= 4;
    }
}

static inline BOOL IsBusy02177240(VObj *o) {
    return o != NULL && o->vfunc_1c();
}

void func_ov000_02177240(VObj *self) {
    s32 n;
    if (LFLD(s32, self, 0x8) == 0xd) {
        VObj *o = LFLD(VObj *, self, 0x58);
        if (o != NULL) {
            if (o->vfunc_1c()) {
                SetFlag02177240(self);
            } else {
                HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x58), p->vfunc_04());
            }
        }
        n = 0;
        if (LFLD(VObj *, self, 0x3c) != NULL && LFLD(VObj *, self, 0x3c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x40) != NULL && LFLD(VObj *, self, 0x40)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x44) != NULL && LFLD(VObj *, self, 0x44)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x48) != NULL && LFLD(VObj *, self, 0x48)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x4c) != NULL && LFLD(VObj *, self, 0x4c)->vfunc_1c()) {
            n++;
        }
        if (LFLD(VObj *, self, 0x50) != NULL && LFLD(VObj *, self, 0x50)->vfunc_1c()) {
            n++;
        }
        if (n == 0) {
            self->vfunc_0c(0);
        }
    }
    SetFlag02177240(self);
}
}
