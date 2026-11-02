#include "ov013/ov013.h"


// Two vectors built at startup at the start of the overlay's .data. The stub stores every member
// as an immediate: the original computed them with an expression MWCC folds in __sinit, which the
// inline identity reproduces. func_ov013_021fc7e0 indexes the pair, so it loads the array's
// address and the address of its first .y as two pool words. That function's file,
// ov013_021fc400.cpp (0x021fc400..0x021fcef8), joined this TU in round dtD.
static inline fx32 K(fx32 v) { return v; }

extern "C" {

extern const VecFx32 data_ov013_0220b5a0[2];

const VecFx32 data_ov013_0220b5a0[2] = {
    {-K(0x5800), K(0x1800), K(0x1800) - 0x15800},
    {K(0x5800), K(0x1800), K(0x1800) - 0x15800},
};

}

// ---- merged from ov013_021fc400.cpp
namespace m_021fc400 {
class Ef13 {
public:
    virtual void Dtor();
    virtual void Delete();
    virtual void SetParam(s32 param);
    virtual void vf0c();
    virtual void SetScale(const VecFx32 *scale);
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void SetPos(const VecFx32 *pos);
    virtual void SetPosXYZ(s32 x, s32 y, s32 z);
    virtual void AddPos(const VecFx32 *delta);
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
    virtual void vf28();
    virtual void vf2c();
    virtual void SetRot(const void *rot);
    virtual void SetRotXYZ(u16 x, u16 y, u16 z);
    u8 pad04[0x20];
    u32 id;
    u8 pad28[0x14];
    s32 speed;
    u8 pad40[0x88];
    s32 loopCount;
};
extern "C" {

extern char data_ov013_0220b5b8[];
extern char data_ov013_0220b5ca[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *t, s32 a);
extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(Ov003Actor *a, u16 id);
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern BOOL func_ov000_021983b0(void *a, s32 b, s32 c, s32 d);

s32 func_ov013_021fc400(Ov003Actor *self) {
    s32 r = 0x10;
    s32 a = ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000), 0x4823);
    s32 b = ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000), 0x5c17);
    if (b >= 2 || a >= 4 || func_ov000_021983b0(self->fsm, r, 3, 1)) {
        s32 rnd = Rand_UpTo(0x63);
        u16 pct = self->hp[0] * 100 / self->hp[1];
        FLD(u8, self, 0xf1) = 0;
        if (pct >= 0x4b) {
            r = 0xf;
        } else if (pct >= 0x32) {
            if (rnd % 2 == 0) {
                r = 0xf;
            } else {
                r = 0xe;
            }
        } else {
            if ((u32)rnd % pct < 0x19) {
                FLD(u8, self, 0xf1) = 2;
                FLD(u8, self, 0xf0) = 1;
            }
            r = 0xe;
        }
    }
    if (!func_ov000_021983b0(self->fsm, 0x10, 7, 1)) {
        r = 0x10;
    }
    return r;
}

void Ov013ActVt_0220b5e0_Start(Ov013ActVt_0220b5e0 *self) {
    ActorSub48 *m;
    s32 n;
    Ov003Actor *a;
    func_ov003_021d112c(self);
    self->hit->unk_30 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_f0 = 0;
    self->unk_f4 = -1;
    n = ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000), 0x5c17);
    self->unk_f8 = n % 2;
    if (n == 2) {
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_FindKind(data_ov000_021ccd68, 0x5000, 0x5c17);
        }
        if (a != NULL && a == self) {
            self->unk_f8 = 1;
        }
    }
    func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x1000, 0);
    func_ov000_021915a0(self->model);
    func_ov000_02198360(self->fsm, 0xf, 0);
    self->unk_ea_6 = 1;
    self->unk_93_4 = 1;
    self->unk_b6 = 100;
}

void Ov013ActVt_0220b5e0_Update(Ov013ActVt_0220b5e0 *self) {
    Ov003Actor *p;
    u8 k;
    if (!Ov013_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->target = p->id;
    }
    k = self->fsm->current;
    if (self->unk_f0 != 0 && k != 0x15 && k != 9) {
        self->fsm->flags |= 4;
    }
    if (k != 1 || self->fsm->st != 0x63) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    self->fsm->flags |= 0x8000;
    self->unk_b6 = 300;
}

void func_ov013_021fc71c(Ov003Actor *self) {
    ActorSub40 *s = self->fsm;
    Ov003Actor *t;
    if (s->history[0] == 4 && s->history[1] == 10 && s->history[2] == 9) {
        func_ov000_02198360(s, 0xf, 0);
        return;
    }
    if (s->st == 0) {
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x63;
        self->fsm->timer = 0;
    }
    self->rot_y = func_01ffc128(0, self->rot_y, 0xcd, 1, 0x8000);
    t = Actor_GetTarget(self);
    if (t != NULL) {
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
    }
}

extern void *data_0214a420;
extern void *data_02097e4c;
extern const VecFx32 data_ov013_0220ae64;
extern u8 data_ov013_0220ae88[];
extern void EffectMgr_Kill(void *a, s32 b);
extern Ov013V *func_020657b0(void *a, s32 b);
extern Ov013V *func_02065f88(s32 id, VecFx32 *pos);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern VecFx32 Ov003Vec_DirXZ(const VecFx32 *a, const VecFx32 *b);
extern void func_ov000_0219a210(VecFx32 *v, const VecFx32 *a, s32 b);
extern void Actor_TurnToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

