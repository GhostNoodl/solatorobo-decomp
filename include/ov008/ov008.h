#ifndef OV008_H
#define OV008_H

#include "types.h"
#include "nitro/fx.h"
#include "Main/Sys/SysState.h"
#include "Main/Sys/SysTask.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/TextWin.h"

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

struct Ov008SprSeq {
    u8 unk_00[0xc];
    u16 **unk_0c;
};

// ov000 model resource (0x138 bytes, func_ov000_0218e9c4).
struct Ov008Anim {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char mdlDir[0x20]; // model directory
    char mdlName[0x1c]; // model name
    char anmDir[0x20]; // animation directory
    char anmName[0xcc]; // animation name
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
    char file[0x20]; // file
    char cell[0x20]; // cell name
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
    u16 next; // entry to show next (0xffff = none)
    u16 shown; // entry shown
};
OV008_SIZE(Ov008Caption, 0x54);

// Slide-in panel (0x6c bytes): a picture plus the sprite made from it.
struct Ov008Panel {
    s32 state;
    Ov008Pic pic;
    Model *sprite;
    s32 offset; // offset
    s32 unk_58;
    s32 unk_5c;
    s32 alpha; // alpha
    s32 speed; // speed
    u8 unk_68;
    u8 unk_69[0x3];
};
OV008_SIZE(Ov008Panel, 0x6c);

// Camera (0xbc bytes, func_0204b370).
class Ov008Cam : public Ov008V {
public:
    u8 unk_04[0xc];
    VecFx32 eye; // position
    VecFx32 at; // target
    u8 unk_28[0x18];
    u16 mode;
    u16 pitch;
    u16 yaw;
    u16 roll;
    s32 dist;
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
    s16 serial; // serial number from the menu's unk_9c
    u16 id;
    s16 unk_08;
    u16 unk_0a;
    s32 unk_0c;
    u8 unk_10[0xc];
    TextWin *label; // label
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

// What Lang_GetGroup returns for an entry id.
struct Ov008Def {
    void *unk_00;
    void *unk_04; // name
};

struct Ov008Mgr;

// ov000 list menu (0xd4 bytes, vtable data_ov000_021caec8; ov008 derives its own with
// vtable data_ov008_021d0368).
class Ov008Menu : public Ov008V {
public:
    s32 state; // state
    Ov008Mgr *owner; // owner
    u32 flags;
    Model *unk_10;
    Ov008MenuRes *unk_14;
    Ov008MenuRes *unk_18;
    s32 font;
    s32 rows; // rows
    s32 width;
    s32 height; // height
    u8 unk_2c[0x38];
    s16 posX;
    s16 posY;
    s16 posZ;
    u8 unk_6a[0x16];
    Ov008Cb onDrawItem; // draw-item callback
    Ov008Cb onDecide; // decide callback
    Ov008Cb onCursor; // cursor callback
    Ov008Cb unk_8c;
    Ov008Cb unk_90;
    Ov008Item *items; // first item
    Ov008Item *topItem; // first shown item
    s16 serial; // next serial number
    u8 unk_9e[0x13];
    s8 cursor; // cursor (from unk_98)
    u8 unk_b2[0x2];
    Model *unk_b4;
    void *unk_b8;
    u8 unk_bc[0x4];
    u8 unk_c0;
    s8 unk_c1;
    u8 unk_c2[0xe];
    s32 scroll; // scroll
};
OV008_SIZE(Ov008Menu, 0xd4);

// Yes/no dialog (0x1e4 bytes, vtables data_ov000_021caec8 -> data_ov000_021cb1b0 -> data_ov000_021cb0b8).
class Ov008Dialog : public Ov008Menu {
public:
    u8 unk_d4[0x108];
    s32 text; // text
    u8 unk_1e0[0x4];
};
OV008_SIZE(Ov008Dialog, 0x1e4);

// Talking character (0x21c bytes, vtables data_ov000_021cac60 -> data_ov000_021ca94c), with
// two text windows.
class Ov008Talk : public Ov008V {
public:
    u8 unk_04[0x8];
    u32 flags;
    u8 unk_10[0x58];
    s16 unk_68;
    u8 unk_6a[0x26];
    TextWin win; // vtable data_0208ba70
    TextWin win2;
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
    Model *unk_d8;
    Ov008Pic *unk_dc;
    Model *unk_e0;
    Ov008Pic *unk_e4;
    Model *unk_e8;
    Model *unk_ec;
    Model *unk_f0;
    Ov008Caption *caption;
    Ov008Panel *panel;
    Ov008PicC4 *unk_fc;
    Ov008Menu *menu;
    Ov008Dialog *dialog;
    Ov008Sel *sel;
    Ov008Talk *talk;
    u16 unk_110;
    u16 unk_112;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
};
OV008_SIZE(Ov008Mgr, 0x120);

extern "C" {
}

// Frees the object at field with the default heap selected.
#define OV008_FREE(field, T, stmt)                      \
    {                                                   \
        void *saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->heapHi;        \
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
    OV008_FREE(field, Model *, (func_02041558(p_), func_02041278(&p_->pltt), Heap_Free(p_)))

static inline void Ov008_DrawModel(Model *m) {
    ModelPart *anim;
    ModelRes *res = m->res;
    void *arg;
    ModelPartRes *t;
    if (res == NULL) {
        return;
    }
    anim = NULL;
    if (m->numParts > 0) {
        anim = m->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        Ov008SprSeq *e = (Ov008SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **e->unk_0c);
    }
    func_02042628(m, arg, anim, 0);
}

static inline void *Ov008_GetTex(Model *m, ModelRes *res, ModelPart *anim) {
    if (anim != NULL && anim->res != NULL) {
        return anim->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, **((Ov008SprSeq *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0))->unk_0c);
}

static inline void Ov008_DrawModel2(Model *m) {
    ModelRes *res = m->res;
    if (res != NULL) {
        ModelPart *anim = 0 >= m->numParts ? NULL : m->parts;
        func_02042628(m, Ov008_GetTex(m, res, anim), anim, 0);
    }
}

static inline s32 Ov008_Abs(s32 v) {
    return v < 0 ? -v : v;
}

#endif
