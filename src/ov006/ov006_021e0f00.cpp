#include "nitro/fx.h"
#include "ov006/Caption.h"
#include "ov006/Gauge.h"

extern "C" {

BOOL Model_IsReady(void *a, int b);

void ov006_Gauge_Load(ov006_Gauge *self) {
    Model *model;
    const char *text;

    self->text = ov006_TextWin_New();
    text = data_ov006_021ec1b5;
    if (self->text != NULL) {
        self->text->unk_vf08();
        self->text->font = 3;
        self->text->unk_2c = 4;
        self->text->unk_34 = 0;
        ov006_TextWin_Start(self->text, (int)text);
        TextWin_InitLines(self->text, 8);
        self->text->flags |= 4;
    }
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
    TexObj_SetRes(self->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->model->flags |= 2;
    self->model->flags &= ~0x80000;
    self->model->flags |= 0x400000;
    TexObj_SelectImage(self->model, 2, 2);
    TexObj_SelectImage(self->model, 2, 3);
    TexObj_SelectImage(self->model, 2, 4);
    TexObj_SelectImage(self->model, 2, 5);
    TexObj_SelectImage(self->model, 2, 6);
    TexObj_SelectImage(self->model, 2, 7);
}

static inline s32 ov006_ApproachFx(s32 cur, s32 target, fx32 rate) {
    s32 d = target - cur;
    if ((d < 0 ? -d : d) > 0x29) {
        return cur + FX_Mul(d, rate);
    }
    return cur;
}

void ov006_Gauge_Update(ov006_Gauge *self) {
    if (!self->unk4) {
        if (self->model == NULL) {
            return;
        }
        if (!Model_IsReady(self->model, 0xffff)) {
            return;
        }
        self->unk4 = 1;
    }
    if (self->unk5) {
        self->unk8 = ov006_ApproachFx(self->unk8, self->unkC, 0x19a);
    } else {
        self->unk8 = self->unkC;
    }
    self->text->unk_vf8c();
}

}
