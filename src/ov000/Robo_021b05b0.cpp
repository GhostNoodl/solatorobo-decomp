#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern s32 data_ov000_021c9ff8[];
BOOL History_SetState(void *s, s32 a, s32 b);
BOOL History_PickFlagged(void *s, s32 *list, s32 count, BOOL push);
void Actor_DropStateMsgs(Actor *self, u8 arg);

void func_ov000_021b05b0(Robo021ca458 *self) {
    ActorSub40 *s;
    self->model = (Model0218fe1c *)&self->mdl1;
    self->hit = (ActorSub48 *)&self->hit1;
    self->unk_b08 = 0x2cd;
    s = self->fsm;
    if (s->flags != 0) {
        if (s->flags & 1) {
            return;
        }
        if (s->flags & 0x80000000) {
            History_SetState(s, 0x1f, 0);
        } else if (s->flags & 2) {
            History_SetState(s, 1, 1);
        } else if ((s->flags & 0x40000) || (s->flags & 0x80000)) {
            History_SetState(s, 0x12, 1);
        }
    }
    s = self->fsm;
    switch (s->current) {
    case 1:
        if (s->flags & 2) {
            break;
        }
    case 2:
        if (!History_PickFlagged(s, data_ov000_021c9ff8, 2, TRUE)) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Actor_DropStateMsgs(self, self->fsm->current);
}
}
