#include "ov000/VObj.h"
#include "Main/Sys/Pad.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

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
