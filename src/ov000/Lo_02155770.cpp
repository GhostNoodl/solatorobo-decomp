#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/Pad.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
BOOL func_ov000_021521ec(void *self, void *msg);

static inline void Lo_OpenSub02155770(UiList *self, u16 a, s32 b, UiItemFn c) {
    void *res = data_02149ef8;
    Lo021cb0b8 *p;
    p = (Lo021cb0b8 *)Heap_Alloc(sizeof(Lo021cb0b8));
    if (p) {
        *(void **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(void **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb1b0;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb0b8;
        p->vfunc_28();
    }
    self->child = p;
    p->msgId = a;
    ((Lo021cb0b8 *)self->child)->text = (char *)MsgRes_GetString(res, b);
    ((Lo021cb0b8 *)self->child)->key = 0;
    ((Lo021cb0b8 *)self->child)->owner = self->owner;
    ((Lo021cb0b8 *)self->child)->onDecide = c;
    self->child->vfunc_08();
    ((Lo021cb0b8 *)self->child)->posZ = self->posZ + 0x200;
    self->busy = 1;
}

static inline BOOL Lo_Active02155770(UiList *self) {
    return self->busy ? FALSE : TRUE;
}

static inline BOOL Lo_Settled02155770(UiList *self) {
    BOOL r = FALSE;
    if (self->topItem == self->unk_a4 && self->unk_b3 == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy02155770(UiList *self) {
    return Lo_Settled02155770(self) ? FALSE : TRUE;
}

void func_ov000_02155770(UiList *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active02155770(self)) {
        return;
    }
    if (self->topItem == self->unk_a4 && self->hidden) {
        self->busy = 1;
        self->state = 1;
        return;
    }
    if (self->flag2) {
        return;
    }
    if (self->hidden) {
        return;
    }
    cont = data_02097dc8->cur;
    trig = data_02097dc8->trig;
    if (self->items != NULL) {
        if (cont == 0) {
            self->unk_b3 = 0;
        }
        self->unk_b2--;
        if (self->unk_9e == 0) {
            if (self->unk_b2 < (self->unk_b3 >> 1)) {
                self->unk_b2 = 0;
                if (cont & 0x40) {
                    self->vfunc_ac(1, 0);
                } else if (cont & 0x80) {
                    self->vfunc_b4(1, 0);
                } else {
                    if (self->itemCount > self->rows && (self->flags & 0x10000)) {
                        if (cont & 0x200) {
                            self->vfunc_b0(self->rows, 0);
                        } else if (cont & 0x100) {
                            self->vfunc_b8(self->rows, 0);
                        }
                    }
                    self->unk_b3 = 0;
                }
            } else if (trig & 3) {
                self->unk_b3 = 0;
            }
        }
    }
    if (Lo_Busy02155770(self)) {
        return;
    }
    if (self->items != NULL && (trig & 1)) {
        UiListItem *item = self->topItem;
        if (item == NULL) {
            item = NULL;
        } else {
            s32 n = self->cursor;
            while (n-- != 0) {
                item = item->next;
            }
        }
        if (!self->vfunc_98(item)) {
            self->flags |= 2;
        }
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            self->flags |= 2;
        }
        return;
    }
    if (self->items == NULL) {
        return;
    }
    if (!(trig & 0x400) || self->unk_8c == NULL) {
        return;
    }
    Lo_OpenSub02155770(self, 0x8f, 0x18, (UiItemFn)func_ov000_021521ec);
    self->unk_90 = self->unk_8c;
}

}
