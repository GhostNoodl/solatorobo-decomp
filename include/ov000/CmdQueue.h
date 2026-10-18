#ifndef OV000_CMDQUEUE_H
#define OV000_CMDQUEUE_H

#include "types.h"

// Ring buffer of 16 (kind, arg) commands, shared by several overlay 0 controllers.
typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
} CmdQueue;

static inline void CmdQueue_Push(CmdQueue *q, s32 kind, s32 arg) {
    q->kinds[q->index] = kind;
    q->args[q->index] = arg;
    if (++q->index >= 0x10) {
        q->index = 0;
    }
}

#endif
