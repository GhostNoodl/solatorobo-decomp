#include "ov006/Caption.h"
#include "ov006/Label.h"
#include "Main/Gfx/FieldMsg.h"

typedef struct ov006_Unk021e16b0 {
    u8 unk0[0x24];
    ov006_Caption *unk24;
    Model *unk28;
    ov006_Label *unk2C;
} ov006_Unk021e16b0;

extern "C" {

extern u8 data_ov006_021ec2fc[];
extern u8 data_ov006_021ec25c[];
extern u8 data_0208b318[];
void TextWin_InitLines(TextWin *win, u32 n);

static inline Model *ov006_NewModel021e16b0(void) {
    Model *model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    return model;
}

static inline void ov006_Caption_ResetText(ov006_Caption *s, const char *str) {
    TextWin *t;
    const char *p = str;
    if (s->label == NULL) {
        return;
    }
    s->label->unk_vf08();
    s->label->font = 7;
    s->label->unk_2c = 4;
    s->label->unk_34 = 0;
    t = s->label;
    t->str = (u32)p;
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, (s8)t->unk_37 != 0);
    data_02097ce0->unk_004 = t->font;
    TextWin_InitLines(s->label, 0x10);
    s->label->flags |= 4;
}

static inline void ov006_Caption_Build(ov006_Caption *s) {
    TextWin *t;
    if (s->kind != 2) {
        s->model = ov006_NewModel021e16b0();
        TexObj_SetRes(s->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
        s->model->flags |= 2;
        s->model->flags &= ~0x80000;
        s->model->flags |= 0x400000;
        TexObj_SelectImage(s->model, 2, data_ov006_021eb824[s->kind].part);
    }
    t = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (t != NULL) {
        *(const u32 **)t = data_0208ba70;
        TextWin_Init(t);
    }
    s->label = t;
    ov006_Caption_ResetText(s, data_ov006_021ec1b5);
}

static inline void ov006_Lbl_SetMove(ov006_Label *l, int x, int y, int z, int s, int d) {
    l->dir.x = x;
    l->dir.y = y;
    l->dir.z = z;
    l->speed = s;
    l->unkD8 = d;
}

void ov006_Unk021e16b0_Load(ov006_Unk021e16b0 *self) {
    int zero = 0;
    ov006_Caption *s;
    ov006_Label *l;
    Model *model;
    s = (ov006_Caption *)Heap_Alloc(0x2c);
    if (s != NULL) {
        s->vtbl = data_ov006_021ec22c;
        s->visible = zero;
        s->x = zero;
        s->y = zero;
        s->textX = zero;
        s->textY = zero;
        s->ofsX = zero;
        s->ofsY = zero;
        s->kind = zero;
        s->model = NULL;
        s->label = NULL;
    }
    self->unk24 = s;
    s->kind = zero;
    ov006_Caption_Build(self->unk24);
    ov006_Caption_ResetText(self->unk24, data_ov006_021ec1b5);
    l = (ov006_Label *)Heap_Alloc(0xec);
    if (l != NULL) {
        *(void **)l = data_ov006_021ec2fc;
        *(void **)&l->loader = data_ov006_021ec25c;
        *(void **)&l->loader.res = data_0208b318;
        l->loader.res.vfunc_08();
        l->loader.step = zero;
        l->loader.res.vfunc_08();
        MI_CpuFill8(l->loader.arcName, zero, 0x20);
        MI_CpuFill8(l->loader.name, zero, 0x20);
        l->loader.request = zero;
        l->state = 2;
        l->timer = zero;
        l->loader.res.vfunc_08();
        l->partId = 0xffff;
        l->model = NULL;
        l->origin.x = zero;
        l->origin.y = zero;
        l->origin.z = zero;
        l->pos.x = zero;
        l->pos.y = zero;
        l->pos.z = zero;
        l->dir.x = 0x1000;
        l->dir.y = zero;
        l->dir.z = zero;
        l->speed = 0x20000;
        l->unkD8 = 0xc000;
        l->alpha = zero;
        l->unkE0 = zero;
        l->unkE4 = zero;
        l->unkE8 = zero;
    }
    self->unk2C = l;
    l->unkE0 = 2;
    ov006_Lbl_SetMove(self->unk2C, zero, zero, zero, zero, zero);
    self->unk28 = ov006_NewModel021e16b0();
    TexObj_SetRes(self->unk28, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk28->flags |= 2;
    self->unk28->flags |= 0x80000;
    self->unk28->flags |= 0x400000;
    TexObj_SelectImage(self->unk28, 2, 8);
}

}
