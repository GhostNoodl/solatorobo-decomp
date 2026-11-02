#include "ov006/Tasks.h"

extern "C" {

extern u8 data_ov006_021ec040[];
void func_ov006_021ccda0(ov006_Task *self);

ov006_Task021ec040 *Ov006Vt_021ec040_Ctor(ov006_Task021ec040 *self) {
    func_ov006_021ccda0(self);
    *(void **)self = data_ov006_021ec040;
    self->unk10 = NULL;
    self->unk14 = NULL;
    self->unk18 = NULL;
    self->unk1C = NULL;
    self->unk20 = NULL;
    self->unk24 = NULL;
    self->unk28 = NULL;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk3E[0] = 0;
    self->unk3E[1] = 0;
    return self;
}

}
