#include "types.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern const VecFx32 data_ov003_021f6bd8;
extern void *data_ov000_021ccd68;
extern Actor *Target_Get(ActorSub4c *t);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToPos(Actor *self, VecFx32 *v, s32 a);
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, u16 ry);
extern void HitSphere_Link(ActorSub48 *a);
extern void func_ov000_021987b8(ActorSub48 *a, s32 b, s32 c, s32 d);

#define HM_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define HM_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])
#define HM_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline Actor *Ov003Hm_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov003Hm_Show(ActorSub48 *a) {
    a->unk_9a_0 = 1;
    a->unk_9a_3 = 1;
    HitSphere_Link(a);
}

void func_ov003_021ed15c(Ov003HomingShot *self) {
    VecFx32 ofs = data_ov003_021f6bd8;
    Actor *t;
    s32 speed;
    if (Target_Get(self->targetObj)->kind == 0x1000) {
        if (self->fsm->st == 0) {
            self->hit->unk_30 = self->def->sphereFlags;
        }
        func_ov003_021db244(self);
        return;
    }
    t = Ov003Hm_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    speed = 0;
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        func_ov003_021dc0c8(self);
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        self->gravity = 0;
        speed = 0x333;
        e = func_02065f88(0x324, &self->pos);
        func_01ffc9fc(&self->fxOffset, &ofs, self->rot_y);
        e->SetScaleAll(0x2333);
        self->unk_bc = e->id;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub40 *w = self->fsm;
        speed = 0x333;
        w->timer++;
        if (w->timer > 0xf) {
            speed = 0x2e1;
            self->vel.y = 0x29;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 2: {
        ActorSub40 *w = self->fsm;
        VecFx32 p;
        u16 timer;
        s32 turn;
        speed = 0x2e1;
        w->timer++;
        timer = w->timer;
        p = t->pos;
        p.y += t->centerY;
        turn = 0x11f;
        if (timer > 0x14) {
            VecFx32 d;
            d.x = p.x - self->pos.x;
            d.y = p.y - self->pos.y;
            d.z = p.z - self->pos.z;
            VEC_Normalize(&d, &d);
            d.y = HM_MUL(d.y, speed);
            self->vel.y += HM_MUL(d.y - self->vel.y, 0x9a);
            turn = 0xe1;
        }
        Actor_TurnToPos(self, &p, turn);
        self->moveYaw = self->rot_y;
        if (timer > 0x64) {
            if (self->unk_1a == 0) {
                self->hit->unk_30 = 0xe0000000;
            }
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 3:
        speed = 0x333;
        if (self->hit != NULL && (self->hit->unk_50 & 0x60000000)) {
            self->age = 0x270f;
        }
        break;
    }
    self->vel.x = HM_MUL(speed, HM_SIN(self->moveYaw));
    self->vel.z = HM_MUL(speed, HM_COS(self->moveYaw));
    VEC_Add(&self->pos, &self->vel, &self->pos);
    self->trailTimer++;
    if (self->trailTimer > 0xf) {
        self->trailTimer = 0;
        func_02065f88(0x12d, &self->pos)->SetRot(&self->rot);
    }
    if (self->unk_bc != (u32)-1) { // the homing shot compares its effect id with -1
        func_01ffc9fc(&self->fxOffset, &ofs, self->rot_y);
    }
    if (self->hit != NULL) {
        if (!(self->param->type & 2)) {
            Ov003Hm_Show(self->hit);
        }
        func_ov000_021987b8(self->hit, 0, 0, 0);
    }
    func_ov003_021dbd80(self);
}

}
