#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fe1c(void *self, s32 a, s32 b, ...);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

void func_ov000_021682fc(void *self) {
    s32 s = LFLD(s32, self, 4);
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 2;
        }
    }
    if (LFLD(s32, self, 4) != 0xa) {
        return;
    }
    if (!((LFLD(u32, self, 0xc) & 0x10000) ? TRUE : FALSE)) {
        LBIT(self, 0xc).b1 = 1;
    }
    LBIT(self, 0xc).b16 = 0;
}

}
