#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov000_021cae48[];
extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021cb4a8[];
void func_ov000_02176560(void);
void func_ov000_02176590(u16 v);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void UiList021cb4a8_SetLabel(void *a, void *b);
void UiList021cb4a8_SetCenteredLabel(void *a, void *b);
void *func_0206ee58(u16 id);
BOOL func_ov002_021d3b10(UiList *self, UiListItem *ev);
BOOL func_ov002_021d3c30(UiList *self, UiListItem *ev);

static inline bool Ov002_Avail(u8 *blk, void *tbl, u16 i) {
    bool a = DataRes_ReadBitsAt_02059544(data_02fe152c, blk, tbl, 1, i) & 1;
    return a & (DataRes_ReadBitsAt_02059544(data_02fe152c, blk, tbl, 0x101, i) == 0);
}

void Task021ef81c_Start(Task021ef81c *self) {
    void *g;
    u8 *blk;
    u32 count;
    UiObj *p;
    u16 i;
    u16 id;
    void *tbl;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    func_ov000_02176560();

    p = (UiObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cadcc;
        p->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)p;
    p->width = 0xf8;
    self->unk_40->rows = 2;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x95;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = 0;
        s->slideY = 0x54;
        s->slideZ = -0x199a;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->color = 0xb;
    Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(g, 0xf3));
    self->unk_40->vfunc_70();
    self->unk_4c = 1;
    self->unk_40->vfunc_08();

    p = (UiObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cae48;
        p->vfunc_28();
    }
    self->unk_44 = (Lo021cae48 *)p;
    p->posX = 0x86;
    p->posY = 0x78;
    p->posZ = -0x199a;
    {
        Lo021cae48 *s = self->unk_44;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_44->slideMode = 1;
    self->unk_44->unk_84 = 2;
    func_ov000_0215d980(self->unk_44, ((s32)data_0214a424->unk_614), 0);
    self->unk_44->vfunc_08();

    p = (UiObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cb5a8;
        p->vfunc_28();
    }
    self->unk_48 = (Lo021cb5a8 *)p;
    p->flags |= 0x4000000;
    self->unk_48->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_48;
        s->posX = 0;
        s->posY = 0x11;
        s->posZ = -0x199a;
    }
    {
        Lo021cb5a8 *s = self->unk_48;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_48->flags |= 0x20000000;
    self->unk_48->vfunc_f4(1, MsgRes_GetString(g, 0x32));
    self->unk_48->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_48->vfunc_08();

    p = (UiObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cb4a8;
        p->vfunc_28();
    }
    self->unk_3c = (UiList021cb4a8 *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xf1));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xf3));
    self->unk_3c->rows = 4;
    self->unk_3c->width = 0xf8;
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->posX = 0;
        s->posY = 0x2c;
        s->posZ = -0x199a;
    }
    {
        UiList021cb4a8 *s = self->unk_3c;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->flags &= ~0x800000;
    self->unk_3c->unk_c1 = 5;
    self->unk_3c->unk_c0 = 0x78;
    UiList021cb4a8_SetLabel(self->unk_3c, MsgRes_GetString(g, 0xa2));
    UiList021cb4a8_SetCenteredLabel(self->unk_3c, MsgRes_GetString(g, 0x40));
    self->unk_3c->onDecide = func_ov002_021d3b10;
    self->unk_3c->onCursor = func_ov002_021d3c30;
    self->unk_3c->owner = self;
    func_ov000_02176590(((u32)self->param));

    blk = data_02fe152c->data + 0x110;
    tbl = DataRes_GetTable(data_02fe152c, 8);
    count = DataRes_GetCount(data_02fe152c, 8);
    for (i = 0; i < count; i++) {
        if (Ov002_Avail(blk, tbl, i)) {
            id = i | 0x4000;
            self->unk_3c->vfunc_74(Param_Get(id), id, 0xffff, FIELD(func_0206ee58(id), 2, u16));
        }
    }
    {
        VObj *m = self->unk_3c;
        if (FIELD(m, 0x9c, s16) == 0) {
            Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(data_02149ef8, 0x9d));
            self->unk_40->vfunc_70();
        } else {
            m->vfunc_a8(UiList_GetItemById(m, 0));
        }
    }
    self->unk_3c->vfunc_08();
    TaskList_Insert(self);
}

}
