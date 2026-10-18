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
    u32 unk_08;
    u8 unk_0c[4];
    u32 unk_10;
    u32 unk_14;
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
extern void func_02012fb8(s32 scale, Ov003Vec *dir, Ov003Vec *src, Ov003Vec *dst);
extern void func_0203de1c(void *p);
extern void *func_0203dd9c(u32 size);
extern void func_ov000_02198328(void *p);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

void func_ov003_021d88ec(u32 *p) {
    u32 i;
    if (p == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p[i] = 0;
    }
}

Ov003StateMachine *func_ov003_021d8910(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->active = 0;
    return self;
}

Ov003StateMachine *func_ov003_021d8928(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->Release();
    return self;
}

Ov003StateMachine *func_ov003_021d8950(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->Release();
    func_0203de1c(self);
    return self;
}

BOOL func_ov003_021d8980(Ov003StateMachine *self) {
    self->active = 1;
    self->cur = NULL;
    self->list = NULL;
    return TRUE;
}

void func_ov003_021d899c(Ov003StateMachine *self) {
    Ov003StateNode *n;
    Ov003StateNode *next;
    if (!self->active) {
        return;
    }
    if (self->active) {
        for (n = self->list; n != NULL; n = next) {
            next = n->next;
            n->state->Leave();
            if (n != NULL) {
                func_0203de1c(n);
            }
        }
        self->cur = NULL;
        self->list = NULL;
    }
    self->active = 0;
}

void func_ov003_021d8a04(Ov003StateMachine *self) {
    if (self->active && self->cur != NULL) {
        self->cur->state->Update();
    }
}

void func_ov003_021d8a30(Ov003StateMachine *self, u8 id, Ov003State *state) {
    Ov003StateNode *n;
    Ov003StateNode *head;
    if (!self->active) {
        return;
    }
    n = (Ov003StateNode *)func_0203dd9c(sizeof(Ov003StateNode));
    n->id = id;
    n->state = state;
    n->next = NULL;
    head = self->list;
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    self->list = head;
}

void func_ov003_021d8a7c(Ov003StateMachine *self, u8 id) {
    Ov003StateNode *n;
    if (!self->active) {
        return;
    }
    n = Ov003StateMachine_Find(self, id);
    if (n == NULL) {
        return;
    }
    if (self->cur != NULL) {
        self->cur->state->Leave();
        self->cur = NULL;
    }
    self->cur = n;
    n->state->Enter();
}

void func_ov003_021d8afc(Ov003StateMachine *self) {
    if (self->active && self->cur != NULL) {
        self->cur->state->Leave();
        self->cur = NULL;
    }
}

BOOL func_ov003_021d8b34(Ov003StateMachine *self, u8 id) {
    BOOL r = FALSE;
    if (self->active && self->cur != NULL) {
        if (self->cur->id == id) {
            r = TRUE;
        }
    }
    return r;
}

void func_ov003_021d8b60(Ov003StateMachine *self, void *arg) {
    if (arg != NULL && self->cur != NULL) {
        self->cur->state->Message(arg);
    }
}

Ov003Timer *func_ov003_021d8b88(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->active = 0;
    func_ov000_02198328(self->unk_0c);
    return self;
}

Ov003Timer *func_ov003_021d8bb8(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->Release();
    return self;
}

Ov003Timer *func_ov003_021d8be0(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->Release();
    func_0203de1c(self);
    return self;
}

BOOL func_ov003_021d8c10(Ov003Timer *self) {
    self->active = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    func_ov000_02198360(self->unk_0c, 0, 1);
    return TRUE;
}

}
