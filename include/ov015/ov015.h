#ifndef OV015_H
#define OV015_H

#include "types.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

// The ship model config at 0x02212db0 (defined in ov015_0221272c.cpp).
struct Ov015ShipCfg {
    const char *name;
    s32 scale;
};

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov015V {
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

struct Ov015Vec {
    s32 x;
    s32 y;
    s32 z;
    Ov015Vec() {}
};

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))
#define VCALL(p) ((Ov015V *)(p))
#define SET_VT(p, vt) (*(void **)(p) = (void *)(vt))
#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile u32 *)(a))

extern "C" {

struct Ov015Task {
    void *vt;
    u32 flag0 : 1;
    u32 flag1 : 1;
    u32 flag2 : 1;
    u32 flag3 : 1;
    u32 flag4 : 1;
    u32 flag5 : 1;
    u32 flag6 : 1;
    u32 flag7 : 1;
    u32 flags_rest : 24;
    s32 unk_08;
    s32 unk_0c;
};


struct Ov015Node {
    void *vt;
    s32 key;
    Ov015Node *prev;
    Ov015Node *next;
};

struct Ov015List {
    void *vt;
    Ov015Node *head;
    Ov015Node *tail;
    s32 count;
};


struct Ov015Fish;
struct Ov015Ship;
struct Ov015CamPair;
struct Ov015Info38;

// Fishing phase state (0x2c bytes, vtable data_ov015_022127ec, func_ov015_021ff350).
struct Ov015Obj30 {
    void *vt;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c;
    u8 *unk_10;
    u8 *unk_14;
    Ov015Fish *unk_18;
    Ov015Ship *unk_1c;
    Ov015CamPair *unk_20;
    Ov015List *unk_24;
    Ov015Info38 *unk_28;
};

static inline void Ov015Obj30_Clear(Ov015Obj30 *p) {
    p->unk_04 = 0;
    p->unk_08 = 0;
    p->unk_0c = 0;
    p->unk_10 = NULL;
    p->unk_14 = NULL;
    p->unk_18 = 0;
    p->unk_1c = 0;
    p->unk_20 = 0;
    p->unk_24 = 0;
    p->unk_28 = 0;
}


struct Ov015V3 {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov015Mtx33 {
    s32 m[3][3];
};

// Camera (0xbc bytes, func_0204b370 / func_0204b420).
struct Ov015Bits8a0 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
};

struct Ov015Cam {
    void *vt;
    Ov015Vec pos;
    Ov015Vec at;
    Ov015Vec up;
    s32 near;
    s32 far;
    s16 fovySin;
    s16 fovyCos;
    s16 aspect;
    u16 fovy;
    s32 fovyDeg;
    u8 unk_3c[2];
    u8 dirty;
    u8 unk_3f;
    u16 unk_40;
    u8 unk_42[0x99 - 0x42];
    u8 unk_99;
    u8 unk_9a;
    u8 unk_9b;
    Ov015Bits8a0 unk_9c;
    u8 unk_9d[0xbc - 0x9d];
};

// The camera object (0x1a0 bytes, vtable data_ov015_0221291c): the top and bottom screen
// cameras plus the follow state.
struct Ov015CamPair {
    void *vt;
    Ov015Cam cam0;
    Ov015Cam cam1;
    s32 unk_17c; // mode
    Ov015Vec unk_180; // target
    Ov015Vec unk_18c;
    s32 unk_198;
    s32 unk_19c; // timer
};

// ov000 model resource (0x138 bytes, func_ov000_0218e9c4 / func_ov000_0218ea20).
struct Ov015Anim {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 unk_03_1 : 1;
    u8 unk_03_2 : 1;
    u8 unk_03_3 : 1;
    u8 unk_03_4 : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char unk_10[0x20]; // model directory
    char unk_30[0x1c]; // model name
    char unk_4c[0x20]; // animation directory
    char unk_6c[0x54]; // animation name
    u8 *unk_c0;
    char unk_c4[0x20];
    char unk_e4[0x20];
    u8 unk_104[0x34];
};

// ov000 Shadow (0x1c bytes, func_ov000_0219196c / func_ov000_021919c8 / func_ov000_02191a24).
struct Ov015Shadow {
    const void *vtbl;
    void *res;
    void *mdl;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 type : 4;
    u8 prev : 4;
    u8 alpha;
    u8 unk_1a;
    u8 state;
};

// Same layout as NNSG3dRenderObj (nnsys/g3d.h), 0x54 bytes.
struct Ov015RenderObj {
    u32 flag;
    void *resMdl;
    void *anmMat;
    void *funcBlendMat;
    void *anmJnt;
    void *funcBlendJnt;
    void *anmVis;
    void *funcBlendVis;
    void *cbFunc;
    u8 cbCmd;
    u8 cbTiming;
    u16 dummy_;
    void *cbInitFunc;
    void *ptrUser;
    u8 *ptrUserSbc;
    void *recJntAnm;
    void *recMatAnm;
    u32 hintMatAnmExist[2];
    u32 hintJntAnmExist[2];
    u32 hintVisAnmExist[2];
};

struct Ov015Glyph {
    u32 code : 8;
    u32 unk_08 : 8;
    u32 x : 9;
    u32 unk_19 : 7;
    u32 w : 10;
    u32 unk_2a : 2;
    u32 pal : 4;
    u32 unk_30 : 16;
};

struct Ov015Stat {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 unk_1c;
    u8 unk_1d;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
};
extern Ov015Stat data_ov015_0221332c;
extern u8 *data_02097d48;

struct Ov015Gauge {
    void *vt;
    s32 state;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    u8 unk_24[8];
    u32 unk_2c;
};

struct Ov015SysA30 {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
};


struct Ov015Globals {
    Ov015V *unk_00;
    Ov015V *unk_04;
};

struct Ov015Fade {
    void *vt;
    u32 unk_04;
    u8 unk_08;
    u8 unk_09;
    s32 unk_0c;
    u16 unk_10;
    s32 unk_14;
    u8 unk_18;
};

struct Ov015Main {
    void *vt;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    Ov015V *unk_18;
};

struct Ov015Child {
    void *vt;
    s32 state;
    s32 unk_08;
};

struct Ov015Shared {
    u8 unk_00[4];
    s32 unk_04;
    u8 unk_08[0x24];
    s32 unk_2c;
};

struct Ov015Flags18 {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
};

struct Ov015Pad {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
};

struct Ov015VecC {
    s32 x;
    s32 y;
    s32 z;
    Ov015VecC() {}
    Ov015VecC(const Ov015VecC &o) : x(o.x), y(o.y), z(o.z) {}
};


void *func_0203dd9c(u32 size);
void func_0203de1c(void *p);
u64 _u32_div_f(u32 a, u32 b);

// Heap selector: [0] = current, [1], [2] = alternate
extern u32 *data_02097dd0;

extern const s16 FX_SinCosTable_[];

}

