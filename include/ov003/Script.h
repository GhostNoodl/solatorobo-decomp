#ifndef OV003_SCRIPT_H
#define OV003_SCRIPT_H

// The ov003 behaviour script list (Ov003ScriptList_Init, vtable data_ov003_021f7974, 0x1c bytes),
// embedded in the actors that pick their next move from a table: tracks of steps added with
// Ov003ScriptList_AddTrack, chosen by id with Ov003ScriptList_SelectTrack and stepped by Ov003ScriptList_Step.

#include "types.h"

// One step of a track. A negative op is a jump that the stepper resolves with the chance
// (out of 0x1000) and a/b; the others are returned to the actor, which reads the rest its own way.
struct Ov003Step {
    s16 op;
    union {
        s16 chance;
        u16 time; // how long a plain step lasts
    };
    u16 a;
    u16 b;
};

// A track (vtable data_ov003_021f7984, 0x14 bytes, built by Ov003ScriptList_AddTrack): val is the
// current step, wrapping at max.
class Ov003Track {
public:
    virtual void v00();
    virtual void Delete();
    u16 id;
    u16 max;
    u16 val;
    u16 unk_0a;
    const Ov003Step *steps;
    Ov003Track *next;
};

struct Ov003ScriptList;
typedef void (*Ov003ScriptFunc)(Ov003ScriptList *self, void *arg);

struct Ov003ScriptList {
    void *vtbl;
    Ov003Track *head;
    u16 count;
    u16 unk_0a;
    Ov003Track *cur;
    Ov003ScriptFunc func; // called with arg before each step
    void *arg;
    u8 enabled;
};

extern "C" {
void Ov003ScriptList_Init(Ov003ScriptList *self);
Ov003ScriptList *Ov003Vt_021f7974_Dtor(Ov003ScriptList *self);
Ov003ScriptList *Ov003Vt_021f7974_DtorDelete(Ov003ScriptList *self);
const Ov003Step *Ov003ScriptList_Step(Ov003ScriptList *self);
void Ov003ScriptList_AddTrack(Ov003ScriptList *self, u16 id, u16 max, const Ov003Step *steps);
Ov003Track *Ov003ScriptList_SelectTrack(Ov003ScriptList *self, u16 id, u16 val);
}

#endif
