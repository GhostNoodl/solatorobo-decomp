#ifndef OV008_H
#define OV008_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov008V {
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

// Stores a vtable pointer into a freshly allocated (or embedded) object.
#define OV008_SET_VT(p, vt) (*(void **)(p) = (void *)(vt))
#define OV008_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

struct Ov008Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov008Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

// 2D sprite (main, 0x160 bytes; set up by func_02041218 + func_02041440).
struct Ov008SprRes {
    u8 unk_00[0x4];
    void *unk_04; // cell bank
    u8 unk_08[0x4];
    void *unk_0c; // animation bank
};

struct Ov008SprFrame {
    u8 unk_00[0x30];
    void *unk_30;
};

struct Ov008SprAnim {
    u8 unk_00[0x4];
    Ov008SprFrame *unk_04;
    u8 unk_08[0x20];
};
OV008_SIZE(Ov008SprAnim, 0x28);

struct Ov008SprSeq {
    u8 unk_00[0xc];
    u16 **unk_0c;
};

struct Ov008SprAttr {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 pid : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
};

struct Ov008Sprite {
    u8 unk_00[0x28];
    Ov008SprRes *unk_28;
    char unk_2c[0x20]; // file name
    u8 unk_4c[0x20];
    union {
        u32 flags;
        Ov008SprAttr attr;
    };
    u8 unk_70[0x8];
    Ov008SprAnim *unk_78;
    u8 unk_7c[0x4];
    s32 unk_80;
    u8 unk_84;
    u8 unk_85;
    u8 unk_86[0x2];
    u8 unk_88[0x74]; // initialised by func_02041218
    s32 unk_fc;
    s32 unk_100;
    u8 unk_104[0x8];
    s32 unk_10c;
    s32 unk_110;
    u8 unk_114[0x3c];
    s32 unk_150;
    u8 unk_154[0xc];
};
OV008_SIZE(Ov008Sprite, 0x160);

// ov000 model resource (0x138 bytes, func_ov000_0218e9c4).
struct Ov008Anim {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char unk_10[0x20]; // model directory
    char unk_30[0x1c]; // model name
    char unk_4c[0x20]; // animation directory
    char unk_6c[0xcc]; // animation name
};
OV008_SIZE(Ov008Anim, 0x138);

// What func_ov000_02190a30 returns for a model.
struct Ov008MdlAnm {
    u8 unk_00[0x112];
    s16 unk_112;
};

// ov000 model (0xe8 bytes, func_ov000_0218fe1c).
struct Ov008Model {
    u8 unk_00[0xb4];
    s16 unk_b4;
    u8 unk_b6[0x32];
};
OV008_SIZE(Ov008Model, 0xe8);

// The picture / text panel (0x4c bytes, vtable data_0208b318).
class Ov008Pic : public Ov008V {
public:
    char unk_04[0x20]; // file
    char unk_24[0x20]; // cell name
    s32 unk_44;
    u8 unk_48[0x4];
};
OV008_SIZE(Ov008Pic, 0x4c);

// Picture subclass (0xc4 bytes, vtable data_0208bf54, func_0205a6a0).
class Ov008PicC4 : public Ov008Pic {
public:
    u8 unk_4c[0x70];
    void *unk_bc;
    u8 unk_c0[0x4];
};
OV008_SIZE(Ov008PicC4, 0xc4);

// Caption (0x54 bytes): a state word and a picture showing the name of entry unk_50.
struct Ov008Caption {
    s32 state;
    Ov008Pic pic;
    u16 unk_50; // entry to show next (0xffff = none)
    u16 unk_52; // entry shown
};
OV008_SIZE(Ov008Caption, 0x54);

// Slide-in panel (0x6c bytes): a picture plus the sprite made from it.
struct Ov008Panel {
    s32 state;
    Ov008Pic pic;
    Ov008Sprite *unk_50;
    s32 unk_54; // offset
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60; // alpha
    s32 unk_64; // speed
    u8 unk_68;
    u8 unk_69[0x3];
};
OV008_SIZE(Ov008Panel, 0x6c);

// Text window (0xb8 bytes, vtable data_0208ba70, func_0204c7d0).
class Ov008Win : public Ov008V {
public:
    u8 unk_04[0x40];
    s32 unk_44; // width
    s32 unk_48; // height
    u8 unk_4c[0x6c];
};
OV008_SIZE(Ov008Win, 0xb8);

