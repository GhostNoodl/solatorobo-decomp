#include "ov009/ov009.h"

extern "C" {

extern BOOL ActorEx_HandleMsg(Actor *self, ActorMsg *msg);
extern void ActorEx_Start(Actor *self);
extern Actor *Target_Get(ActorSub4c *p);

void Ov009ActExVt_0221828c_HandleMsg(Ov009ActExVt_0221828c *self, ActorMsg *msg) {
    if (msg->type == 6) {
        self->unk_ce_u = msg->unk_08;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    ActorEx_HandleMsg(self, msg);
}

void Ov009ActExVt_0221828c_Start(Ov009ActExVt_0221828c *self) {
    Actor *p;
    ActorEx_Start(self);
    self->unk_d0 = 0;
    p = Target_Get(self->targetObj);
    if (p != NULL) {
        self->unk_d2 = p->id;
    }
    History_SetState(self->fsm, 1, 0);
}

}
