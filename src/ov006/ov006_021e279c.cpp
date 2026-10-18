#include "ov006/Model.h"

typedef struct ov006_Unk021e279c {
    u8 unk0[0x60];
    ov006_Model *unk60;
} ov006_Unk021e279c;

extern "C" {

extern const char data_ov006_021ec864[];
extern const char data_ov006_021ec1a9[];

void func_ov006_021e279c(ov006_Unk021e279c *self) {
    ov006_Model *model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, data_ov006_021ec864);
        }
    }
    self->unk60 = model;
    func_020417e0(self->unk60, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk60->unk6C |= 2;
    self->unk60->unk6C |= 0x80000;
    self->unk60->unk6C |= 0x400000;
    func_02041d9c(self->unk60, 2, 0xc);
    func_02041d9c(self->unk60, 2, 0xd);
    func_02041d9c(self->unk60, 2, 0xe);
    func_02041d9c(self->unk60, 2, 0xf);
}

}
