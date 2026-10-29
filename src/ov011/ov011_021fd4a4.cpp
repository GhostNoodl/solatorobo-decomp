#include "ov011/ov011.h"

extern "C" {

struct Ov011Fd4a4 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad0 : 6;
    u8 pad1;
    u16 id;
    u32 pad4;
    s32 unk_08;
    u8 sub[1];
};

#pragma force_active on
void func_ov011_021fd4a4(Ov011Fd4a4 *self) {
    self->b1 = 0;
    self->id = 0xffff;
    self->unk_08 = 0;
    func_ov003_021da48c(self->sub, 1);
}
#pragma force_active reset

struct Ov011Fd4d8Bits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

extern BOOL func_ov000_02198360(void *p, u8 value, BOOL force);
extern BOOL func_ov011_02201578(void *p);
extern BOOL func_ov011_021fa720(void *e, s32 a, s32 b, s32 c, s32 d);

#define BITS4d8(off) FLD(Ov011Fd4d8Bits, self, off)

BOOL func_ov011_021fd4d8(u8 *self, s32 a) {
    BITS4d8(0).b0 = 1;
    BITS4d8(0).b1 = 0;
    BITS4d8(0).b2 = 1;
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0x8) = a;
    FLD(s32, self, 0xc) = 0;
    func_ov003_021da48c(self + 0x20, 1);
    BITS4d8(0x10).b0 = 1;
    FLD(u16, self, 0x12) = 0;
    FLD(u16, self, 0x14) = 0x10;
    FLD(void *, self, 0x18) = func_0203dddc(FLD(u16, self, 0x14) * 4);
    FLD(s32, self, 0x1c) = 0;
    func_ov011_02201578(self + 0x34);
    BITS4d8(0xb4).b0 = 1;
    BITS4d8(0xb4).b1 = 0;
    FLD(u16, self, 0xb6) = 0;
    FLD(s32, self, 0xb8) = -1;
    FLD(s32, self, 0xbc) = 0;
    FLD(s32, self, 0xc0) = 0;
    FLD(s32, self, 0xc4) = 0;
    func_ov003_021da48c(self + 0xc8, 0);
    BITS4d8(0x1b4).b0 = 1;
    BITS4d8(0x1b4).b1 = 0;
    FLD(u16, self, 0x1b6) = 0;
    FLD(s32, self, 0x1b8) = 0;
    FLD(s32, self, 0x1bc) = 0;
    func_ov000_02198360(self + 0x1c0, 2, 0);
    FLD(s32, self, 0x1d8) = -1;
    BITS4d8(0x1d4).b0 = 1;
    FLD(s32, self, 0x1dc) = 0;
    FLD(s32, self, 0x1e0) = 0;
    FLD(u16, self, 0x1d6) = 0;
    BITS4d8(0x1d4).b1 = 0;
    FLD(s32, self, 0x1e4) = 0;
    FLD(s32, self, 0x1e8) = 0;
    FLD(s32, self, 0x1ec) = 0;
    func_ov003_021da48c(self + 0x1f0, 0);
    func_ov011_021fa720(self + 0x204, 1, 0x3333, 0x71c, 0x2000);
    return TRUE;
}

}
