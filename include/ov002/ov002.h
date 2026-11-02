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
#include "Main/Res/ResArc.h"
#include "Main/Res/ArcName.h"
#include "Main/Gfx/G3dGlbSyms.h"
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
#include "ov000/VObj.h"
#include "ov000/UiObj.h"
#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"
#include "ov002/Ov002Task.h"
#include "ov002/StageObj.h"
#include "ov002/ObjLayouts.h"

#ifdef __cplusplus
extern "C" {
#endif

// Resource lookups ov002 used to get from Effect.h, at the types Effect.h gave them. The defining TUs say
// void *(ResList *, const char *) (Main/Res/ResList.c) and (const char *, u32 *) (Main/Sys/NamePool.cpp);
// ov002's callers pass untyped FIELD() values, so these stay as they were.
extern EffectFile *func_02034ec0(void *arc, const char *name);
extern EffectFile *func_02034ff8(void *arc, const char *name);
extern BOOL func_0203ed04(const char *name, void *data);
extern void func_0203f0b4(void *data);

#ifdef __cplusplus
typedef int (*VFunc)(...);
#else
typedef int (*VFunc)();
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


static inline void TaskBase_ctor(Task *self) {
    *(VFunc **)self = (VFunc *)data_ov000_021cc060;
    self->vfunc_58();
}

static inline Task021ef530 *Task_021cd06c_ctor(Task021ef530 *self) {
    TaskBase_ctor(self);
    *(VFunc **)self = data_ov002_021ef530;
    self->vfunc_58();
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

static inline bool Task_getFlag4(Task *self) {
    return self->unk_04_4;
}

static inline bool func_ov002_isCurrent021ccd40(void *p) {
    return data_ov000_021ccd40 == p;
}

void *func_02035f30(void *a, void *b, u16 c);
void func_ov000_02173648(void *self);
extern u8 data_ov000_021ccd34;
void func_0203cb78(s32 a, int b, int c);
void func_ov002_021ce7b8(Task021ef4b0 *self);

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
        VObj *o_ = (field);          \
        if (o_ != NULL) {               \
            if (o_ != NULL) {           \
                o_->vfunc_04();             \
            }                           \
            (field) = NULL;             \
        }                               \
    } while (0)


static inline bool Task_testFlags(Task *self, u32 mask) {
    return self->unk_04 & mask;
}
static inline bool Task_getFlag5(Task *self) {
    return self->unk_04_5;
}

static inline bool Task_getFlag6(Task *self) {
    return self->unk_04_6;
}

extern VFunc data_ov002_021ef4b0[];
extern VFunc data_ov002_021ef430[];
extern VFunc data_ov002_021ef410[];
extern VFunc data_ov002_021ef79c[];
void func_ov000_0216f168(void *self);

static inline void TaskBase_dtor(Task *self) {
    *(VFunc **)self = (VFunc *)data_ov000_021cc060;
    self->vfunc_5c();
}

}
// Frees the Model at unk_3c (Task021ef430, Task021ef530).
template <class T> static inline void Task_deleteModel(T *self) {
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
extern "C" {

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
void func_ov002_021d0b98(Task021ef89c *self);

typedef struct Info0206ee90 {
    u16 unk_00 : 15;
    u16 flag : 1;
} Info0206ee90;

u32 func_0205975c(void *a, int idx);
void *func_0205976c(void *a, int idx);
u16 func_02059544(void *a, void *b, void *c, u16 d, u16 e);

void func_ov002_021e90dc(void);
void func_ov002_021e8f04(s32 id);
bool func_ov002_021e90ac(void);
extern VFunc data_ov002_021ef69c[];
void func_ov000_021c64b4(void *a, void *b);
void func_ov000_021c7000(void *a);
void func_ov002_021d1f70(Task021ef69c *self);

void func_0203caf8(int a);
void Movie_Load(void *a, s32 b, int c, int d);
void Movie_RequestStop(void *a);
void func_ov000_021c701c(void *a);

void func_ov002_021e4904(Ov002LevelTable *self);

static inline void func_ov002_021e4904_inline(Ov002LevelTable *self) {
    self->src = NULL;
    self->count = 0;
    {
        void *saved;
        HEAP_PUSH(saved);
        if (self->thresholds != NULL) {
            Heap_FreeArray(self->thresholds);
            self->thresholds = NULL;
        }
        HEAP_POP(saved);
    }
    self->label = NULL;
    self->desc = NULL;
}
void func_ov002_021e4714(Ov002LevelTable *self);
void func_ov002_021e49a0(Ov002StrTable *self);
extern VFunc data_ov002_021ef91c[];

void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
Ov002LevelTable *Ov002Vt_021f00fc_Dtor(Ov002LevelTable *self);

extern VFunc data_ov002_021ef99c[];

void func_ov002_021e4b80(Ov002StrTable *self);
void func_ov002_021d37f8(Task021ef91c *self);
extern VFunc data_ov002_021ef81c[];
void func_ov000_021763c8(void);
u32 func_ov000_02176538(void);
u32 func_ov000_02180838(void *a);
void func_ov002_021d3ccc(Task021ef81c *self);

Ov002StrTable *Ov002Vt_021f00ec_Dtor(Ov002StrTable *self);
void func_ov002_021d25ec(Task021ef99c *self);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
extern VFunc data_ov002_021ef684[];
void func_ov000_021c2310(void *self);

extern VFunc data_ov002_021efba4[];
extern VFunc data_ov002_021efb14[];
extern char data_ov002_021efad1[];
void func_ov002_021e1d28(Ov002Hud *self);

void func_ov002_021e1cc8(Ov002Hud *self);
void func_ov002_021e1ed8(Ov002Hud *self);
void func_ov002_021e2690(Ov002Hud *self, u8 row, int force);
void func_ov002_021e23ac(Ov002Hud *self);
void func_ov002_021e2528(Ov002Hud *self);
extern VFunc data_ov002_021efb24[];
void func_ov002_021da2fc(void);
Obj021efe7c *func_ov002_021da420(void);
void func_ov002_021da5c0(Obj021efe7c *self);
BOOL func_ov002_021da800(Obj021efe7c *self);
void func_ov002_021da894(Obj021efe7c *self);
void func_ov002_021da960(Obj021efe7c *self);

static inline bool Task_isFlag1Clear(Task *self) {
    return !self->unk_04_1;
}

void func_ov002_021dab58(Obj021efe7c *a, int b);
BOOL func_ov002_021da8d8(Obj021efe7c *a);
extern VFunc data_ov002_021efc24[];
void func_ov002_021d5f60(Task021efc24 *self);
void *Task_FindById(int id);
extern VFunc data_ov002_021efb04[];
void func_ov000_02163254(void *self);
extern VFunc data_ov000_021caec8[];
extern VFunc data_ov000_021cac60[];

void *func_0206ec8c(u32 id);
u8 *func_0206ef10(u32 id);
void func_ov000_02162b40(void *a, s32 b, s32 c, const char *d, s32 e, const char *f, s32 g, s16 h);
void func_ov000_021c95ac(void *a, u16 id);
void func_ov002_021e2754(Ov002Hud *self, u16 id);
extern char data_ov002_021efaeb[];
extern char data_ov002_021efae1[];

void func_ov002_021da39c(void);

static inline bool func_ov002_isState2(void *self) {
    return FIELD(self, 0x4, s32) == 2;
}


BOOL func_ov002_021d6cf0(UiObj *self);

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
extern VFunc data_ov002_021efe5c[];
extern VFunc data_ov002_021efe8c[];

Ov002Mdl021efe3c *Ov002Vt_021efe3c_Ctor(Ov002Mdl021efe3c *self);
Ov002Mdl021efe3c *Ov002Vt_021efe3c_Dtor(Ov002Mdl021efe3c *self);
void func_ov002_021d7620(Ov002Mdl021efe3c *self);
void func_ov002_021d788c(Obj021efe8c *self);
void func_ov002_021d792c(Obj021efe5c *self);
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

u8 *func_0206ef50(u32 id);
Ov002Shape *func_02070dcc(int id);
void NNS_G3dMdlSetMdlAlpha(void *res, int idx, int val);
extern char data_ov002_021efddd[];

u8 *func_0206ede8(u16 id);
BOOL func_ov002_021e38f8(s32 *out, Ov002Shape *shape);
void func_ov002_021d8148(Obj021efe9c *self);

static inline void func_ov002_021d7c04_inline(Obj021efeb8 *self) {
    u8 *info = func_0206ede8(self->unk_48);
    Ov002Shape *v;
    self->unk_4a = info[0] == 0x80 ? 2 : 1;
    v = func_02070dcc(self->unk_4b = info[1]);
    MI_CpuCopy8(v, &self->shape, sizeof(self->shape));
    func_ov002_021e38f8(self->unk_5c, v);
}

void func_ov002_021d83f0(Obj021efe9c *self);
u8 Gfx3DState_NextPolyId(void *a);
void NNS_G3dMdlSetMdlPolygonIDAll(void *mdl, int polygonID);
void func_ov002_021e3b0c(s32 *out, s32 *pos, s32 *origin);

typedef struct Vec2 {
    s32 x;
    s32 y;
} Vec2;

void func_ov002_021eae48(Ov002StageFile *self);
// The board's selection (unk_00, an index into the mode menu) and its top object (func_ov002_021da2fc).
typedef struct Ov002BoardRef {
    u8 unk_00;
    u8 unk_01[0x3];
    Obj021efe7c *top;
} Ov002BoardRef;
extern Ov002BoardRef data_ov002_021f0f90;
void func_ov002_021df1c4(Obj021eff30 *self);

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
extern Ov002Obj021f07d4 *data_ov002_021f0f98; // the model being drawn (func_ov002_021e5b08)
void func_ov002_021ddd80(Obj021efef0 *self);
void func_ov002_021da430(Obj021efe7c *self);
void func_ov002_021dddd0(Obj021efef0 *self);
void func_ov002_021dbdb8(Obj021eff10 *self);
void func_ov002_021db64c(Obj021eff50 *self);
void func_ov002_021d6ec4(Obj021efe4c *self);
void func_ov002_021d6e48(Obj021efe4c *self);
void func_ov002_021d7058(Obj021efe4c *self);
void func_ov002_021d7238(Obj021efe4c *self);
void func_ov002_021d7320(Obj021efe4c *self, s32 t, s32 range);
void func_ov002_021d9444(Obj021efe6c *self);
void func_ov002_021d98ac(Obj021efe6c *self);
void func_ov002_021d9c04(Obj021efe6c *self);
void func_ov002_021d9e38(Obj021efe6c *self, Obj021efeb8 *node);
void func_ov002_021d9ed8(Obj021efe6c *self, Obj021efeb8 *obj, bool del);
void func_ov002_021da054(Obj021efe6c *self);
void func_ov002_021da184(Obj021efe6c *self, Obj021efeb8 *obj);
u8 *func_ov002_021dd9d4(Obj021efe6c *self);
u16 func_ov002_021d9e30(Obj021efeb8 *self);
void func_ov002_021d8b04(Obj021efe9c *self, Vec2 *out);
void func_ov002_021d8b2c(Obj021efe9c *self, Vec2 *out);
Ov002Shape *func_ov002_021d8b40(Obj021efe9c *self);
u8 func_ov002_021d8b48(Obj021efe9c *self);
u8 func_ov002_021d8b74(Obj021efe9c *self);
void func_ov002_021d8b7c(Obj021efe9c *self);
void func_ov002_021d8ba4(Obj021efe9c *self);
void func_ov002_021d8bcc(Obj021efe9c *self);
s32 func_ov002_021dc834(Obj021efe9c *self);
void func_ov002_021d7c54(Obj021efe9c *self, u16 rot);
void func_ov002_021df7b4(Obj021efe9c *self, Vec2 *pos);
void func_ov002_021dbd08(Obj021eff50 *self, VObj *child, s32 state);
Obj021efe6c *func_ov002_021dc270(Obj021eff50 *self);
Obj021eff10 *Ov002Vt_021eff10_Ctor(Obj021eff10 *self);
Obj021efef0 *Ov002Vt_021efef0_Ctor(Obj021efef0 *self);
void func_ov002_021dfc44(Obj021efef0 *self, u16 id);
void func_ov002_021d7b80(Obj021efeb8 *self);
void func_ov002_021d7e54(Obj021efe9c *self);
void func_ov002_021d8e48(Obj021efed4 *self);
void func_ov002_021eae3c(Ov002StageFile *self);

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
UiListItem *func_ov000_02154b58(void *list, u16 id);
void func_ov000_02153c48(UiListItem *item, s32 font, BOOL show, BOOL center, u8 e);

extern VFunc data_ov002_021efeb8[];
extern VFunc data_ov002_021f0674[];
void func_ov002_021e7dac(Ov002Stage *self);
void func_ov002_021e0420(void *self);
void func_ov000_021c524c(void *a, void *b, VecFx32 *pos, s32 d);

extern VFunc data_ov000_021ccbe0[];
void func_ov000_021c3bb0(void *self);
void func_ov002_021d95e0(Obj021efe6c *a);

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
void func_ov002_021d8e90(Obj021efed4 *self);
void func_ov002_021d7ed8(Obj021efe9c *self);

typedef struct Bits021e0420 {
    u32 lo : 16;
    u32 val : 5;
    u32 hi : 11;
} Bits021e0420;

extern VFunc data_ov002_021f0ce8[];
int func_ov002_021e3dac(Vec2 *pos, Ov002Shape *map, Ov002Shape *shape, Vec2 *out);
void func_ov002_021d7d5c(Obj021efe9c *self, Ov002Shape *map);
void func_ov002_021d8c34(Obj021efe9c *self, s32 d, Ov002Shape *map);


typedef struct Bits021e2f04 {
    u32 lo : 12;
    u32 nib : 4;
    u32 hi : 16;
} Bits021e2f04;

void func_ov002_021e0280(Obj021eff30 *self);
void func_ov002_021d7988(Obj021efe5c *self);
void *func_ov000_0214b724(void *p);

extern char data_ov002_021effde[];
extern char data_ov002_021effeb[];
extern VFunc data_ov002_021f0ebc[];
extern VFunc data_ov002_021f001c[];
void func_ov002_021e4fac(NNSG3dRS *rs);

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

static inline void func_ov002_021e4d4c_inline(Ov002Obj *self) {
    Ov002Obj *owner = self->owner;
    int i;
    if (owner != NULL) {
        for (i = 0; i < 8; i++) {
            if (owner->children[i] == self) {
                owner->children[i] = NULL;
                break;
            }
        }
        self->owner = NULL;
    }
    for (i = 0; i < 8; i++) {
        Ov002Obj *child = self->children[i];
        if (child != NULL) {
            child->owner = NULL;
        }
    }
}

void func_ov002_021ec2ac(Ov002Snd021f0cf8 *self);

BOOL func_ov002_021d52e0(UiList *self, UiListItem *ev);
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
void func_ov002_021e5d88(Ov002Obj021f075c *self);
void func_ov002_021e8cc4(Ov002Stage *self);
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

extern char data_ov002_021f00cc[];
extern char data_ov002_021f00d8[];

extern VFunc data_ov002_021f07d4[];
void func_ov002_021e51f8(Ov002Obj021f07d4 *self);
void func_ov002_021d9728(Obj021efe6c *p);

void func_ov002_021e391c(s32 *m, int rot);

int STD_TSNPrintf(void *dst, u32 size, const void *fmt, ...);
extern void *data_ov002_021f0624[];
extern u8 data_ov002_021f064c[];
extern u8 data_ov002_021f0647[];

BOOL func_ov000_0218f110(void *p);
extern char data_ov002_021efdf6[];

void func_ov002_021d9504(Obj021efe6c *self);
void func_ov002_021ebfd0(Ov002Msg021f0ce8 *p);
extern VFunc data_ov002_021efe6c[];

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

void func_ov002_021d36b8(Task021ef91c *self, s32 n);
extern VFunc data_ov002_021eff74[];
void func_ov002_021eacd0(Ov002StageFile *self);
void Gfx3DState_Init(void *p);
void func_ov002_021e7cb4(Ov002Stage *self);

BOOL func_ov002_021e41cc(Vec2 *a, Vec2 *b, Ov002Shape *c, Ov002Shape *d, Vec2 *out);
BOOL func_ov002_021e4578(const Vec2 *pos, const Vec2 *d, Ov002Shape *map, Ov002Shape *shape);
BOOL func_ov002_021e45c4(Obj021efeb8 *self, Obj021efeb8 *list, Ov002Shape *map);
void func_ov002_021e63f0(Ov002Obj021f075c *self);
extern VFunc data_ov002_021f0694[];


Ov002Obj *func_ov002_021e9974(s32 a, s32 b, s16 c, void *d);

void *func_02035fe8(void *a, void *b);
void func_ov002_021ec010(Ov002Msg021f0ce8 *p, const void *src);
extern VFunc data_ov002_021f07ac[];
void *Ov002Vt_021f0ce8_Dtor(Ov002Msg021f0ce8 *p);

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
void func_ov002_021e5d0c(Ov002Obj021f075c *self);

void *Ov002Vt_021f0ce8_Ctor(Ov002Msg021f0ce8 *p);
void func_ov002_021e6a14(Ov002Obj021f07ac *self);
void func_ov002_021ec1e0(Ov002Snd021f0cf8 *self, void *src);

extern VFunc data_ov002_021f06e4[];

void func_ov002_021e6290(Ov002Obj021f075c *self);

void *func_0206ec48(u16 id);
void func_ov002_021e019c(Obj021eff30 *self, u8 a, u8 b);

void func_ov000_0216f844(TimedBuffer021cb920 *p, int a);
extern VFunc data_ov002_021f070c[];

extern const u8 data_ov002_021eef74[];

void func_ov002_021e5140(Ov002Obj021f07d4 *self);
void *func_02035d2c(void *a);

#ifdef __cplusplus
}
#endif

#endif

