#include "ov009/ov009.h"


// A header's zero rotation and vector, plus copies made at startup, among this TU's colour
// bytes and offsets, which the functions of 0x0220d2d8..0x02210e88 read (25 files, merged in
// round dtD, each in its own namespace).
typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov009Ver;

extern const Ov009Ver data_ov009_02216004[2];
extern const VecFx32 data_ov009_02216010;
extern const VecFx32 data_ov009_0221601c;
extern const VecFx32 data_ov009_02216028;
static const VecFx16 data_ov009_0221600a = {0, 0, 0};
const Ov009Ver data_ov009_02216004[2] = {{0x11, 1, 0}, {0x11, 1, 1}};
const VecFx32 data_ov009_0221601c = {0x1800, -FX32_ONE, 0x3000};
const VecFx32 data_ov009_02216028 = {0, 0, 0x1800};
static const VecFx32 data_ov009_02216034 = {0, 0, 0};
const VecFx32 data_ov009_02216010 = {-0x6800, 0xc800, 0xb0cd};
static const VecFx16 data_ov009_02217994 = data_ov009_0221600a;
static const VecFx32 data_ov009_0221799c = data_ov009_02216034;

// ---- merged from ov009_0220d2d8.cpp
namespace m_0220d2d8 {
extern "C" {


extern void func_0203f2b8(void *p);

static inline BOOL Ov009Game_IsVer(Ov009Ver v) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g->unk_ca.c[0] == v.a && g->unk_ca.c[1] == v.b && g->unk_ca.c[2] == v.c) {
        r = TRUE;
    }
    return r;
}

void Ov009ActPair110_Start(Ov009ActPair110 *self) {
    void *saved;
    GroupNode *p;
    Ov003Actor_Start(self);
    if (Ov009Game_IsVer(data_ov009_02216004[0])) {
        u16 v = self->hp[1] >> 1;
        self->hp[1] = v;
        self->hp[0] = v;
    }
    self->unk_f0 = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *s = self->hit;
        if (s != NULL) {
            func_0203f2b8(s);
            Heap_Free(s);
        }
        self->hit = NULL;
    }
    data_02097dd0->cur = saved;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    self->unk_fc = self->unk_f0;
    self->unk_108 = 0;
    self->unk_93_4 = 1;
    self->unk_ea |= 0x100;
    self->unk_10c = -1;
}

extern void *data_02097e4c;
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern void SndMgr_StopSeqArc(void *mgr, s32 h);

void Ov009ActVt_02217f60_Update(Ov009ActVt_02217f60 *self) {
    Ov003Actor *a;
    u16 t;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
        if (func_ov000_021b4738(a) && self->unk_10c >= 0) {
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            self->unk_10c = -1;
        }
    }
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->fsm->flags |= 0x4000;
    t = 0x78;
    if (Ov009Game_IsVer(data_ov009_02216004[1])) {
        t += 0x28;
    }
    self->unk_108++;
    if (self->unk_108 == 3) {
        self->unk_b6 = t + 0xa0;
        self->unk_108 = 0;
    } else {
        self->unk_b6 = t;
    }
}

}
}  // namespace m_0220d2d8

// ---- merged from ov009_0220d5f8.cpp
namespace m_0220d5f8 {
extern "C" {

extern void *data_02097e4c;
extern s32 func_02049afc(void *mgr, s32 id);
extern void func_0204a058(void *mgr, s32 h, s32 a, s32 b);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void Ov009ActPair110_State20(Ov009ActPair110 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0:
        self->unk_10c = func_02049afc(data_02097e4c, 0x3f);
        self->fsm->st++;
        break;
    case 1:
        d.x = self->unk_f0.x - self->pos.x;
        d.y = self->unk_f0.y - self->pos.y;
        d.z = self->unk_f0.z - self->pos.z;
        VEC_MultAdd(0x35, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &self->unk_f0) >= 0x333) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        self->pos = self->unk_f0;
        self->unk_b6 = 0x1e;
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_0204a058(data_02097e4c, self->unk_10c, 0x28, 0x1c2);
        break;
    }
}

extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(ActorGroup *group, u16 kind);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void Ov009ActVt_02217f60_StateIdle(Ov009ActVt_02217f60 *self) {
    VecFx32 d;
    if (VEC_Distance(&self->pos, &self->unk_fc) < 0x19a) {
        self->speed = Rand_PlusMinus(0x29) + 0x8f;
        self->unk_fc = self->unk_f0;
        if (!Ov009_GameIdle() || Ov009Game_IsPaused(data_ov000_021ccd54) || self->fsm->current == 0x15) {
            self->unk_fc.x += Rand_PlusMinus(0xa000);
            self->unk_fc.y += Rand_PlusMinus(0x5000);
            self->unk_fc.z += Rand_PlusMinus(0x5000);
        } else {
            self->unk_fc.x += Rand_PlusMinus(0x14000);
            self->unk_fc.y += Rand_PlusMinus(0xa000);
            self->unk_fc.z += Rand_PlusMinus(0xd000);
            if (ActorGroup_CountKind(ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000), 0x5017) && self->unk_fc.z > -0x37000) {
                self->unk_fc.z = -0x37000;
            }
        }
    }
    d.x = self->unk_fc.x - self->pos.x;
    d.y = self->unk_fc.y - self->pos.y;
    d.z = self->unk_fc.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->speed, &d, &self->pos, &self->pos);
}

}
}  // namespace m_0220d5f8

