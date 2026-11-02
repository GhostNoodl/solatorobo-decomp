#include "ov000/FieldCam.h"
#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

extern "C" {
void Actor_MoveByPad(Actor *self, u16 base, s32 turn, void *range);
void Actor_MoveToPos(Actor *self, const VecFx32 *target, s32 turn);
void Actor_Move(Actor *self, s32 turn);
void Body_Update(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(Robo021ca458 *self);

void Robo021ca458_WalkByPad(Robo021ca458 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim) {
    BOOL moved = FALSE;
    BOOL doAnim = TRUE;
    s32 ox = self->pos.x;
    s32 oz = self->pos.y;
    if (self->mode == 1) {
        if (self->unk_b24_12) {
            func_ov000_021b209c(self);
            return;
        }
        if (self->padCur & 0xf0) {
            FieldCam *cam = &data_ov000_021ccd54->cam;
            u16 ang;
            ang = FieldCam_GetYaw(cam);
            self->speed += LO_FX_MUL(rate, target - self->speed);
            if (self->speed >= target) {
                self->friction = speed;
            } else {
                self->friction = 0x1000;
            }
            Actor_MoveByPad(self, ang, turn, (u8 *)self + 0xb70);
            moved = TRUE;
        }
    } else if (self->unk_b28_0) {
        self->speed = self->unk_b08;
        self->friction = 0x1000;
        Actor_MoveToPos(self, (VecFx32 *)((u8 *)self + 0xb10), turn);
        moved = doAnim;
        doAnim = FALSE;
    }
    if (!moved) {
        self->friction = speed;
        Actor_Move(self, 0);
    }
    if (ox != self->pos.x || oz != self->pos.y) {
        self->unk_ba8 += self->speed;
        if (self->unk_ba8 > 0x1000) {
            u32 v = data_0214a424->unk_010 + ((u32)self->unk_ba8 >> 12);
            if (v >= 0xf423f) {
                data_0214a424->unk_010 = 0xf423f;
            } else {
                data_0214a424->unk_010 = v;
            }
            self->unk_ba8 &= 0xfff;
        }
    }
    if (doAnim) {
        Body_Update(((void *)self->hit), anim, 0, 0);
    }
    if (self->velY < 0) {
        ActorSub48 *m = self->hit;
        if (m->unk_50 & 0x20000000) {
            self->velY = 0;
            m->unk_9a |= 0x20;
        }
    }
}
}
