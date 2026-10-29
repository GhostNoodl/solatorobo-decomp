#include "types.h"
#include "nitro/std.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State02195d88;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 3;
    u16 b8 : 1;
    u16 rest : 7;
} Bits02195d88;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 rest : 4;
} Bits8_02195d88;

typedef struct {
    u16 x, y, z;
} Rot02195d88;

extern "C" {
extern char data_ov000_021cc45c[];
extern u8 *data_0214a424;
void func_ov000_02191008(void *a);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_0203f364(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u8 *func_ov000_02199ba0(void *a);
u16 func_ov000_02199bc8(void *a, void *pos, u16 t, s32 n);
u8 *func_ov000_0219bf90(void);
void func_ov003_021f0c60(void *self, s32 a);

void func_ov000_02195d88(u8 *self) {
    State02195d88 *s = LFLD(State02195d88 *, self, 0x40);
    switch (s->st) {
    case 0:
        LFLD(Bits8_02195d88, self, 0x93).b1 = 1;
        if (LFLD(void *, self, 0x38) != NULL) {
            char *name = LFLD(char *, LFLD(u8 *, self, 0x4c), 0xc);
            if (name != NULL) {
                if (STD_CompareString(name, data_ov000_021cc45c) == 0) {
                    func_ov000_02191008(LFLD(void *, self, 0x38));
                } else {
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), name, 0x1000, 0);
                    func_ov000_021915a0(LFLD(void *, self, 0x38));
                }
            }
            LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = 0x1f;
        }
        if (LFLD(u8 *, self, 0x44) != NULL) {
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(Bits02195d88, q, 0x22).b0 = 0;
            LFLD(Bits02195d88, q, 0x22).b1 = 0;
        }
        if (LFLD(u8 *, self, 0x48) != NULL) {
            u8 *p = LFLD(u8 *, self, 0x48);
            LFLD(s32, p, 0x50) = 0;
            LFLD(s32, p, 0x54) = 0;
            LFLD(s32, p, 0x58) = 0;
            p = LFLD(u8 *, self, 0x48);
            LFLD(Bits02195d88, p, 0x9a).b0 = 0;
            LFLD(Bits02195d88, p, 0x9a).b3 = 0;
            func_0203f364(p);
            p = LFLD(u8 *, self, 0x48);
            LFLD(Bits02195d88, p, 0x9a).b1 = 0;
            LFLD(Bits02195d88, p, 0x9a).b4 = 0;
        }
        LFLD(u16, self, 0x90) = 0xffff;
        if (LFLD(void *, self, 0x58) != NULL) {
            LFLD(Bits02195d88, self, 0xcc).b0 = 0;
        }
        if (LFLD(Bits02195d88, LFLD(u8 *, self, 0xb0), 2).b8) {
            LFLD(Bits8_02195d88, LFLD(u8 *, self, 0x4c), 0x18).b0 = 1;
        }
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LFLD(State02195d88 *, self, 0x40)->timer = 2;
        LFLD(State02195d88 *, self, 0x40)->st++;
        break;
    case 1: {
        u8 *t = func_ov000_02199ba0(LFLD(void *, self, 0x4c));
        u16 r;
        u8 *pl;
        if (t != NULL) {
            r = func_ov000_02199bc8(LFLD(void *, self, 0x4c), self + 0x70, LFLD(State02195d88 *, self, 0x40)->timer, 10);
            LFLD(Rot02195d88, self, 0x7c) = LFLD(Rot02195d88, t, 0x7c);
            LFLD(State02195d88 *, self, 0x40)->timer = r;
            if (LFLD(u8, LFLD(u8 *, self, 0x4c), 1) != 3) {
                break;
            }
            if (r < 10) {
                break;
            }
            pl = func_ov000_0219bf90();
            if (LFLD(u16, pl, 0xc) == LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c)) {
                u32 n = LFLD(u16, data_0214a424, 0x16) + 1;
                if (n >= 0xffff) {
                    n = 0xffff;
                }
                LFLD(u16, data_0214a424, 0x16) = n;
                if (LFLD(u8 *, self, 0x44) != NULL) {
                    u8 *q = LFLD(u8 *, self, 0x44);
                    LFLD(Bits02195d88, q, 0x22).b0 = 0;
                    LFLD(Bits02195d88, q, 0x22).b1 = 0;
                }
                if (LFLD(u8 *, self, 0x48) != NULL) {
                    u8 *p = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02195d88, p, 0x9a).b0 = 0;
                    LFLD(Bits02195d88, p, 0x9a).b3 = 0;
                    func_0203f364(p);
                    p = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02195d88, p, 0x9a).b1 = 0;
                    LFLD(Bits02195d88, p, 0x9a).b4 = 0;
                }
                if (LFLD(u8, LFLD(u8 *, self, 0x4c), 3) != 0) {
                    LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
                    func_ov003_021f0c60(self, 0);
                }
            }
            func_ov000_02198360(LFLD(void *, self, 0x40), 0x15, 0);
        } else {
            func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
        }
        break;
    }
    }
}
}
