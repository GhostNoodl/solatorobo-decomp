#include "ov000/VObj.h"
#include "ov000/ListRow.h"

extern "C" {

extern u8 data_ov000_021cac0c[];
void Heap_Free(void *ptr);

void func_ov000_021c2bb0(ListRowGauge *self) {
    self->height = 0xf;
    self->bar = 0;
    self->label = 0;
    self->max = 0x64;
    self->value = 0x24;
    self->built = 0;
}

VObj *Ov000Vt_021cca88_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    Heap_Free(self);
    return self;
}

}
