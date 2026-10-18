#include "ov006/Model.h"

typedef struct ov006_Icon021df19c {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[8];
    u8 unkE;
    u8 unkF[0xd];
    ov006_Model *unk1C;
} ov006_Icon021df19c;

typedef struct ov006_Unk021def9c {
    void *vtbl;
    u8 unk4;
    int unk8;
    u8 unkC[0x10];
    int unk1C;
    int unk20;
    int unk24;
    u8 unk28[0x5c];
    int unk84;
    ov006_Icon021df19c *unk88;
    ov006_Model *unk8C;
    ov006_Model *unk90;
} ov006_Unk021def9c;

extern "C" {

extern u8 data_ov006_021ec26c[];
extern u8 data_ov006_021ec2dc[];
extern char *data_0208cc94;
extern char *data_0208cc88;
extern char *data_0208cb7c;
extern char data_0214b105[];
void func_02048be4(void *p);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c34(ov006_Model *m, int a, void *cb, int b);
void func_ov006_021dd5dc(void);
void func_ov006_021deea4(void);

static inline void ov006_Unk021def9c_dtor(ov006_Unk021def9c *self) {
    self->vtbl = data_ov006_021ec26c;
    OV006_DELETE_OBJECT(self->unk88);
    OV006_DELETE_MODEL(self->unk8C);
    OV006_DELETE_MODEL(self->unk90);
}

ov006_Unk021def9c *func_ov006_021def9c(ov006_Unk021def9c *self) {
    ov006_Unk021def9c_dtor(self);
    return self;
}

ov006_Unk021def9c *func_ov006_021df098(ov006_Unk021def9c *self) {
    ov006_Unk021def9c_dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021df19c(ov006_Unk021def9c *self) {
    ov006_Icon021df19c *icon;
    ov006_Model *m1;
    ov006_Model *m2;
    ov006_Model *m3;
    void *res;

    icon = (ov006_Icon021df19c *)func_0203dd9c(sizeof(ov006_Icon021df19c));
    if (icon != NULL) {
        icon->vtbl = data_ov006_021ec2dc;
        icon->unk4 = 0;
        func_02048be4(icon->unk6);
        icon->unk1C = NULL;
        icon->unkE = 1;
    }
    self->unk88 = icon;
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    m1 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (m1 != NULL) {
        const char *name = data_0208cc94;
        func_02041218(m1->unk88);
        func_02041440(m1, name, 0);
    }
    icon->unk1C = m1;
    func_020417e0(m1, res);
    icon->unk1C->unk6C |= 2;
    func_02041d9c(icon->unk1C, 0, 0x1e);
    func_02041c34(icon->unk1C, 0x1e, (void *)func_ov006_021dd5dc, 0);
    func_02041d9c(icon->unk1C, 0, 0x1f);
    func_02041c34(icon->unk1C, 0x1f, (void *)func_ov006_021dd5dc, 0);
    func_02041d9c(icon->unk1C, 0, 0x24);
    func_02041c34(icon->unk1C, 0x24, (void *)func_ov006_021dd5dc, 0);
    icon->unk1C->unk6C |= 0x80000;
    icon->unk1C->unk6C = (icon->unk1C->unk6C & ~0x7c) | 0x78;
    m2 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (m2 != NULL) {
        const char *name = data_0208cb7c;
        func_02041218(m2->unk88);
        func_02041440(m2, name, 0);
        func_0201e520(m2->unk2C, data_0214b105);
    }
    self->unk8C = m2;
    func_020417e0(self->unk8C, func_02035de0(data_0214b105, data_0208cb7c));
    self->unk8C->unk6C |= 2;
    self->unk8C->unk6C |= 0x80000;
    func_02041d9c(self->unk8C, 0, 0xe);
    m3 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (m3 != NULL) {
        const char *name = data_0208cc94;
        func_02041218(m3->unk88);
        func_02041440(m3, name, 0);
    }
    self->unk90 = m3;
    func_020417e0(self->unk90, func_02035de0(data_0208cc94, data_0208cc88));
    self->unk90->unk6C |= 2;
    self->unk90->unk6C |= 0x80000;
    func_02041d9c(self->unk90, 0, 0x1e);
    func_02041c34(self->unk90, 0x1e, (void *)func_ov006_021deea4, 0);
    self->unk4 = 6;
    self->unk8 = 0;
    self->unk84 = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk1C = 0x60000;
}

}
