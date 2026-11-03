#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"


typedef struct {
    u8 b0, b1, b2, b3;
    u16 h4, h6, h8, ha;
    s32 wc;
} S0219bebc;
static inline void SetS(S0219bebc *p, S0219bebc v) {
    *p = v;
}

extern "C" {
void Obj0215eab4_Draw(void *p);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);

static inline Actor *FindA(u16 id) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

void func_ov000_021a15e0(Robo021ca458 *self) {
    ActorSub40 *s = (ActorSub40 *)self->fsm;
    Actor *a;
    ActorSub4c *p;
    if (s != NULL) {
        s->flags |= 2;
    }
    self->unk_b24_25 = 1;
    self->unk_b24_21 = 0;
    if (self->unk_b24_5 == 0) {
        return;
    }
    a = FindA(self->unk_b1c);
    p = NULL;
    if (a != NULL) {
        p = a->targetObj;
    }
    if (p != NULL && p->target == self->id) {
        return;
    }
    if (p != NULL) {
        p->target = 0xffff;
    }
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
}

}
