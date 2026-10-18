#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

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
    struct Ov003TmTarget *target;
    u16 state;
    u16 timer;
    u32 unk_10;
    u32 unk_14;
};

struct Ov003TmSub {
    u8 unk_00[0xc];
    Ov003Vec offset;
};

struct Ov003TmTarget {
    u8 unk_00[0x44];
    Ov003TmSub *sub;
    u8 unk_48[0x28];
    Ov003Vec pos;
};

class Ov003TmFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
};

typedef struct {
    u8 unk_00[8];
    Ov003Vec v;
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
extern void VEC_MultAdd(s32 scale, Ov003Vec *dir, Ov003Vec *src, Ov003Vec *dst);
extern void func_0203de1c(void *p);
extern void *func_0203dd9c(u32 size);
extern void func_ov000_02198328(void *p);

void func_ov003_021d8c60(Ov003Timer *self) {
    if (self->active) {
        self->active = 0;
    }
}

extern void *data_02097e4c;
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern Ov003TmFx *func_02065f88(s32 id, const Ov003Vec *pos);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_ov003_021da108(Ov003TmTarget *t, s32 a, s32 b, s32 c, s32 d);

void func_ov003_021d8c78(Ov003Timer *self) {
    BOOL fire;
    if (!self->active) {
        return;
    }
    if (!self->b1) {
        return;
    }
    fire = FALSE;
    switch (self->state) {
    case 0:
        if (self->b2 == 1) {
            self->state = 2;
        } else {
            self->state = 1;
        }
        break;
    case 1:
        if (self->timer % 20 == 0) {
            fire = TRUE;
        }
        if (self->timer >= 0x78) {
            self->timer = 0;
            self->state = 3;
        }
        self->timer++;
        break;
    case 2:
        if (self->timer % 20 == 0) {
            fire = TRUE;
        }
        self->timer++;
        break;
    case 3: {
        Ov003TmTarget *t = self->target;
        Ov003Vec p;
        Ov003TmFx *fx;
        s16 sc;
        Ov003TmSub *sub;
        p.x = t->pos.x;
        p.y = t->pos.y;
        p.z = t->pos.z;
        sub = t->sub;
        if (sub != NULL) {
            Ov003Vec o;
            o.x = sub->offset.x;
            o.y = sub->offset.y;
            o.z = sub->offset.z;
            VEC_Add(&p, &o, &p);
        }
        fx = func_02065f88(5, &p);
        sc = self->unk_06 + 0x3800;
        fx->SetScale(sc, sc, sc);
        func_0204a028(data_02097e4c, 0x56, &p, -3);
        func_ov000_0218996c(0x10, 0x5a);
        self->state = 4;
        break;
    }
    case 4:
        self->target = NULL;
        self->b1 = 0;
        break;
    }
    if (!fire) {
        return;
    }
    {
        Ov003Vec p;
        func_ov003_021da108(self->target, self->unk_06, func_02040498(1) != 0 ? 4 : 3, 0x733, 0xe66);
        p.x = self->target->pos.x;
        p.y = self->target->pos.y;
        p.z = self->target->pos.z;
        func_ov000_0218996c(8, 0xc);
        func_02049f44(data_02097e4c, 0x35, &p, 0);
    }
}

}
