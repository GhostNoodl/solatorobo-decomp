#include "ov010/ov010.h"

struct Ov010FxSet {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[5];
    u16 unk_06;
    u8 unk_08[4];
    s32 fx0;
    s32 fx1;
};

extern "C" {
extern void *data_0214a420;
extern void func_02065804(void *a, s32 b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02196060(void *self);
extern void *func_ov000_02199ba0(void *p);
extern void func_ov010_02203bf8(Ov010FxSet *p);

void func_ov010_0220366c(void *self) {
    if (FLD(u16 *, self, 0x40)[0] == 0) {
        Ov010FxSet *s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 0;
            func_02065804(data_0214a420, s->fx0);
            s->fx0 = 0;
        }
        s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b2 = 0;
            func_02065804(data_0214a420, s->fx1);
            s->fx1 = 0;
        }
    }
    func_ov000_02195d88(self);
}

void func_ov010_022036fc(void *self) {
    BOOL first = FALSE;
    if (FLD(u16 *, self, 0x40)[0] == 0) {
        first = TRUE;
    }
    func_ov000_02196060(self);
    if (first) {
        Ov010FxSet *s = FLD(Ov010FxSet *, self, 0xd8);
        if (s->b0) {
            s->b1 = 1;
            s->unk_06 = 0x3000;
        }
        Ov010_VecSet(&FLD(Ov010Vec, self, 0xa0), 0, 0, 0);
        FLD(Ov010Flags8, self, 0xce).b2 = 1;
        FLD(s32, self, 0x9c) = 0x4c0;
        FLD(u16, self, 0x90) = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0x90);
    }
    func_ov010_02203bf8(FLD(Ov010FxSet *, self, 0xd8));
}
}
