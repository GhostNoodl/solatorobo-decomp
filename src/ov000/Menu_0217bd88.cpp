// ov000 .text 0x0217bd88..0x02180350, part of the Menu translation unit (.text 0x021763c8..0x02180350,
// string pool 0x021cba18..0x021cbac0). The former files are kept as they were, each in its own
// namespace, so that their local typedefs, inlines and extern declarations do not clash. The TU
// is split at the function that does not match yet (0217a1f8); once it does,
// the three parts become one file and the pool can be claimed.
#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "ov000/HeapScope.h"
#include "Main/Sys/Pad.h"
#include "types.h"

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

// ---- Lo_0217e560
namespace m_Lo_0217e560 {

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0217e560;

#define MF(m) LFLD(LoMdlFlags0217e560, m, 0x6c)

extern "C" {

extern u8 *data_02097d48;
u8 func_02043d48(void *p);
extern s16 FX_SinCosTable_[];
s32 FX_Div(s32 a, s32 b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);

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

static inline void LoSetPosFx0217e560(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

// The menu items (func_ov000_0217b230) are 0xb8-byte TextWins. Main/Gfx/TextWin.h clashes with
// LoCommon.h, so this is its vtable up to Render (0x90). SetPos (0x20) and Render return void.
struct LoTextWin {
    virtual void unk_vf00();
    virtual void unk_vf04();
    virtual void unk_vf08();
    virtual void OnSkip();
    virtual void unk_vf10();
    virtual void unk_vf14();
    virtual void unk_vf18();
    virtual void unk_vf1c();
    virtual void unk_vf20(int a, int b);
    virtual char *unk_vf24(char *p);
    virtual char *unk_vf28(char *p);
    virtual char *unk_vf2c(char *p);
    virtual char *unk_vf30(char *p);
    virtual char *unk_vf34(char *p);
    virtual char *unk_vf38(char *p);
    virtual char *unk_vf3c(char *p);
    virtual char *unk_vf40(char *p);
    virtual char *unk_vf44(char *p);
    virtual char *unk_vf48(char *p);
    virtual char *ParseEscape(char *p);
    virtual char *unk_vf50(char *p);
    virtual char *unk_vf54(char *p);
    virtual char *unk_vf58(char *p);
    virtual char *unk_vf5c(char *p);
    virtual char *unk_vf60(char *p);
    virtual char *unk_vf64(char *p);
    virtual char *unk_vf68(char *p);
    virtual char *unk_vf6c(char *p);
    virtual char *unk_vf70(char *p);
    virtual char *unk_vf74(char *p);
    virtual char *unk_vf78(char *p);
    virtual void unk_vf7c();
    virtual void unk_vf80();
    virtual void unk_vf84();
    virtual void unk_vf88();
    virtual void unk_vf8c();
    virtual void Render();
};
#define OBJ(off) LFLD(LoTextWin *, self, off)

static inline void Row0217e560(u8 *self, int off, s32 x, s32 y) {
    OBJ(off)->unk_vf20(x + 0x12, y);
    OBJ(off)->Render();
    OBJ(off + 4)->unk_vf20(x + 0x87 - LFLD(s32, OBJ(off + 4), 0x44), y);
    OBJ(off + 4)->Render();
}
void func_ov000_0217e560(u8 *self, s32 *pos) {
    s32 x = pos[0] >> 12;
    u8 *g = data_02097d48;
    s32 step;
    s32 a;
    s32 s;
    s16 i;
    s32 y = pos[1] >> 12;
    s32 y0;
    s32 t;
    s32 lx;
    if (OBJ(0x74) != NULL) {
        OBJ(0x74)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x74), 0x44) >> 1), y + 0x1e);
        OBJ(0x74)->Render();
    }
    if (OBJ(0x78) != NULL) {
        OBJ(0x78)->unk_vf20(x + 0x80 - (LFLD(s32, OBJ(0x78), 0x44) >> 1), y + 0x2b);
        OBJ(0x78)->Render();
    }
    Row0217e560(self, 0x7c, x, y + 0x3d);
    Row0217e560(self, 0x84, x, y + 0x4a);
    Row0217e560(self, 0x8c, x, y + 0x57);
    Row0217e560(self, 0x94, x, y + 0x64);
    OBJ(0x9c)->unk_vf20(x + 0xbd - (LFLD(s32, OBJ(0x9c), 0x44) >> 1), y + 0xa0);
    OBJ(0x9c)->Render();
    t = LFLD(s32, self, 0x40) % 0x5a000;
    if (t <= 0x1e000) {
        s32 r = FX_Div(t, 0x1e000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2];
    } else if (t <= 0x5a000) {
        s32 r = FX_Div(t - 0x1e000, 0x3c000);
        if (r > 0x1000) {
            r = 0x1000;
        }
        s = FX_SinCosTable_[((r << 14) >> 16) * 2 + 1];
    } else {
        s = 0;
    }
    a = (LO_FX_MUL(s, 0x10000) >> 12) + 0xf;
    lx = x + 0x4c;
    step = 0;
    if (LFLD(s16, self, 0xb8) == 4) {
        y0 = y + 0x75;
        step = 0xe;
    } else if (LFLD(s16, self, 0xb8) == 3) {
        y0 = y + 0x79;
        step = 0x10;
    } else if (LFLD(s16, self, 0xb8) == 2) {
        y0 = y + 0x80;
        step = 0x12;
    } else {
        y0 = y + 0x89;
    }
    for (i = 0; i < LFLD(s16, self, 0xb8); i++) {
        ((LoTextWin **)(self + 0xa8))[i]->unk_vf20(lx - (LFLD(s32, ((LoTextWin **)(self + 0xa8))[i], 0x44) >> 1), y0 + i * step);
        ((LoTextWin **)(self + 0xa8))[i]->Render();
    }
    {
        s32 py = (LFLD(s16, self, 0xba) * step + y0 - 0x5a) << 12;
        MF(LFLD(void *, self, 0xa0)).b19 = 1;
        MF(LFLD(void *, self, 0xa0)).f7 = func_02043d48(g + 0x8b0);
        MF(LFLD(void *, self, 0xa0)).f2 = (u8)a;
        LoSetPosFx0217e560(LFLD(void *, self, 0xa0), (lx - 0x80) << 12, py);
    }
    LFLD(s32, LFLD(void *, self, 0xa0), 0x150) = -0x1c8d;
    LoModelPlayPart(LFLD(void *, self, 0xa0), 4);
}

}

}  // namespace m_Lo_0217e560
#undef MF


