// ov000 .text 0x0217a26c..0x0217b324, part of the Menu translation unit (.text 0x021763c8..0x02180350,
// string pool 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash. The TU
// is split at the functions that do not match yet (0217a1f8, 0217b324); once they do,
// the three parts become one file and the pool can be claimed.
#include "ov000/LoCommon.h"
#include "ov000/VObj.h"

// ---- Lo_0217a26c
namespace m_Lo_0217a26c {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern u8 data_ov000_021cba18[];
extern u8 data_ov000_021cba3f[];
extern u8 data_ov000_021cba45[];
extern u8 data_ov000_021cba50[];
extern u16 *data_02097dc8;
extern void *data_02097e4c;
void func_0204bfcc(void *p);
void STD_CopyString(void *buf, const void *s);
void STD_ConcatenateString(void *buf, const void *s);
void func_0204bfe4(void *p, void *buf, const void *s);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov000_0217a26c(void *self) {
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = -1;
}

void func_ov000_0217a294(void *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x44);
}

}

}  // namespace m_Lo_0217a26c

// ---- Lo_0217a328
namespace m_Lo_0217a328 {

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern void *data_02149ef8;
void *func_0204c0e8(void *p, u16 a);
void func_ov000_0215c1bc(void *a, s32 b, void *c);
void func_ov000_0215ce8c(void *a, s32 b);

void func_ov000_0217a328(u8 *self, s32 a, s32 b) {
    if (LFLD(VObj *, self, 0x48) == NULL) {
        VObj *o = (VObj *)func_0203dd9c(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x48) = o;
    }
    if (a == 0x79 || b == 0x77) {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) |= 0x10000;
    } else {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) &= ~0x10000;
    }
    if (LFLD(s32, self, 0xc) != 1) {
        LFLD(u16, LFLD(VObj *, self, 0x48), 0x48) = 0x2803;
    } else {
        VObj *o = LFLD(VObj *, self, 0x48);
        LFLD(u32, o, 0xc) |= 8;
        LFLD(u16, o, 0x48) = 0x14a5;
        LFLD(s32, o, 0x54) = 0x1c;
    }
    LFLD(s32, LFLD(VObj *, self, 0x48), 0x1c) = 4;
    LFLD(VObj *, self, 0x48)->vfunc_08();
    if (b != -1) {
        func_ov000_0215c1bc(LFLD(VObj *, self, 0x48), 0x8000, func_0204c0e8(data_02149ef8, b));
    } else {
        func_ov000_0215ce8c(LFLD(VObj *, self, 0x48), a);
    }
    LFLD(s16, LFLD(VObj *, self, 0x48), 0x68) = -0x1ccd;
    LFLD(VObj *, self, 0x48)->vfunc_70();
}
}

}  // namespace m_Lo_0217a328

// ---- Stub_0217a478
namespace m_Stub_0217a478 {

extern "C" {

void func_ov000_0217a478(void) {
}

void func_ov000_0217a47c(void) {
}

}

}  // namespace m_Stub_0217a478

// ---- Lo_0217a480
namespace m_Lo_0217a480 {

typedef struct {
    u32 lo : 16;
    u32 b16 : 8;
    u32 hi : 8;
} W518_0217a480;

extern "C" {
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_0206c620(void *p);
void func_0206c670(void *p);
void func_ov000_0217a328(u8 *self, s32 a, s32 b);
BOOL func_ov000_0217a034(void *self, s32 msg);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);

static inline u8 Raw0217a480(u8 *g) {
    return LFLD(W518_0217a480, g, 0x518).b16;
}

static inline u8 Lvl0217a480(u8 *g) {
    return Raw0217a480(g) & ~0xc0;
}

static inline BOOL IsB1_0217a480(void *p) {
    return LBIT(p, 0x48).b1 ? TRUE : FALSE;
}

static inline BOOL IsB2_0217a480(void *p) {
    return LBIT(p, 0x48).b2 ? TRUE : FALSE;
}

void func_ov000_0217a480(u8 *self) {
    if (LFLD(VObj *, self, 0x48) != NULL && !LFLD(VObj *, self, 0x48)->vfunc_1c()) {
        LO_FREE_V(self, 0x48);
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_0c();
    }
    switch (LFLD(s32, self, 0x3c)) {
    case 0:
        if (LFLD(s32, self, 0xc) == 0) {
            if (LFLD(VObj *, self, 0x48) != NULL) {
                return;
            }
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217a034;
            ((VObj *)self)->vfunc_48();
            LFLD(s32, self, 0x3c) = 1;
        } else if (LFLD(s32, self, 0xc) == 1) {
            LFLD(s32, self, 0x3c) = 2;
        }
        break;
    case 1:
        if (LBIT(self, 4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x4c) != -1) {
            LFLD(s32, self, 0x3c) = 2;
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    case 2: {
        u8 *g;
        LFLD(u8, data_02097dd0, 0x31) = 1;
        LFLD(s32, self, 0x40) = 0;
        if (LFLD(s32, self, 0xc) == 0) {
            func_0206c620(data_0214a424);
        } else if (LFLD(s32, self, 0xc) == 1) {
            func_0206c670(data_0214a424);
        }
        LBIT(LFLD(void *, self, 0x44), 0x48).b0 = TRUE;
        LFLD(u32, LFLD(void *, self, 0x44), 0x48) |= 0x20;
        g = data_0214a424;
        if (Lvl0217a480(g) > 0x14) {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x210;
            LFLD(s32, q, 0x40) = n;
        } else {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x200;
            LFLD(s32, q, 0x40) = n;
        }
        func_ov000_0217a328(self, 0x79, -1);
        LFLD(s32, self, 0x3c) = 3;
        break;
    }
    case 3:
        LFLD(s32, self, 0x40)++;
        if (IsB1_0217a480(LFLD(void *, self, 0x44))) {
            if (LFLD(s32, self, 0x40) <= 0x3c) {
                return;
            }
            LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 0x40000;
            LFLD(s32, self, 0x3c) = 4;
        } else {
            if (!IsB2_0217a480(LFLD(void *, self, 0x44))) {
                return;
            }
            func_ov000_0217a328(self, 0x8000, 0x77);
            LFLD(s32, self, 0x3c) = 5;
        }
        break;
    case 4:
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        if (LFLD(s32, self, 0xc) == 0) {
            func_02049a48(data_02097e4c, 0x85, -1, -1, -1);
            func_ov000_0217a328(self, 0x7a, -1);
        }
        LFLD(s32, self, 0x3c) = 5;
        break;
    case 5:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    }
}

}

}  // namespace m_Lo_0217a480

