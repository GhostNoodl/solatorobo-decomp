#ifndef OV007_H
#define OV007_H

#include "types.h"

// Stand-in for a polymorphic object: vNN is the function at byte offset NN in the vtable.
class Ov007V {
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

// Stores a vtable pointer into a freshly allocated object (the inline constructors).
#define OV007_SET_VT(p, vt) (*(void **)(p) = (void *)(vt))
#define OV007_SIZE(T, n) typedef char T##_size_check[(sizeof(T) == (n)) ? 1 : -1]

struct Ov007Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
    u8 unk_0c[0x13];
    u8 unk_1f;
    u8 unk_20[0x11];
    u8 unk_31;
};

// 2D sprite (main, 0x160 bytes; set up by func_02041218 + func_02041440).
struct Ov007SprRes {
    u8 unk_00[0x4];
    void *unk_04; // cell bank
    u8 unk_08[0x4];
    void *unk_0c; // animation bank
};

struct Ov007SprFrame {
    u8 unk_00[0x30];
    void *unk_30;
};

struct Ov007SprAnim {
    u8 unk_00[0x4];
    Ov007SprFrame *unk_04;
};

struct Ov007SprSeq {
    u8 unk_00[0xc];
    u16 **unk_0c;
};

struct Ov007SprAttr {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 pid : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 rest : 12;
};

struct Ov007Sprite {
    u8 unk_00[0x28];
    Ov007SprRes *unk_28;
    u8 unk_2c[0x20];
    u8 unk_4c[0x20];
    union {
        u32 flags;
        Ov007SprAttr attr;
    };
    u8 unk_70[0x8];
    Ov007SprAnim *unk_78;
    u8 unk_7c[0x4];
    s32 unk_80;
    u8 unk_84[0x4];
    u8 unk_88[0x74]; // initialised by func_02041218
    s32 unk_fc;
    s32 unk_100;
    u8 unk_104[0x4c];
    s32 unk_150;
    u8 unk_154[0xc];
};
OV007_SIZE(Ov007Sprite, 0x160);

// ov000 model resource (0x138 bytes, func_ov000_0218e9c4).
struct Ov007Anim {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04[0xc];
    char unk_10[0x20]; // model directory
    char unk_30[0x18]; // model name
    void *unk_48;
    char unk_4c[0x20]; // animation directory
    char unk_6c[0xcc]; // animation name
};
OV007_SIZE(Ov007Anim, 0x138);

// What func_ov000_02190a30 returns for a model.
struct Ov007MdlAnm {
    u8 unk_00[0x112];
    s16 unk_112;
};

// ov000 model (0xe8 bytes, func_ov000_0218fe1c).
struct Ov007Model {
    u8 unk_00[0x4];
    void *unk_04;
    u8 unk_08[0x1c];
    u8 unk_24[0x90]; // NNS render object
    u16 unk_b4;
    u8 unk_b6[0xc];
    u16 unk_c2;
    u8 unk_c4[0x24];
};
OV007_SIZE(Ov007Model, 0xe8);

// The render-object callback state passed to func_ov007_021ce020 / func_ov007_021cdff0.
struct Ov007RsMat {
    u8 unk_00[0xc];
    u32 unk_0c;
};

struct Ov007Rs {
    u8 unk_00[0x1c];
    void *unk_1c;
    u8 unk_20[0x70];
    u8 unk_90;
    u8 unk_91[0x1f];
    Ov007RsMat *unk_b0;
};

// The G3 state block at data_02097d48 + 0x8b0.
struct Ov007G3 {
    u8 unk_00[0x38];
    s32 unk_38;
    u16 unk_3c[0x20]; // toon table
};

struct Ov007Sys {
    u8 unk_000[0x8b0];
    Ov007G3 unk_8b0;
    u8 unk_92c[0xb8];
    s32 unk_9e4;
};

// The license / title picture (0x4c bytes, vtable data_0208b318).
class Ov007Pic : public Ov007V {
public:
    u8 unk_04[0x40];
    s32 unk_44;
    u8 unk_48[0x4];
};
OV007_SIZE(Ov007Pic, 0x4c);

