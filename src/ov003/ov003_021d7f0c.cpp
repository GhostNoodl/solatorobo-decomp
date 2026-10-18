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
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 unk_05;
    s16 unk_06;
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

Ov003TickerSet *func_ov003_021d7f0c(Ov003TickerSet *self) {
    *(void **)self = &data_ov003_021f7d10;
    Ov003Ticker_Clear(&self->tickers[0]);
    Ov003Ticker_Clear(&self->tickers[1]);
    Ov003Ticker_Clear(&self->tickers[2]);
    self->active = 0;
    return self;
}

Ov003TickerSet *func_ov003_021d7fc0(Ov003TickerSet *self) {
    *(void **)self = &data_ov003_021f7d10;
    self->Release();
    Ov003Ticker_Release(&self->tickers[2]);
    Ov003Ticker_Release(&self->tickers[1]);
    Ov003Ticker_Release(&self->tickers[0]);
    return self;
}

Ov003TickerSet *func_ov003_021d80a8(Ov003TickerSet *self) {
    *(void **)self = &data_ov003_021f7d10;
    self->Release();
    Ov003Ticker_Release(&self->tickers[2]);
    Ov003Ticker_Release(&self->tickers[1]);
    Ov003Ticker_Release(&self->tickers[0]);
    func_0203de1c(self);
    return self;
}

BOOL func_ov003_021d8198(Ov003TickerSet *self) {
    self->active = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->unk_06 = 0;
    return TRUE;
}

void func_ov003_021d81d0(Ov003TickerSet *self) {
    if (!self->active) {
        return;
    }
    self->active = 1;
    Ov003Ticker_Release(&self->tickers[0]);
    Ov003Ticker_Release(&self->tickers[1]);
    Ov003Ticker_Release(&self->tickers[2]);
}

}
