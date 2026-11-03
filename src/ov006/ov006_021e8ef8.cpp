#include "ov006/SlotManager.h"
#include "Main/Sys/FieldState.h"
#include "ov006/Racer.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"


extern "C" {

u16 Angle_Approach(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);

static inline void ov006_Limit(u16 *p, u16 d, u16 lim) {
    if (d < 0x8000) {
        if (d > lim) {
            *p -= (u16)(d - lim);
        }
    } else if (d < (u16)-lim) {
        *p -= (u16)(d + lim);
    }
}

void Ov006Racer_UpdateSteer(Ov006Racer *self) {
    u32 kind2;
    u16 h2v;
    u32 mode;
    FieldCam *cam;
    u16 camv;
    s32 h2;
    u16 mode2;
    u16 roll;
    u16 dir;
    s32 h;
    u16 pitch;
    u16 steer;
    u16 held;
    u16 base;

    cam = NULL;
    if (self->idx == gOv006SlotManager->unk5) {
        cam = &gSceneCmd->cam;
    }
    h = self->prm->unk_06;
    held = self->held;
    dir = held;
    if (self->swap) {
        if (held & 0x40) {
            dir = 0x80;
        } else if (held & 0x80) {
            dir = 0x40;
        }
    }
    camv = 0;
    if (cam != NULL) {
        camv = cam->base.pitch;
    }
    {
        u16 a = self->courseRot.x;
        if (a < 0x8000) {
            base = a >> 1;
        } else {
            base = -(u16)((u16)-a >> 1);
        }
    }
    steer = 0;
    mode = self->turnMode;
    if (!(mode == 5 || mode == 6 || mode == 7 || mode == 9 || mode == 8 || mode == 10)) {
        h2 = h * 2;
        {
            u16 t = self->runSpeed * (0xc0 - (h2 + 0x80)) / 0xe66;
            steer = (u16)(h + 0xc0) - t;
        }
        if (!(dir & 0x40)) {
            if (dir & 0x80) {
                steer = -steer;
            } else {
                steer = Angle_Approach(base, self->look.x, 0xcd, 1, 0x8000) - self->look.x;
            }
        }
        self->lookVX = Angle_Approach(steer, self->lookVX, (h << 5) + 0x6cd, 1, 0x8000);
        self->look.x += self->lookVX;
        {
            u16 d = self->look.x - base;
            if (d < 0x8000) {
                if (d > 0x1000) {
                    self->look.x = base + 0x1000;
                }
            } else if (d < 0xf000) {
                self->look.x = base - 0x1000;
            }
        }
        if (self->turnMode == 1) {
            self->look2.x = self->look.x;
        } else {
            self->look2.x = Angle_Approach(self->look.x, self->look2.x, 0x4cd, 1, 0x8000);
        }
        self->rot.x = Angle_Approach(self->look.x, self->rot.x, 0x533, 1, 0x8000);
        if (cam != NULL) {
            camv = Angle_Approach(self->look.x + 0xa0, camv, 0x600, 1, 0x8000);
        }
    } else {
        u16 h2u;
        h2 = h * 2;
        h2u = h2;
        u32 kind = 0;
        if (mode == 5 || mode == 9 || mode == 7) {
            base += (u16)(h * 64 + 0x2580);
            steer = h2u + 0x50;
            kind = 5;
        } else if (mode == 6 || mode == 10 || mode == 8) {
            base -= (u16)(h * 64 + 0x2580);
            steer = -(h2u + 0x50);
            kind = 6;
        }
        if (held & 0x40) {
            if (kind == 5) {
                u16 t = h2u + 0x48;
                steer += t;
                base += t;
            } else {
                u16 t = h + 0x18;
                steer += t;
                base += t;
            }
        } else if (held & 0x80) {
            if (kind == 6) {
                u16 t = h2u + 0x48;
                steer -= t;
                base -= t;
            } else {
                u16 t = h + 0x18;
                steer -= t;
                base -= t;
            }
        }
        self->lookVX = Angle_Approach(steer, self->lookVX, 0x19a, 1, 0x8000);
        self->look.x += self->lookVX;
        self->look2.x = Angle_Approach(self->look.x, self->look2.x, 0x4cd, 1, 0x8000);
        self->rot.x = Angle_Approach(base, self->rot.x, 0x533, 1, 0x8000);
        if (cam != NULL) {
            camv = Angle_Approach(self->look.x, self->rot.x, 0xe66, 1, 0x8000);
        }
    }
    steer = 0;
    roll = 0;
    mode2 = self->turnMode;
    if (!(mode2 == 3 || mode2 == 4 || mode2 == 7 || mode2 == 9 || mode2 == 8 || mode2 == 10)) {
        u16 hh = self->held;
        if (hh & 0x30) {
            u16 v = (u16)(h2 + 0xa0) - (u16)(self->runSpeed * (0xa0 - (h + (h * 4 + 0x60))) / 0xe66);
            if (hh & 0x20) {
                steer = v;
            } else if (hh & 0x10) {
                steer = -v;
            }
        }
        self->lookVY = Angle_Approach(steer, self->lookVY, (h << 5) + 0x200, 1, 0x8000);
        self->look.y += self->lookVY;
        ov006_Limit(&self->look.y, self->look.y - self->courseRot.y, 0x2a00);
        if (self->turnMode == 1) {
            self->look2.y = self->look.y;
        } else {
            self->look2.y = Angle_Approach(self->look.y, self->look2.y, 0x4cd, 1, 0x8000);
        }
        self->rot.y = Angle_Approach(self->look.y, self->rot.y, 0x200, 1, 0x8000);
        roll = -(self->lookVY * 0x28);
    } else {
        pitch = self->look.y;
        h2v = h2;
        kind2 = 0;
        if (mode2 == 4 || mode2 == 9 || mode2 == 10) {
            pitch += (u16)(h * 64 + 0x2580);
            steer = h2v + 0x50;
            roll = -(h * 16 + 0x1f40);
            kind2 = 4;
        } else if (mode2 == 3 || mode2 == 7 || mode2 == 8) {
            pitch -= (u16)(h * 64 + 0x2580);
            steer = -(h2v + 0x50);
            roll = h * 16 + 0x1f40;
            kind2 = 3;
        }
        if (self->held & 0x20) {
            pitch += 0x12c0;
            if (kind2 == 4) {
                u16 t = h2v + 0x48;
                steer += t;
            } else {
                u16 t = h + 0x18;
                steer += t;
            }
            roll -= 0x7d0;
        } else if (self->held & 0x10) {
            pitch -= 0x12c0;
            if (kind2 == 3) {
                u16 t = h2v + 0x48;
                steer -= t;
            } else {
                u16 t = h + 0x18;
                steer -= t;
            }
            roll += 0x7d0;
        }
        self->lookVY = Angle_Approach(steer, self->lookVY, 0x19a, 1, 0x8000);
        self->look.y += self->lookVY;
        self->look2.y = Angle_Approach(self->look.y, self->look2.y, 0x4cd, 1, 0x8000);
        self->rot.y = Angle_Approach(pitch, self->rot.y, 0x200, 1, 0x8000);
    }
    self->rot.z = Angle_Approach(roll, self->rot.z, 0x400, 1, 0x8000);
    if (cam == NULL) {
        return;
    }
    cam->unk_f8.x = camv;
    cam->unk_da |= 0x10;
    cam->unk_f8.y = Angle_Approach(self->look.y, self->rot.y, 0xc00, 1, 0x8000);
    cam->unk_da |= 0x20;
}

}
