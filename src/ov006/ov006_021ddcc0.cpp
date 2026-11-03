#include "ov006/Model.h"

typedef struct ov006_ObjA021de008 {
    void *vtbl;
    u8 unk4;
    s8 unk5;
    u8 unk6;
    u8 unk7[3];
    u8 unkA;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} ov006_ObjA021de008;

typedef struct ov006_ObjB021de008 {
    void *vtbl;
    int unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA[0xa];
    int unk14;
    int unk18;
    int unk1C;
} ov006_ObjB021de008;

typedef struct ov006_ObjC021de008 {
    u32 unk0;
    u8 unk4[0x14];
    int unk18;
    u8 unk1C[0x2c];
    int unk48;
    int unk4C;
    int unk50;
} ov006_ObjC021de008;

typedef struct ov006_Unk021ddcc0 {
    void *vtbl;
    u8 unk4;
    u8 unk5[0xf];
    ov006_ObjA021de008 *unk14;
    ov006_ObjB021de008 *unk18;
    ov006_ObjC021de008 *unk1C;
    Model *unk20;
    Model *unk24;
    u8 unk28[0xc];
    Model *unk34;
} ov006_Unk021ddcc0;

extern "C" {

extern u8 Ov006Vt_021ec2bc_vtbl[];
void LoTimer_FreeModels(void *p);
void LoTimer_Init(void *p);
extern u8 Ov006Vt_021ec24c_vtbl[];
extern u8 Ov006Vt_021ec21c_vtbl[];
extern char data_ov006_021ec178[];
extern char data_ov006_021ec185[];
extern char data_ov006_021ec191[];
void LangData_LocalizePath(char *dst, const char *src);
void ov006_Unk021dcf7c_Load(ov006_ObjA021de008 *p);
void ov006_Unk021dd450_Load(ov006_ObjB021de008 *p);

static inline void ov006_Unk021ddcc0_dtor(ov006_Unk021ddcc0 *self) {
    self->vtbl = Ov006Vt_021ec2bc_vtbl;
    OV006_DELETE_OBJECT(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk1C != NULL) {
            if (self->unk1C != NULL) {
                void *p = self->unk1C;
                LoTimer_FreeModels(p);
                Heap_Free(p);
            }
            self->unk1C = NULL;
        }
        gSysState->cur = saved;
    }
    OV006_DELETE_MODEL(self->unk20);
    OV006_DELETE_MODEL(self->unk24);
    OV006_DELETE_MODEL(self->unk34);
}

ov006_Unk021ddcc0 *Ov006Vt_021ec2bc_Dtor(ov006_Unk021ddcc0 *self) {
    ov006_Unk021ddcc0_dtor(self);
    return self;
}

ov006_Unk021ddcc0 *Ov006Vt_021ec2bc_DtorDelete(ov006_Unk021ddcc0 *self) {
    ov006_Unk021ddcc0_dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_Unk021ddcc0_Load(ov006_Unk021ddcc0 *self) {
    char file[0x20];
    ov006_ObjA021de008 *a;
    ov006_ObjB021de008 *b;
    ov006_ObjC021de008 *c;
    Model *model;

    a = (ov006_ObjA021de008 *)Heap_Alloc(sizeof(ov006_ObjA021de008));
    if (a != NULL) {
        a->vtbl = Ov006Vt_021ec24c_vtbl;
        a->unk4 = 0;
        a->unk5 = -1;
        a->unk6 = 4;
        a->unkA = 0;
        a->unkC = 0;
        a->unk10 = 0;
        a->unk14 = 0;
        a->unk18 = 0;
        a->unk1C = 0;
    }
    self->unk14 = a;
    ov006_Unk021dcf7c_Load(a);
    self->unk14->unk1C = -0x2000;
    b = (ov006_ObjB021de008 *)Heap_Alloc(sizeof(ov006_ObjB021de008));
    if (b != NULL) {
        b->vtbl = Ov006Vt_021ec21c_vtbl;
        b->unk4 = 0;
        b->unk8 = 0;
        b->unk9 = 0;
        b->unk18 = 0;
        b->unk1C = 0;
    }
    self->unk18 = b;
    ov006_Unk021dd450_Load(b);
    self->unk18->unk14 = -0x2000;
    c = (ov006_ObjC021de008 *)Heap_Alloc(sizeof(ov006_ObjC021de008));
    if (c != NULL) {
        LoTimer_Init(c);
    }
    self->unk1C = c;
    c->unk48 = 0;
    c->unk4C = 0;
    c->unk50 = -0x2000;
    self->unk1C->unk18 = 2;
    self->unk1C->unk0 |= 0x400000;
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
    self->unk20 = model;
    TexObj_SetRes(self->unk20, func_02035de0(file, data_ov006_021ec191));
    self->unk20->flags |= 2;
    self->unk20->flags |= 0x80000;
    self->unk20->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk20, 0, 7);
    TexObj_SelectImage(self->unk20, 0, 8);
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
    self->unk24 = model;
    TexObj_SetRes(self->unk24, func_02035de0(file, data_ov006_021ec191));
    self->unk24->flags |= 2;
    self->unk24->flags |= 0x80000;
    self->unk24->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk24, 0, 0xffff);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec185;
        const char *path = file;
        if (path) {
            PlttRes_Init_02041218(&model->pltt);
            TexObj_Init(model, name, 0);
            STD_CopyString(model->name, path);
        }
    }
    self->unk34 = model;
    TexObj_SetRes(self->unk34, func_02035de0(file, data_ov006_021ec185));
    self->unk34->flags |= 2;
    self->unk34->flags |= 0x80000;
    self->unk34->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk34, 0, 0xffff);
    self->unk4 = 1;
}

}
