#include "ov000/VObj.h"

class Obj021c3aa0Sub : public VObj {
public:
    u8 unk_04[0x60];
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
};

typedef struct {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0x4];
    s32 unk_1c;
    u8 unk_20[0x10];
    Obj021c3aa0Sub *unk_30;
} Obj021c3aa0;

static inline void Set(Obj021c3aa0Sub *p, s16 x, s16 y, s16 z) {
    p->unk_64 = x;
    p->unk_66 = y;
    p->unk_68 = z;
}

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x74];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u16 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
    s32 unk_b8;
    s32 unk_bc;
    s32 unk_c0;
    s32 unk_c4;
    s32 unk_c8;
    u8 unk_cc;
    u8 unk_cd;
    u8 unk_ce;
    s32 unk_d0;
    u8 unk_d4;
    s32 unk_d8;
    u8 unk_dc;
    u8 unk_dd;
    u8 unk_de;
    u8 unk_df;
    s32 unk_e0;
    s32 unk_e4;
    s32 unk_e8;
    s32 unk_ec;
    u8 unk_f0;
} Obj021c3af4;

extern "C" {

void func_ov000_021c3aa0(Obj021c3aa0 *self) {
    Obj021c3aa0Sub *sub = self->unk_30;
    if (sub == NULL) {
        return;
    }
    Set(sub, (self->unk_0c >> 12) + ((0x100 - self->unk_1c) >> 1), (self->unk_10 >> 12) + 0x28, self->unk_14);
    self->unk_30->vfunc_20();
}

void func_ov000_021c3af4(Obj021c3af4 *self) {
    self->unk_0c |= 0x40000;
    self->unk_0c |= 0x10;
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->unk_8c = 0;
    self->unk_90 = 0;
    self->unk_94 = 0;
    self->unk_98 = 0;
    self->unk_9c = 0;
    self->unk_a4 = 0;
    self->unk_a0 = 0;
    self->unk_a8 = 0;
    self->unk_ac = 7;
    self->unk_b0 = 0x80000000;
    self->unk_b4 = 0x80000000;
    self->unk_b8 = 0x80000000;
    self->unk_bc = 0;
    self->unk_c0 = 0xc8000;
    self->unk_c8 = 0x19a;
    self->unk_c4 = 0;
    self->unk_cc = 0;
    self->unk_cd = 0;
    self->unk_ce = 0;
    self->unk_d0 = 0;
    self->unk_d4 = 0;
    self->unk_d8 = 0;
    self->unk_dc = 0;
    self->unk_dd = 0;
    self->unk_de = 0;
    self->unk_df = 0;
    self->unk_e0 = 0x7800;
    self->unk_e4 = 0;
    self->unk_e8 = 0;
    self->unk_ec = 0;
    self->unk_f0 = 1;
}

}
