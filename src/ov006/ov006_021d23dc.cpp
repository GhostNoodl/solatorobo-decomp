#include "ov006/Tasks.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct ov006_Unk020706a0 {
    u8 unk0[4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
} ov006_Unk020706a0;

extern "C" {

extern const u8 data_ov006_021eb6fe[4];
extern const u16 data_ov006_021eb78c[];
extern const u8 data_ov006_021eb71c[];
extern const u8 data_ov006_021eb728[];
extern const u8 data_ov006_021eb770[];
extern const u8 data_ov006_021eb740[];

void ov006_Manager_DispatchMenuCb(int a, void *b, int c);
UiListItem *ListOwner_GetNth(UiList *self, int n);
void *ModelViewer_Ctor(void *p);
void ModelViewer_InitCamera(void *p);
void func_ov000_02162910(void *p, const void *a, const void *b, const void *c);
void func_ov000_0216295c(void *p, const void *v, int s);
ov006_Caption *ov006_Caption_Ctor(ov006_Caption *self);
void ov006_Caption_Init_021e0954(ov006_Caption *self);
void ov006_TextHolder_Play_021e0ca8(ov006_Caption *self, void *text, int b);
ov006_Gauge *Ov006Vt_021ec20c_Ctor(ov006_Gauge *self);
void ov006_Gauge_Load(ov006_Gauge *self);
void ov006_Gauge_SetText(ov006_Gauge *self, void *text);
void ov006_Gauge_SetRatio(ov006_Gauge *self, int a, int b, u8 c);
void ov006_Slot_Pack(ov006_Slot *self, void *buf);
void ov006_Menu_SetOwnEntry(ov006_Menu *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021d3498(ov006_TaskD1F *self, u16 id, BOOL dir);
ov006_Unk020706a0 *Tbl_Elem_020706a0(u16 id);
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);
void TaskList_Insert(Task *self);
BOOL func_ov006_021d1df8(UiList *window, UiListItem *node);
BOOL ov006_ListCb_StoreId(UiList *window, UiListItem *node);

static inline void ov006_Caption_SetPos(ov006_Caption *c, int x, int y) {
    c->x = x;
    c->y = y;
}

static inline void ov006_Caption_SetTextPos(ov006_Caption *c, int x, int y) {
    c->textX = x;
    c->textY = y;
}

static inline void ov006_Gauge_SetPos(ov006_Gauge *g, int x, int y) {
    g->x = x;
    g->y = y;
}

void ov006_TaskD1F_Start(ov006_TaskD1F *self) {
    int y;
    int i;
    void *res;
    if (self->vfunc_28()) {
        return;
    }
    res = gMsgRes;
    self->unk54 = ov006_NewUiList();
    self->unk54->vfunc_10(MsgRes_GetString(res, 0x128));
    self->unk54->vfunc_14(MsgRes_GetString(res, 0x129));
    self->unk54->unk_4a = 0x2c00;
    self->unk54->rows = 4;
    self->unk54->width = 0x8c;
    ov006_Window_SetPos(self->unk54, 0, 0x1e, -0x199a);
    self->unk54->posZ = -0x199a;
    ov006_Window_SetSlide(self->unk54, -0xff, 0, -0x199a);
    self->unk54->flags &= ~0x400000;
    self->unk54->flags &= ~0x80000;
    self->unk54->flags |= 0x40000;
    self->unk54->flags &= ~0x800000;
    self->unk54->flags |= 0x10000;
    ov006_Manager_DispatchMenuCb(3, self->unk54, 0);
    self->unk54->vfunc_08();
    UiList_SetPanelColor(self->unk54, data_ov006_021eb6fe[gOv006SlotManager->unk5]);
    if (self->unk4A != 0xffff) {
        UiList *w = self->unk54;
        w->vfunc_a8(UiList_GetItemById(w, self->unk4A));
    } else {
        self->unk54->vfunc_a8(ListOwner_GetNth(self->unk54, 0));
    }
    self->unk54->owner = self;
    self->unk54->onCursor = func_ov006_021d1df8;
    {
        void *p = Heap_Alloc(0x708);
        if (p != NULL) {
            p = ModelViewer_Ctor(p);
        }
        self->unk58 = (ov006_Actor58 *)p;
    }
    ModelViewer_InitCamera(self->unk58);
    func_ov000_02162910(self->unk58, data_ov006_021eb71c, data_ov006_021eb728, data_ov006_021eb770);
    func_ov000_0216295c(self->unk58, data_ov006_021eb740, 0x3d7);
    self->unk5C = ov006_NewLo021cadcc();
    self->unk5C->width = 0xf8;
    self->unk5C->rows = 2;
    ov006_Window_SetPos(self->unk5C, 4, 0x95, -0x199a);
    ov006_Window_SetSlide(self->unk5C, -0x100, 0, -0x199a);
    self->unk5C->slideMode = 1;
    self->unk5C->vfunc_08();
    self->unk60 = ov006_NewLo021cb0b8();
    self->unk60->msgId = 0x12c;
    self->unk60->text = (char *)MsgRes_GetString(res, 0x18);
    self->unk60->key = 1;
    self->unk60->onDecide = ov006_ListCb_StoreId;
    self->unk60->owner = &self->unk4C;
    self->unk60->vfunc_08();
    self->unk60->posZ = -0x1666;
    self->unk60->flags |= 2;
    self->unk64 = ov006_NewLo021cad50();
    Obj0215c1bc_SetText(self->unk64, 0x74, MsgRes_GetString(res, 0x139));
    self->unk64->flags |= 0x10000;
    self->unk64->flags &= ~0x20000;
    self->unk64->flags |= 2;
    {
        ov006_Caption *p = (ov006_Caption *)Heap_Alloc(sizeof(ov006_Caption));
        if (p != NULL) {
            p = ov006_Caption_Ctor(p);
        }
        self->unk68 = p;
    }
    self->unk68->kind = 1;
    ov006_Caption_Init_021e0954(self->unk68);
    ov006_TextHolder_Play_021e0ca8(self->unk68, MsgRes_GetString(res, 0x128), 4);
    ov006_Caption_SetPos(self->unk68, -0xa0, -0x61);
    ov006_Caption_SetTextPos(self->unk68, 0xf, 0);
    self->unk68->ofsY = -0x1e;
    y = -0x3e;
    for (i = 0; i < 4; i++) {
        ov006_Gauge *p = (ov006_Gauge *)Heap_Alloc(sizeof(ov006_Gauge));
        if (p != NULL) {
            p = Ov006Vt_021ec20c_Ctor(p);
        }
        self->gauges[i] = p;
        ov006_Gauge_Load(self->gauges[i]);
        ov006_Gauge_SetPos(self->gauges[i], -0x50, y);
        y += 0x20;
        self->gauges[i]->unk10 = i;
    }
    ov006_Gauge_SetText(self->gauges[0], MsgRes_GetString(res, 0x13a));
    ov006_Gauge_SetText(self->gauges[1], MsgRes_GetString(res, 0x13b));
    ov006_Gauge_SetText(self->gauges[2], MsgRes_GetString(res, 0x13c));
    ov006_Gauge_SetText(self->gauges[3], MsgRes_GetString(res, 0x13e));
    {
        u8 buf[0x18];
        ov006_Slot_Pack(ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5), buf);
        ov006_Menu_SetOwnEntry(data_ov006_021ec888, self->unk49, 1, buf, 0x18);
    }
    if (self->param != 0) {
        self->unk48 = 0;
    }
    {
        GfxSys *g = gGfxSys;
        Gfx3DState_SetDefaults(g->unk_8b0);
        g->unk_8b0[0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        Gfx3DState_Apply(g->unk_8b0);
    }
    if (self->unk54->items != NULL) {
        UiListItem *node = UiList_GetCurrent(self->unk54);
        u16 id = node->id;
        const void *str;
        ov006_Unk020706a0 *p;
        self->unk4A = id;
        str = MsgRes_GetString(gMsgRes, data_ov006_021eb78c[(u16)(id & 0xfff)]);
        if (self->unk5C != NULL && str != NULL) {
            Obj0215bb14_SetText(self->unk5C, str);
            self->unk5C->vfunc_70();
        }
        func_ov006_021d3498(self, id, FALSE);
        p = Tbl_Elem_020706a0(id);
        ov006_Gauge_SetRatio(self->gauges[0], p->unk4 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(self->gauges[1], p->unk5 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(self->gauges[2], p->unk6 << 12, 0xa000, 1);
        ov006_Gauge_SetRatio(self->gauges[3], p->unk7 << 12, 0xa000, 1);
    }
    self->fadeLen += self->unk54->openLen;
    self->unk_04 &= ~2;
    TaskList_Insert(self);
    GfxSys_StartFadeIn(0x14000, 0, 0);
    GfxSys_StartFadeIn(0x14000, 0, 1);
}

}
