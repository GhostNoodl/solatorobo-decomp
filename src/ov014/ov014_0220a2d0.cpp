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
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, Ov014Vec16 *rot, u16 a);

void func_ov014_0220a2d0(Ov014Actor *self, u16 a) {
    Ov014Vec v;
    s32 spd;
    u16 ang;
    Ov014Vec pos;
    Ov014SpawnDesc desc;
    Ov014Vec16 rot;
    Ov014Actor *o;
    s32 base;
    pos.x = 0;
    pos.y = 0x5000;
    pos.z = 0x2000;
    pos.x = func_02040528(0x6000);
    pos.x += pos.x > 0 ? 0x3000 : -0x3000;
    pos.z += func_02040498(0x1000);
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    base = pos.x > 0 ? 0xc000 : 0x4000;
    if (FLD(u16, self, 0xf8) % 2 != 0) {
        ang = base + (u16)func_02040498(0x4000);
    } else {
        ang = base - (u16)func_02040498(0x4000);
    }
    spd = func_02040498(0x3800) + 0x3800;
    v.x = Ov014_FxMul(spd, OV014_SIN(ang));
    v.z = Ov014_FxMul(spd, OV014_COS(ang)) + 0x8000;
    Ov014Spawn_Init(&desc, 0x481d);
    desc.unk_04[0] = a;
    FLD(u16, self, 0xde) = 0xffff;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    o->unk_84.x = v.x;
    o->unk_84.y = 0;
    o->unk_84.z = v.z;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    FLD(u16, self, 0xde) = o->id;
}

void func_ov014_0220a490(Ov014Actor *self, Ov014Vec *vel, u16 a, u16 b, u16 c) {
    Ov014SpawnDesc desc;
    Ov014Vec pos;
    Ov014Vec16 rot;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0x4819);
    desc.unk_04[0] = a;
    desc.unk_04[1] = b;
    desc.unk_04[2] = c;
    desc.parent = -1;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    FLD(u16, self, 0xde) = 0xffff;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    if (o == NULL) {
        return;
    }
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    if (vel != NULL) {
        s32 x = vel->x; s32 y = vel->y; o->unk_84.x = x; s32 z = vel->z; o->unk_84.y = y; o->unk_84.z = z;
    } else {
        o->unk_90 = self->unk_90;
    }
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    FLD(u16, self, 0xde) = o->id;
}


extern u8 data_ov014_02217a48[];
extern u8 data_ov014_02217a4e[];
extern u8 data_ov014_02217a54[];
extern void func_ov000_021911c8(void *a, s32 b);
extern BOOL func_02049244(Ov014Vec *out, s32 speed, const Ov014Vec *from, const Ov014Vec *to, s32 minDist);

void func_ov014_0220a588(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        const void *anim;
        anim = data_ov014_02217a48;
        if (FLD(u8, self, 0x1a5) == 0) {
            anim = data_ov014_02217a4e;
        }
        if (self->unk_ee_0) {
            anim = data_ov014_02217a54;
        }
        func_ov000_02190cb0(self->unk_38, anim, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0xc00);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    if (FLD(u8, self, 0x1a5) == 0) {
        func_02049244(&self->pos, 0xcd, &self->pos, (Ov014Vec *)((u8 *)self + 0x1a8), 0xcd);
    } else if (self->unk_48->unk_9a_4) {
        self->unk_48->unk_9a_5 = 1;
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            func_ov000_02198360(self->unk_40, 4, 0);
        }
    }
}

}
