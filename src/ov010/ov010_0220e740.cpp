#include "ov010/ov010.h"

struct Ov010Path {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    Ov010Vec unk_1c;
    u8 unk_28[0x30];
    u8 unk_58[4];
};

extern "C" {

extern void func_02016fa0(s32 a, void *b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);

BOOL func_ov010_0220e740(Ov010Path *self, s32 a, s32 b, s32 c, const Ov010Vec *v, s32 e) {
    self->b0 = 1;
    self->b1 = 0;
    self->unk_18 = a;
    self->unk_02 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = e;
    self->unk_10 = 0x1000;
    self->unk_1c = *v;
    func_02016fa0(b, self->unk_28, c);
    func_ov003_021da48c(self->unk_58, 1);
    return TRUE;
}

}