static inline s32 Ov013_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov013_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt64(sq);
}

// Enum-typed locals keep their constants out of IRO's propagation (round lfA), so the spawn kind and
// the sound pitch are built where they are assigned (rounds o4B, cmA).
typedef enum { OV013_EF_KIND_FC7E0 = 0x192 } Ov013EfKind;
typedef enum { OV013_SND_PITCH_NONE = 0 } Ov013SndPitch;
void func_ov013_021fc7e0(Ov013ActVt_0220b5e0 *self) {
    Ov013SndPitch pitch;
    Ov013EfKind kind;
    Ov003Actor *pl = Actor_GetTarget(self);
    if (pl == NULL) {
        return;
    }
    VecFx32 tgt = {0, 0, 0};
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m;
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0xcd;
        tgt = self->pos;
        tgt.y += 0x1000;
        self->unk_b8 = tgt;
        m = self->hit;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
        self->fsm->st = 1;
        self->fsm->timer = 0;
        break;
    }
    case 1: {
        u16 r;
        Ef13 *o;
        tgt = self->unk_b8;
        if (self->pos.y < tgt.y) {
            Actor_Move(self, 0);
            if (self->pos.y > tgt.y) {
                self->pos.y = tgt.y;
            }
            break;
        }
        tgt = pl->pos;
        {
            VecFx32 dir = Ov003Vec_DirXZ(&self->pos, &tgt);
            VEC_MultAdd(0x1800, &dir, &tgt, &tgt);
        }
        self->unk_b8 = tgt;
        func_ov000_02190cb0(self->model, data_ov013_0220b5ca, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0x2b8;
        self->velY = -0xcd;
        self->friction = 0;
        self->gravity = 0;
        r = self->rot_y;
        Actor_TurnToPos(self, &tgt, 0x1000);
        self->moveYaw = self->rot_y;
        self->rot_y = r;
        kind = OV013_EF_KIND_FC7E0;
        {
            VecFx32 v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->moveYaw);
            o = (Ef13 *)func_02065f88(kind, &v);
        }
        pitch = OV013_SND_PITCH_NONE;
        self->unk_f4 = o->id;
        o->SetRotXYZ(0, self->moveYaw, 0);
        o->speed = 0xb33;
        o->SetScaleXYZ(0x800, 0x800, 0x800);
        o->loopCount = -1;
        func_02049f44(data_02097e4c, 100, &self->pos, pitch);
        self->fsm->st = 20;
        self->fsm->timer = 0;
        break;
    }
    case 20: {
        Ef13 *o;
        tgt = self->unk_b8;
        Actor_MoveToPos(self, &tgt, 0);
        Actor_TurnToPos(self, &tgt, 0x400);
        if (self->pos.y < 0x99a) {
            self->pos.y = 0x99a;
        }
        func_ov000_0219aae8(self, self, 0x1e, 0x20, 1 << (pl->id >> 12), data_ov013_0220ae88, NULL, self->radius, 0, 100, 0x1000);
        o = (Ef13 *)func_020657b0(data_0214a420, self->unk_f4);
        if (o != NULL) {
            VecFx32 v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->moveYaw);
            o->SetPos(&v);
            o->SetRotXYZ(0, self->rot_y, 0);
        }
        if (Ov013_DistXZ(&self->pos, &tgt) < 0x19a) {
            self->velY = 0x29;
            self->unk_b8 = data_ov013_0220b5a0[self->unk_f8];
            self->fsm->st = 21;
            self->fsm->timer = 0;
        }
        break;
    }
    case 21: {
        Ef13 *o;
        u16 t;
        {
            ActorSub40 *s = self->fsm;
            s->timer++;
            t = s->timer;
        }
        tgt = self->unk_b8;
        if (t > 0x1e) {
            Actor_TurnToPos(self, &tgt, 0x11f);
        }
        if (self->pos.y > data_ov013_0220b5a0[self->unk_f8].y) {
            self->pos.y = data_ov013_0220b5a0[self->unk_f8].y;
        }
        func_ov000_0219aae8(self, self, 0x1e, 0x20, 1 << (pl->id >> 12), data_ov013_0220ae88, NULL, self->radius, 0, 100, 0x1000);
        if (Hit_DiffInSphere(&self->pos, &tgt, 0xccd)) {
            Actor_TurnToPos(self, &tgt, 0x1000);
        }
        if (t > 500) {
            Actor_TurnToPos(self, &tgt, 0x1000);
        }
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        o = (Ef13 *)func_020657b0(data_0214a420, self->unk_f4);
        if (o != NULL) {
            VecFx32 v;
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            func_ov000_0219a210(&v, &data_ov013_0220ae64, self->moveYaw);
            o->SetPos(&v);
            o->SetRotXYZ(0, self->rot_y, 0);
        }
        if (VEC_Distance(&tgt, &self->pos) >= 0x19a) {
            break;
        }
        self->pos = tgt;
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->model);
        EffectMgr_Kill(data_0214a420, self->unk_f4);
        self->fsm->st = 0x63;
        self->fsm->timer = 0;
        break;
    }
    case 0x63:
    {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer > 0x1e) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_021fc400
