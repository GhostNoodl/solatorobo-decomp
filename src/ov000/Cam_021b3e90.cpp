#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov000/FieldCam.h"


extern "C" {

extern ActorMgr *gActorMgr;
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
u16 Actor_YawToPos(Actor *self, void *target);
u16 FX_Atan2(s32 y, s32 x);

static inline Actor *FindActor021b3e90(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline u16 AngleTo(Robo021ca458 *self, Actor *other) {
    u16 angle;
    if (other == NULL || other == self) {
        angle = self->rot_y;
    } else {
        angle = FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
    }
    return angle;
}

BOOL func_ov000_021b3e90(Robo021ca458 *self) {
    BOOL ret;
    u16 dp;
    u16 dy;
    FieldCam *cam;
    ret = FALSE;
    cam = &gSceneCmd->cam;
    if (cam == NULL) {
        return ret;
    }
    if (cam->unk_d6 - 1 != cam->unk_d4) {
        cam->base.wallClip = 0;
        return ret;
    }
    cam->base.wallClip = 1;
    dp = 0;
    dy = 0;
    switch (self->unk_b31) {
    case 0:
        if (self->padTrig & 0x100) {
            if (self->unk_b30 != 0) {
                self->unk_b31 = 1;
                self->unk_b30 = 0;
            } else {
                self->unk_b30 = 20;
            }
        } else if (self->padCur & 0x100) {
            u16 keys = self->padCur;
            ret = TRUE;
            if (keys & 0x80) {
                dp = 0xf800;
            } else if (keys & 0x40) {
                dp = 0x800;
            }
            if (dp != 0) {
                dp += cam->base.pitch;
                if (dp > 0x8000) {
                    s32 t;
                    if (dp < 0xf200) {
                        dp = 0xf200;
                    }
                    t = 0x10000 - dp;
                    cam->unk_f4 = 0x8000 - t * 4;
                    cam->unk_da_2 = 1;
                    cam->unk_dc.x = 0;
                    cam->unk_dc.y = t + 0x1800;
                    cam->unk_dc.z = 0;
                    cam->unk_da_0 = 1;
                } else if (dp > 0x2800) {
                    dp = 0x2800;
                }
                cam->unk_f8 = dp;
                cam->unk_da_4 = 1;
            }
            keys = self->padCur;
            if (keys & 0x10) {
                dy = 0xf400;
            } else if (keys & 0x20) {
                dy = 0xc00;
            }
            if (dy != 0) {
                cam->unk_fa = dy + FieldCam_GetYaw(cam);
                cam->unk_da_5 = 1;
            }
        }
        if (self->unk_b30 != 0) {
            self->unk_b30--;
        }
        if (!ret && self->unk_b24_5 != 0 && self->target != 0xffff) {
            Actor *t = FindActor021b3e90(self->target);
            if (t != NULL) {
                u16 ang;
                if (t->unk_44 != NULL) {
                    ang = Actor_YawToPos(self, t->unk_44);
                } else {
                    ang = AngleTo(self, t);
                }
                cam->unk_fa = ang;
                cam->unk_da_5 = 1;
            }
        }
        break;
    case 1: {
        ret = TRUE;
        if ((u16)(FieldCam_GetYaw(cam) - self->rot_y + 0x600) < 0xc00) {
            self->unk_b30 = 0;
            self->unk_b31 = 0;
        } else {
            cam->unk_fa = self->rot_y;
            cam->unk_da_5 = 1;
        }
        break;
    }
    }
    return ret;
}
}
