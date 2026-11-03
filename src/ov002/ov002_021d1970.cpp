#include "ov002/ov002.h"

extern "C" {

extern VFunc Lo021cb5a8_vtbl[];
extern VFunc Ov000Vt_021ccadc_vtbl[];
extern VFunc Ov000Vt_021cca70_vtbl[];
extern VFunc Ov002Vt_021ef674_vtbl[];
void func_ov000_021c6140(TextList *self);
void ListRow_Init(void *self);
void func_ov000_021c2208(void *self);
void func_ov000_021c2f10(void *self);
void func_ov000_021c308c(void *self, u16 id);
void List021c6474_Append(TextList *self, ListRow *row);
void TextList_SelectByKey(TextList *self, s32 index);
u16 func_0206f788(u16 id);
void *func_0206eed0(u16 id);
BOOL Task021ef69c_List3cOnCursor(TextList *self, ListRow021cca70 *row);
BOOL Task021ef69c_List3cOnDecide(TextList *self, ListRow021cca70 *ev);

typedef struct {
    u16 a;
    u16 b;
} Pair021d1970;

void Task021ef69c_Start(Task021ef69c *self) {
    void *g;
    UiObj *p;
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    g = gMsgRes;
    p = (UiObj *)Heap_Alloc(0xd4);
    if (p != NULL) {
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Ov000Vt_021ccadc_vtbl;
        func_ov000_021c6140((TextList *)p);
    }
    self->unk_3c = (TextList *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(g, 0xee));
    self->unk_3c->vfunc_14(MsgRes_GetString(g, 0xf0));
    self->unk_3c->posZ = -0x199a;
    self->unk_3c->listFlags.showCursor = 1;
    self->unk_3c->listFlags.wrap = 1;
    self->unk_3c->panelWidth = 0xf0;
    {
        u16 i;
        u16 id;
        ListRow021cca70 *q;
        Pair021d1970 *tbl;
        u32 count;
        tbl = (Pair021d1970 *)DataRes_GetTable(gDataRes, 11);
        count = DataRes_GetCount(gDataRes, 11);
        for (i = 0; i < count; i++) {
            id = tbl[i].b;
            if (func_0206f788(id)) {
                func_0206eed0(id);
                q = (ListRow021cca70 *)Heap_Alloc(sizeof(ListRow021cca70));
                if (q != NULL) {
                    *(VFunc **)q = Ov002Vt_021ef684_vtbl;
                    ListRow_Init(q);
                    *(VFunc **)q = Ov000Vt_021cca70_vtbl;
                    *(VFunc **)&q->item = Ov002Vt_021ef674_vtbl;
                    func_ov000_021c2208(&q->item);
                    func_ov000_021c2f10(q);
                }
                q->index = ((u32)tbl[i].b << 4) >> 16;
                func_ov000_021c308c(q, id);
                q->unk_44 = i + 1;
                q->unk_40 = Param_Get(id);
                List021c6474_Append(self->unk_3c, q);
            }
        }
    }
    self->unk_3c->onCursor = (TextListFn)Task021ef69c_List3cOnCursor;
    self->unk_3c->onDecide = (TextListFn)Task021ef69c_List3cOnDecide;
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    TextList_SelectByKey(self->unk_3c, data_ov002_021f0f84[2]);
    Obj021c64b4_SetText(self->unk_3c, ((ListRow021cca70 *)self->unk_3c->cur)->unk_40);
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
    TaskList_Insert(self);
}

}
