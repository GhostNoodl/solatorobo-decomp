#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

typedef struct ov006_Price021da208 {
    u16 unk0;
    u16 unk2;
} ov006_Price021da208;

typedef struct ov006_Entry021da208 {
    void *vtbl;
    u8 unk4[0x10];
    int unk14;
    u8 unk18[0x20];
    void *unk38;
    u16 unk3C;
    int unk40;
} ov006_Entry021da208;

extern "C" {

extern void *data_ov000_021cca40;
extern void *data_ov006_021ebc80;
extern const ov006_Price021da208 data_ov006_021eb7b4[];
extern const ov006_Price021da208 data_ov006_021eb7c4[];
extern const ov006_Price021da208 data_ov006_021eb7e4;

void ListRow_Init(void *self);
void Lo021cca40_Init(void *self);
BOOL ov006_ListCb_StoreIdOrCancel(UiList *self, UiListItem *item);

static inline u8 ov006_SlotManager_GetItem(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->items[i];
    }
    return 0;
}

static inline u8 ov006_SlotManager_GetItemCount(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14D[i];
    }
    return 0;
}

static inline const ov006_Price021da208 *ov006_GetItemPrice(u8 item) {
    const ov006_Price021da208 *p = NULL;
    if (item != 0 && item < 11) {
        p = &data_ov006_021eb7c4[item];
    }
    return p;
}

static inline void *ov006_GetRes(void) {
    return data_02149ef8;
}

static inline ov006_Entry021da208 *ov006_NewEntry(void) {
    ov006_Entry021da208 *e = (ov006_Entry021da208 *)Heap_Alloc(0x48);
    if (e != NULL) {
        e->vtbl = &data_ov006_021ebc80;
        ListRow_Init(e);
        e->vtbl = &data_ov000_021cca40;
        Lo021cca40_Init(e);
    }
    return e;
}

static inline void ov006_Entry_Set(ov006_Entry021da208 *e, void *res, const ov006_Price021da208 *p, int cnt) {
    u16 price = p->unk2;
    e->unk38 = MsgRes_GetString(res, p->unk0);
    e->unk3C = cnt;
    e->unk40 = price * cnt;
}

