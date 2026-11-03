#ifndef OV002_OV002_H
#define OV002_OV002_H

#include "types.h"
#include "ov002/Session.h"
#include "ov002/BoardRef.h"
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
extern EffectFile *ResList_FindType4(void *arc, const char *name);
extern EffectFile *ResList_FindType6(void *arc, const char *name);
extern BOOL G3dRes_SetupVram(const char *name, void *data);
extern void Vram_FreeRes(void *data);

#ifdef __cplusplus
typedef int (*VFunc)(...);
#else
typedef int (*VFunc)();
#endif


/* Switch new allocations to the alternate heap (gSysState->heapHi) and back. */
#define HEAP_PUSH(saved)                                  \
    do {                                                  \
        (saved) = gSysState->cur;                     \
        gSysState->cur = gSysState->heapHi;       \
    } while (0)
#define HEAP_POP(saved) (gSysState->cur = (saved))

void Heap_FreeArray(void *p);

/* ---- */
extern char data_0214b105[];


typedef struct {
    s32 flag0 : 1;
    u32 flag1 : 1;
    u32 rest : 30;
} BitWord;


typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 2;
} BitByte;

extern BitWord *gTaskHost;

u16 DataRes_ReadEntry(void *a, int b, int c, int d);
void TaskHost_Create(int a, int b);
void TaskHost_Destroy(void);

static inline bool func_ov002_inline_flag1(void) {
    return gTaskHost->flag1;
}

extern VFunc Ov002TaskVt_021ef530_vtbl[];
extern char data_ov002_021ef3e4[];
extern char data_ov002_021ef3ec[];
extern char data_ov002_021ef3f8[];
void ResMgr_ReleaseArchive(void *a, void *b, u16 c);
void ResMgr_LoadArchive(void *a, void *b, u16 c, u8 d);
int ResMgr_IsArchiveLoaded(void *a, void *b, u16 c);
Task *TaskHost_RequestSwitch(void *a, int b, int c);
void Obj0215bb14_SetText(void *a, void *b);


static inline void TaskBase_ctor(Task *self) {
    *(VFunc **)self = (VFunc *)Task_vtbl;
    self->vfunc_58();
}

static inline Task021ef530 *Task_021cd06c_ctor(Task021ef530 *self) {
    TaskBase_ctor(self);
    *(VFunc **)self = Ov002TaskVt_021ef530_vtbl;
    self->vfunc_58();
    return self;
}


#define FIELD(p, off, T) (*(T *)((u8 *)(p) + (off)))

/* NitroSDK sin/cos table: s16 sin,cos pairs */
#define FX_SINCOS_TABLE FX_SinCosTable_
/* Element i of the table, folded into a single symbol offset. */
#define FX_SINCOS(i) (FX_SinCosTable_[(i)])

extern void *gFinishingTask;
extern s32 gLastTaskId;
int Model_IsReady(void *a, int b);
void Task_Draw(void *self);
extern char data_ov002_021ef3f9[];

static inline bool Task_getFlag4(Task *self) {
    return self->unk_04_4;
}

static inline bool func_ov002_isCurrent021ccd40(void *p) {
    return gFinishingTask == p;
}

void *ResMgr_GetArchiveList(void *a, void *b, u16 c);
void TaskList_Insert(void *self);
extern u8 gTaskSwitchPending;
void GfxSys_StartFadeIn(s32 a, int b, int c);
void func_ov002_021ce7b8(Task021ef4b0 *self);

static inline void func_ov002_setCurrent021ccd40(void *p) {
    if (gFinishingTask != NULL) {
        gLastTaskId = FIELD(gFinishingTask, 0x14, s32);
    } else {
        gLastTaskId = 0;
    }
    gFinishingTask = p;
}

