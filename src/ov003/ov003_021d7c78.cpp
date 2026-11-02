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
extern u32 data_ov003_021f7d10;
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

void Ov003Mover_SetMaxDist(Ov003Mover *self, s32 maxDist) {
    if (self->active == 1) {
        self->maxDist = maxDist;
    }
}

void Ov003Mover_SetSpeed(Ov003Mover *self, s32 speed) {
    if (self->active == 1) {
        self->speed = speed;
    }
}

void func_ov003_021d7ca8(Ov003Ticker *self) {
    self->active = 0;
    self->loop = 0;
    self->b2 = 0;
    self->count = 0;
    self->interval = 0;
    self->timer = 0;
    self->next = 0;
    self->cur = 0;
}

void func_ov003_021d7ce0(Ov003Ticker *self) {
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

BOOL func_ov003_021d7d24(Ov003Ticker *self, s16 count, s16 interval, bool loop, bool b2) {
    self->active = 1;
    self->loop = loop;
    self->b3 = 0;
    self->b2 = b2;
    self->count = count;
    self->interval = interval;
    self->cur = Rand_PlusMinus(0x1000);
    self->next = self->cur;
    return TRUE;
}

}
