#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02172f7c(void *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

struct Obj021632f0 {
    u8 unk_00[0x8];
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10;
    u8 unk_11[0x3];
    s32 unk_14;
    u8 unk_18[0x10];
    s32 unk_28;
};

void func_ov000_021632f0(Obj021632f0 *self, s32 a, s32 b, s32 c, u8 d) {
    LO_FREE_V(self, 0x20);
    LO_FREE_V(self, 0x24);
    self->unk_14 = a;
    self->unk_08 = b;
    self->unk_0c = c;
    self->unk_10 = d;
    self->unk_28 = 0;
}

}
