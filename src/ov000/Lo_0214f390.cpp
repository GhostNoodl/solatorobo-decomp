#include "ov000/LoCommon.h"

typedef struct {
    s32 v[4];
} LoFadeP0214f390;

extern "C" {

extern u8 data_ov000_021ccd24[];
void func_020708fc(s32 a, LoFadeP0214f390 *out);
void func_02070b98(s32 a, LoFadeP0214f390 *out, s32 b, s32 c);
void func_02035acc(LoFadeP0214f390 *a, LoFadeP0214f390 *b, s32 c);

void func_ov000_0214f390(void *self) {
    LO_FREE_V(self, 0x60);
    LO_FREE_V(self, 0x5c);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_V(self, 0x48);
    LO_FREE_V(self, 0x44);
    LO_FREE_M(self, 0x40);
    LO_FREE_V(self, 0x3c);
    LO_FREE_V(data_ov000_021ccd24, 8);
    {
        LoFadeP0214f390 b;
        LoFadeP0214f390 a;
        func_020708fc(0x1000, &a);
        func_02070b98(0x1000, &b, 1, 2);
        func_02035acc(&a, &b, 2);
    }
    data_ov000_021ccd24[0] = 0;
}

}