extern "C" {
extern u8 data_ov000_021cc060[];

static inline void Ov015TaskBase_Ctor(void *p) {
    SET_VT(p, data_ov000_021cc060);
    VCALL(p)->v58();
}
static inline void Ov015TaskBase_Dtor(void *p) {
    SET_VT(p, data_ov000_021cc060);
    VCALL(p)->v5c();
}
}

#define HEAP_PUSH(saved)                      \
    do {                                      \
        (saved) = data_02097dd0[0];           \
        data_02097dd0[0] = data_02097dd0[2];  \
    } while (0)
#define HEAP_POP(saved) (data_02097dd0[0] = (saved))

#define DELETE_V(field)                 \
    do {                                \
        Ov015V *o_ = (Ov015V *)(field); \
        if (o_ != NULL) {               \
            if (o_ != NULL) {           \
                o_->v04();              \
            }                           \
            (field) = NULL;             \
        }                               \
    } while (0)

static inline s32 Ov015_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

extern "C" {
struct Ov015Slot524 {
    s32 a;
    s32 b;
    u8 c;
    s16 d;
};
struct Ov015SlotHost { u8 pad[0x524]; Ov015Slot524 slots[8]; };

extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);

static inline void Ov015_DeleteFound(void *heap, void *key) {
    Ov015V *o = func_020657b0(heap, key);
    u32 saved;
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
}

