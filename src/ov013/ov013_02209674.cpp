#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be82[];
extern void HitSphere_Link(ActorSub48 *p);
extern s16 *func_ov000_02191318(Model0218fe1c *a, s32 b);
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Ov013_Land(Ov013Act_02207968 *self) {
    func_ov000_02190cb0(self->model, data_ov013_0220be82, 0x155, 0);
    func_ov000_02191318(self->model, 0x96000);
    func_0204a028(data_02097e4c, 0x39, &self->pos, 2);
    self->unk_f0 = 2;
    func_ov000_02198360(self->fsm, 1, 0);
    self->fsm->st = 7;
}

void func_ov013_02209674(Ov013Act_02207968 *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    if (self->fsm->st == 0) {
        self->unk_110 = 0;
    }
    func_ov003_021d36fc(self);
    if (self->fsm->current != 10) {
        return;
    }
    self->targetObj->target = 0xffff;
    m = self->hit;
    m->unk_9a_0 = 1;
    m->unk_9a_3 = 1;
    HitSphere_Link(m);
    n = self->unk_44;
    n->unk_22_0 = 1;
    n->unk_22_1 = 1;
    Ov013_Land(self);
}

void func_ov013_0220976c(Ov013Act_02207968 *self) {
    Ov003Actor *t;
    func_ov003_021d3d28(self);
    if (self->fsm->current != 1) {
        return;
    }
    t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, 0x1000);
    Ov013_Land(self);
}

void func_ov013_02209830(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->fsm->current != 1) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_02209908(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        if (self->pos.y < 0x4800) {
            self->pos.y = 0x4800;
        }
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
    if (self->pos.y < 0x4800) {
        self->pos.y = 0x4800;
    }
    if (self->fsm->current != 1) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_022099e0(Ov013Act_02207968 *self) {
    ActorSub48 *m;
    if (self->fsm->st == 0) {
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        self->rot_x = 0;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d5900(self);
    if (self->fsm->current == 0x14) {
        return;
    }
    Ov013_Land(self);
}

void func_ov013_02209aac(Ov013Act_02207968 *self) {
    if (self->fsm->st == 0) {
        EffectObj *fx;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4811, 10);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4813, 10);
        fx = func_02065f88(0x69, &self->pos);
        if (fx != NULL) {
            fx->SetScaleAll(0x3000);
            fx->AddPosXYZ(0, self->centerY, 0);
        }
    }
    func_ov003_021d6054(self);
}

}