static inline bool func_ov002_isMode4(void) {
    BOOL r; if (gFadeState[3] == 4) { r = TRUE; } else { r = gFadeState[0] == 4; } return r;
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

extern VFunc Ov002TaskVt_021ef4b0_vtbl[];
extern VFunc Ov002TaskVt_021ef430_vtbl[];
extern VFunc Ov002Vt_021ef410_vtbl[];
extern VFunc Ov002TaskVt_021ef79c_vtbl[];
void Buffer0216f144_Free(void *self);

static inline void TaskBase_dtor(Task *self) {
    *(VFunc **)self = (VFunc *)Task_vtbl;
    self->vfunc_5c();
}

}
// Frees the Model at unk_3c (Task021ef430, Task021ef530).
template <class T> static inline void Task_deleteModel(T *self) {
    void *p = self->unk_3c;
    if (p != NULL) {
        if (p != NULL) {
            TexObj_Release((Model *)p);
            PlttRes_Release(&((Model *)p)->pltt);
            Heap_Free(p);
        }
        self->unk_3c = NULL;
    }
}
extern "C" {

static inline bool func_ov002_isMode4b(void) {
    BOOL r;
    if (gFadeState[3] == 4) {
        r = TRUE;
    } else {
        r = gFadeState[1] == 4;
    }
    return r;
}

typedef void (*Callback)(void *);

extern VFunc Ov002TaskVt_021efa1c_vtbl[];
extern VFunc Ov002TaskVt_021ef89c_vtbl[];

s16 *func_0206ee90(u32 id);
extern s32 data_ov002_021f0f84[];
extern VFunc Ov002TaskVt_021ef71c_vtbl[];
void Ov002Stage_Delete_021e916c(void);
void func_ov002_021d0b98(Task021ef89c *self);

typedef struct Info0206ee90 {
    u16 unk_00 : 15;
    u16 flag : 1;
} Info0206ee90;

u32 DataRes_GetCount(void *a, int idx);
void *DataRes_GetTable(void *a, int idx);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, u16 d, u16 e);

void func_ov002_021e90dc(void);
void func_ov002_021e8f04(s32 id);
bool func_ov002_021e90ac(void);
extern VFunc Ov002TaskVt_021ef69c_vtbl[];
void Obj021c64b4_SetText(TextList *self, void *text);
void TextList_Raise(TextList *self);
void func_ov002_021d1f70(Task021ef69c *self);

void GfxSys_StopFade(int a);
void Movie_Load(void *a, s32 b, int c, int d);
void Movie_RequestStop(void *a);
void TextList_Lower(TextList *self);

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
void Ov002LevelTable_Ctor(Ov002LevelTable *self);
void Ov002StrTable_Ctor(Ov002StrTable *self);
extern VFunc Ov002TaskVt_021ef91c_vtbl[];

void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
Ov002LevelTable *Ov002Vt_021f00fc_Dtor(Ov002LevelTable *self);

extern VFunc Ov002TaskVt_021ef99c_vtbl[];

void Ov002StrTable_Clear(Ov002StrTable *self);
void func_ov002_021d37f8(Task021ef91c *self);
extern VFunc Ov002TaskVt_021ef81c_vtbl[];
void func_ov000_021763c8(void);
u32 func_ov000_02176538(void);
u32 func_ov000_02180838(void *a);
void Task021ef81c_FreeWindows(Task021ef81c *self);

Ov002StrTable *Ov002Vt_021f00ec_Dtor(Ov002StrTable *self);
void Task021ef99c_FreeWindows(Task021ef99c *self);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
extern VFunc Ov002Vt_021ef684_vtbl[];
void ListRow_Unlink(void *self);

extern VFunc Ov002TaskVt_021efba4_vtbl[];
extern VFunc Ov002Vt_021efb14_vtbl[];
extern char data_ov002_021efad1[];
void Ov002Hud_Release(Ov002Hud *self);

