#include "ov000/Actor.h"

extern "C" {

Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);

typedef struct {
    u16 kind;
    u16 group;
    s16 unk_04[4];
    s16 unk_0c;
} SpawnDesc0219be1c;

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

Spawned0219be1c *func_ov000_0218bf1c(void *mgr, const SpawnDesc0219be1c *desc, const void *pos, const void *rot, u16 id);

void func_ov000_0219bdb0(u16 target, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    Actor *actor = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, target);
    if (actor == NULL) {
        return;
    }
    func_ov000_0218d398(actor, id, type, notify, size, data);
}

Spawned0219be1c *func_ov000_0219be1c(u16 kind, const void *pos, const void *rot, u16 a, u16 b) {
    SpawnDesc0219be1c desc;
    s32 i;
    Spawned0219be1c *o;

    desc.kind = kind;
    desc.group = kind & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.unk_0c = -1;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, pos, rot, 0xffff);
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
