#include "ov006/ov006.h"
#include "ov006/Window.h"

extern "C" {

extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cac60[];

static inline void ov006_ListWin_Release(ov006_ListWin *self) {
    *(void **)self = data_ov000_021cb0b8;
    self->vfunc_2c();
    *(void **)self = data_ov000_021cb1b0;
    self->vfunc_2c();
    *(void **)self = data_ov000_021caec8;
    self->vfunc_2c();
    *(void **)self = data_ov000_021cac60;
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
