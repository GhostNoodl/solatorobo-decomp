#include "ov000/TextList.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccadc[];
void Heap_Free(void *ptr);
void Obj021c61a8_Release(TextList *self);

TextList *Ov000Vt_021ccadc_DtorDelete(TextList *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccadc);
    Obj021c61a8_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

TextList *Ov000Vt_021ccadc_Dtor(TextList *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccadc);
    Obj021c61a8_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

}
