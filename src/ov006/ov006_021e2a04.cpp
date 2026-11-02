#include "ov006/Caption.h"

typedef struct ov006_Unk021e2a04 {
    void *vtbl;
    u8 unk4[0xc];
    Model *unk10;
    ov006_Caption *unk14;
    Object *unk18[3];
} ov006_Unk021e2a04;

extern "C" {

extern u8 data_ov006_021ec29c[];

static inline void ov006_Unk021e2a04_dtor(ov006_Unk021e2a04 *self) {
    int i;
    self->vtbl = data_ov006_021ec29c;
    OV006_DELETE_MODEL(self->unk10);
    OV006_DELETE_OBJECT(self->unk14);
    for (i = 0; i < 3; i++) {
        OV006_DELETE_OBJECT(self->unk18[i]);
    }
}

ov006_Unk021e2a04 *Ov006Vt_021ec29c_Dtor(ov006_Unk021e2a04 *self) {
    ov006_Unk021e2a04_dtor(self);
    return self;
}

ov006_Unk021e2a04 *Ov006Vt_021ec29c_DtorDelete(ov006_Unk021e2a04 *self) {
    ov006_Unk021e2a04_dtor(self);
    Heap_Free(self);
    return self;
}

void func_ov006_021e2c14(ov006_Unk021e2a04 *self) {
    Model *model;
    const char *text;

    self->unk14 = ov006_Caption_New();
    self->unk14->kind = 0;
    ov006_Caption_Init(self->unk14);
    text = data_ov006_021ec1b5;
    ov006_TextHolder_Play((ov006_TextHolder *)self->unk14, (int)text, 4);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(&model->pltt);
            func_02041440(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    self->unk10 = model;
    func_020417e0(self->unk10, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk10->flags |= 2;
    self->unk10->flags |= 0x80000;
    self->unk10->flags |= 0x400000;
    func_02041d9c(self->unk10, 2, 9);
}

}
