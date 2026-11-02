#include "types.h"
#include "nitro/fx.h"
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

extern u32 data_ov003_021f7cf4;
extern u32 data_ov003_021f7cd8;
extern s16 Ov003Ticker_GetValue(Ov003Ticker *t);
extern void Heap_Free(void *p);
extern void *Heap_Alloc(u32 size);
extern void *History_Init(void *p);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);

void Ov003_ClearWords4(u32 *p) {
    u32 i;
    if (p == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p[i] = 0;
    }
}

Ov003StateMachine *Ov003Vt_021f7cf4_Ctor(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->active = 0;
    return self;
}

Ov003StateMachine *Ov003Vt_021f7cf4_Dtor(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->Release();
    return self;
}

Ov003StateMachine *Ov003Vt_021f7cf4_DtorDelete(Ov003StateMachine *self) {
    *(void **)self = &data_ov003_021f7cf4;
    self->Release();
    Heap_Free(self);
    return self;
}

BOOL Ov003StateMachine_Init(Ov003StateMachine *self) {
    self->active = 1;
    self->cur = NULL;
    self->list = NULL;
    return TRUE;
}

void Ov003StateMachine_Stop(Ov003StateMachine *self) {
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
                Heap_Free(n);
            }
        }
        self->cur = NULL;
        self->list = NULL;
    }
    self->active = 0;
}

void Ov003StateMachine_Update(Ov003StateMachine *self) {
    if (self->active && self->cur != NULL) {
        self->cur->state->Update();
    }
}

void Ov003StateMachine_AddState(Ov003StateMachine *self, u8 id, Ov003State *state) {
    Ov003StateNode *n;
    Ov003StateNode *head;
    if (!self->active) {
        return;
    }
    n = (Ov003StateNode *)Heap_Alloc(sizeof(Ov003StateNode));
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

void Ov003StateMachine_ChangeState(Ov003StateMachine *self, u8 id) {
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

void Ov003StateMachine_Leave(Ov003StateMachine *self) {
    if (self->active && self->cur != NULL) {
        self->cur->state->Leave();
        self->cur = NULL;
    }
}

BOOL Ov003StateMachine_IsState(Ov003StateMachine *self, u8 id) {
    BOOL r = FALSE;
    if (self->active && self->cur != NULL) {
        if (self->cur->id == id) {
            r = TRUE;
        }
    }
    return r;
}

void Ov003StateMachine_SendMessage(Ov003StateMachine *self, void *arg) {
    if (arg != NULL && self->cur != NULL) {
        self->cur->state->Message(arg);
    }
}

Ov003Timer *Ov003Vt_021f7cd8_Ctor(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->active = 0;
    History_Init(self->unk_0c);
    return self;
}

Ov003Timer *Ov003Vt_021f7cd8_Dtor(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->Release();
    return self;
}

Ov003Timer *Ov003Vt_021f7cd8_DtorDelete(Ov003Timer *self) {
    *(void **)self = &data_ov003_021f7cd8;
    self->Release();
    Heap_Free(self);
    return self;
}

BOOL Ov003Timer_Init(Ov003Timer *self) {
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
