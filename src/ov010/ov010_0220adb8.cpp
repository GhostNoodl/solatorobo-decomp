#include "ov010/ov010.h"

extern "C" {
extern void *data_0214a420;
extern void func_02065860(void *a, s32 b);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_021950e8(void *self, u8 *msg);

static inline void Ov010FxB_Stop(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        func_02065860(data_0214a420, FLD(s32, p, 8));
        FLD(s32, p, 8) = 0;
        func_ov000_02198360(p + 0x58, 1, 0);
    }
}

static inline void Ov010FxB_Start(u8 *p) {
    if (FLD(Ov010Flags8, p, 0).b0) {
        FLD(u16, p, 2) = 0;
        FLD(u16, p, 4) = 0x50;
        func_ov003_021da48c(p + 0x58, 2);
    }
}

BOOL func_ov010_0220adb8(void *self, u8 *msg) {
    BOOL r;
    if (msg[5] == 0xe) {
        switch (msg[8]) {
        case 4:
            FLD(Ov010Flags8, self, 0xce).b3 = 1;
            if (FLD(s32, self, 0xd8) == 7) {
                break;
            }
        case 1:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
            break;
        case 0:
            Ov010FxB_Stop(FLD(u8 *, self, 0xec));
            Ov010FxB_Start(FLD(u8 *, self, 0xec));
            break;
        case 2:
            func_ov000_02198360(FLD(void *, self, 0x40), 6, 0);
            break;
        case 3:
            func_ov000_02198360(FLD(void *, self, 0x40), 0x12, 0);
            break;
        }
        r = TRUE;
        FLD(u32, self, 0x30) |= 1 << msg[5];
        msg[5] = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}
}
