#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/ObjLayouts.h"


extern "C" {
extern void *gMessageQueue;
ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 id);
void MessageQueue021cb980_Push14(void *p, s32 a);
void func_ov000_021b1a54(Robo021ca458 *self, s32 a);

static inline Actor *GroupNext(Actor *head, Actor *cur) {
    return cur != NULL ? cur->next : head;
}

void func_ov000_021b1110(Robo021ca458 *self, BOOL force) {
    u8 found = FALSE;
    {
        ActorGroup *g = ActorMgr_GetGroup(gActorMgr, 0x5000);
        Actor *head = g->head;
        Actor *cur;
        for (cur = head; cur != NULL; cur = GroupNext(head, cur)) {
            if (cur->unk_93_4) {
                found = TRUE;
                break;
            }
        }
    }
    if (!found) {
        ActorGroup *g = ActorMgr_GetGroup(gActorMgr, 0x4000);
        Actor *head = g->head;
        Actor *cur;
        for (cur = head; cur != NULL; cur = GroupNext(head, cur)) {
            if (cur->unk_93_4) {
                found = TRUE;
                break;
            }
        }
    }
    if (found && self->unk_b32 == 0 && *self->hp != 0) {
        self->unk_b32++;
    }
    if (force || !self->unk_b28_2) {
        if (self->unk_93_4 == found) {
            return;
        }
        if (found) {
            MessageQueue021cb980_Push14(gMessageQueue, 1);
            self->unk_93_4 = found;
            self->unk_b2a = 0;
        } else {
            MessageQueue021cb980_Push14(gMessageQueue, 2);
            self->unk_93_4 = found;
        }
    } else {
        if (found) {
            return;
        }
        if (!self->unk_b22_3) {
            return;
        }
        if (self->unk_b22_4) {
            return;
        }
        if (self->unk_b24_0) {
            return;
        }
        func_ov000_021b1a54(self, 1);
    }
}
}
