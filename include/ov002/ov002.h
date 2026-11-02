#ifndef OV002_OV002_H
#define OV002_OV002_H

#include "types.h"
#include "nitro/fx.h"
#include "nitro/gx.h"
#include "nitro/mi.h"
#include "nitro/std.h"
#include "nnsys/g3d.h"
#include "Main/Sys/SysState.h"
#include "Main/Res/ResMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Res/StageRes.h"
#include "Main/Res/StageCmd.h"
#include "Main/Gfx/Model.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Sys/Pad.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Movie/Movie.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Sys/Field.h"
#include "Main/Sys/GameScene.h"
#include "ov000/TaskList.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
typedef int (*VFunc)(...);
#else
typedef int (*VFunc)();
#endif

/* Generic object with a vtable as the first member. Slot vN is the virtual function at vtable offset N. */
#ifdef __cplusplus
}
class VObject {
public:
    virtual int v0x0(...);
    virtual int v0x4(...);
    virtual int v0x8(...);
    virtual int v0xc(...);
    virtual int v0x10(...);
    virtual int v0x14(...);
    virtual int v0x18(...);
    virtual int v0x1c(...);
    virtual int v0x20(...);
    virtual int v0x24(...);
    virtual int v0x28(...);
    virtual int v0x2c(...);
    virtual int v0x30(...);
    virtual int v0x34(...);
    virtual int v0x38(...);
    virtual int v0x3c(...);
    virtual int v0x40(...);
    virtual int v0x44(...);
    virtual int v0x48(...);
    virtual int v0x4c(...);
    virtual int v0x50(...);
    virtual int v0x54(...);
    virtual int v0x58(...);
    virtual int v0x5c(...);
    virtual int v0x60(...);
    virtual int v0x64(...);
    virtual int v0x68(...);
    virtual int v0x6c(...);
    virtual int v0x70(...);
    virtual int v0x74(...);
    virtual int v0x78(...);
    virtual int v0x7c(...);
    virtual int v0x80(...);
    virtual int v0x84(...);
    virtual int v0x88(...);
    virtual int v0x8c(...);
    virtual int v0x90(...);
    virtual int v0x94(...);
    virtual int v0x98(...);
    virtual int v0x9c(...);
    virtual int v0xa0(...);
    virtual int v0xa4(...);
    virtual int v0xa8(...);
    virtual int v0xac(...);
    virtual int v0xb0(...);
    virtual int v0xb4(...);
    virtual int v0xb8(...);
    virtual int v0xbc(...);
    virtual int v0xc0(...);
    virtual int v0xc4(...);
    virtual int v0xc8(...);
    virtual int v0xcc(...);
    virtual int v0xd0(...);
    virtual int v0xd4(...);
    virtual int v0xd8(...);
    virtual int v0xdc(...);
    virtual int v0xe0(...);
    virtual int v0xe4(...);
    virtual int v0xe8(...);
    virtual int v0xec(...);
    virtual int v0xf0(...);
    virtual int v0xf4(...);
    virtual int v0xf8(...);
    virtual int v0xfc(...);
};
extern "C" {
#define VC(obj, off) (((VObject *)(obj))->v##off)
#endif

/* Switch new allocations to the alternate heap (data_02097dd0->heapHi) and back. */
#define HEAP_PUSH(saved)                                  \
    do {                                                  \
        (saved) = data_02097dd0->cur;                     \
        data_02097dd0->cur = data_02097dd0->heapHi;       \
    } while (0)
#define HEAP_POP(saved) (data_02097dd0->cur = (saved))

void Heap_FreeArray(void *p);

/* ---- */
typedef struct Unk021f0f80 {
    s32 unk_00;
    s32 unk_04;
    s8 unk_08;
} Unk021f0f80;

extern Unk021f0f80 *data_ov002_021f0f80;
extern void *data_0208cc94;
extern char data_0214b105[];


typedef struct {
    s32 flag0 : 1;
    u32 flag1 : 1;
    u32 rest : 30;
} BitWord;

typedef struct {
    BitWord flags;
    s32 state;
} Unk021cceb4;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} BitByte;

extern BitWord *data_ov000_021ccd44;

