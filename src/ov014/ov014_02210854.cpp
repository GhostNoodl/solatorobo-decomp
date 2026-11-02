#include "ov014/ov014.h"

struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov014Blk12 {
    s32 w[3];
};

struct Ov014Mtx33 {
    s32 m[9];
};


extern "C" {

extern void func_ov000_021984f4(void *a, void *b, s32 c);

void func_ov014_02210854(Ov014Act_0220f9d0 *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, (u8 *)self + 0x118, 0);
    }
}

extern const Ov014Blk12 data_ov014_02216bf4;
extern const Ov014Blk12 data_ov014_02216c00;
extern u8 data_ov014_02216cb8[];
extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, Ov014Rot16 *rot, u16 a);
extern Ov014Actor *func_ov000_0219bf90(void);

Ov014Actor *func_ov014_02210878(Ov014Act_0220f9d0 *self) {
    Ov014Vec v;
    Ov014Vec base;
    Ov014SpawnDesc desc;
    Ov014Mtx33 m2;
    Ov014Vec off;
    Ov014Mtx33 m;
    Ov014Rot16 rot;
    Ov014Actor *o;
    Ov014Actor *pl;
    s32 px;
    s32 i;
    s32 pz;
    u16 cnt;
    s32 step;
    u16 ang;
    *(Ov014Blk12 *)&base = data_ov014_02216bf4;
    cnt = FLD(u16, self->unk_140, 4) + 3;
    step = -0x5554 / cnt;
    ang = step * (u16)((self->unk_144 + self->unk_14c) % cnt) + 0x2aaa;
    *(Ov014Blk12 *)&off = data_ov014_02216c00;
    MTX_Identity33_((MtxFx33 *)&m);
    MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(0xe000), OV014_COS(0xe000));
    if (ang != 0) {
        MTX_RotY33_((MtxFx33 *)&m2, OV014_SIN(ang), OV014_COS(ang));
        MTX_Concat33((MtxFx33 *)&m2, (MtxFx33 *)&m, (MtxFx33 *)&m);
    }
    MTX_MultVec33(&off, (MtxFx33 *)&m, &v);
    VEC_MultAdd(0x3000, &v, &base, &v);
    rot.x = 0xe001;
    rot.z = 0;
    rot.y = ang;
    pl = func_ov000_0219bf90();
    px = pl->pos.x;
    pz = pl->pos.z;
    px += Rand_PlusMinus(0x6000);
    pz -= Rand_UpTo(0x1000);
    desc.kind = 0x4816;
    desc.flags = 0x4816 & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &v, &rot, 0xffff);
    o->unk_60 = data_ov014_02216cb8;
    o->unk_84.x = px;
    o->unk_84.y = 0;
    o->unk_84.z = pz;
    o->flags_0 = 1;
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
    self->target_id = o->id;
    return o;
}

extern const Ov014Vec data_ov014_02216c0c;

Ov014Actor *func_ov014_02210a78(Ov014Act_0220f9d0 *self) {
    Ov014Vec pos;
    Ov014Vec d;
    Ov014SpawnDesc desc;
    Ov014Rot16 rot;
    Ov014Actor *o;
    s32 k;
    s32 i;
    pos.x = self->unk_118.x;
    pos.y = self->unk_118.y;
    pos.z = self->unk_118.z + 0x2000;
    k = ((self->unk_144 + self->unk_14c) % 4) * 0x7fff;
    rot.x = 0xfff;
    rot.y = -0x3fff + (u16)(k / 4);
    rot.z = 0;
    switch ((u16)((self->unk_144 + self->unk_14c) % 4)) {
    case 0:
        d.x = Rand_UpTo(0x1000);
        d.z = Rand_UpTo(0x1000);
        break;
    case 1:
        d.x = -Rand_UpTo(0x1000);
        d.z = Rand_UpTo(0x1000);
        break;
    case 2:
        d.x = -Rand_UpTo(0x1000);
        d.z = -Rand_UpTo(0x1000);
        break;
    case 3:
        d.x = Rand_UpTo(0x1000);
        d.z = -Rand_UpTo(0x1000);
        break;
    }
    d.y = 0;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(Rand_UpTo(0x4000) + 0x4000, &d, &data_ov014_02216c0c, &d);
    desc.kind = 0x4815;
    desc.flags = 0x4815 & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = Group_SpawnActor(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    o->unk_84 = d;
    o->flags_0 = 1;
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
    self->target_id = o->id;
    return o;
}

}