struct Ov007MenuFlags {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 3;
    u32 b7 : 1;
    u32 rest : 24;
};

// The yes/no menu (0x58 bytes, vtables data_0208b614 -> data_0208ca9c -> data_0208c994).
class Ov007Menu : public Ov007V {
public:
    u8 unk_04[0x4];
    u8 unk_08;
    u8 unk_09[0x3f];
    Ov007MenuFlags unk_48;
    u8 unk_4c[0xc];
};
OV007_SIZE(Ov007Menu, 0x58);

// ov000 player object (0xe8 bytes, vtables data_ov000_021cac60 -> data_ov000_021cad50).
class Ov007Player : public Ov007V {
public:
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    u8 unk_20[0x28];
    u16 unk_48;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0x10];
    s16 unk_68;
    u8 unk_6a[0x7e];
};
OV007_SIZE(Ov007Player, 0xe8);

struct Ov007WinAttr {
    u32 b0 : 8;
    u32 alpha : 5;
    u32 pid : 8;
    u32 rest : 11;
};

// Text window (0xb8 bytes, vtable data_0208ba70, func_0204c7d0).
class Ov007Win : public Ov007V {
public:
    union {
        u32 flags;
        Ov007WinAttr attr;
    };
    u8 unk_08[0x1c];
    s32 unk_24; // text
    s32 unk_28;
    u8 unk_2c[0xb];
    s8 unk_37;
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44; // width
    s32 unk_48;
    s32 unk_4c;
    u8 unk_50[0x20];
    s32 unk_70;
    u8 unk_74[0x44];
};
OV007_SIZE(Ov007Win, 0xb8);

// Title camera (0xbc bytes, func_0204b370).
class Ov007Cam : public Ov007V {
public:
    u8 unk_04[0x24];
    s32 unk_28;
    s32 unk_2c;
    s16 unk_30;
    s16 unk_32;
    u16 unk_34;
    u16 unk_36;
    s32 unk_38;
    u8 unk_3c;
    u8 unk_3d;
    u8 unk_3e;
    u8 unk_3f[0x9];
    s32 unk_48;
    u8 unk_4c[0x70];
};
OV007_SIZE(Ov007Cam, 0xbc);

// The object at data_02097e3c.
struct Ov007Game {
    u8 unk_000[0x149];
    u8 unk_149;
};

// The ov000 object func_ov000_02173610(8) returns: a callback slot and its argument.
struct Ov007Menu8 {
    u8 unk_00[0xbc];
    void *unk_bc;
    void *unk_c0;
};

// What func_ov007_021cd58c is called with.
struct Ov007RankC {
    u8 unk_00[0x24];
    struct {
        u32 unk_00 : 8;
        u32 rank : 8;
        u32 unk_10 : 16;
    } unk_24;
};

struct Ov007RankB {
    u8 unk_00[0x28];
    Ov007RankC *unk_28;
};

struct Ov007RankA {
    u8 unk_00[0x5c];
    Ov007RankB *unk_5c;
};

extern "C" {
extern Ov007Heap *data_02097dd0;
void *func_0203dd9c(u32 size);
void func_0203de1c(void *p);
}

#define OV007_FREE_V(field, slot)                       \
    {                                                   \
        u32 saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->def;        \
        if ((field) != NULL) {                          \
            Ov007V *p_ = (field);                       \
            if (p_ != NULL) {                           \
                p_->slot();                             \
            }                                           \
            (field) = NULL;                             \
        }                                               \
        data_02097dd0->cur = saved;                     \
    }

#define OV007_FREE_D(field, dtor)                       \
    {                                                   \
        u32 saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->def;        \
        if ((field) != NULL) {                          \
            void *p_ = (field);                         \
            if (p_ != NULL) {                           \
                dtor(p_);                               \
                func_0203de1c(p_);                      \
            }                                           \
            (field) = NULL;                             \
        }                                               \
        data_02097dd0->cur = saved;                     \
    }

