#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
} Bits021b1dd8;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 6;
} Bits021b1dd8b;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern u8 *data_0214a424;
u16 func_0204bfa8(void *cam);
void func_ov000_0218dd8c(void *self, u16 base, s32 turn, void *range);
void func_ov000_0218ddd4(void *self, const VecFx32 *target, s32 turn);
void func_ov000_0218dbe0(void *self, s32 turn);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(void *self, s32 a);

void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim) {
    BOOL moved = FALSE;
    BOOL doAnim = TRUE;
    s32 ox = LFLD(s32, self, 0x70);
    s32 oz = LFLD(s32, self, 0x74);
    if (LFLD(u8, self, 0x15) == 1) {
        if (LFLD(Bits021b1dd8, self, 0xb24).b12) {
            func_ov000_021b209c(self, moved);
            return;
        }
        if (LFLD(u16, self, 0xb68) & 0xf0) {
            u8 *cam = data_ov000_021ccd54 + 0xf4;
            u16 ang;
            if (LFLD(u16, cam, 0x40) != 0) {
                ang = LFLD(u16, cam, 0x44);
            } else {
                ang = func_0204bfa8(cam);
            }
            LFLD(s32, self, 0x9c) += LO_FX_MUL(rate, target - LFLD(s32, self, 0x9c));
            if (LFLD(s32, self, 0x9c) >= target) {
                LFLD(s32, self, 0xa4) = speed;
            } else {
                LFLD(s32, self, 0xa4) = 0x1000;
            }
            func_ov000_0218dd8c(self, ang, turn, self + 0xb70);
            moved = TRUE;
        }
    } else if (LFLD(Bits021b1dd8b, self, 0xb28).b0) {
        LFLD(s32, self, 0x9c) = LFLD(s32, self, 0xb08);
        LFLD(s32, self, 0xa4) = 0x1000;
        func_ov000_0218ddd4(self, (VecFx32 *)(self + 0xb10), turn);
        moved = doAnim;
        doAnim = FALSE;
    }
    if (!moved) {
        LFLD(s32, self, 0xa4) = speed;
        func_ov000_0218dbe0(self, 0);
    }
    if (ox != LFLD(s32, self, 0x70) || oz != LFLD(s32, self, 0x74)) {
        LFLD(s32, self, 0xba8) += LFLD(s32, self, 0x9c);
        if (LFLD(s32, self, 0xba8) > 0x1000) {
            u32 v = LFLD(u32, data_0214a424, 0x10) + ((u32)LFLD(s32, self, 0xba8) >> 12);
            if (v >= 0xf423f) {
                LFLD(u32, data_0214a424, 0x10) = 0xf423f;
            } else {
                LFLD(u32, data_0214a424, 0x10) = v;
            }
            LFLD(s32, self, 0xba8) &= 0xfff;
        }
    }
    if (doAnim) {
        func_ov000_021987b8(LFLD(void *, self, 0x48), anim, 0, 0);
    }
    if (LFLD(s32, self, 0xa0) < 0) {
        u8 *m = LFLD(u8 *, self, 0x48);
        if (LFLD(u32, m, 0x50) & 0x20000000) {
            LFLD(s32, self, 0xa0) = 0;
            LFLD(u16, m, 0x9a) |= 0x20;
        }
    }
}
}
