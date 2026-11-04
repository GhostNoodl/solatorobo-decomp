#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/SlideWin.h"
#include "ov000/LoTimer.h"
#include "ov000/HeapScope.h"
#include "ov000/LoTicker.h"
#include "ov000/Obj0216c954.h"
#include "ov000/Obj0216ad04.h"

extern "C" {

extern u8 ResHandle_vtbl[];
void Bss021ccd74_FreeModels(void);
void ListBuffer021cb940_Init(ListBuffer021cb940 *self);
void Obj021bbc68_Release(void *p);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
void TextBox_Release(void *p);
void Lo0216b474_Release(Lo0216b474 *p);
void ImageCard_Dtor(void *p);
void PlaceNameCard_Dtor(void *p);
void Obj021b8ecc_Release(void *p);
void Obj021bacf4_Release(void *p);
void Obj021bb810_Release(void *p);

void ListBuffer021cb940_Release(ListBuffer021cb940 *self) {
    Bss021ccd74_FreeModels();
    HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
    HEAP_DELETE_FN(self->unk_2c, TextBox_Release);
    HEAP_DELETE(VObj *, self->unk_30, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_34, ImageCard_Dtor);
    HEAP_DELETE_FN(self->unk_38, PlaceNameCard_Dtor);
    HEAP_DELETE(Lo021cb0b8 *, self->dialog, p->vfunc_04());
    HEAP_DELETE_FN(self->unk_3c, Obj021b8ecc_Release);
    HEAP_DELETE_FN(self->unk_40, Obj021bacf4_Release);
    HEAP_DELETE(u8 *, self->unk_44, Obj021bbc68_Release(p); *(void **)(p + 4) = ResHandle_vtbl; ((VObj *)(p + 4))->vfunc_0c(); Heap_Free(p));
    HEAP_DELETE_FN(self->unk_4c, Obj021bb810_Release);
    HEAP_DELETE(Obj0216c954 *, self->unk_50, Obj0216c9b0_Release(p); Heap_Free(p));
    HEAP_DELETE(LoTimer *, self->unk_54, LoTimer_FreeModels(p); Heap_Free(p));
    HEAP_DELETE(VObj *, self->unk_58, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_5c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_60, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_64, p->vfunc_04());
    HEAP_DELETE(Lo0216b474 *, self->unk_68, Lo0216b474_Release(p); Heap_Free(p));
    HEAP_DELETE(VObj *, self->unk_6c, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_70, p->vfunc_04());
    HEAP_DELETE(VObj *, self->unk_74, p->vfunc_04());
    HEAP_DELETE(Obj0216ad04 *, self->unk_78, Obj0216ad04_Release(p); Heap_Free(p));
    HEAP_DELETE(LoTicker *, self->ticker, LoTicker_Release(p); __cxa_vec_cleanup(p->res, 10, sizeof(LoTextHolder), (void (*)(void *))LoTextHolder_Dtor); Heap_Free(p));
    ListBuffer021cb940_Init(self);
}

}
