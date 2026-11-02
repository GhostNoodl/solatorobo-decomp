#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 2;
    u16 rest : 12;
} H22_021a9be8;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_021a9be8;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021a9be8;

typedef struct {
    u16 a;
    u16 b;
    u16 c[4];
    s16 d;
} Desc_021a9be8;

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern char data_ov000_021cc68a[];
extern char data_ov000_021ca12c[];
Actor *ActorMgr_GetActor(void *mgr, u16 id);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
BOOL func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
s32 **func_ov000_02190a30(void *a, int b);
void *func_ov000_0219122c(void *a, s32 frame);
void Actor_Move(void *self, s32 a);
void func_ov000_0218dd8c(void *self, u16 base, s32 turn, void *p);
u16 Actor_YawToPos(void *self, void *target);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void Actor_SendMsg(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
u8 *Group_SpawnActor(void *mgr, Desc_021a9be8 *d, void *pos, void *rot, u16 a);
void *func_0204a028(void *a, s32 b, void *c, s32 d);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u8 *func_02065f88(s32 id, void *pos);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
u16 Camera_GetYaw(void *cam);
void func_ov000_02168e18(void *self, s32 a, s32 b, VecFx32 *p);

static inline Actor *FindActor_021a9be8(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Both_021a9be8(u8 *c) {
    return (LFLD(H22_021a9be8, c, 0x22).b0 == 1 && LFLD(H22_021a9be8, c, 0x22).b1 == 1) ? TRUE : FALSE;
}

static inline BOOL Has_021a9be8(u8 *c) {
    return LFLD(H22_021a9be8, c, 0x22).b2 != 0 ? TRUE : FALSE;
}

static inline u16 AngleTo_021a9be8(Robo021ca458 *self, u8 *other) {
    if (other == NULL || other == (u8 *)self) {
        return self->rot_y;
    }
    return FX_Atan2(LFLD(s32, other, 0x70) - self->pos.x, LFLD(s32, other, 0x78) - self->pos.z);
}

static inline u16 CamYaw_021a9be8(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return Camera_GetYaw(cam);
}

static inline s32 Frame_021a9be8(Model0218fe1c *m) {
    s32 f = 0;
    s32 **a = func_ov000_02190a30(m, f);
    if (*a != NULL) {
        f = **a;
    }
    return f;
}

static inline void SetFx_021a9be8(Robo021ca458 *self, u8 *o, s32 rz) {
    self->unk_b48 = LFLD(s32, o, 0x24);
    LFLD(s32, o, 0x3c) = 0x2000;
    self->unk_b4c = self->unk_a74 - self->pos.x;
    self->unk_b50 = self->unk_a78 - self->pos.y;
    self->unk_b54 = self->unk_a7c - self->pos.z;
    self->unk_b58 = 0;
    self->unk_b5a = -self->rot_y;
    self->unk_b5c = 0;
    LFLD(s16, self, 0xb5e) = rz;
}

static inline void Bump_021a9be8(Robo021ca458 *self) {
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0 - self->pos.x, self->unk_af8 - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
    }
}

void func_ov000_021a9be8(Robo021ca458 *self) {
    Desc_021a9be8 desc;
    VecFx32 z;
    Pose_021a9be8 m;
    VecFx32 t;
    Actor *tg;
    u8 *a;
    u8 *o;
    s32 lim;
    BOOL fall;
    ActorSub40 *s;
    u16 tm;

    tg = FindActor_021a9be8(self->target);
    if (tg != NULL) {
        u8 *c = tg->unk_44;
        if (!(c != NULL && Both_021a9be8(c) && (u16)(tg->id & 0xf000) == 0x5000 && Has_021a9be8(c))) {
            tg = NULL;
        } else if (self->unk_b2f == 0) {
            self->unk_b2f++;
        }
    }
    fall = FALSE;
    if (!(self->hit->unk_54 & 0x20000000)) {
        lim = -0xf000;
        if (self->unk_b22_0 || self->unk_b24_12 || self->unk_b24_19) {
            lim = -0x2d000;
        }
        if (self->pos.y - self->unk_b00 < lim) {
            fall = TRUE;
        }
    }
    if (fall) {
        self->unk_b36 = 0;
        self->unk_b24 |= 0x40000;
    }
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc68a, 0x555, 1);
        self->speed = 0;
        self->velY = 0;
        if (self->unk_b36 != 0) {
            self->unk_b36 = 1;
        }
        self->friction = 0;
        self->gravity = 0x29;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->unk_b36 == 0) {
            func_ov000_02198360(self->fsm, 1, 0);
            break;
        }
        if (Frame_021a9be8(self->model) > 0x14000) {
            func_ov000_0219122c(self->model, 0x14000);
            self->unk_ae4_0 = 1;
        }
        if (self->fsm->timer == 0x14) {
            o = func_02065f88(0x640, (u8 *)self + 0xa74);
            if (o != NULL) {
                SetFx_021a9be8(self, o, 0);
            }
        }
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0x20) {
            s32 i;
            self->fsm->timer = 0x20;
            func_0204a028(data_02097e4c, 0x44, &self->pos, 2);
            func_02049f44(data_02097e4c, 0x78, &self->pos, 0);
            desc.a = 0x480c;
            desc.b = 0x4000;
            for (i = 0; i < 4; i++) {
                desc.c[i] = 0;
            }
            desc.d = -1;
            a = Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0xa74, (u8 *)self + 0x7c, 0xffff);
            if (a != NULL) {
                u8 *p;
                LFLD(B8_021a9be8, a, 0x16).b0 = 1;
                LFLD(void *, a, 0x60) = data_ov000_021ca12c;
                p = LFLD(u8 *, a, 0x4c);
                if (p != NULL) {
                    LFLD(u16, p, 0x1c) = self->id;
                    LFLD(u8, p, 0x18) |= 8;
                }
                func_ov000_0218d46c(a, self->id, 9);
                self->unk_b24_5 = 1;
                self->unk_b24_7 = 0;
                self->unk_b1c = LFLD(u16, a, 0xc);
                o = func_02065f88(0x195, &self->pos);
                if (o != NULL) {
                    SetFx_021a9be8(self, o, -0x7b);
                }
                self->fsm->st++;
            }
        }
        break;
    case 2:
        if (Frame_021a9be8(self->model) > 0x14000) {
            func_ov000_0219122c(self->model, 0x14000);
        }
        if (self->unk_b36 == 0) {
            a = (u8 *)FindActor_021a9be8(self->unk_b1c);
            if (a == NULL || (LFLD(u8 *, a, 0x40) != NULL ? LFLD(u8, LFLD(u8 *, a, 0x40), 0x13) : 0) == 9) {
                self->fsm->timer = 0;
                self->fsm->st = 10;
            }
        }
        break;
    case 10:
        a = (u8 *)FindActor_021a9be8(self->unk_b1c);
        if (a != NULL) {
            u16 ang;
            func_ov000_0218d46c(a, self->id, 0xb);
            if (a != NULL) {
                VecFx32 *q = LFLD(VecFx32 *, a, 0x48);
                if (q != NULL) {
                    t.x = q->x;
                    t.y = q->y;
                    t.z = q->z;
                } else {
                    t.x = LFLD(s32, a, 0x70);
                    t.y = LFLD(s32, a, 0x74);
                    t.z = LFLD(s32, a, 0x78);
                }
                if (func_01ffbd6c((VecFx32 *)((u8 *)self + 0x70), &t, -1, 0, 0, -1) != -0x1000) {
                    t.x -= self->pos.x;
                    t.y -= self->pos.y;
                    t.z -= self->pos.z;
                    VEC_MultAdd(0xc00, &t, (VecFx32 *)((u8 *)self + 0x70), &t);
                    m.pos = t;
                    m.rx = LFLD(u16, a, 0x7c);
                    m.ry = LFLD(u16, a, 0x7e);
                    m.rz = LFLD(u16, a, 0x80);
                    m.unk = 0;
                    Actor_SendMsg(a, self->id, 7, 1, sizeof(Pose_021a9be8), &m);
                }
            }
            ang = self->rot_y;
            if (tg != NULL) {
                if (((void *)tg->unk_44) != NULL) {
                    ang = Actor_YawToPos(self, ((void *)tg->unk_44));
                } else {
                    ang = AngleTo_021a9be8(self,(u8 *)tg);
                }
            }
            {
                VecFx32 p;
                p.x = LFLD(s32, a, 0x70);
                p.y = LFLD(s32, a, 0x74);
                p.z = LFLD(s32, a, 0x78);
                p.x += FX_SinCosTable_[(ang >> 4) * 2];
                p.z += FX_SinCosTable_[(ang >> 4) * 2 + 1];
                LFLD(VecFx32, a, 0x84) = p;
            }
            LFLD(u16, a, 0x7c) = 0;
            LFLD(u16, a, 0x7e) = ang;
            LFLD(u16, a, 0x80) = 0;
            LFLD(u16, a, 0x90) = self->target;
            self->rot_y = func_01ffc128(ang, self->rot_y, 0x400, 1, 0x8000);
            func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        }
        self->unk_b1c = 0xffff;
        self->unk_b1e = 0xffff;
        self->unk_b24_5 = 0;
        self->unk_b24_7 = self->unk_b24_9;
        self->target = 0xffff;
        self->fsm->st++;
        break;
    case 11:
        if (func_ov000_02191120(self->model)) {
            self->moveYaw = self->rot_y;
            if (self->unk_b36 != 0) {
                self->fsm->st = 0;
            } else {
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        break;
    }
    if (self->fsm->st >= 10) {
        return;
    }
    if (!self->unk_b24_17) {
        u16 yaw = CamYaw_021a9be8((u8 *)data_ov000_021ccd54 + 0xf4);
        u16 ang;
        if (self->padCur & 0xf0) {
            self->speed = self->unk_b08 >> 2;
            func_ov000_0218dd8c(self, yaw, 0, (u8 *)self + 0xb70);
            ang = self->moveYaw;
        } else {
            self->friction = 0x29;
            Actor_Move(self, 0);
            ang = self->rot_y;
        }
        if (tg != NULL) {
            if (((void *)tg->unk_44) != NULL) {
                ang = Actor_YawToPos(self, ((void *)tg->unk_44));
            } else {
                ang = AngleTo_021a9be8(self,(u8 *)tg);
            }
        }
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x400, 1, 0x8000);
    } else {
        Actor_Move(self, 0);
    }
    func_ov000_021987b8(self->hit, 1, 0, 0);
    if (self->velY < 0 && (self->hit->unk_50 & 0x20000000)) {
        self->velY = 0;
        LFLD(u16, self->hit, 0x9a) |= 0x20;
        if (self->unk_b24_17) {
            self->unk_b24_17 = 0;
            self->moveYaw = self->rot_y;
            self->speed = 0;
        }
    }
    Bump_021a9be8(self);
    tm = self->fsm->timer;
    if (tm == 0) {
        return;
    }
    {
        u8 *p;
        u8 *x;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        p = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
        if (p == NULL) return;
        x = LFLD(u8 *, p, 0x70);
        if (x == NULL) return;
        func_ov000_02168e18(x, tm, 0x20, &z);
    }
}
}
