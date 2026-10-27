// ov000 .text 0x0217bd88..0x0217e560, part of the Menu translation unit (.text 0x021763c8..0x02180350,
// string pool 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash. The TU
// is split at the functions that do not match yet (0217a1f8, 0217b324, 0217e560); once they do,
// the four parts become one file and the pool can be claimed.
#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/HeapScope.h"
#include "Main/Sys/Pad.h"

// ---- Win_0217bd88
namespace m_Win_0217bd88 {

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

}  // namespace m_Win_0217bd88

// ---- Lo_0217bf34
namespace m_Lo_0217bf34 {

struct LoDE { s32 d; s32 *e; };
extern "C" {

u16 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

BOOL func_ov000_0217bf34(void *self) {
    VObj *o = LFLD(VObj *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (!o->vfunc_1c()) {
        LFLD(s32, self, 0x68) = 0;
        LO_FREE_V(self, 0x64);
    } else {
        if (!LFLD(VObj *, self, 0x64)->vfunc_0c()) {
            return TRUE;
        }
        if (--LFLD(s32, self, 0x68) < 0) {
            LFLD(s32, self, 0x68) = 0;
        }
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217bf34

// ---- Stub_0217c004
namespace m_Stub_0217c004 {

extern "C" {

BOOL func_ov000_0217bfe4(void *self) {
    if (*(void **)((u8 *)self + 0x64) != NULL) {
        return (BOOL)self;
    }
    return (*(u32 *)((u8 *)self + 0x4) & 0x10000) ? TRUE : FALSE;
}

void func_ov000_0217c004(void) {
}

}

}  // namespace m_Stub_0217c004

// ---- Lo_0217c008
namespace m_Lo_0217c008 {

extern "C" {
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);
void func_ov000_0217a8f4(void);
typedef void (*LoCb0217c008)(void *self, void *arg);
BOOL func_ov000_0217bf34(void *self);
void func_ov000_0217c3b0(u8 *self);
void func_ov000_0217c5a8(u8 *self);
void func_ov000_0217c7b8(u8 *self);
void func_ov000_0217cddc(u8 *self);
void func_ov000_0217cf10(u8 *self);
void func_ov000_0217d0c4(u8 *self);
void func_ov000_0217d66c(u8 *self);
void func_ov000_0217dba4(u8 *self);
void func_ov000_0217ddd4(u8 *self);
extern u8 data_0208b614[];
extern u8 data_0208ca9c[];
extern u8 data_0208c994[];

static inline BOOL Lo0217c3b0_Busy(u8 *self) {
    u8 *p = LFLD(u8 *, self, 0x64);
    if (p == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!((LFLD(u32, p, 0xc) & 0x10000) == 0 ? TRUE : FALSE)) {
            LFLD(u32, p, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline void Lo0217c008_SetMode(u8 *self, s32 m) {
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = m;
        LFLD(s32, self, 0x48) = 0;
    }
}

static inline BOOL Lo0217c008_Flag(VObj *o) {
    return LBIT(o, 0x48).b2 ? TRUE : FALSE;
}

void func_ov000_0217c008(u8 *self) {
    if (LFLD(s32, self, 0x8) != 0xd) {
        return;
    }
    if (!(LFLD(u32, self, 0x4) & 0x20000)) {
        LFLD(s32, self, 0x40) += 0x1000;
        if (LFLD(s32, self, 0x40) >= 0x5a000) {
            LFLD(s32, self, 0x40) -= 0x5a000;
        }
    }
    if (func_ov000_0217bf34(self)) {
        return;
    }
    switch (LFLD(s32, self, 0x4c)) {
    case 1:
        func_ov000_0217c3b0(self);
        break;
    case 2:
        switch (LFLD(s32, self, 0x50)) {
        case 0:
            LFLD(s32, self, 0x54) = 0;
            LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
            ((VObj *)self)->vfunc_48();
            LFLD(s32, self, 0x50) = 1;
            break;
        case 1:
            if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
                break;
            }
            if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
                break;
            }
            if (!((VObj *)self)->vfunc_54()) {
                break;
            }
            if (LFLD(s32, self, 0x54) == 0) {
                LFLD(u32, self, 0x4) |= 0x800000;
                Lo0217c008_SetMode(self, 5);
            }
            LFLD(s32, self, 0x4c) = 0;
            LFLD(s32, self, 0x50) = 0;
            LFLD(s32, self, 0x58) = -1;
            LFLD(s32, self, 0x54) = 0;
            break;
        }
        break;
    case 3:
        func_ov000_0217c5a8(self);
        break;
    case 4:
        func_ov000_0217c7b8(self);
        break;
    }
    if (LFLD(VObj *, self, 0x5c) != NULL) {
        LFLD(VObj *, self, 0x5c)->vfunc_0c();
        if (Lo0217c008_Flag(LFLD(VObj *, self, 0x5c))) {
            Lo0217c008_SetMode(self, 7);
        } else if (LFLD(VObj *, self, 0x60) != NULL) {
            LFLD(VObj *, self, 0x60)->vfunc_0c();
            if (Lo0217c008_Flag(LFLD(VObj *, self, 0x60))) {
                Lo0217c008_SetMode(self, 7);
            }
        }
    }
    switch (LFLD(s32, self, 0x44)) {
    case 1:
        func_ov000_0217cddc(self);
        break;
    case 2:
        func_ov000_0217cf10(self);
        break;
    case 3:
        func_ov000_0217d0c4(self);
        break;
    case 4:
        func_ov000_0217d66c(self);
        break;
    case 5:
        func_ov000_0217dba4(self);
        break;
    case 6:
        if (LFLD(s32, self, 0x48) != 0) {
            break;
        }
        if (Lo0217c3b0_Busy(self)) {
            break;
        }
        if (LFLD(LoCb0217c008, self, 0xbc) != NULL) {
            LFLD(LoCb0217c008, self, 0xbc)(self, LFLD(void *, self, 0xc0));
        }
        ((VObj *)self)->vfunc_0c(0);
        Lo0217c008_SetMode(self, 8);
        break;
    case 7:
        func_ov000_0217ddd4(self);
        break;
    }
}

void func_ov000_0217c3b0(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x72)) {
            LFLD(s32, self, 0x50) = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 3;
        break;
    case 3:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(u32, self, 0x4) |= 0x8000000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        LFLD(s32, self, 0x4c) = 0;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        break;
    }
}

void func_ov000_0217c5a8(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (func_ov000_0217bd88(self, 0x8000, 0x7f)) {
            LFLD(s32, self, 0x50) = 1;
        }
        break;
    case 1:
        if (func_ov000_0217bd88(self, 0x8000, 0x80)) {
            LFLD(s32, self, 0x50) = 2;
        }
        break;
    case 2:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 3;
        break;
    case 3:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(u32, self, 0x4) |= 0x400000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        LFLD(s32, self, 0x4c) = 0;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        break;
    }
}

static inline void Lo0217c7b8_Reset(u8 *self) {
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x58) = -1;
    LFLD(s32, self, 0x54) = 0;
}

static inline BOOL Lo0217c7b8_Ready(u8 *self) {
    if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
        return FALSE;
    }
    if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
        return FALSE;
    }
    if (!((VObj *)self)->vfunc_54()) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0217c7b8(u8 *self) {
    switch (LFLD(s32, self, 0x50)) {
    case 0:
        if (LFLD(s32, self, 0x58) == 1) {
            LFLD(s32, self, 0x50) = 1;
        } else {
            LFLD(s32, self, 0x50) = 5;
        }
        break;
    case 1:
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LFLD(s32, self, 0x54) = 1;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 2;
        break;
    case 2:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(s32, self, 0x50) = 3;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 3:
        LFLD(s32, self, 0x54) = 0x10001;
        LFLD(void *, LoSwitchTask(3), 0x30) = (void *)func_ov000_0217a8f4;
        ((VObj *)self)->vfunc_48();
        LFLD(s32, self, 0x50) = 4;
        break;
    case 4:
        if (!(LBIT(self, 0x4).b0 == 0 ? TRUE : FALSE)) {
            return;
        }
        if (LBIT(self, 0x4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x54) == 0) {
            LFLD(s32, self, 0x50) = 5;
            return;
        }
        Lo0217c7b8_Reset(self);
        break;
    case 5:
        if (!func_ov000_0217bd88(self, 0x8000, 0x82)) {
            return;
        }
        LFLD(u8, data_02097dd0, 0x31) = 1;
        LFLD(u32, self, 0x4) |= 0x10000000;
        LFLD(s32, self, 0x50) = 6;
    case 6: {
        u8 *p = LFLD(u8 *, self, 0x5c);
        LFLD(u32, p, 0x48) |= 0x4000;
        LFLD(s32, p, 0x40) = 0;
        LFLD(s32, self, 0x50) = 7;
        break;
    }
    case 7:
        if (!(LBIT(LFLD(u8 *, self, 0x5c), 0x48).b1 ? TRUE : FALSE)) {
            return;
        }
        if (LFLD(s32, self, 0x58) == 1) {
            LFLD(s32, self, 0x50) = 9;
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        func_ov000_0217bd88(self, 0x8000, 0x83);
        LFLD(s32, self, 0x50) = 8;
        break;
    case 8:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        if (!((LFLD(u32, self, 0x4) & 0x4000000) ? TRUE : FALSE)) {
            Lo0217c008_SetMode(self, 5);
        }
        Lo0217c7b8_Reset(self);
        break;
    case 9: {
        VObj *o = (VObj *)func_0203dd9c(0x58);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_0208b614);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_0208ca9c);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_0208c994);
            o->vfunc_14();
        }
        LFLD(VObj *, self, 0x60) = o;
        o->vfunc_08();
        LFLD(u32, LFLD(u8 *, self, 0x60), 0x48) |= 0x40;
        LBIT(LFLD(u8 *, self, 0x60), 0x48).b0 = 1;
        LFLD(s32, self, 0x50) = 10;
    }
    case 10: {
        u8 *p = LFLD(u8 *, self, 0x60);
        if (!(LBIT(p, 0x48).b7 ? TRUE : FALSE)) {
            return;
        }
        LFLD(u32, p, 0x48) |= 0x4000;
        LFLD(s32, p, 0x40) = 0;
        LFLD(s32, self, 0x50) = 11;
        break;
    }
    case 11:
        if (!(LBIT(LFLD(u8 *, self, 0x60), 0x48).b1 ? TRUE : FALSE)) {
            return;
        }
        if (Lo0217c3b0_Busy(self)) {
            return;
        }
        LO_FREE_V(self, 0x60);
        func_ov000_0217bd88(self, 0x8000, 0x83);
        LFLD(s32, self, 0x50) = 8;
        break;
    }
}
}

}  // namespace m_Lo_0217c008

