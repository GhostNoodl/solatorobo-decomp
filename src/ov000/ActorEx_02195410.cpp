#include "ov000/Actor.h"
#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern s32 data_ov000_021c9d9c[];
extern s32 data_ov000_021c9db0[];
extern s32 data_ov000_021c9dc4[];
BOOL func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
void func_ov000_0218d7e8(Actor *self, u8 arg);

void func_ov000_02195410(ActorEx *self) {
    ActorSub40 *s = self->fsm;
    if (s->flags != 0) {
        if (!func_ov000_0219840c(s, data_ov000_021c9d9c, 5, TRUE)) {
            if (self->fsm->flags & 2) {
                func_ov000_02198360(self->fsm, 1, 1);
            }
        }
    }
    s = self->fsm;
    switch (s->current) {
    case 9:
        func_ov000_0219840c(s, data_ov000_021c9db0, 5, TRUE);
        break;
    case 11:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else if (s->flags & 0x800) {
            func_ov000_02198360(s, 0xb, 1);
        }
        break;
    case 4:
    case 10:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else if (s->flags & 0x800) {
            func_ov000_02198360(s, 0xb, 0);
        }
        break;
    case 14:
        if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        }
        break;
    case 0:
        func_ov000_0219840c(s, data_ov000_021c9dc4, 9, TRUE);
        break;
    case 1:
    case 2:
        if ((s->flags & 0x400) && (self->msg_flags & 0x80)) {
            s->flags &= ~0x400;
            self->targetObj->target = 0xffff;
        }
        if (!func_ov000_0219840c(self->fsm, data_ov000_021c9dc4, 9, TRUE)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    func_ov000_0218d7e8(self, self->fsm->current);
}
}
