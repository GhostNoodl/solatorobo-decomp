#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov000_021984f4(void *a, Ov014Vec *b, s32 c);

void func_ov014_02209ecc(Ov014Act_02209280 *self) {
    u16 k = self->unk_b4;
    if (k != 100 && k != 110) {
        self->unk_48->unk_60 = self->unk_6c >> 1;
        self->unk_48->unk_38 = self->unk_64;
    } else {
        self->unk_48->unk_60 = 0x1000;
        self->unk_48->unk_38 = 0x1000;
    }
    func_ov000_0219864c(self->unk_48, 0, 0);
}

void func_ov014_02209f24(Ov014Act_02209280 *self) {
    Ov014Vec v;
    u16 k;
    Ov014_VecCopy(&v, &self->pos);
    k = self->unk_b4;
    if (k != 100 && k != 110) {
        v.y += 0x5000;
        v.z += 0x2000;
        func_ov000_021984f4(self->unk_44, &v, 0);
    } else {
        v.y += 0x1000;
        func_ov000_021984f4(self->unk_44, &v, 0);
    }
}


struct Ov014SpawnDescB {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnB_Init(Ov014SpawnDescB *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDescB *d, Ov014Vec *pos, u16 *rot, u16 a);

void func_ov014_02209fa0(Ov014Act_02209280 *self, s16 a, s32 kind) {
    Ov014SpawnDescB desc;
    Ov014Vec pos;
    u16 rot[3];
    u16 b;
    Ov014Actor *o;
    Ov014SpawnB_Init(&desc, 0x481e);
    switch (kind) {
    case 5:
        pos.x = 0;
        pos.y = 0;
        pos.z = 0x8000;
        b = 0x24d;
        switch (self->unk_f8 % 3) {
        case 0:
            pos.x -= Rand_PlusMinus(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += Rand_PlusMinus(0x1000) + 0x3000;
            rot[0] = 0;
            rot[1] = 0xe001;
            rot[2] = 0;
            break;
        case 1:
            pos.x += Rand_PlusMinus(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += Rand_PlusMinus(0x1000) + 0x3000;
            rot[0] = 0;
            rot[1] = 0x1fff;
            rot[2] = 0;
            break;
        case 2:
            pos.z -= Rand_PlusMinus(0x1800) + 0x4000;
            rot[0] = 0;
            rot[1] = 0;
            rot[2] = 0;
            break;
        }
        break;
    case 6:
        pos.x = 0;
        pos.y = 0;
        pos.z = 0x8000;
        b = 0x29a;
        switch (self->unk_f8 % 3) {
        case 0:
            pos.x -= Rand_PlusMinus(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += Rand_PlusMinus(0x1000);
            rot[0] = 0;
            rot[1] = 0x1fff;
            rot[2] = 0;
            break;
        case 1:
            pos.x += Rand_PlusMinus(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += Rand_PlusMinus(0x1000);
            rot[0] = 0;
            rot[1] = 0xe001;
            rot[2] = 0;
            break;
        case 2:
            pos.z += Rand_PlusMinus(0x1800) + 0x2000;
            rot[0] = 0;
            rot[1] = 0;
            rot[2] = 0;
            break;
        }
        break;
    case 7:
        pos.x = 0;
        pos.y = 0;
        pos.z = 0x8000;
        b = 0x200;
        if (self->unk_f8 % 2) {
            pos.x += Rand_PlusMinus(0x5000);
            pos.y = 0;
            pos.z -= 0x3000 - Rand_UpTo(0x1800);
            rot[0] = 0;
            rot[1] = 0;
            rot[2] = 0;
        } else {
            pos.x += Rand_PlusMinus(0x5000);
            pos.y = 0;
            pos.z += Rand_UpTo(0x1800) + 0x3000;
            rot[0] = 0;
            rot[1] = 0x7fff;
            rot[2] = 0;
        }
        break;
    }
    desc.unk_04[0] = a;
    desc.unk_04[1] = b;
    desc.unk_04[2] = 0x380;
    self->target_id = 0xffff;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &pos, rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
    o->unk_90 = 0xffff;
    o->flags_0 = 1;
    self->target_id = o->id;
}

}
