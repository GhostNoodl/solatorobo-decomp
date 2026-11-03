#ifndef MAIN_LANG_TBLRES_H
#define MAIN_LANG_TBLRES_H

#include "types.h"

// The actor parameter record (0x44 bytes): func_02070558 returns the record of an actor kind
// (Actor::kind), from the table category kind >> 12. ov003's actors read it when they are built
// (Ov003Res_SetNames, the Target set-up), when they choose a target, when they are knocked back
// (the child spawn) and when they die (the drops); ov009, ov010 and ov012 read the same fields.

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TblActorPair {
    struct {
        u16 a;
        u16 b;
    } p; // ov003_021d112c.cpp copies the pair into ActorSub4c; that copy only matches with this nesting
} TblActorPair;

// Copied into the actor's Target object (ActorSub4c) by the ov003 actor set-up.
typedef struct TblActorTarget {
    /* 0x00 */ u8 type; // also stored on its own in ActorSub4c::type
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ TblActorPair unk_08;
    /* 0x0c */ u32 unk_0c;
} TblActorTarget;

// How the actor picks what to go after (ov003_021d1e8c.cpp).
typedef struct TblActorAggro {
    /* 0x00 */ u16 mode;
    /* 0x02 */ u16 ids[3]; // actor kinds it looks for (0x1003: the player)
    /* 0x08 */ u8 unk_08[2];
    /* 0x0a */ u16 unk_0a[2];
} TblActorAggro;

// The actor that is spawned when this one is knocked back or shoots; none when id is 0xffff.
typedef struct TblActorSpawn {
    /* 0x00 */ u16 id;
    /* 0x02 */ s8 arg;
} TblActorSpawn;

typedef struct TblActorParam {
    /* 0x00 */ TblActorTarget target;
    /* 0x10 */ u8 unk_10[0x18];
    /* 0x28 */ char *evName; // the event animation file (NULL: none)
    /* 0x2c */ TblActorAggro aggro;
    /* 0x3a */ TblActorSpawn spawn;
    /* 0x3e */ u16 dropIds[2]; // Drop_SpawnWeighted: item kinds and their weights
    /* 0x42 */ u8 dropRates[2];
} TblActorParam;
SIZE_ASSERT(TblActorParam, 0x44);

TblActorParam *func_02070558(s32 id);

#ifdef __cplusplus
}
#endif

#endif
