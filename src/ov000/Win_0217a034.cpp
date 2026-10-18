#include "ov000/VObj.h"

class Win0217a034 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u8 pad0c[0x3c];
    u16 unk_48;
    u8 pad4a[0x1e];
    s16 unk_68;
    u8 pad6a[0x1a];
    void *cb;
    u8 pad88[0x154];
    void *unk_1dc;
    u16 unk_1e0;
};

typedef struct {
    u8 pad[0x4c];
    s32 unk_4c;
} Sub0217a034;

class Obj0217a034 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a034 *sub;
    u8 pad30[0xc];
    Win0217a034 *win;
    u8 pad40[4];
    u16 unk_44;
};

extern "C" {

extern void *data_02149ef8;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0204c0e8(void *a, s32 b);
void *func_0203dd9c(u32 size);
void *func_ov000_02154b58(Win0217a034 *w, s32 b);
void func_ov000_02175e6c(void);

BOOL func_ov000_0217a034(Obj0217a034 *self, s32 msg) {
    Sub0217a034 *sub = self->sub;
    Win0217a034 *w;
    void *a;
    void *b;
    switch (msg) {
    case 0: {
        void *res = data_02149ef8;
        a = func_0204c0e8(res, 0x1b);
        b = func_0204c0e8(res, 0x8d);
        w = (Win0217a034 *)func_0203dd9c(0x1e4);
        if (w != NULL) {
            VOBJ_SET_VTABLE(w, data_ov000_021cac60);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021caec8);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb1b0);
            w->vfunc_28();
            VOBJ_SET_VTABLE(w, data_ov000_021cb0b8);
            w->vfunc_28();
        }
        self->win = w;
        w->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = 1;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        w = self->win;
        w->vfunc_a8(func_ov000_02154b58(w, 0));
        w->unk_48 = 0x2803;
        break;
    }
    case 2:
        if (self->unk_44 == 0) {
            sub->unk_4c = self->unk_44;
            self->vfunc_0c(0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
