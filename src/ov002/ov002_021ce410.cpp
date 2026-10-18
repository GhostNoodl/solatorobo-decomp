#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021ce410(Task50 *self) {
    if (VC(self, 0x54)() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
    return TRUE;
}

void func_ov002_021ce464(Task50 *self) {
    if (self->unk_08 != 0) {
        return;
    }
    if (!self->flag2) {
        return;
    }
    FIELD(func_ov000_0218084c(data_ov000_021ccd44, 0x10, 0), 0x2c, s32) = 0;
    data_ov000_021ccd34 = 1;
    data_ov000_021ccd44->flag0 = 0;
}

void func_ov002_021ce4c8(Task50 *self) {
    void *model = self->unk_3c;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (model == NULL || (res = FIELD(model, 0x28, void *)) == NULL) {
        return;
    }
    anim = NULL;
    if (FIELD(model, 0x80, s32) > 0) {
        anim = FIELD(model, 0x78, void *);
    }
    if (anim != NULL && (t = FIELD(anim, 0x4, void *)) != NULL) {
        arg = FIELD(t, 0x30, void *);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), 0);
        arg = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(e, 0xc, void *));
    }
    func_02042628(model, arg, anim, 0);
}

Task50 *func_ov002_021ce53c(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x4c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef4b0;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
    }
    p->v0x8(0x12, 0);
    return p;
}

void func_ov002_021ce5a8(void *self, int arg) {
    func_ov000_0218084c(data_ov000_021ccd44, arg, 0);
}

void func_ov002_021ce5c4(Task50 *self) {
    self->flag1 = 0;
    if (VC(self, 0x28)() != 0) {
        return;
    }
    func_ov002_021ce7b8(self);
    if (func_ov002_isMode4()) {
        func_0203cb78(self->unk_20, 0, -1);
    }
    VC(self, 0x3c)();
    func_ov000_02173648(self);
}

void func_ov002_021ce650(Task50 *self) {
    self->flag7 = 1;
}

void func_ov002_021ce660(Task50 *self, void *arg) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    FIELD(self, 0x44, void *) = arg;
    func_ov002_021ce7b8(self);
    FIELD(self->unk_3c, 0xc, u32) |= 2;
    FIELD(self->unk_40, 0xc, u32) |= 2;
}

void func_ov002_021ce724(Task50 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
}

}

extern "C" {
extern VFunc data_ov000_021cadcc[];
extern char *data_0208cb7c;
void func_ov000_021547e8(void *a, void *b, void *c, int d);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 rest : 25;
} Flags021ce7b8;

static inline BOOL ov002_021ce7b8_check(int idx, u32 arg) {
    u8 *base;
    void *tbl;
    u32 count;
    BOOL ok;
    u16 i;
    ok = TRUE;
    count = func_0205975c(data_02fe152c, idx);
    base = FIELD(data_02fe152c, 0x4c, u8 *) + 0x10 + idx * 0x20;
    tbl = func_0205976c(data_02fe152c, idx);
    for (i = 0; i < count; i++) {
        if (func_02059544(data_02fe152c, base, tbl, arg, i)) {
            ok = FALSE;
            break;
        }
    }
    return ok;
}

void func_ov002_021ce7b8(Task50 *self) {
    void *g = data_02149ef8;
    VObject *o;
    u8 *e;
    BOOL ok = ov002_021ce7b8_check(8, 1);
    if (ok) {
        ok = ov002_021ce7b8_check(8, 0x101);
    }
    FIELD(self, 0x48, Flags021ce7b8).b0 = ok;
    FIELD(self, 0x48, Flags021ce7b8).b2 = ov002_021ce7b8_check(9, 0x101);
    FIELD(self, 0x48, Flags021ce7b8).b4 = ov002_021ce7b8_check(10, 1);
    FIELD(self, 0x48, Flags021ce7b8).b6 = !func_020594bc(data_02fe152c, 5, 1, 5);
    o = (VObject *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021caec8;
        o->v0x28();
    }
    FIELD(self, 0x3c, VObject *) = o;
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xd9));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xda));
    FIELD(FIELD(self, 0x3c, void *), 0x24, s32) = 0x78;
    FIELD(FIELD(self, 0x3c, void *), 0x20, s32) = 6;
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x1e;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x400000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x800000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x20000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x80000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x40000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x10000;
    func_ov000_021547e8(FIELD(self, 0x3c, void *), data_0214b105, data_0208cb7c, 0xb);
    e = (u8 *)FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xe8), 0, 0xffff, 0);
    if (FIELD(self, 0x48, Flags021ce7b8).b0) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (FIELD(self, 0x48, Flags021ce7b8).b1) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xeb), 1, 0xffff, 1);
    if (FIELD(self, 0x48, Flags021ce7b8).b2) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (FIELD(self, 0x48, Flags021ce7b8).b3) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xee), 2, 0xffff, 2);
    if (FIELD(self, 0x48, Flags021ce7b8).b4) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (FIELD(self, 0x48, Flags021ce7b8).b5) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xe5), 3, 0xffff, 3);
    if (FIELD(self, 0x48, Flags021ce7b8).b6) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xe3), 4, 0xffff, 4);
    {
        VObject *m = FIELD(self, 0x3c, VObject *);
        m->v0xa8(func_ov000_02154b58(m, (void *)(u16)FIELD(self, 0x44, s32)));
    }
    FIELD(self, 0x3c, VObject *)->v0x8();
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x40, VObject *) = o;
    FIELD(o, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 2;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x95;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(self, 0x40, VObject *)->v0x8();
}
}

extern "C" {
void func_ov002_021cf280(Task50 *self, u32 id);

static inline u8 *ov002_021cedec_getSelected(void *list) {
    u8 *item = FIELD(list, 0x98, u8 *);
    if (item == NULL) {
        item = NULL;
    } else {
        s32 n = FIELD(list, 0xb1, s8);
        while (n-- != 0) {
            item = FIELD(item, 0x2c, u8 *);
        }
    }
    return item;
}

void func_ov002_021cedec(Task50 *self) {
    u16 keys;
    u32 id;
    keys = FIELD(data_02097dc8, 0x12, u16);
    id = FIELD(ov002_021cedec_getSelected(self->unk_3c), 0x6, u16);
    if (FIELD(self, 0x44, u32) != id) {
        func_ov002_021cf280(self, id);
    }
    FIELD(self, 0x44, u32) = id;
    if (keys & 1) {
        switch (id) {
        case 0:
            if (!FIELD(self, 0x48, Flags021ce7b8).b0) {
                VC(self, 0x60)(0x13, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 1:
            if (!FIELD(self, 0x48, Flags021ce7b8).b2) {
                VC(self, 0x60)(0x15, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 2:
            if (!FIELD(self, 0x48, Flags021ce7b8).b4) {
                VC(self, 0x60)(0x17, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 3:
            if (!FIELD(self, 0x48, Flags021ce7b8).b6) {
                VC(self, 0x60)(0x18, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 4:
            VC(self, 0xc)(0);
            func_0203cc58(self->unk_20, 2, -1);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            return;
        }
    } else if (keys & 2) {
        VC(self, 0xc)(0);
        func_0203cc58(self->unk_20, 2, -1);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
}
}
