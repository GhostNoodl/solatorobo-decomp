#include "ov006/Model.h"

typedef struct ov006_Marker {
    u8 unk0[4];
    u16 unk4;
    u8 unk6[4];
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD[0x17];
} ov006_Marker;

typedef struct ov006_MarkerSet {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    ov006_Marker markers[4];
    ov006_Model *model;
} ov006_MarkerSet;

extern "C" {

extern void *data_ov006_021ec2cc;
extern char data_ov006_021ec1a9[];
extern char data_ov006_021ec864[];

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

void func_ov006_021e22e4(ov006_MarkerSet *self) {
    ov006_Model *model;
    int i;

    for (i = 0; i < 4; i++) {
        self->markers[i].unkA = 0;
        self->markers[i].unkB = 0;
        self->markers[i].unkC = 0;
        self->markers[i].unk4 = 1;
    }
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, data_ov006_021ec864);
        }
    }
    self->model = model;
    func_020417e0(self->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->model->unk6C |= 2;
    self->model->unk6C |= 0x80000;
    self->model->unk6C |= 0x400000;
    func_02041d9c(self->model, 2, 0x10);
    func_02041d9c(self->model, 2, 0x11);
    func_02041d9c(self->model, 2, 0x12);
    func_02041d9c(self->model, 2, 0x13);
    func_02041d9c(self->model, 2, 0x14);
    func_02041d9c(self->model, 2, 0x15);
    func_02041d9c(self->model, 2, 0x16);
    func_02041d9c(self->model, 2, 0x17);
}

}