// ---- Lo_0217cddc
namespace m_Lo_0217cddc {

extern "C" {

extern void *data_ov000_021c9bf4[];
void *func_0203dd9c(u32 size);
void func_ov000_0214b810(void *p);
void func_ov000_0214b724(void *p);
void *func_ov000_0214b6d8(void *p);
void func_ov000_0214b88c(void *p, void *name);
BOOL func_ov000_0214b8d8(void *p);
BOOL func_ov000_0214b8f4(void *p);
s32 func_ov000_0214b6d0(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL HasFlag0217cddc(u8 *self, u32 bit) {
    return (LFLD(u32, self, 0x4) & bit) ? TRUE : FALSE;
}

static inline BOOL Has2_0217cddc(u8 *self, u32 bit) {
    return HasFlag0217cddc(self, bit) ? TRUE : FALSE;
}

void func_ov000_0217cddc(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        if (LFLD(s32, self, 0xc) != 3) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x6f)) {
                break;
            }
        }
        LFLD(u32, self, 0x4) &= 0xc00fffff;
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        if (LFLD(s32, self, 0xc) == 1) {
            LFLD(u32, self, 0x4) |= 0x1000000;
        } else if (LFLD(s32, self, 0xc) == 2) {
            LFLD(u32, self, 0x4) |= 0x2000000;
        } else if (LFLD(s32, self, 0xc) == 3) {
            LFLD(u32, self, 0x4) |= 0x4000000;
        }
        LFLD(s32, self, 0x48) = 1;
        break;
    case 1:
        if (Has2_0217cddc(self, 0x1000000) | Has2_0217cddc(self, 0x2000000) | Has2_0217cddc(self, 0x4000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 3;
                LFLD(s32, self, 0x48) = 0;
            }
        } else {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 2;
                LFLD(s32, self, 0x48) = 0;
            }
        }
        break;
    }
}

