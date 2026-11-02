#ifndef OV011_H
#define OV011_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov011V {
public:
    virtual s32 v00(...);
    virtual s32 v04(...);
    virtual s32 v08(...);
    virtual s32 v0c(...);
    virtual s32 v10(...);
    virtual s32 v14(...);
    virtual s32 v18(...);
    virtual s32 v1c(...);
    virtual s32 v20(...);
    virtual s32 v24(...);
    virtual s32 v28(...);
    virtual s32 v2c(...);
    virtual s32 v30(...);
    virtual s32 v34(...);
    virtual s32 v38(...);
    virtual s32 v3c(...);
    virtual s32 v40(...);
    virtual s32 v44(...);
    virtual s32 v48(...);
    virtual s32 v4c(...);
    virtual s32 v50(...);
    virtual s32 v54(...);
    virtual s32 v58(...);
    virtual s32 v5c(...);
    virtual s32 v60(...);
    virtual s32 v64(...);
    virtual s32 v68(...);
    virtual s32 v6c(...);
    virtual s32 v70(...);
    virtual s32 v74(...);
    virtual s32 v78(...);
    virtual s32 v7c(...);
    virtual s32 v80(...);
    virtual s32 v84(...);
    virtual s32 v88(...);
    virtual s32 v8c(...);
    virtual s32 v90(...);
    virtual s32 v94(...);
    virtual s32 v98(...);
    virtual s32 v9c(...);
    virtual s32 va0(...);
    virtual s32 va4(...);
    virtual s32 va8(...);
    virtual s32 vac(...);
    virtual s32 vb0(...);
    virtual s32 vb4(...);
    virtual s32 vb8(...);
    virtual s32 vbc(...);
    virtual s32 vc0(...);
    virtual s32 vc4(...);
    virtual s32 vc8(...);
    virtual s32 vcc(...);
    virtual s32 vd0(...);
    virtual s32 vd4(...);
    virtual s32 vd8(...);
    virtual s32 vdc(...);
    virtual s32 ve0(...);
    virtual s32 ve4(...);
    virtual s32 ve8(...);
    virtual s32 vec(...);
    virtual s32 vf0(...);
    virtual s32 vf4(...);
    virtual s32 vf8(...);
    virtual s32 vfc(...);
    virtual s32 v100(...);
    virtual s32 v104(...);
    virtual s32 v108(...);
    virtual s32 v10c(...);
    virtual s32 v110(...);
    virtual s32 v114(...);
    virtual s32 v118(...);
    virtual s32 v11c(...);
    virtual s32 v120(...);
    virtual s32 v124(...);
    virtual s32 v128(...);
    virtual s32 v12c(...);
    virtual s32 v130(...);
    virtual s32 v134(...);
    virtual s32 v138(...);
    virtual s32 v13c(...);
    virtual s32 v140(...);
    virtual s32 v144(...);
    virtual s32 v148(...);
    virtual s32 v14c(...);
    virtual s32 v150(...);
    virtual s32 v154(...);
    virtual s32 v158(...);
    virtual s32 v15c(...);
    virtual s32 v160(...);
    virtual s32 v164(...);
    virtual s32 v168(...);
    virtual s32 v16c(...);
    virtual s32 v170(...);
    virtual s32 v174(...);
    virtual s32 v178(...);
    virtual s32 v17c(...);
    virtual s32 v180(...);
    virtual s32 v184(...);
    virtual s32 v188(...);
    virtual s32 v18c(...);
    virtual s32 v190(...);
    virtual s32 v194(...);
    virtual s32 v198(...);
    virtual s32 v19c(...);
    virtual s32 v1a0(...);
    virtual s32 v1a4(...);
    virtual s32 v1a8(...);
    virtual s32 v1ac(...);
    virtual s32 v1b0(...);
    virtual s32 v1b4(...);
    virtual s32 v1b8(...);
    virtual s32 v1bc(...);
    virtual s32 v1c0(...);
    virtual s32 v1c4(...);
    virtual s32 v1c8(...);
    virtual s32 v1cc(...);
    virtual s32 v1d0(...);
    virtual s32 v1d4(...);
    virtual s32 v1d8(...);
    virtual s32 v1dc(...);
    virtual s32 v1e0(...);
    virtual s32 v1e4(...);
    virtual s32 v1e8(...);
    virtual s32 v1ec(...);
    virtual s32 v1f0(...);
    virtual s32 v1f4(...);
    virtual s32 v1f8(...);
    virtual s32 v1fc(...);
};

