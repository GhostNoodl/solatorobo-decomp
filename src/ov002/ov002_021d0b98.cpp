#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021cca10[];
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2334(void *self);
void func_ov000_021c2a88(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
void func_ov000_021c403c(void *list, s32 a);
BOOL func_ov002_021d0a80(void *self, void *arg);

typedef struct {
    u16 a;
    u16 b;
} Pair021d0b98;

void func_ov002_021d0b98(Task021ef89c *self) {
    void *g = data_02149ef8;
    UiObj *p;
    {
        p = (UiObj *)Heap_Alloc(0xf4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->vfunc_28();
            *(VFunc **)p = data_ov000_021ccbe0;
            func_ov000_021c3af4(p);
        }
        self->unk_3c = (Ov002RowList *)p;
        p->rows = 7;
    }
    self->unk_3c->width = 0xf9;
    {
        UiObj *s = self->unk_3c;
        s->posX = 4;
        s->posY = 0x23;
        s->posZ = -0x199a;
    }
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xeb));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xed));
    self->unk_3c->onDecide = (void *)func_ov002_021d0a80;
    {
        u16 i;
        u8 *base;
        void *tbl;
        u16 id;
        u8 *q;
        u32 count;
        base = data_02fe152c->data + 0x10 + 9 * 0x20;
        tbl = func_0205976c(data_02fe152c, 9);
        count = func_0205975c(data_02fe152c, 9);
        for (i = 0; i < count; i++) {
            if (func_02059544(data_02fe152c, base, tbl, 0x101, i)) {
                q = (u8 *)Heap_Alloc(0x48);
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov000_021cca10;
                    func_ov000_021c2334(q);
                }
                FIELD(q, 0x4, s32) = i;
                FIELD(q, 0x3c, s32) = (u16)(i + 1);
                id = ((Pair021d0b98 *)func_0205976c(data_02fe152c, 9))[i].b | 0x5000;
                func_ov000_021c2a88(q, func_0206ec48(id));
                FIELD(q, 0x8, s32) = id;
                func_ov000_021c3fd4(self->unk_3c, q);
            }
        }
    }
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    func_ov000_021c403c(self->unk_3c, data_ov002_021f0f84[1]);
    self->unk_3c->flags &= ~2;
    {
        p = (UiObj *)Heap_Alloc(0xe0);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->vfunc_28();
            *(VFunc **)p = data_ov000_021caec8;
            p->vfunc_28();
            *(VFunc **)p = data_ov000_021cb5a8;
            p->vfunc_28();
        }
        self->unk_40 = (Lo021cb5a8 *)p;
        p->flags |= 0x4000000;
    }
    self->unk_40->slideMode = 1;
    {
        Lo021cb5a8 *s = self->unk_40;
        s->slideX = -0x200;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_40->flags |= 0x20000000;
    self->unk_40->flags |= 0x80000000;
    self->unk_40->vfunc_f4(1, MsgRes_GetString(g, 0x39));
    self->unk_40->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_40->vfunc_08();
    self->unk_40->flags &= ~2;
}

}
