#include "ov006/Model.h"

typedef struct ov006_Unk021e279c {
    u8 unk0[0x60];
    Model *unk60;
} ov006_Unk021e279c;

extern "C" {

extern char data_ov006_021ec864[];
extern char data_ov006_021ec1a9[];

void ov006_Unk021e279c_Load(ov006_Unk021e279c *self) {
    Model *model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    self->unk60 = model;
    TexObj_SetRes(self->unk60, ResMgr_FindArcType2(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk60->flags |= 2;
    self->unk60->flags |= 0x80000;
    self->unk60->flags |= 0x400000;
    TexObj_SelectImage(self->unk60, 2, 0xc);
    TexObj_SelectImage(self->unk60, 2, 0xd);
    TexObj_SelectImage(self->unk60, 2, 0xe);
    TexObj_SelectImage(self->unk60, 2, 0xf);
}

}
