#include "ov000/VObj.h"

class Win0217bd88 : public VObj {
public:
    u8 pad04[8];
    u32 flags;
    u8 pad10[0xc];
    s32 unk_1c;
    u8 pad20[0x28];
    u16 unk_48;
    u8 pad4a[0xa];
    s32 unk_54;
    u8 pad58[0x10];
    s16 unk_68;
};

typedef struct {
    u8 pad[0x64];
    Win0217bd88 *win;
    s32 timer;
} Obj0217bd88;

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void *func_0204c0e8(void *a, u16 b);
void *func_0203dd9c(u32 size);
void func_ov000_0215c1bc(Win0217bd88 *w, s32 a, void *b);
void func_ov000_0215ce8c(Win0217bd88 *w, s32 a);

static inline BOOL Win_IsHidden(Win0217bd88 *w) {
    return (w->flags & 0x10000) == 0 ? TRUE : FALSE;
}

BOOL func_ov000_0217bd88(Obj0217bd88 *self, s32 a, s32 id) {
    Win0217bd88 *w;
    if (self->win != NULL) {
        BOOL busy = FALSE;
        if (self->timer != 0) {
            busy = TRUE;
        }
        if (self->win != NULL && Win_IsHidden(self->win)) {
            busy = TRUE;
        }
        if (!busy) {
            self->win->flags |= 0x40000;
        }
        return FALSE;
    }
    self->timer = 0x3c;
    w = (Win0217bd88 *)func_0203dd9c(0xe8);
    if (w != NULL) {
        VOBJ_SET_VTABLE(w, data_ov000_021cac60);
        w->vfunc_28();
        VOBJ_SET_VTABLE(w, data_ov000_021cad50);
        w->vfunc_28();
    }
    self->win = w;
    if (id == 0x6f || id == 0x74 || id == 0x86 || id == 0x82 || id == 0x84 || id == 0x75 || id == 0x76 || id == 0x6d) {
        self->win->flags |= 0x10000;
    } else {
        w->flags &= ~0x10000;
    }
    w = self->win;
    w->flags |= 8;
    w->unk_48 = 0x14a5;
    w->unk_54 = 0x1c;
    self->win->flags |= 0x20000;
    self->win->unk_1c = 4;
    self->win->vfunc_08();
    if (id != -1) {
        func_ov000_0215c1bc(self->win, 0x8000, func_0204c0e8(data_02149ef8, id));
    } else {
        func_ov000_0215ce8c(self->win, a);
    }
    self->win->unk_68 = -0x199a;
    self->win->vfunc_70();
    return TRUE;
}

}
