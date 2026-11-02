#include "ov006/ov006.h"
#include "ov006/Window.h"

extern "C" {

extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov006_021ec30c[];

ov006_ListWin *ov006_Window_Ctor(ov006_ListWin *self) {
    *(void **)self = data_ov000_021cac60;
    self->vfunc_28();
    *(void **)self = data_ov000_021caec8;
    self->vfunc_28();
    *(void **)self = data_ov000_021cb1b0;
    self->vfunc_28();
    *(void **)self = data_ov000_021cb0b8;
    self->vfunc_28();
    *(void **)self = data_ov006_021ec30c;
    self->unk_1e2 = 0;
    self->unk_1e4 = 0;
    return self;
}

}
