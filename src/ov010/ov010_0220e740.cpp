#include "ov010/ov010.h"

// Ov010Path is in ov010.h.

extern "C" {

extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *c);
extern void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

BOOL func_ov010_0220e740(Ov010Path *self, Actor *owner, const void *msg, s32 size, const VecFx32 *offset, s32 fxId) {
    self->b0 = 1;
    self->b1 = 0;
    self->owner = owner;
    self->timer = 0;
    self->duration = 0;
    self->fxHandle = 0;
    self->fxId = fxId;
    self->unk_10 = 0x1000;
    self->offset = *offset;
    MI_CpuCopy8(msg, self->msg, size);
    func_ov003_021da48c(&self->sm, 1);
    return TRUE;
}

static inline u16 Ov010_SubClamp(u16 a, s32 b) {
    s32 d = a - b;
    u16 r;
    if (d < 0) {
        r = 0;
    } else {
        r = d;
    }
    return r;
}

void func_ov010_0220e7c8(Ov010Path *self) {
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        return;
    }
    self->timer++;
    switch (self->sm.current) {
    case 0:
    case 1:
        break;
    case 2: {
        u16 lim = Ov010_SubClamp(self->duration, 80);
        if (self->timer < lim) {
            return;
        }
        func_ov000_02198360(&self->sm, 3, 0);
        break;
    }
    case 3:
        if (self->sm.st == 0) {
            VecFx32 p;
            EffectObj *e;
            p.x = self->owner->pos.x;
            p.y = self->owner->pos.y;
            p.z = self->owner->pos.z;
            e = func_02065f88(0x322, &p);
            e->SetScaleAll(0xf00);
            e->AddPos(&self->offset);
            e->loopCount = -1;
            func_ov003_021da904(e, self->owner, &self->offset);
            self->fxHandle = e->id;
            self->sm.st++;
        } else {
            u16 lim = Ov010_SubClamp(self->duration, 40);
            if (self->timer < lim) {
                return;
            }
            EffectMgr_StopLoop(data_0214a420, self->fxHandle);
            self->fxHandle = 0;
            func_ov000_02198360(&self->sm, 4, 0);
        }
        break;
    case 4: {
        EffectObj *fx;
        if (self->sm.st == 0) {
            VecFx32 p;
            EffectObj *e;
            p.x = self->owner->pos.x;
            p.y = self->owner->pos.y;
            p.z = self->owner->pos.z;
            e = func_ov003_021da8e4(self->fxId, &p, 0xe66);
            e->SetScaleAll(self->scale);
            e->AddPos(&self->offset);
            e->speed = self->unk_10;
            self->fxHandle = e->id;
            self->sm.st++;
        }
        fx = func_020657b0(data_0214a420, self->fxHandle);
        if (fx != NULL) {
            VecFx32 q;
            q.x = self->owner->pos.x;
            q.y = self->owner->pos.y;
            q.z = self->owner->pos.z;
            VEC_Add(&q, &self->offset, &q);
            fx->SetPos(&q);
        }
        if (self->timer < self->duration) {
            return;
        }
        ActorMgr_SendMsg(self->owner->id, 0xffff, 0xe, 1, 0x30, self->msg);
        func_ov000_02198360(&self->sm, 1, 0);
        break;
    }
    }
}
}
