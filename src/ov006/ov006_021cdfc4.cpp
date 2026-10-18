#include "ov006/Tasks.h"

typedef struct ov006_TaskCDF {
    ov006_TaskHead head;
    int unk3C;
    int unk40;
    u8 unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
} ov006_TaskCDF;

extern "C" {

extern void *data_ov006_021ebe40;

ov006_TaskCDF *func_ov006_021cdfc4(void) {
    ov006_TaskCDF *self = (ov006_TaskCDF *)func_0203dd9c(sizeof(ov006_TaskCDF));
    if (self != NULL) {
        OV006_TASKBASE_CTOR(&self->head);
        self->head.vtbl = &data_ov006_021ebe40;
        self->unk3C = 0;
        self->unk40 = 0;
        self->unk44 = 0;
        self->unk48 = 0;
        self->unk4C = 0;
        self->unk50 = 0;
        self->unk54 = -0x8000;
        self->unk58 = 0x8000;
    }
    VCALL(self, 08, 0x23, 300);
    return self;
}

}
