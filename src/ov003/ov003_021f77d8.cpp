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


struct Ov003Rot16 { s16 x, y, z; };

extern "C" {

// A header's zero rotation and vector, plus copies made at startup. Other functions of this TU
// read the vector and its copy, so those two keep their names. func_ov003_021d883c is part of this
// TU: it reads the vector through the .rodata base plus an offset.
extern const Ov003Rot16 data_ov003_021f4980;
extern const Ov003VecP data_ov003_021f4988;
extern const Ov003VecP data_ov003_021f7cc4;
const Ov003Rot16 data_ov003_021f4980 = {0, 0, 0};
const Ov003VecP data_ov003_021f4988 = {0, 0, 0};
static const Ov003Rot16 data_ov003_021f7cbc = data_ov003_021f4980;
const Ov003VecP data_ov003_021f7cc4 = data_ov003_021f4988;

extern s16 func_ov003_021d7e58(Ov003Ticker *t);
extern void VEC_MultAdd(s32 scale, const Ov003Vec *dir, const Ov003Vec *src, Ov003Vec *dst);

static inline BOOL Ov003TickerSet_IsDone(Ov003TickerSet *self) {
    if (!self->loop && self->count <= 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021d883c(Ov003TickerSet *self, Ov003Vec *dst, const Ov003Vec *src, s32 scale) {
    Ov003Vec v;
    if (self->active && !Ov003TickerSet_IsDone(self)) {
        v.x = func_ov003_021d7e58(&self->tickers[0]);
        v.y = func_ov003_021d7e58(&self->tickers[1]);
        v.z = func_ov003_021d7e58(&self->tickers[2]);
    } else {
        v.x = data_ov003_021f4988.x;
        v.y = data_ov003_021f4988.y;
        v.z = data_ov003_021f4988.z;
    }
    VEC_MultAdd(scale, &v, src, dst);
}

}
