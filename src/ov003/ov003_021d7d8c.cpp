#include "types.h"
#include "nitro/fx.h"
#include "ov003/Ticker.h"


typedef struct {
    u32 unk_00;
    u8 active : 1;
    u8 noSnap : 1;
    u8 done : 1;
    s32 speed;
    s32 dist;
    s32 maxDist;
    VecFx32 pos;
    VecFx32 target;
    VecFx32 dir;
} Ov003Mover;

extern "C" {

extern int Rand_PlusMinus(s32 max);
extern s32 func_0200b184(s32 a, s32 b);
extern u32 Ov003Vt_021f7d10_vtbl;
extern void Heap_Free(void *p);

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

void Ov003Ticker_Release_021d7d8c(Ov003Ticker *self) {
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

void Ov003Ticker_Update_021d7dd0(Ov003Ticker *self) {
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
        self->next = Rand_PlusMinus(0x1000);
    }
    self->count--;
}


static inline s32 FxMul(s32 a, s32 b) { return (s32)(((s64)a * b + 0x800) >> 12); }
s16 Ov003Ticker_GetValue(Ov003Ticker *self) {
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