// ---- merged from ov009_0220d90c.cpp
namespace m_0220d90c {
extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Bits16 {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

extern u8 data_ov009_022160d0[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);

void Ov009ActVt_02217f60_StateShoot(Ov009ActVt_02217f60 *self) {
    Ov003Actor *t;
    Ov003Actor *o;
    VecFx32 a;
    VecFx32 b;
    Ov009Rot r;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    VEC_Add(&self->pos, &data_ov009_02216010, &a);
    r.y = FX_Atan2(a.x - t->pos.x, a.z - t->pos.z) + 0x7c00 + Rand_UpTo(0x800);
    r.x = 0;
    r.z = 0;
    o = func_ov000_0219be1c(0x480b, &a, &r, self->id, self->target);
    if (o != NULL) {
        o->unk_60 = data_ov009_022160d0;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
        VEC_Add(&self->pos, &data_ov009_02216010, &b);
        func_02065f88(0x325, &b)->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
    }
    func_ov000_02198360(self->fsm, 1, 0);
}

}
}  // namespace m_0220d90c

// ---- merged from ov009_0220da24.cpp
namespace m_0220da24 {
extern "C" {

extern BOOL func_ov000_021983b0(ActorSub40 *st, s32 a, s32 b, s32 c);

void Ov009ActVt_02217f60_StateHurt(Ov009ActVt_02217f60 *self) {
    ActorSub40 *st = self->fsm;
    VecFx32 d;
    switch (st->st) {
    case 0:
        self->unk_108 = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->fsm, 0x13, 1, 0)) {
            self->fsm->timer = 0x3c;
            self->fsm->st++;
            return;
        }
        self->unk_fc = self->pos;
        self->unk_fc.x += 0x2800;
        self->unk_fc.y -= 0x2000;
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x41 || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->unk_fc.x = self->unk_f0.x;
            self->unk_fc.y = self->unk_f0.y;
            self->unk_fc.z = self->unk_f0.z;
        }
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
        break;
    }
}

extern void *data_02097e4c;
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);

void Ov009ActPair110_StateDie(Ov003Actor *self) {
    VecFx32 p;
    EffectObj *e;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x480b, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x482e, 0x15);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_ov000_0218996c(0x10, 0x3c);
        self->unk_ea_6 = 1;
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->fsm->timer >= 10) {
            Ov003Actor_Defeat(self, 0, 1, 1);
            self->fsm->st++;
        }
        break;
    }
    self->vfunc_50();
    st = self->fsm;
    st->timer++;
    if (st->timer != 0x78) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.x += Rand_PlusMinus(self->radius >> 1);
    p.y += Rand_PlusMinus(self->height);
    p.z += Rand_UpTo(0x1000) + 0x6000;
    e = func_02065f88(0x325, &p);
    e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
    e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
    self->fsm->timer = 0;
}

extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
void Ov009ActVt_02217f60_State21(Ov009ActVt_02217f60 *self) {
    VecFx32 p0;
    VecFx32 v;
    VecFx32 p1;
    VecFx32 d;
    ActorSub40 *st;
    u16 t;
    d.x = 0x2cd - self->speed;
    d.y = 0x148 - 0x2cd - self->velY;
    d.z = -self->friction;
    VEC_MultAdd(0x66, &d, (VecFx32 *)&self->speed, (VecFx32 *)&self->speed);
    VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
    st = self->fsm;
    st->timer++;
    t = st->timer;
    if (t == 300) {
        SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
    }
    if (t > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
    }
    if ((t & 0x3f) == 1) {
        EffectObj *e;
        p0.x = self->pos.x;
        p0.y = self->pos.y;
        p0.z = self->pos.z;
        p0.x += Rand_PlusMinus(self->radius >> 1);
        p0.y += Rand_PlusMinus(self->height);
        p0.z += Rand_UpTo(0x1000) + 0x6000;
        e = func_02065f88(0x325, &p0);
        e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
        e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
    }
    if ((t & 0xf) == 0) {
        s32 a = -1;
        s32 b = 100;
        switch (self->fsm->timer & 0x3f) {
        case 0:
            a = 3;
            break;
        case 0x10:
            a = 3;
            b = 0x19;
            break;
        case 0x20:
            break;
        case 0x30:
            a = 3;
            b = 0x32;
            break;
        }
        v.x = 0x3000;
        v.y = 0x2800;
        v.z = 0x800;
        p1.x = self->pos.x;
        p1.y = self->pos.y;
        p1.z = self->pos.z + 0x7000;
        func_ov000_0219b71c(&p1, &v, 0xc00, 0x1400, a, b);
        func_ov000_0218996c(6, 10);
    }
}

}
}  // namespace m_0220da24

// ---- merged from ov009_0220dfe8.cpp
namespace m_0220dfe8 {
extern "C" {

extern void func_0203f2b8(void *p);

void Ov009ActVt_02217eb4_Start(Ov009ActVt_02217eb4 *self) {
    void *saved;
    GroupNode *p;
    Ov003Actor_Start(self);
    self->unk_f0 = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *s = self->hit;
        if (s != NULL) {
            func_0203f2b8(s);
            Heap_Free(s);
        }
        self->hit = NULL;
    }
    data_02097dd0->cur = saved;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    self->unk_fc = self->unk_f0;
    self->unk_108 = 0;
    self->unk_109 = Rand_UpTo(2);
    self->unk_ea_6 = 1;
}

}
}  // namespace m_0220dfe8

