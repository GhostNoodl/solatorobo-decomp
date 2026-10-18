#include "ov006/Model.h"
#include <nitro/mi.h>

typedef struct ov006_Icon021dfce8 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[8];
    u8 unkE;
    u8 unkF[0xd];
    ov006_Model *unk1C;
} ov006_Icon021dfce8;

typedef struct ov006_Vec021dfce8 {
    s32 x;
    s32 y;
    s32 z;
} ov006_Vec021dfce8;

typedef struct ov006_Item021dfce8 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    ov006_Vec021dfce8 unk8;
    ov006_Model *unk14;
    ov006_Icon021dfce8 *unk18;
} ov006_Item021dfce8;

typedef struct ov006_Panel021dfce8 {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    ov006_Vec021dfce8 unk10;
    int unk1C;
    int unk20;
    int unk24;
    u8 unk28[0x50];
    u8 unk78[0xa];
    u8 unk82;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
} ov006_Panel021dfce8;

typedef struct ov006_Unk021dfce8 {
    void *vtbl;
    u16 unk4;
    int unk8;
    int unkC;
    u8 unk10[0xc];
    ov006_Item021dfce8 *unk1C;
    ov006_Panel021dfce8 *unk20;
} ov006_Unk021dfce8;

extern "C" {

extern u8 data_ov006_021ec27c[];
extern u8 data_ov006_021ec2dc[];
extern u8 data_ov006_021ec26c[];
extern char *data_0208cc94;
extern char *data_0208cc88;
extern char *data_0208cb7c;
extern char data_0214b105[];
void func_02048be4(void *p);
void *func_02035d5c(const char *a);
void *func_02034d88(void *a, const char *b);
void func_02041c34(ov006_Model *m, int a, void *cb, int b);
void func_02016e28(void *dst, int value, u32 size);
void func_ov006_021dd5dc(void);
void func_ov006_021df19c(ov006_Panel021dfce8 *p);

static inline void ov006_Vec_Set021dfce8(ov006_Vec021dfce8 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov006_021dfce8(ov006_Unk021dfce8 *self) {
    ov006_Item021dfce8 *item;
    ov006_Icon021dfce8 *icon;
    ov006_Panel021dfce8 *panel;
    void *res;
    ov006_Model *m1;

    item = (ov006_Item021dfce8 *)func_0203dd9c(sizeof(ov006_Item021dfce8));
    if (item != NULL) {
        item->vtbl = data_ov006_021ec27c;
        item->unk4 = 0;
        item->unk5 = 0;
        item->unk8.x = 0;
        item->unk8.y = 0;
        item->unk8.z = 0;
        item->unk14 = NULL;
        item->unk18 = NULL;
    }
    self->unk1C = item;
    icon = (ov006_Icon021dfce8 *)func_0203dd9c(sizeof(ov006_Icon021dfce8));
    if (icon != NULL) {
        icon->vtbl = data_ov006_021ec2dc;
        icon->unk4 = 0;
        func_02048be4(icon->unk6);
        icon->unk1C = NULL;
        icon->unkE = 1;
    }
    item->unk18 = icon;
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
    m1 = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (m1 != NULL) {
        const char *name = data_0208cb7c;
        func_02041218(m1->unk88);
        func_02041440(m1, name, 0);
        func_0201e520(m1->unk2C, data_0214b105);
    }
    item->unk14 = m1;
    func_020417e0(item->unk14, func_02035de0(data_0214b105, data_0208cb7c));
    item->unk14->unk6C |= 2;
    item->unk14->unk6C |= 0x80000;
    func_02041d9c(item->unk14, 0, 0xd);
    func_02041d9c(item->unk14, 0, 0xf);
    self->unk1C->unk8.z = -0x1ccd;
    ov006_Vec_Set021dfce8(&self->unk1C->unk8, 0x100000, 0xc0000, self->unk1C->unk8.z);
    panel = (ov006_Panel021dfce8 *)func_0203dd9c(sizeof(ov006_Panel021dfce8));
    if (panel != NULL) {
        panel->vtbl = data_ov006_021ec26c;
        panel->unk4 = 0;
        panel->unk8 = 0;
        panel->unkC = 0;
        panel->unk10.x = 0;
        panel->unk10.y = 0;
        panel->unk10.z = 0;
        panel->unk1C = 0;
        panel->unk20 = 0;
        panel->unk24 = 0;
        MI_CpuClear32(panel->unk28, sizeof(panel->unk28));
        func_02016e28(panel->unk78, 0, sizeof(panel->unk78));
        panel->unk82 = 0;
        panel->unk84 = 0;
        panel->unk88 = 0;
        panel->unk8C = 0;
        panel->unk90 = 0;
    }
    self->unk20 = panel;
    func_ov006_021df19c(panel);
    ov006_Vec_Set021dfce8(&self->unk20->unk10, 0x41000, 0x4e000, self->unk20->unk10.z);
    self->unk20->unk10.z = -0x1ccd;
    self->unk4 = 6;
    self->unk8 = 0;
    self->unkC = 0x1000;
}

}
