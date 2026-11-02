#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/SlideWin.h"
#include "ov000/LoTimer.h"
#include "ov000/HeapScope.h"
#include "ov000/LoTicker.h"

extern "C" {

extern u8 data_0208b318[];
void func_ov000_021bd09c(void);
void func_ov000_0216faac(ListBuffer021cb940 *self);
void func_ov000_021bbcac(void *p);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
void func_020507d8(void *p);
void func_ov000_0216ad34(void *p);
void func_ov000_0216b490(void *p);
void func_ov000_0216c9b0(void *p);
void func_ov000_021b8800(void *p);
void func_ov000_021b88d8(void *p);
void func_ov000_021b8ecc(void *p);
void func_ov000_021bacf4(void *p);
void func_ov000_021bb840(void *p);

void func_ov000_0216fb14(ListBuffer021cb940 *self) {
    func_ov000_021bd09c();
    HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
    HEAP_DELETE_FN(self->unk_2c, func_020507d8);
    HEAP_DELETE(VObj *, self->unk_30, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_34, func_ov000_021b8800);
    HEAP_DELETE_FN(self->unk_38, func_ov000_021b88d8);
    HEAP_DELETE(Lo021cb0b8 *, self->dialog, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_3c, func_ov000_021b8ecc);
    HEAP_DELETE_FN(self->unk_40, func_ov000_021bacf4);
    HEAP_DELETE(u8 *, self->unk_44, func_ov000_021bbcac(p); *(void **)(p + 4) = data_0208b318; ((VObj *)(p + 4))->vfunc_0c(); Heap_Free(p));
    HEAP_DELETE_FN(self->unk_4c, func_ov000_021bb840);
    HEAP_DELETE_FN(self->unk_50, func_ov000_0216c9b0);
    HEAP_DELETE(LoTimer *, self->unk_54, func_ov000_0216e5d0(p); Heap_Free(p));
    HEAP_DELETE(VObj *, self->unk_58, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_5c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_60, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_64, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_68, func_ov000_0216b490);
    HEAP_DELETE(VObj *, self->unk_6c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_70, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_74, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_78, func_ov000_0216ad34);
    HEAP_DELETE(LoTicker *, self->ticker, func_ov000_0216bf90(p); __cxa_vec_cleanup(p->res, 10, sizeof(LoTextHolder), (void (*)(void *))func_ov000_0217006c); Heap_Free(p));
    func_ov000_0216faac(self);
}

}
