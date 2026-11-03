#include "ov006/SlotManager.h"

extern "C" {

ov006_SlotManager *Ov006Vt_021ec068_Dtor(ov006_SlotManager *self) {
    __cxa_vec_cleanup(self->slots, 4, sizeof(ov006_Slot), ov006_Slot_Dtor);
    return self;
}

ov006_SlotManager *Ov006Vt_021ec068_DtorDelete(ov006_SlotManager *self) {
    __cxa_vec_cleanup(self->slots, 4, sizeof(ov006_Slot), ov006_Slot_Dtor);
    Heap_Free(self);
    return self;
}

}
