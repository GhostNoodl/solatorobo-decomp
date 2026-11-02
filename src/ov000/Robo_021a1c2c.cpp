#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 st;
    u16 timer;
} State_021a1c2c;

extern "C" {
extern char data_ov000_021cc630[];
extern char *data_ov000_021ca060[];
extern char *data_ov000_021ca070[];
extern char data_ov000_021cc618[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc5e3[];
extern void *data_02097e4c;
extern void *data_02097dc8;
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
void Actor_Move(void *self, s32 a);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *st, s32 state, s32 x);
s32 func_ov003_021ce5b8(u32 color);
void func_ov000_021915a0(void *a);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_021b468c(void *self);
u16 Camera_GetYaw(void *cam);
u16 Pad_LookupDir(void *rng, void *p);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
void func_02062764(s32 a, s32 b);
void Body_SetPos(void *body, VecFx32 *pos, u32 angle);
BOOL func_ov000_02191120(void *a);

static inline u16 CamYaw_021a1c2c(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return Camera_GetYaw(cam);
}

void func_ov000_021a1c2c(Robo021ca458 *self) {
    VecFx32 p;
    VecFx32 a;
    VecFx32 b;
    BOOL turned;
    char *name;
    s32 se;

    switch (((const State_021a1c2c *)self->fsm)->st) {
    case 0:
        ((State_021a1c2c *)self->fsm)->st++;
        self->unk_b2b = 0;
        self->unk_b24_16 = 0;
        self->unk_b24_18 = 0;
    case 1:
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
        if (!self->unk_b24_16 && !self->unk_b24_17 && !self->unk_b24_18) {
            s32 target = self->unk_b08;
            if (target > 0x252) {
                target = 0x252;
            }
            func_ov000_021b1dd8((u8 *)self, target, 0x200, 0xf00, 0x466, self->unk_b2b < 8);
        } else if (self->unk_b24_18) {
            Actor_Move(self, 0);
        } else {
            s32 f = 1;
            if (self->unk_b24_17 || self->unk_b2b >= 8) {
                f = 0;
            }
            func_ov000_021b1fac(self, FALSE, f);
        }
        turned = FALSE;
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
            turned = TRUE;
        }
        if (turned) {
            func_ov000_02198360(self->fsm, 4, 1);
            return;
        }
        if (self->velY > 0) {
            if (self->hit->unk_50 & 0x80000000) {
                self->velY = -0xcd;
            }
            return;
        }
        if (self->hit->unk_50 & 0x20000000) {
            ((State_021a1c2c *)self->fsm)->timer = 6;
            self->unk_b24_19 = 0;
            name = data_ov000_021cc630;
            se = func_ov003_021ce5b8(self->hit->unk_50);
            if (self->unk_b24_1) {
                name = data_ov000_021ca060[self->unk_b24_5];
                if (self->unk_b24_5 != 0) {
                    self->unk_b24_22 = 0;
                    func_ov000_021915a0(self->model);
                }
                func_02049f44(data_02097e4c, 8, (u8 *)self + 0x70, 0);
                if (self->unk_b24_12 == 1) {
                    EffectObj *o = func_02065f88(0x6d, &self->pos);
                    o->SetScaleAll(0x99a);
                    o->SetRotXYZ(0xf000, 0, 0);
                } else if (!self->unk_b22_3 && (self->hit->unk_50 & 0xf0f0f0) != 0xe0e000) {
                    func_02065f88(0x12f, &self->pos)->SetScaleAll(0x666);
                }
            } else if (self->hit->unk_50 & 0x400) {
                se = 0x2bc;
                name = data_ov000_021cc618;
                func_02065f88(se, &self->pos);
                func_02065f88(se + 1, &self->pos);
                ((State_021a1c2c *)self->fsm)->timer = 0xc;
                se = -1;
            }
            func_ov000_02190cb0(self->model, name, 0x1000, 0);
            if (se >= 0) {
                func_02049f44(data_02097e4c, se, (u8 *)self + 0x70, -5);
                if ((self->hit->unk_50 & 0xf0f0f0) == 0xe0e000) {
                    p = self->pos;
                    p.y += 0xccd;
                    func_02065f88(0x2bc, &p);
                    func_02065f88(0x2bd, &p)->SetScaleAll(0x1800);
                }
            }
            ((State_021a1c2c *)self->fsm)->st++;
            self->velY = 0;
            self->gravity = 0;
            self->friction = 0x800;
            return;
        }
        if (func_ov000_021b468c(self) && self->mode == 1 && self->unk_b24_12 == 0 && !self->unk_b24_1 &&
            (self->padCur & 3) && (self->padCur & 0xf0)) {
            if (self->unk_b2b <= 0x10) {
                self->unk_b2b++;
            }
        } else {
            self->unk_b2b = 0;
        }
        if (!self->unk_b24_1) {
            if (self->unk_b2b >= 8 && self->unk_b2b <= 0x10) {
                u16 yaw = CamYaw_021a1c2c((u8 *)data_ov000_021ccd54 + 0xf4);
                u16 ang = yaw + Pad_LookupDir(data_02097dc8, (u8 *)self + 0xb70);
                s32 h;
                s32 r;
                a = self->pos;
                b = self->pos;
                b.y += self->height + 0x10;
                r = func_01ffbd6c(&a, &b, 0xc0000000, 0, 0, -1);
                if (r == -0x1000) {
                    h = self->height;
                } else {
                    h = r - 0x10;
                }
                a = self->pos;
                a.y += h;
                b = self->pos;
                b.y += h;
                b.x += (s32)(((s64)(self->radius * 2) * FX_SinCosTable_[(ang >> 4) * 2] + 0x800) >> 12);
                b.z += (s32)(((s64)(self->radius * 2) * FX_SinCosTable_[(ang >> 4) * 2 + 1] + 0x800) >> 12);
                if (func_01ffbd6c(&a, &b, 0x40000000, 0, 0, -1) == -0x1000) {
                    self->moveYaw = ang;
                    func_ov000_02190cb0(self->model, data_ov000_021cc62a, 0x800, 1);
                    if (self->velY < 0x148) {
                        self->velY = 0x148;
                    }
                } else {
                    func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x200, 0);
                }
            } else {
                func_ov000_02190cb0(self->model, data_ov000_021cc636, 0x200, 0);
            }
        } else {
            func_ov000_02190cb0(self->model, data_ov000_021ca070[self->unk_b24_5], 0x200, 0);
        }
        if (self->unk_b22_3 && self->gravity > 0x14) {
            self->gravity = 0x14;
        }
        {
            s32 lim;
            BOOL fall = FALSE;
            if (!(self->hit->unk_54 & 0x20000000)) {
                lim = -0xf000;
                if (self->unk_b22_0 || self->unk_b24_12 || self->unk_b24_19) {
                    lim = -0x2d000;
                }
                if (self->pos.y - self->unk_afc.y < lim) {
                    fall = TRUE;
                }
            }
            if (!fall) {
                return;
            }
        }
        LFLD(u16, ((u8 *)self->hp), 0xa) = 0xf0;
        func_02049f44(data_02097e4c, 0x34, (u8 *)self + 0x70, 0);
        if (self->unk_b22_0) {
            if (!self->unk_b24_1) {
                AnimCtrl *q;
                self->unk_b24_1 = 1;
                self->unk_b24_2 = 0;
                ((VObj *)self)->vfunc_18();
                self->unk_75c = self->pos;
                self->unk_76c = self->rot_x;
                self->unk_76e = self->rot_y;
                self->unk_770 = self->rot_z;
                func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
                q = self->mdl1.unk_1c;
                if (q != NULL) {
                    NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)self->mdl1.unk_24, (NNSG3dAnmObj *)q->cur);
                    q->name[0] = 0;
                    q->index = 0xff;
                    q->playing = 0;
                    q->same = 0;
                }
                self->mdl0.unk_cc = -1;
                data_0214a424->bits18.flag8 = 0;
                data_0214a424->bits18.flag9 = 0;
                func_02062764(3, 1);
                data_ov000_021ccd54->stageFlags = 1;
            }
            if (self->unk_9ac < 0xb4) {
                self->unk_9ac = 0xb4;
            }
        }
        {
            s32 y = self->unk_af0.y;
            s32 z = self->unk_af0.z;
            self->pos.x = self->unk_af0.x;
            self->pos.y = y + 0x159a;
            self->pos.z = z;
        }
        Body_SetPos(self->hit, (VecFx32 *)((u8 *)self + 0x70), self->rot_y);
        self->speed = 0;
        self->velY = 0x333;
        self->friction = 0;
        self->gravity = 0x29;
        self->unk_b24 |= 0x50000;
        return;
    case 2: {
        State_021a1c2c *s;
        { s32 f = 1; if (self->unk_b24_17) f = 0; func_ov000_021b1fac(self, TRUE, f); }
        turned = FALSE;
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
            turned = TRUE;
        }
        if (turned) {
            func_ov000_02198360(self->fsm, 4, 1);
            return;
        }
        s = (State_021a1c2c *)self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        if (!func_ov000_02191120(self->model) && ((s64)self->fsm->flags) == 0) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        self->unk_b24_16 = 0;
        self->unk_b24_17 = 0;
        self->unk_b24_18 = 0;
        break;
    }
    }
}
}
