#include "ov006/SlotManager.h"

extern "C" {

ov006_SlotManager *func_ov006_021dac58(ov006_SlotManager *self) {
    __cxa_vec_cleanup(self->slots, 4, sizeof(ov006_Slot), func_ov006_021dab5c);
    return self;
}

ov006_SlotManager *func_ov006_021dac80(ov006_SlotManager *self) {
    __cxa_vec_cleanup(self->slots, 4, sizeof(ov006_Slot), func_ov006_021dab5c);
    func_0203de1c(self);
    return self;
}

}
