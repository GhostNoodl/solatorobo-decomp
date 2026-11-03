#include "types.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u16 cur;
    u16 max;
} Count0219a0b0;

typedef struct {
    u8 pad[0x50];
    Count0219a0b0 *unk_50;
} Actor0219a0b0;

typedef struct {
    u16 timer;
    u16 interval;
    u16 value;
} Obj0219a0b0;

typedef struct {
    u8 pad[4];
    s32 unk_04;
    u8 unk_08;
    u8 pad09[0x1b];
} Ev0219a0b0;

typedef struct {
    Ev0219a0b0 evs[16];
    u8 pad240[8];
    s32 idx;
} Log0219a0b0;

typedef struct {
    u8 pad[0x7c];
    Log0219a0b0 *unk_7c;
} Sub0219a0b0;

typedef struct {
    u8 pad[0x11c];
    Sub0219a0b0 *unk_11c;
} Mgr0219a0b0;

typedef struct {
    u16 value;
    char str[0x22];
} Msg0219a0b0;

extern "C" {
extern Mgr0219a0b0 *gMessageQueue;
void Actor_SendMsg(Actor0219a0b0 *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_02040a98(char *dst, int num);

static inline BOOL GBusy0219a0b0(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle0219a0b0(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        if (GBusy0219a0b0(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_0219a0b0(Obj0219a0b0 *self, Actor0219a0b0 *actor) {
    Count0219a0b0 *cnt;
    Msg0219a0b0 msg;
    Sub0219a0b0 *sub;
    Log0219a0b0 *log;
    if (actor == NULL) {
        return;
    }
    if (!GIdle0219a0b0() || (cnt = actor->unk_50) == NULL) {
        return;
    }
    if (cnt->cur >= cnt->max) {
        return;
    }
    if (self->value == 0 || self->interval == 0) {
        return;
    }
    self->timer++;
    if (self->timer <= self->interval) {
        return;
    }
    self->timer = 0;
    msg.value = self->value;
    Actor_SendMsg(actor, 0xffff, 10, 1, 2, &msg);
    func_02040a98(msg.str, self->value);
    sub = gMessageQueue->unk_11c;
    if (sub == NULL || (log = sub->unk_7c) == NULL) {
        return;
    }
    log->evs[log->idx].unk_04 = 6;
    log->evs[log->idx].unk_08 = 0;
    if (++log->idx >= 16) {
        log->idx = 0;
    }
}

}