// Camera (0xbc bytes, func_0204b370).
class Ov008Cam : public Ov008V {
public:
    u8 unk_04[0xc];
    Ov008Vec3 unk_10; // position
    Ov008Vec3 unk_1c; // target
    u8 unk_28[0x18];
    u16 unk_40;
    u16 unk_42;
    u16 unk_44;
    u16 unk_46;
    s32 unk_48;
    u8 unk_4c[0x70];
};
OV008_SIZE(Ov008Cam, 0xbc);

struct Ov008ItemFlags {
    u16 b0 : 1;
    u16 rest : 15;
};

// ov000 list-menu item (0x34 bytes, func_ov000_02153f90).
struct Ov008Item {
    s32 unk_00;
    s16 unk_04; // serial number from the menu's unk_9c
    u16 id;
    s16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    u8 unk_10[0xc];
    Ov008Win *unk_1c; // label
    u8 unk_20[0x8];
    Ov008Item *prev;
    Ov008Item *next;
    union {
        u16 unk_30;
        Ov008ItemFlags flags;
    };
    u16 unk_32;
};
OV008_SIZE(Ov008Item, 0x34);

struct Ov008ResFlags {
    u32 b0 : 6;
    u32 b6 : 1;
    u32 rest : 25;
};

// The objects at Ov008Menu::unk_14 / unk_18.
struct Ov008MenuRes {
    u8 unk_00[0x4];
    Ov008ResFlags unk_04;
    u8 unk_08[0x64];
    void *unk_6c;
};

typedef s32 (*Ov008Cb)(...);

// What func_0206e7d0 returns for an entry id.
struct Ov008Def {
    void *unk_00;
    void *unk_04; // name
};

struct Ov008Mgr;

// ov000 list menu (0xd4 bytes, vtable data_ov000_021caec8; ov008 derives its own with
// vtable data_ov008_021d0368).
class Ov008Menu : public Ov008V {
public:
    s32 unk_04; // state
    Ov008Mgr *unk_08; // owner
    u32 unk_0c;
    Ov008Sprite *unk_10;
    Ov008MenuRes *unk_14;
    Ov008MenuRes *unk_18;
    s32 unk_1c;
    s32 unk_20; // rows
    s32 unk_24;
    s32 unk_28; // height
    u8 unk_2c[0x38];
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x16];
    Ov008Cb unk_80; // draw-item callback
    Ov008Cb unk_84; // decide callback
    Ov008Cb unk_88; // cursor callback
    Ov008Cb unk_8c;
    Ov008Cb unk_90;
    Ov008Item *unk_94; // first item
    Ov008Item *unk_98; // first shown item
    s16 unk_9c; // next serial number
    u8 unk_9e[0x13];
    s8 unk_b1; // cursor (from unk_98)
    u8 unk_b2[0x2];
    Ov008Sprite *unk_b4;
    void *unk_b8;
    u8 unk_bc[0x4];
    u8 unk_c0;
    s8 unk_c1;
    u8 unk_c2[0xe];
    s32 unk_d0; // scroll
};
OV008_SIZE(Ov008Menu, 0xd4);

// Yes/no dialog (0x1e4 bytes, vtables data_ov000_021caec8 -> data_ov000_021cb1b0 -> data_ov000_021cb0b8).
class Ov008Dialog : public Ov008Menu {
public:
    u8 unk_d4[0x108];
    s32 unk_1dc; // text
    u8 unk_1e0[0x4];
};
OV008_SIZE(Ov008Dialog, 0x1e4);

// Talking character (0x21c bytes, vtables data_ov000_021cac60 -> data_ov000_021ca94c), with
// two text windows.
class Ov008Talk : public Ov008V {
public:
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0x58];
    s16 unk_68;
    u8 unk_6a[0x26];
    Ov008Win unk_90;
    Ov008Win unk_148;
    void *unk_200;
    u8 unk_204[0x18];
};
OV008_SIZE(Ov008Talk, 0x21c);

struct Ov008MgrFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 cnt : 8;
    u32 rest : 19;
};

struct Ov008Sel {
    u8 unk_00[0x6];
    u16 id;
};

// The block at data_02fe1534.
struct Ov008Shared {
    u8 unk_00[0x44];
    u16 unk_44;
    u8 unk_46[0xc];
    u16 unk_52;
    u8 unk_54[0x14];
    u16 unk_68;
};

// The G3 state block at data_02097d48 + 0x8b0.
struct Ov008G3 {
    u8 unk_00;
    u8 unk_01[0x37];
    s32 unk_38;
    u16 unk_3c[0x20]; // toon table
};

