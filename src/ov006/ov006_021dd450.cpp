#include "ov006/Model.h"
#include <nitro/fx.h>

typedef struct ov006_Text021dd450 {
    void *vtbl;
    u8 unk4[8];
    u32 unkC;
    u8 unk10[0x18];
    int unk28;
    u8 unk2C[4];
    int unk30;
    u8 unk34[4];
    VecFx32 unk38;
    u8 unk44[0xc];
    int unk50;
    int unk54;
    int unk58;
    u8 unk5C[0x40];
} ov006_Text021dd450;

typedef struct ov006_Unk021dd450 {
    u8 unk0[0x18];
    ov006_Text021dd450 *unk18;
    ov006_Model *unk1C;
} ov006_Unk021dd450;

extern "C" {

extern u8 data_ov000_021cac0c[];
extern const char data_ov006_021ec09a[];
extern const char data_ov006_021ec0a0[];
extern char data_ov006_021ec178[];
extern char data_ov006_021ec191[];
void func_0206e900(char *dst, const char *src);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

static inline void ov006_Vec_Set021dd450(VecFx32 *v, fx32 x, fx32 y, fx32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov006_021dd450(ov006_Unk021dd450 *self) {
    char file[0x20];
    ov006_Text021dd450 *text;
    ov006_Model *model;

    text = (ov006_Text021dd450 *)func_0203dd9c(sizeof(ov006_Text021dd450));
    if (text != NULL) {
        text->vtbl = data_ov000_021cac0c;
        VCALL(text, 14);
    }
    self->unk18 = text;
    text->unkC |= 8;
    self->unk18->unkC &= ~0x20;
    self->unk18->unk50 = 99;
    self->unk18->unk54 = 3;
    ov006_Vec_Set021dd450(&self->unk18->unk38, 0, 0, 0);
    self->unk18->unk28 = 2;
    self->unk18->unk30 = 0;
    func_ov000_0215fdfc(self->unk18, 1, data_ov006_021ec09a);
    func_ov000_0215fdfc(self->unk18, 2, data_ov006_021ec0a0);
    self->unk18->unk58 = 0;
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        func_02041218(model->unk88);
        func_02041440(model, NULL, 0);
    }
    self->unk1C = model;
    func_0206e900(file, data_ov006_021ec178);
    func_020417e0(self->unk1C, func_02035de0(file, data_ov006_021ec191));
    self->unk1C->unk6C |= 2;
    self->unk1C->unk6C |= 0x80000;
    self->unk1C->unk150 = -0x2000;
    func_02041d9c(self->unk1C, 0, 2);
}

}