// Compile-time size check: fails with a negative array size when sizeof(T) != n.
#define OV011_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

// Generic bitfield views
struct Ov011Flags {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 1;
    u16 b15 : 1;
};

struct Ov011Flags8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct Ov011Vec {
    s32 x;
    s32 y;
    s32 z;
};

static inline void Ov011_VecSet(Ov011Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// 12-byte block: assigning one copies with ldm/stm
struct Ov011Blk12 {
    s32 w[3];
};
#define OV011_BLKCPY(dst, src) (*(Ov011Blk12 *)(dst) = *(const Ov011Blk12 *)(src))

static inline s32 Ov011_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

// NitroSDK sin/cos table: s16 sin,cos pairs
extern "C" const s16 FX_SinCosTable_[];
#define OV011_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV011_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

struct Ov011Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

// The sub-object at Ov011Game54::unk_f4.
struct Ov011GameF4 {
    u8 unk_00[0x99];
    u8 unk_99;
    u8 unk_9a;
    u8 unk_9b;
    Ov011Flags8 unk_9c;
};

struct Ov011Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x47];
    Ov011GameF4 unk_f4;
};

extern "C" {
extern Ov011Game54 *data_ov000_021ccd54;
extern Ov011Heap *data_02097dd0;
extern void *data_ov000_021ccd68;
void Heap_Free(void *p);
void *Heap_Alloc(u32 size);
void Heap_FreeArray(void *p);
void *Heap_AllocArray(u32 size);
void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);
void *ActorMgr_GetActor(void *mgr, u16 id);
void *func_ov000_0219bf90(void);
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, u8 a);
}

