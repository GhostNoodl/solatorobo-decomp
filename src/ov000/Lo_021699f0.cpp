#include "ov000/LoCommon.h"

extern "C" {
extern char data_0214b105[];
extern void *data_0208cb7c;
extern void *data_0208cc94;
extern void *data_0208cc88;
extern u8 data_ov000_021c9ab6[];
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

void func_ov000_021699f0(u8 *self) {
    void *res;
    u8 *m;
    switch (LFLD(s32, self, 0x9c)) {
    case 0:
        LFLD(s32, self, 0x54) = 7;
        LFLD(s32, self, 0x38) = 0;
        LFLD(s32, self, 0x3c) = 0x20;
        LFLD(s32, self, 0x40) = 0;
        LFLD(s32, self, 0x74) = 0x2d;
        LFLD(s32, self, 0x78) = 0xb6;
        LFLD(s32, self, 0x7c) = -0x199a;
        LFLD(u8, self, 0xa8) = 0xff;
        break;
    case 1:
        LFLD(s32, self, 0x54) = 7;
        LFLD(s32, self, 0x38) = 0;
        LFLD(s32, self, 0x3c) = -0x10;
        LFLD(s32, self, 0x40) = 0;
        LFLD(s32, self, 0x74) = 0x2a;
        LFLD(s32, self, 0x78) = 3;
        LFLD(s32, self, 0x7c) = -0x199a;
        LFLD(u8, self, 0xa8) = 1;
        func_ov000_0215fdfc(self, 2, data_ov000_021c9ab6);
        break;
    }
    res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *nm = data_0208cb7c;
        func_02041218(m + 0x88);
        func_02041440(m, nm, 0);
    }
    LFLD(void *, self, 0xa4) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, self, 0xa4), 0x6c) |= 2;
    LFLD(u32, LFLD(void *, self, 0xa4), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(void *, self, 0xa4), 0x6c) |= 0x80000;
    func_02041d9c(LFLD(void *, self, 0xa4), 0, (u16)LFLD(s32, self, 0x9c));
    if (LFLD(u8, self, 0xa8) != 0xff) {
        u8 *m2;
        void *res2;
        res2 = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        m2 = (u8 *)func_0203dd9c(0x160);
        if (m2) {
            void *nm = data_0208cc88;
            func_02041218(m2 + 0x88);
            func_02041440(m2, nm, 0);
        }
        LFLD(void *, self, 0xa0) = m2;
        func_020417e0(m2, res2);
        LFLD(u32, LFLD(void *, self, 0xa0), 0x6c) |= 2;
        LFLD(u32, LFLD(void *, self, 0xa0), 0x6c) |= 0x200000;
        LFLD(u32, LFLD(void *, self, 0xa0), 0x6c) |= 0x80000;
        func_02041d9c(LFLD(void *, self, 0xa0), 0, LFLD(u8, self, 0xa8));
    }
    LFLD(s32, self, 0x28) = 2;
    LFLD(s32, self, 0x30) = 0xc000;
    LFLD(s32, self, 0x4c) = 0x400;
    LFLD(u32, self, 0xc) |= 0x1a0;
}
}
