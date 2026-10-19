#include "ov009/ov009.h"

struct Ov009SpawnDesc2 {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Flag8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
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
extern u8 data_ov009_02215e9c[];
extern Ov009Actor *func_ov000_0218bf1c(void *mgr, Ov009SpawnDesc2 *d, Ov009Vec *pos, Ov009Rot16 *rot, u16 a);

void func_ov009_0220387c(Ov009Actor *self) {
    Ov009SpawnDesc2 desc;
    Ov009Vec p;
    Ov009Actor *o;
    u8 *tmpl = data_ov009_02215e9c;
    Ov009Spawn_Init(&desc, 0x483c);
    {
        s32 z;
        p.x = self->pos.x;
        p.y = self->pos.y;
        z = self->pos.z;
        p.y += 0x4e66;
        p.z = z;
    }
    Ov009Rot16 r = *(Ov009Rot16 *)self->rot;
    r.x = 0x1c70;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &p, &r, 0xffff);
    if (o == NULL) {
        return;
    }
    FLD(void *, o, 0x60) = tmpl;
    FLD(u16, o, 0x90) = FLD(u16, self, 0x90);
    if (FLD(void *, o, 0x4c) != NULL) {
        FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    }
    FLD(u16, self, 0xde) = o->id;
    ((Ov009Flag8 *)((u8 *)o + 0x16))->b0 = 1;
}

}
