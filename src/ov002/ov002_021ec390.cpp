#include "ov002/ov002.h"

typedef struct ov002_StateFlags {
    u32 active : 1;
    u32 b1 : 1;
    u32 paused : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 rest : 26;
} ov002_StateFlags;

typedef struct ov002_Key021ec390 {
    s32 unk0;
    s32 value;
} ov002_Key021ec390;

typedef struct ov002_State021ec390 {
    void *vtbl;
    ov002_StateFlags flags;
    s32 state;
    s32 next;
    s32 unk10;
    s32 timer;
    s32 prevTimer;
    s32 step;
    ov002_Key021ec390 *key;
} ov002_State021ec390;

typedef struct ov002_Ctx021ec390 {
    u32 flags;
    u8 unk4[0xc];
    s32 max;
    s32 min;
    s32 step;
} ov002_Ctx021ec390;

extern "C" {

static inline BOOL ov002_State_IsPaused(ov002_State021ec390 *s) {
    return s->flags.paused == 1 ? TRUE : FALSE;
}

static inline BOOL ov002_State_IsActive(ov002_State021ec390 *s) {
    return s->flags.active == 1 ? TRUE : FALSE;
}

static inline void ov002_State_Update(ov002_State021ec390 *s) {
    if (s->next != 0) {
        s->state = s->next;
        s->next = 0;
        s->unk10 = 0;
        s->timer = 0;
        s->prevTimer = -1;
        s->step = 0x1000;
    } else if (!ov002_State_IsPaused(s)) {
        s->prevTimer = s->timer;
        s->timer = s->timer + s->step;
    }
}

static inline void ov002_State_Change(ov002_State021ec390 *s, s32 state) {
    if (s->state == state) {
        return;
    }
    s->next = state;
    ov002_State_Update(s);
}

static inline BOOL ov002_Ctx_InRange(ov002_Ctx021ec390 *ctx, s32 v) {
    return ctx->max >= v && v > ctx->min ? TRUE : FALSE;
}

static inline void ov002_State_Fail(ov002_State021ec390 *s, ov002_Ctx021ec390 *ctx) {
    if (ov002_State_IsActive(s)) {
        ctx->flags |= 4;
    }
}

BOOL func_ov002_021ec390(ov002_State021ec390 *self, ov002_Ctx021ec390 *ctx) {
    BOOL result = TRUE;
    ov002_State_Update(self);
    self->step = ctx->step;
    if (ov002_Ctx_InRange(ctx, self->key->value)) {
        self->flags.active = 1;
    }
    switch (self->state) {
    case 1:
        if (!VC(self, 0x1c)()) {
            ov002_State_Fail(self, ctx);
            break;
        }
        ov002_State_Change(self, 5);
    case 5:
        if (!VC(self, 0x18)()) {
            ov002_State_Fail(self, ctx);
            break;
        }
        self->flags.b4 = 1;
        ov002_State_Change(self, 6);
    case 6:
        if (!VC(self, 0x20)()) {
            ov002_State_Fail(self, ctx);
            break;
        }
        self->flags.b5 = 1;
        ov002_State_Change(self, 9);
    case 9:
        if (ov002_State_IsActive(self)) {
            VC(self, 0x24)();
            if (self->state != 7) {
                self->next = 7;
            }
        }
        break;
    case 3:
    case 7:
        result = VC(self, 0x28)();
        break;
    }
    return result;
}

}