// ---- merged from ov009_0220e0e4.cpp
namespace m_0220e0e4 {
extern "C" {

struct Ov009Mtx33 {
    s32 m[3][3];
};

extern BOOL func_ov000_0218cea4(Ov003Actor *self);

void Ov009ActVt_02217eb4_Draw(Ov009ActVt_02217eb4 *self) {
    Ov009Mtx33 m;
    Ov009Mtx33 t;
    if (self->hp != NULL && *self->hp == 0) {
        Ov003Actor_SetColor(self, 0x3def);
    }
    self->unk_93_0 = 1;
    MTX_Identity33_((MtxFx33 *)&m);
    MTX_RotZ33_((MtxFx33 *)&t, OV009_SIN(self->rot_z), OV009_COS(self->rot_z));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MTX_RotX33_((MtxFx33 *)&t, OV009_SIN(self->rot_x), OV009_COS(self->rot_x));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MTX_RotY33_((MtxFx33 *)&t, OV009_SIN(self->rot_y), OV009_COS(self->rot_y));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MI_Copy36B(&m, &self->model->rot);
    self->model->trans = self->pos;
    func_ov000_0218cea4(self);
}

extern void func_ov000_0218d7e8(Ov003Actor *self, s32 a);

void Ov009ActVt_02217eb4_SelectState(Ov009ActVt_02217eb4 *self) {
    ActorSub40 *s = self->fsm;
    BOOL run = TRUE;
    u64 f = s->flags;
    u8 k = s->current;
    if ((f & 0x40000) || (f & 0x80000)) {
        if (k == 0xf || k == 0xe || k == 0x21 || k == 0x20 || k == 0x12 || k == 0x13) {
            run = FALSE;
            func_ov000_0218d7e8(self, k);
        }
    }
    if (run) {
        Ov003Actor_SelectState(self);
    }
}

}
}  // namespace m_0220e0e4

// ---- merged from ov009_0220e2a4.cpp
namespace m_0220e2a4 {
extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217eb4_Update(Ov009ActVt_02217eb4 *self) {
    u8 k;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->fsm->current;
    if (k == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 == 0) {
            Ov003Actor *a;
            s32 r;
            if (self->unk_108 != 0) {
                if (VEC_Distance(&self->pos, &self->unk_f0) < 0x5000) {
                    self->unk_108 = 0;
                } else {
                    self->unk_b6 = 0x1e;
                    return;
                }
            }
            self->target = 0xffff;
            a = func_ov000_0219bf90();
            if (a != NULL) {
                self->target = a->id;
            }
            r = Rand_UpTo(10);
            if (self->unk_109 == 2 || r % 3 == 0) {
                self->fsm->flags |= 0x4000;
                self->unk_109 = 0;
            } else {
                self->fsm->flags |= 0x8000;
                self->unk_109++;
            }
            self->unk_b6 = Rand_UpTo(0x1e) + 0x96;
        }
    }
    if (k != 0x15 && k != 0x20 && self->pos.y < -0x1000) {
        self->pos.y = -0x1000;
        self->unk_fc.y = -0x1000;
    }
}

}
}  // namespace m_0220e2a4

// ---- merged from ov009_0220e434.cpp
namespace m_0220e434 {
extern "C" {

extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void Ov009ActVt_02217eb4_State20(Ov009ActVt_02217eb4 *self) {
    VecFx32 d;
    d.x = self->unk_f0.x - self->pos.x;
    d.y = self->unk_f0.y - self->pos.y;
    d.z = self->unk_f0.z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
    if (VEC_Distance(&self->pos, &self->unk_f0) >= 0xcd) {
        return;
    }
    func_ov000_02198360(self->fsm, 1, 0);
    self->pos = self->unk_f0;
    self->unk_b6 = 0x96;
    func_020627a0(self->kind, self->id);
    func_020627dc(4);
    data_ov000_021ccd54->stageFlags = 1;
}

}
}  // namespace m_0220e434

