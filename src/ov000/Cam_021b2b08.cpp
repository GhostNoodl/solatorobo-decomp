#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    u8 pad[2];
    s32 unk_10;
} Msg021b2b08;

extern "C" {
extern void *data_ov000_021ccd68;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
u16 Camera_GetYaw(void *cam);
void func_ov000_0218db58(void *self, u16 angle, u16 center, u16 range, s32 step);
void Actor_SendMsg(void *t, u16 id, s32 a, s32 b, s32 c, void *arg);

static inline Actor *FindActor021b2b08(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

void func_ov000_021b2b08(Robo021ca458 *self) {
    Actor *a = FindActor021b2b08(self->unk_b20);
    void *sub = NULL;
    u8 *cam;
    u16 ang;
    u16 ry;
    u16 rx;
    if (a != NULL) {
        sub = ((void *)a->targetObj);
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f = 1;
    }
    if (sub == NULL || (self->padTrig & 2)) {
        self->moveYaw = self->rot_y - 0x8000;
        self->speed = 0x114;
        self->friction = 0;
        self->velY = 0x53f;
        self->gravity = 0x52;
        self->rot_x = 0;
        self->unk_b29 |= 2;
        func_ov000_02198360(((void *)self->fsm), 0x1d, 0);
        self->fsm->st = 0x64;
        return;
    }
    cam = (u8 *)data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        ang = LFLD(u16, cam, 0x44);
    } else {
        ang = Camera_GetYaw(cam);
    }
    ry = self->rot_y;
    if (self->padCur & 0x20) {
        ry += 0x280;
    } else if (self->padCur & 0x10) {
        ry -= 0x280;
    }
    func_ov000_0218db58(self, ry, ang, 0x1500, 0x400);
    {
        u16 f = self->padCur;
        u16 base = LFLD(u16, cam, 0x42);
        rx = self->rot_x;
        if (f & 0x40) {
            u16 d;
            rx -= 0x80;
            d = rx - base;
            if (d > 0x8000 && d < 0xea00) {
                rx = base + 0xea00;
            }
        } else if (f & 0x80) {
            u16 d;
            rx += 0x80;
            d = rx - base;
            if (d < 0x8000 && d > 0x600) {
                rx = base + 0x600;
            }
        }
    }
    self->rot_x = rx;
    if (self->unk_b20 != 0xffff) {
        Msg021b2b08 msg;
        msg.pos = a->pos;
        msg.rot[0] = self->rot_x;
        msg.rot[1] = self->rot_y;
        msg.rot[2] = self->rot_z;
        msg.unk_10 = 0;
        Actor_SendMsg(a, self->id, 7, 1, 0x18, &msg);
    }
}
}
