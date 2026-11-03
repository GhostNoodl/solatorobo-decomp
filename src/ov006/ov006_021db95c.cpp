#include "ov006/ov006.h"
#include "ov006/Window.h"

extern "C" {

extern u8 Ov000Vt_021cb0b8_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiObj_vtbl[];

static inline void ov006_ListWin_Release(ov006_ListWin *self) {
    *(void **)self = Ov000Vt_021cb0b8_vtbl;
    self->vfunc_2c();
    *(void **)self = Ov000Vt_021cb1b0_vtbl;
    self->vfunc_2c();
    *(void **)self = UiList_vtbl;
    self->vfunc_2c();
    *(void **)self = UiObj_vtbl;
    self->vfunc_2c();
}

ov006_ListWin *ov006_Window_Dtor(ov006_ListWin *self) {
    ov006_ListWin_Release(self);
    return self;
}

ov006_ListWin *ov006_Window_DtorDelete(ov006_ListWin *self) {
    ov006_ListWin_Release(self);
    Heap_Free(self);
    return self;
}

}
