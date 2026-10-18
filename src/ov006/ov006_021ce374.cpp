#include "ov006/Emblem.h"

extern "C" {

extern char data_ov006_021ebbc5[];
extern char data_ov006_021ec864[];
extern char *data_0208ccc0;
extern char *data_0208cca0;

void func_ov006_021ce048(void);
void func_ov006_021ce3f0(ov006_Emblem *self);
void func_ov000_02173648(ov006_Emblem *self);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c20(ov006_Model *self, int a, void *b);
BOOL func_02054f10(ov006_Model *a, int b);

void func_ov006_021ce374(void) {
}

BOOL func_ov006_021ce378(void) {
    return TRUE;
}

void func_ov006_021ce380(ov006_Emblem *self) {
    self->unk4_1 = 0;
    if (VCALL(self, 28)) {
        return;
    }
    func_ov006_021ce3f0(self);
    self->unk44 = 1;
    self->unk2C = 0;
    func_ov000_02173648(self);
}

static inline BOOL ov006_Emblem_Bit4(ov006_Emblem *self) {
    return self->unk4_4 != 0;
}

BOOL func_ov006_021ce3cc(ov006_Emblem *self) {
    return ov006_Emblem_Bit4(self) ? TRUE : FALSE;
}

void func_ov006_021ce3f0(ov006_Emblem *self) {
    ov006_Model *model;
    ov006_Model *model2;

    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ebbc5;
        if (name) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            func_0201e520(model->unk2C, data_ov006_021ec864);
        }
    }
    self->unk3C = model;
    func_020417e0(self->unk3C, func_02035de0(data_ov006_021ec864, data_ov006_021ebbc5));
    self->unk3C->unk6C |= 2;
    self->unk3C->unk6C |= 0x80000;
    func_02041d9c(self->unk3C, 2, 0xffff);
    model2 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model2 != NULL) {
        const char *file = data_0208cca0;
        const char *name = data_0208ccc0;
        func_02041218(model2->unk88);
        func_02041440(model2, name, 0);
        func_0201e520(model2->unk2C, file);
    }
    self->unk40 = model2;
    func_020417e0(self->unk40, func_02034d88(func_02035d5c(data_0208cca0), data_0208ccc0));
    self->unk40->unk6C |= 2;
    func_02041d9c(self->unk40, 0, 0);
    ov006_Model_SetPos(self->unk40, 0, 0, 0);
    self->unk40->unk150 = 0xfffe019a;
    self->unk40->unk158 = (void *)func_ov006_021ce048;
    func_02041c20(self->unk40, 0, &self->unk48);
}

}
