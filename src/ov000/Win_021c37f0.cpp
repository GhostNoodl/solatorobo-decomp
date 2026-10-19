#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

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
    VObj *win;
    s32 unk_34;
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
void *func_0203dd9c(u32 size);
void func_ov000_02158c60(VObj *w, void *a);
s32 func_ov000_02154b58(VObj *w, u16 a);

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
        VObj *p = (VObj *)func_0203dd9c(0xf0);
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
        LFLD(s32, p, 0x24) = self->unk_1c;
        LFLD(s32, self->win, 0x20) = 7;
        LFLD(u16, self->win, 0x48) = 0;
        LFLD(s32, self->win, 0x34) = 0x1000;
        LFLD(s32, self->win, 0x2c) = 1;
        LFLD(s32, self->win, 0xe0) = self->unk_34;
        func_ov000_02158c60(self->win, self->unk_38);
        self->win->vfunc_08();
        {
            VObj *w = self->win;
            w->vfunc_a8(func_ov000_02154b58(w, self->unk_40));
        }
        SetVec((s32 *)((u8 *)self->win + 0x58), 0, 0, 0);
        LFLD(u32, self->win, 0xc) &= ~0x10;
        LFLD(u32, self->win, 0xc) &= ~2;
        self->state = 20;
        break;
    }
    case 20:
        LFLD(u32, self->win, 0xc) &= ~4;
        self->state++;
    case 21:
        if (!self->flags.b1) {
            void *o = LFLD(void *, self->win, 0x98);
            s32 v = o != NULL ? LFLD(s16, o, 4) : 0;
            if (v < 0) {
                v = 0;
            }
            self->unk_40 = v;
            func_ov000_02158c60(self->win, data_ov000_021cc9e8);
            LFLD(u32, self->win, 0xc) |= 4;
            self->state = 30;
        }
        self->win->vfunc_1c();
        break;
    case 30:
        if (!self->flags.b0) {
            HEAP_DELETE_VOBJ(self->win);
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
