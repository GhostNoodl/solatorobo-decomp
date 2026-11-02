#include "ov002/ov002.h"

extern "C" {

typedef struct Fn021def98 {
    s32 (*fn)(void *, void *);
    u32 pad;
} Fn021def98;

typedef struct Id021def98 {
    u16 id;
    u8 pad[6];
} Id021def98;

extern Fn021def98 data_ov002_021eef8c[];
extern Id021def98 data_ov002_021eef90[];
extern VFunc data_ov002_021f0044[];

void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov002_021e2f54(Obj021f002c *self);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov002_021ddcbc(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev);
BOOL func_ov002_021ddd30(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev);
void func_ov002_021e34fc(void *self, s32 (*cmp)(void *, void *));

Ov002RowList *func_ov002_021def98(Obj021efef0 *self, u32 kind) {
    u16 id;
    s32 n;
    s32 j;
    Ov002RowList *p;
    Obj021f002c *q;
    s32 i;
    u8 *counts;
    p = (Ov002RowList *)Heap_Alloc(sizeof(Ov002RowList));
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021ccbe0;
        func_ov000_021c3af4(p);
        *(VFunc **)p = data_ov002_021f0044;
    }
    p->rows = 6;
    p->width = 0x8c;
    p->posX = 0x73;
    p->posY = 0x19;
    p->posZ = -0x199a;
    counts = self->owner->board->unk_08;
    for (i = 0; i < 100; i++) {
        id = i | 0x2000;
        u8 t = func_0206ede8(id)[0];
        if (t == kind) {
            n = counts[i];
            for (j = 0; j < n; j++) {
                q = (Obj021f002c *)Heap_Alloc(sizeof(Obj021f002c));
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov002_021f002c;
                    func_ov002_021e2f54(q);
                }
                q->id = id;
                q->str = func_0206ec48(id);
                q->hasModel = 1;
                func_ov000_021c3fd4(p, q);
            }
        }
    }
    p->owner = (u8 *)self + 0x22;
    p->onDecide = (void *)func_ov002_021ddcbc;
    p->onCursor = (void *)func_ov002_021ddd30;
    p->vfunc_08();
    p->slideX = 0x100;
    p->slideY = 0;
    p->slideZ = -0x199a;
    p->slideMode = 1;
    p->flags = ((p->flags | 2) & ~4) | 0x10;
    {
        s32 k = self->unk_34;
        void *r;
        Obj021eff50 *w;
        func_ov002_021e34fc(p, data_ov002_021eef8c[k].fn);
        r = MsgRes_GetString(data_02149ef8, data_ov002_021eef90[k].id);
        w = self->owner;
        func_ov000_0215bb14(((void *)w->unk_20), r);
        w->unk_20->vfunc_70();
    }
    return p;
}

}
