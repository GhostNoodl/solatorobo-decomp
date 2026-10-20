#include "ov000/LoCommon.h"

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