u16 func_020594bc(void *a, int b, int c, int d);
void func_ov000_02180660(int a, int b);
void func_ov000_02180754(void);

static inline bool func_ov002_inline_flag1(void) {
    return data_ov000_021ccd44->flag1;
}

extern VFunc data_ov002_021ef530[];
extern char data_ov002_021ef3e4[];
extern char data_ov002_021ef3ec[];
extern char data_ov002_021ef3f8[];
void func_02035acc(void *a, void *b, u16 c);
void func_020359fc(void *a, void *b, u16 c, u8 d);
int func_02035bd4(void *a, void *b, u16 c);
void *func_ov000_0218084c(void *a, int b, int c);
void func_ov000_0215bb14(void *a, void *b);

struct Task50 : public VObject {
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
    u8 unk_0c[0x14];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x4];
    s32 unk_2c;
    u8 unk_30[0xc];
    void *unk_3c;
    VObject *unk_40;
    VObject *unk_44;
    s32 unk_48;
    s8 unk_4c;
    s8 unk_4d;
    s8 unk_4e;
    u8 unk_4f;
};

static inline void TaskBase_ctor(Task50 *self) {
    *(VFunc **)self = (VFunc *)data_ov000_021cc060;
    VC(self, 0x58)();
}

static inline Task50 *Task_021cd06c_ctor(Task50 *self) {
    TaskBase_ctor(self);
    *(VFunc **)self = data_ov002_021ef530;
    VC(self, 0x58)();
    return self;
}


#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))

/* NitroSDK sin/cos table: s16 sin,cos pairs */
#define FX_SINCOS_TABLE FX_SinCosTable_
/* Element i of the table, folded into a single symbol offset. */
#define FX_SINCOS(i) (FX_SinCosTable_[(i)])

extern void *data_ov000_021ccd40;
extern s32 data_ov000_021ccd38;
int func_02054f10(void *a, int b);
void func_ov000_0217357c(void *self);
extern char data_ov002_021ef3f9[];

static inline bool Task50_getFlag4(Task50 *self) {
    return self->flag4;
}

static inline bool func_ov002_isCurrent021ccd40(void *p) {
    return data_ov000_021ccd40 == p;
}

void *func_02035f30(void *a, void *b, u16 c);
void func_ov000_02173648(void *self);
extern u8 data_ov000_021ccd34;
void func_0203cb78(s32 a, int b, int c);
void func_ov002_021ce7b8(Task50 *self);

static inline void func_ov002_setCurrent021ccd40(void *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = FIELD(data_ov000_021ccd40, 0x14, s32);
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = p;
}

static inline bool func_ov002_isMode4(void) {
    BOOL r; if (data_02097d78[3] == 4) { r = TRUE; } else { r = data_02097d78[0] == 4; } return r;
}

#define DELETE_VOBJ(field)              \
    do {                                \
        VObject *o_ = (field);          \
        if (o_ != NULL) {               \
            if (o_ != NULL) {           \
                o_->v0x4();             \
            }                           \
            (field) = NULL;             \
        }                               \
    } while (0)

#define TASK_VOBJ(self, off) FIELD(self, off, VObject *)

static inline bool Task50_testFlags(Task50 *self, u32 mask) {
    return FIELD(self, 0x4, u32) & mask;
}
static inline bool Task50_getFlag5(Task50 *self) {
    return self->flag5;
}

static inline bool Task50_getFlag6(Task50 *self) {
    return self->flag6;
}

extern VFunc data_ov002_021ef4b0[];
extern VFunc data_ov002_021ef430[];
extern VFunc data_ov002_021ef410[];
extern VFunc data_ov002_021ef79c[];
void func_ov000_0216f168(void *self);

static inline void TaskBase_dtor(Task50 *self) {
    *(VFunc **)self = (VFunc *)data_ov000_021cc060;
    self->v0x5c();
}

static inline void Task_deleteModel(Task50 *self) {
    void *p = self->unk_3c;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558((Model *)p);
            func_02041278(&((Model *)p)->pltt);
            Heap_Free(p);
        }
        self->unk_3c = NULL;
    }
}

