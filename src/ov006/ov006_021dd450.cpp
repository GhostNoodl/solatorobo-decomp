#include "ov006/Model.h"
#include "ov000/ObjLayouts.h"
#include <nitro/fx.h>

typedef struct ov006_Unk021dd450 {
    u8 unk0[0x18];
    ObjBase021cac0c_021cb6f0 *unk18;
    Model *unk1C;
} ov006_Unk021dd450;

extern "C" {

extern u8 Ov000Vt_021cac0c_vtbl[];
extern const char data_ov006_021ec09a[];
extern const char data_ov006_021ec0a0[];
extern char data_ov006_021ec178[];
extern char data_ov006_021ec191[];
void LangData_LocalizePath(char *dst, const char *src);
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);

static inline void ov006_SetPos021dd450(ObjBase021cac0c_021cb6f0 *o, fx32 x, fx32 y, fx32 z) {
    o->unk_38 = x;
    o->unk_3c = y;
    o->unk_40 = z;
}

void ov006_Unk021dd450_Load(ov006_Unk021dd450 *self) {
    char file[0x20];
    ObjBase021cac0c_021cb6f0 *text;
    Model *model;

    text = (ObjBase021cac0c_021cb6f0 *)Heap_Alloc(sizeof(ObjBase021cac0c_021cb6f0));
    if (text != NULL) {
        *(void **)text = Ov000Vt_021cac0c_vtbl;
        text->vfunc_14();
    }
    self->unk18 = text;
    text->unk_0c |= 8;
    self->unk18->unk_0c &= ~0x20;
    self->unk18->unk_50 = 99;
    self->unk18->unk_54 = 3;
    ov006_SetPos021dd450(self->unk18, 0, 0, 0);
    self->unk18->unk_28 = 2;
    self->unk18->unk_30 = 0;
    Obj0215fdfc_SetEntry(self->unk18, 1, data_ov006_021ec09a);
    Obj0215fdfc_SetEntry(self->unk18, 2, data_ov006_021ec0a0);
    self->unk18->unk_58 = 0;
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        PlttRes_Init_02041218(&model->pltt);
        TexObj_Init(model, NULL, 0);
    }
    self->unk1C = model;
    LangData_LocalizePath(file, data_ov006_021ec178);
    TexObj_SetRes(self->unk1C, ResMgr_FindArcType2(file, data_ov006_021ec191));
    self->unk1C->flags |= 2;
    self->unk1C->flags |= 0x80000;
    self->unk1C->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk1C, 0, 2);
}

}
