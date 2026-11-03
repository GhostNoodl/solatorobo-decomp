#include "ov000/FieldCam.h"
#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/Pad.h"

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
void Robo021ca458_WalkByPad(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
void Actor_Move(Actor *self, s32 a);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
BOOL History_SetState(void *st, s32 state, s32 x);
s32 Ov003_SurfaceSoundId(u32 color);
void Model0218fe1c_SetLoop(void *a);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_021b468c(Robo021ca458 *self);
u16 Pad_LookupDir(void *rng, void *p);
s32 Hit_CastSegment(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
void Shared_ChangeFlags(s32 a, s32 b);
void Body_SetPos(void *body, VecFx32 *pos, u32 angle);
BOOL Model0218fe1c_IsAnimDone(void *a);

void Robo021ca458_State04(Robo021ca458 *self) {
    VecFx32 p;
    VecFx32 a;
    VecFx32 b;
    BOOL turned;
    char *name;
    s32 se;

    switch (((const State_021a1c2c *)self->fsm)->st) {
    case 0:
        self->fsm->st++;
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
            Robo021ca458_WalkByPad((u8 *)self, target, 0x200, 0xf00, 0x466, self->unk_b2b < 8);
        } else if (self->unk_b24_18) {
            Actor_Move(self, 0);
        } else {
            s32 f = 1;
            if (self->unk_b24_17 || self->unk_b2b >= 8) {
                f = 0;
            }
            Robo021ca458_Move(self, FALSE, f);
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
            History_SetState(self->fsm, 4, 1);
            return;
        }
        if (self->velY > 0) {
            if (self->hit->unk_50 & 0x80000000) {
                self->velY = -0xcd;
            }
            return;
        }
        if (self->hit->unk_50 & 0x20000000) {
            self->fsm->timer = 6;
            self->unk_b24_19 = 0;
            name = data_ov000_021cc630;
            se = Ov003_SurfaceSoundId(self->hit->unk_50);
            if (self->unk_b24_1) {
                name = data_ov000_021ca060[self->unk_b24_5];
                if (self->unk_b24_5 != 0) {
                    self->unk_b24_22 = 0;
                    Model0218fe1c_SetLoop(self->model);
                }
                SndMgr_PlayAt(data_02097e4c, 8, (u8 *)self + 0x70, 0);
                if (self->unk_b24_12 == 1) {
                    EffectObj *o = Effect_SpawnId(0x6d, &self->pos);
                    o->SetScaleAll(0x99a);
                    o->SetRotXYZ(0xf000, 0, 0);
                } else if (!self->unk_b22_3 && (self->hit->unk_50 & 0xf0f0f0) != 0xe0e000) {
                    Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x666);
                }
            } else if (self->hit->unk_50 & 0x400) {
                se = 0x2bc;
                name = data_ov000_021cc618;
                Effect_SpawnId(se, &self->pos);
                Effect_SpawnId(se + 1, &self->pos);
                self->fsm->timer = 0xc;
                se = -1;
            }
            Model0218fe1c_SetAnim(self->model, name, 0x1000, 0);
            if (se >= 0) {
                SndMgr_PlayAt(data_02097e4c, se, (u8 *)self + 0x70, -5);
                if ((self->hit->unk_50 & 0xf0f0f0) == 0xe0e000) {
                    p = self->pos;
                    p.y += 0xccd;
                    Effect_SpawnId(0x2bc, &p);
                    Effect_SpawnId(0x2bd, &p)->SetScaleAll(0x1800);
                }
            }
            self->fsm->st++;
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
                u16 yaw = FieldCam_GetYaw(&data_ov000_021ccd54->cam);
                u16 ang = yaw + Pad_LookupDir(data_02097dc8, (u8 *)self + 0xb70);
                s32 h;
                s32 r;
                a = self->pos;
                b = self->pos;
                b.y += self->height + 0x10;
                r = Hit_CastSegment(&a, &b, 0xc0000000, 0, 0, -1);
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
                if (Hit_CastSegment(&a, &b, 0x40000000, 0, 0, -1) == -0x1000) {
                    self->moveYaw = ang;
                    Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 1);
                    if (self->velY < 0x148) {
                        self->velY = 0x148;
                    }
                } else {
                    Model0218fe1c_SetAnim(self->model, data_ov000_021cc636, 0x200, 0);
                }
            } else {
                Model0218fe1c_SetAnim(self->model, data_ov000_021cc636, 0x200, 0);
            }
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov000_021ca070[self->unk_b24_5], 0x200, 0);
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
        self->hpObj->unk_0a = 0xf0;
        SndMgr_PlayAt(data_02097e4c, 0x34, (u8 *)self + 0x70, 0);
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
                Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e3, 0x1000, 1);
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
                Shared_ChangeFlags(3, 1);
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
        { s32 f = 1; if (self->unk_b24_17) f = 0; Robo021ca458_Move(self, TRUE, f); }
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
            History_SetState(self->fsm, 4, 1);
            return;
        }
        s = (State_021a1c2c *)self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        if (!Model0218fe1c_IsAnimDone(self->model) && ((s64)self->fsm->flags) == 0) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        self->unk_b24_16 = 0;
        self->unk_b24_17 = 0;
        self->unk_b24_18 = 0;
        break;
    }
    }
}
}