static inline bool func_ov002_isMode4b(void) {
    BOOL r;
    if (data_02097d78[3] == 4) {
        r = TRUE;
    } else {
        r = data_02097d78[1] == 4;
    }
    return r;
}

typedef void (*Callback)(void *);

extern VFunc data_ov002_021efa1c[];
extern VFunc data_ov002_021ef89c[];

s16 *func_0206ee90(u32 id);
extern s32 data_ov002_021f0f84[];
extern VFunc data_ov002_021ef71c[];
void func_ov002_021e916c(void);
void func_ov002_021d0b98(Task50 *self);

typedef struct Info0206ee90 {
    u16 unk_00 : 15;
    u16 flag : 1;
} Info0206ee90;

u32 func_0205975c(void *a, int idx);
void *func_0205976c(void *a, int idx);
u16 func_02059544(void *a, void *b, void *c, u16 d, u16 e);

void func_ov002_021e90dc(void);
void func_ov002_021e8f04(s32 id);
void *func_ov002_021e9b28(void *arg);
bool func_ov002_021e90ac(void);
extern void *data_ov002_021f0f9c;
extern VFunc data_ov002_021ef69c[];
void func_ov000_021c64b4(void *a, void *b);
void func_ov000_021c7000(void *a);
void func_ov002_021d1f70(void *self);

void func_0203caf8(int a);
void func_020444b0(void *a, s32 b, int c, int d);
void func_02044524(void *a);
void func_ov000_021c701c(void *a);

void func_ov002_021e4904(void *p);

static inline void func_ov002_021e4904_inline(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            Heap_FreeArray(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
}
void func_ov002_021e4714(void *p);
void func_ov002_021e49a0(void *p);
extern VFunc data_ov002_021ef91c[];

void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void *Ov002Vt_021f00fc_Dtor(void *p);

extern VFunc data_ov002_021ef99c[];

void func_ov002_021e4b80(void *p);
void func_ov002_021d37f8(void *self);
extern VFunc data_ov002_021ef81c[];
void func_ov000_021763c8(void);
u32 func_ov000_02176538(void);
u32 func_ov000_02180838(void *a);
void func_ov002_021d3ccc(void *self);

void *Ov002Vt_021f00ec_Dtor(void *p);
void func_ov002_021d25ec(Task50 *self);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
extern VFunc data_ov002_021ef684[];
void func_ov000_021c2310(void *self);

extern VFunc data_ov002_021efba4[];
extern VFunc data_ov002_021efb14[];
extern char data_ov002_021efad1[];
void func_ov002_021e1d28(void *self);

void func_ov002_021e1cc8(void *self);
void func_ov002_021e1ed8(void *self);
void func_ov002_021e2690(void *self, u8 a, int b);
void func_ov002_021e23ac(void *self);
void func_ov002_021e2528(void *self);
extern VFunc data_ov002_021efb24[];
void func_ov002_021da2fc(void);
void *func_ov002_021da420(void);
void func_ov002_021da5c0(void *self);
BOOL func_ov002_021da800(void *self);
void func_ov002_021da894(void *self);
void func_ov002_021da960(void *self);

static inline bool Task50_isFlag1Clear(Task50 *self) {
    return !self->flag1;
}

void func_ov002_021dab58(void *a, int b);
BOOL func_ov002_021da8d8(void *a);
extern VFunc data_ov002_021efc24[];
void func_ov002_021d5f60(void *a);
void *func_ov000_02173610(int id);
extern VFunc data_ov002_021efb04[];
void func_ov000_02163254(void *self);
extern VFunc data_ov000_021caec8[];
extern VFunc data_ov000_021cac60[];

void *func_0206ec8c(u32 id);
u8 *func_0206ef10(u32 id);
void func_ov000_02162b40(void *a, s32 b, s32 c, const char *d, s32 e, const char *f, s32 g, s16 h);
void func_ov000_021c95ac(void *a, u16 id);
void func_ov002_021e2754(void *a, u16 id);
extern char data_ov002_021efaeb[];
extern char data_ov002_021efae1[];

void func_ov002_021da39c(void);
typedef int (*MenuCallback)(void *self, void *arg);
typedef void (*MenuCallback2)(void *arg, void *self);

static inline bool func_ov002_isState2(void *self) {
    return FIELD(self, 0x4, s32) == 2;
}

typedef void (*MenuCallback3)(void *arg, void *self, int a);

int func_ov002_021d6cf0(void *self);

void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);

