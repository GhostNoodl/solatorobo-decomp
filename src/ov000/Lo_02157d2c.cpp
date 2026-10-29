#include "ov000/LoCommon.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern u8 data_02fe1534[];
void func_0206281c(void);
u32 func_0204045c(void);
void func_ov000_0215f0ec(void *p, void *q);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);

void func_ov000_02157d2c(void *self, void *arg) {
    u32 *p = (u32 *)func_0203dd9c(0x2c);
    if (p) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0x80;
        p[6] = 6;
        p[9] = 0;
        p[10] = 0;
    }
    LFLD(void *, self, 0xd8) = p;
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        LBIT(LFLD(void *, self, 0xd8), 0).b4 = 1;
    }
    LBIT(LFLD(void *, self, 0xd8), 0).b0 = 1;
    func_ov000_0215f0ec(LFLD(void *, self, 0xd8), arg);
    {
        u8 *q = LFLD(u8 *, self, 0xd8);
        LFLD(s32, q, 0x14) = LFLD(s32, LFLD(void *, q, 0x24), 0x44) + 0x10;
    }
}

}