// ---- merged from ov009_0220e4fc.cpp
namespace m_0220e4fc {
extern "C" {


void Ov009ActVt_02217eb4_StateIdle(Ov009ActVt_02217eb4 *self) {
    VecFx32 d;
    if (VEC_Distance(&self->pos, &self->unk_fc) < 0xcd) {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            s32 r;
            self->unk_fc = self->unk_f0;
            r = Rand_PlusMinus(0x7000);
            if (self->unk_108 != 0 && r > 0) {
                r = -r;
            }
            self->unk_fc.x += r;
            self->unk_fc.y += Rand_PlusMinus(0x3000);
            self->fsm->timer = 0;
        }
    }
    d.x = self->unk_fc.x - self->pos.x;
    d.y = self->unk_fc.y - self->pos.y;
    d.z = self->unk_fc.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);
struct Ov009Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void Ov009ActVt_02217eb4_StateShoot(Ov009ActVt_02217eb4 *self) {
    VecFx32 d;
    Ov009Rot3 r;
    ActorSub40 *st;
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0: {
        self->unk_fc.x = self->pos.x + 0x1e000;
        self->unk_fc.y = 0x5000;
        self->unk_fc.z = self->pos.z - 0xa000;
        self->unk_b8.x = self->unk_fc.x;
        self->unk_b8.y = self->unk_fc.y;
        self->unk_b8.z = self->unk_fc.z;
        st->st++;
        self->fsm->timer = Rand_UpTo(0x14) + 100;
        break;
    }
    case 1:
        self->rot_z = func_01ffc128(0xd8e4, self->rot_z, 0x52, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        r.y = self->rot_y;
        r.x = 0;
        r.z = 0;
        func_ov000_0219be1c(0x482e, &self->pos, &r, self->id, self->target);
        func_02065f88(0x325, &self->pos)->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
        self->fsm->st++;
        self->fsm->timer = Rand_UpTo(0x14) + 0x46;
        break;
    case 2:
        self->rot_z = func_01ffc128(0, self->rot_z, 0x29, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        self->unk_fc.x = self->unk_f0.x;
        self->unk_fc.y = self->unk_f0.y;
        self->unk_fc.z = self->unk_f0.z;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 3: {
        s32 dist;
        self->rot_z = func_01ffc128(0, self->rot_z, 0x29, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x266, &d, &self->pos, &self->pos);
        dist = VEC_Distance(&self->pos, &self->unk_fc);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x78 || dist < 0x3000) {
            self->rot_z = 0;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_0220e4fc

// ---- merged from ov009_0220e954.cpp
namespace m_0220e954 {
extern "C" {

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern Ov003Actor *func_ov000_0219be1c(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void func_ov000_0219a210(VecFx32 *v, const void *a, u16 b);
extern u8 data_ov009_0221610c[];

struct Ov009Bits_cc {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

void Ov009ActVt_02217eb4_StateAttack(Ov009ActVt_02217eb4 *self) {
    VecFx32 d;
    VecFx32 p;
    Ov003Actor *t;
    ActorSub40 *st;
    ActorSub44 *s;
    Ov003Actor *a;
    s32 dist;
    u16 tm;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0:
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0x11f;
        self->velY = 0x52;
        self->moveYaw = 0x4000;
        st->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        Actor_Move(self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->fsm;
        st->timer++;
        if (st->timer > 0xb4) {
            self->speed = 0xa4;
            self->velY = 0x52;
            self->moveYaw = 0x58e4;
            self->fsm->st++;
            self->fsm->timer = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        if (self->fsm->timer > 0x78) {
            Actor_TurnToActor(self, t, 0x29);
            self->rot_z = func_01ffc128(0x71c, self->rot_z, 0x14, 1, 0x8000);
        } else {
            self->rot_z = func_01ffc128(0xeaab, self->rot_z, 0x52, 1, 0x8000);
        }
        break;
    case 2:
        Actor_TurnToActor(self, t, 0xa4);
        self->rot_z = func_01ffc128(0xe39, self->rot_z, 0x52, 1, 0x8000);
        self->rot_x = func_01ffc128(0x11c7, self->rot_x, 0x29, 1, 0x8000);
        Actor_Move(self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->fsm;
        st->timer++;
        if (st->timer <= 0x5a) {
            return;
        }
        if (self->pos.y < 0x5000) {
            return;
        }
        self->speed = 0x333;
        self->velY = -0x52;
        self->friction = 0x1052;
        self->moveYaw = self->rot_y;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 3:
        st->timer++;
        tm = st->timer;
        if (Ov009_GameIdle() && tm > 10 && tm < 100 && tm % 10 == 0) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            func_ov000_0219a210(&p, &data_ov009_0221601c, self->rot_y);
            a = func_ov000_0219be1c(0x4800, &p, &self->rot_x, self->id, self->target);
            if (a != NULL) {
                a->unk_60 = data_ov009_0221610c;
                ((Ov009Bits_cc *)((u8 *)a + 0xcc))->b3 = 0;
            }
        }
        Actor_Move(self, 0);
        if (tm <= 200) {
            return;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->pos.z = self->unk_f0.z;
        self->pos.x = self->unk_f0.x - 0xf000;
        self->pos.y = self->unk_f0.y + 0x1e000;
        self->rot_y = 0xc000;
        self->rot_x = 0;
        self->rot_z = 0xeaab;
        self->fsm->st++;
        break;
    case 4:
        d.x = self->unk_f0.x - self->pos.x;
        d.y = self->unk_f0.y - self->pos.y;
        d.z = self->unk_f0.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        dist = VEC_Distance(&self->pos, &self->unk_f0);
        if (dist < 0x2000) {
            s = self->unk_44;
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
            self->rot_z = func_01ffc128(0, self->rot_z, 0x29, 1, 0x8000);
        }
        if (dist < 0x19a) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_0220e954

// ---- merged from ov009_0220ee10.cpp
namespace m_0220ee10 {
extern "C" {

void Ov009ActVt_02217eb4_StateHurt(Ov009ActVt_02217eb4 *self) {
    ActorSub40 *st = self->fsm;
    VecFx32 d;
    switch (st->st) {
    case 0:
        self->unk_fc = self->pos;
        self->unk_fc.x += 0x2000;
        self->unk_fc.y -= 0x1000;
        st->st++;
        self->fsm->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x28 || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->unk_fc.x = self->pos.x;
            self->unk_fc.y = self->pos.y;
            self->unk_fc.z = self->pos.z;
        }
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
        break;
    }
}

extern void *data_02097e4c;
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
void Ov009ActVt_02217eb4_StateDie(Ov009ActVt_02217eb4 *self) {
    VecFx32 v;
    VecFx32 d;
    ActorSub40 *st;
    u16 t;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        *self->hp = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_ea_6 = 1;
        self->targetObj->target = 0xffff;
        {
            s32 z = Rand_PlusMinus(0x29);
            s32 x = Rand_PlusMinus(0x29);
            self->velY = -0x71;
            self->friction = z;
            self->speed = x;
        }
        self->fsm->st++;
        break;
    }
    case 1:
        d.x = 0x185 - self->speed;
        d.y = -0x8f - self->velY;
        d.z = -self->friction;
        VEC_MultAdd(0x66, &d, (VecFx32 *)&self->speed, (VecFx32 *)&self->speed);
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        st = self->fsm;
        st->timer++;
        t = st->timer;
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        if (t > 0x78) {
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->SetScaleXYZ(0x6000, 0x6000, 0x6000);
            self->fsm->timer = 0x29;
            self->fsm->st++;
            return;
        }
        if ((t & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            u32 r = self->fsm->timer & 0x3f;
            if (r == 0 || r == 0x20) {
                a = 3;
                b = 100;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            func_ov000_0219b71c(&self->pos, &v, 0xc00, 0x1400, a, b);
            func_ov000_0218996c(6, 10);
        }
        break;
    case 2:
        if ((u8)self->fsm->timer < 0x1f) {
            Ov003Actor_SetAlpha(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Ov003Actor_Defeat(self, 1, 1, 1);
        }
        break;
    }
}

}
}  // namespace m_0220ee10

// ---- merged from ov009_0220f1ac.cpp
namespace m_0220f1ac {
extern "C" {


void Ov009ActVt_02217eb4_State21(Ov009ActVt_02217eb4 *self) {
    VecFx32 d;
    ActorSub40 *st;
    d.x = 0x266 - self->speed;
    d.y = -0x15c - self->velY;
    d.z = -self->friction;
    VEC_MultAdd(0x66, &d, (VecFx32 *)&self->speed, (VecFx32 *)&self->speed);
    VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
    st = self->fsm;
    st->timer++;
    if (st->timer > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
    }
}

extern void *data_02097e4c;
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern void SndMgr_StopSeqArc(void *mgr, s32 h);

void Ov009ActPair110_Update(Ov009ActVt_02217b58 *self) {
    Ov003Actor *a;
    u16 pct;
    s32 n;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
        if (func_ov000_021b4738(a) && self->unk_10c >= 0) {
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            self->unk_10c = -1;
        }
    }
    if (self->unk_18 != 0) {
        self->unk_ea_6 = 1;
        return;
    }
    self->unk_ea_6 = 0;
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->fsm->flags |= 0x4000;
    pct = (self->hp[0] * 100) / self->hp[1];
    if (pct > 0x46) {
        n = 5;
    } else {
        n = 8;
        if (pct <= 0x28) {
            n = 10;
        }
    }
    self->unk_108++;
    if (self->unk_108 == n) {
        self->unk_b6 = 200;
        self->unk_108 = 0;
    } else {
        self->unk_b6 = 0x28;
    }
}

}
}  // namespace m_0220f1ac

// ---- merged from ov009_0220f3ec.cpp
namespace m_0220f3ec {
extern "C" {


void Ov009ActPair110_StateIdle(Ov009ActVt_02217b58 *self) {
    VecFx32 d;
    if (VEC_Distance(&self->pos, &self->unk_fc) < 0x19a) {
        self->unk_fc = self->unk_f0;
        self->unk_fc.x += Rand_PlusMinus(0x7000);
        self->unk_fc.y += Rand_PlusMinus(0x2000);
    }
    d.x = self->unk_fc.x - self->pos.x;
    d.y = self->unk_fc.y - self->pos.y;
    d.z = self->unk_fc.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
}

}
}  // namespace m_0220f3ec

// ---- merged from ov009_0220f4b0.cpp
namespace m_0220f4b0 {
extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Bits16 {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

extern VecFx32 data_ov009_02216040;
extern VecFx32 data_ov009_0221604c;
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);

void Ov009ActPair110_StateShoot(Ov009ActVt_02217b58 *self) {
    Ov003Actor *t;
    Actor *o;
    VecFx32 *off;
    VecFx32 a;
    VecFx32 b;
    Ov009Rot r;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    if (self->unk_108 % 2 == 0) {
        off = &data_ov009_02216040;
        VEC_Add(&self->pos, off, &a);
    } else {
        off = &data_ov009_0221604c;
        VEC_Add(&self->pos, off, &a);
    }
    VEC_Add(&self->pos, off, &b);
    r.y = FX_Atan2(a.x - t->pos.x, a.z - t->pos.z) + 0x7a00 + Rand_UpTo(0x800);
    r.x = 0;
    r.z = 0;
    if (r.y < 0xea9c) {
        if (r.y > 0x1554) {
            r.y = 0xea9c;
        }
    }
    o = Ov003Actor_SpawnChild(self, 0x482d, &a, &r, t);
    if (o != NULL) {
        o->unk_18 = 1;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
    }
    func_02065f88(0x325, &b)->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
    func_ov000_02198360(self->fsm, 1, 0);
}

}
}  // namespace m_0220f4b0

// ---- merged from ov009_0220f5fc.cpp
namespace m_0220f5fc {
extern "C" {

extern void *data_02097e4c;
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void Ov009ActPair110_State21(Ov009ActVt_02217b58 *self) {
    VecFx32 v;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x482d, 0x15);
        self->speed = 0;
        self->friction = 0;
        self->velY = -0x71;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        st->timer++;
        if (st->timer > 0xb4) {
            func_ov000_0218996c(0x14, 0x3c);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            func_02065f88(5, &self->pos)->SetScaleAll(0x7000);
            self->fsm->timer = 0x29;
            self->fsm->st++;
            return;
        }
        if ((st->timer & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            switch (self->fsm->timer & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                a = 3;
                b = 0x19;
                break;
            case 0x20:
                break;
            case 0x30:
                a = 3;
                b = 0x32;
                break;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            func_ov000_0219b71c(&self->pos, &v, 0xc00, 0x1400, a, b);
            func_ov000_0218996c(6, 10);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        if ((u8)self->fsm->timer < 0x1f) {
            Ov003Actor_SetAlpha(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
}

}
}  // namespace m_0220f5fc

// ---- merged from ov009_0220f868.cpp
namespace m_0220f868 {
extern "C" {

extern BOOL func_ov000_021983b0(ActorSub40 *st, s32 a, s32 b, s32 c);

void Ov009ActPair110_StateHurt(Ov009ActVt_02217b58 *self) {
    ActorSub40 *st = self->fsm;
    VecFx32 d;
    switch (st->st) {
    case 0:
        self->unk_108 = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->fsm, 0x13, 1, 0)) {
            self->fsm->timer = 0x2d;
            self->fsm->st++;
            return;
        }
        self->unk_fc = self->pos;
        self->unk_fc.x += Rand_PlusMinus(0x1800);
        self->unk_fc.y -= 0x2333;
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x3c || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->unk_fc.x = self->unk_f0.x;
            self->unk_fc.y = self->unk_f0.y;
            self->unk_fc.z = self->unk_f0.z;
        }
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
        break;
    }
}

}
}  // namespace m_0220f868

// ---- merged from ov009_0220f9f4.cpp
namespace m_0220f9f4 {
extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217e08_Start(Ov009ActVt_02217e08 *self) {
    Ov003Actor *a;
    Ov003Actor_Start(self);
    self->target = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->target = a->id;
    }
}

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL func_ov000_021983b0(void *st, s32 a, s32 b, s32 c);
static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}


extern ActorGroup *ActorMgr_GetGroup(void *mgr, u16 id);

void Ov009ActVt_02217e08_Update(Ov009ActVt_02217e08 *self) {
    Ov003Actor *p;
    ActorGroup *g;
    Actor *a;
    if (!Ov009_GameIdle()) {
        return;
    }
    {
    u8 mode = self->fsm->current;
    self->unk_93_4 = 1;
    if (mode == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            if (self->kind != 0x541a) {
                Ov003Actor *t = Actor_GetTarget(self);
                if (Ov009_DistXZ(&self->pos, &t->pos) < 0x3800 && func_ov000_021983b0(self->fsm, 0x10, 4, 1)) {
                    self->fsm->flags |= 0x8000;
                    self->unk_b6 = 0x78;
                } else {
                    self->fsm->flags |= 0x10000;
                    self->unk_b6 = 0xb4;
                }
            } else {
                self->fsm->flags |= 0x20000;
                self->unk_b6 = 0x96;
            }
        }
    }
    }
    if (self->kind != 0x541a) {
        return;
    }
    p = func_ov000_0219bf90();
    g = ActorMgr_GetGroup(data_ov000_021ccd68, 0x4000);
    if (p == NULL || g == NULL || (a = g->head) == NULL) {
        return;
    }
    do {
        if (a->kind == 0x4006 && a->targetObj != NULL && a->targetObj->target == p->id &&
            a->hit != NULL) {
            a->hit->unk_30 = 0;
        }
        a = (a != NULL) ? a->next : g->head;
    } while (a != NULL);
}

extern void *data_02097e4c;
extern char data_ov009_022179a8[];
extern char data_ov009_022179ae[];
extern void *func_ov000_02191318(void *m, s32 a);
extern void func_ov000_02191690(void *m);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void Ov009ActVt_02217e08_State20(Ov009ActVt_02217e08 *self) {
    ActorSub40 *st = self->fsm;
    ActorSub44 *s44;
    ActorSub48 *s48;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179a8, 0x1000, 0);
        func_ov000_02191318(self->model, 0x35000);
        func_ov000_02191690(self->model);
        self->unk_f0 = self->pos.y;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->hit;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
        if (self->kind == 0x541a) {
            s48 = self->hit;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
            self->pos.y += 0x10000;
        } else {
            self->pos.y += 0x8000;
        }
        self->velY = -0x19a;
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0x52;
        func_02049a48(data_02097e4c, 0x63, -1, -1, -1);
        self->fsm->st++;
        break;
    case 1:
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (!(self->hit->unk_50 & 0x20000000)) {
            if (self->unk_f0 < self->pos.y) {
                return;
            }
            if (self->velY >= 0) {
                return;
            }
        }
        func_ov000_02190cb0(self->model, data_ov009_022179ae, 0x200, 0);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        func_ov000_0218996c(0x14, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        self->fsm->st++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x1e) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_0220f9f4

// ---- merged from ov009_0220fe78.cpp
namespace m_0220fe78 {
extern "C" {

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);

void Ov009ActVt_02217e08_StateIdle(Ov009ActVt_02217e08 *self) {
    Ov003Actor_StateIdle(self);
    Actor_TurnToActor(self, Actor_GetTarget(self), self->unk_b0->unk_02);
}

}
}  // namespace m_0220fe78

// ---- merged from ov009_0220fea4.cpp
namespace m_0220fea4 {
extern "C" {

extern void *data_02097e4c;
extern char data_ov009_022179a8[];
extern char data_ov009_022179b4[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191690(void *p);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_ov000_0218d46c(Ov003Actor *a, u16 id, s32 msg);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern BOOL func_ov000_0219aae8(Actor *self, Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218996c(s32 a, s32 b);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov003Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

static inline void Ov009_Sub(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

void Ov009ActVt_02217e08_StateAttack2(Ov009ActVt_02217e08 *self) {
    VecFx32 p;
    VecFx32 d;
    Ov003Actor *t;
    Ov003Actor *o;
    ActorSub40 *st;
    ActorSub44 *s;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    o = Ov009_FindActor(self->target_id);
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179a8, 0x200, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer == 0x13) {
            func_ov000_02191708(self->model);
            self->velY = 0x8cd;
            self->gravity = 0x29;
            func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->fsm->st++;
        }
        break;
    case 2:
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (self->model->anim_state == 1) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->height + 0x1000;
            o = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, 0x482f, &p, &self->rot_x, t));
            o->speed = 0;
            o->velY = 0;
            o->friction = 0;
            func_ov000_0218d46c(o, self->id, 9);
            { s32 tx = t->pos.x; s32 ty = t->pos.y; s32 tz = t->pos.z; d.x = tx - self->pos.x; d.y = ty - self->pos.y; d.z = tz - self->pos.z; }
            d.y = 0;
            VEC_MultAdd(0xe66, &d, &self->pos, &self->pos);
            Actor_TurnToActor(self, t, 0x1000);
            self->model->visible = 0;
            func_ov000_02191690(self->model);
        }
        if (self->velY < 0) {
            self->gravity = 0x7b;
            self->model->visible = true;
        }
        if (self->hit->unk_50 & 0x20000000) {
            func_02065f88(0x66, &self->pos)->SetScaleXYZ(0x1c00, 0x1c00, 0x1c00);
            if (t != NULL) {
                func_ov000_0219aae8(self, self, 0x1e, 0x20, (u16)(1 << (t->id >> 12)), 0, 0, 0x3400, 0x2800, 0x64, 0x1000);
            }
            func_ov000_0218996c(0xf, 0x1e);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            self->fsm->st++;
            self->fsm->timer = 0;
            self->hit->unk_9a_5 = 1;
            s = self->unk_44;
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
        }
        break;
    case 3:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_02191708(self->model);
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 4:
        if (self->model->anim_state == 2 && o != NULL) {
            func_ov000_0218d46c(o, self->id, 0xb);
            o->target = self->target;
            o->rot_x = self->rot_x;
            o->rot_y = self->rot_y;
            o->rot_z = self->rot_z;
        }
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x89, 0);
            func_ov000_021915a0(self->model);
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    case 5:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    if (o != NULL && Ov009_Mode(o) == 9) {
        VecFx32 q;
        q.x = self->pos.x; q.y = self->pos.y; q.z = self->pos.z;
        q.y += self->height + 0x1000;
        o->pos.x = q.x; o->pos.y = q.y; o->pos.z = q.z;
        o->speed = 0;
        o->velY = 0;
        o->friction = 0;
    }
}

}
}  // namespace m_0220fea4

// ---- merged from ov009_02210348.cpp
namespace m_02210348 {
extern "C" {

extern void *data_02097e4c;
extern char data_ov009_022179a8[];
extern char data_ov009_022179b4[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_021911c8(void *m, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d46c(Ov003Actor *a, u16 id, s32 msg);
static inline Ov003Actor *Ov009_FindActor5(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov009ActVt_02217e08_StateAttack3(Ov009ActVt_02217e08 *self) {
    VecFx32 p;
    VecFx32 q;
    Ov003Actor *t = Actor_GetTarget(self);
    Ov003Actor *h;
    if (t == NULL) {
        return;
    }
    Ov009_FindActor5(self->target_id);
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179a8, 0x2ab, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    case 1: {
        ActorSub44 *s44;
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer != 0x16) {
            return;
        }
        self->velY = 0x8cd;
        self->gravity = 0x3e;
        func_02049a48(data_02097e4c, 0x42, -1, -1, -1);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->fsm->st++;
        return;
    }
    case 2: {
        ActorSub44 *s44;
        Actor_Move(self, 0);
        if (self->model->anim_state == 1) {
            func_ov000_021911c8(self->model, 0x200);
        }
        if (self->velY < 0) {
            self->gravity = 0x52;
        }
        if (self->unk_f0 < self->pos.y) {
            return;
        }
        if (self->velY >= 0) {
            return;
        }
        func_02065f88(0x66, &self->pos)->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        func_ov000_0218996c(0x12, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        p.x = t->pos.x;
        p.y = t->pos.y;
        p.z = t->pos.z;
        p.y += self->height + 0x1000;
        h = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, 0x482f, &p, &self->rot_x, t));
        h->speed = 0;
        h->velY = -0x19a;
        h->friction = 0;
        h->gravity = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->target = self->target;
        func_ov000_021911c8(self->model, 0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    }
    case 3:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        q.x = t->pos.x;
        q.y = t->pos.y;
        q.z = t->pos.z;
        q.y += self->height + 0x1000;
        h = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, 0x482f, &q, &self->rot_x, t));
        h->speed = 0;
        h->velY = -0x19a;
        h->friction = 0;
        h->gravity = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->target = self->target;
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x89, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    case 4: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        return;
    }
    }
}

}
}  // namespace m_02210348

// ---- merged from ov009_022106e4.cpp
namespace m_022106e4 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);

void Ov009ActVt_02217e08_StateHurt(Ov009ActVt_02217e08 *self) {
    if (self->fsm->st == 0) {
        if (self->kind != 0x541a) {
            func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0x42, &self->pos, 0);
        }
    }
    Ov003Actor_StateHurt(self);
    if (self->fsm->current == 1) {
        self->unk_b6 = 0x3c;
    }
}

}
}  // namespace m_022106e4

// ---- merged from ov009_02210760.cpp
namespace m_02210760 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);