#define DELETE_WITH(field, dtor)        \
    do {                                \
        void *p_ = (field);             \
        if (p_ != NULL) {               \
            if (p_ != NULL) {           \
                dtor(p_);               \
                Heap_Free(p_);      \
            }                           \
            (field) = NULL;             \
        }                               \
    } while (0)

extern VFunc data_ov002_021efe3c[];

void *Ov002Vt_021efe3c_Dtor(void *self);
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

u8 *func_0206ef50(u32 id);
void *func_02070dcc(int id);
void NNS_G3dMdlSetMdlAlpha(void *res, int idx, int val);
extern char data_ov002_021efddd[];

u8 *func_0206ede8(u16 id);
BOOL func_ov002_021e38f8(s32 *out, void *ev);
void func_ov002_021d8148(void *self);

static inline void func_ov002_021d7c04_inline(void *self) {
    u8 *info = func_0206ede8(FIELD(self, 0x48, u16));
    void *v;
    FIELD(self, 0x4a, u8) = info[0] == 0x80 ? 2 : 1;
    v = func_02070dcc(FIELD(self, 0x4b, u8) = info[1]);
    MI_CpuCopy8(v, (u8 *)self + 0x4c, 8);
    func_ov002_021e38f8((s32 *)((u8 *)self + 0x5c), v);
}

void func_ov002_021d83f0(void *self);
u8 Gfx3DState_NextPolyId(void *a);
void NNS_G3dMdlSetMdlPolygonIDAll(void *mdl, int polygonID);
void func_ov002_021e3b0c(s32 *out, s32 *pos, s32 *origin);

typedef struct Vec2 {
    s32 x;
    s32 y;
} Vec2;

typedef struct Bits021d8b48 {
    u16 lo : 8;
    u16 mode : 2;
    u16 hi : 6;
} Bits021d8b48;

void func_ov002_021eae48(void *self);
extern void *data_ov002_021f0f90[];
void func_ov002_021df1c4(void *self);

typedef struct Bits16 {
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
} Bits16;

extern VFunc data_ov002_021efef0[];
extern VFunc data_ov002_021efe7c[];
extern VFunc data_ov002_021eff30[];
extern VFunc data_ov002_021eff10[];
extern VFunc data_ov002_021eff50[];
extern VFunc data_ov002_021efe4c[];
extern VFunc data_ov002_021f0684[];
extern VFunc data_ov002_021f00ec[];
extern void *data_ov002_021f0f98;
void func_ov002_021ddd80(void *self);
void func_ov002_021da430(void *self);
void func_ov002_021dddd0(void *self);
void func_ov002_021dbdb8(void *self);
void func_ov002_021db64c(void *self);
void func_ov002_021d6ec4(void *self);
void func_ov002_021eae3c(void *self);

typedef struct Nibbles16 {
    u16 n0 : 4;
    u16 n1 : 4;
    u16 n2 : 4;
    u16 n3 : 4;
} Nibbles16;

typedef struct Bits32 {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
} Bits32;

extern VFunc data_ov002_021f00fc[];
extern VFunc data_ov002_021f0cf8[];
extern VFunc data_ov002_021f0ef4[];
void *func_ov000_02154b58(void *a, void *b);
void func_ov000_02153c48(void *a, s32 b, int c, int d, u8 e);

extern VFunc data_ov002_021efeb8[];
extern VFunc data_ov002_021f0674[];
int func_ov002_021e7ea8(void *a);
void func_ov002_021e7dac(void *self);
void func_ov002_021e0420(void *self);
void func_ov000_021c524c(void *a, void *b, VecFx32 *pos, s32 d);

extern VFunc data_ov000_021ccbe0[];
void func_ov000_021c3bb0(void *self);
void func_ov002_021d95e0(void *a);
void func_02065eec(void *a);

