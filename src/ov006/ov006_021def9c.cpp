#include "ov006/Model.h"
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

typedef struct ov006_Icon021df19c {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[8];
    u8 unkE;
    u8 unkF[0xd];
    Model *unk1C;
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
    Model *unk8C;
    Model *unk90;
} ov006_Unk021def9c;

extern "C" {

extern u8 data_ov006_021ec26c[];
extern u8 data_ov006_021ec2dc[];
extern char data_0214b105[];
void PlayTime_Clear(void *p);
void TexObj_SetOamFunc(Model *m, int a, void *cb, int b);
void *ov006_OamCb_TimeDigits(void *self, u16 *flag, void *oam, u16 *count);
void *ov006_Counter_OamCb(void *self, const u16 *mode, void *oam, u16 *count);

static inline void ov006_Unk021def9c_dtor(ov006_Unk021def9c *self) {
    self->vtbl = data_ov006_021ec26c;
    OV006_DELETE_OBJECT(self->unk88);
    OV006_DELETE_MODEL(self->unk8C);
    OV006_DELETE_MODEL(self->unk90);
}

ov006_Unk021def9c *Ov006Vt_021ec26c_Dtor(ov006_Unk021def9c *self) {
    ov006_Unk021def9c_dtor(self);
    return self;
}

ov006_Unk021def9c *Ov006Vt_021ec26c_DtorDelete(ov006_Unk021def9c *self) {
    ov006_Unk021def9c_dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_Unk021def9c_Load(ov006_Unk021def9c *self) {
    ov006_Icon021df19c *icon;
    Model *m1;
    Model *m2;
    Model *m3;
    void *res;

    icon = (ov006_Icon021df19c *)Heap_Alloc(sizeof(ov006_Icon021df19c));
    if (icon != NULL) {
        icon->vtbl = data_ov006_021ec2dc;
        icon->unk4 = 0;
        PlayTime_Clear(icon->unk6);
        icon->unk1C = NULL;
        icon->unkE = 1;
    }
    self->unk88 = icon;
    res = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
    m1 = (Model *)Heap_Alloc(sizeof(Model));
    if (m1 != NULL) {
        const char *name = data_0208cc94;
        PlttRes_Init_02041218(&m1->pltt);
        TexObj_Init(m1, name, 0);
    }
    icon->unk1C = m1;
    TexObj_SetRes(m1, res);
    icon->unk1C->flags |= 2;
    TexObj_SelectImage(icon->unk1C, 0, 0x1e);
    TexObj_SetOamFunc(icon->unk1C, 0x1e, (void *)ov006_OamCb_TimeDigits, 0);
    TexObj_SelectImage(icon->unk1C, 0, 0x1f);
    TexObj_SetOamFunc(icon->unk1C, 0x1f, (void *)ov006_OamCb_TimeDigits, 0);
    TexObj_SelectImage(icon->unk1C, 0, 0x24);
    TexObj_SetOamFunc(icon->unk1C, 0x24, (void *)ov006_OamCb_TimeDigits, 0);
    icon->unk1C->flags |= 0x80000;
    icon->unk1C->flags = (icon->unk1C->flags & ~0x7c) | 0x78;
    m2 = (Model *)Heap_Alloc(sizeof(Model));
    if (m2 != NULL) {
        const char *name = data_0208cb7c;
        PlttRes_Init_02041218(&m2->pltt);
        TexObj_Init(m2, name, 0);
        STD_CopyString(m2->name, data_0214b105);
    }
    self->unk8C = m2;
    TexObj_SetRes(self->unk8C, func_02035de0(data_0214b105, data_0208cb7c));
    self->unk8C->flags |= 2;
    self->unk8C->flags |= 0x80000;
    TexObj_SelectImage(self->unk8C, 0, 0xe);
    m3 = (Model *)Heap_Alloc(sizeof(Model));
    if (m3 != NULL) {
        const char *name = data_0208cc94;
        PlttRes_Init_02041218(&m3->pltt);
        TexObj_Init(m3, name, 0);
    }
    self->unk90 = m3;
    TexObj_SetRes(self->unk90, func_02035de0(data_0208cc94, data_0208cc88));
    self->unk90->flags |= 2;
    self->unk90->flags |= 0x80000;
    TexObj_SelectImage(self->unk90, 0, 0x1e);
    TexObj_SetOamFunc(self->unk90, 0x1e, (void *)ov006_Counter_OamCb, 0);
    self->unk4 = 6;
    self->unk8 = 0;
    self->unk84 = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk1C = 0x60000;
}

}