static inline BOOL Ov011Game_IsBusy(Ov011Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov011Game_IsIdle(Ov011Game54 *g) {
    if (Ov011Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_GameIdle(void) {
    Ov011Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov011Game_IsIdle(g);
    }
    return TRUE;
}

struct Ov011Node {
    u16 id;
    u8 unk_02[0x2];
    Ov011Node *next;
};

struct Ov011LNode {
    u8 unk_00[0xc];
    Ov011LNode *next;
};

struct Ov011PNode {
    Ov011Vec v;
    Ov011PNode *next;
};

struct Ov011Ent {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
    u8 unk_01[0x3];
    Ov011PNode *unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u16 unk_30;
    u8 unk_32[0x2];
    s32 unk_34;
};
OV011_SIZE(Ov011Ent, 0x38);

struct Ov011E38 : public Ov011V {
    u8 unk_04[0x34];
};

struct Ov011E30 : public Ov011V {
    u8 unk_04[0x2c];
};


static inline void Ov011_SetLerp(s32 *p, s32 from, s32 to, s32 frames) {
    p[1] = to;
    p[0] = from;
    p[2] = (to - p[0]) / frames;
}

static inline Ov011PNode *Ov011_PushNode(Ov011PNode *head, Ov011PNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

struct Ov011Tw {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s32 unk_04;
    Ov011Vec v08;
    Ov011Vec v14;
    Ov011Vec v20;
};

struct Ov011TwObj {
    Ov011V *vt;
    Ov011Tw tw;
};

struct Ov011Sub38;

// The 0x138-byte animation object (func_ov000_0218e9c4); unk_00 is negative until it is ready.
struct Ov011Anim {
    s16 unk_00;
    u8 unk_02[0x2];
    u32 unk_04[0x4d];
};
OV011_SIZE(Ov011Anim, 0x138);

struct Ov011Model2 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011Sub38 *model;
    u8 m0c[0x30];
    u8 m3c[0x24];
};

#define OV011_TWV(p) ((Ov011V *)(p))
#define OV011_TW(p) ((Ov011Tw *)((u8 *)(p) + 4))

// The 0xe8-byte 3D model (func_ov000_0218fe1c), an object's unk_38.
struct Ov011Sub38 {
    void *unk_00;
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x2c];
    void *unk_50;
    u8 unk_54[0x24];
    Ov011Vec pos;
    u8 mtx[0x24];
    Ov011Vec scale;
    u16 unk_b4;
    u8 unk_b6[0x8];
    u8 alpha;
    u8 unk_bf;
    u8 unk_c0;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 4;
    u16 unk_c2_5 : 1;
    u16 unk_c2_6 : 2;
    u16 unk_c2_8 : 1;
    u16 unk_c2_9 : 2;
    u16 unk_c2_11 : 5;
    u8 unk_c4[0x24];
};

OV011_SIZE(Ov011Sub38, 0xe8);

// State/timer/flags block (reset by func_ov003_021da48c, ticked by func_ov003_021da40c);
// unk_13 is the state the owner's handler table is keyed on.
struct Ov011Sub40 {
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
};
OV011_SIZE(Ov011Sub40, 0x14);

struct Ov011Sub44 {
    u8 unk_00[0xc];
    Ov011Vec unk_0c;
    u8 unk_18[0x4];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
};

struct Ov011Sub48 {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    u8 unk_4c[0x4];
    u32 unk_50;
    u32 unk_54;
    u8 unk_58[0x8];
    s32 unk_60;
    u8 unk_64[0x4];
    Ov011Vec unk_68;
    u8 unk_74[0x26];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 1;
    u16 unk_9a_2 : 1;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 1;
    u16 unk_9a_8 : 8;
};

struct Ov011Sub3c {
    u8 unk_00[0x14];
    s32 unk_14;
    u8 unk_18;
    u8 unk_19;
};

// An object's unk_4c.
struct Ov011Sub4c {
    u8 unk_00[0x8];
    u16 unk_08;
    u16 unk_0a;
    u8 unk_0c[0x10];
    u16 unk_1c;
};

struct Ov011Param {
    s16 unk_00;
    s16 unk_02;
    u8 unk_04[0x4];
    u16 unk_08;
    u16 unk_0a_0 : 7;
    u16 unk_0a_7 : 3;
    u16 unk_0a_10 : 6;
};

// Common object base (the ov000 object class, 0xcc bytes) that every actor in the
// actor manager derives from.
class Ov011Obj : public Ov011V {
public:
    u8 unk_04[0x8];
    u16 id;
    u16 kind;
    u8 unk_10[0x5];
    u8 unk_15;
    u8 unk_16_0 : 1;
    u8 unk_16_1 : 7;
    u8 unk_17;
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x2];
    u8 unk_24[0xc];
    u32 unk_30;
    u8 unk_34[0x4];
    Ov011Sub38 *unk_38;
    Ov011Sub3c *unk_3c;
    Ov011Sub40 *unk_40;
    Ov011Sub44 *unk_44;
    Ov011Sub48 *unk_48;
    Ov011Sub4c *unk_4c;
    u16 *hp; // hp[0] current, hp[1] maximum
    u8 unk_54[0xc];
    void *unk_60;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov011Vec pos;
    u16 rot[3];
    u8 unk_82[0x2];
    Ov011Vec unk_84;
    u16 target; // id of the targeted actor (ov000 Actor::target)
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_93_4 : 1;
    u8 unk_93_5 : 3;
    u8 unk_94_0 : 1;
    u8 unk_94_1 : 2;
    u8 unk_94_3 : 5;
    u8 unk_95[0x3];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x4];
    Ov011Param *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov011Vec unk_b8;
    s32 unk_c4;
    s32 unk_c8;
};

// The ov003 actor class; subclass fields start at 0xf0.
class Ov011Actor : public Ov011Obj {
public:
    s32 unk_cc;
    u8 unk_d0[0xe];
    u16 unk_de;
    u8 unk_e0[0xa];
    u16 unk_ea_0 : 3;
    u16 unk_ea_3 : 3;
    u16 unk_ea_6 : 2;
    u16 unk_ea_8 : 1;
    u16 unk_ea_9 : 1;
    u16 unk_ea_10 : 1;
    u16 unk_ea_11 : 3;
    u16 unk_ea_14 : 1;
    u16 unk_ea_15 : 1;
    u8 unk_ec_0 : 1;
    u8 unk_ec_1 : 1;
    u8 unk_ec_2 : 6;
    u8 unk_ed;
    u16 unk_ee_0 : 1;
    u16 unk_ee_1 : 1;
    u16 unk_ee_2 : 2;
    u16 unk_ee_4 : 1;
    u16 unk_ee_5 : 1;
    u16 unk_ee_6 : 1;
    u16 unk_ee_7 : 2;
    u16 unk_ee_9 : 7;
};
OV011_SIZE(Ov011Actor, 0xf0);

