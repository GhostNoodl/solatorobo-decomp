#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_02149ef8;
extern void *data_0208cc88;
extern void *data_0208cc94;
void *MsgRes_GetString(void *a, s32 b);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041c5c(void *model, void *fn);
void *func_ov000_021c5a0c(u8 *self, u16 *cmd, void *arr, u16 *count);

void func_ov000_021c5bd4(Lo021cca40 *self) {
    void *res;
    TextWin *p;
    u8 *m;
    if (self->unk_44 != 0) {
        return;
    }
    res = data_02149ef8;
    p = (TextWin *)Heap_Alloc(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    self->unk_30 = p;
    p->font = 8;
    {
        void *t = self->unk_38;
        if (t == NULL) {
            t = MsgRes_GetString(res, 0x50);
        }
        p = self->unk_30;
        p->str = (u32)t;
    }
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->unk_30->unk_2c = 0;
    self->unk_30->flags |= 0x40;
    self->unk_30->flags |= 0x1000000;
    self->unk_30->flags |= 0x400000;
    self->unk_30->flags |= 0x4;
    m = (u8 *)Heap_Alloc(0x160);
    if (m != NULL) {
        void *arc;
        void *name;
        name = data_0208cc88;
        arc = data_0208cc94;
        func_02041218((struct PlttRes *)(m + 0x88));
        func_02041440((Model *)m, (const char *)name, 0);
        STD_CopyString((char *)m + 0x2c, (const char *)arc);
    }
    self->unk_34 = (Model *)(m);
    func_020417e0(self->unk_34, func_02034d88(func_02035d5c(m + 0x2c), (u8 *)self->unk_34 + 0x4c));
    self->unk_34->flags |= 2;
    func_02041d9c(self->unk_34, 0, 6);
    func_02041d9c(self->unk_34, 0, 7);
    func_02041c5c((u8 *)self->unk_34, (void *)func_ov000_021c5a0c);
    self->unk_44 = 1;
}

}

