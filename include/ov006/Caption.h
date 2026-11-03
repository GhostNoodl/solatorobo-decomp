#ifndef OV006_CAPTION_H
#define OV006_CAPTION_H

#include "ov006/Model.h"
#include "ov006/Anim.h"

typedef struct ov006_CaptionEntry {
    u16 part;
    u16 width;
    u16 height;
} ov006_CaptionEntry;

/* 0x2c-byte object (vtable ov006_Caption_vtbl): a model plus a text anim. */
typedef struct ov006_Caption {
    void *vtbl;
    u8 visible;
    int x;
    int y;
    int textX;
    int textY;
    int ofsX;
    int ofsY;
    int kind;
    Model *model;
    TextWin *label;
} ov006_Caption;

/* A model with a title caption and up to three captions (vtable Ov006Vt_021ec29c_vtbl, 0x24 bytes;
   ctor Ov006Vt_021ec29c_Ctor, built by ov006_CaptionPanel_Load; ov006_CaptionSet_SetText fills
   captions[idx], ov006_CaptionPanel_PlayText plays the title's text). */
typedef struct ov006_CaptionPanel {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    Model *model;
    ov006_Caption *title;
    ov006_Caption *captions[3];
} ov006_CaptionPanel;

#ifdef __cplusplus
extern "C" {
#endif

extern char data_ov006_021ec1a9[];
extern char data_ov006_021ec1b5[];
extern char data_ov006_021ec864[];
extern const ov006_CaptionEntry ov006_CaptionTable[];
extern const u32 TextWin_vtbl[];
extern u8 ov006_Caption_vtbl[];
extern u8 Ov006Vt_021ec29c_vtbl[];

ov006_CaptionPanel *Ov006Vt_021ec29c_Ctor(ov006_CaptionPanel *self);
void ov006_CaptionPanel_Load(ov006_CaptionPanel *self);
void ov006_CaptionSet_SetText(ov006_CaptionPanel *self, const char *text, int idx);

#ifdef __cplusplus
}
#endif

static inline TextWin *ov006_TextWin_New(void) {
    TextWin *anim = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (anim != NULL) {
        *(const u32 **)anim = TextWin_vtbl;
        TextWin_Init(anim);
    }
    return anim;
}

static inline ov006_Caption *ov006_Caption_New(void) {
    ov006_Caption *c = (ov006_Caption *)Heap_Alloc(sizeof(ov006_Caption));
    if (c != NULL) {
        c->vtbl = ov006_Caption_vtbl;
        c->visible = 0;
        c->x = 0;
        c->y = 0;
        c->textX = 0;
        c->textY = 0;
        c->ofsX = 0;
        c->ofsY = 0;
        c->kind = 0;
        c->model = NULL;
        c->label = NULL;
    }
    return c;
}

static inline void ov006_Caption_Init(ov006_Caption *self) {
    Model *model;
    const char *text;

    if (self->kind != 2) {
        model = (Model *)Heap_Alloc(sizeof(Model));
        if (model != NULL) {
            const char *name = data_ov006_021ec1a9;
            if (name) {
                PlttRes_Init_02041218(&model->pltt);
                TexObj_Init(model, name, 0);
                STD_CopyString(model->name, data_ov006_021ec864);
            }
        }
        self->model = model;
        TexObj_SetRes(self->model, ResMgr_FindArcType2(data_ov006_021ec864, data_ov006_021ec1a9));
        self->model->flags |= 2;
        self->model->flags &= ~0x80000;
        self->model->flags |= 0x400000;
        TexObj_SelectImage(self->model, 2, ov006_CaptionTable[self->kind].part);
    }
    self->label = ov006_TextWin_New();
    text = data_ov006_021ec1b5;
    ov006_TextHolder_Play((ov006_TextHolder *)self, (int)text, 4);
}

#endif
