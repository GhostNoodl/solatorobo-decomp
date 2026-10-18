#include "ov000/LoCommon.h"

extern "C" {

extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u16 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void func_ov000_0216e5d0(void *self) {
    LO_FREE_M(self, 0x10);
    LO_FREE_M(self, 0x14);
}

}
