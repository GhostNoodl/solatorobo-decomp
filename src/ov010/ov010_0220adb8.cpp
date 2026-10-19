#include "ov010/ov010.h"

namespace NA { extern "C" u8 data_ov010_0220f534[]; }
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

extern void func_ov000_02194758(void *self);
extern void func_ov000_02198328(void *p);
extern void func_0203f364(void *p);
extern u8 data_ov010_0220f534[];
extern Ov010Vec data_ov010_0220f594;
extern BOOL func_ov010_0220e740(void *self, void *a, void *b, s32 c, const Ov010Vec *v, s32 e);

static inline u8 *Ov010FxA_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x28);
    if (p != NULL) {
        func_ov000_02198328(p + 0x14);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

static inline u8 *Ov010FxB_New(void) {
    u8 *p = (u8 *)func_0203dd9c(0x6c);
    if (p != NULL) {
        func_ov000_02198328(p + 0x58);
        FLD(Ov010Flags8, p, 0).b0 = 0;
    }
    return p;
}

void func_ov010_0220aecc(u8 *self) {
    u8 *p;
    func_ov000_02194758(self);
    func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
    func_ov000_02198360(self + 0x158, 1, 0);
    FLD(s32, self, 0xd8) = 1;
    FLD(u8 *, self, 0xe8) = p = Ov010FxA_New();
    FLD(Ov010Flags8, p, 0).b0 = 1;
    FLD(Ov010Flags8, p, 0).b1 = 0;
    FLD(Ov010Flags8, p, 0).b2 = 0;
    FLD(u16, p, 2) = 0;
    FLD(s32, p, 4) = 0;
    FLD(Ov010Vec, p, 8) = FLD(Ov010Vec, data_ov010_0220f534, 0x60);
    func_ov003_021da48c(p + 0x14, 0);
    FLD(u8 *, self, 0xec) = Ov010FxB_New();
    func_ov010_0220e740(FLD(u8 *, self, 0xec), self, NA::data_ov010_0220f534, 1, &data_ov010_0220f594, 0x68);
    if (FLD(Ov010Flags8, FLD(u8 *, self, 0xec), 0).b0) {
        FLD(s32, FLD(u8 *, self, 0xec), 0x14) = 0x4000;
    }
    FLD(Ov010Flags, self, 0xcc).b4 = 0;
    {
        u8 *mm = FLD(u8 *, self, 0x48);
        FLD(Ov010Flags, mm, 0x9a).b0 = 0;
        FLD(Ov010Flags, mm, 0x9a).b3 = 0;
        func_0203f364(mm);
    }
    {
        u8 *q = FLD(u8 *, self, 0x44);
        FLD(Ov010Flags, q, 0x22).b0 = 0;
        FLD(Ov010Flags, q, 0x22).b1 = 0;
    }
    FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
    {
        u8 *m = FLD(u8 *, self, 0x38);
        FLD(s32, m, 0xa8) = 0x1400;
        FLD(s32, m, 0xac) = 0x1400;
        FLD(s32, m, 0xb0) = 0x1400;
    }
    FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = FLD(u16, self, 0xd0);
    FLD(Ov010Flags8, FLD(u8 *, self, 0x4c), 0x18).b4 = 1;
    FLD(Ov010Flags, FLD(u8 *, self, 0x48), 0x9a).b7 = 1;
    FLD(s32, FLD(u8 *, self, 0x48), 0x48) = FLD(s32, self, 0x64) + (FLD(s32, self, 0x64) >> 1);
    FLD(u8, self, 0xcf) = 1;
}

}