// ---- Dtor_0217e9c8
namespace m_Dtor_0217e9c8 {

extern "C" {

extern u8 data_ov000_021cbae0[];
extern u8 data_ov000_021cc060[];
void *func_0203dd9c(u32 size);

VObj *func_ov000_0217e9c8(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x58);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbae0);
        obj->vfunc_58();
    }
    obj->vfunc_08(0x9, 0xc8);
    return obj;
}

}

}  // namespace m_Dtor_0217e9c8

// ---- Lo_0217ea30
namespace m_Lo_0217ea30 {

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits0217ea30;

extern "C" {
extern void *data_02149ef8;
extern void *data_02fe152c;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
void *func_0204c0e8(void *g, u32 id);
BOOL func_0206c4a0(void);
BOOL func_02059454(void *a, s32 b, s32 c, s32 d);
void func_ov000_02175e6c(void);

class Obj0217ea30 {
public:
    u8 data[0x1e4];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Obj0217ea30() {
        *(void **)this = data_ov000_021cac60;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021caec8;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb1b0;
        ((VObj *)this)->vfunc_28();
        *(void **)this = data_ov000_021cb0b8;
        ((VObj *)this)->vfunc_28();
    }
};

// `b` is declared as an unused third parameter and `a` as a one-element array
// because that gives the target's register allocation. Each arm ends with its
// own copy of the `new`/store/`vfunc_10` tail to get the target's branch layout.
s32 func_ov000_0217ea30(VObj *self, s32 msg, void *b) {
    u8 *p = LFLD(u8 *, self, 0x2c);
    void *g;
    VObj *o;
    void *a[1];
    switch (msg) {
    case 0:
        if (func_0206c4a0()) {
            if (func_02059454(data_02fe152c, 5, 1, 4)) {
                g = data_02149ef8;
                a[0] = func_0204c0e8(g, 0x1d);
                b = func_0204c0e8(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                LFLD(VObj *, self, 0x3c) = o;
                o->vfunc_10(b);
            } else {
                g = data_02149ef8;
                a[0] = func_0204c0e8(g, 0x1c);
                b = func_0204c0e8(g, 0x8d);
                o = (VObj *)new Obj0217ea30;
                LFLD(VObj *, self, 0x3c) = o;
                o->vfunc_10(b);
            }
        } else {
            g = data_02149ef8;
            a[0] = func_0204c0e8(g, 0x1e);
            b = func_0204c0e8(g, 0x8d);
            o = (VObj *)new Obj0217ea30;
            LFLD(VObj *, self, 0x3c) = o;
            o->vfunc_10(b);
        }
        LFLD(void *, LFLD(void *, self, 0x3c), 0x1dc) = a[0];
        LFLD(s16, LFLD(void *, self, 0x3c), 0x1e0) = 0;
        LFLD(void *, LFLD(void *, self, 0x3c), 0x8) = self;
        LFLD(void *, LFLD(void *, self, 0x3c), 0x84) = (void *)func_ov000_02175e6c;
        LFLD(VObj *, self, 0x3c)->vfunc_08();
        LFLD(s16, LFLD(void *, self, 0x3c), 0x68) = -0x1666;
        LFLD(Bits0217ea30, self, 0x4).b0 = true;
        LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x4000000;
        break;
    case 2:
        if (func_0206c4a0()) {
            if (func_02059454(data_02fe152c, 5, 1, 4)) {
                if (LFLD(u16, self, 0x44) == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else if (LFLD(u16, self, 0x44) == 1) {
                    LFLD(s32, p, 0x44) = 1;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            } else {
                if (LFLD(u16, self, 0x44) == 0) {
                    LFLD(s32, p, 0x44) = 0;
                } else {
                    return 0;
                }
                self->vfunc_0c(0);
                return 1;
            }
        }
        LFLD(s32, p, 0x44) = 2;
        break;
    }
    return 0;
}

}

}  // namespace m_Lo_0217ea30

// ---- Lo_0217ed94
namespace m_Lo_0217ed94 {

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

void func_ov000_0217ed94(void) {
    LoTaskObj()->vfunc_2c();
}

void func_ov000_0217edb4(VObj *self) {
    LBIT(self, 4).b1 = 0;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
}

void func_ov000_0217ede8(void *self) {
    LFLD(s32, self, 0x20) = 0x8000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = -1;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
}

void func_ov000_0217ee18(void *self) {
    LO_FREE_V(self, 0x48);
    LO_FREE_M(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x54);
}

}

}  // namespace m_Lo_0217ed94

// ---- Stub_0217ef34
namespace m_Stub_0217ef34 {

extern "C" {

void func_ov000_0217ef34(void) {
}

void func_ov000_0217ef38(void) {
}

}

}  // namespace m_Stub_0217ef34

// ---- Lo_0217ef3c
namespace m_Lo_0217ef3c {

extern "C" {

extern s32 data_02097d78[];
extern u8 *data_02097e48;
extern void *data_02fe152c;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd64;
extern u8 data_0208b318[];
extern char data_ov000_021cba75[];
extern char data_ov000_021cba7f[];
extern char data_ov000_021cba8b[];
extern char data_ov000_021cba97[];
extern char data_ov000_021cbaa3[];
extern void *data_02097e4c;
extern u8 *data_02097dc8;
BOOL func_02059454(void *p, s32 a, s32 b, s32 c);
s32 func_ov000_0217ea30(VObj *self, s32 msg, void *b);
void func_ov000_0216f42c(void *a, void *b);
void func_020656b4(void *p);
void func_ov000_0218e514(void *p, s32 a);
void func_0206e900(char *dst, const char *src);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void STD_CopyString(void *dst, void *src);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_0204a2e0(void *mgr, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);
void func_0204aab0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_ov000_02187150(void *p, s32 a);
void func_ov000_02182b0c(void *p);
void *func_ov000_0219bf90(void);
void func_ov000_021b4774(void);
void func_020623fc(void);
void func_ov000_02182590(void *p);

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
} SndBits;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 2;
} Bits0e;

typedef struct {
    u8 b0 : 1;
} LoBits8;

#define STATE LFLD(s32, self, 0x3c)

static inline BOOL FadeIs4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

static inline BOOL FadeIs3(void) {
    BOOL r = FALSE;
    if (data_02097d78[3] == 3) {
        r = TRUE;
    } else if (data_02097d78[0] == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL FadeIdle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline void SndStop(void) {
    u8 *p = data_02097e48;
    if (LFLD(SndBits, p, 0).b3) {
        LFLD(u16, p, 6) = 0x8000;
        LFLD(u16, p, 8) = 0x3c;
        LFLD(u16, p, 2) = 0;
    }
    p = data_02097e48;
    LFLD(u16, p, 0x74) = 0x8000;
    LFLD(u16, p, 0x70) = 0;
}

static inline BOOL LoBit1(VObj *self) {
    return LBIT(self, 4).b1 ? TRUE : FALSE;
}

static inline VObj *NewLoader(void) {
    VObj *o = (VObj *)func_0203dd9c(0x4c);
    if (o != NULL) {
        *(void **)o = data_0208b318;
        o->vfunc_08();
    }
    return o;
}

static inline u8 *NewModel2(char *nm, char *arc) {
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        char *n = nm;
        char *a = arc;
        if (n) {
            func_02041218(m + 0x88);
            func_02041440(m, n, 0);
            STD_CopyString(m + 0x2c, a);
        }
    }
    return m;
}

void func_ov000_0217ef3c(VObj *self) {
    char buf[0x20];
    switch (STATE) {
    case 0:
        if (func_02059454(data_02fe152c, 5, 1, 3)) {
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217ea30;
            self->vfunc_48();
            STATE = 1;
        } else {
            STATE = 3;
        }
        return;
    case 1:
        if (LoBit1(self)) {
            return;
        }
        if (!self->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x44) == 2) {
            STATE = 2;
        } else if (LFLD(s32, self, 0x44) == -1) {
            STATE = 3;
        } else if (LFLD(s32, self, 0x44) == 0) {
            STATE = 8;
        } else if (LFLD(s32, self, 0x44) == 1) {
            STATE = 10;
        }
        return;
    case 2:
    case 3:
        SndStop();
        if (!FadeIs3() && !FadeIs4()) {
            func_0203cc58(0xb4000, 1, -1);
        }
        if (STATE == 3) {
            STATE = 4;
        } else {
            STATE = 7;
            return;
        }
        LFLD(s32, self, 0x40) = 0;
    case 4: {
        VObj *o;
        if (!FadeIs4()) {
            return;
        }
        {
            u8 **pmq = &data_ov000_021ccd30;
            u8 *mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x11c));
            LFLD(void *, mq, 0x11c) = NULL;
            mq = *pmq;
            func_ov000_0216f42c(mq, LFLD(void *, mq, 0x118));
            LFLD(void *, mq, 0x118) = NULL;
        }
        LFLD(Bits0e, data_ov000_021ccd54, 0xe).b2 = 2;
        func_020656b4(data_0214a420);
        func_ov000_0218e514(data_ov000_021ccd68, 0xf000);
        LFLD(LoBits8, data_ov000_021ccd64, 0xc).b0 = 0;
        func_0206e900(buf, data_ov000_021cba75);
        o = NewLoader();
        LFLD(VObj *, self, 0x48) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x48)->vfunc_24(buf, data_ov000_021cba7f);
        o = NewLoader();
        LFLD(VObj *, self, 0x50) = o;
        LFLD(s32, o, 0x44) = 2;
        LFLD(VObj *, self, 0x50)->vfunc_24(buf, data_ov000_021cba8b);
        STATE = 5;
    }
    case 5: {
        BOOL ok = TRUE;
        u8 *m;
        u8 *p;
        if (!LFLD(VObj *, self, 0x48)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!LFLD(VObj *, self, 0x50)->vfunc_2c()) {
            ok = FALSE;
        }
        if (!ok) {
            return;
        }
        if (++LFLD(s32, self, 0x40) < 0x1e) {
            return;
        }
        LFLD(s32, self, 0x40) = 0;
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
        LFLD(u8 *, self, 0x4c) = m;
        func_020417e0(LFLD(void *, self, 0x4c), (void *)LFLD(VObj *, self, 0x48)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x4c), 2, 0xffff);
        m = NewModel2(data_ov000_021cba97, data_ov000_021cbaa3);
        LFLD(u8 *, self, 0x54) = m;
        func_020417e0(LFLD(void *, self, 0x54), (void *)LFLD(VObj *, self, 0x50)->vfunc_10());
        func_02041d9c(LFLD(void *, self, 0x54), 0, 0xffff);
        LFLD(s32, LFLD(void *, self, 0x54), 0x150) = -0x1ccd;
        func_0204a2e0(data_02097e4c, 0);
        func_0203cb78(0x3c000, 0, -1);
        p = data_02097e48;
        if (LFLD(SndBits, p, 0).b0) {
            if (LFLD(u16, p, 6) != 0xffff || LFLD(u16, p, 4) != 0x2f) {
                if (LFLD(u16, p, 2) != 10 && LFLD(u16, p, 2) != 0) {
                    if (LFLD(u16, p, 6) != 0xffff) {
                        func_0204aab0(p);
                    }
                    LFLD(u16, p, 2) = 1;
                } else {
                    LFLD(u16, p, 2) = 0;
                }
                LFLD(u16, p, 6) = 0x2f;
                LFLD(u16, p, 8) = 10;
            }
        }
        STATE = 6;
    }
    case 6:
        if (!FadeIdle()) {
            return;
        }
        if (++LFLD(s32, self, 0x40) <= 600) {
            if (!(LFLD(u16, data_02097dc8, 0x12) & 3)) {
                return;
            }
        }
        func_0203cc58(0xf000, 1, -1);
        STATE = 7;
        return;
    case 7:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02187150(data_ov000_021ccd54, 0);
        STATE = 12;
        return;
    case 8:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 9;
    case 9:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        func_ov000_02182b0c(data_ov000_021ccd54);
        STATE = 12;
        return;
    case 10:
        SndStop();
        func_0203cc58(0x3c000, 1, -1);
        STATE = 11;
    case 11:
        if (!FadeIs4()) {
            return;
        }
        LFLD(s32, self, 0x20) = 0x1000;
        self->vfunc_0c(0);
        if (func_ov000_0219bf90()) {
            func_ov000_021b4774();
        }
        func_020623fc();
        { u8 *q = data_ov000_021ccd54; q[0xac] = 1;
        func_ov000_02182590(q + 0xac); }
        STATE = 12;
        break;
    }
}

}

}  // namespace m_Lo_0217ef3c
#undef STATE