void Ov009ActVt_02217e08_StateKnockBack(Ov009ActVt_02217e08 *self) {
    if (self->fsm->st == 0) {
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    Ov003Actor_StateKnockBack(self);
    if (self->fsm->current == 1) {
        self->unk_b6 = 0x3c;
    }
}

}
}  // namespace m_02210760

// ---- merged from ov009_022107b4.cpp
namespace m_022107b4 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov009ActVt_02217e08_StateDown(Ov009ActVt_02217e08 *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *a;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        a = Ov009_FindActor(self->target_id);
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, a);
            a->vfunc_08();
        }
    }
    Ov003Actor_StateDown(self);
}

void Ov009ActVt_02217e08_StateDie(Ov009ActVt_02217e08 *self) {
    if (self->fsm->st == 0) {
        Ov003Actor *a;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4006, 0x15);
        a = Ov009_FindActor(self->target_id);
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, a);
            a->vfunc_08();
        }
        self->unk_ea |= 0x400;
    }
    Ov003Actor_StateDie(self);
}


void Ov009ActVt_02217c04_Start(Ov009ActVt_02217c04 *self) {
    ActorSub48 *s48;
    GroupNode *p;
    Ov003Actor_Start(self);
    s48 = self->hit;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
    }
    self->unk_f0 = self->pos;
    self->unk_93_4 = 1;
    func_ov000_0219a2f4(&self->pos, 0x5000, -0xa000);
    self->pos.y += 0x4800;
    self->unk_ea |= 0x400;
}

