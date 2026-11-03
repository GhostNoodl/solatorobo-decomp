#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);

void Ov009ActVt_02216a00_StateDie(Ov009ActVt_02216a00 *self) {
    if (self->fsm->st == 0) {
        ActorMgr_BroadcastKind(gActorMgr, 0x5401, 0x15);
        ActorMgr_BroadcastKind(gActorMgr, 0x541f, 0x15);
        self->unk_ea_10 = 1;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_02216954_Start(Ov003Actor *self) {
    Ov003Actor *a;
    Ov003Actor_Start(self);
    if (self->unk_1a == 0) {
        return;
    }
    if (gActorMgr == NULL) {
        a = NULL;
    } else {
        a = ActorMgr_FindKind(gActorMgr, 0x1000, 0x1001);
    }
    if (a != NULL) {
        self->target = a->id;
    }
    self->unk_c8 = 0x50000;
}

extern char data_ov009_02216ab0[];
extern void Shared_SetEventActor(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void Ov009ActVt_022164a0_State20(Ov009ActVt_022164a0 *self) {
    ActorSub40 *st = self->fsm;
    ActorSub44 *s44;
    switch (st->st) {
    case 0:
        if (self->unk_1a != 0) {
            History_SetState(st, 1, 0);
            return;
        }
        self->pos.y += 0x5000;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->velY = -0x19a;
        self->gravity = 0x52;
        SndMgr_PlayAt(gSndMgr, 0x63, &self->pos, 0);
        self->fsm->st++;
    case 1:
        Actor_Move(self, 0);
        Body_Update(self->hit, 0, 0, 0);
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab0, 0x200, 0);
        Effect_SpawnId(0x12e, &self->pos)->SetScaleAll(0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->fsm->st++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x2d) {
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(4);
            gSceneCmd->stageFlags = 1;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern void Vec_RotateY(VecFx32 *out, VecFx32 *a, u16 b);
static inline Ov003Actor *Ov009_FindActor5(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov009ActVt_022164a0_StateAttack2(Ov009ActVt_022164a0 *self) {
    Ov003Actor *t = Ov009_FindActor5(self->target);
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab0, 0x200, 0);
        {
            Model0218fe1c *m = self->model;
            m->evScript = NULL;
            m->evCursor = NULL;
        }
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        switch (self->kind) {
        case 0x5032:
            self->unk_f0 = 0xb4;
            break;
        case 0x5402:
            self->unk_f0 = 100;
            break;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x28) {
            self->velY = 0x400;
            self->gravity = 0x29;
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 2: {
        u16 a;
        ActorGroup *g;
        Actor_Move(self, 0);
        Body_Update(self->hit, 0, 0, 0);
        if (self->velY < 0) {
            self->gravity = 0x52;
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov009_02216ab0, 0x800, 1);
        if (t != NULL) {
            Hit_ApplyInArea(self, self, self->unk_f0, 0x20, (u16)(1 << (t->id >> 12)), NULL, 0, 0x3400, 0x2800, 0x64, 0x1000);
        }
        Effect_SpawnId(0x66, &self->pos)->SetScaleAll(0x1c00);
        g = ActorMgr_GetGroup(gActorMgr, 0x5000);
        if (g != NULL && g->count <= 3) {
            do {
                Actor *o = Ov003Actor_SpawnAtSelf(self, 0x5404, 4);
                if (o != NULL) {
                    VecFx32 v;
                    v.z = self->radius;
                    v.x = 0;
                    v.y = 0x2000;
                    a = self->rot_y + 0xe800 + Rand_UpTo(0x3000);
                    Vec_RotateY(&v, &v, a);
                    VEC_Add(&v, &self->pos, &v);
                    o->pos.x = v.x;
                    o->pos.y = v.y;
                    o->pos.z = v.z;
                    o->speed = Rand_UpTo(0x80) + 0x19a;
                    o->velY = 0x333;
                    o->friction = 0;
                    o->gravity = 0x52;
                    o->moveYaw = a;
                }
            } while (g->count <= 3);
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 3:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            History_SetState(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
}

}
