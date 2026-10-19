#include "ov000/LoCommon.h"

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