// ---- Dtor_0217a88c
namespace m_Dtor_0217a88c {

extern "C" {

extern u8 data_ov000_021cbb60[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

void func_ov000_0217a86c(void *self) {
    VObj *obj = *(VObj **)((u8 *)self + 0x48);
    if (obj != NULL) {
        obj->vfunc_20();
    }
}

VObj *func_ov000_0217a88c(void) {
    VObj *obj = (VObj *)func_0203dd9c(0xc4);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbb60);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x8, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217a88c

// ---- Win_0217a8f4
namespace m_Win_0217a8f4 {

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

}  // namespace m_Win_0217a8f4

// ---- Lo_0217ab30
namespace m_Lo_0217ab30 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ab30(void *self) {
    VObj *obj = (VObj *)func_0203dd9c(0x4c);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_0208b318);
        obj->vfunc_08();
    }
    LFLD(VObj *, self, 0x3c) = obj;
    LFLD(s32, obj, 0x44) = 7;
    LFLD(VObj *, self, 0x3c)->vfunc_1c(data_0208cc9c);
}

BOOL func_ov000_0217ab8c(void *self) {
    BOOL r = TRUE;
    if (!LoTaskObj()->vfunc_2c()) {
        r = FALSE;
    }
    if (!LFLD(VObj *, self, 0x3c)->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}

}  // namespace m_Lo_0217ab30

// ---- Lo_0217abd8
namespace m_Lo_0217abd8 {

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void STD_CopyString(void *dst, void *src);
VObj *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    func_02041218(m + 0x88);
    func_02041440(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

class Model {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Model(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

void func_ov000_0217abd8(VObj *self) {
    u8 *m;
    VObj *o;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    {
        LoCreateFn fn = LFLD(LoCreateFn, data_ov000_021ccd34, 0x18);
        if (fn == NULL) {
            LFLD(LoCreateFn, data_ov000_021ccd34, 0x18) = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (VObj *)fn();
    }
    LFLD(VObj *, self, 0x5c) = o;
    o->vfunc_08();
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        ModelInit(m, data_0208cc9c, data_0208cb78);
    }
    LFLD(u8 *, self, 0xa0) = m;
    func_020417e0(LFLD(u8 *, self, 0xa0), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0xa0) + 0x4c));
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 1);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 2);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 3);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 4);
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) = (LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) & ~0x7c) | 0x78;
    func_ov000_02173648(self);
    LFLD(u32, self, 4) |= 0x10000;
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = 1;
        LFLD(s32, self, 0x48) = 0;
    }
}

}

}  // namespace m_Lo_0217abd8

