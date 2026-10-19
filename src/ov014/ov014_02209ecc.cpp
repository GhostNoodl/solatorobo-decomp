#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_ov000_021984f4(void *a, Ov014Vec *b, s32 c);

void func_ov014_02209ecc(Ov014Actor *self) {
    u16 k = FLD(u16, self, 0xb4);
    if (k != 100 && k != 110) {
        self->unk_48->unk_60 = FLD(s32, self, 0x6c) >> 1;
        self->unk_48->unk_38 = self->unk_64;
    } else {
        self->unk_48->unk_60 = 0x1000;
        self->unk_48->unk_38 = 0x1000;
    }
    func_ov000_0219864c(self->unk_48, 0, 0);
}

void func_ov014_02209f24(Ov014Actor *self) {
    Ov014Vec v;
    u16 k;
    Ov014_VecCopy(&v, &self->pos);
    k = FLD(u16, self, 0xb4);
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

extern void *data_ov000_021ccd64;
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDescB *d, Ov014Vec *pos, u16 *rot, u16 a);

void func_ov014_02209fa0(Ov014Actor *self, s16 a, s32 kind) {
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
        switch (FLD(u16, self, 0xf8) % 3) {
        case 0:
            pos.x -= func_02040528(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += func_02040528(0x1000) + 0x3000;
            rot[0] = 0;
            rot[1] = 0xe001;
            rot[2] = 0;
            break;
        case 1:
            pos.x += func_02040528(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += func_02040528(0x1000) + 0x3000;
            rot[0] = 0;
            rot[1] = 0x1fff;
            rot[2] = 0;
            break;
        case 2:
            pos.z -= func_02040528(0x1800) + 0x4000;
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
        switch (FLD(u16, self, 0xf8) % 3) {
        case 0:
            pos.x -= func_02040528(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += func_02040528(0x1000);
            rot[0] = 0;
            rot[1] = 0x1fff;
            rot[2] = 0;
            break;
        case 1:
            pos.x += func_02040528(0x1000) + 0x4000;
            pos.y = 0;
            pos.z += func_02040528(0x1000);
            rot[0] = 0;
            rot[1] = 0xe001;
            rot[2] = 0;
            break;
        case 2:
            pos.z += func_02040528(0x1800) + 0x2000;
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
        if (FLD(u16, self, 0xf8) % 2) {
            pos.x += func_02040528(0x5000);
            pos.y = 0;
            pos.z -= 0x3000 - func_02040498(0x1800);
            rot[0] = 0;
            rot[1] = 0;
            rot[2] = 0;
        } else {
            pos.x += func_02040528(0x5000);
            pos.y = 0;
            pos.z += func_02040498(0x1800) + 0x3000;
            rot[0] = 0;
            rot[1] = 0x7fff;
            rot[2] = 0;
        }
        break;
    }
    desc.unk_04[0] = a;
    desc.unk_04[1] = b;
    desc.unk_04[2] = 0x380;
    FLD(u16, self, 0xde) = 0xffff;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (FLD(void *, o, 0x4c) != NULL) {
        FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    }
    o->unk_90 = 0xffff;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    FLD(u16, self, 0xde) = o->id;
}

}
