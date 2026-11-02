#include "ov006/Caption.h"

extern "C" {


static inline void ov006_CaptionPanel_Dtor(ov006_CaptionPanel *self) {
    int i;
    self->vtbl = data_ov006_021ec29c;
    OV006_DELETE_MODEL(self->model);
    OV006_DELETE_OBJECT(self->title);
    for (i = 0; i < 3; i++) {
        OV006_DELETE_OBJECT(self->captions[i]);
    }
}

ov006_CaptionPanel *Ov006Vt_021ec29c_Dtor(ov006_CaptionPanel *self) {
    ov006_CaptionPanel_Dtor(self);
    return self;
}

ov006_CaptionPanel *Ov006Vt_021ec29c_DtorDelete(ov006_CaptionPanel *self) {
    ov006_CaptionPanel_Dtor(self);
    Heap_Free(self);
    return self;
}

void func_ov006_021e2c14(ov006_CaptionPanel *self) {
    Model *model;
    const char *text;

    self->title = ov006_Caption_New();
    self->title->kind = 0;
    ov006_Caption_Init(self->title);
    text = data_ov006_021ec1b5;
    ov006_TextHolder_Play((ov006_TextHolder *)self->title, (int)text, 4);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(&model->pltt);
            func_02041440(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    self->model = model;
    func_020417e0(self->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->model->flags |= 2;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x400000;
    func_02041d9c(self->model, 2, 9);
}

}
