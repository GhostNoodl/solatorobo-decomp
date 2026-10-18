#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220f024[];
extern void func_ov000_02190cb0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);

void func_ov010_02204cdc(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(s32, data_ov010_0220f024, 0x2c), 0x266, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
    FLD(u16, FLD(void *, self, 0x40), 0)++;
}

}
