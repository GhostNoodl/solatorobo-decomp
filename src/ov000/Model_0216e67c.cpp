#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 2;
    u32 pri : 5;
    u32 rest : 25;
} Bits6c0216e67c;

typedef struct {
    u32 b0 : 1;
    u32 busy : 1;
    u32 b2 : 15;
    u32 b17 : 1;
    u32 rest : 14;
} Bits0216e67c;

extern "C" {
extern char data_0214b105[];
extern void *data_0208cb7c;
extern void *data_0208cc94;
extern void *data_0208cc88;
void *func_0203dd9c(u32 size);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c34(void *model, s32 a, void *cb, void *arg);
void *func_ov000_0216d5b0(void);

void func_ov000_0216e67c(u8 *self) {
    void *res;
    u8 *m;
    u8 *m2;
    void *res2;
    if (LFLD(Bits0216e67c, self, 0).busy == 1) {
        return;
    }
    res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *n = data_0208cb7c;
        func_02041218(m + 0x88);
        func_02041440(m, n, 0);
    }
    LFLD(u8 *, self, 0x10) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 2;
    LFLD(s32, LFLD(u8 *, self, 0x10), 0x150) = -0x2000;
    func_02041d9c(LFLD(u8 *, self, 0x10), 0, 0xc);
    func_02041d9c(LFLD(u8 *, self, 0x10), 0, 0xf);
    LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 0x80000;
    LFLD(Bits6c0216e67c, LFLD(u8 *, self, 0x10), 0x6c).pri = 0x1e;
    res2 = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    m2 = (u8 *)func_0203dd9c(0x160);
    if (m2) {
        void *n = data_0208cc88;
        func_02041218(m2 + 0x88);
        func_02041440(m2, n, 0);
    }
    LFLD(u8 *, self, 0x14) = m2;
    func_020417e0(m2, res2);
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x6c) |= 2;
    LFLD(s32, LFLD(u8 *, self, 0x14), 0x150) = -0x2000;
    {
        u8 *q = LFLD(u8 *, self, 0x14);
        LFLD(s32, q, 0x144) = 0x800;
        LFLD(s32, q, 0x148) = 0x800;
        LFLD(s32, q, 0x14c) = 0x800;
    }
    func_02041d9c(LFLD(u8 *, self, 0x14), 0, 0x1e);
    func_02041c34(LFLD(u8 *, self, 0x14), 0x1e, (void *)func_ov000_0216d5b0, self);
    func_02041d9c(LFLD(u8 *, self, 0x14), 0, 0x1f);
    func_02041c34(LFLD(u8 *, self, 0x14), 0x1f, (void *)func_ov000_0216d5b0, self);
    func_02041d9c(LFLD(u8 *, self, 0x14), 0, 0x20);
    LFLD(u32, LFLD(u8 *, self, 0x14), 0x6c) |= 0x80000;
    LFLD(Bits6c0216e67c, LFLD(u8 *, self, 0x14), 0x6c).pri = 0x1e;
    LFLD(Bits0216e67c, self, 0).b17 = 1;
    LFLD(Bits0216e67c, self, 0).busy = 1;
}
}