// The ov011 NPC class (constructor Ov011Npc_Ctor, vtable data_ov011_022079f0),
// derived straight from the object base.
class Ov011Npc : public Ov011Obj {
public:
    Ov011Flags unk_cc;
    u8 unk_ce_0 : 1;
    u8 unk_ce_1 : 1;
    u8 unk_ce_2 : 6;
    u8 unk_cf;
    u16 unk_d0;
    void *unk_d4;
    u8 unk_d8[0xc];
    u8 unk_e4[0xc];
    u8 unk_f0[0xc];
};

// Head of Ov011Scene: the owning actor and the list of actors taking part. The group movers
// keep a pointer to it.
class Ov011List {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01[0x3];
    s32 unk_04;
    Ov011Obj *actor;
    Ov011Node *head;
};

// A Ov011Ent-driven group mover (update func_ov011_021fa8c8, table data_ov011_02207344).
class Ov011Mgr {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E38 *arr8;
    Ov011E30 *arrC;
    u16 *ids;
    Ov011List *list;
    Ov011Ent *unk_18;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_28[0x7];
    u8 unk_2f;
};
OV011_SIZE(Ov011Mgr, 0x30);

struct Ov011E40 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[0x3];
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

// Point mover (Ov011Mov_Init .. Ov011Mov_GetPos).
struct Ov011Mov {
    u8 active;
    u8 unk_01[0x3];
    s32 accel;
    Ov011Vec pos;
    Ov011Vec vel;
};
OV011_SIZE(Ov011Mov, 0x20);

// Second group mover (update func_ov011_021fb684, table data_ov011_022072d8).
class Ov011Mgr2 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40 *arr8;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_20[0x7];
    u8 unk_27;
    u8 unk_28[0xb8];
    Ov011Mov mov;
};
OV011_SIZE(Ov011Mgr2, 0x100);

// Effect with its own model (init func_ov011_02201578, update func_ov011_02201758).
struct Ov011Fx {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    Ov011Anim *anim;
    Ov011Sub38 *model;
    Ov011Vec v0c;
    Ov011Vec v18;
    u8 mtx[0x24];
    u16 state;
    u16 timer;
    u8 unk_4c[0x10];
    u8 s5c[0xc];
    u8 s68[0xc];
    u8 s74[0xc];
};
OV011_SIZE(Ov011Fx, 0x80);

// Ring buffer of s32 values (allocated by func_ov011_021fd4d8).
struct Ov011Ring {
    u8 b0 : 1;
    u8 rest : 7;
    u8 pad;
    u16 idx;
    u16 cap;
    u8 pad2[2];
    s32 *buf;
    s32 count;
};

class Ov011Scene;

// Tutorial/message step runner (handlers in data_ov011_02207308).
class Ov011Sub1b4 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 id;
    Ov011Scene *scene;
    Ov011Ent *ent;
    Ov011Sub40 seq;
};
OV011_SIZE(Ov011Sub1b4, 0x20);

// The 0x23c-byte scene state that the main ov011 actor owns at unk_100 (built by
// Ov011SceneActor_Start, initialised by func_ov011_021fd4d8, updated by func_ov011_021fd638,
// handlers in data_ov011_022073a0).
class Ov011Scene : public Ov011List {
public:
    Ov011Ring ring;
    Ov011Sub40 seq;
    Ov011Fx fx;
    Ov011Mgr2 mgr2;
    Ov011Sub1b4 s1b4;
    Ov011Mgr mgr;
    Ov011Ent ent;
};
OV011_SIZE(Ov011Scene, 0x23c);

// Tween object with a 0x24-byte layout (Ov011Vt_022079b0_Ctor constructs one).
struct Ov011E24 : public Ov011V {
    u8 unk_04[0x20];
};

// The 0x3c-byte object at Ov011SceneActor::unk_104.
struct Ov011Sa104 {
    Ov011Sub40 seq;
    Ov011E24 tw;
    void *unk_38;
};
OV011_SIZE(Ov011Sa104, 0x3c);

