#include "ov012/ov012.h"

extern "C" {
extern char data_ov012_0220b406[];
extern char data_ov012_0220b40c[];
extern char data_ov012_0220b412[];
extern char data_ov012_0220b418[];

static inline u16 Ov012_AngTo(Ov003Actor *self, Ov003Actor *t) {
    if (t == NULL || t == self) {
        return self->rot_y;
    }
    return FX_Atan2(t->pos.x - self->pos.x, t->pos.z - self->pos.z);
}

void Ov012ActVt_0220b35c_StateShoot(Ov003Actor *self) {
    Ov003Actor *o = Ov012_FindActor(self->unk_d0->target_id);
    Ov003Actor *pl = Actor_GetTarget(self);
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        self->speed = 0;
        self->unk_96 = self->rot_y;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_02049f44(data_02097e4c, 0x701, &self->pos, 0);
        if (self->unk_d0->target_id != 0xffff) {
            func_ov000_02190cb0(self->model, data_ov012_0220b40c, 0x400, 0);
            self->fsm->st = 10;
        } else {
            func_ov000_02190cb0(self->model, data_ov012_0220b412, 0x400, 0);
            self->fsm->st++;
        }
        break;
    case 1:
        if (self->model->anim_state == 1) {
            Actor *n = Ov003Actor_SpawnAtSelf(self, 0x4009, 9);
            if (n != NULL) {
                self->unk_d0->target_id = n->id;
            }
            self->fsm->st++;
        }
        Actor_TurnToActor(self, pl, 0x400);
        break;
    case 2:
        if (o != NULL && o->state != 2) {
            break;
        }
        if (!func_ov000_02191120(self->model)) {
            break;
        }
        func_ov000_02190cb0(self->model, data_ov012_0220b40c, 0x400, 0);
        self->fsm->st = 10;
        break;
    case 10:
        if (pl != NULL) {
            self->unk_96 = Ov012_AngTo(self, pl);
            self->rot_y = func_01ffc128(self->unk_96, self->rot_y, 0x59a, 1, 0x8000);
        }
        if (self->model->anim_state != 1) {
            break;
        }
        if (o != NULL) {
            func_ov000_0218d46c((StageObj3D *)o, self->id, 0xe);
        }
        self->fsm->st++;
        break;
    case 11:
        if (!func_ov000_02191120(self->model)) {
            break;
        }
        if (o != NULL && o->targetObj != NULL && o->targetObj->unk_1e == 0) {
            Ov003Actor *n = Ov012_FindActor(self->unk_d0->target_id);
            if (n != NULL) {
                func_ov000_0218d46c((StageObj3D *)n, self->id, 10);
                if (n->targetObj != NULL) {
                    n->targetObj->unk_18_0 = 0;
                }
                self->unk_d0->target_id = 0xffff;
            }
            func_02049f44(data_02097e4c, 0x700, &self->pos, 0);
        }
        func_ov000_02190cb0(self->model, data_ov012_0220b418, 0x19a, 0);
        func_ov000_021915a0(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 12:
        s->timer++;
        if (s->timer <= 0x3c) {
            break;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 13:
        s->timer++;
        if (s->timer > 0x3c) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        Actor_TurnToActor(self, pl, 0x400);
        break;
    }
}

void Ov012ActVt_0220b35c_State16(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov012_0220b406, 0x400, 0);
        self->speed = 0x59a;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_02049f44(data_02097e4c, 0x700, &self->pos, 0);
        self->fsm->st++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 0x2d || VEC_Distance(&self->pos, &self->unk_b8) < 0x1800) {
            self->friction = 0xc00;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        {
            VecFx32 v;
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            Actor_MoveToPos(self, &v, 0);
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > 0x3c) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        Actor_Move(self, 0);
        break;
    }
    Actor_TurnToActor(self, Actor_GetTarget(self), 0x400);
    func_ov000_021987b8(self->hit, 1, 0, 0);
}
}

extern "C" {
void Ov012ActVt_0220b35c_StateDown(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            ActorSub4c *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->targetObj;
            if (p != NULL) {
                p->unk_18_0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        if (*self->hp == 0) {
            func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
        }
    }
    Ov003Actor_StateDown(self);
}
}

extern "C" {
void Ov012ActVt_0220b35c_StateDie(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        EffectObj *e;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4009, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4801, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->SetScaleAll(0x2400);
            e->AddPosXYZ(0, self->centerY, 0);
        }
    }
    Ov003Actor_StateDie(self);
}
}

extern "C" {
void Ov012ActVt_0220b35c_StateHurt(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            ActorSub4c *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->targetObj;
            if (p != NULL) {
                p->unk_18_0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x703, &self->pos, 0);
    }
    Ov003Actor_StateHurt(self);
}
}

extern "C" {
void Ov012ActVt_0220b35c_StateKnockBack(Ov003Actor *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *o = Ov012_FindActor(self->unk_d0->target_id);
        if (o != NULL) {
            ActorSub4c *p;
            func_ov000_0218d46c((StageObj3D *)o, self->id, 10);
            p = o->targetObj;
            if (p != NULL) {
                p->unk_18_0 = 0;
            }
            self->unk_d0->target_id = 0xffff;
        }
        func_02049f44(data_02097e4c, 0x704, &self->pos, 0);
    }
    Ov003Actor_StateKnockBack(self);
}
}

extern "C" {
Ov003Actor *Ov012ActVt_0220b35c_Dtor(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    return self;
}
}

extern "C" {
Ov003Actor *Ov012ActVt_0220b35c_DtorDelete(Ov003Actor *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
}
