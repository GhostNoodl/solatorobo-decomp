#include "ov000/LoCommon.h"

extern "C" {
extern char data_ov000_021cabf4[];
s32 STD_GetStringLength(const char *s);
void STD_CopyString(char *dst, const char *src);
char *STD_SearchString(char *str, const char *sub);
void *func_0203de84(u32 size, s32 align);
void func_ov000_0215429c(void *self);

void func_ov000_02158b48(VObj *self) {
    u16 line;
    BOOL done;
    char *p;
    char *s;
    u8 *n;
    LFLD(s16, self, 0x64) = (0x100 - LFLD(s32, self, 0x24)) >> 1;
    line = 0;
    done = FALSE;
    if (LFLD(char *, self, 0xe4) == NULL) {
        LFLD(s32, self, 0xe8) = STD_GetStringLength(LFLD(char *, self, 0xe0)) + 1;
        LFLD(char *, self, 0xe4) = (char *)func_0203de84(LFLD(s32, self, 0xe8), 4);
        STD_CopyString(LFLD(char *, self, 0xe4), LFLD(char *, self, 0xe0));
    }
    s = LFLD(char *, self, 0xe4);
    do {
        p = STD_SearchString(s, data_ov000_021cabf4);
        if (p != NULL) {
            *p = 0;
        } else {
            done = TRUE;
        }
        self->vfunc_74(s, line, 0xffff, 0xffff);
        s = p + 1;
        line++;
    } while (!done && *s != 0);
    func_ov000_0215429c(self);
    LFLD(s32, LFLD(u8 *, self, 0xac), 0x10) = (LFLD(s32, self, 0x24) - 0x10) << 12;
    for (n = LFLD(u8 *, self, 0x94); n != NULL; n = LFLD(u8 *, n, 0x2c)) {
        if (LFLD(u16, n, 6) == 0) {
            break;
        }
    }
    self->vfunc_a8(n);
}
}

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);

void func_ov000_02158c60(VObj *self, s32 arg) {
    u8 *p;
    LO_FREE_V(self, 0xec);
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(u8 *, self, 0xec) = p;
    LFLD(s32, p, 0x28) = 8;
    p = LFLD(u8 *, self, 0xec);
    LFLD(s32, p, 0x24) = arg;
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(u32, LFLD(u8 *, self, 0xec), 0x4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0xec), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0xec), 0x4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0xec), 0x4) |= 0x40000000;
    LFLD(u32, LFLD(u8 *, self, 0xec), 0x4) |= 0x4;
    func_0204ca70(LFLD(u8 *, self, 0xec));
}
}
