#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 b0 : 2;
    u16 b2 : 1;
    u16 b3 : 2;
    u16 b5 : 1;
    u16 b6 : 2;
    u16 b8 : 1;
    u16 rest : 7;
} Flags021950e8;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bits021950e8;

extern "C" {
extern u8 *data_0214a424;
Actor *func_ov000_0219bf90(void);
BOOL func_ov000_0219b3b4(void *p);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
BOOL func_ov000_0218d494(Actor *self, ActorMsg *msg);

static inline BOOL IsB1021950e8(Actor *p) {
    return LFLD(Bits021950e8, p, 0xb24).b1 ? TRUE : FALSE;
}

BOOL func_ov000_021950e8(Actor *self, ActorMsg *msg) {
    BOOL handled = FALSE;
    BOOL callBase = TRUE;
    switch (msg->type) {
    case 9: {
        u8 *sub = (u8 *)self->unk_4c;
        callBase = FALSE;
        if (sub != NULL) {
            u8 k = LFLD(u8, sub, 0);
            u8 k2 = LFLD(u8, sub, 2);
            if (k == 0x15) {
                if (LFLD(u16, msg->data, 0) != 0) {
                    ((ActorSub40 *)self->unk_40)->flags |= 0x40;
                    if (LFLD(void *, self, 0x50) != NULL) {
                        LFLD(u16, LFLD(void *, self, 0x50), 4) = LFLD(u16, msg->data, 4);
                    }
                }
            } else if (k == 0xb) {
                ((ActorSub40 *)self->unk_40)->flags |= 0x40000;
            } else if (k2 == 1 && ((k != 0x11 && k != 0x12 && k != 0x13 && k != 0x14) || LFLD(u16, msg->data, 0) != 0)) {
                if (!LFLD(Flags021950e8, self, 0xcc).b2) {
                    Actor *p = func_ov000_0219bf90();
                    if (p != NULL && msg->id == p->id) {
                        u8 *g = data_0214a424;
                        u32 n = LFLD(u16, g, 0x16) + 1;
                        if (n >= 0xffff) {
                            n = 0xffff;
                        }
                        LFLD(u16, g, 0x16) = n;
                        ((ActorSub40 *)self->unk_40)->flags |= 0x200000;
                    }
                }
            } else if (LFLD(u16, msg->data, 0) == 0 && LFLD(u16, sub, 0x1c) == 0xffff) {
                Actor *p = func_ov000_0219bf90();
                if (p != NULL && !IsB1021950e8(p) && msg->id == p->id && p->target == self->id &&
                    func_ov000_0219b3b4(self->unk_4c) && LFLD(void *, self, 0x48) != NULL &&
                    (LFLD(u32, LFLD(void *, self, 0x48), 0x54) & 0x20000000)) {
                    VecFx32 a;
                    VecFx32 b;
                    a = self->pos;
                    b = p->pos;
                    a.y += LFLD(s32, self, 0x6c);
                    b.y += LFLD(s32, p, 0x6c);
                    if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) == -0x1000) {
                        ((ActorSub40 *)self->unk_40)->flags |= 0x400;
                        LFLD(u16, self->unk_4c, 0x1c) = msg->id;
                        LFLD(Flags021950e8, self, 0xcc).b8 = 1;
                    }
                }
            }
        }
        handled = TRUE;
        break;
    }
    case 2:
        if (msg->data[0] == 0x15) {
            LFLD(Flags021950e8, self, 0xcc).b5 = 0;
        }
        break;
    }
    if (callBase && func_ov000_0218d494(self, msg)) {
        return TRUE;
    }
    if (handled) {
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    return handled;
}
}
