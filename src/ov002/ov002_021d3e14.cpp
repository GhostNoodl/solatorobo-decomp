#include "ov002/ov002.h"

extern "C" {

extern VFunc Lo021cadcc_vtbl[];
extern VFunc Lo021cae48_vtbl[];
extern VFunc Lo021cb5a8_vtbl[];
extern VFunc UiList021cb4a8_vtbl[];
void MenuScript_Bind(void);
void MenuScript_Run(u16 v);
void Lo021cae48_SetValue(void *a, s32 b, s32 c);
void UiList021cb4a8_SetLabel(void *a, void *b);
void UiList021cb4a8_SetCenteredLabel(void *a, void *b);
void *func_0206ee58(u16 id);
BOOL Task021ef81c_List3cOnDecide(UiList *self, UiListItem *ev);
BOOL Task021ef81c_List3cOnCursor(UiList *self, UiListItem *ev);

static inline bool Ov002_Avail(u8 *blk, void *tbl, u16 i) {
    bool a = DataRes_ReadBitsAt_02059544(gDataRes, blk, tbl, 1, i) & 1;
    return a & (DataRes_ReadBitsAt_02059544(gDataRes, blk, tbl, 0x101, i) == 0);
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
    g = gMsgRes;
    MenuScript_Bind();

    p = (UiObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Lo021cadcc_vtbl;
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
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Lo021cae48_vtbl;
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
    self->unk_44->style = 2;
    Lo021cae48_SetValue(self->unk_44, ((s32)gStageFlags->unk_614), 0);
    self->unk_44->vfunc_08();

    p = (UiObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = UiList_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Lo021cb5a8_vtbl;
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
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = UiList_vtbl;
        p->vfunc_28();
        *(VFunc **)p = UiList021cb4a8_vtbl;
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
    self->unk_3c->onDecide = Task021ef81c_List3cOnDecide;
    self->unk_3c->onCursor = Task021ef81c_List3cOnCursor;
    self->unk_3c->owner = self;
    MenuScript_Run(((u32)self->param));

    blk = gDataRes->data + 0x110;
    tbl = DataRes_GetTable(gDataRes, 8);
    count = DataRes_GetCount(gDataRes, 8);
    for (i = 0; i < count; i++) {
        if (Ov002_Avail(blk, tbl, i)) {
            id = i | 0x4000;
            self->unk_3c->vfunc_74(Param_Get(id), id, 0xffff, FIELD(func_0206ee58(id), 2, u16));
        }
    }
    {
        VObj *m = self->unk_3c;
        if (FIELD(m, 0x9c, s16) == 0) {
            Obj0215bb14_SetText(self->unk_40, MsgRes_GetString(gMsgRes, 0x9d));
            self->unk_40->vfunc_70();
        } else {
            m->vfunc_a8(UiList_GetItemById(m, 0));
        }
    }
    self->unk_3c->vfunc_08();
    TaskList_Insert(self);
}

}
