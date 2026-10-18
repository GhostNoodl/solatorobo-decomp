#include "ov003/Vec.h"

struct Ov003Spring {
    u8 unk_00[0x9c];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

struct Ov003SpawnInfo {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
};

class Ov003Spawnable {
public:
    virtual void v00();
    virtual void Init();
};

struct Ov003Bits {
    u32 unk_00;
    u64 mask;
    u8 unk_0c[7];
    u8 cur;
};

extern "C" {

extern Ov003Spawnable *func_ov003_021f1420(Ov003SpawnInfo *info);
extern Ov003Spawnable *func_ov000_02192b24(Ov003SpawnInfo *info);
extern Ov003Spawnable *func_ov003_021cfab4(Ov003SpawnInfo *info);
extern Ov003Spawnable *func_ov000_021b4828(Ov003SpawnInfo *info);
extern void func_ov000_02198360(Ov003Bits *self, u8 idx, s32 flag);
extern Ov003Mtx33 *func_02027240(void);
extern void *func_02065f88(void *mgr, const void *arg);

void func_ov003_021da2c8(Ov003Spring *self, s32 a, s32 b, s32 c, s32 d) {
    if (self == NULL) {
        return;
    }
    if (c > 0 && c < 0x1000) {
        a = Ov003_FxMul(a, c);
    }
    if (d != 0) {
        b -= d;
        if (b < -0x800) {
            b = -0x800;
        }
    }
    self->unk_9c = a;
    self->unk_a0 = b;
    self->unk_a4 = c;
    self->unk_a8 = d;
}

Ov003Spawnable *func_ov003_021da32c(u16 id) {
    Ov003SpawnInfo info;
    Ov003Spawnable *obj = NULL;
    s32 i;
    s32 kind = id & 0xf000;
    info.id = id;
    info.kind = kind;
    for (i = 0; i < 4; i++) {
        info.unk_04[i] = 0;
    }
    info.unk_0c = -1;
    switch ((u16)kind) {
    case 0x1000:
        obj = func_ov003_021f1420(&info);
        break;
    case 0x2000:
    case 0x3000:
        obj = func_ov003_021f1420(&info);
        break;
    case 0x4000:
        obj = func_ov000_02192b24(&info);
        break;
    case 0x5000:
        obj = func_ov003_021cfab4(&info);
        break;
    case 0x6000:
        obj = func_ov000_021b4828(&info);
        break;
    }
    if (obj != NULL) {
        obj->Init();
    }
    return obj;
}

void func_ov003_021da40c(Ov003Bits *self) {
    u8 idx;
    u8 i;
    if (self->mask == 0) {
        return;
    }
    idx = self->cur;
    for (i = 0; i < 64; i++) {
        if (((u64)1 << i) & self->mask) {
            idx = i;
            break;
        }
    }
    func_ov000_02198360(self, idx, 0);
    self->mask = 0;
}

void func_ov003_021da48c(Ov003Bits *self, u8 idx) {
    self->mask = 0;
    func_ov000_02198360(self, idx, 1);
}

void *func_ov003_021da4a8(const Ov003Vec *base, s32 range, void *mgr) {
    Ov003Vec v;
    Ov003Vec p;
    s16 y = func_02040528(range);
    v.x = func_02040528(range);
    v.y = y;
    v.z = 0;
    func_020117a4(&v, func_02027240(), &v);
    func_02012be8(base, &v, &p);
    return func_02065f88(mgr, &p);
}

struct Ov003URot {
    u16 x;
    u16 y;
    u16 z;
};

class Ov003Follower {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetPos(Ov003Vec *pos);
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003URot *rot);
    u32 target;
    Ov003Vec offset;
    u8 unk_14[0x50];
    Ov003URot rot;
};

struct Ov003FollowTgt {
    u8 unk_00[0x70];
    Ov003Vec pos;
    Ov003URot rot;
};

extern void *data_ov000_021ccd68;
extern Ov003FollowTgt *func_ov000_0218e640(void *mgr, u16 id);

static inline Ov003FollowTgt *Ov003_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Ov003_RotY(Ov003Vec *out, s32 angle, const Ov003Vec *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    func_02011488(&m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, &m, out);
}

static inline void Ov003_RotYM(Ov003Vec *out, s32 angle, const Ov003Vec *in, Ov003Mtx33 *m) {
    if (angle == 0) {
        *out = *in;
        return;
    }
    func_02011488(m, OV003_SIN(angle), OV003_COS(angle));
    func_020117a4(in, m, out);
}

static inline void Ov003Follower_Update(Ov003Follower *self) {
    Ov003FollowTgt *t;
    Ov003Vec p;
    Ov003Vec off;
    Ov003Mtx33 m;
    if (self == NULL) {
        return;
    }
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    p = t->pos;
    off = self->offset;
    Ov003_RotYM(&off, (u16)t->rot.y, &off, &m);
    func_02012be8(&p, &off, &p);
    self->SetPos(&p);
}

void func_ov003_021da520(Ov003Follower *self) {
    Ov003FollowTgt *t;
    if (self == NULL) {
        return;
    }
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Ov003Vec p = t->pos;
    Ov003Vec off = self->offset;
    Ov003_RotY(&off, (u16)t->rot.y, &off);
    func_02012be8(&p, &off, &p);
    self->SetPos(&p);
}

void func_ov003_021da620(Ov003Follower *self) {
    Ov003FollowTgt *t;
    if (self == NULL) {
        return;
    }
    Ov003Follower_Update(self);
    t = Ov003_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    Ov003URot r;
    r.x = self->rot.x;
    r.y = self->rot.y;
    r.z = self->rot.z;
    r.y = t->rot.y;
    self->SetRot(&r);
}

}
