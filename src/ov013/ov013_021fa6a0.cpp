#include "ov013/ov013.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern char data_ov013_0220ae4e[];
extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_020621c4(void);
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov013Msg *msg);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(ActorGroup *group, u16 kind);
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(ActorSub40 *a, u8 b, s32 c, BOOL d);
s32 Ov013Boss_ChooseAttack(Ov013Boss *self);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);

void Ov013Boss_Start(Ov013Boss *self) {
    ActorSub48 *m;
    ActorSub44 *n;
    Ov003Actor *p;
    Ov003Actor_Start(self);
    self->hit->unk_30 = 0;
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    Ov013_VecSet(&self->hit->offset, 0, 0x2000, 0);
    Ov013_VecSet(&self->unk_44->unk_0c, 0, 0x2000, 0);
    self->unk_93_4 = 1;
    self->target = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->target = p->id;
    }
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = -0x14000;
    self->unk_3c->unk_14 = self->radius << 1;
    self->unk_f1 = 0;
    self->unk_f0 = 0;
    self->side = 0;
    self->unk_f4 = 0x1000;
    self->unk_f8 = 0;
    self->unk_b6 = 0x3c;
    if (func_020621c4()) {
        Ov003Actor_ScaleStats(self, data_ov013_0220ae4e);
        self->unk_f4 = 0x1800;
    }
}

void Ov013Boss_Update(Ov013Boss *self) {
    Ov003Actor *p;
    s32 n;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->target = p->id;
    }
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    n = Ov013Boss_ChooseAttack(self);
    self->fsm->flags |= 1ull << n;
    self->unk_b6 = 0x96;
    if (n == 0x10) {
        self->unk_b6 = 0xb4;
    }
}

void Ov013Boss_HandleMsg(Ov013Boss *self, Ov013Msg *msg) {
    if (msg->type == 9) {
        func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x40, &self->pos, 0);
    }
    Ov003Actor_HandleMsg(self, msg);
}

void Ov013Boss_State20(Ov013Boss *self) {
    ActorSub40 *s = self->fsm;
    ActorSub44 *n;
    switch (s->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->model->alpha = 0;
        self->rot_y = 0;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    case 0x14: {
        u8 a = self->model->alpha;
        if (a < 0x1f) {
            s->timer++;
            if (s->timer % 6 == 0) {
                self->model->alpha = a + 1;
            }
        } else {
            s->st = 0x63;
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        break;
    }
    case 0x63:
        s->timer++;
        if (s->timer > 0x14) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov013Boss_StateIdle(Ov013Boss *self) {
    Ov003Actor *t;
    if (self->fsm->st == 0) {
        ActorSub44 *n;
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->fsm->st = 0x63;
        self->fsm->timer = 0;
    }
    t = Actor_GetTarget(self);
    if (t != NULL) {
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
    }
}


extern char data_ov013_0220b5be[];
extern char data_ov013_0220b5c4[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern VecFx32 Ov003Vec_DirXZ(const VecFx32 *a, const VecFx32 *b);
extern void Actor_TurnToPos(Ov003Actor *self, VecFx32 *p, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

void Ov013Boss_StateAttack(Ov013Boss *self) {
    VecFx32 v;
    v.x = self->unk_b8.x;
    v.y = self->unk_b8.y;
    v.z = self->unk_b8.z;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220b5be, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->velY = 0xa4;
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y = 0x1333;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->fsm->st = 1;
        self->fsm->timer = 0;
        break;
    case 1:
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &v) == 0) {
            func_ov000_02190cb0(self->model, data_ov013_0220b5c4, 0x2ab, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st = 2;
            self->fsm->timer = 0;
            break;
        }
        if (self->pos.x == v.x && self->pos.z == v.z) {
            self->pos.y += self->velY;
            if (self->pos.y > v.y) {
                self->pos.y = v.y;
            }
        }
        break;
    case 2: {
        Ov003Actor *t;
        s32 r;
        if (self->model->anim_state == 0) {
            break;
        }
        t = Ov013_FindActor(self->target);
        if (t == NULL) {
            break;
        }
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        v.y = 0x99a;
        VecFx32 d = Ov003Vec_DirXZ(&v, &self->pos);
        VEC_MultAdd(0x7800, &d, &v, &v);
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        self->speed = 0x600;
        r = FX_Div(Ov013_DistXZ(&self->pos, &v), self->speed);
        self->velY = -FX_Div(self->pos.y - v.y, r);
        self->fsm->st = 0x14;
        break;
    }
    case 0x14:
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&self->pos, &v) == 0) {
            self->velY = 0;
            self->fsm->st = 0x15;
            self->fsm->timer = 0;
            break;
        }
        if (self->pos.x == v.x && self->pos.z == v.z) {
            self->pos.y += self->velY;
            if (self->pos.y < v.y) {
                self->pos.y = v.y;
            }
            break;
        }
        if (Hit_DiffInSphere(&self->pos, &v, 0x333)) {
            self->pos.x = v.x;
            self->pos.y = v.y;
            self->pos.z = v.z;
        }
        break;
    case 0x15:
        Actor_Move(self, 0);
        if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x16;
            self->fsm->timer = 0;
        }
        break;
    case 0x16:
        Actor_Move(self, 0);
        self->speed = FX_Mul(self->speed, 0xf33);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer <= 0x1e) {
                break;
            }
        }
        func_ov000_02190cb0(self->model, data_ov013_0220b5be, 0x400, 0);
        func_ov000_021915a0(self->model);
        self->velY = 0x333;
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x17;
        self->fsm->timer = 0;
        break;
    case 0x17:
        Actor_Move(self, 0);
        if (self->pos.y > 0x3000) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->pos.y <= 0x8000) {
            break;
        }
        self->pos.y = 0x8000;
        v.y = 0x8000;
        v.x = 0;
        v.z = -0x14000;
        self->unk_b8.x = v.x;
        self->unk_b8.y = v.y;
        self->unk_b8.z = v.z;
        Actor_TurnToPos(self, &v, 0x1000);
        self->speed = 0x4cd;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x62;
        self->fsm->timer = 0;
        break;
    case 0x62:
        Actor_MoveToPos(self, &v, 0);
        if (VEC_Distance(&v, &self->pos) != 0) {
            break;
        }
        self->velY = -0x19a;
        self->rot_y = 0;
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x63;
        self->fsm->timer = 0;
        break;
    case 0x63:
        if (self->pos.y > 0) {
            ActorSub44 *n;
            Actor_Move(self, 0);
            if (self->pos.y >= 0x3000) {
                break;
            }
            n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
            break;
        }
        self->pos.y = 0;
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x64;
        self->fsm->timer = 0;
        break;
    case 0x64: {
        ActorSub40 *q = self->fsm;
        q->timer++;
        if (q->timer <= 0x14) {
            break;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        break;
    }
    }
}
}
