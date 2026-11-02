#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/FieldMgr.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021af464;

#define REG_SQRTCNT_021af464 (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT_021af464 (*(volatile u32 *)0x40002b4)
/* written without volatile: the target computes both halves before storing */
#define REG_SQRT_PARAM_021af464 (*(u64 *)0x40002b8)

extern "C" {

extern void *data_02097e4c;
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc71d[];
extern char data_ov000_021cc723[];
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
void Model0218fe1c_SetAnimDelay(void *a, u16 delay, BOOL force);
void Model0218fe1c_SetReverse(void *a);
void Model0218fe1c_ClearReverse(void *a);
BOOL History_SetState(St_021af464 *st, s32 state, s32 x);
void Body_Update(void *a, s32 b, s32 c, s32 d);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Actor_MoveToPos(Actor *self, const void *target, s32 turn);
void Actor_Move(Actor *self, s32 turn);
s32 func_ov000_021b288c(void *self);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
void HitSphere_Unlink_0203f364(void *obj);
void *SndMgr_PlayAt(void *mgr, s32 id, void *pos, s32 a);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline Actor *FindActor021af464(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Dist021af464(s32 dx, s32 dz) {
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    REG_SQRTCNT_021af464 = 1;
    REG_SQRT_PARAM_021af464 = (u64)(sq << 2);
    while (REG_SQRTCNT_021af464 & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT_021af464 + 1) >> 1;
}

static inline s32 FxMul021af464(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline BOOL GBusy021af464(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle021af464(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021af464(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL GHasD4_021af464(void) {
    return data_ov000_021ccd54->event != 0 ? TRUE : FALSE;
}

static inline BOOL Ev19_021af464(void) {
    LangBlockB *e = data_ov000_021ccd6c->blockB;
    if (e != NULL && e->unk_19_0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov000_021af464(Robo021ca458 *self) {
    Actor *a;
    ActorSub4c *info;
    VecFx32 pos;
    u16 ang;
    VecFx32 v;
    a = FindActor021af464(self->target);
    info = NULL;
    if (a != NULL) {
        info = (ActorSub4c *)((u8 *)a->targetObj);
        pos = a->pos;
        ang = a->rot_y;
        {
            u16 r = ang + 0x8000;
            pos.x += FxMul021af464(FX_SinCosTable_[(r >> 4) * 2], 0x800);
            pos.z += FxMul021af464(FX_SinCosTable_[(r >> 4) * 2 + 1], 0x800);
        }
        pos.y += 0x800;
    }
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    if (((St_021af464 *)self->fsm)->state < 10) {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        self->hit->unk_9a_4 = 0;
    }
    switch (((St_021af464 *)self->fsm)->state) {
    case 0:
        if (info != NULL) {
            u8 k = info->type;
            if (k == 9) {
                self->unk_b24_14 = 1;
            } else if (k == 10) {
                self->unk_b24_14 = 2;
            }
        } else {
            self->unk_b24_14 = 0;
            History_SetState(((St_021af464 *)self->fsm), 1, 0);
            break;
        }
        SndMgr_PlayAt(data_02097e4c, 7, &self->pos, 0);
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 0);
        self->speed = Dist021af464(pos.x - self->pos.x, pos.z - self->pos.z) >> 4;
        self->velY = ((pos.y - self->pos.y) >> 4) + 0x185;
        self->friction = 0;
        self->gravity = 0x52;
        self->unk_b24_27 = 0;
        ((St_021af464 *)self->fsm)->state++;
        break;
    case 1:
        self->rot_y = func_01ffc128(ang, self->rot_y, 0x400, 1, 0x8000);
        Actor_MoveToPos(self, &pos, 0);
        {
            St_021af464 *st = ((St_021af464 *)self->fsm);
            st->timer++;
            if (st->timer < 0x10) {
                break;
            }
        }
        Model0218fe1c_SetAnim(self->model,
                            self->unk_b24_14 == 1 ? data_ov000_021cc71d : data_ov000_021cc723,
                            0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1400);
        Model0218fe1c_SetAnimDelay(self->model, 10, 0);
        ((St_021af464 *)self->fsm)->timer = 0;
        ((St_021af464 *)self->fsm)->state++;
        break;
    case 2: {
        St_021af464 *st = ((St_021af464 *)self->fsm);
        st->timer++;
        if (st->timer >= 10) {
            self->pos = pos;
            self->rot_y = ang;
            self->moveYaw = ang;
            self->target = 0xffff;
            SndMgr_PlayAt(data_02097e4c, 1, &self->pos, 0);
            ((St_021af464 *)self->fsm)->state++;
        } else {
            VecFx32 d;
            self->rot_y = func_01ffc128(ang, self->rot_y, 0x8cd, 1, 0x8000);
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
    case 3: {
        s32 r = func_ov000_021b288c(self);
        if (r <= 0) {
            self->unk_b24_14 = 0;
            if (r == 0) {
                self->speed = 0x19a;
                self->velY = 0x2cd;
                self->gravity = 0x52;
            } else {
                self->speed = 0;
                self->velY = 0x185;
                self->gravity = 0x52;
            }
            self->friction = 0;
            self->unk_b29 |= 2;
            Model0218fe1c_SetAnim(self->model, data_ov000_021cc62a, 0x800, 0);
            SndMgr_PlayAt(data_02097e4c, 7, &self->pos, 0);
            ((St_021af464 *)self->fsm)->state = 10;
        } else if (self->velY == 0) {
            Model0218fe1c_SetAnimDelay(self->model, 1, 0);
        } else if (self->velY < 0) {
            Model0218fe1c_SetReverse(self->model);
        } else {
            Model0218fe1c_ClearReverse(self->model);
        }
        break;
    }
    case 10:
        self->unk_b29 |= 2;
        Actor_Move(self, 0);
        Body_Update(self->hit, 0, 0, 0);
        if (self->velY > 0) {
            break;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            break;
        }
        History_SetState(((St_021af464 *)self->fsm), 4, 0);
        break;
    }
    if (Ev19_021af464()) {
        return;
    }
    if (info != NULL && (info->unk_18_4 ? TRUE : FALSE)) {
        return;
    }
    if (self->unk_b24_27) {
        return;
    }
    if (!GIdle021af464() || GHasD4_021af464()) {
        self->unk_b24_27 = 1;
    }
    {
        v = self->pos;
        v.y += self->centerY;
        func_ov000_021899d8(&v, 0, 0x6ccd, 1, 0x1000, 0x1000);
    }
}

}
