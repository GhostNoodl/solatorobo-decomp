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

s32 func_ov000_02152690(void *self, s32 *out, s32 *outS, s32 ang) {
    s32 s;
    s32 t;
    if (ang == -1) {
        ang = LFLD(s32, self, 0x38);
    }
    s = FX_SinCosTable_[((ang << 14) >> 16) * 2];
    t = LFLD(s32, self, 0x2c);
    if (t == 0) {
        if (outS) {
            *outS = s;
        }
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
    } else if (t == 1) {
        s32 k;
        if (outS) {
            *outS = 0x1000;
        }
        k = 0x1000 - s;
        out[0] = LO_FX_MUL(k, LFLD(s32, self, 0x58) << 12);
        out[1] = LO_FX_MUL(k, LFLD(s32, self, 0x5c) << 12);
        out[2] = 0;
    }
    return s;
}

}
