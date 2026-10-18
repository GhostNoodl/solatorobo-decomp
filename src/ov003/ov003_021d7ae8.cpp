#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov003Vec() {}
};

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

extern s32 func_02013068(Ov003Vec *a, Ov003Vec *b);
extern void func_02012fb8(s32 scale, Ov003Vec *dir, Ov003Vec *src, Ov003Vec *dst);
extern void func_02012d78(Ov003Vec *src, Ov003Vec *dst);
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

void func_ov003_021d7ae8(Ov003Mover *self) {
    if (self->active) {
        self->active = 0;
    }
}

void func_ov003_021d7b00(Ov003Mover *self) {
    BOOL reached;
    s32 d;
    if (!self->active) {
        return;
    }
    if (!self->noSnap && self->done == 1) {
        return;
    }
    self->dist += self->speed;
    if (self->dist > self->maxDist) {
        self->dist = self->maxDist;
    }
    d = func_02013068(&self->target, &self->pos);
    reached = TRUE;
    if (d > self->dist) {
        reached = FALSE;
    }
    func_02012fb8(self->dist, &self->dir, &self->pos, &self->pos);
    if (!reached) {
        return;
    }
    self->done = 1;
    if (!self->noSnap) {
        self->pos.x = self->target.x;
        self->pos.y = self->target.y;
        self->pos.z = self->target.z;
    }
}

Ov003Vec *func_ov003_021d7bbc(Ov003Mover *self) {
    if (self->active) {
        return &self->pos;
    }
    return NULL;
}

Ov003Vec *func_ov003_021d7bd4(Ov003Mover *self) {
    if (self->active) {
        return &self->dir;
    }
    return NULL;
}

BOOL func_ov003_021d7bec(Ov003Mover *self) {
    BOOL r = FALSE;
    if (self->active) {
        r = self->done;
    }
    return r;
}

void func_ov003_021d7c08(Ov003Mover *self, const Ov003Vec *target) {
    if (!self->active) {
        return;
    }
    if (self->done) {
        return;
    }
    self->target = *target;
    self->dir.x = target->x - self->pos.x;
    self->dir.y = target->y - self->pos.y;
    self->dir.z = target->z - self->pos.z;
    func_02012d78(&self->dir, &self->dir);
}

}
