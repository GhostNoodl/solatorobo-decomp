#include "ov006/Model.h"

typedef struct ov006_MarkerSet {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    u8 markers[4][0x24];
    ov006_Model *model;
} ov006_MarkerSet;

extern "C" {

extern void *data_ov006_021ec2cc;

void func_02009f64(void *arr, int count, u32 size, void *dtor);
void func_ov006_021e1f68(void *self);

static inline void ov006_MarkerSet_Dtor(ov006_MarkerSet *self) {
    self->vtbl = &data_ov006_021ec2cc;
    OV006_DELETE_MODEL(self->model);
    func_02009f64(self->markers, 4, sizeof(self->markers[0]), func_ov006_021e1f68);
}

ov006_MarkerSet *func_ov006_021e21cc(ov006_MarkerSet *self) {
    ov006_MarkerSet_Dtor(self);
    return self;
}

ov006_MarkerSet *func_ov006_021e2254(ov006_MarkerSet *self) {
    ov006_MarkerSet_Dtor(self);
    func_0203de1c(self);
    return self;
}

}
