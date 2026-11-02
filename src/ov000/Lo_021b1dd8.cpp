#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern u8 *data_ov000_021ccd54;
extern u8 *data_0214a424;
u16 Camera_GetYaw(void *cam);
void func_ov000_0218dd8c(void *self, u16 base, s32 turn, void *range);
void Actor_MoveToPos(void *self, const VecFx32 *target, s32 turn);
void Actor_Move(void *self, s32 turn);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(void *self);

void func_ov000_021b1dd8(Robo021ca458 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim) {
    BOOL moved = FALSE;
    BOOL doAnim = TRUE;
    s32 ox = self->pos.x;
    s32 oz = self->pos.y;
    if (self->unk_15 == 1) {
        if (self->unk_b24_12) {
            func_ov000_021b209c(self);
            return;
        }
        if (self->unk_b68 & 0xf0) {
            u8 *cam = data_ov000_021ccd54 + 0xf4;
            u16 ang;
            if (LFLD(u16, cam, 0x40) != 0) {
                ang = LFLD(u16, cam, 0x44);
            } else {
                ang = Camera_GetYaw(cam);
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
    } else if (self->unk_b28_0) {
        self->unk_9c = self->unk_b08;
        self->unk_a4 = 0x1000;
        Actor_MoveToPos(self, (VecFx32 *)((u8 *)self + 0xb10), turn);
        moved = doAnim;
        doAnim = FALSE;
    }
    if (!moved) {
        self->unk_a4 = speed;
        Actor_Move(self, 0);
    }
    if (ox != self->pos.x || oz != self->pos.y) {
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
        func_ov000_021987b8(((void *)self->unk_48), anim, 0, 0);
    }
    if (self->unk_a0 < 0) {
        u8 *m = (u8 *)((void *)self->unk_48);
        if (LFLD(u32, m, 0x50) & 0x20000000) {
            self->unk_a0 = 0;
            LFLD(u16, m, 0x9a) |= 0x20;
        }
    }
}
}
