#include "ov006/Model.h"
#include "ov006/Racer.h"

extern "C" {

extern char data_ov006_021ec178[];
extern char data_ov006_021ec185[];
void func_0206e900(char *dst, const char *src);
void func_02041c34(Model *m, int a, void *cb, int b);
void *func_ov006_021dc6b4(void *a, u16 *b, void *c, u16 *d);

void func_ov006_021dc8f8(Ov006Marker *self) {
    char file[0x20];
    Model *model;
    func_0206e900(file, data_ov006_021ec178);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec185;
        const char *path = file;
        if (path) {
            func_02041218(&model->pltt);
            func_02041440(model, name, 0);
            STD_CopyString(model->name, path);
        }
    }
    self->model = model;
    func_020417e0(self->model, func_02035de0(file, data_ov006_021ec185));
    self->model->flags |= 2;
    self->model->flags |= 0x80000;
    func_02041c34(self->model, 0xf, (void *)func_ov006_021dc6b4, 0);
    func_02041d9c(self->model, 0, 0xffff);
}

}
