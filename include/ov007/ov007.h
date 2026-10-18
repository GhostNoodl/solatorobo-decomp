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

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))

struct Ov007Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
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
            void *p_ = (field);                         \
            if (p_ != NULL) {                           \
                func_02041558(p_);                      \
                func_02041278((u8 *)p_ + 0x88);         \
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
    Ov007V *unk_14;
    void *unk_18;
    void *unk_1c;
    void *unk_20;
    void *unk_24;
    void *unk_28;
    void *unk_2c;
    void *unk_30;
    void *unk_34;
    void *unk_38;
    Ov007V *unk_3c;
    u8 unk_40[0x8];
    Ov007V *unk_48;
    u8 unk_4c;
    u8 unk_4d;
    u8 unk_4e;
    u8 unk_4f;
    s32 unk_50;
    s32 unk_54;
    s32 unk_58;
    Ov007V *unk_5c[2];
    s8 unk_64;
    u8 unk_65;
    u16 unk_66;
    Ov007V *unk_68;
};

extern "C" {

extern Ov007Scene *data_ov007_021cfc60;
extern u8 *data_02097d48;
extern void *data_0208b318;
extern char data_ov007_021cfbd8[];
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
void func_ov000_0218ea20(void *p);
void func_ov000_0218fee4(void *p);
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
        void *p_ = (field);                             \
        if (p_ != NULL) {                               \
            func_02041558(p_);                          \
            func_02041278((u8 *)p_ + 0x88);             \
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
struct Ov007Rank {
    u32 unk_00 : 8;
    u32 rank : 8;
    u32 unk_10 : 16;
};

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
};

struct Ov007Flags44 {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 3;
    u32 b7 : 1;
    u32 rest : 24;
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
void *func_ov000_02173610(int id);

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

static inline BOOL Ov007_Flag2(Ov007V *p) {
    return FLD(Ov007Flags44, p, 0x48).b2 ? TRUE : FALSE;
}

static inline BOOL Ov007_Flag3(Ov007V *p) {
    return FLD(Ov007Flags44, p, 0x48).b3 ? TRUE : FALSE;
}

static inline BOOL Ov007_Flag7(Ov007V *p) {
    return FLD(Ov007Flags44, p, 0x48).b7 ? TRUE : FALSE;
}

static inline BOOL Ov007_Closed(Ov007V *p) {
    return FLD(u8, p, 0x8) == 0 ? TRUE : FALSE;
}

static inline BOOL Ov007_MenuDone(void) {
    return data_ov000_021ccd44->b1 ? TRUE : FALSE;
}

static inline BOOL Ov007_Busy(Ov007V *p) {
    return (FLD(u32, p, 0xc) & 0x10000) ? FALSE : TRUE;
}

static inline Ov007V *Ov007_NewPlayer(Ov007Scene *s, s32 id) {
    Ov007V *p = (Ov007V *)func_0203dd9c(0xe8);
    if (p != NULL) {
        FLD(void *, p, 0) = &data_ov000_021cac60;
        p->v28();
        FLD(void *, p, 0) = &data_ov000_021cad50;
        p->v28();
    }
    s->unk_68 = p;
    FLD(u32, s->unk_68, 0xc) |= 0x10000;
    p = s->unk_68;
    FLD(u32, p, 0xc) |= 0x8;
    FLD(u16, p, 0x48) = 0x14a5;
    FLD(s32, p, 0x54) = 0x1c;
    FLD(u32, s->unk_68, 0xc) |= 0x20000;
    FLD(s32, s->unk_68, 0x1c) = 4;
    s->unk_68->v08();
    func_ov000_0215c1bc(s->unk_68, 0x8000, func_0204c0e8(data_02149ef8, id));
    FLD(s16, s->unk_68, 0x68) = -0x299a;
    s->unk_68->v70();
    return p;
}

static inline void Ov007_FreePage(Ov007Scene *s) {
    OV007_FREE_V(s->unk_48, v04);
    OV007_FREE_M(s->unk_28);
    OV007_FREE_M(s->unk_2c);
}

extern "C" {
s32 func_02043d48(void *p);
void func_ov007_021cdff0(void *task);
void func_ov007_021cd58c(void *task, Ov007Scene *s);
}

#endif
