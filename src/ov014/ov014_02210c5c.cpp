#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern u8 data_ov014_02216cf4[];
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, VecFx32 *pos, Ov014Vec16 *rot, u16 a);
extern Ov003Actor *func_ov000_0219bf90(void);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

Ov003Actor *func_ov014_02210c5c(Ov014Act_0220f9d0 *self) {
    VecFx32 pos;
    Ov014Vec16 rot;
    Ov014SpawnDesc desc;
    Ov003Actor *o;
    pos.x = self->unk_f0.trans.x;
    pos.y = self->unk_f0.trans.y;
    pos.z = self->unk_f0.trans.z;
    switch ((self->unk_144 + self->unk_14c) % 4) {
    case 0:
        pos.x = self->unk_f0.trans.x + 0x6000;
        break;
    case 1:
        pos.x = self->unk_f0.trans.x - 0x6000;
        break;
    case 2:
        pos.x = self->unk_f0.trans.x + 0x4000;
        pos.y = self->unk_f0.trans.y + 0x1000;
        break;
    case 3:
        pos.x = self->unk_f0.trans.x - 0x4000;
        pos.y = self->unk_f0.trans.y + 0x1000;
        break;
    }
    rot.x = self->rot_x;
    rot.y = self->rot_y;
    rot.z = self->rot_z;
    Ov014Spawn_Init(&desc, 0x4814);
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    o->target = func_ov000_0219bf90()->id;
    o->flags_0 = 1;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
    self->target_id = o->id;
    return o;
}

Ov003Actor *func_ov014_02210d9c(Ov014Act_0220f9d0 *self) {
    Ov014SpawnDesc desc;
    VecFx32 pos;
    Ov014Vec16 rot;
    Ov003Actor *o;
    u16 id = self->target_id;
    if (data_ov000_021ccd68 == NULL) {
        o = NULL;
    } else {
        o = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    if (o != NULL) {
        return NULL;
    }
    Ov014Spawn_Init(&desc, 0x4806);
    pos.x = self->unk_f0.trans.x;
    pos.y = self->unk_f0.trans.y;
    pos.z = self->unk_f0.trans.z + 0x2000;
    pos.y -= 0x1000;
    rot.x = self->rot_x;
    rot.y = self->rot_y;
    rot.z = self->rot_z;
    rot.x = 0x2c00;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return NULL;
    }
    o->target = self->target;
    o->flags_0 = 1;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
    o->unk_60 = data_ov014_02216cf4;
    self->target_id = o->id;
    return o;
}

}
