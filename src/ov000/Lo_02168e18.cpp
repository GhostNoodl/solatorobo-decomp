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

struct Obj02168e18 {
    u8 unk_00[0xc];
    u32 unk_0c;
    u8 unk_10[0x8c];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

void func_ov000_02168e18(Obj02168e18 *self, s32 a, s32 b, Lo3W *p) {
    self->unk_9c = p->v[0];
    self->unk_a0 = p->v[1];
    self->unk_a4 = p->v[2];
    if (a > b) {
        s32 q = a / b;
        self->unk_a8 = q;
        if (q >= 3) {
            a = b;
        } else {
            a = a % b;
        }
    } else {
        self->unk_a8 = 0;
    }
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
