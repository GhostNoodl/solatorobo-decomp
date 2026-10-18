#ifndef OV015_H
#define OV015_H

#include "types.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

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


struct Ov015Obj30 {
    void *vt;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c;
    Ov015V *unk_10;
    Ov015V *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};

struct Ov015Obj34 {
    void *vt;
    Ov015V *unk_04;
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

struct Ov015Cam {
    void *vt;
    Ov015V3 pos;
    Ov015V3 at;
    Ov015V3 up;
    s32 near;
    s32 far;
    s16 fovySin;
    s16 fovyCos;
    u8 unk_34[2];
    u16 fovy;
    s32 fovyDeg;
    u8 unk_3c[2];
    u8 unk_3e;
    u8 unk_3f;
    u16 unk_40;
    u8 unk_42[0xbc - 0x42];
};

struct Ov015CamPair {
    void *vt;
    Ov015Cam cam0;
    Ov015Cam cam1;
    u8 unk_17c[0x10];
    s32 unk_18c;
    s32 unk_190;
    s32 unk_194;
    s32 unk_198;
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
s64 _s32_div_f(s32 a, s32 b);
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

#endif
