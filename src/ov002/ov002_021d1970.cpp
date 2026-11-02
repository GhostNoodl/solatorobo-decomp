#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021ccadc[];
extern VFunc data_ov000_021cca70[];
extern VFunc data_ov002_021ef674[];
void func_ov000_021c6140(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2208(void *self);
void func_ov000_021c2f10(void *self);
void func_ov000_021c308c(void *self, u16 id);
void func_ov000_021c6474(void *list, void *item);
void func_ov000_021c65e0(void *list, s32 a);
u16 func_0206f788(u16 id);
void *func_0206eed0(u16 id);
BOOL func_ov002_021d18d4(void *self, void *arg);
BOOL func_ov002_021d18e8(void *self, void *ev);

typedef struct {
    u16 a;
    u16 b;
} Pair021d1970;

void func_ov002_021d1970(Task021ef69c *self) {
    void *g;
    UiObj *p;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    p = (UiObj *)Heap_Alloc(0xd4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021ccadc;
        func_ov000_021c6140(p);
    }
    self->unk_3c = (Ov002TextList *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xee));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xf0));
    self->unk_3c->posZ = -0x199a;
    self->unk_3c->unk_c4 |= 2;
    self->unk_3c->unk_c4_0 = 1;
    self->unk_3c->unk_a4 = 0xf0;
    {
        u16 i;
        u16 id;
        ListRow021cca70 *q;
        Pair021d1970 *tbl;
        u32 count;
        tbl = (Pair021d1970 *)func_0205976c(data_02fe152c, 11);
        count = func_0205975c(data_02fe152c, 11);
        for (i = 0; i < count; i++) {
            id = tbl[i].b;
            if (func_0206f788(id)) {
                func_0206eed0(id);
                q = (ListRow021cca70 *)Heap_Alloc(sizeof(ListRow021cca70));
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov000_021cca70;
                    *(VFunc **)&q->item = data_ov002_021ef674;
                    func_ov000_021c2208(&q->item);
                    func_ov000_021c2f10(q);
                }
                q->index = ((u32)tbl[i].b << 4) >> 16;
                func_ov000_021c308c(q, id);
                q->unk_44 = i + 1;
                q->unk_40 = func_0206ec48(id);
                func_ov000_021c6474(self->unk_3c, q);
            }
        }
    }
    self->unk_3c->onCursor = (void *)func_ov002_021d18d4;
    self->unk_3c->onDecide = (void *)func_ov002_021d18e8;
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    func_ov000_021c65e0(self->unk_3c, data_ov002_021f0f84[2]);
    func_ov000_021c64b4(self->unk_3c, ((ListRow021cca70 *)self->unk_3c->unk_88)->unk_40);
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
    self->unk_40->slideMode = 1;
    self->unk_40->posZ = -0x199a;
    {
        Lo021cb5a8 *s = self->unk_40;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_40->flags |= 0x20000000;
    self->unk_40->flags |= 0x80000000;
    self->unk_40->vfunc_f4(1, MsgRes_GetString(g, 0x34));
    self->unk_40->vfunc_f4(2, MsgRes_GetString(g, 0x33));
    self->unk_40->vfunc_08();
    self->unk_5c = -0x100;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_60 = 0;
    self->unk_58 = -0x199a;
    self->unk_64 = -0x199a;
    func_ov000_02173648(self);
}

}
