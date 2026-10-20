#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u32 unk_00;
    u8 active : 1;
    u8 noSnap : 1;
    u8 done : 1;
    s32 speed;
    s32 dist;
    s32 maxDist;
    Ov003Vec pos;
    Ov003Vec target;
    Ov003Vec dir;
} Ov003Mover;

typedef struct {
    u8 active : 1;
    u8 loop : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    s16 count;
    s16 interval;
    s16 timer;
    s16 next;
    s16 cur;
} Ov003Ticker;

extern "C" {

extern s32 VEC_Distance(Ov003Vec *a, Ov003Vec *b);
extern void VEC_MultAdd(s32 scale, Ov003Vec *dir, Ov003Vec *src, Ov003Vec *dst);
extern void VEC_Normalize(Ov003Vec *src, Ov003Vec *dst);
extern s16 func_02040528(s32 max);
extern s32 func_0200b184(s32 a, s32 b);
extern u32 data_ov003_021f7d10;
extern void func_0203de1c(void *p);

class Ov003TickerSet {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 unk_05[3];
    Ov003Ticker tickers[3];
};

static inline void Ov003Ticker_Release(Ov003Ticker *self) {
    if (self->active) {
        self->active = 0;
        self->loop = 0;
        self->b2 = 0;
        self->count = 0;
        self->interval = 0;
        self->timer = 0;
        self->next = 0;
        self->cur = 0;
    }
}

static inline void Ov003Ticker_Clear(Ov003Ticker *self) {
    self->active = 0;
    self->loop = 0;
    self->b2 = 0;
    self->count = 0;
    self->interval = 0;
    self->timer = 0;
    self->next = 0;
    self->cur = 0;
}

void func_ov003_021d7d8c(Ov003Ticker *self) {
    if (self->active) {
        self->active = 0;
        self->loop = 0;
        self->b2 = 0;
        self->count = 0;
        self->interval = 0;
        self->timer = 0;
        self->next = 0;
        self->cur = 0;
    }
}

void func_ov003_021d7dd0(Ov003Ticker *self) {
    BOOL run;
    if (!self->active) {
        return;
    }
    if (self->loop || self->count > 0) {
        run = TRUE;
    } else {
        run = FALSE;
    }
    if (!run) {
        return;
    }
    if (self->interval > self->timer) {
        self->timer++;
    } else {
        self->timer = 0;
        self->cur = self->next;
        self->next = func_02040528(0x1000);
    }
    self->count--;
}


static inline s32 FxMul(s32 a, s32 b) { return (s32)(((s64)a * b + 0x800) >> 12); }
s16 func_ov003_021d7e58(Ov003Ticker *self) {
    s16 v;
    s32 cur;
    s16 r = 0;
    s32 d;
    if (self->active && !self->b3) {
        if (self->b2) {
            d = self->interval - self->timer;
            if (d == 0) {
                v = self->next;
            } else {
                cur = self->cur;
                v = cur + (s16)FxMul(self->next - cur, 0x1000 / d);
            }
        } else {
            v = self->next;
        }
        r = (v > 0x1000) ? 0x1000 : ((v < -0x1000) ? -0x1000 : v);
    }
    return r;
}

}
