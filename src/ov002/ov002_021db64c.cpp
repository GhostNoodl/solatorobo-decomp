#include "ov002/ov002.h"

extern "C" {

void Obj021eff50_Release(Obj021eff50 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_18);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_20);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_24);
    HEAP_POP(saved);
}


extern VFunc Lo021cadcc_vtbl[];

extern VFunc Lo021cae48_vtbl[];

extern Ov002SndCue data_ov002_021ef016[];

extern u8 data_ov002_021efe30[];

void Lo021cae48_SetValue(void *a, u16 b, int c);

void Model0218fe1c_ClearReverse(void *a);

void *Model0218fe1c_GetAnimCtrl(void *a, int b);

void func_ov002_021db750(Obj021eff50 *self) {
    UiObj *o;
    UiObj *o2;
    void *g = gMsgRes;
    UiObj *s;
    Ov002SndCue *e;
    Obj021efe4c *p;
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = UiObj_vtbl;
        o->vfunc_28();
        *(VFunc **)o = Lo021cadcc_vtbl;
        o->vfunc_28();
    }
    self->unk_20 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_20->rows = 2;
    s = self->unk_20;
    s->posX = 4;
    s->posY = 0x97;
    s->posZ = -0x666;
    s = self->unk_20;
    s->slideX = -0x100;
    s->slideY = 0;
    s->slideZ = -0x666;
    self->unk_20->slideMode = 1;
    self->unk_20->vfunc_10(MsgRes_GetString(g, 0xbc));
    self->unk_20->vfunc_14(MsgRes_GetString(g, 0x10a));
    Obj0215bb14_SetText(self->unk_20, data_ov002_021efe30);
    self->unk_20->vfunc_08();
    self->unk_20->vfunc_70();
    self->unk_20->flags &= ~2;
    o2 = (UiObj *)Heap_Alloc(0x98);
    if (o2 != NULL) {
        *(VFunc **)o2 = UiObj_vtbl;
        o2->vfunc_28();
        *(VFunc **)o2 = Lo021cae48_vtbl;
        o2->vfunc_28();
    }
    self->unk_24 = (Lo021cae48 *)o2;
    o2->posX = 0x9c;
    o2->posY = 0x88;
    o2->posZ = -0x1666;
    s = self->unk_24;
    s->slideX = 0x100;
    s->slideY = 0;
    s->slideZ = -0x1666;
    self->unk_24->slideMode = 1;
    self->unk_24->style = 3;
    Lo021cae48_SetValue(self->unk_24, ((u16)self->board->unk_8a), 0);
    self->unk_24->vfunc_08();
    self->unk_24->flags &= ~2;
    {
        Ov002Shape *b = self->board->field->map;
        s32 lo = b->ox;
        s32 hi = b->oy;
        self->unk_28 = lo;
        self->unk_2c = hi;
    }
    p = self->board->field;
    if (p->unk_5d == 0) {
        s32 val = 0;
        s32 *q;
        Model0218fe1c_ClearReverse(p->unk_10);
        e = data_ov002_021ef016;
        p->cues = e;
        q = *(s32 **)Model0218fe1c_GetAnimCtrl(p->unk_10, 0);
        if (q != NULL) {
            val = *q;
        }
        while (e->time < (val >> 12)) {
            if (e->time < 0) {
                break;
            }
            e++;
        }
        p->cue = e;
        p->unk_5d = 1;
        self->unk_34 = 0x3c;
    }
}

}
