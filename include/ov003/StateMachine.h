#ifndef OV003_STATEMACHINE_H
#define OV003_STATEMACHINE_H

// The state machine of the ov003 script objects (021d85c8, 021d88ec, 021d8c60, 021f77d8):
// a list of states by id, each with enter / leave / update / message methods.

#include "types.h"

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

#endif