struct Ov008Sys {
    u8 unk_000[0x8b0];
    Ov008G3 unk_8b0;
};

// The block at data_02097ce0.
struct Ov008Ce0 {
    u32 unk_00;
    s32 unk_04;
};

// The save block at data_02fe152c.
struct Ov008Save {
    u8 unk_00[0x4c];
    u8 *unk_4c;
};

// What func_ov000_021824d0 returns.
struct Ov008Chr {
    u8 unk_00[0xc6];
    u16 unk_c6;
};

// The ov008 manager (0x120 bytes, data_ov008_021d0500).
struct Ov008Mgr {
    union {
        u32 unk_00;
        Ov008MgrFlags flags;
    };
    s32 state;
    Ov008Cam cam;
    Ov008Anim *unk_c4;
    Ov008Model *unk_c8;
    Ov008Anim *unk_cc;
    Ov008Model *unk_d0;
    Ov008Pic *unk_d4;
    Ov008Sprite *unk_d8;
    Ov008Pic *unk_dc;
    Ov008Sprite *unk_e0;
    Ov008Pic *unk_e4;
    Ov008Sprite *unk_e8;
    Ov008Sprite *unk_ec;
    Ov008Sprite *unk_f0;
    Ov008Caption *unk_f4;
    Ov008Panel *unk_f8;
    Ov008PicC4 *unk_fc;
    Ov008Menu *unk_100;
    Ov008Dialog *unk_104;
    Ov008Sel *unk_108;
    Ov008Talk *unk_10c;
    u16 unk_110;
    u16 unk_112;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};
OV008_SIZE(Ov008Mgr, 0x120);

extern "C" {
extern Ov008Heap *data_02097dd0;
void *Heap_Alloc(u32 size);
void Heap_Free(void *p);
void func_02041558(void *p);
void func_02041278(void *p);
void func_02041218(void *p);
void *func_ov000_0218fee4(void *p);
}

// Frees the object at field with the default heap selected.
#define OV008_FREE(field, T, stmt)                      \
    {                                                   \
        u32 saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->def;        \
        if ((field) != NULL) {                          \
            T p_ = (field);                             \
            if (p_ != NULL) {                           \
                stmt;                                   \
            }                                           \
            (field) = NULL;                             \
        }                                               \
        data_02097dd0->cur = saved;                     \
    }

#define OV008_FREE_V(field, slot) OV008_FREE(field, Ov008V *, p_->slot())
#define OV008_FREE_D(field, dtor) OV008_FREE(field, void *, (dtor(p_), Heap_Free(p_)))
#define OV008_FREE_M(field) \
    OV008_FREE(field, Ov008Sprite *, (func_02041558(p_), func_02041278(p_->unk_88), Heap_Free(p_)))

extern "C" {
Ov008SprSeq *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, u8 d);
}

static inline void Ov008_DrawModel(Ov008Sprite *m) {
    Ov008SprAnim *anim;
    Ov008SprRes *res = m->unk_28;
    void *arg;
    Ov008SprFrame *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (m->unk_80 > 0) {
        anim = m->unk_78;
    }
    if (anim != NULL && (t = anim->unk_04) != NULL) {
        arg = t->unk_30;
    } else {
        Ov008SprSeq *e = NNS_G2dGetAnimSequenceByIdx(res->unk_0c, 0);
        arg = NNS_G2dGetCellDataByIdx(res->unk_04, **e->unk_0c);
    }
    func_02042628(m, arg, anim, 0);
}

static inline void *Ov008_GetTex(Ov008Sprite *m, Ov008SprRes *res, Ov008SprAnim *anim) {
    if (anim != NULL && anim->unk_04 != NULL) {
        return anim->unk_04->unk_30;
    }
    return NNS_G2dGetCellDataByIdx(res->unk_04, **NNS_G2dGetAnimSequenceByIdx(res->unk_0c, 0)->unk_0c);
}

static inline void Ov008_DrawModel2(Ov008Sprite *m) {
    Ov008SprRes *res = m->unk_28;
    if (res != NULL) {
        Ov008SprAnim *anim = 0 >= m->unk_80 ? NULL : m->unk_78;
        func_02042628(m, Ov008_GetTex(m, res, anim), anim, 0);
    }
}

static inline s32 Ov008_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

#define OV008_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline s32 Ov008_Abs(s32 v) {
    return v < 0 ? -v : v;
}

#endif
