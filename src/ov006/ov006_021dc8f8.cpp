#include "ov006/Model.h"
#include "ov006/Racer.h"

extern "C" {

extern char data_ov006_021ec178[];
extern char data_ov006_021ec185[];
void LangData_LocalizePath(char *dst, const char *src);
void TexObj_SetOamFunc(Model *m, int a, void *cb, int b);
void *ov006_Unk021dc6b4_ShiftPalette(void *a, u16 *b, void *c, u16 *d);

void Ov006Marker_Load(Ov006Marker *self) {
    char file[0x20];
    Model *model;
    LangData_LocalizePath(file, data_ov006_021ec178);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec185;
        const char *path = file;
        if (path) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, path);
        }
    }
    self->model = model;
    TexObj_SetRes(self->model, func_02035de0(file, data_ov006_021ec185));
    self->model->flags |= 2;
    self->model->flags |= 0x80000;
    TexObj_SetOamFunc(self->model, 0xf, (void *)ov006_Unk021dc6b4_ShiftPalette, 0);
    TexObj_SelectImage(self->model, 0, 0xffff);
}

}
