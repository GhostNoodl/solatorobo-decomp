#include "ov000/VObj.h"

class Win0217a8f4 : public VObj {
public:
    void *owner_pad;
    void *owner;
    u32 unk_0c;
    u8 pad10[0x38];
    u16 unk_48;
    u8 pad4a[0xa];
    s32 unk_54;
    u8 pad58[0x10];
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
    u8 pad50[4];
    u32 unk_54;
} Sub0217a8f4;

class Obj0217a8f4 : public VObj {
public:
    u32 b0 : 1;
    u32 rest : 31;
    u8 pad08[0x24];
    Sub0217a8f4 *sub;
    u8 pad30[0xc];
    Win0217a8f4 *win;
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
void func_ov000_02175e6c(void);

BOOL func_ov000_0217a8f4(Obj0217a8f4 *self, s32 msg) {
    Sub0217a8f4 *sub = self->sub;
    s32 idx = sub->unk_4c;
    u16 lo = sub->unk_54;
    u16 hi = sub->unk_54 >> 16;
    Win0217a8f4 *w;
    void *a;
    void *b;
    s32 id;
    switch (msg) {
    case 0: {
        switch (idx) {
        case 1: id = 0x91; break;
        case 2: id = 0x92; break;
        case 3: id = 0x93; break;
        case 4: if (hi == 0) id = 0x94; else id = 0x95; break;
        default: id = 0x8d; break;
        }
        void *res = data_02149ef8;
        a = func_0204c0e8(res, 0x18);
        b = func_0204c0e8(res, id);
        w = (Win0217a8f4 *)func_0203dd9c(0x1e4);
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
        w->unk_0c |= 8;
        w->unk_48 = 0x14a5;
        w->unk_54 = 0x1c;
        self->win->vfunc_10(b);
        self->win->unk_1dc = a;
        self->win->unk_1e0 = lo;
        self->win->owner = self;
        self->win->cb = (void *)func_ov000_02175e6c;
        self->win->vfunc_08();
        self->win->unk_68 = -0x1666;
        self->b0 = 1;
        break;
    }
    case 1:
        break;
    case 2: {
        u16 c = self->unk_44;
        self->vfunc_0c(0);
        if (c == 0) {
            sub->unk_54 = c;
            self->vfunc_0c(0);
            return TRUE;
        }
        sub->unk_54 = -1;
        self->vfunc_0c(0);
        return FALSE;
    }
    }
    return FALSE;
}

}
