#include "ov011/ov011.h"

struct Ov011Tw108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 unk_02;
    s16 unk_04;
};

struct Ov011Ea {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov011B0a {
    u16 lo : 7;
    u16 mid : 3;
    u16 rest : 6;
};

extern "C" {

void func_ov000_0218d988(void *self, void *target, s32 c);
void func_ov000_02191690(void *a);
void func_ov000_02191708(void *a);
void func_ov000_021911c8(void *a, s32 b);

#pragma force_active on
void func_ov011_0220023c(void *self) {
    void *pl;
    void *q;
    s32 s;
    if (FLD(Ov011Tw108 *, self, 0x108) == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    q = FLD(void *, self, 0xb0);
    if (q != NULL && pl != NULL && (s = FLD(Ov011Tw108 *, self, 0x108)->unk_02) != 0) {
        func_ov000_0218d988(self, pl, Ov011_FxMul(FLD(s16, q, 2), s));
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b1) {
        FLD(Ov011Ea, self, 0xea).lo = 2;
    } else {
        FLD(Ov011Ea, self, 0xea).lo = FLD(Ov011B0a, FLD(void *, self, 0xb0), 0xa).mid;
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b0) {
        func_ov000_02191690(FLD(void *, self, 0x38));
    } else {
        func_ov000_02191708(FLD(void *, self, 0x38));
    }
    func_ov000_021911c8(FLD(void *, self, 0x38), FLD(Ov011Tw108 *, self, 0x108)->unk_04);
}
#pragma force_active reset
}
