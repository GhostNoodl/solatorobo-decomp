#include "types.h"

typedef struct {
    u8 unk_00[0xa8];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xa];
    u8 unk_be;
    u8 unk_bf[3];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    Ov003Model *unk_38;
    u8 unk_3c[4];
    Ov003PropWk *work;
    u8 unk_44[0x30];
    s32 unk_74;
} Ov003Prop;

extern void *data_ov000_021ccd68;
extern void func_ov000_02194758(void *self);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);

void func_ov003_021e0800(Ov003Prop *self) {
    func_ov000_02194758(self);
    self->unk_38->unk_c2_0 = 0;
    func_ov000_0218e8ec(data_ov000_021ccd68, 0x400c, 0x15);
    self->unk_74 -= 0x14000;
}

