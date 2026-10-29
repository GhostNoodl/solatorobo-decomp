#include "ov000/LoCommon.h"

typedef struct {
    char s[16];
} LoName16;

extern "C" {

extern void *data_0208cc88;
extern void *data_0208cc94;
extern void *data_02149ef8;
extern u8 *data_02097ce0;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void *func_02035f30(void *a, void *b, s32 c);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void STD_CopyString(void *dst, void *src);
BOOL func_ov000_02152e5c(void *self);
void *func_ov000_0214c084(void);
void func_020708fc(s32 a, LoName16 *out);
void func_02070b98(s32 a, LoName16 *out, s32 b, s32 c);
s32 func_0206ffa0(s32 a);
s32 func_0204c0e8(void *p, s32 a);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, s32 f);
void func_0204ca70(void *win);

typedef struct {
    u32 lo : 2;
    u32 k : 5;
    u32 hi : 25;
} Bits0214c2d0;

void func_ov000_0214c2d0(u8 *self) {
    LoName16 a;
    LoName16 b;
    void *res;
    u8 *m;
    void *fnt;

    LFLD(u32, self, 0xc) |= 0x10;
    LFLD(s32, self, 0x24) = 0x8c;
    LFLD(s32, self, 0x28) = 0x2b;
    LFLD(s16, self, 0x64) = 0;
    LFLD(s16, self, 0x66) = 0xc0 - LFLD(s32, self, 0x28);
    LFLD(s16, self, 0x68) = -0x1000;
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(LFLD(void *, self, 0x10), 0, 0xb);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 0xc);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 0xd);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 0xe);
    }
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *arc;
        void *name;
        name = data_0208cc88;
        arc = data_0208cc94;
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    LFLD(u8 *, self, 0x88) = m;
    {
        void *x = func_02035d5c(LFLD(u8 *, self, 0x88) + 0x2c);
        void *y = func_02034d88(x, LFLD(u8 *, self, 0x88) + 0x4c);
        func_020417e0(LFLD(u8 *, self, 0x88), y);
    }
    LFLD(u32, LFLD(u8 *, self, 0x88), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0x88), 0, 6);
    func_02041c5c(LFLD(u8 *, self, 0x88), (void *)func_ov000_0214c084);
    func_02041c20(LFLD(u8 *, self, 0x88), 6, self);

    func_020708fc(0x1000, &a);
    func_02070b98(0x1000, &b, 1, 2);
    res = func_02034d88(func_02035f30(&a, &b, 2), &b);
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        func_02041218(m + 0x88);
        func_02041440(m, &b, 0);
        STD_CopyString(m + 0x2c, &a);
    }
    LFLD(u8 *, self, 0x84) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0x84), 0, 0xffff);
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 0x80000;
    LFLD(Bits0214c2d0, LFLD(u8 *, self, 0x84), 0x6c).k = 0x1e;
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 0x100000;
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 0x20000;
    LFLD(s32, self, 0x2c) = 1;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = LFLD(s32, self, 0x28) + 0x40;
    LFLD(s32, self, 0x60) = 0;

    fnt = data_02149ef8;
    LFLD(s32, self, 0xb8) = 8;
    LFLD(s32, self, 0xb4) = func_0206ffa0(0x1000);
    LFLD(s32, self, 0xdc) = func_0204c4fc(LFLD(s32, self, 0xb8), LFLD(s32, self, 0xc8), LFLD(s32, self, 0xb4), self + 0xd4, self + 0xd8, LFLD(s8, self, 0xc7) != 0 ? 1 : 0);
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, self, 0xb8);
    LFLD(u16, self, 0x104) = 0x7fff;
    LFLD(u16, self, 0x106) = 0x67f;
    LFLD(s32, self, 0x108) = 0x9000;
    LFLD(u32, self, 0x94) |= 0x40;
    LFLD(u32, self, 0x94) |= 0x1000000;
    LFLD(u32, self, 0x94) |= 0x40000004;
    func_0204ca70(self + 0x90);

    LFLD(s32, self, 0x170) = 4;
    LFLD(s32, self, 0x16c) = func_0204c0e8(fnt, 0x117);
    LFLD(s32, self, 0x194) = func_0204c4fc(LFLD(s32, self, 0x170), LFLD(s32, self, 0x180), LFLD(s32, self, 0x16c), self + 0x18c, self + 0x190, LFLD(s8, self, 0x17f) != 0);
    LFLD(s32, data_02097ce0, 4) = LFLD(s32, self, 0x170);
    LFLD(u32, self, 0x14c) |= 0x40;
    LFLD(u32, self, 0x14c) |= 0x1000000;
    LFLD(u32, self, 0x14c) |= 0x40000004;
    func_0204ca70(self + 0x148);
    LBIT(self, 0xc).b0 = 1;
}

}
