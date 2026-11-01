#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
} Bits0218b420;

struct Obj0218b420 {
    u8 unk_00[0x44];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    u8 unk_84[0x1e];
    Bits0218b420 unk_a2;
};

void func_ov000_0218b420(Obj0218b420 *self) {
    s32 na, a, nb, b, c, nc, y;
    if (!self->unk_a2.b2) {
        na = 0x80000000;
        a = 0x7fffffff;
    } else {
        a = self->unk_7c;
        na = -a;
    }
    if (!self->unk_a2.b1) {
        nb = 0x80000000;
        b = 0x7fffffff;
    } else {
        b = self->unk_74;
        nb = -b;
    }
    self->unk_48 = na;
    self->unk_54 = a;
    self->unk_44 = nb;
    if (!self->unk_a2.b2) {
        nc = 0x80000000;
        c = 0x7fffffff;
    } else {
        c = self->unk_80;
        nc = -c;
    }
    y = self->unk_78;
    self->unk_60 = nc;
    self->unk_4c = nb;
    self->unk_50 = b;
    self->unk_58 = b;
    self->unk_5c = -y;
    self->unk_64 = -y;
    self->unk_68 = y;
    self->unk_6c = c;
    self->unk_70 = y;
}
}
