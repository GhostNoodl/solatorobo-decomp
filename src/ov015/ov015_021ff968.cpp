#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_022128fc[];
void func_ov015_02209270(void *p);
void func_0203f2b8(void *p);
void func_ov000_02191b04(void *p);
void func_ov000_0218fee4(void *p);
void func_ov000_0218ea20(void *p);
void func_ov015_0220900c(void *p);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov015_022121b4(u8 *self);
void func_ov015_022123c4(u8 *self);
void func_ov000_02191318(void *a, s32 b);
void func_ov015_02209790(u8 *self, s32 a);
void func_ov015_02209b80(u8 *self, s32 a, s32 b);
u8 *func_ov015_0220c93c(u8 *self);

void *func_ov015_021ff968(u8 *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    func_0203f2b8(self + 0x568);
    func_ov000_02191b04(self + 0x54c);
    func_ov000_0218fee4(self + 0x464);
    func_ov000_0218ea20(self + 0x32c);
    func_ov000_0218fee4(self + 0x244);
    func_ov000_0218ea20(self + 0x10c);
    func_ov015_0220900c(self + 0xc0);
    func_0203de1c(self);
    return self;
}

void *func_ov015_021ff9d4(void *self) {
    func_ov000_02191b04(self);
    return self;
}

void func_ov015_021ff9e8(u8 *self) {
    u8 *n;
    s32 cnt;
    s32 i;
    func_ov015_022121b4(FLD(u8 *, self, 0x10));
    {
        u8 *p = FLD(u8 *, self, 0x10);
        i = 0;
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0x1800;
        FLD(s32, p, 0x14) = 0x1800 - 0x72000;
    }
    {
        s32 v = FLD(s32, FLD(u8 *, self, 0x28), 0x10);
        u8 *p = FLD(u8 *, self, 0x10);
        FLD(s32, p, 0x18) = v;
        FLD(s32, p, 0x1c) = v;
        FLD(s32, p, 0x20) = v;
    }
    FLD(s32, FLD(u8 *, self, 0x10), 0x30) = FLD(s32, FLD(u8 *, self, 0x28), 0x8);
    func_ov015_022123c4(FLD(u8 *, self, 0x10));
    FLD(s32, FLD(u8 *, self, 0x14), 0x28c) = FLD(s32, FLD(u8 *, self, 0x28), 0xc);
    VCALL(FLD(void *, self, 0x14))->v14();
    FLD(u16, FLD(u8 *, self, 0x1c), 0xd3c) = 2;
    n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4);
    cnt = FLD(s32, FLD(u8 *, self, 0x24), 0xc);
    for (; n != NULL; n = FLD(u8 *, n, 0xc), i++) {
        u8 *obj = FLD(u8 *, n, 0x4);
        u8 *m = (u8 *)func_0203dd9c(0x40);
        s32 q;
        if (m != NULL) m = func_ov015_0220c93c(m);
        func_ov015_02209b80(obj, (s32)m, 5);
        q = FX_Div(i << 12, cnt << 12);
        FLD(s32, obj, 0x40) = Ov015_FxMul(q, 0x64000) - 0x32000;
        FLD(s32, obj, 0x44) = -0x32000;
        FLD(s32, obj, 0x48) = Ov015_FxMul(q, -0x41000) - 0x4b000;
        func_ov000_02191318(obj + 0x244, Ov015_FxMul(q, 0x3c000));
        FLD(s32, obj, 0xac) = -0x32000;
        FLD(s32, obj, 0xb0) = 0x32000;
        FLD(s32, obj, 0xb4) = -0x4b000;
        FLD(s32, obj, 0xb8) = -0x8c000;
        func_ov015_02209790(obj, 1);
    }
}

}
