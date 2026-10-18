#ifndef OV000_CMDOBJ_H
#define OV000_CMDOBJ_H

#include "types.h"

// Script command runner shared by the overlay 0 event commands: a step counter, a
// 16-entry (kind, arg) ring and a pointer-to-member callback that is cleared with
// __ptmf_null when a command finishes.
class CmdObj;
typedef s32 (CmdObj::*CmdPmf)();

class CmdObj {
public:
    s32 state;
    u16 step;
    u8 pad_06[0xa];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 rd;
    s32 index;
    s32 unk_98;
    CmdPmf unk_9c;
    u16 unk_a4;
    u16 unk_a6;
    u16 unk_a8;
};

static inline void CmdObj_Done(CmdObj *self) {
    self->unk_9c = NULL;
    self->unk_98 = 0;
    self->unk_a4 = 0;
    self->unk_a6 = 0;
    self->unk_a8 = 0;
    self->kinds[self->rd] = 0;
    self->args[self->rd] = 0;
    if (++self->rd >= 0x10) {
        self->rd = 0;
    }
    self->state = 5;
}

static inline void CmdObj_Push(CmdObj *self, s32 kind, s32 arg) {
    self->kinds[self->index] = kind;
    self->args[self->index] = arg;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

#endif
