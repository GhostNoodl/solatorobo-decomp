#include "ov000/TextList.h"

extern "C" {

extern u8 UiObj_vtbl[];
extern u8 Ov000Vt_021ccadc_vtbl[];
void Heap_Free(void *ptr);
void Obj021c61a8_Release(TextList *self);

TextList *Ov000Vt_021ccadc_DtorDelete(TextList *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021ccadc_vtbl);
    Obj021c61a8_Release(self);
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

TextList *Ov000Vt_021ccadc_Dtor(TextList *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021ccadc_vtbl);
    Obj021c61a8_Release(self);
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    return self;
}

}
