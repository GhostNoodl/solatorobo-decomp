#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    s16 speed;
    u8 pad02[6];
    u16 rx;
    u16 ry;
    u16 rz;
    u16 mode;
    s16 se0;
    s16 se0arg;
    s16 se1;
    s16 se1arg;
} Hang_021b209c;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021b209c;

typedef struct {
    u16 a;
    u8 b;
    u16 c;
} Arg_021b209c;

typedef struct {
    u8 pad[0xc];
    s32 tx;
    u8 pad10[4];
    s32 tz;
    u8 pad18[0x14];
    u32 keys;
} Pad_021b209c;

class Eff_021b209c {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
};

extern "C" {
extern u8 *data_ov000_021ccd68;
extern Hang_021b209c data_ov000_021ca320[];
extern Pad_021b209c data_02fe0f14;
extern void *data_02097e4c;
Actor *ActorMgr_GetActor(void *mgr, u16 id);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
u16 FX_Atan2(s32 x, s32 z);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void Actor_SendMsg(void *a, u16 id, s32 b, s32 c, s32 d, void *e);
void *func_02049f44(void *snd, s32 id, void *pos, s32 a);
void func_ov000_0218996c(s32 a, s32 b);
BOOL func_ov000_0219aae8(void *a, void *b, s32 c, s32 d, s32 e, VecFx32 *f, void *g, s32 h, s32 i, s32 j, s32 k);
void Actor_Move(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
s32 func_02049afc(void *snd, s32 se);
void func_0204a0d4(void *snd, s32 h, s32 arg);
void SndMgr_StopSeqArc(void *snd, s32 h);
Eff_021b209c *func_02065f88(s32 id, void *pos);
void func_ov000_0218d46c(void *a, u16 id, s32 b);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline Actor *FindActor_021b209c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Mul_021b209c(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov000_021b209c(Robo021ca458 *self) {
    BOOL grab = FALSE;
    u8 ok = FALSE;
    Hang_021b209c *info;
    s32 ret;
    Actor *actor;
    u8 *sub;
    VecFx32 from;
    VecFx32 to;
    VecFx32 v;
    Pose_021b209c p;
    Arg_021b209c arg;

    actor = FindActor_021b209c(self->unk_b20);
    sub = NULL;
    if (actor != NULL) {
        sub = ((u8 *)actor->targetObj);
    }
    info = NULL;
    if (sub != NULL) {
        info = &data_ov000_021ca320[LFLD(u16, sub, 6)];
    }
    if (info == NULL) {
        return;
    }
    from = self->pos;
    from.y += self->height;
    to = from;
    to.x += Mul_021b209c(FX_SinCosTable_[((u16)(self->moveYaw + 0x1200) >> 4) * 2], 0x2333);
    to.z += Mul_021b209c(FX_SinCosTable_[((u16)(self->moveYaw + 0x1200) >> 4) * 2 + 1], 0x2333);
    ret = func_01ffbd6c(&from, &to, 0x40000000, 0, 0, -1);
    if (ret == -0x1000) {
        to = from;
        to.x += Mul_021b209c(FX_SinCosTable_[((u16)(self->moveYaw - 0x1200) >> 4) * 2], 0x2333);
        to.z += Mul_021b209c(FX_SinCosTable_[((u16)(self->moveYaw - 0x1200) >> 4) * 2 + 1], 0x2333);
        ret = func_01ffbd6c(&from, &to, 0x40000000, 0, 0, -1);
    }
    if (ret != -0x1000) {
        if (data_02fe0f14.keys & 0x200) {
            grab = TRUE;
            if (info->mode == 1) {
                ok = TRUE;
            }
        } else {
            ok = TRUE;
        }
        if (ok) {
            u16 ang = FX_Atan2(data_02fe0f14.tx, data_02fe0f14.tz);
            if ((u16)(ang - self->moveYaw) < 0x8000) {
                self->moveYaw = ang - 0x4000;
            } else {
                self->moveYaw = ang + 0x4000;
            }
        }
    }
    if (grab) {
        self->speed = 0;
    } else {
        s32 spd = info->speed;
        if (self->speed != 0) {
            s32 d = (spd - self->speed) >> 3;
            if (d == 0) {
                self->speed = spd;
            }
            self->speed += d;
        } else {
            self->speed = spd;
        }
        self->gravity = 0x52;
        if (!(self->hit->unk_54 & 0x20000000)) {
            self->gravity += 0x52;
        }
        self->rot_y = func_01ffc128(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        if (((s32)self->hit->unk_58) != 0) {
            self->speed >>= 4;
            self->velY = 0x200;
            arg.c = 0xffff;
            arg.a = 0xa;
            arg.b = 1;
            Actor_SendMsg(self, self->id, 9, 0, 6, &arg);
            func_02049f44(data_02097e4c, 0x309, &self->pos, 0);
            func_ov000_0218996c(0xa, 0xf);
            v.y = self->centerY;
            v.x = 0;
            v.z = 0;
            func_ov000_0219aae8(self, self, 0xa, 0, 0x30, &v, 0, self->radius + 0xccd, 0, -1, 0x1000);
        }
    }
    self->friction = 0;
    Actor_Move(self, 0);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    {
        ActorSub48 *body = self->hit;
        if (body->unk_50 & 0x20000000) {
            if (self->velY <= 0) {
                self->velY = -0x800;
                LFLD(u16, body, 0x9a) |= 0x20;
                if (info->se0 >= 0 && self->seSlot < 0) {
                    self->seSlot = func_02049afc(data_02097e4c, info->se0);
                    func_0204a0d4(data_02097e4c, self->seSlot, info->se0arg);
                }
                if (info->se1 >= 0 && self->unk_b66 < 0) {
                    self->unk_b66 = func_02049afc(data_02097e4c, info->se1);
                    func_0204a0d4(data_02097e4c, self->unk_b66, info->se1arg);
                }
            }
            if ((self->hit->unk_50 & 0x400) && (LFLD(u16, data_ov000_021ccd68, 0xa) & 0x1f)) {
                func_02065f88(0x2bd, &self->pos);
            }
        } else {
            if (self->seSlot >= 0) {
                SndMgr_StopSeqArc(data_02097e4c, self->seSlot);
                self->seSlot = -1;
            }
            if (self->unk_b66 >= 0) {
                SndMgr_StopSeqArc(data_02097e4c, self->unk_b66);
                self->unk_b66 = -1;
            }
        }
    }
    if (self->unk_b20 != 0xffff) {
        p.pos = self->pos;
        p.rx = self->rot_x;
        p.ry = self->rot_y;
        p.rz = self->rot_z;
        p.rx += info->rx;
        p.ry += info->ry;
        p.rz += info->rz;
        p.unk = 0;
        if (grab && info->mode != 2) {
            p.ry += 0x8000;
        }
        Actor_SendMsg(actor, self->id, 7, 1, 0x18, &p);
    }
    if (!grab) {
        return;
    }
    if (self->unk_b24_12 == 1 && !(self->hit->unk_50 & 0x20000000)) {
        return;
    }
    if (info->mode == 2) {
        func_ov000_0218d46c(actor, self->id, 0xa);
    }
    if (info->mode == 3) {
        self->speed = info->speed;
        self->velY = 0x200;
    } else {
        self->speed = Mul_021b209c(info->speed, 0x59a);
        if (self->speed < 0x229) {
            self->speed = 0x229;
        }
        self->velY = 0x53f;
    }
    self->friction = 0;
    self->gravity = 0x52;
    if (self->unk_b24_12 == 1) {
        Eff_021b209c *e = func_02065f88(0x6d, &self->pos);
        e->v0c(0xccd);
        e->v34(0x2000, 0, 0);
    }
    if (self->seSlot >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->seSlot);
        self->seSlot = -1;
    }
    if (self->unk_b66 >= 0) {
        SndMgr_StopSeqArc(data_02097e4c, self->unk_b66);
        self->unk_b66 = -1;
    }
    self->unk_b29_1 = 1;
    func_ov000_02198360(((void *)self->fsm), 0x1d, 0);
    self->fsm->st = 0x64;
}
}
