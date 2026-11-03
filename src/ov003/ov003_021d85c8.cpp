#include "types.h"
#include "ov003/Vec.h"
#include "ov003/Ticker.h"
#include "ov003/StateMachine.h"


class Ov003TickerSet {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 loop : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    s16 count;
    Ov003Ticker tickers[3];
};

class Ov003Timer {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    s16 unk_06;
    u32 unk_08;
    u8 unk_0c[4];
    u32 unk_10;
    u32 unk_14;
};


static inline Ov003StateNode *Ov003StateMachine_Find(Ov003StateMachine *self, u8 id) {
    Ov003StateNode *n;
    for (n = self->list; n != NULL; n = n->next) {
        if (n->id == id) {
            return n;
        }
    }
    return NULL;
}

extern "C" {

extern u32 Ov003Vt_021f7cf4_vtbl;
extern u32 Ov003Vt_021f7cd8_vtbl;
extern s16 Ov003Ticker_GetValue(Ov003Ticker *t);
extern void Heap_Free(void *p);
extern void *Heap_Alloc(u32 size);
extern void *History_Init(void *p);
extern s32 Rand_PlusMinus(s32 max);

static inline void Ov003Ticker_Reset(Ov003Ticker *t) {
    if (t->active) {
        t->active = false;
        t->loop = false;
        t->b2 = false;
        t->count = 0;
        t->interval = 0;
        t->timer = 0;
        t->next = 0;
        t->cur = 0;
    }
}

static inline void Ov003Ticker_Start(Ov003Ticker *t, s16 count, s16 interval, bool loop, bool b2) {
    t->active = true;
    t->loop = loop;
    t->b3 = false;
    t->b2 = b2;
    t->count = count;
    t->interval = interval;
    t->cur = Rand_PlusMinus(0x1000);
    t->next = t->cur;
}

void Ov003TickerSet_Start(Ov003TickerSet *self, s16 count, s16 interval, bool loop, bool b2);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match declared the stack parameter b2 `volatile` so that it
// is reloaded for each ticker; plain bool/int/u8/BOOL types and a loop all load it once. The score is in
// docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Ov003TickerSet_Start(Ov003TickerSet *self, s16 count, s16 interval, bool loop, bool b2) {
    if (!self->active) {
        return;
    }
    Ov003Ticker_Reset(&self->tickers[0]);
    Ov003Ticker_Reset(&self->tickers[1]);
    Ov003Ticker_Reset(&self->tickers[2]);
    self->count = count;
    self->loop = loop;
    Ov003Ticker_Start(&self->tickers[0], count, interval, loop, b2);
    Ov003Ticker_Start(&self->tickers[1], count, interval, loop, b2);
    Ov003Ticker_Start(&self->tickers[2], count, interval, loop, b2);
}
#endif


void Ov003TickerSet_SetPaused(Ov003TickerSet *self, bool v) {
    if (self->active) {
        self->b2 = v;
        self->b3 = v;
    }
}

void Ov003TickerSet_SetHold(Ov003TickerSet *self, bool v) {
    if (self->active) {
        self->b3 = v;
    }
}

BOOL Ov003TickerSet_IsHeld(Ov003TickerSet *self) {
    BOOL r = FALSE;
    if (self->active) {
        r = self->b3;
    }
    return r;
}

}
