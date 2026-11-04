#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Actor.h"
#include "Main/Res/StageFlags.h"

extern "C" {
extern char data_ov000_021cc5e9[];
extern char data_ov000_021cc6c0[];
extern char data_ov000_021cc636[];
extern void *gSndMgr;
void Shared_ChangeFlags(s32 a, s32 b);
u16 Hit_FindOpenDir(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
BOOL History_SetState(void *p, s32 a, s32 b);

static inline void SetRgb021ac080(StageFlags *g, u8 r, u8 gr, u8 b) {
    g->color.r = r;
    g->color.g = gr;
    g->color.b = b;
}

static inline BOOL GBusy021ac080(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle021ac080(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        if (GBusy021ac080(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void Robo021ca458_State1b(Robo021ca458 *self) {
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0:
        self->unk_b24_2 = 2;
        self->unk_b24_1 = 0;
        self->target = 0xffff;
        self->fieldId = gSceneCmd->unk_ca;
        gStageFlags->bits18.flag8 = 1;
        gStageFlags->target = self->unk_75c;
        gStageFlags->targetRotY = self->unk_76e;
        SetRgb021ac080(gStageFlags, self->unk_772, self->unk_773, self->unk_774);
        Shared_ChangeFlags(3, 2);
        gSceneCmd->stageFlags = 1;
        self->pos.y += 0x119a;
        Model0218fe1c_SetAnim(&self->mdl1, data_ov000_021cc5e9, 0x155, 0);
        Model0218fe1c_SetAnim(&self->mdl0, data_ov000_021cc6c0, 0x400, 0);
        self->mdl0.unk_cc = 0x320;
        self->fsm->st++;
        break;
    case 1: {
        VecFx32 v;
        self->speed = 0x133;
        self->velY = 0x2cd;
        self->gravity = 0x52;
        self->friction = 0;
        v = self->pos;
        v.y += self->centerY - 0x119a;
        self->moveYaw = Hit_FindOpenDir(&v, 0x2000, self->rot_y, 4, 0, 0xffffffff);
        SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 2: {
        s32 d;
        u16 t;
        u16 *s;
        self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x400, 1, 0x8000);
        Robo021ca458_Move(self, FALSE, 1);
        d = self->pos.y - self->unk_75c.y;
        if (d < 0x1800) {
            self->pos.y += (self->unk_75c.y + 0x1800 - self->pos.y) >> 2;
        } else if (d > 0x1ccd) {
            self->pos.y += (self->unk_75c.y + 0x1ccd - self->pos.y) >> 2;
        }
        s = (u16 *)self->fsm;
        s[1]++;
        t = s[1];
        if (t == 10) {
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc636, 0x2ab, 0);
        }
        if (t < 0x16 && GIdle021ac080() && self->mode != 3) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc636, 0x2ab, 0);
        self->unk_b24_2 = 0;
        History_SetState(self->fsm, 4, 0);
        break;
    }
    }
}
}

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 z;
} Msg021ac3ec;

extern "C" {
extern void *gSndMgr;
extern char data_ov000_021cc6c6[];
extern char data_ov000_021cc6cc[];
void Model0218fe1c_StopAnim(void *p);
void SndMgr_StopSeqArc(void *mgr, s32 id);
void Field_ShakeCamera(s32 a, s32 b);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Actor_SendMsgU8(void *o, u16 id, s32 c);
Actor *Target_GetActor(void *p);
void func_ov000_02199f88(void *t, void *self);
void Model0218fe1c_SetAnimDelay(void *a, s32 b, s32 c);
BOOL Model0218fe1c_IsAnimDone(void *a);
BOOL Model0218fe1c_IsAnimDelayed(void *m);
void Robo021ca458_Move(Robo021ca458 *self, BOOL a, s32 b);
BOOL History_SetState(void *s, s32 a, s32 b);
u16 FX_Atan2(s32 x, s32 z);

static inline Actor *GetObj021ac3ec(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline void Reset021ac3ec(Robo021ca458 *self) {
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
}

void Robo021ca458_State12(Robo021ca458 *self) {
    BOOL go;
    switch (self->fsm->st) {
    case 0: {
        Actor *o;
        char *anm = data_ov000_021cc6c6;
        if (self->unk_93_5 != 0) {
            anm = data_ov000_021cc6cc;
        }
        Model0218fe1c_SetAnim(self->model, anm, 0x800, 1);
        if (self->unk_b22_0 != 0) {
            if (self->unk_998 != NULL) {
                Model0218fe1c_StopAnim(self->unk_998);
            }
            if (self->seSlot >= 0) {
                SndMgr_StopSeqArc(gSndMgr, self->seSlot);
                self->seSlot = -1;
            }
            if (self->unk_b22_0 > 1) {
                self->unk_b22_0 = 1;
                self->rot_x = 0;
                self->rot_z = 0;
                self->unk_9a6 = 0;
                self->unk_9a8 = 0;
                self->unk_9aa = 0;
                self->unk_9a0 = 0;
                self->unk_9a2 = 0;
                self->unk_9a4 = 0;
            }
        }
        self->hpObj->unk_0a = 0x5a;
        Field_ShakeCamera(6, 10);
        o = GetObj021ac3ec(self->unk_b1c);
        if (o != NULL) {
            Msg021ac3ec m;
            m.pos = self->pos;
            m.pos.y += self->centerY;
            m.rot[0] = o->rot_x;
            m.rot[1] = o->rot_y;
            m.rot[2] = o->rot_z;
            m.z = 0;
            Actor_SendMsg(o, self->id, 7, 1, 0x18, &m);
            Actor_SendMsgU8(o, self->id, 10);
            if (o->targetObj != NULL) {
                o->targetObj->unk_18_0 = 0;
            }
        }
        Reset021ac3ec(self);
        self->target = 0xffff;
        self->unk_b24_21 = 0;
        if (self->unk_93_5 == 0) {
            self->unk_b36 = 0;
        } else if (self->unk_93_5 == 1) {
            self->unk_93_5 = 2;
        }
        {
            Actor *t = Target_GetActor(((u8 *)self->hp));
            u16 ang;
            if (t == NULL || t == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
            }
            self->unk_96 = ang;
        }
        self->speed = 0;
        self->moveYaw = self->unk_96 + 0x8000;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        u8 f = self->unk_93_5;
        if (f != 0) {
            self->speed = 0x371;
            self->velY = 0;
            self->friction = 0xccd;
            self->gravity = 0x52;
            if (f == 2) {
                self->unk_93_5 = 1;
            }
        } else {
            func_ov000_02199f88(((u8 *)self->hp), self);
        }
        Model0218fe1c_SetAnimDelay(self->model, 5, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            if (self->unk_93_5 != 0) {
                History_SetState(self->fsm, 0x1c, 0);
            } else {
                History_SetState(self->fsm, 1, 0);
            }
        }
        if (!Model0218fe1c_IsAnimDelayed(self->model)) {
            Robo021ca458_Move(self, TRUE, 1);
            if (!self->unk_b24_1 && (self->hit->unk_50 & 0x400)) {
                History_SetState(self->fsm, 4, 0);
            }
        }
        break;
    }
    go = FALSE;
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
        go = TRUE;
    }
    if (go) {
        History_SetState(self->fsm, 4, 0);
    }
    self->rot_y = Angle_Approach(self->unk_96, self->rot_y, 0x8cd, 1, 0x8000);
}
}
