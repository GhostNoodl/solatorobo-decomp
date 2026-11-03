#include "ov000/FieldCam.h"
#include "ov000/ActorMgr.h"
#include "ov000/LoCommon.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    VecFx32 pos;
    ActorRot rot;
    s32 x;
} Msg_021a6280;

typedef struct {
    u8 pad_00[6];
    FieldId rgb;
} Def_021a6280;

#define SQRTCNT_021a6280 (*(volatile u16 *)0x40002b0)
#define SQRT_RESULT_021a6280 (*(volatile u32 *)0x40002b4)
#define SQRT_PARAM_021a6280 (*(volatile u64 *)0x40002b8)

extern "C" {
extern char data_ov000_021cc68a[];
extern char data_ov000_021cc690[];
extern char data_ov000_021cc5e3[];
extern Def_021a6280 data_ov000_021c9fe8;
extern void *gSndMgr;
Actor *Actor_GetTarget(Actor *self);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
u16 Actor_YawToPos(Actor *self, void *target);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
BOOL History_SetState(void *st, s32 state, s32 x);
void *SndMgr_PlayVolume(void *a, s32 b, s32 c, s32 d, s32 e);
s32 SndMgr_PlayPan(void *a, s32 b, s32 c);
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_IsAnimDone(void *a);
BOOL Model0218fe1c_IsAnimDelayed(void *a);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
void *Model0218fe1c_SetAnimFrame(void *a, s32 frame);
void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
s32 Rand_UpTo(s32 max);
void Field_ShakeCamera(s32 a, s32 b);
void func_ov000_021899d8(VecFx32 *a, s32 b, s32 c, s32 d, s16 e, s16 f);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
s32 Hit_CastSegment(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
void Ov003_AddMeter_021cedf4(u16 add);
u8 Ov003_GetMaxCombo(void);

static inline Actor *FindActor_021a6280(u16 id) {
    Actor *r;
    if (gActorMgr == NULL) {
        return NULL;
    }
    r = ActorMgr_GetActor(gActorMgr, id);
    return r;
}

static inline u16 AngleTo_021a6280(Robo021ca458 *self, Actor *other) {
    if (other == NULL || other == self) {
        return self->rot_y;
    }
    return FX_Atan2(other->pos.x - self->pos.x, other->pos.z - self->pos.z);
}

static inline BOOL FieldId_Eq(FieldId *a, FieldId b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 FxMul_021a6280(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Robo021ca458_State0b(Robo021ca458 *self) {
    BOOL busy;
    u16 ang;
    Actor *a;
    ActorSub4c *sub;
    Actor *t;
    VecFx32 p;
    VecFx32 d;
    VecFx32 o;
    Msg_021a6280 m;
    VecFx32 v;

    a = FindActor_021a6280(self->unk_b1c);
    self->unk_b24_26 = 0;
    sub = NULL;
    busy = FALSE;
    if (a != NULL) {
        sub = (ActorSub4c *)((u8 *)a->targetObj);
        if ((u16)(a->id & 0xf000) == 0x5000 && a->hp != NULL) {
            if (*a->hp == 0) {
                self->unk_b24_26 = 1;
            } else {
                busy = TRUE;
            }
        }
    }
    switch (self->fsm->st) {
    case 0:
        if (!self->unk_93_4) {
            self->unk_b24_22 = 0;
        }
        if (!busy) {
            self->unk_b24_22 = 0;
        }
        if (self->unk_b24_5 == 1) {
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc68a, 0x555, 0);
            self->unk_b24_7 = 0;
            if (self->unk_b22_3 && self->unk_93_4) {
                Model0218fe1c_SetAnimFrame(self->model, 0x14000);
                Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
            } else if (self->unk_b24_22 != 0) {
                Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
            }
        } else {
            self->unk_b2b = 0;
            self->unk_b2c_0 = 0;
            self->unk_b2c_1 = 0;
            self->unk_b2c_2 = 0;
            self->unk_b2c_3_f = 0;
            self->unk_b2c_7 = 0;
            if (self->unk_ba4 != NULL && self->unk_b24_22 != 0) {
                if (self->unk_ba4->unk_06_0 && (self->padCur & 0xf0) && (self->hit->unk_50 & 0x20000000) &&
                    (!self->unk_ba4->unk_06_2 || (self->padCur & 0x30))) {
                    self->unk_b2c_0 = true;
                    History_SetState(self->fsm, 0x11, 0);
                    goto end;
                }
                if (self->unk_ba4->unk_06_2 && (self->padCur & 0xf0) && (self->hit->unk_50 & 0x20000000)) {
                    self->unk_b2c_2 = 1;
                    History_SetState(self->fsm, 0x11, 0);
                    goto end;
                }
                if (self->unk_ba4->unk_06_1 && (self->padCur & 0xf0) && !(self->hit->unk_50 & 0x20000000)) {
                    self->unk_b2c_1 = 1;
                    History_SetState(self->fsm, 0x11, 0);
                    if (self->unk_b24_22 >= 2 && sub->unk_1a >= 3) {
                        self->unk_b2a_0 = true;
                    }
                    goto end;
                }
            }
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc690, 0x400, 0);
            if (self->unk_93_4) {
                if (self->unk_b24_22 != 0) {
                    Model0218fe1c_SetAnimSpeed(self->model, 0x3000);
                } else {
                    Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
                }
            }
        }
        if (self->unk_b24_22 != 0) {
            s32 se;
            s32 lvl = 0;
            EffectObj *e;
            Model0218fe1c_SetAnimDelay(self->model, 0x14, lvl);
            se = 0x194;
            if (self->unk_b24_22 >= 2 && sub != NULL) {
                if (sub->unk_1a == 2) {
                    se += 1;
                    lvl = 2;
                } else if (sub->unk_1a >= 3) {
                    lvl = sub->unk_1a;
                    se += 2;
                    self->unk_b2a_0 = true;
                }
            }
            SndMgr_PlayPan(gSndMgr, 0x44, lvl);
            e = Effect_SpawnId(se, &self->pos);
            e->speed = 0x1400;
            e->AddPosXYZ(0, self->centerY, 0);
            {
                u32 sc = 0xe66;
                if (self->unk_b24_22 < 2) {
                    sc >>= 1;
                }
                e->SetScaleAll(sc);
            }
            if (!self->unk_b22_3 && gStageFlags->bits18.mode == 1) {
                u16 n = 0xc;
                if (sub != NULL) {
                    n += (u16)(sub->unk_1a << 1);
                }
                if (self->unk_ba4 != NULL) {
                    n += self->unk_ba4->unk_05_4;
                }
                Ov003_AddMeter_021cedf4(n);
            }
        } else if (self->unk_b24_26) {
            Model0218fe1c_SetAnimDelay(self->model, 0x32, 0);
            SndMgr_PlayVolume(gSndMgr, 0x30c, -1, -1, -1);
            EffectHud_New2716();
        }
        if (self->unk_b24_12 == 0) {
            if (self->speed > 0x229) {
                self->speed = 0x229;
            }
            if (self->velY < 0x5c) {
                self->velY = 0x5c;
            }
            self->velY -= self->velY >> 1;
            self->gravity = 10;
            self->friction = 0xe66;
        }
        self->fsm->st++;
        break;
    case 1:
        t = Actor_GetTarget(self);
        if (t != NULL) {
            if (((void *)t->unk_44) != NULL) {
                ang = Actor_YawToPos(self, ((void *)t->unk_44));
            } else {
                ang = AngleTo_021a6280(self, t);
            }
        } else if (self->unk_b24_12 == 0) {
            ang = self->rot_y;
            if (self->mode == 1 && (self->padCur & 0xf0)) {
                ang = self->padDir + FieldCam_GetYaw(&gSceneCmd->cam);
            }
        } else {
            ang = self->rot_y;
        }
        self->rot_y = Angle_Approach(ang, self->rot_y, 0x59a, 1, 0x8000);
        self->unk_b2c_3_f = 0;
        if (self->unk_b24_22 != 0 && self->unk_ba4 != NULL && self->unk_ba4->unk_06_3 && (self->padTrig & 1) &&
            self->unk_b2c_7 < 5 && sub != NULL) {
            EffectObj *e;
            p.x = sub->dest.x;
            p.y = sub->dest.y;
            p.z = sub->dest.z;
            e = Effect_SpawnId(0x69, &p);
            self->unk_b48 = e->id;
            self->unk_b5e = 0x7b;
            self->unk_b4c = p.x - self->pos.x;
            self->unk_b50 = p.y - self->pos.y;
            self->unk_b54 = p.z - self->pos.z;
            self->unk_b58 = 0;
            self->unk_b5a = 0;
            self->unk_b5c = 0;
            e->SetScaleAll(0x800);
            e->speed = 0x2800;
            Field_ShakeCamera(5, 6);
            SndMgr_PlayVolume(gSndMgr, 0x7a, -1, -1, -1);
            self->unk_b2c_3_f = 1;
            self->unk_b2c_7++;
        }
        if (self->model->anim_state == 1) {
            if (self->unk_b24_5 != 0 && a != NULL) {
                ActorSub4c *s2;
                Actor_SendMsgU8(a, self->id, 0xb);
                if (a != NULL) {
                    if (a->hit != NULL) {
                        v = a->hit->pos;
                    } else {
                        v = a->pos;
                    }
                    if (Hit_CastSegment((VecFx32 *)((u8 *)self + 0x70), &v, -1, 0, 0, -1) != -0x1000) {
                        v.x -= self->pos.x;
                        v.y -= self->pos.y;
                        v.z -= self->pos.z;
                        VEC_MultAdd(0xc00, &v, (VecFx32 *)((u8 *)self + 0x70), &v);
                        m.pos = v;
                        m.rot = a->rot;
                        m.x = 0;
                        Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &m);
                    }
                }
                a->rot_y = ang;
                self->rot_y = ang;
                if (a->unk_93_7_f) {
                    a->target = self->target;
                }
                s2 = (ActorSub4c *)((u8 *)a->targetObj);
                if (s2 != NULL) {
                    s32 x = 0;
                    s32 y = 0;
                    s32 z = 0;
                    s32 se;
                    if (t != NULL) {
                        VecFx32 tp;
                        s64 sq;
                        s32 dx;
                        s32 dz;
                        s32 h;
                        if (t->unk_44 != NULL) {
                            tp = t->unk_44->pos;
                        } else {
                            tp.x = t->pos.x;
                            tp.y = t->pos.y + t->centerY;
                            tp.z = t->pos.z;
                        }
                        dx = self->pos.x - tp.x;
                        dz = self->pos.z - tp.z;
                        sq = (s64)dx * dx;
                        sq += (s64)dz * dz;
                        SQRTCNT_021a6280 = 1;
                        SQRT_PARAM_021a6280 = (u64)(sq * 4);
                        while (SQRTCNT_021a6280 & 0x8000) {
                        }
                        x = (s32)(SQRT_RESULT_021a6280 + 1) >> 1;
                        h = self->pos.y + self->height;
                        if (self->unk_b22_3) {
                            h += 0x333;
                        }
                        y = tp.y - h;
                    } else if (!(self->hit->unk_50 & 0x20000000) &&
                               self->pos.y - self->hit->check.y >= 0x159a) {
                        x = 0x2000;
                        y = -0x2000;
                    } else if (self->unk_b24_22 != 0 || self->unk_b24_26) {
                        x = 0x1800;
                        y = -0xc00;
                    }
                    if (self->unk_b24_12 != 0) {
                        z = self->speed;
                        s2->unk_18_2 = 1;
                    }
                    s2->unk_50 = x;
                    s2->unk_54 = y;
                    s2->unk_58 = z;
                    s2->unk_18_0 = 0;
                    if (self->unk_b24_22 != 0) {
                        u8 lv = 0;
                        u8 n;
                        if (self->unk_ba4 != NULL && self->unk_ba4->unk_06_3) {
                            lv = self->unk_b2c_7 << 1;
                        }
                        s2->unk_19 = self->unk_b24_22;
                        s2->unk_1b = lv;
                        n = Ov003_GetMaxCombo();
                        if (self->unk_b24_22 < 2) {
                            n--;
                        }
                        se = s2->unk_1a >= n ? 0x307 : 0x306;
                    } else {
                        se = self->unk_b24_26 ? 0x30d : 0x305;
                    }
                    if (se >= 0) {
                        SndMgr_PlayVolume(gSndMgr, se, -1, -1, -1);
                    }
                    if (self->unk_b24_22 != 0 || self->unk_b24_26) {
                        if (FieldId_Eq(&gSceneCmd->unk_ca, data_ov000_021c9fe8.rgb)) {
                            SndMgr_PlayPan(gSndMgr, 0x5e, Rand_UpTo(3));
                        }
                    }
                }
            }
            self->unk_b24_5 = 0;
            self->unk_b1c = 0xffff;
            self->unk_b1e = 0xffff;
            self->unk_b24_7 = self->unk_b24_9;
            self->target = 0xffff;
            if (self->unk_93_4) {
                Model0218fe1c_SetAnimSpeed(self->model, 0x1400);
            }
            self->gravity = 0x29;
            self->unk_b2c_3_f = 0;
            self->fsm->st++;
        }
    case 2:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc5e3, 0x200, 0);
            self->fsm->st++;
            self->fsm->timer = 0;
            self->friction = 0x800;
        }
        break;
    case 3: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 6) {
            self->gravity = 0x52;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    }
end:
    if (!Model0218fe1c_IsAnimDelayed(self->model)) {
        Robo021ca458_Move(self, FALSE, 0);
        if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
            self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
            self->speed = 0x66;
            self->friction = 0;
            if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
                self->velY = 0x200;
            }
            self->gravity = 0x52;
            self->unk_b24_17 = 1;
        }
    }
    if (self->unk_b24_22 >= 2 || self->unk_b24_26) {
        if (a != NULL) {
            d = a->pos;
            d.x -= self->pos.x;
            d.y -= self->pos.y;
            d.z -= self->pos.z;
            d.x = FxMul_021a6280(d.x, 0x733);
            d.y = FxMul_021a6280(d.y, 0x733);
            d.z = FxMul_021a6280(d.z, 0x733);
            d.y = self->height;
            VEC_Add(&d, (VecFx32 *)((u8 *)self + 0x70), &o);
            func_ov000_021899d8(&o, 0, 0x8ccd, 1, 0x2333, 0x1000);
        }
    }
}

}