static inline BOOL IsSet0217cf10(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

void func_ov000_0217cf10(u8 *self) {
    if (LFLD(void *, self, 0x6c) != NULL) {
        func_ov000_0214b810(LFLD(void *, self, 0x6c));
    }
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        void *p;
        HEAP_DELETE(void *, LFLD(void *, self, 0x6c), func_ov000_0214b724(p); func_0203de1c(p));
        p = func_0203dd9c(0x3c);
        if (p != NULL) {
            p = func_ov000_0214b6d8(p);
        }
        LFLD(void *, self, 0x6c) = p;
        func_ov000_0214b88c(p, data_ov000_021c9bf4[1]);
        LFLD(s32, self, 0x48) = 1;
        break;
    }
    case 1:
        if (!func_ov000_0214b8d8(LFLD(void *, self, 0x6c))) {
            break;
        }
        if (!func_ov000_0214b8f4(LFLD(void *, self, 0x6c))) {
            if (func_ov000_0214b6d0((u8 *)LFLD(void *, self, 0x6c) + 0x20) == 3) {
                LFLD(s32, self, 0x48) = 3;
            } else {
                LFLD(s32, self, 0x48) = 2;
            }
            break;
        }
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 3;
            LFLD(s32, self, 0x48) = 0;
        }
        break;
    case 3:
        if (func_ov000_0217bd88(self, 0x8000, 0x70)) {
            LFLD(s32, self, 0x48) = 2;
        }
        break;
    case 2:
        if (!func_ov000_0217bd88(self, 0x8000, 0x71)) {
            break;
        }
        LFLD(s32, self, 0x4c) = 1;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 4;
        break;
    case 4:
        if (IsSet0217cf10(self)) {
            break;
        }
        func_ov000_0217bd88(self, 0x8000, 0x6f);
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 3;
            LFLD(s32, self, 0x48) = 0;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217cddc

