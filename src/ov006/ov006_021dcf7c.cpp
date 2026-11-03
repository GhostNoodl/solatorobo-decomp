#include "ov006/Model.h"

typedef struct ov006_Unk021dcf7c {
    u8 unk0[5];
    s8 unk5;
    u8 unk6;
    u8 unk7[5];
    Model *unkC;
    Model *unk10;
} ov006_Unk021dcf7c;

extern "C" {

extern char data_ov006_021ec178[];
extern char data_ov006_021ec191[];
extern char data_ov006_021ec19d[];
void LangData_LocalizePath(char *dst, const char *src);

void ov006_Unk021dcf7c_Load(ov006_Unk021dcf7c *self) {
    char file[0x20];
    Model *model;

    LangData_LocalizePath(file, data_ov006_021ec178);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec191;
        const char *path = file;
        if (path) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, path);
        }
    }
    self->unkC = model;
    TexObj_SetRes(self->unkC, ResMgr_FindArcType2(file, data_ov006_021ec191));
    self->unkC->flags |= 2;
    self->unkC->flags |= 0x80000;
    TexObj_SelectImage(self->unkC, 0, 0);
    TexObj_SelectImage(self->unkC, 0, 1);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec19d;
        const char *path = file;
        if (path) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, path);
        }
    }
    self->unk10 = model;
    TexObj_SetRes(self->unk10, ResMgr_FindArcType2(file, data_ov006_021ec19d));
    self->unk10->flags |= 2;
    self->unk10->flags |= 0x80000;
    TexObj_SelectImage(self->unk10, 0, 0xffff);
    self->unk5 = -1;
    self->unk6 = 4;
}

}
