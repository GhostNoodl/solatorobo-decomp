#include "ov014/ov014.h"

struct Ov014Vec16 {
    u16 x;
    u16 y;
    u16 z;
};

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

void func_ov014_02210854(Ov014Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, (u8 *)self + 0x118, 0);
    }
}

extern void *data_ov000_021ccd64;
extern const Ov014Blk12 data_ov014_02216bf4;
extern const Ov014Blk12 data_ov014_02216c00;
extern u8 data_ov014_02216cb8[];
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDesc *d, Ov014Vec *pos, Ov014Vec16 *rot, u16 a);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void MTX_Identity33_(Ov014Mtx33 *m);
extern void MTX_RotX33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov014Mtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov014Mtx33 *a, Ov014Mtx33 *b, Ov014Mtx33 *out);
extern void MTX_MultVec33(const Ov014Vec *v, const Ov014Mtx33 *m, Ov014Vec *out);
extern void VEC_MultAdd(s32 a, const Ov014Vec *v1, const Ov014Vec *v2, Ov014Vec *out);

Ov014Actor *func_ov014_02210878(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Vec base;
    Ov014SpawnDesc desc;
    Ov014Mtx33 m2;
    Ov014Vec off;
    Ov014Mtx33 m;
    Ov014Vec16 rot;
    Ov014Actor *o;
    Ov014Actor *pl;
    s32 px;
    s32 i;
    s32 pz;
    u16 cnt;
    s32 step;
    u16 ang;
    *(Ov014Blk12 *)&base = data_ov014_02216bf4;
    cnt = FLD(u16, FLD(u8 *, self, 0x140), 4) + 3;
    step = -0x5554 / cnt;
    ang = step * (u16)((FLD(s32, self, 0x144) + FLD(u16, self, 0x14c)) % cnt) + 0x2aaa;
    *(Ov014Blk12 *)&off = data_ov014_02216c00;
    MTX_Identity33_(&m);
    MTX_RotX33_(&m, OV014_SIN(0xe000), OV014_COS(0xe000));
    if (ang != 0) {
        MTX_RotY33_(&m2, OV014_SIN(ang), OV014_COS(ang));
        MTX_Concat33(&m2, &m, &m);
    }
    MTX_MultVec33(&off, &m, &v);
    VEC_MultAdd(0x3000, &v, &base, &v);
    rot.x = 0xe001;
    rot.z = 0;
    rot.y = ang;
    pl = func_ov000_0219bf90();
    px = pl->pos.x;
    pz = pl->pos.z;
    px += func_02040528(0x6000);
    pz -= func_02040498(0x1000);
    desc.kind = 0x4816;
    desc.flags = 0x4816 & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &v, &rot, 0xffff);
    FLD(void *, o, 0x60) = data_ov014_02216cb8;
    FLD(s32, o, 0x84) = px;
    FLD(s32, o, 0x88) = 0;
    FLD(s32, o, 0x8c) = pz;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    FLD(u16, self, 0xde) = o->id;
    return o;
}

extern const Ov014Vec data_ov014_02216c0c;
extern void VEC_Normalize(const Ov014Vec *src, Ov014Vec *dst);

Ov014Actor *func_ov014_02210a78(Ov014Actor *self) {
    Ov014Vec pos;
    Ov014Vec d;
    Ov014SpawnDesc desc;
    Ov014Vec16 rot;
    Ov014Actor *o;
    s32 k;
    s32 i;
    pos.x = FLD(s32, self, 0x118);
    pos.y = FLD(s32, self, 0x11c);
    pos.z = FLD(s32, self, 0x120) + 0x2000;
    k = ((FLD(s32, self, 0x144) + FLD(u16, self, 0x14c)) % 4) * 0x7fff;
    rot.x = 0xfff;
    rot.y = -0x3fff + (u16)(k / 4);
    rot.z = 0;
    switch ((u16)((FLD(s32, self, 0x144) + FLD(u16, self, 0x14c)) % 4)) {
    case 0:
        d.x = func_02040498(0x1000);
        d.z = func_02040498(0x1000);
        break;
    case 1:
        d.x = -func_02040498(0x1000);
        d.z = func_02040498(0x1000);
        break;
    case 2:
        d.x = -func_02040498(0x1000);
        d.z = -func_02040498(0x1000);
        break;
    case 3:
        d.x = func_02040498(0x1000);
        d.z = -func_02040498(0x1000);
        break;
    }
    d.y = 0;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(func_02040498(0x4000) + 0x4000, &d, &data_ov014_02216c0c, &d);
    desc.kind = 0x4815;
    desc.flags = 0x4815 & 0xf000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &pos, &rot, 0xffff);
    FLD(Ov014Vec, o, 0x84) = d;
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
    FLD(u16, self, 0xde) = o->id;
    return o;
}

}
