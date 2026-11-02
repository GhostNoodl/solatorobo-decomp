#ifndef OV000_ACTORMGR_H
#define OV000_ACTORMGR_H

// The actor manager (data_ov000_021ccd68) and its groups, one per id group key (id & 0xf000).
// Kept apart from Actor.h so that files with their own actor prototypes can use the types.

#include "ov000/ActorBase.h"

typedef struct ActorGroup {
    struct ActorGroup *prev;
    struct ActorGroup *next;
    u16 key;
    u16 unk_0a;
    Actor *head;
    Actor *tail;
    u16 serial;
    u16 count;
    PauseNode pause;
} ActorGroup;

typedef struct ActorMgr {
    ActorGroup *head;
    ActorGroup *tail;
    u16 count;
    u16 frame;
    ActorMsg msgs[0x80];
    PauseNode pause;
} ActorMgr;

extern "C" {
extern ActorMgr *data_ov000_021ccd68;
}

#endif