void Ov002Hud_Init(Ov002Hud *self);
void Ov002Hud_Load(Ov002Hud *self);
void Ov002Hud_SetRow(Ov002Hud *self, u8 row, int force);
void Ov002Hud_Update(Ov002Hud *self);
void func_ov002_021e2528(Ov002Hud *self);
extern VFunc Ov002TaskVt_021efb24_vtbl[];
void Obj021efe7c_Create(void);
Obj021efe7c *Obj021efe7c_Get(void);
void Obj021efe7c_Setup(Obj021efe7c *self);
BOOL Obj021efe7c_IsLoaded(Obj021efe7c *self);
void Obj021efe7c_Start(Obj021efe7c *self);
void Obj021efe7c_Draw(Obj021efe7c *self);

static inline bool Task_isFlag1Clear(Task *self) {
    return !self->unk_04_1;
}

void Obj021efe7c_SetPhase(Obj021efe7c *a, int b);
BOOL Obj021efe7c_Update(Obj021efe7c *a);
extern VFunc Ov002TaskVt_021efc24_vtbl[];
void func_ov002_021d5f60(Task021efc24 *self);
void *Task_FindById(int id);
extern VFunc Ov002Vt_021efb04_vtbl[];
void MsgBox_Release(void *self);
extern VFunc UiList_vtbl[];
extern VFunc UiObj_vtbl[];

void *func_0206ec8c(u32 id);
Param0206ef10 *Param_GetRecord(u32 id);
void ModelViewer_SetModel(void *a, const char *mdlArc, const char *mdlName, const char *anmArc, const char *anmName, const char *anim, s32 frame, s16 speed);
void Obj021c95ac_Init_021c95ac(void *a, u16 id);
void Ov002Hud_SetInfo(Ov002Hud *self, u16 id);
extern char data_ov002_021efaeb[];
extern char data_ov002_021efae1[];

void Obj021efe7c_Delete(void);

static inline bool func_ov002_isState2(void *self) {
    return FIELD(self, 0x4, s32) == 2;
}


BOOL Ov002RowList_IsLoaded(UiObj *self);

void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);

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

extern VFunc Ov002Vt_021efe3c_vtbl[];
extern VFunc Ov002Vt_021efe5c_vtbl[];
extern VFunc Ov002Vt_021efe8c_vtbl[];

Ov002Mdl021efe3c *Ov002Vt_021efe3c_Ctor(Ov002Mdl021efe3c *self);
Ov002Mdl021efe3c *Ov002Vt_021efe3c_Dtor(Ov002Mdl021efe3c *self);
void Ov002Mdl021efe3c_Load(Ov002Mdl021efe3c *self);
void Obj021efe8c_SyncAnmFrame(Obj021efe8c *self);
void Obj021efe5c_SyncAnmFrame(Obj021efe5c *self);
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

u8 *func_0206ef50(u32 id);
Ov002Shape *ParamKind_GetShape(int id);
void NNS_G3dMdlSetMdlAlpha(void *res, int idx, int val);
extern char data_ov002_021efddd[];

u8 *Param_GetEntry(u16 id);
BOOL func_ov002_021e38f8(s32 *out, Ov002Shape *shape);
void func_ov002_021d8148(Obj021efe9c *self);

static inline void func_ov002_021d7c04_inline(Obj021efeb8 *self) {
    u8 *info = Param_GetEntry(self->unk_48);
    Ov002Shape *v;
    self->unk_4a = info[0] == 0x80 ? 2 : 1;
    v = ParamKind_GetShape(self->unk_4b = info[1]);
    MI_CpuCopy8(v, &self->shape, sizeof(self->shape));
    func_ov002_021e38f8(self->unk_5c, v);
}

void func_ov002_021d83f0(Obj021efe9c *self);
u8 Gfx3DState_NextPolyId(void *a);
void NNS_G3dMdlSetMdlPolygonIDAll(void *mdl, int polygonID);
void Ov002_CellToPos(s32 *out, s32 *pos, s32 *origin);

