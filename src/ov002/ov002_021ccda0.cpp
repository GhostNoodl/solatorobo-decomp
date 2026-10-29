#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ccda0(void) {
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 != NULL) {
        return;
    }
    p = (Unk021f0f80 *)func_0203dd9c(sizeof(Unk021f0f80));
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08 = -1;
    }
    data_ov002_021f0f80 = p;
}

void func_ov002_021ccde4(void) {
    u32 saved;
    Unk021f0f80 *p;
    if (data_ov002_021f0f80 == NULL) {
        return;
    }
    saved = data_02097dd0[0];
    data_02097dd0[0] = data_02097dd0[2];
    p = data_ov002_021f0f80;
    if (p != NULL) {
        if (p != NULL) {
            if (p->unk_04 >= 1) {
                func_02036838(data_02097cdc, data_0208cca0, 7, 0);
                func_02036838(data_02097cdc, data_0208cc94, 7, 0);
                func_02036838(data_02097cdc, data_0214b105, 7, 0);
            }
            func_0203de1c(p);
        }
        data_ov002_021f0f80 = NULL;
    }
    data_02097dd0[0] = saved;
}

void func_ov002_021cceb4(Unk021cceb4 *self) {
    switch (self->state) {
    case 0:
        if (func_020594bc(data_02fe152c, 5, 1, 0) == 1) {
            data_0214a424->unk_18.b8 = 0;
            data_0214a424->unk_18.b9 = 0;
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
            BitByte *b = (BitByte *)(data_02097d48 + 0x8b0);
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

Task50 *func_ov002_021cd06c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(sizeof(Task50));
    if (p != NULL) {
        Task_021cd06c_ctor(p);
    }
    VC(p, 0x8)(0x10, 0);
    return p;
}

void func_ov002_021cd0d4(Task50 *self) {
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
extern char *data_0208cb7c;
void func_0204aab0(void *p);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
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

void func_ov002_021cd124(Task50 *self) {
    void *g;
    void *res;
    void *m;
    VObject *o;
    {
        u8 *mm = data_02097e48;
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
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    res = func_02034d88(func_02035f30(data_ov002_021ef3e4, data_ov002_021ef3ec, 2), data_ov002_021ef3ec);
    m = func_0203dd9c(0x160);
    if (m != NULL) {
        func_02041218((u8 *)m + 0x88);
        func_02041440(m, NULL, 0);
    }
    FIELD(self, 0x3c, void *) = m;
    func_020417e0(m, res);
    FIELD(FIELD(self, 0x3c, void *), 0x6c, u32) |= 2;
    func_02041d9c(FIELD(self, 0x3c, void *), 0, 0);
    o = (VObject *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021caec8;
        o->v0x28();
    }
    FIELD(self, 0x40, VObject *) = o;
    FIELD(self, 0x40, VObject *)->v0x10(func_0204c0e8(g, 0xd7));
    FIELD(self, 0x40, VObject *)->v0x14(func_0204c0e8(g, 0xd8));
    FIELD(FIELD(self, 0x40, void *), 0x24, s32) = 0x92;
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 6;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x1e;
        FIELD(s, 0x68, s16) = -0x1ccd;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x1ccd;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x400000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x800000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x20000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x80000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x40000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x10000;
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0x96), 0, 0xffff, 0xffff);
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0xba), 1, 0xffff, 0xffff);
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0xc2), 2, 0xffff, 0xffff);
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0x4f), 3, 0xffff, 0xffff);
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0xd9), 4, 0xffff, 0xffff);
    FIELD(self, 0x40, VObject *)->v0x74(func_0204c0e8(g, 0xdd), 5, 0xffff, 0xffff);
    self->unk_4c = data_ov002_021f0f80->unk_08;
    data_ov002_021f0f80->unk_08 = -1;
    if (self->unk_4c == -1) {
        self->unk_4c = 0;
    }
    {
        VObject *mm = FIELD(self, 0x40, VObject *);
        mm->v0xa8(func_ov000_02154b58(mm, (void *)self->unk_4c));
    }
    func_ov000_021547e8(FIELD(self, 0x40, void *), data_0214b105, data_0208cb7c, 0xb);
    FIELD(self, 0x40, VObject *)->v0x8();
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~0x10;
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x44, VObject *) = o;
    FIELD(o, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x44, void *), 0x20, s32) = 2;
    {
        u8 *s = FIELD(self, 0x44, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x95;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x44, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x44, void *), 0x2c, s32) = 1;
    FIELD(self, 0x44, VObject *)->v0x8();
    FIELD(self, 0x48, Flags021cd124).b1 = !func_020624d8();
    FIELD(self, 0x48, Flags021cd124).b0 = func_ov000_02188dfc() != 0;
    if (func_020594bc(data_02fe152c, 5, 1, 0) == 0) {
        FIELD(self, 0x48, Flags021cd124).b2 = 1;
    }
    if (FIELD(self, 0x48, Flags021cd124).b0) {
        FIELD(func_ov000_02154b58(FIELD(self, 0x40, void *), (void *)0), 0x24, s32) = 0xe;
    }
    if (FIELD(self, 0x48, Flags021cd124).b2) {
        FIELD(func_ov000_02154b58(FIELD(self, 0x40, void *), (void *)1), 0x24, s32) = 0xe;
    }
    if (FIELD(self, 0x48, Flags021cd124).b1) {
        FIELD(func_ov000_02154b58(FIELD(self, 0x40, void *), (void *)5), 0x24, s32) = 0xe;
    }
    ((VObject *)self)->v0x78(self->unk_4c);
    {
        void *t = data_ov000_021ccd30;
        if (t != NULL) {
            if (FIELD(t, 0x118, void *) == NULL) {
                void *task = func_0203dd9c(0x34);
                if (task != NULL) {
                    *(VFunc **)task = data_ov002_021ef410;
                    func_ov000_0216f144(task);
                    *(VFunc **)task = data_ov000_021cb920;
                    func_ov000_0216f828(task);
                }
                FIELD(t, 0x118, void *) = task;
                func_ov000_0216f398(t, task, 0x10000, t);
                FIELD(FIELD(t, 0x118, void *), 0x4, u32) |= 0x10;
            }
            if (FIELD(data_ov000_021ccd30, 0x118, void *) != NULL) {
                func_ov000_0216f844(FIELD(data_ov000_021ccd30, 0x118, void *), 1);
            }
        }
    }
    if (func_ov002_isMode4()) {
        func_0203cb78(self->unk_20, 0, 0);
    }
    func_ov000_02173648(self);
}
}