// ---- Lo_0217f778
namespace m_Lo_0217f778 {

typedef struct {
    u8 pad_00[0x24];
    s32 unk_24;
    s32 unk_28;
    u8 pad_2c[0x20];
    Model *unk_4c;
    u8 pad_50[4];
    Model *unk_54;
} Obj0217f778;

extern "C" {
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02043d20(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

void func_ov000_0217f778(Obj0217f778 *self) {
    Model *m;
    if (self->unk_24 == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Vec(0x1b, 0x1000, 0x1000, 0x1000);
    self->unk_28 = FX_SinCosTable_[((s32)(self->unk_24 << 14) >> 16) * 2];
    m = self->unk_4c;
    if (m != NULL) {
        Model_PlayPart(m, 0);
    }
    {
        Model *m2 = self->unk_54;
        if (m2 != NULL) {
            Model_PlayPart(m2, 0);
        }
    }
}

}

}  // namespace m_Lo_0217f778

// ---- Lo_0217f8d0
namespace m_Lo_0217f8d0 {

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

VObj *func_ov000_0217f8d0(void) {
    VObj *obj = (VObj *)func_0203dd9c(0x160);
    if (obj != NULL) {
        VOBJ_SET_VTABLE(obj, data_ov000_021cc060);
        obj->vfunc_58();
        VOBJ_SET_VTABLE(obj, data_ov000_021cbf60);
        LFLD(s32, obj, 0x3c) = 0;
        LFLD(s32, obj, 0x40) = 0;
        LFLD(s32, obj, 0x44) = 0;
        LFLD(s32, obj, 0x48) = 0;
        LFLD(s32, obj, 0x4c) = 0;
        LFLD(s32, obj, 0x50) = 0;
        LFLD(s32, obj, 0x54) = 0;
        LFLD(s32, obj, 0x58) = 0;
        LFLD(u16, obj, 0x5c) = 0;
        LFLD(u8, obj, 0x5e) = 0;
        LFLD(u8, obj, 0x5f) = 0;
    }
    obj->vfunc_08(0xc, 0xc8);
    return obj;
}

BOOL func_ov000_0217f958(void *self, void *msg) {
    if (msg != NULL) {
        void *o = LFLD(void *, self, 8);
        VObj *p;
        LBIT(LFLD(void *, o, 0x3c), 0xc).b2 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 0;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 0;
        p = LFLD(VObj *, o, 0x44);
        p->vfunc_a8(func_ov000_02154b58(p, 1));
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov000_0217f9e8(void *self, void *msg) {
    if (msg != NULL) {
        void *o = LFLD(void *, self, 8);
        func_0206ecd4(0x100, (u8 *)o + 0x5f, LFLD(u16, msg, 6));
        if (LFLD(VObj *, o, 0x40) != NULL) {
            func_ov000_0215bb14(LFLD(VObj *, o, 0x40), (u8 *)o + 0x5f);
            LFLD(VObj *, o, 0x40)->vfunc_70();
        }
    }
    return TRUE;
}

BOOL func_ov000_0217fa34(void *self, void *msg) {
    void *o = LFLD(void *, self, 8);
    if (msg != NULL) {
        if (LFLD(u16, msg, 6) == 0) {
            void *a = LFLD(void *, o, 0x3c);
            void *n = LFLD(void *, a, 0x98);
            if (n == NULL) {
                n = NULL;
            } else {
                s32 c = LFLD(s8, a, 0xb1);
                while (c-- != 0) {
                    n = LFLD(void *, n, 0x2c);
                }
            }
            if (LFLD(u16, n, 6) != LFLD(u16, o, 0x5c)) {
                func_0206f21c(LFLD(u16, n, 6), 0);
                if (LFLD(u16, o, 0x5c) != 0) {
                    func_0206f21c(LFLD(u16, o, 0x5c), 1);
                }
            }
            LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
            LFLD(u8, o, 0x5e) = 1;
        }
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        LBIT(LFLD(void *, o, 0x44), 0xc).b1 = 1;
        LBIT(LFLD(void *, o, 0x44), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    }
    return FALSE;
}

}

}  // namespace m_Lo_0217f8d0

// ---- Heap_0217fb44
namespace m_Heap_0217fb44 {

typedef struct {
    u8 pad[0x3c];
    VObj *unk_3c;
    VObj *unk_40;
    VObj *unk_44;
    VObj *unk_48;
    void *unk_4c;
} Obj0217fb44;

extern "C" {

extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
void func_02036838(void *a, void *b, s32 c, s32 d);

void func_ov000_0217fb44(Obj0217fb44 *self) {
    HEAP_DELETE_VOBJ(self->unk_3c);
    HEAP_DELETE_VOBJ(self->unk_40);
    HEAP_DELETE_VOBJ(self->unk_44);
    HEAP_DELETE_VOBJ(self->unk_48);
    HEAP_DELETE_MODEL(self->unk_4c);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
}

}

}  // namespace m_Heap_0217fb44

// ---- Lo_0217fcc4
namespace m_Lo_0217fcc4 {

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

void func_ov000_0217fcc4(void) {
    func_020359d0(data_0208cca0, 7, 0);
    func_020359d0(data_0208cc94, 7, 0);
}

BOOL func_ov000_0217fd04(void) {
    BOOL r = LoTaskObj()->vfunc_2c() ? TRUE : FALSE;
    r = (r & func_02035b90(data_0208cca0, 7)) ? TRUE : FALSE;
    return (r & func_02035b90(data_0208cc94, 7)) ? TRUE : FALSE;
}

}

}  // namespace m_Lo_0217fcc4

// ---- Lo_0217fd70
namespace m_Lo_0217fd70 {

extern "C" {
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern void *data_0208cb7c;
extern u8 data_0214b105[];
extern u8 data_ov000_021cbab1[];
extern u8 data_ov000_021cba33[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cafc0[];
void *func_0203dd9c(u32 size);
void *func_0204c0e8(void *g, u32 id);
void func_ov000_0215bb14(void *o, void *s);
void func_ov000_02173648(void *self);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
s32 func_ov000_02154b58(void *p, s32 a);
s32 func_0206ec48(u16 id);
s32 func_0206f080(u16 id);
u8 *func_0206ede8(u16 id);
void func_ov000_0217f958(void);
void func_ov000_0217f9e8(void);
void func_ov000_0217fa34(void);

static inline s32 ItemCat0217fd70(u16 id) {
    return ((u16)(id & 0xf000) >> 12) - 1;
}

void func_ov000_0217fd70(VObj *self) {
    u8 *e;
    s32 i;
    s32 b;
    s32 n;
    u16 id;
    VObj *o;
    u16 iid;
    void *g;
    u8 *base;
    s32 a;
    if (self->vfunc_28()) {
        return;
    }
    g = data_02149ef8;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb2a8;
    }
    LFLD(VObj *, self, 0x3c) = o;
    LFLD(VObj *, self, 0x3c)->vfunc_10(func_0204c0e8(g, 0x11a));
    LFLD(VObj *, self, 0x3c)->vfunc_14(func_0204c0e8(g, 0x11b));
    LFLD(s32, LFLD(void *, self, 0x3c), 0x20) = 5;
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s16, s, 0x64) = 0;
        LFLD(s16, s, 0x66) = 0x2c;
        LFLD(s16, s, 0x68) = -0xccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x3c);
        LFLD(s32, s, 0x58) = -0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0xccd;
    }
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x400000;
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) |= 0x800000;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc0) = 0x80;
    LFLD(u8, LFLD(void *, self, 0x3c), 0xc1) = 3;
    func_ov000_021547e8(LFLD(void *, self, 0x3c), data_0214b105, data_0208cb7c, 0xb);
    func_ov000_021546ec(LFLD(void *, self, 0x3c), data_ov000_021cbab1, data_ov000_021cba33, 0xffff);
    if (LFLD(s32, self, 0xc) != 0) {
        LFLD(u16, self, 0x5c) = LFLD(s32, self, 0xc);
    }
    id = LFLD(u16, self, 0x5c);
    if (ItemCat0217fd70(id) == 1) {
        a = func_0206ec48(id);
        b = func_0206f080(id);
        e = (u8 *)LFLD(VObj *, self, 0x3c)->vfunc_74(a, id, (u16)b, 1);
        LFLD(s32, e, 0x10) = *func_0206ede8(LFLD(u16, self, 0x5c));
        LFLD(s16, e, 0xa) = 0xb;
        LFLD(s32, e, 0x24) = 4;
    }
    {
        base = data_0214a424 + 0x2a;
        for (i = 0; i < 100; i++) {
            n = base[i];
            iid = i | 0x2000;
            if (n > 0) {
                a = func_0206ec48(iid);
                b = func_0206f080(iid);
                e = (u8 *)LFLD(VObj *, self, 0x3c)->vfunc_74(a, iid, (u16)b, n);
                LFLD(s32, e, 0x10) = *func_0206ede8(LFLD(u16, self, 0x5c));
            }
        }
    }
    LFLD(void *, LFLD(void *, self, 0x3c), 0x8) = self;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x84) = (void *)func_ov000_0217f958;
    LFLD(void *, LFLD(void *, self, 0x3c), 0x88) = (void *)func_ov000_0217f9e8;
    {
        VObj *t = LFLD(VObj *, self, 0x3c);
        t->vfunc_a8(func_ov000_02154b58(t, 0));
    }
    LFLD(VObj *, self, 0x3c)->vfunc_08();
    LFLD(u32, LFLD(void *, self, 0x3c), 0xc) &= ~2;
    o = (VObj *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x40) = o;
    LFLD(s32, o, 0x20) = 2;
    LFLD(s32, LFLD(void *, self, 0x40), 0x24) = 0xf8;
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s16, s, 0x64) = 4;
        LFLD(s16, s, 0x66) = 0x96;
        LFLD(s16, s, 0x68) = -0xccd;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x40);
        LFLD(s32, s, 0x58) = -0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0xccd;
    }
    LFLD(s32, LFLD(void *, self, 0x40), 0x2c) = 1;
    func_ov000_0215bb14(LFLD(void *, self, 0x40), func_0204c0e8(g, 0x11d));
    LFLD(VObj *, self, 0x40)->vfunc_70();
    LFLD(VObj *, self, 0x40)->vfunc_08();
    o = (VObj *)func_0203dd9c(0x1e4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb1b0;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb0b8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cafc0;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x44) = o;
    LFLD(VObj *, self, 0x44)->vfunc_10(func_0204c0e8(g, 0x11c));
    LFLD(s16, LFLD(void *, self, 0x44), 0x68) = -0x666;
    LFLD(VObj *, self, 0x44)->vfunc_08();
    LFLD(void *, LFLD(void *, self, 0x44), 0x8) = self;
    LFLD(void *, LFLD(void *, self, 0x44), 0x84) = (void *)func_ov000_0217fa34;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 2;
    LFLD(u32, LFLD(void *, self, 0x44), 0xc) |= 4;
    o = (VObj *)func_0203dd9c(0xe0);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb5a8;
        o->vfunc_28();
    }
    LFLD(VObj *, self, 0x48) = o;
    LFLD(u32, o, 0xc) |= 0x4000000;
    LFLD(s32, LFLD(void *, self, 0x48), 0x2c) = 1;
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s16, s, 0x64) = 0xa5;
        LFLD(s16, s, 0x66) = 0x12;
        LFLD(s16, s, 0x68) = -0x99a;
    }
    {
        u8 *s = LFLD(u8 *, self, 0x48);
        LFLD(s32, s, 0x58) = 0x100;
        LFLD(s32, s, 0x5c) = 0;
        LFLD(s32, s, 0x60) = -0x99a;
    }
    LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 0x20000000;
    LFLD(VObj *, self, 0x48)->vfunc_f4(1, func_0204c0e8(g, 0x32));
    LFLD(VObj *, self, 0x48)->vfunc_08();
    func_ov000_02173648(self);
}

}

}  // namespace m_Lo_0217fd70
