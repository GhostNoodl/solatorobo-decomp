#include "ov002/ov002.h"

extern "C" {

void func_ov002_021db64c(Obj021eff50 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x18, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x20, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x24, VObj *));
    HEAP_POP(saved);
}

typedef struct B750 { u16 a : 4; u16 b : 4; u16 rest : 8; } B750;

extern VFunc data_ov000_021cadcc[];

extern VFunc data_ov000_021cae48[];

extern s16 data_ov002_021ef016[];

extern u8 data_ov002_021efe30[];

void func_ov000_0215d980(void *a, u16 b, int c);

void func_ov000_021917f8(void *a);

void *func_ov000_02190a30(void *a, int b);

void func_ov002_021db750(Obj021eff50 *self) {
    UiObj *o;
    UiObj *o2;
    void *g = data_02149ef8;
    u8 *s;
    s16 *e;
    u8 *p;
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_20 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_20->rows = 2;
    s = ((u8 *)self->unk_20);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x97;
    FIELD(s, 0x68, s16) = -0x666;
    s = ((u8 *)self->unk_20);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x666;
    self->unk_20->slideMode = 1;
    self->unk_20->vfunc_10(MsgRes_GetString(g, 0xbc));
    self->unk_20->vfunc_14(MsgRes_GetString(g, 0x10a));
    func_ov000_0215bb14(self->unk_20, data_ov002_021efe30);
    self->unk_20->vfunc_08();
    self->unk_20->vfunc_70();
    self->unk_20->flags &= ~2;
    o2 = (UiObj *)Heap_Alloc(0x98);
    if (o2 != NULL) {
        *(VFunc **)o2 = data_ov000_021cac60;
        o2->vfunc_28();
        *(VFunc **)o2 = data_ov000_021cae48;
        o2->vfunc_28();
    }
    self->unk_24 = (Lo021cae48 *)o2;
    o2->posX = 0x9c;
    o2->posY = 0x88;
    o2->posZ = -0x1666;
    s = ((u8 *)self->unk_24);
    FIELD(s, 0x58, s32) = 0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x1666;
    self->unk_24->slideMode = 1;
    self->unk_24->unk_84 = 3;
    func_ov000_0215d980(self->unk_24, ((u16)self->board->unk_8a), 0);
    self->unk_24->vfunc_08();
    self->unk_24->flags &= ~2;
    {
        B750 *b = &FIELD(FIELD(((void *)self->board->field), 0x6c, void *), 0x6, B750);
        s32 lo = b->a;
        s32 hi = b->b;
        self->unk_28 = lo;
        self->unk_2c = hi;
    }
    p = ((u8 *)self->board->field);
    if (FIELD(p, 0x5d, u8) == 0) {
        s32 val = 0;
        s32 *q;
        func_ov000_021917f8(FIELD(p, 0x10, void *));
        e = data_ov002_021ef016;
        FIELD(p, 0x60, s16 *) = e;
        q = *(s32 **)func_ov000_02190a30(FIELD(p, 0x10, void *), 0);
        if (q != NULL) {
            val = *q;
        }
        while (e[0] < (val >> 12)) {
            if (e[0] < 0) {
                break;
            }
            e += 3;
        }
        FIELD(p, 0x64, s16 *) = e;
        FIELD(p, 0x5d, u8) = 1;
        self->unk_34 = 0x3c;
    }
}

}
