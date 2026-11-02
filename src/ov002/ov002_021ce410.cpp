#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021ce410(Task *self) {
    if (self->vfunc_54() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
    return TRUE;
}

void func_ov002_021ce464(Task021ef430 *self) {
    if (self->state != 0) {
        return;
    }
    if (!self->unk_04_2) {
        return;
    }
    FIELD(func_ov000_0218084c(data_ov000_021ccd44, 0x10, 0), 0x2c, s32) = 0;
    data_ov000_021ccd34 = 1;
    data_ov000_021ccd44->flag0 = 0;
}

void func_ov002_021ce4c8(Task021ef430 *self) {
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
    func_02042628((Model *)model, arg, (ModelPart *)anim, 0);
}

Task021ef4b0 *func_ov002_021ce53c(void) {
    Task021ef4b0 *p = (Task021ef4b0 *)Heap_Alloc(0x4c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef4b0;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
    }
    p->vfunc_08(0x12, 0);
    return p;
}

void func_ov002_021ce5a8(Task021ef4b0 *self, int arg) {
    func_ov000_0218084c(data_ov000_021ccd44, arg, 0);
}

void func_ov002_021ce5c4(Task021ef4b0 *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28() != 0) {
        return;
    }
    func_ov002_021ce7b8(self);
    if (func_ov002_isMode4()) {
        func_0203cb78(self->fadeLen, 0, -1);
    }
    self->vfunc_3c();
    func_ov000_02173648(self);
}

void Ov002Task_SetFlag7(Task *self) {
    self->unk_04_7 = 1;
}

void func_ov002_021ce660(Task021ef4b0 *self, u32 arg) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    self->unk_44 = arg;
    func_ov002_021ce7b8(self);
    self->unk_3c->flags |= 2;
    self->unk_40->flags |= 2;
}

void func_ov002_021ce724(Task021ef4b0 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
}

}

extern "C" {
extern VFunc data_ov000_021cadcc[];
void func_ov000_021547e8(void *a, void *b, const char *c, int d);

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
    base = data_02fe152c->data + 0x10 + idx * 0x20;
    tbl = func_0205976c(data_02fe152c, idx);
    for (i = 0; i < count; i++) {
        if (func_02059544(data_02fe152c, base, tbl, arg, i)) {
            ok = FALSE;
            break;
        }
    }
    return ok;
}

void func_ov002_021ce7b8(Task021ef4b0 *self) {
    void *g = data_02149ef8;
    UiObj *o;
    u8 *e;
    BOOL ok = ov002_021ce7b8_check(8, 1);
    if (ok) {
        ok = ov002_021ce7b8_check(8, 0x101);
    }
    self->unk_48_0 = ok;
    self->unk_48_2 = ov002_021ce7b8_check(9, 0x101);
    self->unk_48_4 = ov002_021ce7b8_check(10, 1);
    self->unk_48_6 = !func_020594bc(data_02fe152c, 5, 1, 5);
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_3c = (UiList *)o;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xd9));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xda));
    self->unk_3c->width = 0x78;
    self->unk_3c->rows = 6;
    {
        UiList *s = self->unk_3c;
        s->posX = 0;
        s->posY = 0x1e;
        s->posZ = -0x199a;
    }
    {
        UiList *s = self->unk_3c;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags &= ~0x400000;
    self->unk_3c->flags &= ~0x800000;
    self->unk_3c->flags &= ~0x20000;
    self->unk_3c->flags &= ~0x80000;
    self->unk_3c->flags &= ~0x40000;
    self->unk_3c->flags &= ~0x10000;
    func_ov000_021547e8(self->unk_3c, data_0214b105, data_0208cb7c, 0xb);
    e = (u8 *)self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xe8), 0, 0xffff, 0);
    if (self->unk_48_0) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (self->unk_48_1) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xeb), 1, 0xffff, 1);
    if (self->unk_48_2) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (self->unk_48_3) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xee), 2, 0xffff, 2);
    if (self->unk_48_4) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    if (self->unk_48_5) {
        FIELD(e, 0xa, s16) = 0xb;
    }
    e = (u8 *)self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xe5), 3, 0xffff, 3);
    if (self->unk_48_6) {
        FIELD(e, 0x24, s32) = 0xe;
    }
    self->unk_3c->vfunc_74(MsgRes_GetString(g, 0xe3), 4, 0xffff, 4);
    {
        VObj *m = self->unk_3c;
        m->vfunc_a8(func_ov000_02154b58(m, self->unk_44));
    }
    self->unk_3c->vfunc_08();
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_40->rows = 2;
    {
        Lo021cadcc *s = self->unk_40;
        s->posX = 4;
        s->posY = 0x95;
        s->posZ = -0x199a;
    }
    {
        Lo021cadcc *s = self->unk_40;
        s->slideX = -0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_40->slideMode = 1;
    self->unk_40->vfunc_08();
}
}

extern "C" {
void func_ov002_021cf280(Task021ef4b0 *self, u32 id);

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

void func_ov002_021cedec(Task021ef4b0 *self) {
    u16 keys;
    u32 id;
    keys = data_02097dc8->trig;
    id = FIELD(ov002_021cedec_getSelected(self->unk_3c), 0x6, u16);
    if (self->unk_44 != id) {
        func_ov002_021cf280(self, id);
    }
    self->unk_44 = id;
    if (keys & 1) {
        switch (id) {
        case 0:
            if (!self->unk_48_0) {
                self->vfunc_60(0x13, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 1:
            if (!self->unk_48_2) {
                self->vfunc_60(0x15, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 2:
            if (!self->unk_48_4) {
                self->vfunc_60(0x17, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 3:
            if (!self->unk_48_6) {
                self->vfunc_60(0x18, 0);
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            return;
        case 4:
            self->vfunc_0c(0);
            func_0203cc58(self->fadeLen, 2, -1);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            return;
        }
    } else if (keys & 2) {
        self->vfunc_0c(0);
        func_0203cc58(self->fadeLen, 2, -1);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
}
}
