#include "nitro/fx.h"
#include "ov006/Caption.h"

typedef struct ov006_Unk021e0f00 {
    u8 unk0[0x1c];
    Model *unk1C;
    TextWin *unk20;
} ov006_Unk021e0f00;

typedef struct ov006_Fader021e10d0 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[2];
    s32 unk8;
    s32 unkC;
    u8 unk10[0xc];
    void *unk1C;
    void *unk20;
} ov006_Fader021e10d0;

extern "C" {

BOOL func_02054f10(void *a, int b);

void func_ov006_021e0f00(ov006_Unk021e0f00 *self) {
    Model *model;
    const char *text;

    self->unk20 = ov006_TextWin_New();
    text = data_ov006_021ec1b5;
    if (self->unk20 != NULL) {
        self->unk20->unk_vf08();
        self->unk20->font = 3;
        self->unk20->unk_2c = 4;
        self->unk20->unk_34 = 0;
        ov006_TextWin_Start(self->unk20, (int)text);
        TextWin_InitLines(self->unk20, 8);
        self->unk20->flags |= 4;
    }
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(&model->pltt);
            func_02041440(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    self->unk1C = model;
    func_020417e0(self->unk1C, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk1C->flags |= 2;
    self->unk1C->flags &= ~0x80000;
    self->unk1C->flags |= 0x400000;
    func_02041d9c(self->unk1C, 2, 2);
    func_02041d9c(self->unk1C, 2, 3);
    func_02041d9c(self->unk1C, 2, 4);
    func_02041d9c(self->unk1C, 2, 5);
    func_02041d9c(self->unk1C, 2, 6);
    func_02041d9c(self->unk1C, 2, 7);
}

static inline s32 ov006_ApproachFx(s32 cur, s32 target, fx32 rate) {
    s32 d = target - cur;
    if ((d < 0 ? -d : d) > 0x29) {
        return cur + FX_Mul(d, rate);
    }
    return cur;
}

void func_ov006_021e10d0(ov006_Fader021e10d0 *self) {
    if (!self->unk4) {
        if (self->unk1C == NULL) {
            return;
        }
        if (!func_02054f10(self->unk1C, 0xffff)) {
            return;
        }
        self->unk4 = 1;
    }
    if (self->unk5) {
        self->unk8 = ov006_ApproachFx(self->unk8, self->unkC, 0x19a);
    } else {
        self->unk8 = self->unkC;
    }
    VCALL(self->unk20, 8c);
}

}
