#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ccda0(void) {
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 != NULL) {
        return;
    }
    p = (Unk021f0f80 *)Heap_Alloc(sizeof(Unk021f0f80));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = -1;
    }
    data_ov002_021f0f80 = p;
}

void func_ov002_021ccde4(void) {
    void *saved;
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 == NULL) {
        return;
    }
    HEAP_PUSH(saved);
    p = data_ov002_021f0f80;
    if (p != NULL) {
        if (p != NULL) {
            if (p->unk_04 >= 1) {
                func_02036838(data_02097cdc, data_0208cca0, 7, 0);
                func_02036838(data_02097cdc, data_0208cc94, 7, 0);
                func_02036838(data_02097cdc, data_0214b105, 7, 0);
            }
            Heap_Free(p);
        }
        data_ov002_021f0f80 = NULL;
    }
    HEAP_POP(saved);
}

void func_ov002_021cceb4(Unk021cceb4 *self) {
    switch (self->state) {
    case 0:
        if (func_020594bc(data_02fe152c, 5, 1, 0) == 1) {
            data_0214a424->bits18.flag8 = 0;
            data_0214a424->bits18.flag9 = 0;
        }
        func_020359d0(data_0208cca0, 7, 0);
        func_020359d0(data_0208cc94, 7, 0);
        func_020359d0(data_0214b105, 7, 0);
        self->state = 1;
    case 1:
        func_02035b90(data_0208cca0, 7);
        func_02035b90(data_0208cc94, 7);
        if (func_02035b90(data_0214b105, 7) == 0) {
            return;
        }
        self->state = 2;
    case 2:
        func_ov000_02180660(0x10, 0);
        {
            BitByte *b = (BitByte *)(data_02097d48->unk_8b0);
            b->b4 = 0;
            b->b5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        self->state = 3;
        return;
    case 3:
        BOOL r = func_ov002_inline_flag1();
        if (r) {
            func_ov000_02180754();
            func_0203cc58(0x1e000, 2, -1);
            self->flags.flag0 = 1;
            self->state = 4;
        }
        return;
    }
}

void func_ov002_021cd068(void *self) {
}

Task021ef530 *func_ov002_021cd06c(void) {
    Task021ef530 *p = (Task021ef530 *)Heap_Alloc(sizeof(Task021ef530));
    if (p != NULL) {
        Task_021cd06c_ctor(p);
    }
    p->vfunc_08(0x10, 0);
    return p;
}

void func_ov002_021cd0d4(Task021ef530 *self) {
    func_020359fc(data_ov002_021ef3e4, data_ov002_021ef3ec, 2, 0);
    self->unk_4d = 1;
}

int func_ov002_021cd104(void) {
    return func_02035bd4(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
}

}

extern "C" {
extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov000_021cb920[];
void func_0204aab0(void *p);
void func_ov000_021547e8(void *a, void *b, const char *c, int d);
BOOL func_020624d8(void);
BOOL func_ov000_02188dfc(void);
void func_ov000_0216f144(void *p);
void func_ov000_0216f828(void *p);
void *func_ov000_0216f398(void *a, void *b, s32 c, void *d);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} Flags021cd124;

void func_ov002_021cd124(Task021ef530 *self) {
    void *g;
    void *res;
    void *m;
    UiObj *o;
    {
        u8 *mm = (u8 *)data_02097e48.queue;
        if (FIELD(mm, 0x0, Bits16).b0) {
            if (FIELD(mm, 0x6, u16) != 0xffff || FIELD(mm, 0x4, u16) != 13) {
                if (FIELD(mm, 0x2, u16) != 10 && FIELD(mm, 0x2, u16) != 0) {
                    if (FIELD(mm, 0x6, u16) != 0xffff) {
                        func_0204aab0(mm);
                    }
                    FIELD(mm, 0x2, u16) = 1;
                } else {
                    FIELD(mm, 0x2, u16) = 0;
                }
                FIELD(mm, 0x6, u16) = 13;
                FIELD(mm, 0x8, u16) = 10;
            }
        }
    }
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    res = func_02034d88(func_02035f30(data_ov002_021ef3e4, data_ov002_021ef3ec, 2), data_ov002_021ef3ec);
    m = Heap_Alloc(0x160);
    if (m != NULL) {
        func_02041218((PlttRes *)((u8 *)m + 0x88));
        func_02041440((Model *)m, NULL, 0);
    }
    self->unk_3c = (Model *)m;
    func_020417e0((Model *)m, res);
    self->unk_3c->flags |= 2;
    func_02041d9c((Model *)self->unk_3c, 0, 0);
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_40 = (UiList *)o;
    self->unk_40->vfunc_10(MsgRes_GetString(g, 0xd7));
    self->unk_40->vfunc_14(MsgRes_GetString(g, 0xd8));
    self->unk_40->width = 0x92;
    self->unk_40->rows = 6;
    {
        UiList *s = self->unk_40;
        s->posX = 0;
        s->posY = 0x1e;
        s->posZ = -0x1ccd;
    }
    {
        UiList *s = self->unk_40;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x1ccd;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->flags &= ~0x400000;
    self->unk_40->flags &= ~0x800000;
    self->unk_40->flags &= ~0x20000;
    self->unk_40->flags &= ~0x80000;
    self->unk_40->flags &= ~0x40000;
    self->unk_40->flags &= ~0x10000;
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0x96), 0, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xba), 1, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xc2), 2, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0x4f), 3, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xd9), 4, 0xffff, 0xffff);
    self->unk_40->vfunc_74(MsgRes_GetString(g, 0xdd), 5, 0xffff, 0xffff);
    self->unk_4c = data_ov002_021f0f80->unk_08;
    data_ov002_021f0f80->unk_08 = -1;
    if (self->unk_4c == -1) {
        self->unk_4c = 0;
    }
    {
        VObj *mm = self->unk_40;
        mm->vfunc_a8(func_ov000_02154b58(mm, self->unk_4c));
    }
    func_ov000_021547e8(self->unk_40, data_0214b105, data_0208cb7c, 0xb);
    self->unk_40->vfunc_08();
    self->unk_40->flags &= ~0x10;
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_44 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_44->rows = 2;
    {
        Lo021cadcc *s = self->unk_44;
        s->posX = 4;
        s->posY = 0x95;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_44;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_44->slideMode = 1;
    self->unk_44->vfunc_08();
    self->unk_48_1 = !func_020624d8();
    self->unk_48_0 = func_ov000_02188dfc() != 0;
    if (func_020594bc(data_02fe152c, 5, 1, 0) == 0) {
        self->unk_48_2 = 1;
    }
    if (self->unk_48_0) {
        func_ov000_02154b58(self->unk_40, 0)->unk_24 = 0xe;
    }
    if (self->unk_48_2) {
        func_ov000_02154b58(self->unk_40, 1)->unk_24 = 0xe;
    }
    if (self->unk_48_1) {
        func_ov000_02154b58(self->unk_40, 5)->unk_24 = 0xe;
    }
    self->vfunc_78(self->unk_4c);
    {
        FieldPlayer *t = data_ov000_021ccd30;
        if (t != NULL) {
            if (t->unk_118 == NULL) {
                TimedBuffer021cb920 *task = (TimedBuffer021cb920 *)Heap_Alloc(sizeof(TimedBuffer021cb920));
                if (task != NULL) {
                    *(VFunc **)task = data_ov002_021ef410;
                    func_ov000_0216f144(task);
                    *(VFunc **)task = data_ov000_021cb920;
                    func_ov000_0216f828(task);
                }
                t->unk_118 = task;
                func_ov000_0216f398(t, task, 0x10000, t);
                t->unk_118->flags |= 0x10;
            }
            if (data_ov000_021ccd30->unk_118 != NULL) {
                func_ov000_0216f844(data_ov000_021ccd30->unk_118, 1);
            }
        }
    }
    if (func_ov002_isMode4()) {
        func_0203cb78(self->fadeLen, 0, 0);
    }
    func_ov000_02173648(self);
}
}
