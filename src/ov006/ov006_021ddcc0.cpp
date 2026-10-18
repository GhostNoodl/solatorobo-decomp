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
    ov006_Model *unk20;
    ov006_Model *unk24;
    u8 unk28[0xc];
    ov006_Model *unk34;
} ov006_Unk021ddcc0;

extern "C" {

extern u8 data_ov006_021ec2bc[];
void func_ov000_0216e5d0(void *p);
void func_ov000_0216e574(void *p);
extern u8 data_ov006_021ec24c[];
extern u8 data_ov006_021ec21c[];
extern char data_ov006_021ec178[];
extern char data_ov006_021ec185[];
extern char data_ov006_021ec191[];
void func_0206e900(char *dst, const char *src);
void func_ov006_021dcf7c(ov006_ObjA021de008 *p);
void func_ov006_021dd450(ov006_ObjB021de008 *p);

static inline void ov006_Unk021ddcc0_dtor(ov006_Unk021ddcc0 *self) {
    self->vtbl = data_ov006_021ec2bc;
    OV006_DELETE_OBJECT(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
    {
        void *saved = data_02097dd0->current;
        data_02097dd0->current = data_02097dd0->unk8;
        if (self->unk1C != NULL) {
            if (self->unk1C != NULL) {
                void *p = self->unk1C;
                func_ov000_0216e5d0(p);
                func_0203de1c(p);
            }
            self->unk1C = NULL;
        }
        data_02097dd0->current = saved;
    }
    OV006_DELETE_MODEL(self->unk20);
    OV006_DELETE_MODEL(self->unk24);
    OV006_DELETE_MODEL(self->unk34);
}

ov006_Unk021ddcc0 *func_ov006_021ddcc0(ov006_Unk021ddcc0 *self) {
    ov006_Unk021ddcc0_dtor(self);
    return self;
}

ov006_Unk021ddcc0 *func_ov006_021dde60(ov006_Unk021ddcc0 *self) {
    ov006_Unk021ddcc0_dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021de008(ov006_Unk021ddcc0 *self) {
    char file[0x20];
    ov006_ObjA021de008 *a;
    ov006_ObjB021de008 *b;
    ov006_ObjC021de008 *c;
    ov006_Model *model;

    a = (ov006_ObjA021de008 *)func_0203dd9c(sizeof(ov006_ObjA021de008));
    if (a != NULL) {
        a->vtbl = data_ov006_021ec24c;
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
    func_ov006_021dcf7c(a);
    self->unk14->unk1C = -0x2000;
    b = (ov006_ObjB021de008 *)func_0203dd9c(sizeof(ov006_ObjB021de008));
    if (b != NULL) {
        b->vtbl = data_ov006_021ec21c;
        b->unk4 = 0;
        b->unk8 = 0;
        b->unk9 = 0;
        b->unk18 = 0;
        b->unk1C = 0;
    }
    self->unk18 = b;
    func_ov006_021dd450(b);
    self->unk18->unk14 = -0x2000;
    c = (ov006_ObjC021de008 *)func_0203dd9c(sizeof(ov006_ObjC021de008));
    if (c != NULL) {
        func_ov000_0216e574(c);
    }
    self->unk1C = c;
    c->unk48 = 0;
    c->unk4C = 0;
    c->unk50 = -0x2000;
    self->unk1C->unk18 = 2;
    self->unk1C->unk0 |= 0x400000;
    func_0206e900(file, data_ov006_021ec178);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec191;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unk20 = model;
    func_020417e0(self->unk20, func_02035de0(file, data_ov006_021ec191));
    self->unk20->unk6C |= 2;
    self->unk20->unk6C |= 0x80000;
    self->unk20->unk150 = -0x2000;
    func_02041d9c(self->unk20, 0, 7);
    func_02041d9c(self->unk20, 0, 8);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec191;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unk24 = model;
    func_020417e0(self->unk24, func_02035de0(file, data_ov006_021ec191));
    self->unk24->unk6C |= 2;
    self->unk24->unk6C |= 0x80000;
    self->unk24->unk150 = -0x2000;
    func_02041d9c(self->unk24, 0, 0xffff);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        const char *name = data_ov006_021ec185;
        const char *path = file;
        if (path) {
            func_02041218(model->unk88);
            func_02041440(model, name, 0);
            STD_CopyString(model->unk2C, path);
        }
    }
    self->unk34 = model;
    func_020417e0(self->unk34, func_02035de0(file, data_ov006_021ec185));
    self->unk34->unk6C |= 2;
    self->unk34->unk6C |= 0x80000;
    self->unk34->unk150 = -0x2000;
    func_02041d9c(self->unk34, 0, 0xffff);
    self->unk4 = 1;
}

}
