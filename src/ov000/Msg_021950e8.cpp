#include "ov000/Actor.h"
#include "Main/Res/StageFlags.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits021950e8;

extern "C" {
Actor *ActorMgr_FindPlayer(void);
BOOL func_ov000_0219b3b4(void *p);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
BOOL Actor_HandleMsg(Actor *self, ActorMsg *msg);

static inline BOOL IsB1021950e8(Actor *p) {
    return LFLD(Bits021950e8, p, 0xb24).b1 ? TRUE : FALSE;
}

BOOL ActorEx_HandleMsg(ActorEx *self, ActorMsg *msg) {
    BOOL handled = FALSE;
    BOOL callBase = TRUE;
    switch (msg->type) {
    case 9: {
        ActorSub4c *sub = self->targetObj;
        callBase = FALSE;
        if (sub != NULL) {
            u8 k = sub->type;
            u8 k2 = sub->unk_02;
            if (k == 0x15) {
                if (LFLD(u16, msg->data, 0) != 0) {
                    ((ActorSub40 *)self->fsm)->flags |= 0x40;
                    if (self->hp != NULL) {
                        self->hpObj->unk_04 = LFLD(u16, msg->data, 4);
                    }
                }
            } else if (k == 0xb) {
                ((ActorSub40 *)self->fsm)->flags |= 0x40000;
            } else if (k2 == 1 && ((k != 0x11 && k != 0x12 && k != 0x13 && k != 0x14) || LFLD(u16, msg->data, 0) != 0)) {
                if (!self->unk_cc_2) {
                    Actor *p = ActorMgr_FindPlayer();
                    if (p != NULL && msg->id == p->id) {
                        StageFlags *g = data_0214a424;
                        u32 n = g->unk_016 + 1;
                        if (n >= 0xffff) {
                            n = 0xffff;
                        }
                        g->unk_016 = n;
                        ((ActorSub40 *)self->fsm)->flags |= 0x200000;
                    }
                }
            } else if (LFLD(u16, msg->data, 0) == 0 && sub->target == 0xffff) {
                Actor *p = ActorMgr_FindPlayer();
                if (p != NULL && !IsB1021950e8(p) && msg->id == p->id && p->target == self->id &&
                    func_ov000_0219b3b4(self->targetObj) && self->hit != NULL &&
                    (self->hit->unk_54 & 0x20000000)) {
                    VecFx32 a;
                    VecFx32 b;
                    a = self->pos;
                    b = p->pos;
                    a.y += self->centerY;
                    b.y += p->centerY;
                    if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) == -0x1000) {
                        ((ActorSub40 *)self->fsm)->flags |= 0x400;
                        self->targetObj->target = msg->id;
                        self->unk_cc_8 = 1;
                    }
                }
            }
        }
        handled = TRUE;
        break;
    }
    case 2:
        if (msg->data[0] == 0x15) {
            self->unk_cc_5 = 0;
        }
        break;
    }
    if (callBase && Actor_HandleMsg(self, msg)) {
        return TRUE;
    }
    if (handled) {
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    return handled;
}
}
