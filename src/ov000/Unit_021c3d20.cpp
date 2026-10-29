#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern void *data_0208cc88;
extern void *data_0208cc94;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *STD_CopyString(void *dst, void *src);
BOOL func_ov000_02152e5c(void *self);
void func_ov000_0215ec44(void *self);
void func_ov000_0215e8b0(void *self);
void *func_ov000_021c77bc(u8 *self, u16 *cmd, void *arr, u16 *count);
void *func_ov000_021c782c(u8 *self, void *req, void *buf, u16 *count);

void func_ov000_021c3d20(u8 *self) {
    void *p;
    u8 *m;
    u8 *o;

    LBIT(self, 0xc).b1 = 0;
    LFLD(s32, self, 0x2c) = 1;
    {
        s32 z = LFLD(s16, self, 0x68);
        LFLD(s32, self, 0x58) = -(LFLD(s32, self, 0x24) + 0x20);
        LFLD(s32, self, 0x60) = z;
    }
    LFLD(s32, self, 0x5c) = 0;
    p = LFLD(void *, self, 0x94);
    if (p != NULL) {
        LFLD(s32, self, 0x28) = LFLD(s32, self, 0x20) * LFLD(s32, p, 0x18);
    } else {
        LFLD(s32, self, 0x28) = LFLD(s32, self, 0x20) * 0xc;
    }
    LFLD(s32, self, 0x28) += 0xf;
    LFLD(s32, self, 0xc0) = (LFLD(s32, self, 0x28) - 0x14) << 12;
    if (LFLD(s32, self, 0x98) < LFLD(s32, self, 0x20)) {
        LFLD(s32, self, 0xc8) = 0x1000;
    } else {
        LFLD(s32, self, 0xc8) = FX_Div(LFLD(s32, self, 0x20) << 12, LFLD(s32, self, 0x98) << 12);
    }
    LFLD(s32, self, 0xc4) = FX_Div(LFLD(s32, self, 0x9c) << 12, LFLD(s32, self, 0x98) << 12);
    if (LFLD(s32, self, 0xb4) == (s32)0x80000000) {
        LFLD(s32, self, 0xb4) = 0x4000;
    }
    if (LFLD(s32, self, 0xb0) == (s32)0x80000000) {
        if (LFLD(u32, self, 0xc) & 0x40000) {
            LFLD(s32, self, 0xb0) = (((LFLD(s32, self, 0x24) << 12) - 0x20000) >> 12) - 4;
        } else {
            LFLD(s32, self, 0xb0) = LFLD(s32, self, 0x24) - 4;
        }
    }
    if (LFLD(s32, self, 0xb8) == (s32)0x80000000) {
        LFLD(s32, self, 0xb8) = 0x20000;
    }
    LFLD(void *, self, 0xa0) = LFLD(void *, self, 0x94);
    if (func_ov000_02152e5c(self)) {
        func_02041d9c(LFLD(void *, self, 0x10), 0, 2);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 4);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 6);
        func_02041c5c(LFLD(void *, self, 0x10), (void *)func_ov000_021c77bc);
        func_02041c20(LFLD(void *, self, 0x10), 2, self);
    }
    if (LFLD(u32, self, 0xc) & 0x400000) {
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
        LFLD(u8 *, self, 0x84) = m;
        func_020417e0(LFLD(u8 *, self, 0x84), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0x84) + 0x4c));
        LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 2;
        func_02041d9c(LFLD(u8 *, self, 0x84), 0, 6);
        func_02041c20(LFLD(u8 *, self, 0x84), 6, self);
        if (LFLD(u32, self, 0xc) & 0x800000) {
            func_02041d9c(LFLD(u8 *, self, 0x84), 0, 7);
        }
        func_02041c5c(LFLD(u8 *, self, 0x84), (void *)func_ov000_021c782c);
    }
    if (LFLD(void *, self, 0x90) == NULL) {
        o = (u8 *)func_0203dd9c(0x2c);
        if (o != NULL) {
            func_ov000_0215ec44(o);
        }
        LFLD(u8 *, self, 0x90) = o;
        func_ov000_0215e8b0(o);
        LFLD(s32, LFLD(u8 *, self, 0x90), 0x10) = LFLD(s32, self, 0xb0) << 12;
        LFLD(u32, LFLD(u8 *, LFLD(u8 *, self, 0x90), 0x28), 0x6c) &= ~0x200000;
    }
    LBIT(self, 0xc).b0 = 1;
}
}
