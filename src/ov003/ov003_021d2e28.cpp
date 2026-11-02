#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern s32 data_ov003_021f43f0[];
extern s32 data_ov003_021f437c[];
extern s32 data_ov003_021f440c[];
extern s32 History_PickFlagged(ActorSub40 *self, s32 *list, s32 count, BOOL push);
extern BOOL History_SetState(ActorSub40 *self, u8 value, BOOL force);
extern void Actor_DropStateMsgs(Actor *self, u8 state);

void Ov003Actor_SelectState(Ov003Actor *self) {
    ActorSub40 *h = self->fsm;
    if (h->flags != 0 && History_PickFlagged(h, data_ov003_021f43f0, 7, TRUE) == 0) {
        h = self->fsm;
        if (h->current != 0x15) {
            if (h->flags & 0x100000) {
                History_SetState(h, 0x14, TRUE);
            } else if (h->flags & 0x2) {
                History_SetState(h, 1, TRUE);
            } else if (h->flags & 0x80000) {
                History_SetState(h, 0x13, TRUE);
            } else if (h->flags & 0x40000) {
                History_SetState(h, 0x12, TRUE);
            }
        }
    }
    h = self->fsm;
    switch (h->current) {
    case 9:
        History_PickFlagged(h, data_ov003_021f437c, 3, TRUE);
        break;
    case 4:
    case 11:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        if (h->flags & 0x200) {
            History_SetState(h, 9, FALSE);
        }
        break;
    case 0:
        History_PickFlagged(h, data_ov003_021f440c, 7, TRUE);
        break;
    case 1:
    case 2:
        if (History_PickFlagged(h, data_ov003_021f440c, 7, TRUE) == 0) {
            h = self->fsm;
            if (h->flags & 0x4) {
                History_SetState(h, 2, FALSE);
            } else {
                History_SetState(h, 1, FALSE);
            }
        }
        break;
    }
    Actor_DropStateMsgs(self, self->fsm->current);
}

}
