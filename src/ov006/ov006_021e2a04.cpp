#include "ov006/Caption.h"

typedef struct ov006_Unk021e2a04 {
    void *vtbl;
    u8 unk4[0xc];
    ov006_Model *unk10;
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

ov006_Unk021e2a04 *func_ov006_021e2a04(ov006_Unk021e2a04 *self) {
    ov006_Unk021e2a04_dtor(self);
    return self;
}

ov006_Unk021e2a04 *func_ov006_021e2b08(ov006_Unk021e2a04 *self) {
    ov006_Unk021e2a04_dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021e2c14(ov006_Unk021e2a04 *self) {
    ov006_Model *model;
    const char *text;

    self->unk14 = ov006_Caption_New();
    self->unk14->unk20 = 0;
    ov006_Caption_Init(self->unk14);
    text = data_ov006_021ec1b5;
    ov006_AnimHolder_Play((ov006_AnimHolder *)self->unk14, (int)text, 4);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, data_ov006_021ec864);
        }
    }
    self->unk10 = model;
    func_020417e0(self->unk10, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk10->unk6C |= 2;
    self->unk10->unk6C |= 0x80000;
    self->unk10->unk6C |= 0x400000;
    func_02041d9c(self->unk10, 2, 9);
}

}
