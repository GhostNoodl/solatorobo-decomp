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

void func_ov000_0215d30c(void *self) {
    VObj *o;
    if (LFLD(s32, self, 4) != 2) {
        return;
    }
    LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
    LFLD(s32, self, 0x38) = 0x1000;
    o = LFLD(VObj *, self, 0x98);
    if (o) {
        if (!(LFLD(u32, self, 0xc) & 0x10000)) {
            LFLD(u32, o, 4) |= 0x4000000;
        }
        LFLD(VObj *, self, 0x98)->vfunc_8c();
        if (!LBIT(self, 0xc).b1) {
            if (LFLD(VObj *, self, 0x98)->vfunc_10() || (LFLD(u32, self, 0xc) & 0x40000)) {
                LBIT(self, 0xc).b1 = 1;
            }
        }
    }
    if (LBIT(self, 0xc).b1 == 1) {
        LFLD(s32, self, 4) = 1;
    }
}

}
