#include "ov006/Model.h"

typedef struct ov006_Unk021dc8f8 {
    u8 unk0[0x2c];
    ov006_Model *unk2C;
} ov006_Unk021dc8f8;

extern "C" {

extern char data_ov006_021ec178[];
extern char data_ov006_021ec185[];
void func_0206e900(char *dst, const char *src);
void func_02041c34(ov006_Model *m, int a, void *cb, int b);
void *func_ov006_021dc6b4(void *a, u16 *b, void *c, u16 *d);

void func_ov006_021dc8f8(ov006_Unk021dc8f8 *self) {
    char file[0x20];
    ov006_Model *model;
    func_0206e900(file, data_ov006_021ec178);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec185;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unk2C = model;
    func_020417e0(self->unk2C, func_02035de0(file, data_ov006_021ec185));
    self->unk2C->unk6C |= 2;
    self->unk2C->unk6C |= 0x80000;
    func_02041c34(self->unk2C, 0xf, (void *)func_ov006_021dc6b4, 0);
    func_02041d9c(self->unk2C, 0, 0xffff);
}

}
