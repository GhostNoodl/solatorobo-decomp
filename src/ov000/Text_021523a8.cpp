#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);

void func_ov000_021523a8(VObj *self, s32 arg) {
    u8 *p;
    LO_FREE_V(self, 0x14);
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(u8 *, self, 0x14) = p;
    LFLD(s32, p, 0x28) = 8;
    p = LFLD(u8 *, self, 0x14);
    LFLD(s32, p, 0x24) = arg;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(u16, LFLD(u8 *, self, 0x14), 0x74) = 0x7fff;
    LFLD(u16, LFLD(u8 *, self, 0x14), 0x76) = 0x67f;
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x4) |= 0x40000000;
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x4) |= 0x4;
    func_0204ca70(LFLD(u8 *, self, 0x14));
}

void func_ov000_021524f8(VObj *self, const char *src) {
    u8 *p;
    char buf[0x100];
    char *d;
    LO_FREE_V(self, 0x18);
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(u8 *, self, 0x18) = p;
    d = buf;
    while (*src != 0) {
        if (*src != '\n') {
            *d++ = *src;
        } else {
            *d++ = ' ';
        }
        src++;
    }
    *d = 0;
    LFLD(s32, LFLD(u8 *, self, 0x18), 0x28) = 4;
    p = LFLD(u8 *, self, 0x18);
    LFLD(char *, p, 0x24) = buf;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(u32, LFLD(u8 *, self, 0x18), 0x4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x18), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x18), 0x4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x18), 0x4) |= 0x40000000;
    LFLD(u32, LFLD(u8 *, self, 0x18), 0x4) |= 0x4;
    func_0204ca70(LFLD(u8 *, self, 0x18));
    LFLD(char *, LFLD(u8 *, self, 0x18), 0x24) = NULL;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = LFLD(s32, LFLD(u8 *, self, 0x18), 0x44) + 0x40;
    if (LFLD(s32, self, 0x50) + 0x68 < 0x100) {
        LFLD(s32, self, 0x50) = 0x98;
    }
}
}
