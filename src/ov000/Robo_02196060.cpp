#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State02196060;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 rest : 12;
} Bits02196060;

extern "C" {
extern char data_ov000_021cc456[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd6c;
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02199dc0(void *a, void *b);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void func_0203f324(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void *func_ov000_021b68b8(void *a, void *pos);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void SetVel02196060(u8 *self, s32 x, s32 y, s32 z) {
    LFLD(s32, self, 0x9c) = x;
    LFLD(s32, self, 0xa0) = y;
    LFLD(s32, self, 0xa4) = z;
}

void func_ov000_02196060(u8 *self) {
    State02196060 *s = LFLD(State02196060 *, self, 0x40);
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc456, 0x1000, 0);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        if (LFLD(u8, LFLD(u8 *, self, 0x4c), 1) == 1) {
            func_ov000_02199dc0(LFLD(u8 *, self, 0x4c), self);
            func_02049f44(data_02097e4c, 0xb, self + 0x70, 0);
            LFLD(State02196060 *, self, 0x40)->st++;
        } else {
            SetVel02196060(self, 0x229, 0x27, 0);
            LFLD(s32, self, 0xa8) = 0x52;
            LFLD(State02196060 *, self, 0x40)->st++;
        }
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
        {
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(Bits02196060, LFLD(u8 *, self, 0x44), 0x22).b0 = 1;
            LFLD(Bits02196060, q, 0x22).b1 = 1;
        }
        if (LFLD(u8 *, self, 0x48) != NULL) {
            u8 *p = LFLD(u8 *, self, 0x48);
            LFLD(Bits02196060, p, 0x9a).b0 = 1;
            LFLD(Bits02196060, p, 0x9a).b3 = 1;
            func_0203f324(p);
            LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x12;
        }
        break;
    case 1:
        s->timer++;
        if (s->timer > 2) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
        }
        if (LFLD(s32, self, 0xa0) > 0 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x80000000)) {
            LFLD(s32, self, 0xa0) = -0xcd;
        }
        {
            u8 *o = (u8 *)func_ov000_021b68b8(data_ov000_021ccd6c, self + 0x70);
            if (o != NULL) {
                u16 ang = (u64)LFLD(u16, o, 0x1a);
                LFLD(s32, self, 0x9c) = FX_Mul(LFLD(s32, self, 0x9c), 0x59a);
                if (LFLD(s32, self, 0x9c) < 0x8f) {
                    LFLD(s32, self, 0x9c) = 0x8f;
                }
                LFLD(u16, self, 0x98) = ang;
                LFLD(s32, self, 0xa8) = 0x52;
            }
        }
        func_ov000_0218dbe0(self, 0);
        if (LFLD(u8 *, self, 0x48) != NULL) {
            func_ov000_021987b8(LFLD(u8 *, self, 0x48), 0, 0, 0);
        }
        break;
    }
}
}
