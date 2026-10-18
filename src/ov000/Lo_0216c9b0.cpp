#include "ov000/LoCommon.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u16 func_0204045c(void);
void func_ov000_0215fe1c(void *self, s32 a, s32 b);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

void func_ov000_0216c9b0(void *self) {
    u32 saved;
    void *p;
    LO_HEAP_PUSH(saved);
    p = LFLD(void *, self, 0x10);
    if (p) {
        if (p) {
            func_ov000_021c216c(p);
            func_0203de1c(p);
        }
        LFLD(void *, self, 0x10) = NULL;
    }
    LO_HEAP_POP(saved);
    LO_FREE_M(self, 0xc);
    func_ov000_0216c954(self, 0, 0);
}

}