#define OV007_FREE_M(field)                             \
    {                                                   \
        u32 saved = data_02097dd0->cur;                 \
        data_02097dd0->cur = data_02097dd0->def;        \
        if ((field) != NULL) {                          \
            Ov007Sprite *p_ = (field);                  \
            if (p_ != NULL) {                           \
                func_02041558(p_);                      \
                func_02041278(p_->unk_88);         \
                func_0203de1c(p_);                      \
            }                                           \
            (field) = NULL;                             \
        }                                               \
        data_02097dd0->cur = saved;                     \
    }

struct Ov007Scene {
    s32 timer;
    s32 mode;
    s32 state;
    s32 sub;
    s32 idx;
    Ov007Pic *unk_14;
    Ov007Anim *unk_18;
    Ov007Anim *unk_1c;
    Ov007Anim *unk_20;
    Ov007Anim *unk_24;
    Ov007Sprite *unk_28;
    Ov007Sprite *unk_2c;
    Ov007Model *unk_30;
    Ov007Model *unk_34;
    Ov007Model *unk_38;
    Ov007Cam *unk_3c;
    s16 unk_40;
    u8 unk_42[0x2];
    s32 unk_44;
    Ov007Menu *unk_48;
    u8 unk_4c;
    u8 unk_4d;
    u8 unk_4e;
    u8 unk_4f;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    Ov007Win *unk_5c[2];
    s8 unk_64;
    u8 unk_65;
    u16 unk_66;
    Ov007Player *unk_68;
};
OV007_SIZE(Ov007Scene, 0x6c);

extern "C" {

extern Ov007Scene *data_ov007_021cfc60;
extern Ov007Sys *data_02097d48;
extern void *data_0208b318;
extern void *data_ov000_021ccd54;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_02149ef8;

void func_ov007_021cce28(Ov007Scene *s);
void func_ov007_021ccec0(Ov007Scene *s);
void func_ov007_021ccf9c(Ov007Scene *s);
void func_ov007_021cd628(Ov007Scene *s);
void func_ov007_021cef80(Ov007Scene *s);
void func_ov007_021ce038(Ov007Scene *s);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fee4(void *p);
void func_02041558(void *p);
void func_02041278(void *p);
void func_0203c9e8(int a, int b);
void func_0203cc58(int a, int b, int c);
void func_0203cb78(s32 a, int b, int c);
BOOL func_ov000_02189068(void *p);
s32 func_0204c0e8(void *p, s32 id);
void func_ov000_0215c1bc(void *p, s32 a, s32 b);
}

#define OV007_DEL_V(field, slot)                        \
    if ((field) != NULL) {                              \
        Ov007V *p_ = (field);                           \
        if (p_ != NULL) {                               \
            p_->slot();                                 \
        }                                               \
        (field) = NULL;                                 \
    }
#define OV007_DEL_D(field, dtor)                        \
    if ((field) != NULL) {                              \
        void *p_ = (field);                             \
        if (p_ != NULL) {                               \
            dtor(p_);                                   \
            func_0203de1c(p_);                          \
        }                                               \
        (field) = NULL;                                 \
    }
#define OV007_DEL_M(field)                              \
    if ((field) != NULL) {                              \
        Ov007Sprite *p_ = (field);                      \
        if (p_ != NULL) {                               \
            func_02041558(p_);                          \
            func_02041278(p_->unk_88);             \
            func_0203de1c(p_);                          \
        }                                               \
        (field) = NULL;                                 \
    }
#define OV007_PUSH(saved)                               \
    saved = data_02097dd0->cur;                         \
    data_02097dd0->cur = data_02097dd0->def;
#define OV007_POP(saved) data_02097dd0->cur = saved;

#define OV007_DEL2(field, stmt)                         \
    if ((field) != NULL) {                              \
        p = (field);                                    \
        if (p != NULL) {                                \
            stmt;                                       \
        }                                               \
        (field) = NULL;                                 \
    }

