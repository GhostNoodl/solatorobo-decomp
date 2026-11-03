#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u8 a;
    u16 b;
    u8 c;
} Msg021a3e50;

extern "C" {
extern u8 *data_ov000_021ccd30;
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc648[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void Actor_TurnToActor(Actor *self, void *other, s32 step);
BOOL Model0218fe1c_SetAnim(void *p, void *a, s32 b, s32 c);
void Model0218fe1c_SetLoop(void *p);
void Shared_SetEventActor(u16 a, u16 b);
BOOL MessageQueue_GetById(void *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
void *Task_FindById(s32 kind);
BOOL History_SetState(void *p, s32 a, s32 b);

static inline Actor *FindActor021a3e50(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline BOOL IsBusy021a3e50(void) {
    BOOL r;
    u8 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (MessageQueue_GetById(m, 6)) {
        r = TRUE;
    } else if (LFLD(void *, m, 0x11c) == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700c4(LFLD(void *, m, 0x11c));
    }
    return r;
}

void func_ov000_021a3e50(Robo021ca458 *self) {
    Actor *t;
    ActorSub40 *sub;
    self->hit->unk_9a |= 0x20;
    if (self->unk_b2f == 0) {
        self->unk_b2f++;
    }
    t = FindActor021a3e50(self->target);
    sub = self->fsm;
    switch (sub->st) {
    case 0:
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 1;
            m.b = 0x19a;
            m.c = 1;
            Actor_SendMsg(t, self->id, 5, TRUE, 6, &m);
            if (t->kind == 0x2003) {
                u16 v;
                self->fsm->st++;
                v = self->hpObj->max;
                Actor_SendMsg(self, self->id, 10, TRUE, 2, &v);
            } else {
                self->fsm->st = 10;
                if (self->unk_bac != self->target) {
                    StageFlags *g;
                    u32 n;
                    self->unk_bac = self->target;
                    g = data_0214a424;
                    n = g->unk_014 + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    g->unk_014 = n;
                }
            }
        }
        {
            u8 *anim = data_ov000_021cc5e3;
            if (!self->unk_b24_1) {
                anim = data_ov000_021cc648;
            }
            Model0218fe1c_SetAnim(self->model, anim, 0x400, 0);
        }
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        break;
    case 1:
        sub->timer++;
        if (sub->timer > 0x1e) {
            self->fsm->st = 10;
            self->fsm->timer = 0;
        }
        break;
    case 10:
        if (t != NULL) {
            Shared_SetEventActor(t->kind, t->id);
            data_ov000_021ccd54->stageFlags = 1;
        }
        self->fsm->st++;
        break;
    case 11:
        sub->timer++;
        if (sub->timer > 0x14) {
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 12:
        if (IsBusy021a3e50()) {
            break;
        }
        if (Task_FindById(7)) {
            break;
        }
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 0;
            m.b = 0x19a;
            m.c = 1;
            Actor_SendMsg(t, self->id, 5, TRUE, 6, &m);
        }
        self->unk_b2f = 0x2d;
        self->target = 0xffff;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    Actor_TurnToActor(self, t, 0x400);
}

}
