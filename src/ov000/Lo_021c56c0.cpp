#include "ov000/LoCommon.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} NodeBits;

extern "C" {
void func_ov000_021c4460(void *self);
void func_ov000_021c4b00(void *self);
void func_ov000_0215f330(void *p);
void func_ov000_021c4c10(void *self);

struct Obj021c56c0 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x18];
    s32 unk_20;
    u8 unk_24[0x70];
    u8 *unk_94;
    u8 unk_98[0x4];
    s32 unk_9c;
    u8 *unk_a0;
    u8 unk_a4[0x30];
    s8 unk_d4;
    u8 unk_d5[0x3];
    s32 unk_d8;
    u8 unk_dc[0x3];
    u8 unk_df;
    u8 unk_e0[0x14];
    void *unk_f4;
    void *unk_f8;
    void *unk_fc;
};

void func_ov000_021c56c0(Obj021c56c0 *self) {
    s32 i;
    u8 *n;

    if (self->unk_04 == 2) {
        if (LBIT(self, 0xc).b1) {
            self->unk_04 = 1;
        }
        func_ov000_021c4460(self);
        func_ov000_021c4b00(self);
        self->unk_d4++;
        if (self->unk_d4 < 20) {
            self->unk_d8 += LO_FX_MUL(0x6000 - self->unk_d8, 0x19a);
        } else if (self->unk_d4 >= 50) {
            self->unk_d4 = 0;
            self->unk_d8 = 0;
        } else {
            self->unk_d8 += LO_FX_MUL(0 - self->unk_d8, 0xcd);
        }
        func_ov000_0215f330(self->unk_f4);
        func_ov000_0215f330(self->unk_f8);
        func_ov000_0215f330(self->unk_fc);
    }
    i = 0;
    for (n = self->unk_94; n != NULL; n = LFLD(u8 *, n, 0x28)) {
        BOOL on = FALSE;
        switch (self->unk_df) {
        case 0:
            on = i >= self->unk_9c && i <= self->unk_9c + (self->unk_20 - 1);
            break;
        case 1:
            on = i >= self->unk_9c && i <= self->unk_9c + self->unk_20;
            break;
        case 2:
            on = i >= self->unk_9c - 1 && i <= self->unk_9c + self->unk_20 - 1;
            break;
        }
        if (on) LFLD(NodeBits, n, 0x20).b0 = 1; else LFLD(NodeBits, n, 0x20).b0 = 0;
        LFLD(NodeBits, n, 0x20).b1 = 0;
        ((VObj *)n)->vfunc_08();
        i++;
    }
    if (self->unk_a0 != NULL) {
        LFLD(NodeBits, self->unk_a0, 0x20).b1 = 1;
    }
    func_ov000_021c4c10(self);
}
}