// The 6-byte object at Ov011SceneActor::unk_108.
struct Ov011Sa108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
};
OV011_SIZE(Ov011Sa108, 6);

// The 4-byte object at Ov011SceneActor::unk_10c.
struct Ov011Sa10c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    u16 timer;
};
OV011_SIZE(Ov011Sa10c, 4);

// The ov011 actor that owns the scene (constructor Ov011SceneActor_Ctor, vtable
// data_ov011_022078f0, setup Ov011SceneActor_Start).
class Ov011SceneActor : public Ov011Actor {
public:
    u8 unk_f0_0 : 1;
    u8 unk_f0_1 : 1;
    u8 unk_f0_2 : 6;
    u8 unk_f1;
    u16 unk_f2;
    Ov011Vec unk_f4;
    Ov011Scene *scene;
    Ov011Sa104 *unk_104;
    Ov011Sa108 *unk_108;
    Ov011Sa10c *unk_10c;
};

// ov003-actor subclasses named after their vtables (only the fields ov011 reads).
// vtable data_ov011_02207cf8: Ov011Act7cf8_Start, func_ov011_022038ac.
class Ov011Act7cf8 : public Ov011Actor {
public:
    Ov011Vec unk_f0;
};

// vtable data_ov011_02207e50: Ov011Act7e50_Start, func_ov011_02203e94, func_ov011_02203ef0.
class Ov011Act7e50 : public Ov011Actor {
public:
    Ov011Vec unk_f0;
    u16 unk_fc;
};

// vtable data_ov011_02207c4c: Ov011Act7c4c_Start, func_ov011_022043cc, func_ov011_02204428,
// func_ov011_02204a8c.
class Ov011Act7c4c : public Ov011Actor {
public:
    Ov011Vec unk_f0;
    u16 unk_fc;
    u16 unk_fe;
    s32 unk_100;
    Ov011Vec unk_104;
};

class Ov011Bar;

// vtable data_ov011_02207da4: Ov011Act7da4_Dtor .. func_ov011_02206e18 (the photo/boss
// actor of ov011_02204b94.cpp .. ov011_022071b4.cpp).
class Ov011Act7da4 : public Ov011Actor {
public:
    u8 unk_f0;
    Ov011Anim unk_f4[2];
    void *unk_364;
    void *unk_368;
    u16 unk_36c;
    u8 unk_36e;
    u8 unk_36f;
    Ov011Vec unk_370[3];
    u8 unk_394;
    Ov011Bar *unk_398;
};

// An effect from the main-module effect manager (func_02065f88 / EffectGroup_Create create one,
// func_020657b0 looks one up by its handle unk_24).
class Ov011Eff : public Ov011V {
public:
    u8 unk_04[0x18];
    s32 unk_1c;
    u8 unk_20[0x4];
    s32 unk_24;
    u8 unk_28[0x14];
    s32 unk_3c;
    u8 unk_40[0x88];
    s32 unk_c8;
};

// An actor message (ov000 ActorMsg); the payload at 0x0c depends on cmd.
struct Ov011ActMsg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    s32 cmd;
    union {
        s32 arg;
        struct {
            u8 b;
            u8 unk_01;
            s16 x;
            s16 y;
        } p;
    } u;
};

// The player actor (func_ov000_0219bf90); only the fields ov011 reads.
class Ov011Player : public Ov011Obj {
public:
    u8 unk_cc[0xa24];
    Ov011Vec unk_af0;
    u8 unk_afc[0x20];
    u16 unk_b1c;
    u8 unk_b1e[0x72];
    Ov011Vec unk_b90;
    s32 unk_b9c;
};

static inline Ov011Obj *Ov011_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (Ov011Obj *)ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Ov011_ActorValid(u16 id) {
    Ov011Obj *a;
    Ov011Player *pl;
    a = Ov011_FindActor(id);
    if (a == NULL) {
        return FALSE;
    }
    pl = (Ov011Player *)func_ov000_0219bf90();
    if (pl == NULL) {
        return FALSE;
    }
    if (pl->unk_b1c == a->id) {
        return FALSE;
    }
    if (!(a->unk_48->unk_50 & 0x20000000)) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov011_NodeValid(Ov011Node *n) {
    BOOL r = FALSE;
    if (n != NULL) {
        r = Ov011_ActorValid(n->id);
    }
    return r;
}



#endif
