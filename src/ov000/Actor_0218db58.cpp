#include "ov000/Actor.h"

extern "C" {

void Actor_PitchToActor(Actor *self, Actor *other, s32 step) {
    s32 dx;
    s32 dz;
    s32 oy;
    if (other == self) {
        return;
    }
    dx = self->pos.x - other->pos.x;
    dz = self->pos.z - other->pos.z;
    oy = other->pos.y;
    {
        s64 sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        REG_SQRTCNT = 1;
        REG_SQRT_PARAM = (u64)(sq << 2);
    }
    while (REG_SQRTCNT & 0x8000) {
    }
    self->rot_x = func_01ffc128(FX_Atan2(self->pos.y - oy, (s32)(REG_SQRT_RESULT + 1) >> 1), self->rot_x, step, 1, 0x8000);
}

void func_ov000_0218db58(Actor *self, u16 angle, u16 center, u16 range, s32 step) {
    u16 diff = angle - center;
    if (diff > 0x8000) {
        if (diff < (u16)-range) {
            angle = angle - (u16)(diff - (u16)-range);
        }
    } else if (diff > range) {
        angle = angle - (u16)(diff - range);
    }
    self->rot_y = func_01ffc128(angle, self->rot_y, step, 1, 0x8000);
}

#define AMUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void Actor_Move(Actor *self, s32 rate) {
    if (rate != 0) {
        if (rate == 0x1000) {
            self->rot_y = self->moveYaw;
        } else {
            u16 d;
            self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, rate < 0 ? -rate : rate, 1, 0x8000);
            d = self->moveYaw - self->rot_y;
            if (d > 0x8000) {
                d = -d;
            }
            if (d > 0x400) {
                s32 f = 0x1000 / (d >> 11);
                if (f < 0x1000) {
                    self->speed = AMUL(self->speed, f);
                }
            }
            if (rate < 0) {
                self->moveYaw = self->rot_y;
            }
        }
    }
    {
        u16 ang = self->moveYaw;
        s32 dx = AMUL(self->speed, FX_SinCosTable_[(ang >> 4) * 2]);
        s32 dz = AMUL(self->speed, FX_SinCosTable_[(ang >> 4) * 2 + 1]);
        s32 x = self->pos.x + dx;
        self->pos.z += dz;
        self->pos.x = x;
        if (self->friction != 0 && self->friction != 0x1000) {
            self->speed = AMUL(self->speed, self->friction);
        }
    }
    if (self->gravity != 0) {
        self->pos.y += self->velY;
        self->velY -= self->gravity;
        if (self->velY < -0x800) {
            self->velY = -0x800;
        }
    } else {
        s32 v = self->velY;
        if (v != 0.0f) {
            self->pos.y += v;
        }
    }
}

}