// ---- Lo_0217d0c4
namespace m_Lo_0217d0c4 {

extern "C" {

extern void *data_0214a424;
void func_020473ac(void *s, s32 state);
void func_0206c4c4(void *p);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d0c4(void *o) {
    return (LFLD(u32, o, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d0c4(u8 *self) {
    void *o = LFLD(void *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!Ready0217d0c4(o)) {
            LFLD(u32, o, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d0c4(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d0c4(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

static inline BOOL B7_0217d0c4(void *o) { return LBIT(o, 0x48).b7 ? TRUE : FALSE; }
static inline BOOL B11_0217d0c4(void *o) { return LBIT(o, 0x48).b11 ? TRUE : FALSE; }
static inline BOOL B1_0217d0c4(void *o) { return LBIT(o, 0x48).b1 ? TRUE : FALSE; }
static inline BOOL B13_0217d0c4(void *o) { return LBIT(o, 0x48).b13 ? TRUE : FALSE; }
static inline BOOL B3_0217d0c4(void *o) { return LBIT(o, 0x48).b3 ? TRUE : FALSE; }

static inline void Exit0217d0c4(u8 *self, s32 next) {
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = next;
        LFLD(s32, self, 0x48) = 0;
    }
}

void func_ov000_0217d0c4(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0:
        func_020473ac(LFLD(void *, self, 0x5c), 1);
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x40;
        LBIT(LFLD(void *, self, 0x5c), 0x48).b0 = 1;
        LFLD(s32, self, 0x48) = 1;
        break;
    case 1: {
        void *o = LFLD(void *, self, 0x5c);
        void *q;
        u32 flags;
        u8 b;
        if (!B7_0217d0c4(o)) {
            return;
        }
        q = LFLD(void *, o, 0x28);
        if (B11_0217d0c4(o)) {
            LFLD(s32, self, 0x48) = 9;
            return;
        }
        flags = LFLD(u32, self, 0x4);
        if (Flag0217d0c4(flags, 0x4000000)) {
            LFLD(s32, self, 0x48) = 0x13;
            return;
        }
        b = LFLD(u8, q, 0x15);
        if (!(b & 1)) {
            if (Flag0217d0c4(flags, 0x1000000)) {
                LFLD(s32, self, 0x48) = 0x16;
                return;
            }
            if (Flag0217d0c4(flags, 0x2000000)) {
                LFLD(s32, self, 0x48) = 0x16;
            } else {
                LFLD(s32, self, 0x48) = 2;
            }
        } else {
            if (b & 4) {
                LFLD(s32, self, 0x48) = 6;
            } else {
                LFLD(s32, self, 0x48) = 7;
            }
        }
        break;
    }
    case 2: {
        BOOL busy = FALSE;
        void *o = LFLD(void *, self, 0x64);
        if (LFLD(s32, self, 0x68) != 0) {
            busy = TRUE;
        }
        if (o != NULL && Ready0217d0c4(o)) {
            busy = TRUE;
        }
        if (busy) {
            return;
        }
        LFLD(u32, o, 0xc) |= 0x40000;
        LFLD(u32, self, 0x4) |= 0x100000;
        func_0206c4c4(data_0214a424);
        Exit0217d0c4(self, 5);
        break;
    }
    case 6:
        LFLD(u32, self, 0x4) |= 0x200000;
        func_0206c4c4(data_0214a424);
        Exit0217d0c4(self, 4);
        break;
    case 7: {
        void *o = LFLD(void *, self, 0x5c);
        LFLD(u32, o, 0x48) |= 0x400;
        LFLD(s32, o, 0x40) = 0;
        LFLD(s32, self, 0x48) = 8;
        break;
    }
    case 8: {
        void *o = LFLD(void *, self, 0x5c);
        if (B1_0217d0c4(o)) {
            Exit0217d0c4(self, 4);
            return;
        }
        if (B11_0217d0c4(o)) {
            LFLD(s32, self, 0x48) = 9;
        }
        break;
    }
    case 9:
        if (func_ov000_0217bd88(self, 0x8000, 0x85)) {
            LFLD(s32, self, 0x48) = 0xa;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x86)) {
            LFLD(s32, self, 0x48) = 0xb;
        }
        break;
    case 11:
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x1000;
        LFLD(s32, self, 0x48) = 0xc;
        break;
    case 12: {
        void *o;
        if (Busy0217d0c4(self)) {
            return;
        }
        o = LFLD(void *, self, 0x5c);
        if (B1_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x87);
            LFLD(s32, self, 0x48) = 0xd;
            return;
        }
        if (B13_0217d0c4(o)) {
            func_ov000_0217bd88(self, 0x8000, 0x88);
            LFLD(s32, self, 0x48) = 0xe;
        }
        break;
    }
    case 13:
        Exit0217d0c4(self, 4);
        break;
    case 14:
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        func_020473ac(LFLD(void *, self, 0x5c), 4);
        LFLD(s32, self, 0x48) = 0xf;
        break;
    case 15:
        LFLD(s32, self, 0x4c) = 4;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = 0;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 0x11;
        break;
    case 17:
        if (Waiting0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 4);
        break;
    case 19:
        if (!(LFLD(u8, LFLD(void *, self, 0x5c), 0x8) == 0 ? TRUE : FALSE)) {
            LFLD(s32, self, 0x48) = 0x14;
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 20:
        if (!func_ov000_0217bd88(self, 0x8000, 0x6d)) {
            return;
        }
        LFLD(u32, LFLD(void *, self, 0x5c), 0x48) |= 0x8;
        LFLD(s32, self, 0x48) = 0x15;
        break;
    case 21:
        if (B3_0217d0c4(LFLD(void *, self, 0x5c))) {
            return;
        }
        if (Busy0217d0c4(self)) {
            return;
        }
        Exit0217d0c4(self, 6);
        break;
    case 22:
        if (func_ov000_0217bd88(self, 0x8000, 0x174)) {
            LFLD(s32, self, 0x48) = 0x17;
        }
        break;
    case 23:
        if (Flag0217d0c4(LFLD(u32, self, 0x4), 0x1000000)) {
            if (!func_ov000_0217bd88(self, 0x8000, 0x148)) {
                break;
            }
        } else {
            if (!func_ov000_0217bd88(self, 0x8000, 0x175)) {
                break;
            }
        }
        Exit0217d0c4(self, 6);
        break;
    }
}

}

}  // namespace m_Lo_0217d0c4

// ---- Lo_0217d66c
namespace m_Lo_0217d66c {

extern "C" {

extern void *data_02097e4c;
BOOL func_0203e688(void);
void func_020473ac(void *s, s32 state);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
void func_ov000_0217b324(void *self, s32 a);
BOOL func_ov000_0217bd88(void *self, s32 a, s32 b);

static inline BOOL Ready0217d66c(void *o) {
    return (LFLD(u32, o, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL Busy0217d66c(u8 *self) {
    void *o = LFLD(void *, self, 0x64);
    if (o == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!Ready0217d66c(o)) {
            LFLD(u32, o, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

static inline BOOL Flag0217d66c(u32 flags, u32 bit) {
    return (flags & bit) ? TRUE : FALSE;
}

static inline BOOL Waiting0217d66c(u8 *self) {
    return LFLD(s32, self, 0x4c) != 0 ? TRUE : FALSE;
}

static inline void SePlay0217d66c(s32 id) {
    func_02049a48(data_02097e4c, id, -1, -1, -1);
}

void func_ov000_0217d66c(u8 *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        u32 flags;
        if (Busy0217d66c(self)) {
            return;
        }
        flags = LFLD(u32, self, 0x4);
        if (Flag0217d66c(flags, 0x4000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 6;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        if (Flag0217d66c(flags, 0x1000000) || Flag0217d66c(flags, 0x2000000)) {
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        func_020473ac(LFLD(void *, self, 0x5c), 4);
        func_ov000_0217b324(self, 0);
        LFLD(s32, self, 0x48) = 1;
        break;
    }
    case 1:
        if (!func_0203e688()) {
            return;
        }
        SePlay0217d66c(0x27);
        LFLD(s32, self, 0x48) = 2;
        break;
    case 2:
        LFLD(s32, self, 0xa4) += 0x1000;
        if (LFLD(s32, self, 0xa4) < 0x18000) {
            return;
        }
        LFLD(s32, self, 0xa4) = 0x18000;
        LFLD(u32, self, 0x4) &= ~0x10000;
        LFLD(s32, self, 0x48) = 3;
        break;
    case 3: {
        Pad *pad;
        if (Flag0217d66c(LFLD(u32, self, 0x4), 0x10000)) {
            return;
        }
        pad = data_02097dc8;
        if ((pad->cur & 0x548) == 0x548) {
            LFLD(s32, self, 0x48) = 0xc;
            return;
        }
        if (pad->trig & 1) {
            switch (LFLD(s8, LFLD(u8 *, self + LFLD(s16, self, 0xba) * 4, 0xa8), 0x98)) {
            case '1':
                LFLD(s32, self, 0x48) = 4;
                return;
            case '2':
                LFLD(s32, self, 0x48) = 6;
                return;
            case '3':
                LFLD(s32, self, 0x48) = 8;
                return;
            case '4':
                LFLD(s32, self, 0x48) = 10;
                return;
            }
            break;
        }
        if (pad->trig & 2) {
            SePlay0217d66c(0x28);
            LFLD(u32, self, 0x4) |= 0x20000000;
            if (LFLD(s32, self, 0x44) != 7) {
                LFLD(s32, self, 0x44) = 5;
                LFLD(s32, self, 0x48) = 0;
            }
            return;
        }
        if (pad->repeat & 0x80) {
            LFLD(s16, self, 0xba)++;
            if (LFLD(s16, self, 0xba) >= LFLD(s16, self, 0xb8)) {
                LFLD(s16, self, 0xba) = LFLD(s16, self, 0xb8) - 1;
                return;
            }
            SePlay0217d66c(0x1d);
            return;
        }
        if (pad->repeat & 0x40) {
            LFLD(s16, self, 0xba)--;
            if (LFLD(s16, self, 0xba) < 0) {
                LFLD(s16, self, 0xba) = 0;
                return;
            }
            SePlay0217d66c(0x1d);
        }
        break;
    }
    case 4:
        LFLD(s32, self, 0x4c) = 2;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 5;
        break;
    case 5:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 6:
        LFLD(s32, self, 0x4c) = 1;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 7;
        break;
    case 7:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 8:
        LFLD(s32, self, 0x4c) = 3;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = -1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 9;
        break;
    case 9:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 10:
        if (func_ov000_0217bd88(self, 0x8000, 0x19d)) {
            LFLD(s32, self, 0x48) = 0xb;
        }
        break;
    case 11:
        if (LFLD(VObj *, self, 0x64) != NULL && LFLD(VObj *, self, 0x64)->vfunc_0c() &&
            (data_02097dc8->cur & 0x548) == 0x548) {
            LFLD(u32, LFLD(void *, self, 0x64), 0xc) |= 0x40000;
            LFLD(s32, self, 0x48) = 0xc;
            return;
        }
        if (!Busy0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    case 12:
        if (Busy0217d66c(self)) {
            return;
        }
        LFLD(s32, self, 0x4c) = 4;
        LFLD(s32, self, 0x50) = 0;
        LFLD(s32, self, 0x58) = 1;
        LFLD(s32, self, 0x54) = 0;
        LFLD(s32, self, 0x48) = 9;
        break;
    case 13:
        if (!Waiting0217d66c(self)) {
            LFLD(s32, self, 0x48) = 3;
        }
        break;
    }
}

}

}  // namespace m_Lo_0217d66c

// ---- Lo_0217dba4
namespace m_Lo_0217dba4 {

extern "C" {
extern void *data_ov000_021ccd54;
extern void *data_0214a424;
void func_0206c994(void *p);
void func_ov000_02186204(void *p, s32 a);
void func_ov000_0218781c(void *p, s32 a);
void func_ov000_02187588(void *p);
void func_ov000_0218283c(void *p, s32 a);
void func_ov000_02182920(void *p);
void func_ov000_021829f8(void *p);

static inline BOOL Bit(u32 f, u32 m) {
    return (f & m) ? TRUE : FALSE;
}

static inline BOOL IsFree(u8 *sub) {
    return (LFLD(u32, sub, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline BOOL CheckSub(u8 *self) {
    u8 *sub = LFLD(u8 *, self, 0x64);
    if (sub == NULL) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x68) == 0) {
        if (!IsFree(sub)) {
            LFLD(u32, sub, 0xc) |= 0x40000;
        }
    }
    return TRUE;
}

void func_ov000_0217dba4(VObj *self) {
    u32 f;
    LFLD(u32, self, 4) |= 0x10000;
    if (CheckSub((u8 *)self)) {
        return;
    }
    if (LFLD(s32, self, 0xa4) != 0) {
        LFLD(s32, self, 0xa4) -= 0x1000;
        if (LFLD(s32, self, 0xa4) <= 0) {
            LFLD(s32, self, 0xa4) = 0;
        }
        return;
    }
    LFLD(VObj *, self, 0x5c)->vfunc_74();
    f = LFLD(u32, self, 4);
    if (f & 0x10000000) {
        if (LFLD(s32, self, 0x44) != 7) {
            LFLD(s32, self, 0x44) = 1;
            LFLD(s32, self, 0x48) = 0;
        }
        return;
    }
    if (!(f & 0x20000000)) {
        if (Bit(f, 0x1000000)) {
            if (!Bit(f, 0x200000)) {
                func_0206c994(data_0214a424);
            }
            func_ov000_02186204(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x2000000)) {
            if (!Bit(f, 0x200000)) {
                func_0206c994(data_0214a424);
            }
            func_ov000_0218781c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x8000000)) {
            func_ov000_02187588(data_ov000_021ccd54);
        } else if (Bit(f, 0x100000) || Bit(f, 0x200000)) {
            func_ov000_0218283c(data_ov000_021ccd54, 0);
        } else if (Bit(f, 0x400000)) {
            func_ov000_02182920(data_ov000_021ccd54);
        } else if (Bit(f, 0x800000)) {
            func_ov000_021829f8(data_ov000_021ccd54);
        }
        LFLD(u8, data_ov000_021ccd34, 0) = 1;
        LFLD(LoTaskFlags, LFLD(void *, data_ov000_021ccd34, 0x10), 0).b0 = 1;
    }
    self->vfunc_0c(0);
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = 8;
        LFLD(s32, self, 0x48) = 0;
    }
}
}

}  // namespace m_Lo_0217dba4

// ---- Lo_0217ddd4
namespace m_Lo_0217ddd4 {

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

void func_ov000_0217ddd4(void *self) {
    switch (LFLD(s32, self, 0x48)) {
    case 0: {
        u32 fl;
        s32 k;
        LFLD(VObj *, self, 0x5c)->vfunc_74();
        if (LFLD(VObj *, self, 0x60) != NULL) {
            LFLD(VObj *, self, 0x60)->vfunc_74();
        }
        fl = LFLD(u32, self, 4);
        if (fl & 0x10000000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x84);
        } else if (fl & 0x100000) {
            k = func_ov000_0217bd88(self, 0x8000, 0x75);
        } else {
            k = func_ov000_0217bd88(self, 0x8000, 0x76);
        }
        if (!k) {
            return;
        }
        LFLD(s32, self, 0x48) = 1;
    }
    case 1:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        break;
    }
}

extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
typedef struct { s32 x, y, z; } V0217de7c;
void func_ov000_0217df5c(void *self, V0217de7c *v);
void func_ov000_0217e560(void *self, V0217de7c *v);

void func_ov000_0217de7c(void *self) {
    s32 st;
    if (LFLD(void *, self, 0x24) == NULL) {
        return;
    }
    st = LFLD(s32, self, 0x44);
    if ((st == 4 || st == 5 || st == 7) && LFLD(s32, self, 0xa4) != 0) {
        s32 t = FX_Div(LFLD(s32, self, 0xa4), 0x18000);
        s32 c = 0x1000 - FX_SinCosTable_[((t * 0x4000) >> 16) * 2];
        V0217de7c v;
        v.x = LO_FX_MUL(c, 0x140000);
        v.y = 0;
        v.x &= ~0xfff;
        v.y &= ~0xfff;
        func_ov000_0217df5c(self, &v);
        func_ov000_0217e560(self, &v);
    }
    if (LFLD(VObj *, self, 0x64) != NULL) {
        LFLD(VObj *, self, 0x64)->vfunc_20();
    }
}

}

}  // namespace m_Lo_0217ddd4

// ---- Lo_0217df5c
namespace m_Lo_0217df5c {

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0217df5c;

#define MF(m) LFLD(LoMdlFlags0217df5c, m, 0x6c)

typedef struct {
    s32 x, y, z;
} LoVec0217df5c;

extern "C" {

extern u8 *data_02097d48;
extern u8 data_0208b3d0[];
extern LoVec0217df5c data_ov000_021c9c10;
u8 func_02043d48(void *p);
void func_02043d20(void *p, s32 a);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
s32 func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(LoVec0217df5c *pos, LoVec0217df5c *col, s32 a, s32 b);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void LoSetPosFx0217df5c(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

static inline void LoSetPosV0217df5c(void *m, LoVec0217df5c *p) {
    LFLD(s32, m, 0xfc) = p->x;
    LFLD(s32, m, 0x100) = p->y;
}

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_ov000_0217df5c(u8 *self, LoVec0217df5c *pos) {
    LoVec0217df5c v;
    u8 *g = data_02097d48;
    u32 size;
    u8 i;
    MF(LFLD(void *, self, 0xa0)).b19 = 1;
    MF(LFLD(void *, self, 0xa0)).f7 = func_02043d48(g + 0x8b0);
    MF(LFLD(void *, self, 0xa0)).f2 = 0x1c;
    LoSetPosV0217df5c(LFLD(void *, self, 0xa0), pos);
    LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1ccd;
    LoModelPlayPart(LFLD(void *, self, 0xa0), 1);
    if (LFLD(u8, self, 0x71) != 0) {
        v.x = pos->x - 0x6f000;
        v.y = pos->y - 0x4a000;
        v.z = pos->z;
        MF(LFLD(void *, self, 0xa0)).b19 = 0;
        MF(LFLD(void *, self, 0xa0)).f2 = 0x1f;
        for (i = 0; i < 3; i++) {
            LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c8d;
            LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
            LoModelPlayPart(LFLD(void *, self, 0xa0), 2);
            if (i < LFLD(u8, self, 0x71)) {
                LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c4d;
                LoSetPosV0217df5c(LFLD(void *, self, 0xa0), &v);
                LoModelPlayPart(LFLD(void *, self, 0xa0), 3);
            }
            v.x += 0xc000;
        }
    }
    func_02043d20(g + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1f00d0);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0x16000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0xc000, 0x1000);
    size = *(u32 *)0x020828f8;
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xc000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xf4000, pos->y + 0x60000, -0x1c8d);
    G3_Vec(0x1b, 0x2000, 0xa0000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0x80000, pos->y + 0xaf000, -0x1c8d);
    G3_Vec(0x1b, 0xea000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos->x + 0xbe000, pos->y + 0x74000, -0x1c8d);
    G3_Vec(0x1b, 0x66000, 0x71000, 0x1000);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 0), size);
    G3_Cmd1(0x12, 1);
    {
    LoVec0217df5c c = data_ov000_021c9c10;
    v.x = pos->x + 0xbe000;
    v.y = pos->y + 0x6e000;
    v.z = -0x1c4d;
    func_ov000_0214b1a0(&v, &c, 0x1f, func_ov000_0214b8ec(LFLD(void *, self, 0x6c)));
    }
}

}

}  // namespace m_Lo_0217df5c
#undef MF
