#include "ov000/Actor.h"
#include "ov000/Group.h"

extern "C" {

Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);


typedef struct {
    u8 pad_00[0x1c];
    u16 unk_1c;
} SpawnSub0219be1c;

typedef struct {
    u8 pad_00[0x16];
    u8 unk_16_0 : 1;
    u8 unk_16_1 : 7;
    u8 pad_17[0x4c - 0x17];
    SpawnSub0219be1c *unk_4c;
    u8 pad_50[0x90 - 0x50];
    u16 unk_90;
} Spawned0219be1c;

Spawned0219be1c *Group_SpawnActor(void *mgr, const GroupActorDesc *desc, const void *pos, const void *rot, u16 id);

void ActorMgr_SendMsg(u16 target, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    Actor *actor = data_ov000_021ccd68 == NULL ? NULL : ActorMgr_GetActor(data_ov000_021ccd68, target);
    if (actor == NULL) {
        return;
    }
    Actor_SendMsg(actor, id, type, notify, size, data);
}

Spawned0219be1c *Actor_SpawnKind(u16 kind, const void *pos, const void *rot, u16 a, u16 b) {
    GroupActorDesc desc;
    s32 i;
    Spawned0219be1c *o;

    desc.kind = kind;
    desc.group = kind & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.args[i] = 0;
    }
    desc.unk_0c = -1;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, pos, rot, 0xffff);
    if (o != NULL) {
        o->unk_16_0 = 1;
        o->unk_90 = b;
        if (o->unk_4c != NULL) {
            o->unk_4c->unk_1c = a;
        }
    }
    return o;
}

}
