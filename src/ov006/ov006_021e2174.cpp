#include "ov006/SlotManager.h"

typedef struct ov006_Elem021e1f28 {
    u8 unk0[0x24];
} ov006_Elem021e1f28;

typedef struct ov006_Unk021e2174 {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    ov006_Elem021e1f28 elems[4];
} ov006_Unk021e2174;

extern "C" {

extern u8 data_ov006_021ec2cc[];
void *func_ov006_021e1f28(void *self);
void func_ov006_021e1f68(void *self);

ov006_Unk021e2174 *func_ov006_021e2174(ov006_Unk021e2174 *self) {
    self->vtbl = data_ov006_021ec2cc;
    __cxa_vec_ctor(self->elems, 4, sizeof(ov006_Elem021e1f28), (void *)func_ov006_021e1f28, (void *)func_ov006_021e1f68);
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    return self;
}

}
