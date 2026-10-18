#include "ov000/LoCommon.h"

extern "C" {

void STD_CopyLString(void *dst, const void *src, s32 n);

static inline void LoInitEC44(void *self) {
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x10) = 0x80000;
    LFLD(s32, self, 0x14) = 0xf000;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
}

void func_ov000_02162b40(void *self, const void *s0, const void *s1, const void *s2, const void *s3, s32 d, s32 e, s16 f) {
    STD_CopyLString((u8 *)self + 0xb, s0, 0x20);
    STD_CopyLString((u8 *)self + 0x2b, s1, 0x18);
    STD_CopyLString((u8 *)self + 0x43, s2, 0x20);
    STD_CopyLString((u8 *)self + 0x63, s3, 0x18);
    LFLD(u8, self, 0x7b) = e != 0 ? TRUE : FALSE;
    LFLD(u8, self, 0xa) = 1;
    LFLD(u8, self, 0x6bc) = 1;
    LFLD(s32, self, 0x6c0) = d;
    LFLD(s32, self, 0x6c4) = e;
    LFLD(s16, self, 0x6c8) = f;
}

}
