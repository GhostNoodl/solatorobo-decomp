#include "ov010/ov010.h"

struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
};

extern "C" {
extern Ov010Vec data_ov010_0220fe38;
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void func_ov010_02203bf8(Ov010FxSet *p);

void func_ov010_02202c9c(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        Ov010FxSet *s;
        FLD(u8, FLD(void *, self, 0x38), 0xbe) = 0x1f;
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x1000;
        }
        FLD(u16, FLD(void *, self, 0x40), 0)++;
    }
    {
        FLD(s32, self, 0xe0) = Ov010_FxMul(FLD(s32, self, 0xe0), 0xf80);
        FLD(s32, self, 0xe4) = Ov010_FxMul(FLD(s32, self, 0xe4), 0xf80);
        FLD(s32, self, 0xe8) = Ov010_FxMul(FLD(s32, self, 0xe8), 0xf80);
    }
    VEC_MultAdd(4, &data_ov010_0220fe38, &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0xe0));
    VEC_Add(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xe0), &FLD(Ov010Vec, self, 0x70));
    if (FLD(Ov010FxSet *, self, 0xd8) != NULL) {
        func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
    }
}
}