typedef struct Vec2 {
    s32 x;
    s32 y;
} Vec2;

void Ov002StageFile_Free(Ov002StageFile *self);
void Obj021eff30_Release(Obj021eff30 *self);

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

extern VFunc Ov002Vt_021efef0_vtbl[];
extern VFunc Ov002Vt_021efe7c_vtbl[];
extern VFunc Ov002Vt_021eff30_vtbl[];
extern VFunc Ov002Vt_021eff10_vtbl[];
extern VFunc Ov002Vt_021eff50_vtbl[];
extern VFunc Ov002Vt_021efe4c_vtbl[];
extern VFunc Ov002Vt_021f0684_vtbl[];
extern VFunc Ov002Vt_021f00ec_vtbl[];
extern Ov002Obj021f07d4 *data_ov002_021f0f98; // the model being drawn (Ov002Obj021f07d4_Draw)
void Obj021efef0_Init(Obj021efef0 *self);
void Obj021efe7c_Release(Obj021efe7c *self);
void Obj021efef0_Release(Obj021efef0 *self);
void Obj021eff10_Release(Obj021eff10 *self);
void Obj021eff50_Release(Obj021eff50 *self);
void Obj021efe4c_Release(Obj021efe4c *self);
void Obj021efe4c_Init(Obj021efe4c *self);
void func_ov002_021d7058(Obj021efe4c *self);
void func_ov002_021d7238(Obj021efe4c *self);
void func_ov002_021d7320(Obj021efe4c *self, s32 t, s32 range);
void Obj021efe6c_Init(Obj021efe6c *self);
void func_ov002_021d98ac(Obj021efe6c *self);
void func_ov002_021d9c04(Obj021efe6c *self);
void Obj021efe6c_AppendPiece(Obj021efe6c *self, Obj021efeb8 *node);
void Obj021efe6c_RemovePiece(Obj021efe6c *self, Obj021efeb8 *obj, bool del);
void func_ov002_021da054(Obj021efe6c *self);
void func_ov002_021da184(Obj021efe6c *self, Obj021efeb8 *obj);
u8 *func_ov002_021dd9d4(Obj021efe6c *self);
u16 func_ov002_021d9e30(Obj021efeb8 *self);
void Obj021efe9c_GetCell(Obj021efe9c *self, Vec2 *out);
void Obj021efe9c_GetOrigin(Obj021efe9c *self, Vec2 *out);
Ov002Shape *Obj021efe9c_GetShape(Obj021efe9c *self);
u8 Obj021efe9c_GetRot(Obj021efe9c *self);
u8 func_ov002_021d8b74(Obj021efe9c *self);
void func_ov002_021d8b7c(Obj021efe9c *self);
void func_ov002_021d8ba4(Obj021efe9c *self);
void func_ov002_021d8bcc(Obj021efe9c *self);
s32 func_ov002_021dc834(Obj021efe9c *self);
void Obj021efe9c_SetRot(Obj021efe9c *self, u16 rot);
void Obj021efe9c_SetCell(Obj021efe9c *self, Vec2 *pos);
void func_ov002_021dbd08(Obj021eff50 *self, VObj *child, s32 state);
Obj021efe6c *Obj021eff50_GetBoard(Obj021eff50 *self);
Obj021eff10 *Ov002Vt_021eff10_Ctor(Obj021eff10 *self);
Obj021efef0 *Ov002Vt_021efef0_Ctor(Obj021efef0 *self);
void func_ov002_021dfc44(Obj021efef0 *self, u16 id);
void Obj021efeb8_Init(Obj021efeb8 *self);
void Obj021efe9c_Init(Obj021efe9c *self);
void Obj021efed4_Init(Obj021efed4 *self);
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

extern VFunc Ov002Vt_021f00fc_vtbl[];
extern VFunc Ov002Vt_021f0cf8_vtbl[];
extern VFunc Ov002Vt_021f0ef4_vtbl[];
UiListItem *UiList_GetItemById(void *list, u16 id);
void Obj02153c48_CreateText(UiListItem *item, s32 font, BOOL show, BOOL center, u8 e);

