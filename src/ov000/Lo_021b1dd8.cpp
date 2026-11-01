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
void func_ov000_021b209c(void *self);

struct Obj021b1dd8 {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0x32];
    void *unk_48;
    u8 unk_4c[0x24];
    s32 unk_70;
    s32 unk_74;
    u8 unk_78[0x24];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    u8 unk_a8[0xa60];
    s32 unk_b08;
    u8 unk_b0c[0x18];
    Bits021b1dd8 unk_b24;
    Bits021b1dd8b unk_b28;
    u8 unk_b29[0x3f];
    u16 unk_b68;
    u8 unk_b6a[0x3e];
    s32 unk_ba8;
};

void func_ov000_021b1dd8(Obj021b1dd8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim) {
    BOOL moved = FALSE;
    BOOL doAnim = TRUE;
    s32 ox = self->unk_70;
    s32 oz = self->unk_74;
    if (self->unk_15 == 1) {
        if (self->unk_b24.b12) {
            func_ov000_021b209c(self);
            return;
        }
        if (self->unk_b68 & 0xf0) {
            u8 *cam = data_ov000_021ccd54 + 0xf4;
            u16 ang;
            if (LFLD(u16, cam, 0x40) != 0) {
                ang = LFLD(u16, cam, 0x44);
            } else {
                ang = func_0204bfa8(cam);
            }
            self->unk_9c += LO_FX_MUL(rate, target - self->unk_9c);
            if (self->unk_9c >= target) {
                self->unk_a4 = speed;
            } else {
                self->unk_a4 = 0x1000;
            }
            func_ov000_0218dd8c(self, ang, turn, (u8 *)self + 0xb70);
            moved = TRUE;
        }
    } else if (self->unk_b28.b0) {
        self->unk_9c = self->unk_b08;
        self->unk_a4 = 0x1000;
        func_ov000_0218ddd4(self, (VecFx32 *)((u8 *)self + 0xb10), turn);
        moved = doAnim;
        doAnim = FALSE;
    }
    if (!moved) {
        self->unk_a4 = speed;
        func_ov000_0218dbe0(self, 0);
    }
    if (ox != self->unk_70 || oz != self->unk_74) {
        self->unk_ba8 += self->unk_9c;
        if (self->unk_ba8 > 0x1000) {
            u32 v = LFLD(u32, data_0214a424, 0x10) + ((u32)self->unk_ba8 >> 12);
            if (v >= 0xf423f) {
                LFLD(u32, data_0214a424, 0x10) = 0xf423f;
            } else {
                LFLD(u32, data_0214a424, 0x10) = v;
            }
            self->unk_ba8 &= 0xfff;
        }
    }
    if (doAnim) {
        func_ov000_021987b8(self->unk_48, anim, 0, 0);
    }
    if (self->unk_a0 < 0) {
        u8 *m = (u8 *)self->unk_48;
        if (LFLD(u32, m, 0x50) & 0x20000000) {
            self->unk_a0 = 0;
            LFLD(u16, m, 0x9a) |= 0x20;
        }
    }
}
}
