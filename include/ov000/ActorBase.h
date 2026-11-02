#ifndef OV000_ACTORBASE_H
#define OV000_ACTORBASE_H

// The ov000 actor base class (ctor Actor_Ctor, vtable data_ov000_021cc3b4,
// 0xac bytes) and the small types its members use. Kept apart from Actor.h so that
// headers with layouts can derive from Actor without Actor.h's prototypes.

#include "types.h"
#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/ActorParts.h"
#include "ov000/Model0218fe1c.h"

// Payload of a hit message (ActorMsg type 9, applied by func_ov003_021d6548).
typedef struct ActorMsgHit {
    u16 dmg;
    u8 kind;
} ActorMsgHit;

typedef struct ActorMsg {
    struct ActorMsg *next;
    u8 unk_04;
    u8 type;
    u16 id; // sender
    union {
        u8 data[0x30];
        ActorMsgHit hit; // type 9
        struct {
            u8 unk_08;
            u8 unk_09;
            s16 unk_0a;
            u16 unk_0c;
        };
    };
} ActorMsg;

class Actor;

typedef struct PauseNode {
    struct PauseNode *parent;
    u32 unk_04;
} PauseNode;

// The Target object at Actor::targetObj (ctor func_ov000_02199b00, Target_02199b00.c, 0x5c bytes).
typedef struct {
    u8 type;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    char *unk_0c;
    u16 kinds[2];
    u16 ids[2];
    union {
        u8 unk_18;
        struct {
            u8 unk_18_0 : 1;
            u8 unk_18_1 : 1;
            u8 unk_18_2 : 3;
            u8 unk_18_5 : 1;
            u8 unk_18_6 : 2;
        };
    };
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    u16 target; // id of the targeted actor (Target_Set / Target_Get)
    u16 unk_1e;
    u8 unk_20[0x24];
    VecFx32 dest;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
} ActorSub4c;
SIZE_ASSERT(ActorSub4c, 0x5c);

// The actor's shadow (Actor::unk_3c, 0x1c bytes, built by func_ov000_021919c8 and placed with
// func_ov000_02191c24 / 02191ec4); deleted through vfunc_04.
class ActorShadow : public VObj {
public:
    u8 unk_04[0x8];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    union {
        u8 unk_18;
        struct {
            u8 unk_18_0 : 4; // the ov003 actor ctor pushes its value into unk_18_4 before setting it
            u8 unk_18_4 : 4;
        };
    };
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
};

class Actor : public VObj {
public:
    Actor *prev;
    Actor *next;
    u16 id;
    u16 kind;
    s32 unk_10;
    u8 state;
    u8 mode; // update mode: Actor_Tick calls vfunc_34 / 2c / 30 for 1 / 2 / 3 (the ctor sets 2)
    union {
        u8 unk_16; // read and written whole in some ov012/ov014 actors
        struct {
            u8 flags_0 : 1;
            u8 flags_1 : 1;
            u8 flags_2 : 6;
        };
    };
    u8 unk_17;
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    s16 unk_22;
    PauseNode pause;
    ActorMsg *msgs;
    u32 msg_flags;
    void *unk_34; // resource names (0x138 bytes, ctor func_ov000_0218e9c4; filled by func_ov003_021d0a2c)
    Model0218fe1c *model;
    ActorShadow *unk_3c;
    ActorSub40 *fsm; // state block (func_ov000_02198360 switches state)
    ActorSub44 *unk_44;
    ActorSub48 *hit; // collision sphere (a HitSphere: func_0203f260, HitSphere_Link)
    ActorSub4c *targetObj; // Target object (Target_Get / Target_Set)
    union {
        u16 *hp; // hp gauge (hp[0], hp[1]; ov011 Ov011Obj::hp)
        ActorHp *hpObj; // the same block with its fields
    };
    void *unk_54;
    void *hitMesh; // HitMesh (HitMesh_Link / func_0203f920)
    void *unk_5c;
    void *unk_60;
    s32 radius; // horizontal size (spawn info hx << 4; ActorMgr_FindKindNear adds it to the distance)
    s32 height; // vertical size (spawn info hy << 4)
    s32 centerY; // height of the body centre above pos (height / 2 for the robot)
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
    union {
        u8 unk_94;
        struct {
            u8 unk_94_0 : 1;
            u8 unk_94_1 : 2;
            u8 unk_94_3 : 5;
        };
    };
    u8 unk_95;
    u16 unk_96;
    u16 moveYaw; // heading Actor_Move moves along (Actor_MoveToPos aims it at the target)
    u16 unk_9a;
    s32 speed; // horizontal speed along moveYaw (Actor_Move)
    s32 velY; // vertical velocity, added to pos.y by Actor_Move
    s32 friction; // speed multiplier per frame (0 or 0x1000: none)
    s32 gravity; // subtracted from velY each frame (velY floor -0x800); 0: no gravity
};

SIZE_ASSERT(Actor, 0xac);

#endif
