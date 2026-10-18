#include "ov014/ov014.h"

struct Ov014Vec16 {
    s16 x;
    s16 y;
    s16 z;
};

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

extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern u8 data_ov014_02216cf4[];
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, Ov014Vec16 *rot, u16 a);
extern Ov014Actor *func_ov000_0219bf90(void);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);

Ov014Actor *func_ov014_02210c5c(Ov014Actor *self) {
    Ov014Vec pos;
    Ov014Vec16 rot;
    Ov014SpawnDesc desc;
    Ov014Actor *o;
    pos.x = FLD(s32, self, 0x118);
    pos.y = FLD(s32, self, 0x11c);
    pos.z = FLD(s32, self, 0x120);
    switch ((FLD(s32, self, 0x144) + FLD(u16, self, 0x14c)) % 4) {
    case 0:
        pos.x = FLD(s32, self, 0x118) + 0x6000;
        break;
    case 1:
        pos.x = FLD(s32, self, 0x118) - 0x6000;
        break;
    case 2:
        pos.x = FLD(s32, self, 0x118) + 0x4000;
        pos.y = FLD(s32, self, 0x11c) + 0x1000;
        break;
    case 3:
        pos.x = FLD(s32, self, 0x118) - 0x4000;
        pos.y = FLD(s32, self, 0x11c) + 0x1000;
        break;
    }
    rot.x = self->rot[0];
    rot.y = self->rot[1];
    rot.z = self->rot[2];
    Ov014Spawn_Init(&desc, 0x4814);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    o->unk_90 = func_ov000_0219bf90()->id;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    FLD(u16, self, 0xde) = o->id;
    return o;
}

Ov014Actor *func_ov014_02210d9c(Ov014Actor *self) {
    Ov014SpawnDesc desc;
    Ov014Vec pos;
    Ov014Vec16 rot;
    Ov014Actor *o;
    u16 id = FLD(u16, self, 0xde);
    if (data_ov000_021ccd68 == NULL) {
        o = NULL;
    } else {
        o = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    if (o != NULL) {
        return NULL;
    }
    Ov014Spawn_Init(&desc, 0x4806);
    pos.x = FLD(s32, self, 0x118);
    pos.y = FLD(s32, self, 0x11c);
    pos.z = FLD(s32, self, 0x120) + 0x2000;
    pos.y -= 0x1000;
    rot.x = self->rot[0];
    rot.y = self->rot[1];
    rot.z = self->rot[2];
    rot.x = 0x2c00;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return NULL;
    }
    o->unk_90 = self->unk_90;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    FLD(void *, o, 0x60) = data_ov014_02216cf4;
    FLD(u16, self, 0xde) = o->id;
    return o;
}

}