extern VFunc Ov002Vt_021efeb8_vtbl[];
extern VFunc Ov002Vt_021f0674_vtbl[];
void Ov002Stage_Release(Ov002Stage *self);
void Ov002_ScaleAlphaMatCb(NNSG3dRS *rs);
void func_ov000_021c524c(void *a, void *b, VecFx32 *pos, s32 d);

extern VFunc Ov000Vt_021ccbe0_vtbl[];
void LoBase021ccb54_021ccbe0_Release(void *self);
void func_ov002_021d95e0(Obj021efe6c *a);

static inline void *func_ov002_021e0b08_inline(void *self) {
    void *prev;
    void *next;
    *(VFunc **)self = Ov002Vt_021efeb8_vtbl;
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

extern VFunc Ov002Vt_021f0e14_vtbl[];
extern VFunc Ov002Vt_021f0e84_vtbl[];
extern VFunc Ov002Vt_021f0e4c_vtbl[];
extern VFunc Ov002Vt_021f0f2c_vtbl[];
extern VFunc Ov002Vt_021efed4_vtbl[];
extern VFunc Ov002Vt_021efe9c_vtbl[];
void Obj021efed4_Release(Obj021efed4 *self);
void Obj021efe9c_Release(Obj021efe9c *self);

typedef struct Bits021e0420 {
    u32 lo : 16;
    u32 val : 5;
    u32 hi : 11;
} Bits021e0420;

extern VFunc Ov002Vt_021f0ce8_vtbl[];
int func_ov002_021e3dac(Vec2 *pos, Ov002Shape *map, Ov002Shape *shape, Vec2 *out);
void Obj021efe9c_ClampToBoard(Obj021efe9c *self, Ov002Shape *map);
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
extern VFunc Ov002Vt_021f0ebc_vtbl[];
extern VFunc Ov002Vt_021f001c_vtbl[];
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

extern VFunc Ov002Vt_021f0734_vtbl[];

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

void Ov002Snd021f0cf8_Next(Ov002Snd021f0cf8 *self);

BOOL func_ov002_021d52e0(UiList *self, UiListItem *ev);
typedef BOOL (*EvCallback)(void *, void *);
void func_ov000_02152294(void *self, u16 a, int b, EvCallback cb);
u8 LangData_GetLang(void);
void func_ov002_021d4540(void *dst, u32 size, const void *a, const void *b, int mode);
// The resource-name table data_ov002_021ef5ac (defined in ov002_021ef150.cpp). Not const:
// Task021ef99c_Start reloads it after every call in its loop.
typedef struct Ov002ResNames {
    const char *hdExt;
    const char *bmExt;
    const char *pic;
    const char *param;
    s32 scale;
    const char *cepct;
} Ov002ResNames;
extern u8 data_ov002_021ef650[];

void LoBase021ccb54_021ccbe0_Setup(void *self);
void func_ov000_021c4ab8(void *self);
extern VecFx16 data_ov002_021ef038[]; // the list frame outline (Ov002RowList_Setup)

extern VFunc Ov002Vt_021f075c_vtbl[];
void Ov002Obj021f075c_FreeAnims(Ov002Obj021f075c *self);
void func_ov002_021e8cc4(Ov002Stage *self);
void *Twl0214b6d8_Init(void *p);
void Loader_Start(void *p, const void *a);
void func_ov000_0214b810(void *p);
BOOL Loader_IsDone(void *p);
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

extern VFunc Ov002Vt_021f07d4_vtbl[];
void Ov002Obj021f07d4_Release(Ov002Obj021f07d4 *self);
void Obj021efe6c_Update(Obj021efe6c *p);

void Ov002_QuarterRotMtx(s32 *m, int rot);

int STD_TSNPrintf(void *dst, u32 size, const void *fmt, ...);
extern void *data_ov002_021f0624[];
extern u8 data_ov002_021f064c[];
extern u8 data_ov002_021f0647[];

BOOL ResSet_UpdateLoad(void *p);
extern char data_ov002_021efdf6[];

void Obj021efe6c_FreePieces(Obj021efe6c *self);
void Ov002Msg021f0ce8_Init(Ov002Msg021f0ce8 *p);
extern VFunc Ov002Vt_021efe6c_vtbl[];

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
extern VFunc Ov002Vt_021eff74_vtbl[];
void Ov002StageFile_Init(Ov002StageFile *self);
void Gfx3DState_Init(void *p);
void Ov002Stage_Init(Ov002Stage *self);

BOOL func_ov002_021e41cc(Vec2 *a, Vec2 *b, Ov002Shape *c, Ov002Shape *d, Vec2 *out);
BOOL func_ov002_021e4578(const Vec2 *pos, const Vec2 *d, Ov002Shape *map, Ov002Shape *shape);
BOOL func_ov002_021e45c4(Obj021efeb8 *self, Obj021efeb8 *list, Ov002Shape *map);
void Ov002Obj021f075c_UpdateAnims(Ov002Obj021f075c *self);
extern VFunc Ov002Vt_021f0694_vtbl[];


Ov002Obj *Ov002Obj021f06e4_New(s32 a, s32 b, s16 c, void *d);

void *func_02035fe8(void *a, void *b);
void Ov002Msg021f0ce8_Load(Ov002Msg021f0ce8 *p, const void *src);
extern VFunc Ov002Vt_021f07ac_vtbl[];
void *Ov002Vt_021f0ce8_Dtor(Ov002Msg021f0ce8 *p);

extern u8 data_ov002_021ef655[];
extern u8 data_ov002_021ef659[];
extern u8 data_ov002_021ef65d[];
extern u8 data_ov002_021ef661[];
extern u8 data_ov002_021ef651[];
extern u8 data_ov002_021ef665[];
extern VFunc Ov002Vt_021f000c_vtbl[];

void *func_ov000_0214b8ec(void *p);
void func_ov000_0214b1a0(VecFx32 *a, VecFx32 *b, s32 c, void *d);
extern VecFx32 data_ov002_021ef124;

extern u8 data_ov002_021f064d[];
extern u8 data_ov002_021f0654[];
extern u8 data_ov002_021f065e[];
extern u8 data_ov002_021f0665[];
extern VFunc Ov002Vt_021f002c_vtbl[];
void func_ov000_021c4738(void *self, s32 index);
extern u16 data_ov002_021ef058[][5];
typedef int (*SortCmp)(void *, void *);

void ModelViewer_Draw(void *p);
void MsgBox_Render(void *p);

void func_0206e3a0(void *a, void *b);
void Gfx3DState_Apply(void *p);
void Ov002Obj021f075c_Init(Ov002Obj021f075c *self);

void *Ov002Vt_021f0ce8_Ctor(Ov002Msg021f0ce8 *p);
void Ov002Obj021f07ac_Init(Ov002Obj021f07ac *self);
void Ov002Snd021f0cf8_Load(Ov002Snd021f0cf8 *self, void *src);

extern VFunc Ov002Vt_021f06e4_vtbl[];

void func_ov002_021e6290(Ov002Obj021f075c *self);

void *Param_Get(u16 id);
void func_ov002_021e019c(Obj021eff30 *self, u8 a, u8 b);

void func_ov000_0216f844(TimedBuffer021cb920 *p, int a);
extern VFunc Ov002Vt_021f070c_vtbl[];

extern const u8 data_ov002_021eef74[];

void Ov002Obj021f07d4_Init(Ov002Obj021f07d4 *self);
void *func_02035d2c(void *a);

#ifdef __cplusplus
}
#endif

#endif

