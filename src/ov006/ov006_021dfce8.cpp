#include "ov006/Model.h"
#include <nitro/mi.h>
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"

typedef struct ov006_Icon021dfce8 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    u8 unk6[8];
    u8 unkE;
    u8 unkF[0xd];
    Model *unk1C;
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
    Model *unk14;
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

extern u8 Ov006Vt_021ec27c_vtbl[];
extern u8 Ov006Vt_021ec2dc_vtbl[];
extern u8 Ov006Vt_021ec26c_vtbl[];
extern char data_0214b105[];
void PlayTime_Clear(void *p);
void TexObj_SetOamFunc(Model *m, int a, void *cb, int b);
void *ov006_OamCb_TimeDigits(void *self, u16 *flag, void *oam, u16 *count);
void ov006_Unk021def9c_Load(ov006_Panel021dfce8 *p);

static inline void ov006_Vec_Set021dfce8(ov006_Vec021dfce8 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void ov006_Unk021dfce8_Load(ov006_Unk021dfce8 *self) {
    ov006_Item021dfce8 *item;
    ov006_Icon021dfce8 *icon;
    ov006_Panel021dfce8 *panel;
    void *res;
    Model *m1;

    item = (ov006_Item021dfce8 *)Heap_Alloc(sizeof(ov006_Item021dfce8));
    if (item != NULL) {
        item->vtbl = Ov006Vt_021ec27c_vtbl;
        item->unk4 = 0;
        item->unk5 = 0;
        item->unk8.x = 0;
        item->unk8.y = 0;
        item->unk8.z = 0;
        item->unk14 = NULL;
        item->unk18 = NULL;
    }
    self->unk1C = item;
    icon = (ov006_Icon021dfce8 *)Heap_Alloc(sizeof(ov006_Icon021dfce8));
    if (icon != NULL) {
        icon->vtbl = Ov006Vt_021ec2dc_vtbl;
        icon->unk4 = 0;
        PlayTime_Clear(icon->unk6);
        icon->unk1C = NULL;
        icon->unkE = 1;
    }
    item->unk18 = icon;
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
    m1 = (Model *)Heap_Alloc(sizeof(Model));
    if (m1 != NULL) {
        const char *name = data_0208cb7c;
        PlttRes_Init_02041218(&m1->pltt);
        TexObj_Init(m1, name, 0);
        STD_CopyString(m1->name, data_0214b105);
    }
    item->unk14 = m1;
    TexObj_SetRes(item->unk14, func_02035de0(data_0214b105, data_0208cb7c));
    item->unk14->flags |= 2;
    item->unk14->flags |= 0x80000;
    TexObj_SelectImage(item->unk14, 0, 0xd);
    TexObj_SelectImage(item->unk14, 0, 0xf);
    self->unk1C->unk8.z = -0x1ccd;
    ov006_Vec_Set021dfce8(&self->unk1C->unk8, 0x100000, 0xc0000, self->unk1C->unk8.z);
    panel = (ov006_Panel021dfce8 *)Heap_Alloc(sizeof(ov006_Panel021dfce8));
    if (panel != NULL) {
        panel->vtbl = Ov006Vt_021ec26c_vtbl;
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
        MI_CpuFill8(panel->unk78, 0, sizeof(panel->unk78));
        panel->unk82 = 0;
        panel->unk84 = 0;
        panel->unk88 = 0;
        panel->unk8C = 0;
        panel->unk90 = 0;
    }
    self->unk20 = panel;
    ov006_Unk021def9c_Load(panel);
    ov006_Vec_Set021dfce8(&self->unk20->unk10, 0x41000, 0x4e000, self->unk20->unk10.z);
    self->unk20->unk10.z = -0x1ccd;
    self->unk4 = 6;
    self->unk8 = 0;
    self->unkC = 0x1000;
}

}