static inline void *func_ov002_021e0b08_inline(void *self) {
    void *prev;
    void *next;
    *(VFunc **)self = data_ov002_021efeb8;
    prev = FIELD(self, 0x70, void *);
    if (prev != NULL) {
        FIELD(prev, 0x74, void *) = FIELD(self, 0x74, void *);
    }
    next = FIELD(self, 0x74, void *);
    if (next != NULL) {
        FIELD(next, 0x70, void *) = FIELD(self, 0x70, void *);
    }
    return self;
}

extern VFunc data_ov002_021f0e14[];
extern VFunc data_ov002_021f0e84[];
extern VFunc data_ov002_021f0e4c[];
extern VFunc data_ov002_021f0f2c[];
extern VFunc data_ov002_021efed4[];
extern VFunc data_ov002_021efe9c[];
void func_ov002_021d8e90(void *self);
void func_ov002_021d7ed8(void *self);

typedef struct Bits021e0420 {
    u32 lo : 16;
    u32 val : 5;
    u32 hi : 11;
} Bits021e0420;

extern VFunc data_ov002_021f0ce8[];
int func_ov002_021e3dac(Vec2 *pos, void *a, void *b, Vec2 *out);


typedef struct Bits021e2f04 {
    u32 lo : 12;
    u32 nib : 4;
    u32 hi : 16;
} Bits021e2f04;

void func_ov002_021e0280(void *self);
void func_ov002_021d7988(void *a);
void *func_ov000_0214b724(void *p);

extern char data_ov002_021effde[];
extern char data_ov002_021effeb[];
extern VFunc data_ov002_021f0ebc[];
extern VFunc data_ov002_021f001c[];
void func_ov002_021e4fac(void *self);

typedef struct Bits8 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Bits8;

extern VFunc data_ov002_021f0734[];

static inline void func_ov002_021e4d4c_inline(void *self) {
    u8 *owner = FIELD(self, 0x48, u8 *);
    int i;
    if (owner != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(owner + 0x28))[i] == self) {
                ((void **)(owner + 0x28))[i] = NULL;
                break;
            }
        }
        FIELD(self, 0x48, void *) = NULL;
    }
    for (i = 0; i < 8; i++) {
        void *child = ((void **)((u8 *)self + 0x28))[i];
        if (child != NULL) {
            FIELD(child, 0x48, void *) = NULL;
        }
    }
}

void func_ov002_021ec2ac(void *self);

BOOL func_ov002_021d52e0(void *self, void *ev);
typedef BOOL (*EvCallback)(void *, void *);
void func_ov000_02152294(void *self, u16 a, int b, EvCallback cb);
u8 LangData_GetLang(void);
void func_ov002_021d4540(void *dst, u32 size, const void *a, const void *b, int mode);
// The resource-name table data_ov002_021ef5ac (defined in ov002_021ef150.cpp). Not const:
// func_ov002_021d278c reloads it after every call in its loop.
typedef struct Ov002ResNames {
    const char *hdExt;
    const char *bmExt;
    const char *pic;
    const char *param;
    s32 scale;
    const char *cepct;
} Ov002ResNames;
extern u8 data_ov002_021ef650[];

void func_ov000_021c3d20(void *self);
void func_ov000_021c4ab8(void *self);
extern u8 data_ov002_021ef038[];

extern VFunc data_ov002_021f075c[];
void func_ov002_021e5d88(void *self);
void func_ov002_021e8cc4(void *self);
void *func_ov000_0214b6d8(void *p);
void func_ov000_0214b88c(void *p, const void *a);
void func_ov000_0214b810(void *p);
BOOL func_ov000_0214b8d8(void *p);
// The staff-roll configuration (defined in ov002_021ef380.cpp).
struct Ov002StaffCfg {
    s32 w0, w4;
    const char *dir;
    const char *photo;
    s32 w10;
    const char *pathFmt;
    const char *dir2;
    s32 w1c, w20, w24, w28, w2c;
    s32 tagTime, tagFadeOut, tagFadeIn;
    char photo0[8];
    char photo1[8];
    const char *photoB;
    const char *photoA;
};
extern Ov002StaffCfg data_ov002_021f0d88;

extern VecFx32 data_ov002_021ef110;

