#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} CamFlags021b3e90;

typedef struct {
    u8 b0 : 6;
    u8 b6 : 1;
    u8 b7 : 1;
} CamFlags9c021b3e90;

typedef struct {
    u32 b0 : 5;
    u32 b5 : 2;
    u32 rest : 25;
} Bits021b3e90;

typedef struct {
    u8 pad_00[0x40];
    u16 unk_40;
    u16 pitch;
    u16 yaw;
    u8 pad_46[0x56];
    CamFlags9c021b3e90 unk_9c;
    u8 pad_9d[0x37];
    u16 unk_d4;
    u16 unk_d6;
    u8 pad_d8[2];
    CamFlags021b3e90 unk_da;
    u8 pad_db;
    s32 unk_dc;
    s32 unk_e0;
    s32 unk_e4;
    u8 pad_e8[0xc];
    s32 unk_f4;
    u16 unk_f8;
    u16 unk_fa;
} Cam021b3e90;

extern "C" {

extern ActorMgr *data_ov000_021ccd68;
u16 func_0204bfa8(Cam021b3e90 *cam);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);
u16 func_ov000_0218d8f4(Actor *self, void *target);
u16 FX_Atan2(s32 y, s32 x);

static inline u16 CamYaw(Cam021b3e90 *cam) {
    if (cam->unk_40 != 0) {
        return cam->yaw;
    }
    return func_0204bfa8(cam);
}

static inline Actor *FindActor021b3e90(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 AngleTo(Actor *self, Actor *other) {
    u16 angle;
    if (other == NULL || other == self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
    }
    return angle;
}

BOOL func_ov000_021b3e90(Actor *self) {
    BOOL ret;
    u16 dp;
    u16 dy;
    Cam021b3e90 *cam;
    ret = FALSE;
    {
        u8 *g = (u8 *)data_ov000_021ccd54;
        cam = (Cam021b3e90 *)(g + 0xf4);
    }
    if (cam == NULL) {
        return ret;
    }
    if (cam->unk_d6 - 1 != cam->unk_d4) {
        cam->unk_9c.b6 = 0;
        return ret;
    }
    cam->unk_9c.b6 = 1;
    dp = 0;
    dy = 0;
    switch (LFLD(u8, self, 0xb31)) {
    case 0:
        if (LFLD(u16, self, 0xb6a) & 0x100) {
            if (LFLD(u8, self, 0xb30) != 0) {
                LFLD(u8, self, 0xb31) = 1;
                LFLD(u8, self, 0xb30) = 0;
            } else {
                LFLD(u8, self, 0xb30) = 20;
            }
        } else if (LFLD(u16, self, 0xb68) & 0x100) {
            u16 keys = LFLD(u16, self, 0xb68);
            ret = TRUE;
            if (keys & 0x80) {
                dp = 0xf800;
            } else if (keys & 0x40) {
                dp = 0x800;
            }
            if (dp != 0) {
                dp += cam->pitch;
                if (dp > 0x8000) {
                    s32 t;
                    if (dp < 0xf200) {
                        dp = 0xf200;
                    }
                    t = 0x10000 - dp;
                    cam->unk_f4 = 0x8000 - t * 4;
                    cam->unk_da.b2 = 1;
                    cam->unk_dc = 0;
                    cam->unk_e0 = t + 0x1800;
                    cam->unk_e4 = 0;
                    cam->unk_da.b0 = 1;
                } else if (dp > 0x2800) {
                    dp = 0x2800;
                }
                cam->unk_f8 = dp;
                cam->unk_da.b4 = 1;
            }
            keys = LFLD(u16, self, 0xb68);
            if (keys & 0x10) {
                dy = 0xf400;
            } else if (keys & 0x20) {
                dy = 0xc00;
            }
            if (dy != 0) {
                cam->unk_fa = dy + CamYaw(cam);
                cam->unk_da.b5 = 1;
            }
        }
        if (LFLD(u8, self, 0xb30) != 0) {
            LFLD(u8, self, 0xb30)--;
        }
        if (!ret && LFLD(Bits021b3e90, self, 0xb24).b5 != 0 && self->target != 0xffff) {
            Actor *t = FindActor021b3e90(self->target);
            if (t != NULL) {
                u16 ang;
                if (t->unk_44 != NULL) {
                    ang = func_ov000_0218d8f4(self, t->unk_44);
                } else {
                    ang = AngleTo(self, t);
                }
                cam->unk_fa = ang;
                cam->unk_da.b5 = 1;
            }
        }
        break;
    case 1: {
        ret = TRUE;
        if ((u16)(CamYaw(cam) - self->rot_y + 0x600) < 0xc00) {
            LFLD(u8, self, 0xb30) = 0;
            LFLD(u8, self, 0xb31) = 0;
        } else {
            cam->unk_fa = self->rot_y;
            cam->unk_da.b5 = 1;
        }
        break;
    }
    }
    return ret;
}
}
