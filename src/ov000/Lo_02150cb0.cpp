#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021ccd24[];
void func_ov000_02153fd8(void *p);

void func_ov000_02150cb0(void *self) {
    LFLD(VObj, self, 0x60).vfunc_08();
    LFLD(VObj, self, 0x118).vfunc_08();
    LFLD(VObj, self, 0x1d0).vfunc_08();
    LFLD(VObj, self, 0x288).vfunc_08();
    LFLD(VObj, self, 0x340).vfunc_08();
    LFLD(VObj, self, 0x3f8).vfunc_08();
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(void *, self, 0x54) != NULL) {
            void *p = LFLD(void *, self, 0x54);
            if (p != NULL) {
                func_ov000_02153fd8(p);
                func_0203de1c(p);
            }
            LFLD(void *, self, 0x54) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x58);
    LO_FREE_V(self, 0x4c);
    LO_FREE_V(self, 0x50);
    LO_FREE_M(self, 0x48);
    LO_FREE_M(self, 0x44);
    LO_FREE_V(self, 0x3c);
    if (LFLD(u16, self, 0x42) == 0xffff) {
        LO_FREE_V(data_ov000_021ccd24, 8);
    }
}

}
