#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_0214b105[];
extern void *data_0208cb7c;
extern void *data_0208cc94;
extern void *data_0208cc88;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9b04[];
extern u8 data_ov000_021c9b0a[];

void func_ov000_0216a608(void *self) {
    void *res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *nm = data_0208cb7c;
        func_02041218(m + 0x88);
        func_02041440(m, nm, 0);
    }
    LFLD(void *, self, 0x9c) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 2;
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 0x80000;
    func_02041d9c(LFLD(void *, self, 0x9c), 0, 2);
    {
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
    func_02041d9c(LFLD(void *, self, 0xa0), 0, 0x21);
    }
    LFLD(s32, self, 0x28) = 2;
    LFLD(s32, self, 0x30) = 0xc000;
    LFLD(u32, self, 0xc) |= 0x1a0;
    LFLD(s32, self, 0x50) = 0x30;
    LFLD(s32, self, 0x54) = 6;
    LFLD(s32, self, 0x58) = 1;
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x3c) = 0x20;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x74) = 0x2d;
    LFLD(s32, self, 0x78) = 0xae;
    LFLD(s32, self, 0x7c) = 0xffffe666;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9b04);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9b0a);
}

}
