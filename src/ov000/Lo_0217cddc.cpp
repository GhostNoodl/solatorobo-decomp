#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"

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
