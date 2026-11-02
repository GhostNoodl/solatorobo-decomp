#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021efca4_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->vfunc_2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void func_ov002_021d58ac(void) {
}

BOOL func_ov002_021d58b0(void) {
    return TRUE;
}

}

extern "C" {
extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov002_021efca4[];
extern char data_ov002_021efaf1[];
extern u8 data_ov002_021eef54[];
void *func_02035de0(void *a, void *b);
void func_ov000_021547e8(void *a, void *b, const char *c, int d);
void *func_ov000_02162124(void *p);
void func_ov000_021627ac(void *p);
void func_ov000_021c95fc(void *p);
BOOL func_ov002_021d5444(UiList *self, UiListItem *ev);
BOOL func_ov002_021d5350(UiList *self, UiListItem *ev);
void func_ov002_021d66b0(void *self, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);

static inline UiListItem *ov002_021d58b8_sel(UiList *g) {
    UiListItem *p = g->topItem;
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = g->cursor;
        while (n-- != 0) {
            p = p->next;
        }
    }
    return p;
}

static inline void ov002_021d58b8_setName(Task021efc24 *self, u16 id) {
    if (self->unk_54 != NULL) {
        func_ov000_0215bb14(self->unk_54, func_0206ec8c(id));
        self->unk_54->vfunc_70();
    }
}

static inline void ov002_021d58b8_setInfo(Task021efc24 *self, u16 id) {
    if (self->unk_58 != NULL) {
        Param0206ef10 *info = func_0206ef10(id);
        func_ov000_02162b40(self->unk_58, info->def.name[0], info->def.name[1], data_ov002_021efae1,
                            info->def.unk_1c, data_ov002_021efaeb, info->def.unk_18, 0x1000);
    }
}

static inline void ov002_021d58b8_setId(Ov002Hud *x, u16 id) {
    if (x != NULL) {
        func_ov002_021e2754(x, id);
    }
}

void func_ov002_021d58b8(Task021efc24 *self) {
    void *res;
    void *m;
    UiObj *o;
    void *g = data_02149ef8;
    u8 *base;
    void *tbl;
    u16 i;
    u16 id;
    u32 count;
    UiListItem *e;
    self->unk_74 = data_0214a424->bits18.unk_3 + 0x8000;
    res = func_02035de0(data_ov002_021efaf1, data_0208ccc0);
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        func_02041218((PlttRes *)((u8 *)m + 0x88));
        func_02041440((Model *)m, NULL, 0);
    }
    self->unk_3c = (Model *)m;
    func_020417e0((Model *)m, res);
    self->unk_3c->flags |= 2;
    func_02041d9c((Model *)self->unk_3c, 0, 0);
    self->unk_3c->unk_150 = -0x1fe66;
    self->unk_3c->unk_158 = (void *)func_ov002_021d66b0;
    func_02041c20((Model *)self->unk_3c, 0, (u8 *)self + 0x40);
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_4c = (Lo021cadcc *)o;
    o->rows = 1;
    {
        Lo021cadcc *s = self->unk_4c;
        s->posX = 0;
        s->posY = 0x12;
        s->posZ = -0x199a;
    }
    self->unk_4c->width = 0x5a;
    self->unk_4c->posZ = -0x199a;
    {
        Lo021cadcc *s = self->unk_4c;
        s->slideX = -0xff;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_4c->slideMode = 1;
    {
        Lo021cadcc *s = self->unk_4c;
        s->shape = (VecFx16 *)data_ov002_021eef54;
        s->shapeCount = 5;
    }
    self->unk_4c->flags |= 0x80000;
    self->unk_4c->vfunc_08();
    func_ov000_0215bb14(self->unk_4c, func_0206ec48(self->unk_74));
    self->unk_4c->vfunc_70();
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(VFunc **)o = data_ov002_021efca4;
    }
    self->unk_50 = (UiList *)o;
    self->unk_50->vfunc_10(MsgRes_GetString(g, 0xbe));
    self->unk_50->vfunc_14(MsgRes_GetString(g, 0xbf));
    self->unk_50->rows = 2;
    self->unk_50->width = 0x74;
    {
        UiList *s = self->unk_50;
        s->posX = 0;
        s->posY = 0x30;
        s->posZ = -0x199a;
    }
    self->unk_50->posZ = -0x199a;
    {
        UiList *s = self->unk_50;
        s->slideX = -0xff;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    func_ov000_021547e8(self->unk_50, data_0214b105, data_0208cb7c, 0xb);
    self->unk_50->flags &= ~0x400000;
    self->unk_50->flags &= ~0x80000;
    self->unk_50->flags |= 0x40000;
    self->unk_50->flags &= ~0x800000;
    self->unk_50->flags |= 0x10000;
    self->unk_50->vfunc_08();
    base = data_02fe152c->data;
    tbl = func_0205976c(data_02fe152c, 12);
    count = func_0205975c(data_02fe152c, 12);
    for (i = 0; i < count; i++) {
        if (func_02059544(data_02fe152c, base + 0x190, tbl, 1, i)) {
            id = i + 0x8000;
            e = (UiListItem *)self->unk_50->vfunc_74(func_0206ec48(id), id, 0xffff, 0xffff);
            if (self->unk_74 == id) {
                e->unk_24 = 4;
            }
        }
    }
    self->unk_50->onDecide = func_ov002_021d5444;
    self->unk_50->onCursor = func_ov002_021d5350;
    self->unk_50->owner = self;
    {
        VObj *mm = self->unk_50;
        mm->vfunc_a8(func_ov000_02154b58(mm, self->unk_74));
    }
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_54 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_54->rows = 3;
    {
        Lo021cadcc *s = self->unk_54;
        s->posX = 4;
        s->posY = 0x87;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_54;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_54->slideMode = 1;
    self->unk_54->vfunc_08();
    {
        UiListItem *p = NULL;
        UiListItem *it = self->unk_50->topItem;
        if (it != NULL) {
            s32 n = self->unk_50->cursor;
            while (n-- != 0) {
                it = it->next;
            }
            p = it;
        }
        if (p != NULL) {
            ov002_021d58b8_setName(self, p->id);
        }
    }
    {
        void *q = Heap_Alloc(0x708);
        if (q != NULL) {
            q = func_ov000_02162124(q);
        }
        self->unk_58 = (VObj *)q;
        func_ov000_021627ac(q);
    }
    {
        UiListItem *p = ov002_021d58b8_sel(self->unk_50);
        if (p != NULL) {
            ov002_021d58b8_setInfo(self, p->id);
        }
    }
    {
        Task021efba4 *t = (Task021efba4 *)Task_FindById(0x1b);
        if (t != NULL) {
            if (t->hud != NULL) {
                func_ov002_021e2690(t->hud, 9, 0);
            }
            func_ov000_021c95fc((u8 *)self + 0x60);
            if (t->hud != NULL) {
                MI_CpuCopy8((u8 *)self + 0x60, t->hud->unk_2c, 0x14);
            }
            ov002_021d58b8_setId(t->hud, self->unk_74);
        }
    }
    if (func_ov002_isMode4()) {
        func_0203cb78(0x14000, 0, -1);
    }
    func_ov000_02173648(self);
}
}