// ---- Lo_0217ad54
namespace m_Lo_0217ad54 {

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbf60[];
extern void *data_0208cc9c;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_ov000_02154b58(void *p, s32 a);
void func_0206ecd4(s32 a, void *b, u16 c);
void func_ov000_0215bb14(void *a, void *b);
void func_0206f21c(u16 a, s32 b);
void func_020359d0(void *a, s32 b, s32 c);
s32 func_02035b90(void *a, s32 b);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

void func_ov000_0217ad54(void *self) {
    s32 i;
    LFLD(s32, self, 0x20) = 0x1000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = 0;
    LFLD(s32, self, 0x60) = 0;
    LFLD(s32, self, 0x64) = 0;
    LFLD(s32, self, 0x68) = 0;
    LFLD(s32, self, 0x6c) = 0;
    LFLD(u8, self, 0x70) = 0;
    LFLD(u8, self, 0x71) = 0;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x80) = 0;
    LFLD(s32, self, 0x7c) = 0;
    LFLD(s32, self, 0x88) = 0;
    LFLD(s32, self, 0x84) = 0;
    LFLD(s32, self, 0x90) = 0;
    LFLD(s32, self, 0x8c) = 0;
    LFLD(s32, self, 0x98) = 0;
    LFLD(s32, self, 0x94) = 0;
    LFLD(s32, self, 0x9c) = 0;
    LFLD(s32, self, 0xa0) = 0;
    LFLD(s32, self, 0xa4) = 0;
    for (i = 0; i < 4; i++) {
        ((s32 *)((u8 *)self + 0xa8))[i] = 0;
    }
    LFLD(u16, self, 0xb8) = 0;
    LFLD(u16, self, 0xba) = 0;
    LFLD(s32, self, 0xbc) = 0;
    LFLD(s32, self, 0xc0) = 0;
}

}

}  // namespace m_Lo_0217ad54

// ---- Lo_0217adfc
namespace m_Lo_0217adfc {

typedef struct {
    u8 pad[0xa8];
    VObj *objs[4];
} Arr0217adfc;

extern "C" {
void func_ov000_0214b724(void *p);

void func_ov000_0217adfc(u8 *self) {
    s32 i;
    LO_FREE_V(self, 0x60);
    LO_FREE_V(self, 0x5c);
    LO_FREE_V(self, 0x64);
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(void *, self, 0x6c) != NULL) {
            void *p = LFLD(void *, self, 0x6c);
            if (p != NULL) {
                func_ov000_0214b724(p);
                func_0203de1c(p);
            }
            LFLD(void *, self, 0x6c) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x74);
    LO_FREE_V(self, 0x78);
    LO_FREE_V(self, 0x7c);
    LO_FREE_V(self, 0x80);
    LO_FREE_V(self, 0x84);
    LO_FREE_V(self, 0x88);
    LO_FREE_V(self, 0x8c);
    LO_FREE_V(self, 0x90);
    LO_FREE_V(self, 0x94);
    LO_FREE_V(self, 0x98);
    LO_FREE_V(self, 0x9c);
    LFLD(u8, self, 0x71) = 0;
    LO_FREE_M(self, 0xa0);
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (((Arr0217adfc *)self)->objs[i] != NULL) {
            VObj *p_ = ((Arr0217adfc *)self)->objs[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            ((Arr0217adfc *)self)->objs[(u32)i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x3c);
}
}

}  // namespace m_Lo_0217adfc

// ---- Lo_0217b230
namespace m_Lo_0217b230 {

class Obj0217b230 : public VObj {
public:
    u32 b0 : 2;
    u32 b2 : 1;
    u32 b3 : 3;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 5;
    u32 b13 : 9;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 7;
    u8 pad_08[0x1c];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0xa];
    u8 unk_36;
    s8 unk_37;
    s32 unk_38;
    u8 pad_3c[8];
    u8 unk_44[4];
    u8 unk_48[4];
    s32 unk_4c;
    u8 pad_50[0x20];
    s32 unk_70;
    s16 unk_74;
    s16 unk_76;
    s32 unk_78;
};

typedef struct {
    s32 unk_00;
    s32 unk_04;
} Data02097ce0;

extern "C" {
extern u8 data_0208ba70[];
extern Data02097ce0 *data_02097ce0;
void *func_0203dd9c(u32 size);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *p);

Obj0217b230 *func_ov000_0217b230(void *unused, s32 a1, s32 a2) {
    Obj0217b230 *o = (Obj0217b230 *)func_0203dd9c(0xb8);
    if (o != NULL) {
        VOBJ_SET_VTABLE(o, data_0208ba70);
        func_0204c7d0(o);
    }
    o->unk_37 = 1;
    o->unk_28 = a2;
    o->unk_24 = a1;
    o->unk_4c = func_0204c4fc(o->unk_28, o->unk_38, o->unk_24, o->unk_44, o->unk_48, o->unk_37 ? 1 : 0);
    data_02097ce0->unk_04 = o->unk_28;
    o->unk_70 = -0x1c8d;
    o->b8 = 0x1e;
    o->unk_74 = 0x7fff;
    o->unk_76 = 0x2adf;
    o->unk_78 = 0x8000;
    o->unk_36 = 1;
    o->b6 = 1;
    o->b22 = 1;
    o->b24 = 1;
    o->vfunc_14();
    o->b2 = 1;
    func_0204ca70(o);
    return o;
}

}

}  // namespace m_Lo_0217b230
