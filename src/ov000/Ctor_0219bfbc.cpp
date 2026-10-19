#include "types.h"

#define F(type, off) (*(type *)((u8 *)self + (off)))
#define G(type, off) (*(type *)((u8 *)data_0214a424 + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 b14 : 18;
} B24_0219bfbc;

typedef struct {
    s32 x, y, z;
} Vec_0219bfbc;

typedef struct {
    u16 b0 : 6;
    u16 b6 : 3;
    u16 b9 : 7;
} B22_0219bfbc;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 5;
    u16 b8 : 1;
    u16 b9 : 7;
} G18_0219bfbc;

extern "C" {
extern u8 data_ov000_021cc774[];
extern u8 *data_0214a424;
void func_ov000_0218c2d4(void *self);
void func_ov000_0218fe1c(void *p);
void func_ov000_0218e9c4(void *p);
void func_ov000_021985e8(void *p);
void func_0203d45c(void *q, u16 a, u16 b, u16 c, u16 d);

u8 *func_ov000_0219bfbc(u8 *self) {
    u32 mode;
    func_ov000_0218c2d4(self);
    F(void *, 0) = data_ov000_021cc774;
    func_ov000_0218fe1c(self + 0xac);
    func_ov000_0218e9c4(self + 0x194);
    func_ov000_021985e8(self + 0x2cc);
    func_ov000_0218fe1c(self + 0x368);
    func_ov000_0218e9c4(self + 0x450);
    func_ov000_0218e9c4(self + 0x588);
    func_ov000_021985e8(self + 0x6c0);
    func_ov000_0218fe1c(self + 0x778);
    func_ov000_0218e9c4(self + 0x860);
    F(u16, 0xae8) = 0;
    F(u16, 0xaea) = 0;
    F(u16, 0xaec) = 0;
    F(s32, 0x99c) = 0;
    F(s32, 0x998) = 0;
    F(s32, 0x9b0) = 0;
    F(s32, 0x9b4) = 0;
    F(u8, 0xb28) = 0;
    F(u8, 0xb29) = 0;
    F(u8, 0xb2a) = 0;
    F(u8, 0xb2e) = 0;
    F(u8, 0xb2f) = 0;
    F(u8, 0xb30) = 0;
    F(u8, 0xb31) = 0;
    F(u16, 0x7c) = 0;
    F(u16, 0xb22) = 0;
    F(u16, 0xb2c) = 0;
    F(u16, 0xb32) = 0;
    F(u16, 0xb36) = 0;
    F(u16, 0xb38) = 0;
    F(u16, 0xb1c) = 0xffff;
    F(u16, 0xb1e) = 0xffff;
    F(u16, 0xb20) = 0xffff;
    // The flag word is cleared and its fields set last in this group, after the 0xffff stores.
    F(u32, 0xb24) = 0;
    F(B24_0219bfbc, 0xb24).b5 = 0;
    F(B24_0219bfbc, 0xb24).b7 = F(B24_0219bfbc, 0xb24).b9;
    F(B24_0219bfbc, 0xb24).b12 = 0;
    if (G(G18_0219bfbc, 0x18).b8) {
        F(B24_0219bfbc, 0xb24).b1 = 0;
    } else {
        F(B24_0219bfbc, 0xb24).b1 = 1;
    }
    if (!F(B24_0219bfbc, 0xb24).b1) {
        F(Vec_0219bfbc, 0x75c) = G(Vec_0219bfbc, 0x148);
        u16 v = G(u16, 0x156);
        F(u16, 0x76c) = 0;
        F(u16, 0x76e) = v;
        F(u16, 0x770) = 0;
        F(u8, 0x772) = G(u8, 0x134);
        F(u8, 0x773) = G(u8, 0x135);
        F(u8, 0x774) = G(u8, 0x136);
    }
    F(s32, 0x768) = 0;
    F(s32, 0xaf0) = 0;
    F(s32, 0xaf4) = 0;
    F(s32, 0xaf8) = 0;
    F(s32, 0xafc) = 0;
    F(s32, 0xb00) = 0;
    F(s32, 0xb04) = 0;
    F(s32, 0xb40) = 0;
    F(s32, 0xb44) = 0;
    F(s32, 0xb48) = 0;
    F(s16, 0xb64) = -1;
    F(s16, 0xb66) = -1;
    F(u16, 0xb68) = 0;
    F(u16, 0xb6a) = 0;
    F(u16, 0xb6c) = 0;
    F(u16, 0xb6e) = 0;
    func_0203d45c(self + 0xb70, 0, 0x4000, 0x8000, 0xc000);
    F(s32, 0xb0c) = 0x1000;
    F(s32, 0xb9c) = 0;
    mode = G(G18_0219bfbc, 0x18).b1;
    F(B22_0219bfbc, 0xb22).b6 = 0;
    if (mode == 1) {
        F(B22_0219bfbc, 0xb22).b6 = 2;
    } else if (mode == 2) {
        F(B22_0219bfbc, 0xb22).b6 = 5;
    }
    F(s32, 0xba4) = 0;
    F(s32, 0xba0) = 0;
    F(s32, 0xba8) = 0;
    F(u16, 0xbac) = 0xffff;
    F(u8, 0x16) |= 4;
    return self;
}
}
