#include "ov000/LoCommon.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u16 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

void func_ov000_0216912c(void *self, s32 a, s32 b, s32 c, LoDE de) {
    if (LFLD(s32, self, 0xa0) != a) {
        LFLD(s32, self, 0xa0) = a;
        LFLD(s32, self, 0x5c) = 0;
        LFLD(s32, self, 0x60) = 0;
        LFLD(s32, self, 0x64) = 0;
        LFLD(s32, self, 0x68) = 0;
        LFLD(s32, self, 0x6c) = 0x1000;
        LFLD(s32, self, 0x58) = b;
    }
    if (c < (LFLD(s32, self, 0x64) >> 12)) {
        LFLD(s32, self, 0xa8) = 10;
        LFLD(s32, self, 0xac) = LFLD(s32, self, 0x5c);
        LFLD(u16, self, 0xa4) = func_0204045c();
    }
    if (LFLD(s32, self, 0x60) == 0) {
        LFLD(s32, self, 0x5c) = c << 12;
    }
    func_ov000_0215fe1c(self, c, de.d);
    LFLD(s32, self, 0x80) = de.e[0];
    LFLD(s32, self, 0x84) = de.e[1];
    LFLD(s32, self, 0x88) = de.e[2];
    LBIT(self, 0xc).b1 = 0;
    LBIT(self, 0xc).b16 = 1;
}

}
