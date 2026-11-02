#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern char data_ov014_02217d3a[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern char data_ov014_02217d4c[];
extern u8 data_ov014_02216dc0[];
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void func_ov000_02191618(Model0218fe1c *a);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, void *pos, void *rot, u16 a);

static inline void Ov014_TimerTick(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void Ov014Act_0221267c_StateIdle(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        self->fsm->timer = 60;
        break;
    case 1:
        Actor_TurnToActor(self, func_ov000_0219bf90(), 0x400);
        s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            s->st++;
            self->fsm->timer = 30;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 2:
        if (ActorSub40_Timer(s) == 0) {
            s->st--;
            self->fsm->timer = 60;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    }
}

void Ov014Act_0221267c_StateAttack(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 10;
        self->fsm->timer = 20;
        break;
    case 10:
        Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
        s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            func_02065f88(0x5e2, (VecFx32 *)((u8 *)self + 0x33c))->SetScaleXYZ(0x2000, 0x2000, 0x2000);
            self->fsm->st++;
            self->fsm->timer = 60;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 11:
        if (ActorSub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0x19a, 0);
            func_ov000_02191618(self->model);
            self->fsm->st++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 12:
        if (self->model->anim_state == 1) {
            Ov014SpawnDesc desc;
            Ov003Actor *o;
            Ov014Spawn_Init(&desc, 0x483a);
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0x33c, &self->rot_x, 0xffff);
            o->unk_60 = data_ov014_02216dc0;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->fsm->st = 20;
            self->fsm->timer = 120;
        }
        break;
    case 20:
        if (ActorSub40_Timer(s) == 0) {
            s->st = 0xffff;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    default:
        s->st = 0xffff;
        break;
    }
}


extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

void Ov014Act_0221267c_StateAttack2(Ov014Act_0221267c *self) {
    ActorSub40 *s = self->fsm;
    switch (ActorSub40_State(s)) {
    case 0: {
        s32 base;
        u16 ang;
        func_ov000_02190cb0(self->model, data_ov014_02217d3a, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 10;
        self->fsm->timer = 0x14;
        base = self->unk_354 != 0 ? 0x1fff : -0x1fff;
        ang = FX_Atan2(self->unk_84.x - self->pos.x, self->unk_84.z - self->pos.z);
        self->unk_34c = base + ang;
        self->unk_350 = (-base * 2) / 100;
        break;
    }
    case 10:
        self->rot_y = func_01ffc128(self->unk_34c, self->rot_y, 0x400, 1, 0x8000);
        s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            func_02065f88(0x5dd, (VecFx32 *)((u8 *)self + 0x33c))->SetScaleXYZ(0x2000, 0x2000, 0x2000);
            self->fsm->st++;
            self->fsm->timer = 0x3c;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 11:
        if (ActorSub40_Timer(s) == 0) {
            func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0x19a, 0);
            func_ov000_02191618(self->model);
            self->fsm->st++;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    case 12:
        if (self->model->anim_state == 1) {
            Ov014SpawnDesc desc;
            Ov003Actor *o;
            Ov014Spawn_Init(&desc, 0x483a);
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, (u8 *)self + 0x33c, &self->rot_x, 0xffff);
            o->unk_60 = data_ov014_02216dc0;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->unk_312--;
            self->fsm->st++;
            self->fsm->timer = 0x78;
        }
        break;
    case 13:
        if (ActorSub40_Timer(s) == 0) {
            s->st = 0x14;
        } else {
            Ov003Actor *a;
            u16 id;
            self->unk_34c += self->unk_350;
            self->rot_y = self->unk_34c;
            id = self->target_id;
            if (data_ov000_021ccd68 == NULL) {
                a = NULL;
            } else {
                a = ActorMgr_GetActor(data_ov000_021ccd68, id);
            }
            if (a != NULL) {
                a->pos = self->unk_314.trans;
                a->rot_y = self->unk_34c;
            }
            Ov014_TimerTick(self->fsm);
        }
        break;
    case 20:
        s->st = 0xffff;
        break;
    default:
        s->st = 0xffff;
        break;
    }
}

}
