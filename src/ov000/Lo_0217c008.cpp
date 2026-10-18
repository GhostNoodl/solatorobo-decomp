#include "ov000/LoCommon.h"

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
