#include "ov002/ov002.h"

extern "C" {

extern VFunc Lo021cb5a8_vtbl[];
extern VFunc Hud021cca10_vtbl[];
void LoBase021ccb54_021ccbe0_CtorBase(void *self);
void ListRow_Init(void *self);
void Hud021cca10_Init(void *self);
void Hud021cca10_SetText(void *self, void *a);
void LoBase021ccb54_021ccbe0_AppendRow(void *list, void *item);
void LoBase021ccb54_021ccbe0_Select(void *list, s32 a);
BOOL func_ov002_021d0a80(Ov002RowList *self, Hud021cca10 *arg);

typedef struct {
    u16 a;
    u16 b;
} Pair021d0b98;

void func_ov002_021d0b98(Task021ef89c *self) {
    void *g = gMsgRes;
    UiObj *p;
    {
        p = (UiObj *)Heap_Alloc(0xf4);
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Ov000Vt_021ccbe0_vtbl;
            LoBase021ccb54_021ccbe0_CtorBase(p);
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
        Hud021cca10 *q;
        u32 count;
        base = gDataRes->data + 0x10 + 9 * 0x20;
        tbl = DataRes_GetTable(gDataRes, 9);
        count = DataRes_GetCount(gDataRes, 9);
        for (i = 0; i < count; i++) {
            if (DataRes_ReadBitsAt_02059544(gDataRes, base, tbl, 0x101, i)) {
                q = (Hud021cca10 *)Heap_Alloc(sizeof(Hud021cca10));
                if (q != NULL) {
                    *(VFunc **)q = Ov002Vt_021ef684_vtbl;
                    ListRow_Init(q);
                    *(VFunc **)q = Hud021cca10_vtbl;
                    Hud021cca10_Init(q);
                }
                q->index = i;
                q->unk_3c = (u16)(i + 1);
                id = ((Pair021d0b98 *)DataRes_GetTable(gDataRes, 9))[i].b | 0x5000;
                Hud021cca10_SetText(q, Param_Get(id));
                q->unk_08 = id;
                LoBase021ccb54_021ccbe0_AppendRow(self->unk_3c, q);
            }
        }
    }
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    LoBase021ccb54_021ccbe0_Select(self->unk_3c, data_ov002_021f0f84[1]);
    self->unk_3c->flags &= ~2;
    {
        p = (UiObj *)Heap_Alloc(0xe0);
        if (p != NULL) {
            *(VFunc **)p = UiObj_vtbl;
            p->vfunc_28();
            *(VFunc **)p = UiList_vtbl;
            p->vfunc_28();
            *(VFunc **)p = Lo021cb5a8_vtbl;
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
