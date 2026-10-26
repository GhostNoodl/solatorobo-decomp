#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Rot021e8ef8 {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e8ef8;

typedef struct ov006_Cam021e8ef8 {
    u8 unk0[0x42];
    u16 unk42;
    u8 unk44[0x96];
    u8 unkDA;
    u8 unkDB[0x1d];
    u16 unkF8;
    u16 unkFA;
} ov006_Cam021e8ef8;

typedef struct ov006_Car021e8ef8 {
    u8 unk0[0x7c];
    ov006_Rot021e8ef8 rot;
    u8 unk82[0x2a];
    s8 *unkAC;
    u8 unkB0[0xec];
    u16 unk19C_0 : 2;
    u16 mode : 4;
    u16 boosting : 1;
    u16 unk19C_7 : 1;
    u16 swap : 1;
    u16 unk19C_9 : 7;
    u8 unk19E;
    u8 unk19F;
    s32 speed;
    u16 held;
    u16 trig;
    u8 unk1A8[6];
    ov006_Rot021e8ef8 look;
    u16 lookVX;
    u16 lookVY;
    u8 unk1B8[2];
    ov006_Rot021e8ef8 look2;
    u8 unk1C0[0x4c];
    u16 unk20C;
    u16 unk20E;
} ov006_Car021e8ef8;

extern "C" {

extern u8 *data_ov000_021ccd54;
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);

static inline void ov006_Limit(u16 *p, u16 d, u16 lim) {
    if (d < 0x8000) {
        if (d > lim) {
            *p -= (u16)(d - lim);
        }
    } else if (d < (u16)-lim) {
        *p -= (u16)(d + lim);
    }
}

void func_ov006_021e8ef8(ov006_Car021e8ef8 *self) {
    u32 kind2;
    u16 h2v;
    u32 mode;
    ov006_Cam021e8ef8 *cam;
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
    if (self->unk19E == data_ov006_021ec884->unk5) {
        cam = (ov006_Cam021e8ef8 *)(data_ov000_021ccd54 + 0xf4);
    }
    h = self->unkAC[6];
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
        camv = cam->unk42;
    }
    {
        u16 a = self->unk20C;
        if (a < 0x8000) {
            base = a >> 1;
        } else {
            base = -(u16)((u16)-a >> 1);
        }
    }
    steer = 0;
    mode = self->mode;
    if (!(mode == 5 || mode == 6 || mode == 7 || mode == 9 || mode == 8 || mode == 10)) {
        h2 = h * 2;
        {
            u16 t = self->speed * (0xc0 - (h2 + 0x80)) / 0xe66;
            steer = (u16)(h + 0xc0) - t;
        }
        if (dir & 0x40) {
        } else if (dir & 0x80) {
            steer = -steer;
        } else {
            steer = func_01ffc128(base, self->look.x, 0xcd, 1, 0x8000) - self->look.x;
        }
        self->lookVX = func_01ffc128(steer, self->lookVX, (h << 5) + 0x6cd, 1, 0x8000);
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
        if (self->mode == 1) {
            self->look2.x = self->look.x;
        } else {
            self->look2.x = func_01ffc128(self->look.x, self->look2.x, 0x4cd, 1, 0x8000);
        }
        self->rot.x = func_01ffc128(self->look.x, self->rot.x, 0x533, 1, 0x8000);
        if (cam != NULL) {
            camv = func_01ffc128(self->look.x + 0xa0, camv, 0x600, 1, 0x8000);
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
        self->lookVX = func_01ffc128(steer, self->lookVX, 0x19a, 1, 0x8000);
        self->look.x += self->lookVX;
        self->look2.x = func_01ffc128(self->look.x, self->look2.x, 0x4cd, 1, 0x8000);
        self->rot.x = func_01ffc128(base, self->rot.x, 0x533, 1, 0x8000);
        if (cam != NULL) {
            camv = func_01ffc128(self->look.x, self->rot.x, 0xe66, 1, 0x8000);
        }
    }
    steer = 0;
    roll = 0;
    mode2 = self->mode;
    if (!(mode2 == 3 || mode2 == 4 || mode2 == 7 || mode2 == 9 || mode2 == 8 || mode2 == 10)) {
        u16 hh = self->held;
        if (hh & 0x30) {
            u16 v = (u16)(h2 + 0xa0) - (u16)(self->speed * (0xa0 - (h + (h * 4 + 0x60))) / 0xe66);
            if (hh & 0x20) {
                steer = v;
            } else if (hh & 0x10) {
                steer = -v;
            }
        }
        self->lookVY = func_01ffc128(steer, self->lookVY, (h << 5) + 0x200, 1, 0x8000);
        self->look.y += self->lookVY;
        ov006_Limit(&self->look.y, self->look.y - self->unk20E, 0x2a00);
        if (self->mode == 1) {
            self->look2.y = self->look.y;
        } else {
            self->look2.y = func_01ffc128(self->look.y, self->look2.y, 0x4cd, 1, 0x8000);
        }
        self->rot.y = func_01ffc128(self->look.y, self->rot.y, 0x200, 1, 0x8000);
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
        self->lookVY = func_01ffc128(steer, self->lookVY, 0x19a, 1, 0x8000);
        self->look.y += self->lookVY;
        self->look2.y = func_01ffc128(self->look.y, self->look2.y, 0x4cd, 1, 0x8000);
        self->rot.y = func_01ffc128(pitch, self->rot.y, 0x200, 1, 0x8000);
    }
    self->rot.z = func_01ffc128(roll, self->rot.z, 0x400, 1, 0x8000);
    if (cam == NULL) {
        return;
    }
    cam->unkF8 = camv;
    cam->unkDA |= 0x10;
    cam->unkFA = func_01ffc128(self->look.y, self->rot.y, 0xc00, 1, 0x8000);
    cam->unkDA |= 0x20;
}

}
