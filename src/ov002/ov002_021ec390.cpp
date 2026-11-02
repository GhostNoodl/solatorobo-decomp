#include "ov002/ov002.h"
#include "ov002/StaffRoll.h"

extern "C" {

static inline BOOL ov002_State_IsPaused(Ov002StaffNode *s) {
    return s->clock.flags.paused == 1 ? TRUE : FALSE;
}

static inline BOOL ov002_State_IsActive(Ov002StaffNode *s) {
    return s->clock.flags.active == 1 ? TRUE : FALSE;
}

static inline void ov002_State_Update(Ov002StaffNode *s) {
    if (s->clock.next != 0) {
        s->clock.state = s->clock.next;
        s->clock.next = 0;
        s->clock.sub = 0;
        s->clock.timer = 0;
        s->clock.prevTimer = -1;
        s->clock.step = 0x1000;
    } else if (!ov002_State_IsPaused(s)) {
        s->clock.prevTimer = s->clock.timer;
        s->clock.timer = s->clock.timer + s->clock.step;
    }
}

static inline void ov002_State_Change(Ov002StaffNode *s, s32 state) {
    if (s->clock.state == state) {
        return;
    }
    s->clock.next = state;
    ov002_State_Update(s);
}

static inline BOOL ov002_Ctx_InRange(Ov002StaffClock *ctx, s32 v) {
    return ctx->timer >= v && v > ctx->prevTimer ? TRUE : FALSE;
}

static inline void ov002_State_HoldClock(Ov002StaffNode *s, Ov002StaffClock *ctx) {
    if (ov002_State_IsActive(s)) {
        ctx->flags.paused = 1;
    }
}

BOOL func_ov002_021ec390(Ov002StaffNode *self, Ov002StaffClock *ctx) {
    BOOL result = TRUE;
    ov002_State_Update(self);
    self->clock.step = ctx->step;
    if (ov002_Ctx_InRange(ctx, self->entry->time)) {
        self->clock.flags.active = 1;
    }
    switch (self->clock.state) {
    case 1:
        if (!self->vfunc_1c()) {
            ov002_State_HoldClock(self, ctx);
            break;
        }
        ov002_State_Change(self, 5);
    case 5:
        if (!self->vfunc_18()) {
            ov002_State_HoldClock(self, ctx);
            break;
        }
        self->clock.flags.b4 = 1;
        ov002_State_Change(self, 6);
    case 6:
        if (!self->vfunc_20()) {
            ov002_State_HoldClock(self, ctx);
            break;
        }
        self->clock.flags.b5 = 1;
        ov002_State_Change(self, 9);
    case 9:
        if (ov002_State_IsActive(self)) {
            self->vfunc_24();
            if (self->clock.state != 7) {
                self->clock.next = 7;
            }
        }
        break;
    case 3:
    case 7:
        result = self->vfunc_28();
        break;
    }
    return result;
}

}
