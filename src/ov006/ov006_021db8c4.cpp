#include "ov006/ov006.h"
#include "ov006/Window.h"

extern "C" {

extern u8 Ov000Vt_021cb0b8_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 ov006_Window_vtbl[];

ov006_ListWin *ov006_Window_Ctor(ov006_ListWin *self) {
    *(void **)self = UiObj_vtbl;
    self->vfunc_28();
    *(void **)self = UiList_vtbl;
    self->vfunc_28();
    *(void **)self = Ov000Vt_021cb1b0_vtbl;
    self->vfunc_28();
    *(void **)self = Ov000Vt_021cb0b8_vtbl;
    self->vfunc_28();
    *(void **)self = ov006_Window_vtbl;
    self->unk_1e2 = 0;
    self->unk_1e4 = 0;
    return self;
}

}
