#ifndef OV000_GROUP_H
#define OV000_GROUP_H

// The spawn groups (data_ov000_021ccd64, a Group of 0x48 bytes built by Group_Init_0218bb34).
// Each GroupNode (0xa4 bytes, ctor func_ov000_0218a9d8, made by func_ov000_0218b9ec) spawns its
// actor from `spawn` (Group_SpawnActor) once one of the views the field camera registered this
// frame (Group_AddCamView) is inside its spawn volume (func_ov000_0218adf0), and removes the
// actor again once every view has left its despawn volume (func_ov000_0218af9c). The spawned
// actors are recorded in `entries` (GroupNode_UpdateEntry).

#include "types.h"
#include "nitro/fx.h"
#include "Main/Math/Rot16.h"
#include "Main/Sys/FieldId.h"

// What Group_SpawnActor builds an actor from; the class is kind & 0xf000.
typedef struct GroupActorDesc {
    u16 kind;
    u16 group; // the actor manager group, kind & 0xf000
    s16 args[4]; // copied to Actor::unk_18 .. unk_1e
    s16 unk_0c; // copied to Actor::unk_22
} GroupActorDesc;

// A spawned actor's record: its kind and id (only the id's group key, id & 0xf000, once it is
// gone), its args, and where and in which field it was when it went (GroupNode_UpdateEntry).
typedef struct GroupEntry {
    u16 kind;
    u16 actor;
    s16 args[4];
    s16 unk_0c;
    FieldId fieldId;
    u8 unk_11;
    Rot16 rot;
    VecFx32 pos;
} GroupEntry;

// A camera view (Group_AddCamView: the eye and FieldCam_GetYaw), the segment HitVolume_TestSegment tests.
typedef struct GroupView {
    VecFx32 from;
    VecFx32 to;
    u16 yaw;
} GroupView;

typedef struct GroupNodeFlags {
    u8 unk_0 : 1;
    u8 useRange : 1;
    u8 useHeight : 1; // without it the spawn volume has no height limit (func_ov000_0218b420)
    u8 useAngle : 1; // the despawn range shrinks with the view's angle to the actor
    u8 toGround : 1; // the spawn position is moved down onto the ground (Geom_SnapToGround)
    u8 unk_5 : 1; // GroupNode_UpdateEntry keeps the entry's position and field
    u8 unk_6 : 1;
    u8 unk_7 : 1;
} GroupNodeFlags;

typedef struct GroupNode {
    struct GroupNode *prev;
    struct GroupNode *next;
    u16 id; // given by Group_Add; spawned actors keep it in Actor::unk_20
    u8 state; // 1 wait for a view, 2 spawned, 3 wait unk_9a seconds
    u8 count; // entries in use
    GroupEntry entries[1];
    GroupActorDesc spawn;
    FieldId fieldId; // the field the node spawns in (compared with FieldState::unk_ca)
    FieldId fieldFilter; // 0xff: any; GroupNode_Refresh drops the node once the field differs
    VecFx32 spawnMin; // the spawn volume around pos (HitVolume_TestSegment)
    VecFx32 spawnMax;
    VecFx32 despawnMin; // the volume the actor must leave to be removed (func_ov000_0218af9c)
    VecFx32 despawnMax;
    // The volumes are rebuilt from these by func_ov000_0218b420 and scaled by GroupNode_SetSpawnRange.
    fx32 spawnRange; // the spawn volume's half width, and the range from a view when useRange is set
    fx32 despawnRange;
    fx32 spawnHeight;
    fx32 despawnHeight;
    fx32 fadeStart; // the actor fades out from this distance to the camera up to spawnRange (ActorEx_Draw)
    VecFx32 pos;
    Rot16 rot;
    u16 unk_9a; // seconds to wait in state 3
    u32 timer; // frames waited in state 3
    s8 spawned; // times the actor was spawned
    s8 maxSpawns; // < 0: no limit
    union {
        u8 unk_a2;
        GroupNodeFlags flags;
    };
    u8 unk_a3; // given to the spawned actor's Actor::unk_17 unless 0xff
} GroupNode;

typedef struct Group {
    GroupNode *head;
    GroupNode *tail;
    u16 serial;
    u16 count;
    union {
        u8 raw;
        struct {
            u8 flag_0 : 1; // nodes are updated (func_ov000_0218be54)
            u8 flag_1 : 1;
            u8 flag_2 : 6;
        } bits;
    } unk_0c;
    u8 viewCount;
    u8 unk_0e[2];
    VecFx32 viewPos[4];
    u16 viewYaw[4];
} Group;

#ifdef __cplusplus
extern "C" {
#endif

GroupNode *func_ov000_0218a9d8(GroupNode *self);
GroupNode *func_ov000_0218b9ec(GroupActorDesc *desc, const FieldId *fieldId, const FieldId *fieldFilter, VecFx32 *pos, Rot16 *rot);
void func_ov000_0218b420(GroupNode *self);
void func_ov000_0218b60c(GroupNode *self, const FieldId *fieldId, const VecFx32 *pos, const Rot16 *rot);
void GroupNode_SetSpawnRange(GroupNode *self, s32 scaleXZ, s32 scaleY);
void func_ov000_0218b7c0(GroupNode *self, s32 kind, s32 mode);
void GroupNode_Refresh(GroupNode *self);
void func_ov000_0218ac98(GroupNode *self);
void func_ov000_0218adf0(GroupNode *self);
void Group_Add(Group *g, GroupNode *node);
s32 Group_GetSpawnPositions(Group *g, s32 max, VecFx32 *out, s32 kind, u16 id);
void Obj0218c208_AddPoint(Group *self, const VecFx32 *pos, u16 yaw);
void Group_AddCamView(Group *self);
void Group_RemoveNode(Group *g, GroupNode *node, BOOL notify);
BOOL HitVolume_TestSegment(GroupNode *node, GroupView *view);
s32 Geom_SnapToGround(VecFx32 *pos, s32 up, s32 down);

#ifdef __cplusplus
}
#endif

#endif
