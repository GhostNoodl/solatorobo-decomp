#ifndef OV006_CAPTION_H
#define OV006_CAPTION_H

#include "ov006/Model.h"
#include "ov006/Anim.h"

typedef struct ov006_CaptionEntry {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} ov006_CaptionEntry;

/* 0x2c-byte object (vtable data_ov006_021ec22c): a model plus a text anim. */
typedef struct ov006_Caption {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    ov006_Model *unk24;
    ov006_Anim *unk28;
} ov006_Caption;

#ifdef __cplusplus
extern "C" {
#endif

extern char data_ov006_021ec1a9[];
extern char data_ov006_021ec1b5[];
extern char data_ov006_021ec864[];
extern const ov006_CaptionEntry data_ov006_021eb824[];
extern const u32 data_0208ba70[];
extern u8 data_ov006_021ec22c[];
void func_0204c7d0(ov006_Anim *anim);

#ifdef __cplusplus
}
#endif

static inline ov006_Anim *ov006_Anim_New(void) {
    ov006_Anim *anim = (ov006_Anim *)func_0203dd9c(0xb8);
    if (anim != NULL) {
        *(const u32 **)anim = data_0208ba70;
        func_0204c7d0(anim);
    }
    return anim;
}

static inline ov006_Caption *ov006_Caption_New(void) {
    ov006_Caption *c = (ov006_Caption *)func_0203dd9c(sizeof(ov006_Caption));
    if (c != NULL) {
        c->vtbl = data_ov006_021ec22c;
        c->unk4 = 0;
        c->unk8 = 0;
        c->unkC = 0;
        c->unk10 = 0;
        c->unk14 = 0;
        c->unk18 = 0;
        c->unk1C = 0;
        c->unk20 = 0;
        c->unk24 = NULL;
        c->unk28 = NULL;
    }
    return c;
}

static inline void ov006_Caption_Init(ov006_Caption *self) {
    ov006_Model *model;
    const char *text;

    if (self->unk20 != 2) {
        model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
        if (model != NULL) {
            const char *name = data_ov006_021ec1a9;
            if (name) {
                func_02041218(model->unk88);
                func_02041440(model, name, 0);
                func_0201e520(model->unk2C, data_ov006_021ec864);
            }
        }
        self->unk24 = model;
        func_020417e0(self->unk24, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
        self->unk24->unk6C |= 2;
        self->unk24->unk6C &= ~0x80000;
        self->unk24->unk6C |= 0x400000;
        func_02041d9c(self->unk24, 2, data_ov006_021eb824[self->unk20].unk0);
    }
    self->unk28 = ov006_Anim_New();
    text = data_ov006_021ec1b5;
    ov006_AnimHolder_Play((ov006_AnimHolder *)self, (int)text, 4);
}

#endif
