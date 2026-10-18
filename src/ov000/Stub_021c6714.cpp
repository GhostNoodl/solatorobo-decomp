#include "types.h"

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 pad_08[4];
    u32 unk_0c_0 : 1;
    u32 unk_0c_1 : 1;
    u32 unk_0c_2 : 30;
    u8 pad_10[0x9c];
    s32 unk_ac;
    s32 unk_b0;
    u8 pad_b4[0xc];
    s32 unk_c0;
    u32 unk_c4_0 : 2;
    u32 unk_c4_2 : 1;
    u32 unk_c4_3 : 29;
} Obj021c6714;

extern "C" {

extern const s16 FX_SinCosTable_[];
void func_ov000_021c67e4(Obj021c6714 *self);
void func_ov000_021c69e4(Obj021c6714 *self);

void func_ov000_021c6714(Obj021c6714 *self) {
    if (self->unk_04 == 2) {
        s32 t;
        if (self->unk_0c_1) {
            self->unk_04 = 1;
        }
        func_ov000_021c67e4(self);
        t = (self->unk_ac + 1) % 60;
        self->unk_ac = t;
        self->unk_b0 = (FX_SinCosTable_[((t * (0x10000 / 60)) >> 4) * 2] + 0x800) >> 12;
    }
    func_ov000_021c69e4(self);
    if (self->unk_c4_2) {
        if (++self->unk_c0 >= 6) {
            self->unk_c0 = 6;
        }
    } else {
        if (--self->unk_c0 < 0) {
            self->unk_c0 = 0;
        }
    }
}

}
