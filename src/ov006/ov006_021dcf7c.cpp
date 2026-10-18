#include "ov006/Model.h"

typedef struct ov006_Unk021dcf7c {
    u8 unk0[5];
    s8 unk5;
    u8 unk6;
    u8 unk7[5];
    ov006_Model *unkC;
    ov006_Model *unk10;
} ov006_Unk021dcf7c;

extern "C" {

extern char data_ov006_021ec178[];
extern char data_ov006_021ec191[];
extern char data_ov006_021ec19d[];
void func_0206e900(char *dst, const char *src);

void func_ov006_021dcf7c(ov006_Unk021dcf7c *self) {
    char file[0x20];
    ov006_Model *model;

    func_0206e900(file, data_ov006_021ec178);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec191;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unkC = model;
    func_020417e0(self->unkC, func_02035de0(file, data_ov006_021ec191));
    self->unkC->unk6C |= 2;
    self->unkC->unk6C |= 0x80000;
    func_02041d9c(self->unkC, 0, 0);
    func_02041d9c(self->unkC, 0, 1);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec19d;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unk10 = model;
    func_020417e0(self->unk10, func_02035de0(file, data_ov006_021ec19d));
    self->unk10->unk6C |= 2;
    self->unk10->unk6C |= 0x80000;
    func_02041d9c(self->unk10, 0, 0xffff);
    self->unk5 = -1;
    self->unk6 = 4;
}

}
