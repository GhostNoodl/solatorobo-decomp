#include "types.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

void func_ov000_02178110(u8 *self) {
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x3c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x40), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x44), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x48), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x4c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x50), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x54), p->vfunc_04());
}
}
