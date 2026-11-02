#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern s32 data_ov003_021f43f0[];
extern s32 data_ov003_021f437c[];
extern s32 data_ov003_021f440c[];
extern s32 func_ov000_0219840c(ActorSub40 *self, s32 *list, s32 count, BOOL push);
extern BOOL func_ov000_02198360(ActorSub40 *self, u8 value, BOOL force);
extern void func_ov000_0218d7e8(Actor *self, u8 state);

void func_ov003_021d2e28(Ov003Actor *self) {
    ActorSub40 *h = self->fsm;
    if (h->flags != 0 && func_ov000_0219840c(h, data_ov003_021f43f0, 7, TRUE) == 0) {
        h = self->fsm;
        if (h->current != 0x15) {
            if (h->flags & 0x100000) {
                func_ov000_02198360(h, 0x14, TRUE);
            } else if (h->flags & 0x2) {
                func_ov000_02198360(h, 1, TRUE);
            } else if (h->flags & 0x80000) {
                func_ov000_02198360(h, 0x13, TRUE);
            } else if (h->flags & 0x40000) {
                func_ov000_02198360(h, 0x12, TRUE);
            }
        }
    }
    h = self->fsm;
    switch (h->current) {
    case 9:
        func_ov000_0219840c(h, data_ov003_021f437c, 3, TRUE);
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
            func_ov000_02198360(h, 9, FALSE);
        }
        break;
    case 0:
        func_ov000_0219840c(h, data_ov003_021f440c, 7, TRUE);
        break;
    case 1:
    case 2:
        if (func_ov000_0219840c(h, data_ov003_021f440c, 7, TRUE) == 0) {
            h = self->fsm;
            if (h->flags & 0x4) {
                func_ov000_02198360(h, 2, FALSE);
            } else {
                func_ov000_02198360(h, 1, FALSE);
            }
        }
        break;
    }
    func_ov000_0218d7e8(self, self->fsm->current);
}

}