void ov006_Task021ec040_BuildShopList(ov006_Task021ec040 *self) {
    void *res = ov006_GetRes();
    u8 n = data_ov006_021ec884->lap;
    const ov006_Price021da208 *base;
    u8 i;
    if (n < 1) {
        n = 1;
    } else if (n > 4) {
        n = 4;
    }
    base = &data_ov006_021eb7b4[(u8)(n - 1)];
    self->unk10 = ov006_NewUiList021cb4a8();
    self->unk10->vfunc_10(MsgRes_GetString(res, 0x18e));
    self->unk10->vfunc_14(MsgRes_GetString(res, 0x18f));
    self->unk10->unk_4a = 0x2c00;
    UiList021cb4a8_SetLabel(self->unk10, MsgRes_GetString(res, 0x190));
    UiList021cb4a8_SetCenteredLabel(self->unk10, MsgRes_GetString(res, 0x3e));
    self->unk10->width = 0xf8;
    self->unk10->rows = 1;
    ov006_Window_SetPos(self->unk10, 0, 0x19, -0x199a);
    ov006_Window_SetSlide(self->unk10, -0x100, 0, 0);
    self->unk10->flags |= 0x400000;
    self->unk10->flags &= ~0x800000;
    self->unk10->unk_c0 = 0x8c;
    self->unk10->unk_c1 = 4;
    self->unk10->vfunc_74(MsgRes_GetString(res, base->unk0), 0, 0xffff, base->unk2);
    self->unk10->flags &= ~0x40000;
    self->unk10->flags &= ~0x20000;
    self->unk10->flags &= ~0x10000;
    self->unk10->flags &= ~0x2000000;
    {
        UiList021cb4a8 *w = self->unk10;
        w->vfunc_a8(UiList_GetItemById(w, 0));
    }
    self->unk10->flags |= 4;
    self->unk10->vfunc_08();
    self->unk10->flags &= ~2;

    self->unk14 = ov006_NewHudList();
    Obj021c55e8_SetLabel1(self->unk14, MsgRes_GetString(res, 0x191));
    Obj021c55e8_SetLabel2(self->unk14, MsgRes_GetString(res, 0x192));
    Obj021c55e8_SetLabel3(self->unk14, MsgRes_GetString(res, 0x3e));
    self->unk14->width = 0xf8;
    self->unk14->rows = 4;
    ov006_Window_SetPos(self->unk14, 2, 0x3b, -0x199a);
    ov006_Window_SetSlide(self->unk14, -0x100, 0, 0);
    if (data_ov006_021ec860->unk1C) {
        const ov006_Price021da208 *p = &data_ov006_021eb7e4;
        ov006_Entry021da208 *e = ov006_NewEntry();
        ov006_Entry_Set(e, res, p, data_ov006_021ec884->numActive);
        e->unk14 = -0x199a;
        LoBase021ccb54_021ccbe0_AppendRow(self->unk14, e);
    }
    for (i = 0; i < 3; i++) {
        u8 item = ov006_SlotManager_GetItem(data_ov006_021ec884, i);
        const ov006_Price021da208 *p = ov006_GetItemPrice(item);
        if (p != NULL) {
            int cnt = 1;
            ov006_Entry021da208 *e;
            if (item < 8) {
                cnt = ov006_SlotManager_GetItemCount(data_ov006_021ec884, i);
            }
            e = ov006_NewEntry();
            ov006_Entry_Set(e, res, p, cnt);
            LoBase021ccb54_021ccbe0_AppendRow(self->unk14, e);
        }
    }
    self->unk14->flags &= ~0x40000;
    self->unk14->unk_f0 = 0;
    self->unk14->flags |= 4;
    self->unk14->vfunc_08();
    self->unk14->flags &= ~2;

    self->unk18 = ov006_NewLo021cae48();
    ov006_Window_SetPos(self->unk18, 0x92, 0x86, -0x199a);
    ov006_Window_SetSlide(self->unk18, 0x100, 0, 0);
    self->unk18->slideMode = 1;
    self->unk18->vfunc_08();
    Lo021cae48_SetValue(self->unk18, self->unk38, 1);

    self->unk1C = ov006_NewLo021cae48();
    ov006_Window_SetPos(self->unk1C, 0x92, 0x96, -0x199a);
    ov006_Window_SetSlide(self->unk1C, 0x100, 0, 0);
    self->unk1C->slideMode = 1;
    self->unk1C->vfunc_08();
    Lo021cae48_SetValue(self->unk1C, *(s32 *)((u8 *)data_0214a424 + 0x20), 1);

    self->unk20 = ov006_NewLo021cb5a8();
    self->unk20->flags |= 0x4000000;
    self->unk20->slideMode = 1;
    self->unk20->flags |= 0x20000000;
    self->unk20->flags |= 0x80000000;
    ov006_Window_SetSlide(self->unk20, 0x100, 0, -0xcd);
    self->unk20->vfunc_f4(1, MsgRes_GetString(res, 0x36));
    self->unk20->vfunc_08();
    self->unk20->flags |= 2;

    self->unk24 = ov006_NewLo021cad50();
    Obj0215c1bc_SetText(self->unk24, 0x74, MsgRes_GetString(res, 0x197));
    self->unk24->flags |= 0x10000;
    self->unk24->flags &= ~0x20000;
    self->unk24->flags |= 2;

    self->unk28 = ov006_NewLo021cb0b8();
    self->unk28->msgId = 0x8d;
    self->unk28->text = (char *)MsgRes_GetString(ov006_GetRes(), 0x26);
    self->unk28->key = 0;
    self->unk28->onDecide = ov006_ListCb_StoreIdOrCancel;
    self->unk28->owner = &self->unk2C;
    self->unk28->vfunc_08();
    self->unk28->posZ = -0x1666;
    self->unk28->flags |= 2;
}

}
