#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov003Vec() {}
};

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

class Ov003State {
public:
    virtual void v00();
    virtual void v04();
    virtual void Enter();
    virtual void Leave();
    virtual void Update();
    virtual void Message(void *arg);
};

typedef struct Ov003StateNode {
    u8 id;
    Ov003State *state;
    struct Ov003StateNode *next;
} Ov003StateNode;

class Ov003StateMachine {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active;
    Ov003StateNode *cur;
    Ov003StateNode *list;
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

struct Ov003VecP {
    s32 x;
    s32 y;
    s32 z;
};

typedef struct {
    u8 unk_00[8];
    Ov003VecP v;
} Ov003Defaults;

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

extern const Ov003Defaults data_ov003_021f4980;
extern u32 data_ov003_021f7cf4;
extern u32 data_ov003_021f7cd8;
extern s16 func_ov003_021d7e58(Ov003Ticker *t);
extern void func_02012fb8(s32 scale, const Ov003Vec *dir, const Ov003Vec *src, Ov003Vec *dst);
extern void func_0203de1c(void *p);
extern void *func_0203dd9c(u32 size);
extern void func_ov000_02198328(void *p);

void func_ov003_021d87d0(Ov003TickerSet *self, bool v) {
    if (self->active) {
        self->b2 = v;
        self->b3 = v;
    }
}

void func_ov003_021d8800(Ov003TickerSet *self, bool v) {
    if (self->active) {
        self->b3 = v;
    }
}

BOOL func_ov003_021d8820(Ov003TickerSet *self) {
    BOOL r = FALSE;
    if (self->active) {
        r = self->b3;
    }
    return r;
}

}
