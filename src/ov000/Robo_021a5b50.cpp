#include "ov000/LoCommon.h"

typedef struct {
    u16 state;
    u16 timer;
} State021a5b50;

typedef struct {
    u8 lo : 5;
    u8 mode : 2;
    u8 hi : 1;
} B93_021a5b50;

extern "C" {

extern u8 data_ov000_021cc678[];
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02198360(State021a5b50 *st, s32 state, s32 x);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
u16 FX_Atan2(s32 y, s32 x);

void func_ov000_021a5b50(u8 *self) {
    switch (LFLD(State021a5b50 *, self, 0x40)->state) {
    case 0:
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc678, 0x200, 0);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        LFLD(s32, self, 0xa4) = 0x800;
        LFLD(B93_021a5b50, self, 0x93).mode = 1;
        if (LFLD(s32, self, 0xa8) == 0) {
            LFLD(s32, self, 0xa8) = 0x52;
        }
        LFLD(State021a5b50 *, self, 0x40)->state++;
    case 1:
        if (LFLD(u16, self, 0xb36) == 0) {
            LFLD(B93_021a5b50, self, 0x93).mode = 0;
            func_ov000_02198360(LFLD(State021a5b50 *, self, 0x40), 1, 0);
            return;
        }
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
            LFLD(s32, self, 0x9c) = 0;
            LFLD(s32, self, 0xa4) = 0;
        } else {
            State021a5b50 *st = LFLD(State021a5b50 *, self, 0x40);
            st->timer++;
            if (st->timer > 0x3c) {
                LFLD(B93_021a5b50, self, 0x93).mode = 0;
                LFLD(u16, self, 0xb36) = 0;
                func_ov000_02198360(LFLD(State021a5b50 *, self, 0x40), 4, 0);
            }
        }
        func_ov000_021b1fac(self, FALSE, 1);
        if (!LBIT(self, 0xb24).b1) {
            return;
        }
        if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
            return;
        }
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70),
                                         LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!LBIT(self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        LBIT(self, 0xb24).b17 = 1;
        break;
    }
}

}
