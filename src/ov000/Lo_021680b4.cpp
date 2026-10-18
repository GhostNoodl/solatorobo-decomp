#include "ov000/LoCommon.h"

extern "C" {
extern char data_0214b105[];
extern void *data_0208cb7c;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9aec[];
extern u8 data_ov000_021c9af2[];

void func_ov000_021680b4(void *self) {
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
    func_02041d9c(LFLD(void *, self, 0x9c), 0, 3);
    LFLD(s32, self, 0x30) = 0xc000;
    LFLD(s32, self, 0x50) = 0x44;
    LFLD(s32, self, 0x54) = 4;
    LFLD(s32, self, 0x28) = 0;
    LFLD(u32, self, 0xc) |= 0x240;
    LFLD(s32, self, 0x58) = 1;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x7c) = -0x2000;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9aec);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9af2);
}

}