struct Ov015ObjFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
};
static inline BOOL Ov015_ObjIsB1(Ov015ObjFlags *f) {
    return f->b1 == 1 ? TRUE : FALSE;
}

struct Ov015AnimFlags {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
    u16 rest : 7;
};

struct Ov015D48Bits2 {
    u8 lo : 4;
    u8 b4 : 1;
    u8 hi : 3;
};
struct Ov015Bgm {
    u16 active : 1;
    u16 rest : 15;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
};
extern Ov015Pad *data_02097e48;
void func_0204aab0(Ov015Bgm *p);
static inline void Ov015_BgmFade(void) {
    Ov015Bgm *p = (Ov015Bgm *)data_02097e48;
    if (p->active) {
        if (p->unk6 != 0xffff || p->unk4 != 0x25) {
            u16 v;
            if (p->unk2 != 10 && p->unk2 != 0) {
                if (p->unk6 != 0xffff) {
                    func_0204aab0(p);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk2 = v;
            p->unk6 = 0x25;
            p->unk8 = 10;
        }
    }
}
struct Ov015Gfx7f8 {
    u8 pad[0xfc];
    u32 fc;
    u8 pad2[0x240 - 0x100];
    Ov015Vec a;
    Ov015Vec b;
    Ov015Vec c;
};
extern Ov015Gfx7f8 NNS_G3dGlb;
}

extern "C" {
// ---- struct types (svD) ----
#define OV015_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]
struct Ov015ShipMtx;
struct Ov015Fish;
struct Ov015Model;
struct Ov015FishInfo;
struct Ov015Obj48;
struct Ov015Obj34;
struct Ov015Ship;
struct Ov015Game;
struct Ov015Info38;
// Node matrix (rotation rows and translation) and the node id it is captured for (func_ov015_02208424).
struct Ov015ShipMtx {
    Ov015Vec m[4];
    u8 id;
    u8 unk_31[0x3];
};
OV015_SIZE(Ov015ShipMtx, 0x34);
// Fish data block (0x2c bytes, vtable data_ov015_02212e84).
struct Ov015FishInfo {
    void *unk_00;
    u16 unk_04;
    u16 unk_06;
    u8 unk_08[0x2];
    s16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    u16 unk_10;
    s16 unk_12;
    u16 unk_14;
    s16 unk_16;
    s16 unk_18;
    u8 unk_1a[0x2];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};
OV015_SIZE(Ov015FishInfo, 0x2c);
// ov000 model instance (0xe8 bytes, func_ov000_0218fe1c).
struct Ov015Model {
    u8 unk_00[0x24];
    Ov015RenderObj unk_24;
    Ov015VecC unk_78;
    Ov015Vec unk_84[3];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0x2];
    s16 unk_b6;
    s16 unk_b8;
    s16 unk_ba;
    s16 unk_bc;
    u8 unk_be[0x4];
    Ov015AnimFlags unk_c2;
    s16 unk_c4;
    u8 unk_c6[0xa];
    u8 *unk_d0;
    u8 *unk_d4;
    u8 unk_d8[0x10];
};
OV015_SIZE(Ov015Model, 0xe8);
// Main object (0x48 bytes, func_0203f260 / func_0203f2b8).
struct Ov015Obj48 {
    Ov015Vec unk_00;
    Ov015Vec unk_0c;
    u8 unk_18[0xc];
    u8 unk_24;
    u8 unk_25[0x3];
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x8];
    s32 unk_38;
    u8 unk_3c[0x8];
    u32 unk_44;
};
OV015_SIZE(Ov015Obj48, 0x48);
// Fish (0x5b0 bytes, vtable data_ov015_022128fc, ctor func_ov015_02209114).
struct Ov015Fish {
    void *unk_00;
    u16 unk_04;
    u8 unk_06[0x2];
    s32 unk_08;
    Ov015Vec unk_0c[3];
    Ov015Vec unk_30;
    s32 unk_3c;
    Ov015Vec unk_40;
    Ov015Vec unk_4c[3];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90;
    u8 unk_91[0x3];
    s32 unk_94;
    s32 unk_98;
    Ov015Vec unk_9c;
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
    s32 unk_b8;
    s32 unk_bc;
    Ov015FishInfo unk_c0;
    s32 unk_ec;
    Ov015V *unk_f0;
    s32 unk_f4;
    Ov015V *unk_f8;
    s32 unk_fc;
    Ov015V *unk_100;
    s16 unk_104;
    u8 unk_106[0x2];
    s32 unk_108;
    Ov015Anim unk_10c;
    Ov015Model unk_244;
    Ov015Anim unk_32c;
    Ov015Model unk_464;
    Ov015Shadow unk_54c;
    Ov015Obj48 unk_568;
};
OV015_SIZE(Ov015Fish, 0x5b0);
// Fishing phase state (0x34 bytes, func_ov015_0220015c / func_ov015_02200194).
struct Ov015Obj34 {
    void *vt;
    u8 *unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    Ov015Ship *unk_24;
    Ov015Fish *unk_28;
    Ov015CamPair *unk_2c;
    Ov015Info38 *unk_30;
};
OV015_SIZE(Ov015Obj34, 0x34);
// Player ship (0xd58 bytes, ctor func_ov015_0220765c, dtor func_ov015_02207738).
struct Ov015Ship {
    Ov015Anim unk_00;
    Ov015Model unk_138;
    Ov015Anim unk_220;
    Ov015Model unk_358[8];
    Ov015Anim unk_a98;
    Ov015Model unk_bd0;
    Ov015Shadow unk_cb8;
    Ov015ShipMtx unk_cd4;  // matrix captured for one node
    Ov015Vec unk_d08;
    Ov015Vec unk_d14;
    u16 unk_d20;
    u16 unk_d22;
    u16 unk_d24;
    u8 unk_d26[0x2];
    Ov015V *unk_d28;
    s32 unk_d2c;
    Ov015V *unk_d30;
    s32 unk_d34;
    u16 unk_d38;
    u16 unk_d3a;
    u16 unk_d3c;
    s16 unk_d3e;
    u8 unk_d40;
    u8 unk_d41;
    u8 unk_d42;
    u8 unk_d43[0x1];
    s32 unk_d44;
    u16 unk_d48;
    u8 unk_d4a[0x2];
    Ov015Vec unk_d4c;
};
OV015_SIZE(Ov015Ship, 0xd58);
// Fish info block (0x38 bytes, vtable data_ov015_022132d0, ctor func_ov015_02211828).
struct Ov015Info38 {
    void *vt;
    u16 unk_04;
    u8 unk_06[0x2];
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
    s32 unk_30;
    s32 unk_34;
};
OV015_SIZE(Ov015Info38, 0x38);
// Fishing game controller (0xcc bytes, vtable data_ov015_0221296c, func_ov015_02200f74).
struct Ov015Game {
    void *vt;
    s32 state;
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10;
    u8 unk_11[0x3];
    s32 unk_14;
    Ov015Ship *unk_18;
    Ov015List *unk_1c;
    u8 *unk_20;
    Ov015CamPair *unk_24;
    u8 *unk_28;
    u8 *unk_2c;
    Ov015Obj30 unk_30;
    Ov015Obj34 unk_5c;
    u8 *unk_90;
    Ov015Info38 unk_94;
};
OV015_SIZE(Ov015Game, 0xcc);
// ---- end struct types (svD) ----
}

#endif