extern u8 data_ov002_021f00cc[];
extern u8 data_ov002_021f00d8[];
VObject *func_02066774(void *a, void *b, int c, void *d);

extern VFunc data_ov002_021f07d4[];
void func_ov002_021e51f8(void *self);
void func_ov002_021d9728(void *p);
void func_02065ac0(void *p);

void func_ov002_021e391c(s32 *m, int rot);

extern void *data_ov002_021f0fac[9];
void func_ov002_021eea74(void *p);
int STD_TSNPrintf(void *dst, u32 size, const void *fmt, ...);
extern void *data_ov002_021f0624[];
extern u8 data_ov002_021f064c[];
extern u8 data_ov002_021f0647[];

BOOL func_ov000_0218f110(void *p);
extern u8 data_ov002_021efdf6[];

void func_ov002_021d9504(void *self);
void func_ov002_021ebfd0(void *p);
extern VFunc data_ov002_021efe6c[];

void func_ov002_021da184(void *self, void *p);
void func_ov000_021c9544(void *a, void *b);
typedef struct Bits021d9e38 {
    u16 b0 : 1;
    u16 mode : 2;
    u16 id : 4;
    u16 rest : 9;
} Bits021d9e38;
typedef struct Oam021e7ab8 {
    u32 y : 8;
    u32 a0 : 8;
    u32 x : 9;
    u32 a1 : 7;
    u32 b0 : 12;
    u32 pal : 4;
    u32 b1 : 16;
} Oam021e7ab8;

void func_ov002_021d36b8(void *self, s32 n);
extern VFunc data_ov002_021eff74[];
void func_ov002_021eacd0(void *self);
void func_02043858(void *p);
void func_ov002_021e7cb4(void *self);

BOOL func_ov002_021e41cc(Vec2 *a, Vec2 *b, void *c, void *d, Vec2 *out);
void func_ov002_021e63f0(void *self);
void *func_ov002_021e4ee4(void *self, s32 kind, s32 min);
void func_ov002_021e61b4(void *p);
extern VFunc data_ov002_021f0694[];

void func_ov002_021e6360(void *self);

void *func_ov002_021e9974(s32 a, s32 b, s16 c, void *d);

void *func_02035fe8(void *a, void *b);
void func_ov002_021ec010(void *p, const void *src);
extern VFunc data_ov002_021f07ac[];
void *Ov002Vt_021f0ce8_Dtor(void *p);

extern u8 data_ov002_021ef655[];
extern u8 data_ov002_021ef659[];
extern u8 data_ov002_021ef65d[];
extern u8 data_ov002_021ef661[];
extern u8 data_ov002_021ef651[];
extern u8 data_ov002_021ef665[];
extern VFunc data_ov002_021f000c[];

void *func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(VecFx32 *a, VecFx32 *b, s32 c, void *d);
extern VecFx32 data_ov002_021ef124;

extern u8 data_ov002_021f064d[];
extern u8 data_ov002_021f0654[];
extern u8 data_ov002_021f065e[];
extern u8 data_ov002_021f0665[];
extern VFunc data_ov002_021f002c[];
void func_ov000_021c4738(void *self, void *a);
extern u16 data_ov002_021ef058[][5];
typedef int (*SortCmp)(void *, void *);

void func_ov000_02162a58(void *p);
void func_ov000_02163594(void *p);

void func_0206e3a0(void *a, void *b);
void func_02043b20(void *p);
void func_ov002_021e5d0c(void *self);

void *Ov002Vt_021f0ce8_Ctor(void *p);
void func_ov002_021e6a14(void *self);
void func_ov002_021ec1e0(void *self, void *src);

extern VFunc data_ov002_021f06e4[];

void func_ov002_021e6290(void *self);

void *func_0206ec48(u16 id);
void func_ov002_021e019c(void *self, u8 a, u8 b);

void func_ov000_0216f844(void *p, int a);
VObject *func_020657b0(void *a, void *b);
extern VFunc data_ov002_021f070c[];

extern const u8 data_ov002_021eef74[];

void func_ov002_021e5140(void *self);
void *func_02035d2c(void *a);

#ifdef __cplusplus
}
#endif

#endif

