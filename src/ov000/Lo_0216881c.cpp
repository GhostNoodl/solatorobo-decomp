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

void func_ov000_0216881c(void *self) {
    s32 s = LFLD(s32, self, 4);
    if (s == 1 || s == 8 || s == 3 || s == 0xa) {
        if (LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 2;
        }
    }
    switch (LFLD(s32, self, 4)) {
    case 8:
        LFLD(s32, self, 0xb8) = -8;
        break;
    case 0xa:
        if (!((LFLD(u32, self, 0xc) & 0x10000) ? TRUE : FALSE)) {
            LBIT(self, 0xc).b1 = 1;
        }
        if (--LFLD(s32, self, 0xb8) < -8) {
            LFLD(s32, self, 0xb8) = 4;
        }
        LBIT(self, 0xc).b16 = 0;
        break;
    }
}

}
