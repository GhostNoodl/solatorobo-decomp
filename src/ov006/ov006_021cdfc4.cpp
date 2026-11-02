#include "ov006/Tasks.h"
#include "ov006/Emblem.h"

extern "C" {

extern void *data_ov006_021ebe40;

ov006_Emblem *ov006_Emblem_New(void) {
    ov006_Emblem *self = (ov006_Emblem *)Heap_Alloc(sizeof(ov006_Emblem));
    if (self != NULL) {
        OV006_TASKBASE_CTOR(self);
        *(void **)self = &data_ov006_021ebe40;
        self->unk3C = NULL;
        self->unk40 = NULL;
        self->unk44 = 0;
        self->unk48 = 0;
        self->unk4C = 0;
        self->unk50 = 0;
        self->unk54 = -0x8000;
        self->unk58 = 0x8000;
    }
    self->vfunc_08(0x23, 300);
    return self;
}

}
