#include "ov006/Marker.h"

extern "C" {

extern void *data_ov006_021ec2cc;
extern char data_ov006_021ec1a9[];
extern char data_ov006_021ec864[];

void __cxa_vec_cleanup(void *arr, int count, u32 size, void *dtor);

static inline void ov006_MarkerSet_Dtor(ov006_MarkerSet *self) {
    self->vtbl = &data_ov006_021ec2cc;
    OV006_DELETE_MODEL(self->model);
    __cxa_vec_cleanup(self->markers, 4, sizeof(self->markers[0]), func_ov006_021e1f68);
}

ov006_MarkerSet *Ov006Vt_021ec2cc_Dtor(ov006_MarkerSet *self) {
    ov006_MarkerSet_Dtor(self);
    return self;
}

ov006_MarkerSet *Ov006Vt_021ec2cc_DtorDelete(ov006_MarkerSet *self) {
    ov006_MarkerSet_Dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_MarkerSet_Load(ov006_MarkerSet *self) {
    Model *model;
    int i;

    for (i = 0; i < 4; i++) {
        self->markers[i].unkA = 0;
        self->markers[i].unkB = 0;
        self->markers[i].unkC = 0;
        self->markers[i].state = 1;
    }
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    self->model = model;
    TexObj_SetRes(self->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->model->flags |= 2;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x400000;
    TexObj_SelectImage(self->model, 2, 0x10);
    TexObj_SelectImage(self->model, 2, 0x11);
    TexObj_SelectImage(self->model, 2, 0x12);
    TexObj_SelectImage(self->model, 2, 0x13);
    TexObj_SelectImage(self->model, 2, 0x14);
    TexObj_SelectImage(self->model, 2, 0x15);
    TexObj_SelectImage(self->model, 2, 0x16);
    TexObj_SelectImage(self->model, 2, 0x17);
}

}
