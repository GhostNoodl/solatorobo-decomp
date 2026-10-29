#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 25;
} B24_021a19a0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
} B22_021a19a0;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 6;
} B28_021a19a0;

typedef struct {
    s32 x, y, z;
} Vec_021a19a0;

extern "C" {

extern char data_ov000_021cc61e[];
extern char data_ov000_021cc624[];
extern char data_ov000_021cc62a[];
extern char *data_ov000_021ca050[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s32 b);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
u16 FX_Atan2(s32 y, s32 x);

void func_ov000_021a19a0(u8 *self) {
    BOOL turned;
    s32 rate;
    char *name;
    s32 target;
    s16 spd;
    s32 speed;
    s32 frame;
    LBIT(self, 0xb24).b17 = 0;
    rate = 0x400;
    frame = rate;
    target = LFLD(s32, self, 0xb08);
    name = data_ov000_021cc61e;
    speed = 0x1000;
    if (LBIT(self, 0xb24).b1) {
        if (!LFLD(B22_021a19a0, self, 0xb22).b3) {
            name = data_ov000_021ca050[LFLD(B24_021a19a0, self, 0xb24).b5];
        } else {
            if (LFLD(B24_021a19a0, self, 0xb24).b5 != 0) {
                name = data_ov000_021cc624;
            }
            rate = 0x111;
        }
    } else if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x400) {
        name = data_ov000_021cc624;
        if (LFLD(u16, self, 0xb36) == 1) {
            target = 0x1c3;
            frame = speed;
        } else {
            target = 0x10a;
            speed -= 0xb8;
            frame = 0xcd;
        }
    }
    func_ov000_02190cb0(LFLD(void *, self, 0x38), name, rate, 0);
    if (!LFLD(B22_021a19a0, self, 0xb22).b3) {
        func_ov000_021915a0(LFLD(void *, self, 0x38));
    }
    LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
    func_ov000_021b1dd8(self, target, frame, speed, 0x466, 1);
    spd = 0x1000;
    if (!LFLD(B22_021a19a0, self, 0xb22).b3) {
        // The repeated (s16)(v * 2) terms keep MWCC from folding the else branch into one multiply.
        s16 v = LFLD(s32, self, 0x9c);
        if (LBIT(self, 0xb24).b1) {
            spd = (s16)(v * 2) * 5;
        } else {
            spd = (s16)(v * 2) * 4 + (s16)(v * 2) * 2 + (s16)(v * 2);
        }
    }
    func_ov000_021911c8(LFLD(void *, self, 0x38), spd);
    if (LFLD(B28_021a19a0, self, 0xb28).b0 == 3) {
        LFLD(B28_021a19a0, self, 0xb28).b0 = 2;
        LFLD(Vec_021a19a0, self, 0xb10) = LFLD(Vec_021a19a0, self, 0x70);
    }
    turned = FALSE;
    if (LBIT(self, 0xb24).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70),
                                         LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!LBIT(self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        LBIT(self, 0xb24).b17 = 1;
        turned = TRUE;
    }
    if (!turned) {
        return;
    }
    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
    func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
}

}