extern Ov003Actor *func_ov000_0219bf90(void);
static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}
static inline s32 Ov009_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}
void Ov009ActVt_02217c04_Update(Ov009ActVt_02217c04 *self) {
    VecFx32 d;
    Ov003Actor *pl;
    VecFx32 t;
    if (!Ov009_GameIdle()) {
        return;
    }
    if ((u8)(self->fsm->current + 0xff) > 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    pl = func_ov000_0219bf90();
    self->target = pl->id;
    t = pl->pos;
    if (Ov009_DistXZ(&self->pos, &t) < 0x7000) {
        self->fsm->flags |= 0x8000;
        self->unk_b6 = 0x96;
        return;
    }
    d.x = t.x - self->unk_f0.x;
    d.y = t.y + 0x4800 - self->unk_f0.y;
    d.z = t.z - self->unk_f0.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x5000, &d, &self->unk_f0, &d);
    if (Ov009_DistXZ(&d, &self->pos) > 0x1800) {
        self->unk_b8 = d;
        self->fsm->flags |= 4;
    }
}
}
}  // namespace m_022107b4

// ---- merged from ov009_02210ba8.cpp
namespace m_02210ba8 {
extern "C" {

extern char data_ov009_022179b4[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);

void Ov009ActVt_02217c04_StateIdle(Ov009ActVt_02217c04 *self) {
    Ov003Actor *t;
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    }
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
}

extern void Actor_MoveToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_02217c04_StateMove(Ov009ActVt_02217c04 *self) {
    Ov003Param *p;
    VecFx32 v;
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    p = self->unk_b0;
    self->speed = p->unk_00;
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, p->unk_02);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    func_ov000_0219a2f4(&self->pos, 0x5000, -0xa000);
    self->pos.y += 0x4800;
}

}
}  // namespace m_02210ba8

