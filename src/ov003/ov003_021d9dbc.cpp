#include "ov003/Vec.h"

struct Ov003VecP {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003Kind {
    u8 unk_00[0x13];
    u8 kind;
};

struct Ov003Attach {
    u8 unk_00[0xc];
    Ov003Vec pos;
};

struct Ov003FxActor {
    u8 unk_00[0x40];
    Ov003Kind *unk_40;
    Ov003Attach *unk_44;
    u8 unk_48[8];
    u16 *unk_50;
    u8 unk_54[0x1c];
    Ov003Vec pos;
};

class Ov003Effect {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetTime(s32 t);
};

static inline s32 Ov003Kind_Get(Ov003Kind *k) {
    return k != NULL ? k->kind : 0;
}

struct Ov003YawActor {
    u8 unk_00[0x44];
    Ov003Attach *unk_44;
    u8 unk_48[0x36];
    u16 yaw;
};

extern "C" {

extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern const Ov003VecP data_ov003_021f4988;
extern void *func_ov000_0218e4cc(void *mgr, u16 id);
extern void func_ov000_0218dfb4(void *obj, u16 id);
extern BOOL func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(void);
extern s32 func_02040498(s32 v);
extern Ov003Mtx33 *NNS_G3dGlbGetInvV(void);
extern Ov003Effect *func_02065f88(void *mgr, const Ov003Vec *pos);

void func_ov003_021d9dbc(Ov003Vec *out, const Ov003Vec *a, const Ov003Vec *b, s32 dist, s32 yoff) {
    Ov003Vec d;
    Ov003Vec r;
    if (VEC_Distance(a, b) <= dist) {
        *out = *a;
        return;
    }
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(dist, &d, b, &r);
    if (yoff != 0) {
        r.y += yoff;
    }
    *out = r;
}

void func_ov003_021d9e90(Ov003Vec *out, const Ov003Vec *dir, const Ov003Vec *base, s32 scale, s32 yoff) {
    Ov003Vec r;
    VEC_MultAdd(scale, dir, base, &r);
    if (yoff != 0) {
        r.y += yoff;
    }
    *out = r;
}

void func_ov003_021d9edc(u16 id) {
    func_ov000_0218dfb4(func_ov000_0218e4cc(data_ov000_021ccd68, id), id);
}

void func_ov003_021d9f04(Ov003Rot *out, const Ov003Vec *v) {
    out->x = Ov003_Pitch(v->y);
    out->y = FX_Atan2(v->x, v->z);
    out->z = 0;
}

void func_ov003_021d9f80(Ov003Rot *out, const Ov003Vec *a, const Ov003Vec *b) {
    Ov003Vec d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    VEC_Normalize(&d, &d);
    out->x = Ov003_Pitch(d.y);
    out->y = FX_Atan2(d.x, d.z);
    out->z = 0;
}

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

BOOL func_ov003_021da03c(Ov003FxActor *self) {
    if (!Ov003_GameIdle()) {
        return FALSE;
    }
    if (*self->unk_50 == 0) {
        return FALSE;
    }
    if (Ov003Kind_Get(self->unk_40) == 0x20 || Ov003Kind_Get(self->unk_40) == 0) {
        return FALSE;
    }
    if (!func_ov000_0219bf90() || func_ov000_021b4738()) {
        return FALSE;
    }
    return TRUE;
}

static inline Ov003Effect *Ov003_SpawnScatter(const Ov003Vec *base, s32 range, void *mgr) {
    Ov003Vec v;
    Ov003Vec p;
    s16 y = func_02040528(range);
    v.x = func_02040528(range);
    v.y = y;
    v.z = 0;
    MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(base, &v, &p);
    return func_02065f88(mgr, &p);
}

void func_ov003_021da108(Ov003FxActor *self, s32 range, void *mgr, s32 base, s32 top) {
    Ov003Vec pos;
    Ov003VecP off = data_ov003_021f4988;
    pos = self->pos;
    s32 r;
    Ov003Effect *e;
    if (self->unk_44 != NULL) {
        off.x = self->unk_44->pos.x;
        off.y = self->unk_44->pos.y;
        off.z = self->unk_44->pos.z;
    }
    VEC_Add(&pos, (Ov003Vec *)&off, &pos);
    r = func_02040498(top - base);
    e = Ov003_SpawnScatter(&pos, range, mgr);
    if (e != NULL) {
        e->SetTime(base + r);
    }
}

static inline void Ov003_RotY(Ov003VecP *out, s32 angle, const Ov003VecP *in) {
    Ov003Mtx33 m;
    if (angle == 0) {
        *out = *in;
        return;
    }
    MTX_RotY33_(&m, OV003_SIN(angle), OV003_COS(angle));
    MTX_MultVec33((const Ov003Vec *)in, &m, (Ov003Vec *)out);
}

Ov003VecP func_ov003_021da214(Ov003YawActor *actor) {
    Ov003VecP v = data_ov003_021f4988;
    if (actor != NULL && actor->unk_44 != NULL) {
        v = *(Ov003VecP *)&actor->unk_44->pos;
        Ov003_RotY(&v, actor->yaw, &v);
    }
    return v;
}

}
