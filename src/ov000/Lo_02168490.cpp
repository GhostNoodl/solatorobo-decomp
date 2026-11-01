#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

struct Obj02168490 {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x90];
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
};

void func_ov000_02168490(Obj02168490 *self, s32 a, s32 b, Lo3W *p, Lo3W *q) {
    self->unk_a0 = p->v[0];
    self->unk_a4 = p->v[1];
    self->unk_a8 = p->v[2];
    self->unk_ac = q->v[0];
    self->unk_b0 = q->v[1];
    self->unk_b4 = q->v[2];
    if (a > b) {
        a = b;
    }
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
