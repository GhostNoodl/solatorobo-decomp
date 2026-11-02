#include "ov006/Model.h"
#include "Main/Gfx/FieldMsg.h"

typedef struct ov006_Sub021e16b0 {
    void *vtbl;
    u8 unk4;
    int unk8[6];
    int type;
    Model *model;
    TextWin *txt;
} ov006_Sub021e16b0;

typedef struct ov006_Lbl021e16b0 {
    void *vtbl;
    int unk4;
    u16 unk8;
    u8 unkA[2];
    void *unkC;
    u8 unk10;
    u8 unk11[3];
    void *unk14;
    u8 unk18[0x48];
    char unk60[0x20];
    char unk80[0x20];
    u8 unkA0;
    u8 unkA1[3];
    u16 unkA4;
    Model *unkA8;
    u8 unkAC[4];
    int unkB0[6];
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    u8 unkE8;
} ov006_Lbl021e16b0;

typedef struct ov006_Unk021e16b0 {
    u8 unk0[0x24];
    ov006_Sub021e16b0 *unk24;
    Model *unk28;
    ov006_Lbl021e16b0 *unk2C;
} ov006_Unk021e16b0;

typedef struct ov006_Anim021eb824 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} ov006_Anim021eb824;

extern "C" {

extern u8 data_ov006_021ec22c[];
extern char data_ov006_021ec1a9[];
extern char data_ov006_021ec864[];
extern char data_ov006_021ec1b5[];
extern ov006_Anim021eb824 data_ov006_021eb824[];
extern u8 data_ov006_021ec2fc[];
extern u8 data_ov006_021ec25c[];
extern u8 data_0208b318[];
void TextWin_InitLines(TextWin *win, u32 n);

static inline Model *ov006_NewModel021e16b0(void) {
    Model *model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec1a9;
        if (name) {
            func_02041218(&model->pltt);
            func_02041440(model, name, 0);
            STD_CopyString(model->name, data_ov006_021ec864);
        }
    }
    return model;
}

static inline void ov006_Sub021e16b0_Reset(ov006_Sub021e16b0 *s, const char *str) {
    TextWin *t;
    const char *p = str;
    if (s->txt == NULL) {
        return;
    }
    s->txt->unk_vf08();
    s->txt->font = 7;
    s->txt->unk_2c = 4;
    s->txt->unk_34 = 0;
    t = s->txt;
    t->str = (u32)p;
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, (s8)t->unk_37 != 0);
    data_02097ce0->unk_004 = t->font;
    TextWin_InitLines(s->txt, 0x10);
    s->txt->flags |= 4;
}

static inline void ov006_Sub021e16b0_Init(ov006_Sub021e16b0 *s) {
    TextWin *t;
    if (s->type != 2) {
        s->model = ov006_NewModel021e16b0();
        func_020417e0(s->model, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
        s->model->flags |= 2;
        s->model->flags &= ~0x80000;
        s->model->flags |= 0x400000;
        func_02041d9c(s->model, 2, data_ov006_021eb824[s->type].unk0);
    }
    t = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (t != NULL) {
        *(const u32 **)t = data_0208ba70;
        func_0204c7d0(t);
    }
    s->txt = t;
    ov006_Sub021e16b0_Reset(s, data_ov006_021ec1b5);
}

static inline void ov006_Lbl_SetMove(ov006_Lbl021e16b0 *l, int x, int y, int z, int s, int d) {
    l->unkC8 = x;
    l->unkCC = y;
    l->unkD0 = z;
    l->unkD4 = s;
    l->unkD8 = d;
}

void func_ov006_021e16b0(ov006_Unk021e16b0 *self) {
    int zero = 0;
    ov006_Sub021e16b0 *s;
    ov006_Lbl021e16b0 *l;
    Model *model;
    s = (ov006_Sub021e16b0 *)Heap_Alloc(0x2c);
    if (s != NULL) {
        s->vtbl = data_ov006_021ec22c;
        s->unk4 = zero;
        s->unk8[0] = zero;
        s->unk8[1] = zero;
        s->unk8[2] = zero;
        s->unk8[3] = zero;
        s->unk8[4] = zero;
        s->unk8[5] = zero;
        s->type = zero;
        s->model = NULL;
        s->txt = NULL;
    }
    self->unk24 = s;
    s->type = zero;
    ov006_Sub021e16b0_Init(self->unk24);
    ov006_Sub021e16b0_Reset(self->unk24, data_ov006_021ec1b5);
    l = (ov006_Lbl021e16b0 *)Heap_Alloc(0xec);
    if (l != NULL) {
        l->vtbl = data_ov006_021ec2fc;
        l->unkC = data_ov006_021ec25c;
        l->unk14 = data_0208b318;
        VCALL(&l->unk14, 08);
        l->unk10 = zero;
        VCALL(&l->unk14, 08);
        MI_CpuFill8(l->unk60, zero, 0x20);
        MI_CpuFill8(l->unk80, zero, 0x20);
        l->unkA0 = zero;
        l->unk4 = 2;
        l->unk8 = zero;
        VCALL(&l->unk14, 08);
        l->unkA4 = 0xffff;
        l->unkA8 = NULL;
        l->unkB0[0] = zero;
        l->unkB0[1] = zero;
        l->unkB0[2] = zero;
        l->unkB0[3] = zero;
        l->unkB0[4] = zero;
        l->unkB0[5] = zero;
        l->unkC8 = 0x1000;
        l->unkCC = zero;
        l->unkD0 = zero;
        l->unkD4 = 0x20000;
        l->unkD8 = 0xc000;
        l->unkDC = zero;
        l->unkE0 = zero;
        l->unkE4 = zero;
        l->unkE8 = zero;
    }
    self->unk2C = l;
    l->unkE0 = 2;
    ov006_Lbl_SetMove(self->unk2C, zero, zero, zero, zero, zero);
    self->unk28 = ov006_NewModel021e16b0();
    func_020417e0(self->unk28, func_02035de0(data_ov006_021ec864, data_ov006_021ec1a9));
    self->unk28->flags |= 2;
    self->unk28->flags |= 0x80000;
    self->unk28->flags |= 0x400000;
    func_02041d9c(self->unk28, 2, 8);
}

}
