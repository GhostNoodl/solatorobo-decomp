#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits32_0219ff8c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 rest : 10;
} Bits16_0219ff8c;

typedef struct {
    u8 st : 2;
    u8 b2 : 1;
    u8 rest : 5;
} Bits8_0219ff8c;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 rest : 3;
} Bits93_0219ff8c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 rest : 11;
} Bits22_0219ff8c;

extern "C" {

void func_ov000_021bd300(void *p);
void func_ov000_021b1a54(u8 *self, BOOL flag);
void func_0203f364(void *p);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);

static inline s32 Dist0219ff8c(u8 *self) {
    s32 dx = LFLD(s32, self, 0x70) - LFLD(s32, self, 0xb10);
    s32 dz = LFLD(s32, self, 0x78) - LFLD(s32, self, 0xb18);
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT + 1) >> 1;
}

void func_ov000_0219ff8c(u8 *self) {
    LFLD(u16, self, 0xb68) = 0;
    LFLD(u16, self, 0xb6a) = 0;
    LFLD(u16, self, 0xb6c) = 0;
    LFLD(u16, self, 0xb6e) = 0;
    LFLD(u16, self, 0xb36) = 0;
    LFLD(u16, self, 0xb38) = 0;
    LFLD(Bits16_0219ff8c, self, 0xb2c).b4 = 0;
    LFLD(Bits32_0219ff8c, LFLD(u8 *, self, 0x5c), 0).b1 = 0;
    func_ov000_021bd300(LFLD(u8 *, self, 0x5c));
    LFLD(Bits32_0219ff8c, LFLD(u8 *, self, 0x9b0), 0).b1 = 0;
    func_ov000_021bd300(LFLD(u8 *, self, 0x9b0));
    if (LFLD(Bits32_0219ff8c, self, 0xb24).b0) {
        LFLD(Bits32_0219ff8c, self, 0xb24).b0 = 0;
        if (*LFLD(u16 *, self, 0x50) == 0) {
            *LFLD(u16 *, self, 0x50) = 1;
        }
    }
    if (LFLD(Bits22_0219ff8c, self, 0xb22).b3 && !LFLD(Bits22_0219ff8c, self, 0xb22).b4 &&
        !LFLD(Bits93_0219ff8c, self, 0x93).b4 && !LFLD(Bits32_0219ff8c, self, 0xb24).b0) {
        func_ov000_021b1a54(self, TRUE);
    }
    if (LFLD(Bits8_0219ff8c, self, 0xb28).st != 0) {
        {
            u8 *p = LFLD(u8 *, self, 0x48);
            LFLD(Bits16_0219ff8c, p, 0x9a).b3 = 0;
            func_0203f364(p);
        }
        switch (LFLD(Bits8_0219ff8c, self, 0xb28).st) {
        case 1:
            if (Dist0219ff8c(self) <= 0x400) {
                LFLD(u64, LFLD(u8 *, self, 0x40), 4) |= 2;
            } else {
                LFLD(u64, LFLD(u8 *, self, 0x40), 4) |= 4;
            }
            break;
        case 2:
            if (Dist0219ff8c(self) <= 0x400) {
                LFLD(u8, self, 0x15) = 1;
                LFLD(Bits8_0219ff8c, self, 0xb28).st = 0;
                LFLD(Bits8_0219ff8c, self, 0xb28).b2 = 0;
                LFLD(u64, LFLD(u8 *, self, 0x40), 4) |= 2;
            } else {
                LFLD(u64, LFLD(u8 *, self, 0x40), 4) |= 4;
            }
            break;
        case 3:
            LFLD(u64, LFLD(u8 *, self, 0x40), 4) |= 4;
            LFLD(Bits8_0219ff8c, self, 0xb28).st = 2;
            break;
        }
        return;
    }
    if (LFLD(u16, self, 0xb1e) != 0xffff) {
        Actor *a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, LFLD(u16, self, 0xb1e));
        if (a == NULL) {
            LFLD(u16, self, 0xb1e) = 0xffff;
        }
    }
}

}
