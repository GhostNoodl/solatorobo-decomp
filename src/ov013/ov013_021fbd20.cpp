#include "ov013/ov013.h"

struct Ov013SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov013Spawn_Init(Ov013SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern char data_ov013_0220b5d0[];
extern char data_ov013_0220b5b8[];
extern Ov013Vec data_ov013_0220ae70;
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, Ov013Actor *a, s32 b);
extern void func_ov000_0219a210(Ov013Vec *v, Ov013Vec *off, u16 rot);
extern Ov013Actor *func_ov000_0218bf1c(void *mgr, Ov013SpawnDesc *d, Ov013Vec *pos, u16 *rot, u16 a);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov013_021fbd20(Ov013Actor *self) {
    Ov013Sub40 *w;
    Ov013Actor *a = Ov013_FindActor(self->unk_90);
    if (a == NULL) {
        return;
    }
    w = self->unk_40;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5d0, 0x2ab, 1);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state = 0x14;
        self->unk_40->timer = 0;
        break;
    case 0x14: {
        Ov013SpawnDesc d;
        Ov013Vec pos;
        Ov013Actor *o;
        func_ov000_0218d988(self, a, self->unk_b0->unk_02);
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        Ov013Spawn_Init(&d, 0x4820);
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        func_ov000_0219a210(&pos, &data_ov013_0220ae70, self->rot[1]);
        pos.y = 0;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &pos, self->rot, 0xffff);
        FLD(Ov013Flags8, o, 0x16).b0 = 1;
        o->unk_90 = self->unk_90;
        if (FLD(u8, self, 0xf0) != 0) {
            o->unk_9c = 0x11f;
            o->unk_a0 = 0;
            o->unk_a4 = 0;
            o->unk_a8 = 0;
        }
        if (FLD(void *, o, 0x4c) != NULL) {
            FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
        }
        FLD(u16, self, 0xde) = o->id;
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 0x63;
        self->unk_40->timer = 0;
        break;
    }
    case 0x63:
        if (FLD(u8, self, 0xf1) != 0) {
            w->timer++;
            if (w->timer > 60) {
                FLD(u8, self, 0xf1)--;
                self->unk_40->state = 0;
                self->unk_40->timer = 0;
            }
        } else {
            w->timer++;
            if (w->timer > 20) {
            FLD(u8, self, 0xf0) = 0;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
        }
        break;
    }
}
}
