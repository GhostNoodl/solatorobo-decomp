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


extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

static inline BOOL Ov009Game_IsVer(Ov009Ver v) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = FALSE;
    if (g->unk_ca.c[0] == v.a && g->unk_ca.c[1] == v.b && g->unk_ca.c[2] == v.c) {
        r = TRUE;
    }
    return r;
}

void func_ov009_0220d2d8(Ov009ActPair110 *self) {
    void *saved;
    u8 *p;
    func_ov003_021d112c(self);
    if (Ov009Game_IsVer(data_ov009_02216004[0])) {
        u16 v = self->unk_50[1] >> 1;
        self->unk_50[1] = v;
        self->unk_50[0] = v;
    }
    self->unk_f0 = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *s = self->unk_48;
        if (s != NULL) {
            func_0203f2b8(s);
            Heap_Free(s);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    self->unk_fc = self->unk_f0;
    self->unk_108 = 0;
    self->unk_93_4 = 1;
    self->unk_ea |= 0x100;
    self->unk_10c = -1;
}

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void SndMgr_StopSeqArc(void *mgr, s32 h);

void Ov009ActVt_02217f60_Update(Ov009ActVt_02217f60 *self) {
    Ov009Actor *a;
    u16 t;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
        if (func_ov000_021b4738(a) && self->unk_10c >= 0) {
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            self->unk_10c = -1;
        }
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x4000;
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

void func_ov009_0220d5f8(Ov009ActPair110 *self) {
    Ov009Vec d;
    switch (self->unk_40->state) {
    case 0:
        self->unk_10c = func_02049afc(data_02097e4c, 0x3f);
        self->unk_40->state++;
        break;
    case 1:
        d.x = self->unk_f0.x - self->pos.x;
        d.y = self->unk_f0.y - self->pos.y;
        d.z = self->unk_f0.z - self->pos.z;
        VEC_MultAdd(0x35, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &self->unk_f0) >= 0x333) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        self->pos = self->unk_f0;
        self->unk_b6 = 0x1e;
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_0204a058(data_02097e4c, self->unk_10c, 0x28, 0x1c2);
        break;
    }
}

extern Ov009Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(Ov009Actor *a, u16 id);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void func_ov009_0220d730(Ov009ActVt_02217f60 *self) {
    Ov009Vec d;
    if (VEC_Distance(&self->pos, &self->unk_fc) < 0x19a) {
        self->unk_9c = Rand_PlusMinus(0x29) + 0x8f;
        self->unk_fc = self->unk_f0;
        if (!Ov009_GameIdle() || Ov009Game_IsPaused(data_ov000_021ccd54) || self->unk_40->unk_13 == 0x15) {
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
    VEC_MultAdd(self->unk_9c, &d, &self->pos, &self->pos);
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
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220d90c(Ov009ActVt_02217f60 *self) {
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Vec a;
    Ov009Vec b;
    Ov009Rot r;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    VEC_Add(&self->pos, &data_ov009_02216010, &a);
    r.y = FX_Atan2(a.x - t->pos.x, a.z - t->pos.z) + 0x7c00 + Rand_UpTo(0x800);
    r.x = 0;
    r.z = 0;
    o = func_ov000_0219be1c(0x480b, &a, &r, self->id, self->unk_90);
    if (o != NULL) {
        o->unk_60 = data_ov009_022160d0;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
        VEC_Add(&self->pos, &data_ov009_02216010, &b);
        func_02065f88(0x325, &b)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
}  // namespace m_0220d90c

// ---- merged from ov009_0220da24.cpp
namespace m_0220da24 {
extern "C" {

extern BOOL func_ov000_021983b0(Ov009Sub40 *st, s32 a, s32 b, s32 c);

void func_ov009_0220da24(Ov009ActVt_02217f60 *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        self->unk_108 = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->unk_40, 0x13, 1, 0)) {
            self->unk_40->timer = 0x3c;
            self->unk_40->state++;
            return;
        }
        self->unk_fc = self->pos;
        self->unk_fc.x += 0x2800;
        self->unk_fc.y -= 0x2000;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x41 || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
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
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220dba4(Ov009Actor *self) {
    Ov009Vec p;
    Ov009V *e;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x480b, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x482e, 0x15);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_ov000_0218996c(0x10, 0x3c);
        self->unk_ea_6 = 1;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (self->unk_40->timer >= 10) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state++;
        }
        break;
    }
    self->v50();
    st = self->unk_40;
    st->timer++;
    if (st->timer != 0x78) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.x += Rand_PlusMinus(self->unk_64 >> 1);
    p.y += Rand_PlusMinus(self->unk_68);
    p.z += Rand_UpTo(0x1000) + 0x6000;
    e = func_02065f88(0x325, &p);
    e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    self->unk_40->timer = 0;
}

extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
void func_ov009_0220dd84(Ov009ActVt_02217f60 *self) {
    Ov009Vec p0;
    Ov009Vec v;
    Ov009Vec p1;
    Ov009Vec d;
    Ov009Sub40 *st;
    u16 t;
    d.x = 0x2cd - self->unk_9c;
    d.y = 0x148 - 0x2cd - self->unk_a0;
    d.z = -self->unk_a4;
    VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    st = self->unk_40;
    st->timer++;
    t = st->timer;
    if (t == 300) {
        SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
    }
    if (t > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
    }
    if ((t & 0x3f) == 1) {
        Ov009V *e;
        p0.x = self->pos.x;
        p0.y = self->pos.y;
        p0.z = self->pos.z;
        p0.x += Rand_PlusMinus(self->unk_64 >> 1);
        p0.y += Rand_PlusMinus(self->unk_68);
        p0.z += Rand_UpTo(0x1000) + 0x6000;
        e = func_02065f88(0x325, &p0);
        e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        e->v14(0x1ccd, 0x1ccd, 0x1ccd);
    }
    if ((t & 0xf) == 0) {
        s32 a = -1;
        s32 b = 100;
        switch (self->unk_40->timer & 0x3f) {
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

extern u8 *Group_FindNode(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void Ov009ActVt_02217eb4_Start(Ov009ActVt_02217eb4 *self) {
    void *saved;
    u8 *p;
    func_ov003_021d112c(self);
    self->unk_f0 = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *s = self->unk_48;
        if (s != NULL) {
            func_0203f2b8(s);
            Heap_Free(s);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
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

extern void func_ov003_021d6868(Ov009Actor *self, s32 a);
extern BOOL func_ov000_0218cea4(Ov009Actor *self);

void Ov009ActVt_02217eb4_Draw(Ov009ActVt_02217eb4 *self) {
    Ov009Mtx33 m;
    Ov009Mtx33 t;
    if (self->unk_50 != NULL && *self->unk_50 == 0) {
        func_ov003_021d6868(self, 0x3def);
    }
    self->unk_93_0 = 1;
    MTX_Identity33_((MtxFx33 *)&m);
    MTX_RotZ33_((MtxFx33 *)&t, OV009_SIN(self->rot[2]), OV009_COS(self->rot[2]));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MTX_RotX33_((MtxFx33 *)&t, OV009_SIN(self->rot[0]), OV009_COS(self->rot[0]));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MTX_RotY33_((MtxFx33 *)&t, OV009_SIN(self->rot[1]), OV009_COS(self->rot[1]));
    MTX_Concat33((MtxFx33 *)&m, (MtxFx33 *)&t, (MtxFx33 *)&m);
    MI_Copy36B(&m, (u8 *)self->unk_38 + 0x84);
    self->unk_38->unk_78 = self->pos;
    func_ov000_0218cea4(self);
}

extern void func_ov000_0218d7e8(Ov009Actor *self, s32 a);
extern void func_ov003_021d2e28(Ov009Actor *self);

void func_ov009_0220e220(Ov009ActVt_02217eb4 *self) {
    Ov009Sub40 *s = self->unk_40;
    BOOL run = TRUE;
    u64 f = s->flags;
    u8 k = s->unk_13;
    if ((f & 0x40000) || (f & 0x80000)) {
        if (k == 0xf || k == 0xe || k == 0x21 || k == 0x20 || k == 0x12 || k == 0x13) {
            run = FALSE;
            func_ov000_0218d7e8(self, k);
        }
    }
    if (run) {
        func_ov003_021d2e28(self);
    }
}

}
}  // namespace m_0220e0e4

// ---- merged from ov009_0220e2a4.cpp
namespace m_0220e2a4 {
extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217eb4_Update(Ov009ActVt_02217eb4 *self) {
    u8 k;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->unk_40->unk_13;
    if (k == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 == 0) {
            Ov009Actor *a;
            s32 r;
            if (self->unk_108 != 0) {
                if (VEC_Distance(&self->pos, &self->unk_f0) < 0x5000) {
                    self->unk_108 = 0;
                } else {
                    self->unk_b6 = 0x1e;
                    return;
                }
            }
            self->unk_90 = 0xffff;
            a = func_ov000_0219bf90();
            if (a != NULL) {
                self->unk_90 = a->id;
            }
            r = Rand_UpTo(10);
            if (self->unk_109 == 2 || r % 3 == 0) {
                self->unk_40->flags |= 0x4000;
                self->unk_109 = 0;
            } else {
                self->unk_40->flags |= 0x8000;
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

void func_ov009_0220e434(Ov009ActVt_02217eb4 *self) {
    Ov009Vec d;
    d.x = self->unk_f0.x - self->pos.x;
    d.y = self->unk_f0.y - self->pos.y;
    d.z = self->unk_f0.z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
    if (VEC_Distance(&self->pos, &self->unk_f0) >= 0xcd) {
        return;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
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


void func_ov009_0220e4fc(Ov009ActVt_02217eb4 *self) {
    Ov009Vec d;
    if (VEC_Distance(&self->pos, &self->unk_fc) < 0xcd) {
        Ov009Sub40 *st = self->unk_40;
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
            self->unk_40->timer = 0;
        }
    }
    d.x = self->unk_fc.x - self->pos.x;
    d.y = self->unk_fc.y - self->pos.y;
    d.z = self->unk_fc.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}

extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
struct Ov009Rot3 {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov009_0220e5f0(Ov009ActVt_02217eb4 *self) {
    Ov009Vec d;
    Ov009Rot3 r;
    Ov009Sub40 *st;
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0: {
        self->unk_fc.x = self->pos.x + 0x1e000;
        self->unk_fc.y = 0x5000;
        self->unk_fc.z = self->pos.z - 0xa000;
        self->unk_b8.x = self->unk_fc.x;
        self->unk_b8.y = self->unk_fc.y;
        self->unk_b8.z = self->unk_fc.z;
        st->state++;
        self->unk_40->timer = Rand_UpTo(0x14) + 100;
        break;
    }
    case 1:
        self->rot[2] = func_01ffc128(0xd8e4, self->rot[2], 0x52, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        r.y = self->rot[1];
        r.x = 0;
        r.z = 0;
        func_ov000_0219be1c(0x482e, &self->pos, &r, self->id, self->unk_90);
        func_02065f88(0x325, &self->pos)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
        self->unk_40->state++;
        self->unk_40->timer = Rand_UpTo(0x14) + 0x46;
        break;
    case 2:
        self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x11f, &d, &self->pos, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        self->unk_fc.x = self->unk_f0.x;
        self->unk_fc.y = self->unk_f0.y;
        self->unk_fc.z = self->unk_f0.z;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 3: {
        s32 dist;
        self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0x266, &d, &self->pos, &self->pos);
        dist = VEC_Distance(&self->pos, &self->unk_fc);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x78 || dist < 0x3000) {
            self->rot[2] = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
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

extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219a210(Ov009Vec *v, const void *a, u16 b);
extern u8 data_ov009_0221610c[];

struct Ov009Bits_cc {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
};

void func_ov009_0220e954(Ov009ActVt_02217eb4 *self) {
    Ov009Vec d;
    Ov009Vec p;
    Ov009Actor *t;
    Ov009Sub40 *st;
    Ov009Sub44 *s;
    Ov009Actor *a;
    s32 dist;
    u16 tm;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    st = self->unk_40;
    switch (st->state) {
    case 0:
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0x11f;
        self->unk_a0 = 0x52;
        self->unk_98 = 0x4000;
        st->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        Actor_Move((Actor *)self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xb4) {
            self->unk_9c = 0xa4;
            self->unk_a0 = 0x52;
            self->unk_98 = 0x58e4;
            self->unk_40->state++;
            self->unk_40->timer = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
        }
        if (self->unk_40->timer > 0x78) {
            Actor_TurnToActor(self, t, 0x29);
            self->rot[2] = func_01ffc128(0x71c, self->rot[2], 0x14, 1, 0x8000);
        } else {
            self->rot[2] = func_01ffc128(0xeaab, self->rot[2], 0x52, 1, 0x8000);
        }
        break;
    case 2:
        Actor_TurnToActor(self, t, 0xa4);
        self->rot[2] = func_01ffc128(0xe39, self->rot[2], 0x52, 1, 0x8000);
        self->rot[0] = func_01ffc128(0x11c7, self->rot[0], 0x29, 1, 0x8000);
        Actor_Move((Actor *)self, 0);
        if (self->pos.y > 0x6000) {
            self->pos.y = 0x6000;
        }
        st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x5a) {
            return;
        }
        if (self->pos.y < 0x5000) {
            return;
        }
        self->unk_9c = 0x333;
        self->unk_a0 = -0x52;
        self->unk_a4 = 0x1052;
        self->unk_98 = self->rot[1];
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 3:
        st->timer++;
        tm = st->timer;
        if (Ov009_GameIdle() && tm > 10 && tm < 100 && tm % 10 == 0) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            func_ov000_0219a210(&p, &data_ov009_0221601c, self->rot[1]);
            a = func_ov000_0219be1c(0x4800, &p, self->rot, self->id, self->unk_90);
            if (a != NULL) {
                a->unk_60 = data_ov009_0221610c;
                ((Ov009Bits_cc *)((u8 *)a + 0xcc))->b3 = 0;
            }
        }
        Actor_Move((Actor *)self, 0);
        if (tm <= 200) {
            return;
        }
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->pos.z = self->unk_f0.z;
        self->pos.x = self->unk_f0.x - 0xf000;
        self->pos.y = self->unk_f0.y + 0x1e000;
        self->rot[1] = 0xc000;
        self->rot[0] = 0;
        self->rot[2] = 0xeaab;
        self->unk_40->state++;
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
            self->rot[2] = func_01ffc128(0, self->rot[2], 0x29, 1, 0x8000);
        }
        if (dist < 0x19a) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_0220e954

// ---- merged from ov009_0220ee10.cpp
namespace m_0220ee10 {
extern "C" {

void func_ov009_0220ee10(Ov009ActVt_02217eb4 *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        self->unk_fc = self->pos;
        self->unk_fc.x += 0x2000;
        self->unk_fc.y -= 0x1000;
        st->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x28 || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
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
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
void func_ov009_0220ef1c(Ov009ActVt_02217eb4 *self) {
    Ov009Vec v;
    Ov009Vec d;
    Ov009Sub40 *st;
    u16 t;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        *self->unk_50 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_ea_6 = 1;
        self->unk_4c->target = 0xffff;
        {
            s32 z = Rand_PlusMinus(0x29);
            s32 x = Rand_PlusMinus(0x29);
            self->unk_a0 = -0x71;
            self->unk_a4 = z;
            self->unk_9c = x;
        }
        self->unk_40->state++;
        break;
    }
    case 1:
        d.x = 0x185 - self->unk_9c;
        d.y = -0x8f - self->unk_a0;
        d.z = -self->unk_a4;
        VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        st = self->unk_40;
        st->timer++;
        t = st->timer;
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        if (t > 0x78) {
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->v14(0x6000, 0x6000, 0x6000);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((t & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            u32 r = self->unk_40->timer & 0x3f;
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
        if ((u8)self->unk_40->timer < 0x1f) {
            func_ov003_021d6954(self, self->unk_40->timer);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        }
        break;
    }
}

}
}  // namespace m_0220ee10

// ---- merged from ov009_0220f1ac.cpp
namespace m_0220f1ac {
extern "C" {


void func_ov009_0220f1ac(Ov009ActVt_02217eb4 *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    d.x = 0x266 - self->unk_9c;
    d.y = -0x15c - self->unk_a0;
    d.z = -self->unk_a4;
    VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    st = self->unk_40;
    st->timer++;
    if (st->timer > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
    }
}

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void SndMgr_StopSeqArc(void *mgr, s32 h);

void Ov009ActPair110_Update(Ov009ActVt_02217b58 *self) {
    Ov009Actor *a;
    u16 pct;
    s32 n;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
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
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x4000;
    pct = (self->unk_50[0] * 100) / self->unk_50[1];
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


void func_ov009_0220f3ec(Ov009ActVt_02217b58 *self) {
    Ov009Vec d;
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

extern Ov009Vec data_ov009_02216040;
extern Ov009Vec data_ov009_0221604c;
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);

void func_ov009_0220f4b0(Ov009ActVt_02217b58 *self) {
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Vec *off;
    Ov009Vec a;
    Ov009Vec b;
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
    o = func_ov003_021d69f0(self, 0x482d, &a, &r, t);
    if (o != NULL) {
        o->unk_18 = 1;
        FLD(Ov009Bits16, o, 0xcc).b3 = 0;
    }
    func_02065f88(0x325, &b)->v34(0, (u16)(self->rot[1] + 0x8000), 0);
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
}  // namespace m_0220f4b0

// ---- merged from ov009_0220f5fc.cpp
namespace m_0220f5fc {
extern "C" {

extern void *data_02097e4c;
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_0220f5fc(Ov009ActVt_02217b58 *self) {
    Ov009Vec v;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x482d, 0x15);
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a0 = -0x71;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st->timer++;
        if (st->timer > 0xb4) {
            func_ov000_0218996c(0x14, 0x3c);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            SndMgr_StopSeqArc(data_02097e4c, self->unk_10c);
            func_02065f88(5, &self->pos)->v0c(0x7000);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((st->timer & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            switch (self->unk_40->timer & 0x3f) {
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
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
            self->v08();
            return;
        }
        if ((u8)self->unk_40->timer < 0x1f) {
            func_ov003_021d6954(self, self->unk_40->timer);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    }
}

}
}  // namespace m_0220f5fc

// ---- merged from ov009_0220f868.cpp
namespace m_0220f868 {
extern "C" {

extern BOOL func_ov000_021983b0(Ov009Sub40 *st, s32 a, s32 b, s32 c);

void func_ov009_0220f868(Ov009ActVt_02217b58 *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        self->unk_108 = 0;
        if (func_ov000_021983b0(st, 0x12, 1, 0) || func_ov000_021983b0(self->unk_40, 0x13, 1, 0)) {
            self->unk_40->timer = 0x2d;
            self->unk_40->state++;
            return;
        }
        self->unk_fc = self->pos;
        self->unk_fc.x += Rand_PlusMinus(0x1800);
        self->unk_fc.y -= 0x2333;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x3c || VEC_Distance(&self->pos, &self->unk_fc) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
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

extern Ov009Actor *func_ov000_0219bf90(void);

void Ov009ActVt_02217e08_Start(Ov009ActVt_02217e08 *self) {
    Ov009Actor *a;
    func_ov003_021d112c(self);
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
}

extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern BOOL func_ov000_021983b0(void *st, s32 a, s32 b, s32 c);
static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

struct Ov009Group {
    u8 unk_00[0xc];
    Ov009Actor *head;
};

extern Ov009Group *ActorMgr_GetGroup(void *mgr, u16 id);

void Ov009ActVt_02217e08_Update(Ov009ActVt_02217e08 *self) {
    Ov009Actor *p;
    Ov009Group *g;
    Ov009Actor *a;
    if (!Ov009_GameIdle()) {
        return;
    }
    {
    u8 mode = self->unk_40->unk_13;
    self->unk_93_4 = 1;
    if (mode == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            if (self->kind != 0x541a) {
                Ov009Actor *t = Actor_GetTarget(self);
                if (Ov009_DistXZ(&self->pos, &t->pos) < 0x3800 && func_ov000_021983b0(self->unk_40, 0x10, 4, 1)) {
                    self->unk_40->flags |= 0x8000;
                    self->unk_b6 = 0x78;
                } else {
                    self->unk_40->flags |= 0x10000;
                    self->unk_b6 = 0xb4;
                }
            } else {
                self->unk_40->flags |= 0x20000;
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
        if (a->kind == 0x4006 && a->unk_4c != NULL && a->unk_4c->target == p->id &&
            a->unk_48 != NULL) {
            a->unk_48->unk_30 = 0;
        }
        a = (a != NULL) ? ((Ov009Actor *)a->unk_08) : g->head;
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
void func_ov009_0220fc38(Ov009ActVt_02217e08 *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Sub44 *s44;
    Ov009Sub48 *s48;
    switch (st->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x1000, 0);
        func_ov000_02191318(self->unk_38, 0x35000);
        func_ov000_02191690(self->unk_38);
        self->unk_f0 = self->pos.y;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
        if (self->kind == 0x541a) {
            s48 = self->unk_48;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
            self->pos.y += 0x10000;
        } else {
            self->pos.y += 0x8000;
        }
        self->unk_a0 = -0x19a;
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        func_02049a48(data_02097e4c, 0x63, -1, -1, -1);
        self->unk_40->state++;
        break;
    case 1:
        Actor_Move((Actor *)self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            if (self->unk_f0 < self->pos.y) {
                return;
            }
            if (self->unk_a0 >= 0) {
                return;
            }
        }
        func_ov000_02190cb0(self->unk_38, data_ov009_022179ae, 0x200, 0);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        func_ov000_0218996c(0x14, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        self->unk_40->state++;
        break;
    case 2:
        st->timer++;
        if (st->timer > 0x1e) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_0220f9f4

// ---- merged from ov009_0220fe78.cpp
namespace m_0220fe78 {
extern "C" {

extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_0220fe78(Ov009ActVt_02217e08 *self) {
    func_ov003_021d3524(self);
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
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191690(void *p);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern BOOL func_ov000_0219aae8(Ov009Obj *self, Ov009Obj *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218996c(s32 a, s32 b);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline s32 Ov009_Mode(Ov009Actor *a) {
    return a->unk_40 != NULL ? a->unk_40->unk_13 : 0;
}

static inline void Ov009_Sub(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

void func_ov009_0220fea4(Ov009ActVt_02217e08 *self) {
    Ov009Vec p;
    Ov009Vec d;
    Ov009Actor *t;
    Ov009Actor *o;
    Ov009Sub40 *st;
    Ov009Sub44 *s;
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    o = Ov009_FindActor(self->target_id);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x200, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer == 0x13) {
            func_ov000_02191708(self->unk_38);
            self->unk_a0 = 0x8cd;
            self->unk_a8 = 0x29;
            func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->unk_40->state++;
        }
        break;
    case 2:
        Actor_Move((Actor *)self, 0);
        func_ov000_021987b8(self->unk_48, 0, 0, 0);
        if (self->unk_38->anim_state == 1) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->unk_68 + 0x1000;
            o = func_ov003_021d69f0(self, 0x482f, &p, self->rot, t);
            o->unk_9c = 0;
            o->unk_a0 = 0;
            o->unk_a4 = 0;
            func_ov000_0218d46c(o, self->id, 9);
            { s32 tx = t->pos.x; s32 ty = t->pos.y; s32 tz = t->pos.z; d.x = tx - self->pos.x; d.y = ty - self->pos.y; d.z = tz - self->pos.z; }
            d.y = 0;
            VEC_MultAdd(0xe66, &d, &self->pos, &self->pos);
            Actor_TurnToActor(self, t, 0x1000);
            self->unk_38->unk_c2_0 = 0;
            func_ov000_02191690(self->unk_38);
        }
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x7b;
            self->unk_38->unk_c2_0 = true;
        }
        if (self->unk_48->unk_50 & 0x20000000) {
            func_02065f88(0x66, &self->pos)->v14(0x1c00, 0x1c00, 0x1c00);
            if (t != NULL) {
                func_ov000_0219aae8(self, self, 0x1e, 0x20, (u16)(1 << (t->id >> 12)), 0, 0, 0x3400, 0x2800, 0x64, 0x1000);
            }
            func_ov000_0218996c(0xf, 0x1e);
            func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
            self->unk_40->state++;
            self->unk_40->timer = 0;
            self->unk_48->unk_9a_5 = 1;
            s = self->unk_44;
            s->unk_22_0 = true;
            s->unk_22_1 = 1;
        }
        break;
    case 3:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0xf) {
            func_ov000_02191708(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 4:
        if (self->unk_38->anim_state == 2 && o != NULL) {
            func_ov000_0218d46c(o, self->id, 0xb);
            o->unk_90 = self->unk_90;
            o->rot[0] = self->rot[0];
            o->rot[1] = self->rot[1];
            o->rot[2] = self->rot[2];
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    case 5:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    if (o != NULL && Ov009_Mode(o) == 9) {
        Ov009Vec q;
        q.x = self->pos.x; q.y = self->pos.y; q.z = self->pos.z;
        q.y += self->unk_68 + 0x1000;
        o->pos.x = q.x; o->pos.y = q.y; o->pos.z = q.z;
        o->unk_9c = 0;
        o->unk_a0 = 0;
        o->unk_a4 = 0;
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
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_021911c8(void *m, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
static inline Ov009Actor *Ov009_FindActor5(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02210348(Ov009ActVt_02217e08 *self) {
    Ov009Vec p;
    Ov009Vec q;
    Ov009Actor *t = Actor_GetTarget(self);
    Ov009Actor *h;
    if (t == NULL) {
        return;
    }
    Ov009_FindActor5(self->target_id);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179a8, 0x2ab, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 1: {
        Ov009Sub44 *s44;
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer != 0x16) {
            return;
        }
        self->unk_a0 = 0x8cd;
        self->unk_a8 = 0x3e;
        func_02049a48(data_02097e4c, 0x42, -1, -1, -1);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->state++;
        return;
    }
    case 2: {
        Ov009Sub44 *s44;
        Actor_Move((Actor *)self, 0);
        if (self->unk_38->anim_state == 1) {
            func_ov000_021911c8(self->unk_38, 0x200);
        }
        if (self->unk_a0 < 0) {
            self->unk_a8 = 0x52;
        }
        if (self->unk_f0 < self->pos.y) {
            return;
        }
        if (self->unk_a0 >= 0) {
            return;
        }
        func_02065f88(0x66, &self->pos)->v14(0x2000, 0x2000, 0x2000);
        func_ov000_0218996c(0x12, 0x3c);
        func_02049a48(data_02097e4c, 0x17, -1, -1, -1);
        p.x = t->pos.x;
        p.y = t->pos.y;
        p.z = t->pos.z;
        p.y += self->unk_68 + 0x1000;
        h = func_ov003_021d69f0(self, 0x482f, &p, self->rot, t);
        h->unk_9c = 0;
        h->unk_a0 = -0x19a;
        h->unk_a4 = 0;
        h->unk_a8 = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->unk_90 = self->unk_90;
        func_ov000_021911c8(self->unk_38, 0x1400);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    }
    case 3:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        q.x = t->pos.x;
        q.y = t->pos.y;
        q.z = t->pos.z;
        q.y += self->unk_68 + 0x1000;
        h = func_ov003_021d69f0(self, 0x482f, &q, self->rot, t);
        h->unk_9c = 0;
        h->unk_a0 = -0x19a;
        h->unk_a4 = 0;
        h->unk_a8 = 0x52;
        func_ov000_0218d46c(h, self->id, 4);
        h->unk_90 = self->unk_90;
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    case 4: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer <= 0x1e) {
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
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
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov003_021d4fd8(Ov009Actor *self);

void func_ov009_022106e4(Ov009ActVt_02217e08 *self) {
    if (self->unk_40->state == 0) {
        if (self->kind != 0x541a) {
            func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0x42, &self->pos, 0);
        }
    }
    func_ov003_021d4fd8(self);
    if (self->unk_40->unk_13 == 1) {
        self->unk_b6 = 0x3c;
    }
}

}
}  // namespace m_022106e4

// ---- merged from ov009_02210760.cpp
namespace m_02210760 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_02210760(Ov009ActVt_02217e08 *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
    }
    func_ov003_021d5348(self);
    if (self->unk_40->unk_13 == 1) {
        self->unk_b6 = 0x3c;
    }
}

}
}  // namespace m_02210760

// ---- merged from ov009_022107b4.cpp
namespace m_022107b4 {
extern "C" {

extern void *data_02097e4c;
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_022107b4(Ov009ActVt_02217e08 *self) {
    if (self->unk_40->state == 0) {
        Ov009Actor *a;
        func_02049f44(data_02097e4c, 0x63, &self->pos, 0);
        a = Ov009_FindActor(self->target_id);
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)a);
            a->v08();
        }
    }
    func_ov003_021d5900(self);
}

void func_ov009_02210848(Ov009ActVt_02217e08 *self) {
    if (self->unk_40->state == 0) {
        Ov009Actor *a;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4006, 0x15);
        a = Ov009_FindActor(self->target_id);
        if (a != NULL) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)a);
            a->v08();
        }
        self->unk_ea |= 0x400;
    }
    func_ov003_021d6054(self);
}

extern u8 *Group_FindNode(void *mgr, u16 id);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void Ov009ActVt_02217c04_Start(Ov009ActVt_02217c04 *self) {
    Ov009Sub48 *s48;
    u8 *p;
    func_ov003_021d112c(self);
    s48 = self->unk_48;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    self->unk_f0 = self->pos;
    self->unk_93_4 = 1;
    func_ov000_0219a2f4(&self->pos, 0x5000, -0xa000);
    self->pos.y += 0x4800;
    self->unk_ea |= 0x400;
}

extern Ov009Actor *func_ov000_0219bf90(void);
static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}
static inline s32 Ov009_DistXZ(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}
void Ov009ActVt_02217c04_Update(Ov009ActVt_02217c04 *self) {
    Ov009Vec d;
    Ov009Actor *pl;
    Ov009Vec t;
    if (!Ov009_GameIdle()) {
        return;
    }
    if ((u8)(self->unk_40->unk_13 + 0xff) > 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    pl = func_ov000_0219bf90();
    self->unk_90 = pl->id;
    t = pl->pos;
    if (Ov009_DistXZ(&self->pos, &t) < 0x7000) {
        self->unk_40->flags |= 0x8000;
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
        self->unk_40->flags |= 4;
    }
}
}
}  // namespace m_022107b4

// ---- merged from ov009_02210ba8.cpp
namespace m_02210ba8 {
extern "C" {

extern char data_ov009_022179b4[];
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_02210ba8(Ov009ActVt_02217c04 *self) {
    Ov009Actor *t;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    }
    t = Actor_GetTarget(self);
    if (t == NULL) {
        return;
    }
    Actor_TurnToActor(self, t, self->unk_b0->unk_02);
}

extern void Actor_MoveToPos(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_02210c18(Ov009ActVt_02217c04 *self) {
    Ov009Param *p;
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    p = self->unk_b0;
    self->unk_9c = p->unk_00;
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, p->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
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
extern Ov009Actor *Actor_GetTarget(Ov009Actor *self);
extern void Actor_TurnToActor(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219a210(Ov009Vec *v, const Ov009Vec *a, u16 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 b);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_02210ce8(Ov009ActVt_02217c04 *self) {
    Ov009Actor *t = Actor_GetTarget(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179ba, 0x2ab, 0);
        self->unk_40->state++;
        break;
    case 1:
        if (self->unk_38->anim_state == 1) {
            Ov009Vec p;
            Ov009Actor *a;
            p = self->pos;
            {
                Ov009Vec o = data_ov009_02216028;
                func_ov000_0219a210(&p, &o, self->rot[1]);
            }
            a = func_ov003_021d69f0(self, 0x4802, &p, self->rot, t);
            if (a != NULL) {
                a->unk_9c = Rand_UpTo(0x80) + 0x19a;
                a->unk_a0 = 0x19a;
                a->unk_a4 = 0;
                a->unk_a8 = 0x52;
                func_ov000_0218d46c(a, self->id, 4);
            }
            func_02049f44(data_02097e4c, 0xb, &self->pos, 0);
            self->unk_40->state++;
        } else {
            Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        }
        break;
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
}  // namespace m_02210ce8
