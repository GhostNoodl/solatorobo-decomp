#ifndef OV000_ACTORBASE_H
#define OV000_ACTORBASE_H

// The ov000 actor base class (ctor Actor_Ctor, vtable data_ov000_021cc3b4,
// 0xac bytes) and the small types its members use. Kept apart from Actor.h so that
// headers with layouts can derive from Actor without Actor.h's prototypes.

#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ActorParts.h"

typedef struct ActorMsg {
    struct ActorMsg *next;
    u8 unk_04;
    u8 type;
    u16 id;
    u8 data[0x30];
} ActorMsg;

class Actor;

typedef struct PauseNode {
    struct PauseNode *parent;
    u32 unk_04;
} PauseNode;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0x8];
    char *unk_0c;
    u8 unk_10[0x9];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 unk_1c;
} ActorSub4c;

class Actor : public VObj {
public:
    Actor *prev;
    Actor *next;
    u16 id;
    u16 kind;
    s32 unk_10;
    u8 state;
    u8 unk_15;
    u8 flags_0 : 1;
    u8 flags_1 : 1;
    u8 flags_2 : 6;
    u8 unk_17;
    u16 unk_18[4];
    u16 unk_20;
    s16 unk_22;
    PauseNode pause;
    ActorMsg *msgs;
    u32 msg_flags;
    s32 unk_34;
    void *unk_38;
    u8 *unk_3c;
    ActorSub40 *unk_40;
    u8 *unk_44;
    ActorSub48 *unk_48;
    ActorSub4c *unk_4c;
    u16 *hp; // hp gauge (hp[0], hp[1]; ov011 Ov011Obj::hp)
    void *unk_54;
    void *unk_58;
    void *unk_5c;
    void *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[0x2];
    VecFx32 unk_84;
    u16 target;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_93_4 : 1;
    u8 unk_93_5 : 2;
    u8 unk_93_7_f : 1;
    u8 unk_94;
    u8 unk_95;
    u16 unk_96;
    u16 unk_98;
    u16 unk_9a;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

SIZE_ASSERT(Actor, 0xac);

#endif
