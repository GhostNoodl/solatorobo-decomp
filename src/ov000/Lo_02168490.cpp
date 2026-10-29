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

void func_ov000_02168490(void *self, s32 a, s32 b, Lo3W *p, Lo3W *q) {
    LFLD(s32, self, 0xa0) = p->v[0];
    LFLD(s32, self, 0xa4) = p->v[1];
    LFLD(s32, self, 0xa8) = p->v[2];
    LFLD(s32, self, 0xac) = q->v[0];
    LFLD(s32, self, 0xb0) = q->v[1];
    LFLD(s32, self, 0xb4) = q->v[2];
    if (a > b) {
        a = b;
    }
    func_ov000_0215fe1c(self, a, b);
    LFLD(u32, self, 0xc) = (LFLD(u32, self, 0xc) & ~2) | 0x10000;
}

}