struct Ov007Row {
    s32 v;
    u8 unk_04[0x14];
};

struct Ov007RowB {
    u8 v;
    u8 unk_01[0x17];
};

struct Ov007Fade {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
};

struct Ov007Pad {
    u8 unk_00[0x12];
    u16 trg;
    u8 unk_14[0x2];
    u16 unk_16;
};


struct Ov007Bits {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
};

extern "C" {

extern Ov007Fade data_02097d78;
extern Ov007Pad *data_02097dc8;
extern Ov007Bits *data_ov000_021ccd44;
extern const Ov007Row data_ov007_021cfa50[];
extern const Ov007Row data_ov007_021cfa54[];
extern const Ov007Row data_ov007_021cfa58[];
extern const Ov007Row data_ov007_021cfa5c[];
extern const Ov007Row data_ov007_021cfa60[];
extern const Ov007RowB data_ov007_021cfa64[];
extern void *data_0208b614;
extern void *data_0208ca9c;
extern void *data_0208c994;

void func_02041218(void *p);
void func_02041440(void *p, s32 res, int c);
void *func_02034d88(Ov007V *a, void *b);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
BOOL func_02054f10(void *a, int b);
BOOL OS_IsRunOnTwl(void);
void func_ov000_02180660(int a, int b);
void func_ov000_02180754(void);
Ov007Menu8 *func_ov000_02173610(int id);

}

static inline BOOL Ov007_FadeIdle(void) {
    BOOL r;
    if (data_02097d78.unk_0c == 0 && data_02097d78.unk_00 == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Ov007_FadeDone(void) {
    BOOL r;
    if (data_02097d78.unk_0c == 4) {
        r = TRUE;
    } else {
        r = data_02097d78.unk_00 == 4;
    }
    return r;
}

static inline BOOL Ov007_Flag2(Ov007Menu *p) {
    return p->unk_48.b2 ? TRUE : FALSE;
}

static inline BOOL Ov007_Flag3(Ov007Menu *p) {
    return p->unk_48.b3 ? TRUE : FALSE;
}

static inline BOOL Ov007_Flag7(Ov007Menu *p) {
    return p->unk_48.b7 ? TRUE : FALSE;
}

static inline BOOL Ov007_Closed(Ov007Menu *p) {
    return p->unk_08 == 0 ? TRUE : FALSE;
}

static inline BOOL Ov007_MenuDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL Ov007_Busy(Ov007Player *p) {
    return (p->unk_0c & 0x10000) ? FALSE : TRUE;
}

static inline Ov007Player *Ov007_NewPlayer(Ov007Scene *s, s32 id) {
    Ov007Player *p = (Ov007Player *)func_0203dd9c(0xe8);
    if (p != NULL) {
        OV007_SET_VT(p, &data_ov000_021cac60);
        p->v28();
        OV007_SET_VT(p, &data_ov000_021cad50);
        p->v28();
    }
    s->unk_68 = p;
    s->unk_68->unk_0c |= 0x10000;
    p = s->unk_68;
    p->unk_0c |= 0x8;
    p->unk_48 = 0x14a5;
    p->unk_54 = 0x1c;
    s->unk_68->unk_0c |= 0x20000;
    s->unk_68->unk_1c = 4;
    s->unk_68->v08();
    func_ov000_0215c1bc(s->unk_68, 0x8000, func_0204c0e8(data_02149ef8, id));
    s->unk_68->unk_68 = -0x299a;
    s->unk_68->v70();
    return p;
}

static inline void Ov007_FreePage(Ov007Scene *s) {
    OV007_FREE_V(s->unk_48, v04);
    OV007_FREE_M(s->unk_28);
    OV007_FREE_M(s->unk_2c);
}

extern "C" {
u8 func_02043d48(void *p);
void func_ov007_021cdff0(Ov007Rs *rs);
void func_ov007_021cd58c(Ov007RankA *task, Ov007Scene *s);
}

#endif