// ---- merged from ov009_02210ce8.cpp
namespace m_02210ce8 {
extern "C" {

extern char data_ov009_022179ba[];
extern void *data_02097e4c;
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void func_ov000_0219a210(VecFx32 *v, const VecFx32 *a, u16 b);
extern void func_ov000_0218d46c(Ov003Actor *a, u16 id, s32 b);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);

void Ov009ActVt_02217c04_StateAttack(Ov009ActVt_02217c04 *self) {
    Ov003Actor *t = Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179ba, 0x2ab, 0);
        self->fsm->st++;
        break;
    case 1:
        if (self->model->anim_state == 1) {
            VecFx32 p;
            Ov003Actor *a;
            p = self->pos;
            {
                VecFx32 o = data_ov009_02216028;
                func_ov000_0219a210(&p, &o, self->rot_y);
            }
            a = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, 0x4802, &p, &self->rot_x, t));
            if (a != NULL) {
                a->speed = Rand_UpTo(0x80) + 0x19a;
                a->velY = 0x19a;
                a->friction = 0;
                a->gravity = 0x52;
                func_ov000_0218d46c(a, self->id, 4);
            }
            func_02049f44(data_02097e4c, 0xb, &self->pos, 0);
            self->fsm->st++;
        } else {
            Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        }
        break;
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_02210ce8
