#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags021c37f0;

typedef struct {
    u8 pad_00[0x1c];
    s32 unk_1c;
    Flags021c37f0 flags;
    u8 pad_21[0xf];
    Lo021cb3a8 *win;
    char *unk_34;
    void *unk_38;
    s32 state;
    u16 unk_40;
} Obj021c37f0;

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021cc9e8[];
void *Heap_Alloc(u32 size);
void func_ov000_02158c60(Lo021cb3a8 *w, void *a);
UiListItem *func_ov000_02154b58(UiList *w, u16 a);

static inline void SetVec(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

void func_ov000_021c37f0(Obj021c37f0 *self) {
    switch (self->state) {
    case 0:
        if (!self->flags.b0) {
            return;
        }
        self->state = 10;
    case 10: {
        Lo021cb3a8 *p = (Lo021cb3a8 *)Heap_Alloc(sizeof(Lo021cb3a8));
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, data_ov000_021cac60);
            p->vfunc_28();
            VOBJ_SET_VTABLE(p, data_ov000_021caec8);
            p->vfunc_28();
            VOBJ_SET_VTABLE(p, data_ov000_021cb4a8);
            p->vfunc_28();
            VOBJ_SET_VTABLE(p, data_ov000_021cb3a8);
            p->vfunc_28();
        }
        self->win = p;
        p->width = self->unk_1c;
        self->win->rows = 7;
        self->win->color = 0;
        self->win->openLen = 0x1000;
        self->win->slideMode = 1;
        self->win->srcStr = self->unk_34;
        func_ov000_02158c60(self->win, self->unk_38);
        self->win->vfunc_08();
        {
            Lo021cb3a8 *w = self->win;
            w->vfunc_a8(func_ov000_02154b58(w, self->unk_40));
        }
        SetVec(&self->win->slideX, 0, 0, 0);
        self->win->flags &= ~0x10;
        self->win->flags &= ~2;
        self->state = 20;
        break;
    }
    case 20:
        self->win->flags &= ~4;
        self->state++;
    case 21:
        if (!self->flags.b1) {
            UiListItem *o = self->win->topItem;
            s32 v = o != NULL ? o->index : 0;
            if (v < 0) {
                v = 0;
            }
            self->unk_40 = v;
            func_ov000_02158c60(self->win, data_ov000_021cc9e8);
            self->win->flags |= 4;
            self->state = 30;
        }
        self->win->vfunc_1c();
        break;
    case 30:
        if (!self->flags.b0) {
            HEAP_DELETE(Lo021cb3a8 *, self->win, p->vfunc_04());
            self->state = 0;
        }
        if (self->flags.b1) {
            func_ov000_02158c60(self->win, self->unk_38);
            self->state = 20;
        }
        break;
    }
}
}
