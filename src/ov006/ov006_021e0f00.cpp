#include "ov006/Caption.h"

typedef struct ov006_Unk021e0f00 {
    u8 unk0[0x1c];
    ov006_Model *unk1C;
    ov006_Anim *unk20;
} ov006_Unk021e0f00;

extern "C" {

void func_ov006_021e0f00(ov006_Unk021e0f00 *self) {
    ov006_Model *model;
    const char *text;

    self->unk20 = ov006_Anim_New();
    text = data_ov006_021ec1b5;
    if (self->unk20 != NULL) {
        VCALL(self->unk20, 08);
        self->unk20->unk28 = 3;
        self->unk20->unk2C = 4;
        self->unk20->unk34 = 0;
        ov006_Anim_Start(self->unk20, (int)text);
        func_0204ca14(self->unk20, 8);
        self->unk20->unk4 |= 4;
    }
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            func_0201e520(model->unk2C, data_ov006_021ec864);
        }
    }
    self->unk1C = model;
    func_020417e0(self->unk1C, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk1C->unk6C |= 2;
    self->unk1C->unk6C &= ~0x80000;
    self->unk1C->unk6C |= 0x400000;
    func_02041d9c(self->unk1C, 2, 2);
    func_02041d9c(self->unk1C, 2, 3);
    func_02041d9c(self->unk1C, 2, 4);
    func_02041d9c(self->unk1C, 2, 5);
    func_02041d9c(self->unk1C, 2, 6);
    func_02041d9c(self->unk1C, 2, 7);
}

}
