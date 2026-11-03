#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021aef50;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
} B190_021aef50;

typedef struct {
    u16 x, y, z;
} Rot_021aef50;

#define REG_SQRTCNT_021aef50 (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT_021aef50 (*(volatile u32 *)0x40002b4)
/* written without volatile: the target computes both halves before storing */
#define REG_SQRT_PARAM_021aef50 (*(u64 *)0x40002b8)

extern "C" {

extern void *data_02097e4c;
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc630[];
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
BOOL History_SetState(St_021aef50 *st, s32 state, s32 x);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Actor_TurnToPos(Actor *self, void *v, s32 a);
void Actor_MoveToPos(Actor *self, const void *target, s32 turn);
void Actor_Move(Actor *self, s32 turn);
s32 Geom_SnapToGround(void *pos, s32 up, s32 down);
void *SndMgr_PlayAt(void *mgr, s32 id, void *pos, s32 a);
void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline Actor *FindActor021aef50(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Dist021aef50(s32 dx, s32 dz) {
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    REG_SQRTCNT_021aef50 = 1;
    REG_SQRT_PARAM_021aef50 = (u64)(sq << 2);
    while (REG_SQRTCNT_021aef50 & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT_021aef50 + 1) >> 1;
}

void Robo021ca458_State1d(Robo021ca458 *self) {
    u16 id;
    Actor *a;
    u8 *info;
    VecFx32 pos;
    id = self->unk_b20;
    if (id == 0xffff) {
        id = self->target;
    }
    a = FindActor021aef50(id);
    info = NULL;
    if (a != NULL) {
        info = ((u8 *)a->targetObj);
        pos = a->pos;
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    switch (((St_021aef50 *)self->fsm)->state) {
    case 0:
        if (info != NULL) {
            u8 k = info[2];
            if (k == 9) {
                self->unk_b24_12 = 1;
                data_ov000_021ccd54->cam.base.flags |= 0x20;
            } else if (k == 10) {
                self->unk_b24_12 = 2;
            } else if (k == 11) {
                self->unk_b24_12 = 3;
            }
        } else {
            self->unk_b24_12 = 0;
            History_SetState(((St_021aef50 *)self->fsm), 1, 0);
            return;
        }
        self->unk_b20 = self->target;
        self->target = 0xffff;
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 0);
        {
            s32 d = Dist021aef50(pos.x - self->pos.x, pos.z - self->pos.z);
            self->speed = d >> 4;
            self->velY = 0x53f;
            self->friction = 0;
            self->gravity = 0x52;
        }
        SndMgr_PlayAt(data_02097e4c, 7, &self->pos, 0);
        ((St_021aef50 *)self->fsm)->state++;
        break;
    case 1:
        if (a == NULL) {
            self->unk_b24_12 = 0;
            History_SetState(((St_021aef50 *)self->fsm), 4, 0);
        }
        Actor_TurnToPos(self, &pos, 0x59a);
        Actor_MoveToPos(self, &pos, 0);
        {
            St_021aef50 *st = ((St_021aef50 *)self->fsm);
            st->timer++;
            if (st->timer < 0x10) {
                break;
            }
        }
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc630, 0x400, 0);
        ((St_021aef50 *)self->fsm)->timer = 0;
        ((St_021aef50 *)self->fsm)->state++;
        if (self->unk_b24_12 == 1) {
            EffectObj *e = Effect_SpawnId(0x6d, &pos);
            e->SetScaleAll(0xb33);
            e->SetRotXYZ(0xf000, 0, 0);
        } else if (self->unk_b24_12 == 3) {
            SndMgr_PlayAtPitch(data_02097e4c, 0xe, &self->pos, -5);
        }
        break;
    case 2: {
        St_021aef50 *st = ((St_021aef50 *)self->fsm);
        st->timer++;
        if (st->timer >= 10) {
            if (a != NULL) {
                self->pos = pos;
                {
                    u16 ry = a->rot_y;
                    u16 rz = a->rot_z;
                    u16 rx = a->rot_x;
                    self->rot_x = rx;
                    self->rot_y = ry;
                    self->rot_z = rz;
                    self->moveYaw = ry;
                }
            }
            History_SetState(((St_021aef50 *)self->fsm), 1, 0);
        } else {
            VecFx32 d;
            self->rot_y = Angle_Approach(a->rot_y, self->rot_y, 0x800, 1, 0x8000);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            d.x = pos.x - self->pos.x;
            d.y = pos.y - self->pos.y;
            d.z = pos.z - self->pos.z;
            VEC_MultAdd(0x800, &d, &self->pos, &self->pos);
        }
        break;
    }
    case 100:
        self->unk_b20 = 0xffff;
        self->unk_b24_12 = 0;
        self->rot_x = 0;
        SndMgr_PlayAt(data_02097e4c, 7, &self->pos, 0);
        ((St_021aef50 *)self->fsm)->state++;
    case 101:
        self->unk_b29 |= 2;
        Actor_Move(self, 0);
        if (self->velY >= 0) {
            break;
        }
        if (Geom_SnapToGround(&self->pos, self->height << 1, -0x66) == -0x1000) {
            break;
        }
        data_ov000_021ccd54->cam.base.groundClip = 0;
        History_SetState(((St_021aef50 *)self->fsm), 4, 0);
        break;
    }
}

}
