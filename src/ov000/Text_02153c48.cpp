#include "ov000/LoCommon.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u32 b0 : 8;
    u32 f8 : 5;
    u32 rest : 19;
} TwBits02153c48;

extern "C" {
extern u8 data_0208ba70[];
extern void *data_02149ef8;
void TextWin_Init(void *p);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void TextWin_RenderToVram(void *p);

static inline TextWin *NewTw02153c48(void) {
    TextWin *o = (TextWin *)Heap_Alloc(sizeof(TextWin));
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        TextWin_Init(o);
    }
    return o;
}

struct Obj02153c48 {
    s32 unk_00;
    u8 unk_04[0x8];
    s32 unk_0c;
    u8 unk_10[0xc];
    TextWin *unk_1c;
    TextWin *unk_20;
    s32 unk_24;
};

void Obj02153c48_CreateText(Obj02153c48 *self, s32 a, BOOL show, BOOL center, u8 d) {
    TextWin *w;
    LO_FREE_V(self, 0x1c);
    LO_FREE_V(self, 0x20);
    w = NewTw02153c48();
    self->unk_1c = w;
    if (d) {
        w->unk_37 = 1;
    }
    self->unk_1c->font = a;
    self->unk_1c->unk_2c = self->unk_24;
    w = self->unk_1c;
    w->str = self->unk_00;
    w->unk_4c = Text_Measure(w->font, w->spacing, w->str, &w->width, &w->height, (s8)w->unk_37 ? 1 : 0);
    data_02097ce0->unk_004 = ((s32)w->font);
    self->unk_1c->unk_4_8 = 0x1e;
    if (center) {
        self->unk_1c->unk_36 = 1;
    }
    self->unk_1c->flags |= 0x40;
    self->unk_1c->flags |= 0x1000000;
    self->unk_1c->flags |= 0x400000;
    self->unk_1c->flags |= 0x40000000;
    self->unk_1c->flags |= 4;
    if (show) {
        TextWin_RenderToVram(self->unk_1c);
    }
    if (!(self->unk_0c == -1 ? TRUE : FALSE)) {
        return;
    }
    {
        void *fnt = data_02149ef8;
        w = NewTw02153c48();
        self->unk_20 = w;
        w->font = 4;
        self->unk_20->unk_2c = 0xe;
        {
            s32 t = MsgRes_GetString(fnt, 0xa0);
            w = self->unk_20;
            w->str = t;
        }
    }
    w->unk_4c = Text_Measure(w->font, w->spacing, w->str, &w->width, &w->height, (s8)w->unk_37 ? 1 : 0);
    data_02097ce0->unk_004 = ((s32)w->font);
    self->unk_20->unk_4_8 = 0x1e;
    self->unk_20->flags |= 0x40;
    self->unk_20->flags |= 0x1000000;
    self->unk_20->flags |= 0x400000;
    self->unk_20->flags |= 0x40000000;
    self->unk_20->flags |= 4;
    if (show) {
        TextWin_RenderToVram(self->unk_20);
    }
}

}
