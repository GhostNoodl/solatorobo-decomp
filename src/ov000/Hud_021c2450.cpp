#include "ov000/TaskList.h"
#include "Main/Gfx/FieldMsg.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u32 b0 : 2;
    u32 lay : 5;
    u32 rest : 25;
} MdlFlags021c2450;

extern "C" {
extern char *data_0208cc88;
extern char *data_0208cc94;
extern char *data_0208cb7c;
extern char data_0214b105[];
extern char data_ov000_021cc9bc[];
void func_02041c5c(Model *m, void *fn);
void *func_ov000_021c7608(u8 *self, u16 *cmd, void *arr, u16 *count);

static inline BOOL Txt_IsVis021c2450(TextWin *t) {
    return t->rendering ? TRUE : FALSE;
}

static inline void SetText021c2450(Hud021cca10 *self, char *str0) {
    TextWin *t;
    char *str = str0;
    if (self->text == NULL) {
        t = (TextWin *)Heap_Alloc(0xb8);
        if (t != NULL) {
            VOBJ_SET_VTABLE(t, data_0208ba70);
            func_0204c7d0(t);
        }
        self->text = t;
    }
    self->text->unk_vf08();
    self->text->font = 8;
    t = self->text;
    t->str = (u32)str;
    t->unk_4c = Text_Measure(t->font, t->spacing, t->str, &t->width, &t->height, (s8)t->unk_37 != 0);
    data_02097ce0->unk_004 = t->font;
    self->text->unk_4_8 = 0x1e;
    self->text->unk_vf14();
    self->text->flags |= 0x40;
    self->text->flags |= 0x1000000;
    self->text->flags |= 0x400000;
    self->text->flags |= 0x200000;
    self->text->flags |= 0x4;
    self->str = str;
}

void func_ov000_021c2450(Hud021cca10 *self) {
    Model *m;
    Model *m2;
    if (self->built == 0) {
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            char *name = data_0208cc94;
            char *a = data_0208cc88;
            func_02041218(&m->pltt);
            func_02041440(m, a, 0);
            STD_CopyString(m->name, name);
        }
        self->unk_30 = m;
        func_020417e0(self->unk_30, func_02034d88(func_02035d5c(m->name), self->unk_30->unk_04c));
        self->unk_30->flags |= 2;
        func_02041d9c(self->unk_30, 0, 6);
        func_02041c20(self->unk_30, 6, (void *)self->unk_3c);
        func_02041c5c(self->unk_30, (void *)func_ov000_021c7608);
        self->unk_30->flags |= 0x80000;
        ((MdlFlags021c2450 *)&self->unk_30->flags)->lay = 0x1e;
        self->unk_30->flags |= 0x100000;

        m2 = (Model *)Heap_Alloc(sizeof(Model));
        if (m2 != NULL) {
            char *a = data_0208cb7c;
            func_02041218(&m2->pltt);
            func_02041440(m2, a, 0);
            STD_CopyString(m2->name, data_0214b105);
        }
        self->unk_34 = m2;
        func_020417e0(self->unk_34, func_02034d88(func_02035d5c(m2->name), self->unk_34->unk_04c));
        self->unk_34->flags |= 2;
        func_02041d9c(self->unk_34, 0, 4);
        self->unk_34->flags |= 0x80000;
        ((MdlFlags021c2450 *)&self->unk_34->flags)->lay = 0x1e;
        self->unk_34->flags |= 0x100000;
        if (self->text == NULL) {
            SetText021c2450(self, data_ov000_021cc9bc);
        }
        self->built = 1;
        return;
    }
    if (self->shown) {
        if (Txt_IsVis021c2450(self->text)) {
            return;
        }
        SetText021c2450(self, self->str);
    } else {
        if (!Txt_IsVis021c2450(self->text)) {
            return;
        }
        self->text->unk_vf08();
        self->text->rendering = 0;
    }
}
}
