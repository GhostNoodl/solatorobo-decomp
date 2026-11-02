#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];

void Task021ef79c_Start(Task021ef79c *self) {
    UiObj *o;
    UiObj *o2;
    UiObj *s;
    VObj *m;
    void *g;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        self->unk_3c->flags &= ~2;
        self->unk_40->flags &= ~2;
        self->unk_44 = 0;
        return;
    }
    g = data_02149ef8;
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_3c = (UiList *)o;
    o->rows = 2;
    self->unk_3c->width = 0x92;
    s = self->unk_3c;
    s->posX = 0;
    s->posY = 0x23;
    s->posZ = -0x199a;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xe8));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xea));
    self->unk_3c->flags &= ~0x10000;
    self->unk_3c->flags &= ~0x40000;
    self->unk_3c->flags &= ~0x20000;
    self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xf1), 0xb, 0xffff, 0xffff);
    self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xf2), 0x14, 0xffff, 0xffff);
    self->unk_3c->vfunc_08();
    m = self->unk_3c;
    m->vfunc_a8(UiList_GetItemById(m, 0xb));
    o2 = (UiObj *)Heap_Alloc(0x8c);
    if (o2 != NULL) {
        *(VFunc **)o2 = data_ov000_021cac60;
        o2->vfunc_28();
        *(VFunc **)o2 = data_ov000_021cadcc;
        o2->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)o2;
    o2->width = 0xf8;
    self->unk_40->rows = 2;
    s = self->unk_40;
    s->posX = 4;
    s->posY = 0x95;
    s->posZ = -0x199a;
    s = self->unk_40;
    s->slideX = -0x100;
    s->slideY = 0;
    s->slideZ = -0x199a;
    self->unk_40->slideMode = 1;
    self->unk_40->vfunc_08();
    TaskList_Insert(self);
}

BOOL func_ov002_021cf314(int idx, u32 arg);

void Task021ef79c_PreUpdate(Task021ef79c *self) {
    UiListItem *e;
    void *mgr;
    void *s1;
    void *s2;
    UiListItem *e2;
    if (self->state == 8) {
        mgr = data_02149ef8;
        e = UiList_GetItemById(self->unk_3c, 0xb);
        e->name = NULL;
        {
            HEAP_PUSH(s1);
            DELETE_VOBJ(e->label);
            HEAP_POP(s1);
        }
        e->name = (const char *)MsgRes_GetString(mgr, 0xf1);
        if (func_ov002_021cf314(8, 1)) {
            e->unk_24 = 0xe;
            e->unk_10 = -1;
        } else {
            e->unk_24 = 0;
            e->unk_10 = 0;
        }
        Obj02153c48_CreateText(e, 8, 0, 0, 0);
        e2 = UiList_GetItemById(self->unk_3c, 0x14);
        e2->name = NULL;
        {
            HEAP_PUSH(s2);
            DELETE_VOBJ(e2->label);
            HEAP_POP(s2);
        }
        e2->name = (const char *)MsgRes_GetString(mgr, 0xf2);
        if (func_ov002_021cf314(8, 0x101)) {
            e2->unk_24 = 0xe;
            e2->unk_10 = -1;
        } else {
            e2->unk_24 = 0;
            e2->unk_10 = 0;
        }
        Obj02153c48_CreateText(e2, 8, 0, 0, 0);
    }
    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
}

}
