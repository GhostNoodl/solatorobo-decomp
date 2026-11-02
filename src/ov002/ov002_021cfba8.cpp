#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];

void func_ov002_021cfba8(Task021ef79c *self) {
    UiObj *o;
    UiObj *o2;
    u8 *s;
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
    s = ((u8 *)self->unk_3c);
    FIELD(s, 0x64, s16) = 0;
    FIELD(s, 0x66, s16) = 0x23;
    FIELD(s, 0x68, s16) = -0x199a;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xe8));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xea));
    self->unk_3c->flags &= ~0x10000;
    self->unk_3c->flags &= ~0x40000;
    self->unk_3c->flags &= ~0x20000;
    self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xf1), 0xb, 0xffff, 0xffff);
    self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xf2), 0x14, 0xffff, 0xffff);
    self->unk_3c->vfunc_08();
    m = self->unk_3c;
    m->vfunc_a8(func_ov000_02154b58(m, (void *)0xb));
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
    s = ((u8 *)self->unk_40);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x95;
    FIELD(s, 0x68, s16) = -0x199a;
    s = ((u8 *)self->unk_40);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x199a;
    self->unk_40->slideMode = 1;
    self->unk_40->vfunc_08();
    func_ov000_02173648(self);
}

BOOL func_ov002_021cf314(int idx, u32 arg);

void func_ov002_021cfe48(Task021ef79c *self) {
    u8 *e;
    void *mgr;
    void *s1;
    void *s2;
    u8 *e2;
    if (self->state == 8) {
        mgr = data_02149ef8;
        e = (u8 *)func_ov000_02154b58(self->unk_3c, (void *)0xb);
        FIELD(e, 0x0, void *) = NULL;
        {
            HEAP_PUSH(s1);
            DELETE_VOBJ(FIELD(e, 0x1c, VObj *));
            HEAP_POP(s1);
        }
        FIELD(e, 0x0, void *) = MsgRes_GetString(mgr, 0xf1);
        if (func_ov002_021cf314(8, 1)) {
            FIELD(e, 0x24, s32) = 0xe;
            FIELD(e, 0x10, s32) = -1;
        } else {
            FIELD(e, 0x24, s32) = 0;
            FIELD(e, 0x10, s32) = 0;
        }
        func_ov000_02153c48(e, 8, 0, 0, 0);
        e2 = (u8 *)func_ov000_02154b58(self->unk_3c, (void *)0x14);
        FIELD(e2, 0x0, void *) = NULL;
        {
            HEAP_PUSH(s2);
            DELETE_VOBJ(FIELD(e2, 0x1c, VObj *));
            HEAP_POP(s2);
        }
        FIELD(e2, 0x0, void *) = MsgRes_GetString(mgr, 0xf2);
        if (func_ov002_021cf314(8, 0x101)) {
            FIELD(e2, 0x24, s32) = 0xe;
            FIELD(e2, 0x10, s32) = -1;
        } else {
            FIELD(e2, 0x24, s32) = 0;
            FIELD(e2, 0x10, s32) = 0;
        }
        func_ov000_02153c48(e2, 8, 0, 0, 0);
    }
    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
}

}
