#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb3a8[];
extern u8 data_ov000_021cc9e8[];
void *Heap_Alloc(u32 size);
void Lo021cb3a8_SetText(Lo021cb3a8 *w, void *a);
UiListItem *UiList_GetItemById(UiList *w, u16 a);

static inline void SetVec(s32 *v, s32 x, s32 y, s32 z) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

void func_ov000_021c37f0(ListRowText *self) {
    switch (self->state) {
    case 0:
        if (!self->shown) {
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
        p->width = self->width;
        self->win->rows = 7;
        self->win->color = 0;
        self->win->openLen = 0x1000;
        self->win->slideMode = 1;
        self->win->srcStr = self->unk_34;
        Lo021cb3a8_SetText(self->win, self->unk_38);
        self->win->vfunc_08();
        {
            Lo021cb3a8 *w = self->win;
            w->vfunc_a8(UiList_GetItemById(w, self->unk_40));
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
        if (!self->unk_20_1) {
            UiListItem *o = self->win->topItem;
            s32 v = o != NULL ? o->index : 0;
            if (v < 0) {
                v = 0;
            }
            self->unk_40 = v;
            Lo021cb3a8_SetText(self->win, data_ov000_021cc9e8);
            self->win->flags |= 4;
            self->state = 30;
        }
        self->win->vfunc_1c();
        break;
    case 30:
        if (!self->shown) {
            HEAP_DELETE(Lo021cb3a8 *, self->win, p->vfunc_04());
            self->state = 0;
        }
        if (self->unk_20_1) {
            Lo021cb3a8_SetText(self->win, self->unk_38);
            self->state = 20;
        }
        break;
    }
}
}
