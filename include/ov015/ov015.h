#ifndef OV015_H
#define OV015_H

#include "types.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Sys/Field.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Sys/Pad.h"
#include "Main/Res/StageFlags.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/G3dGlbSyms.h"
#include "ov000/TaskList.h"
#include "ov000/UiObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorParts.h"
#include "ov000/Model0218fe1c.h"
#include "ov002/StageObj.h"

typedef volatile u16 vu16;
typedef volatile u32 vu32;

// The ship model config at 0x02212db0 (defined in ov015_0221272c.cpp).
struct Ov015ShipCfg {
    const char *name;
    s32 scale;
};

// The overlay's vector: a VecFx32 with a user-declared (empty) default constructor and a member-wise
// copy constructor. Both are load-bearing: copy-initialised locals (func_ov015_021fd0f4,
// Ov015Scene2a08_Draw, func_ov015_021ffb90, ...) are built field by field, where a plain VecFx32 (or a
// class with only the implicit copy) is copied as one 12-byte block. Being derived from VecFx32, it
// passes to the SDK's VecFx32 * parameters without a cast. (Ov015Vec, which spelled the copy as a
// mem-initialiser list, gives the same code and is merged into it.)
struct Ov015Vec : public VecFx32 {
    Ov015Vec() {}
    Ov015Vec(const Ov015Vec &o) {
        x = o.x;
        y = o.y;
        z = o.z;
    }
};

// The 4-byte record of func_0206ee20 (Main/Lang/ParamTbl.cpp) as ov015 reads it: the shop and
// reward code multiplies price by the count and splits a budget by it (func_ov015_022113e8).
typedef struct Ov015ParamPrice {
    u16 unk_00;
    u16 price;
} Ov015ParamPrice;

#define FLD(type, p, off) (*(type *)((u8 *)(p) + (off)))
#define SET_VT(p, vt) (*(void **)(p) = (void *)(vt))
#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile u32 *)(a))

extern "C" {



struct Ov015Fish;

// List node (0x10, vtable Ov015Node_vtbl); the fish list is the only list.
struct Ov015Node : public VObj {
    Ov015Fish *fish;
    Ov015Node *prev;
    Ov015Node *next;
};

struct Ov015List : public VObj {
    Ov015Node *head;
    Ov015Node *tail;
    s32 count;
};


struct Ov015Fish;
struct Ov015Ship;
struct Ov015CamPair;
struct Ov015Info38;
struct Ov015Obj290;
struct Ov015Obj292c;

// Fishing phase state (0x2c bytes, vtable Ov015Obj30_vtbl, Ov015Obj30_Init).
struct Ov015Obj30 : public VObj {
    s32 step;
    s32 timer;
    u8 unk_0c;
    Ov015Obj292c *unk_10;
    Ov015Obj290 *unk_14;
    Ov015Fish *fish;
    Ov015Ship *ship;
    Ov015CamPair *cam;
    Ov015List *fishList;
    Ov015Info38 *info;
};

static inline void Ov015Obj30_Clear(Ov015Obj30 *p) {
    p->step = 0;
    p->timer = 0;
    p->unk_0c = 0;
    p->unk_10 = NULL;
    p->unk_14 = NULL;
    p->fish = 0;
    p->ship = 0;
    p->cam = 0;
    p->fishList = 0;
    p->info = 0;
}


struct Ov015V3 {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov015Mtx33 {
    s32 m[3][3];
};

// Camera (0xbc bytes, Camera_Ctor / Camera_Dtor).
struct Ov015Bits8a0 {
    u8 b0 : 2;
    u8 shakeX : 1;
    u8 shakeY : 1;
    u8 shakeZ : 1;
    u8 rest : 3;
};

struct Ov015Cam : public VObj {
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
    u16 mode;
    u8 unk_42[0x99 - 0x42];
    u8 shakeTime;
    u8 shakeLen;
    u8 shakeCur;
    Ov015Bits8a0 flags;
    u8 unk_9d[0xbc - 0x9d];
};

// The camera object (0x1a0 bytes, vtable Ov015Vt_0221291c_vtbl): the top and bottom screen
// cameras plus the follow state.
struct Ov015CamPair : public VObj {
    Ov015Cam cam0;
    Ov015Cam cam1;
    s32 mode; // mode
    Ov015Vec target; // target
    Ov015Vec unk_18c;
    s32 unk_198;
    s32 timer; // timer
};

// ov000 model resource (0x138 bytes, ResSet_Init / ResSet_ReleaseAll).
struct Ov015Anim {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03_0 : 1;
    u8 ownMdl : 1;
    u8 ownAnm : 1;
    u8 unk_03_3 : 1;
    u8 ownEv : 1;
    u8 unk_03_5 : 3;
    u8 unk_04[0xc];
    char mdlDir[0x20]; // model directory
    char mdlName[0x1c]; // model name
    char anmDir[0x20]; // animation directory
    char anmName[0x54]; // animation name
    u8 *evHandle;
    char evDir[0x20];
    char evName[0x20];
    u8 unk_104[0x34];
};

// ov000 Shadow (0x1c bytes, Shadow_CtorBase / Shadow_Ctor / Ov000Vt_021cc438_Dtor).
struct Ov015Shadow {
    const void *vtbl;
    void *res;
    void *mdl;
    s32 unk_0c;
    s32 unk_10;
    s32 scale;
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

struct Ov015Gauge : public VObj {
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


struct Ov015Fade : public VObj {
    u32 posZ;
    u8 alphaFrom;
    u8 alphaTo;
    s32 duration;
    u16 color;
    s32 time;
    u8 alpha;
};

struct Ov015Main : public VObj {
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    VObj *child;
};

// gOv015Globals: the running main sequence (Ov015Main_Create) and the screen fade it
// creates (Ov015_GetFade returns it).
struct Ov015Globals {
    Ov015Main *mainSeq;
    Ov015Fade *fade;
};

// Base of the top-level ov015 sequences (vtable Ov015Child_vtbl, dtor Ov015Child_Dtor):
// Ov015Main steps state through vtable slots 0x08..0x18; slot 0x18 returns the next sequence
// (1: Ov015SceneSeq, 2: Ov015Game, 3: quit).
struct Ov015Child : public VObj {
    s32 state;
    s32 unk_08;
};

// Menu scene sequence (0x14 bytes, vtable Ov015SceneSeq_vtbl, init func_ov015_02206aa0): runs the
// ov000 scene tasks and picks the next sequence from the last one.
struct Ov015SceneSeq : public Ov015Child {
    Task *scene; // the current scene task (gFinishingTask)
    s32 next;    // 4: game, 5: quit
};
SIZE_ASSERT(Ov015SceneSeq, 0x14);

void Ov015Child_DtorBase(Ov015Child *self);

// ov000 task helpers: TaskList_Insert inserts a task into the list by priority (then calls its
// slot 0x20); Task_Draw resets the draw scale and updates fadeSin.
void TaskList_Insert(Task *task);
void Task_Draw(Task *self);

// ov000 task host (gTaskHost) and the scene task globals: TaskHost_RequestSwitch switches the
// host to task kind `kind` (creating it with param c) and returns that task; gFinishingTask is
// the current scene task and gLastTaskId the id of the previous one.
extern TaskHost *gTaskHost;
extern Task *gFinishingTask;
extern u32 gLastTaskId;
Task *TaskHost_RequestSwitch(TaskHost *cur, s32 kind, s32 c);

// The item of a list with the given id (ov000 List_02154a68.cpp).
UiListItem *UiList_GetItemById(UiList *self, u16 id);
void func_ov015_02206aa0(Ov015SceneSeq *self);

struct Ov015ItemEnt {
    u16 id;
    s32 count;
};

// Data shared by the ov015 sequences (0x30 bytes, vtable Ov015Vt_02213200_vtbl, built by
// Ov015Shared_Create into gOv015Shared).
struct Ov015Shared : public VObj {
    s32 unk_04; // sequence kind (Ov015Main::unk_04)
    u16 unk_08; // item id (price from func_0206ef88)
    u16 unk_0a; // id of the func_0206f040 table that func_ov015_02211160 picks from
    u16 catchId; // fish caught (func_ov015_02211334)
    Ov015ItemEnt items[3]; // reward items for catchId
    s32 total; // value of items
    s32 unk_2c;
};
SIZE_ASSERT(Ov015Shared, 0x30);
extern Ov015Shared *gOv015Shared;

// Node callbacks (NNS_G3dRenderObjSetInitFunc installs the one that sets the NODEDESC callback).
void Ov015Ship_CaptureNodeMtx(NNSG3dRS *rs);
void Ov015Ship_SetCaptureCb(NNSG3dRS *rs);
void func_ov015_02208f7c(NNSG3dRS *rs);
void func_ov015_022090fc(NNSG3dRS *rs);
void func_ov015_02211954(NNSG3dRS *rs);
void func_ov015_022119d0(NNSG3dRS *rs);

void func_ov015_02211334(Ov015Shared *self, u16 id);
void func_ov015_022113e8(Ov015Shared *self, Ov015ItemEnt *list, s32 n, u16 a, s32 budget);
u32 func_ov015_02211160(Ov015Shared *self, u16 *out, u32 n);

struct Ov015Flags18 {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
};

u64 _u32_div_f(u32 a, u32 b);

}

extern "C" {

static inline void Ov015TaskBase_Ctor(Task *p) {
    SET_VT(p, Task_vtbl);
    p->vfunc_58();
}
static inline void Ov015TaskBase_Dtor(Task *p) {
    SET_VT(p, Task_vtbl);
    p->vfunc_5c();
}
}

#define HEAP_PUSH(saved)                      \
    do {                                      \
        (saved) = gSysState->cur;          \
        gSysState->cur = gSysState->heapHi; \
    } while (0)
#define HEAP_POP(saved) (gSysState->cur = (saved))

#define DELETE_V(field)                 \
    do {                                \
        VObj *o_ = (VObj *)(field); \
        if (o_ != NULL) {               \
            if (o_ != NULL) {           \
                o_->vfunc_04();            \
            }                           \
            (field) = NULL;             \
        }                               \
    } while (0)

extern "C" {
struct Ov015Slot524 {
    const char *anim; // animation name for mdl0 (NULL: unused slot)
    s32 endTime;      // used while the stage time is at most this
    u8 c;             // set: Model0218fe1c_SetLoop, clear: Model0218fe1c_ClearLoop
    s16 speed;
};

// Animated stage model (0x584, vtable Ov015StageMdl_vtbl; ctor func_ov015_0220dde8, base vtable
// Ov015Vt_02212f64_vtbl): two resource sets and models on an ov002 stage object. The model pose
// (unk_4d0/unk_4dc/unk_500) is copied from the object at unk_520 each frame; slots pick the
// animation by time (Ov015StageMdl_QueueAnim adds one).
struct Ov015StageMdl : public Ov002Obj {
    ActorRes res0;
    Model0218fe1c mdl0;
    ActorRes res1;
    u16 unk_3a4; // animation frame of mdl1 (0: not animated)
    Model0218fe1c mdl1;
    s16 unk_490; // animation speed of both models
    s32 slot;    // current slot (-1: none)
    u16 unk_498; // id passed to Tbl_FindEntry_0206fef8
    MtxFx33 unk_49c; // mdl0's render user data
    VecFx32 unk_4c0;
    s32 unk_4cc;
    VecFx32 unk_4d0;
    MtxFx33 unk_4dc;
    VecFx32 unk_500;
    s32 unk_50c;
    char *unk_510;
    char *unk_514;
    Ov002Cam021f0854 *unk_518; // the stage's kind 7 camera with unk_4c 2 (screen 1)
    Ov002Cam021f0854 *unk_51c; // with unk_4c 3 (screen 2)
    Ov002Obj021f075c *unk_520; // the kind 3 animation object it follows
    Ov015Slot524 slots[8];
};
SIZE_ASSERT(Ov015StageMdl, 0x584);

void *func_ov015_0220dde8(Ov015StageMdl *self);
void Ov015StageMdl_QueueAnim(Ov015StageMdl *self, const char *anim, s32 endTime, u8 c, s16 speed);


static inline void Ov015_DeleteFound(EffectMgr *mgr, u32 key) {
    EffectObj *o = Effect_Find_020657b0(mgr, key);
    void *saved;
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
}

struct Ov015AnimFlags {
    u16 visible : 1;
    u16 b1 : 1;
    u16 invV : 1;
    u16 flipX : 1;
    u16 boxTest : 1;
    u16 clearInit : 1;
    u16 b6 : 1;
    u16 restoreMat : 1;
    u16 flushVP : 1;
    u16 rest : 7;
};

void SndQueue_Push_0204aab0(SndQueue *queue, u16 value); // defined in Main/Snd/SndQueue.cpp
static inline void Ov015_BgmFade(void) {
    SndQueue *p = gSndQueue.queue;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != 0x25) {
            u16 v;
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    SndQueue_Push_0204aab0(p, p->unk_06);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk_02 = v;
            p->unk_06 = 0x25;
            p->unk_08 = 10;
        }
    }
}
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
// Node matrix (rotation rows and translation) and the node id it is captured for (Ov015Ship_CaptureNodeMtx).
struct Ov015ShipMtx {
    Ov015Vec m[4];
    u8 id;
    u8 unk_31[0x3];
};
OV015_SIZE(Ov015ShipMtx, 0x34);
// Fish data block (0x2c bytes, vtable Ov015FishInfo_vtbl).
struct Ov015FishInfo : public VObj {
    u16 id;
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
// ov000 model instance (0xe8 bytes, Model0218fe1c_Init).
struct Ov015Model {
    u8 unk_00[0x24];
    Ov015RenderObj renderObj;
    Ov015Vec trans;
    Ov015Vec rot[3];
    VecFx32 scale;
    u8 unk_b4[0x2];
    s16 color;
    s16 color2;
    s16 blend;
    s16 blendMax;
    u8 unk_be[0x4];
    Ov015AnimFlags flags;
    s16 unk_c4;
    u8 unk_c6[0xa];
    u8 *evTable;
    u8 *evData;
    u8 unk_d8[0x10];
};
OV015_SIZE(Ov015Model, 0xe8);
// A model resource and its model.
struct Ov015MdlPair {
    Ov015Anim res;
    Ov015Model mdl;
};
// Three models (0x664, vtable Ov015Vt_0221294c_vtbl; built by Ov015Game_Create, Ov015Game::unk_20).
struct Ov015MdlSet : public VObj {
    Ov015MdlPair p[3];
};
OV015_SIZE(Ov015MdlSet, 0x664);
// Main object (0x48 bytes, HitSphere_Init / HitSphere_Unlink_0203f2b8).
struct Ov015Obj48 {
    Ov015Vec pos;
    Ov015Vec prev;
    u8 push[0xc];
    u8 active;
    u8 unk_25[0x3];
    s32 group;
    s32 mask;
    u8 unk_30[0x8];
    s32 radius;
    u8 unk_3c[0x8];
    u32 unk_44;
};
OV015_SIZE(Ov015Obj48, 0x48);
// Fish (0x5b0 bytes, vtable Ov015Fish_vtbl, ctor Ov015Fish_Ctor).
struct Ov015Fish : public VObj {
    u16 id;
    u8 unk_06[0x2];
    s32 unk_08;
    Ov015Vec rot2[3];
    Ov015Vec pos2;
    s32 unk_3c;
    Ov015Vec pos;
    Ov015Vec rot[3];
    VecFx32 scale;
    s32 scaleMul;
    s32 radius;
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 shadowAlpha;
    u8 unk_91[0x3];
    s32 unk_94;
    s32 unk_98;
    Ov015Vec dir;
    s32 unk_a8;
    s32 minX;
    s32 maxX;
    s32 maxZ;
    s32 minZ;
    s32 unk_bc;
    Ov015FishInfo info;
    s32 nextStateId;
    VObj *nextState;
    s32 stateId;
    VObj *state;
    s32 prevStateId;
    VObj *prevState;
    s16 animSpeed;
    u8 unk_106[0x2];
    s32 drawMode;
    Ov015Anim res;
    Ov015Model model;
    Ov015Anim res2;
    Ov015Model model2;
    Ov015Shadow shadow;
    Ov015Obj48 hit;
};
OV015_SIZE(Ov015Fish, 0x5b0);
// Fishing phase state (0x34 bytes, Ov015Obj34_Init / Ov015Obj34_DtorBase).
struct Ov015Obj34 : public VObj {
    EffectObj *fx;
    s32 step;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    Ov015Ship *ship;
    Ov015Fish *fish;
    Ov015CamPair *cam;
    Ov015Info38 *info;
};
OV015_SIZE(Ov015Obj34, 0x34);
// Player ship (0xd58 bytes, ctor Ov015Ship_Ctor, dtor Ov015Ship_Dtor).
struct Ov015Ship {
    Ov015Anim res;
    Ov015Model model;
    Ov015Anim res2;
    Ov015Model subModels[8];
    Ov015Anim res3;
    Ov015Model model3;
    Ov015Shadow shadow;
    Ov015ShipMtx nodeMtx;  // matrix captured for one node
    Ov015Vec unk_d08;
    Ov015Vec pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_d26[0x2];
    EffectObj *fx;
    s32 fxTimer;
    EffectObj *fx2;
    s32 fxTimer2;
    u16 loadStep;
    u16 unk_d3a;
    u16 unk_d3c;
    s16 unk_d3e;
    u8 unk_d40;
    u8 unk_d41;
    u8 unk_d42;
    u8 unk_d43[0x1];
    s32 unk_d44;
    u16 modelIdx;
    u8 unk_d4a[0x2];
    Ov015Vec unk_d4c;
};
OV015_SIZE(Ov015Ship, 0xd58);
// Fish info block (0x38 bytes, vtable Ov015Info38_vtbl, ctor Ov015Info38_Ctor).
struct Ov015Info38 : public VObj {
    u16 id;
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
// Fishing game controller (0xcc bytes, vtable Ov015Game_vtbl, func_ov015_02200f74).
// Fishing HUD (0x30, vtable Ov015Hud_vtbl; built by Ov015Game_Create, dtor
// Ov015Hud_Dtor). func_ov015_021fb5d4 updates the counters from data_ov015_0221332c each frame;
// Ov015Hud_Draw draws the two 2D models.
struct Ov015Hud : public VObj {
    s32 unk_04;
    s32 frame; // frame counter, wraps at 0x7fff
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    Model *mdl0;
    Model *mdl1;
    s32 unk_2c;
};
OV015_SIZE(Ov015Hud, 0x30);

s32 func_ov015_021fb474(Ov015Hud *self);
BOOL func_ov015_021fb5d4(Ov015Hud *self);
void Ov015Hud_Draw(Ov015Hud *self);
void func_ov015_021fc40c(Ov015Hud *self, s32 mode);
void func_ov015_021fcb1c(Ov015Hud *self);

struct Ov015Game : public Ov015Child {
    s32 step;
    u8 unk_10;
    u8 unk_11[0x3];
    s32 unk_14;
    Ov015Ship *ship;
    Ov015List *fishList;
    Ov015MdlSet *unk_20;
    Ov015CamPair *cam;
    Ov015Hud *hud;
    struct Ov015Result *result;
    Ov015Obj30 phase1;
    Ov015Obj34 phase2;
    struct Ov015MsgMgr *unk_90;
    Ov015Info38 info;
};
OV015_SIZE(Ov015Game, 0xcc);
// ---- end struct types (svD) ----
}

extern "C" {
// Fish behaviour state (abstract base, vtable Ov015FishState_vtbl, dtor Ov015FishState_Dtor).
// The fish calls v08 on entry (with itself), v0c each frame and v10 on exit.
struct Ov015FishState : public VObj {
};
}

struct Ov015UiText;

// ov000 number display (0x98 bytes, vtables UiObj_vtbl -> Lo021cae48_vtbl).
struct Ov015UiNum : public UiObj {
    s32 unk_84;
    s32 unk_88;
    u32 value; // value
    u8 unk_90[0x8];
};
SIZE_ASSERT(Ov015UiNum, 0x98);
// Sets value (and unk_88 too when both is set).
extern "C" void Lo021cae48_SetValue(Ov015UiNum *self, s32 value, BOOL both);

// Camera view block: eye/at/up and the projection, laid out like Main Camera 0x04..0x3f
// (0x3c bytes; initialised by GfxCamPos_Init and GfxCamParam_Init).
struct Ov015CamView {
    Ov015Vec eye;
    Ov015Vec at;
    Ov015Vec up;
    s32 fovSin;
    s32 fovCos;
    s16 aspect;
    s16 nearClip;
    s16 farClip;
    u8 unk_32[0x8];
    u8 projDirty;
    u8 unk_3b;
};
SIZE_ASSERT(Ov015CamView, 0x3c);

// Fish state, vtable Ov015FishState18_vtbl (0x18 bytes; built in Ov015FishState2c_Update).
struct Ov015FishState18 : public Ov015FishState {
    Ov015Fish *fish;
    s32 step;
    s32 timer;
    s32 duration;
    u32 fxKey;
};
SIZE_ASSERT(Ov015FishState18, 0x18);

// Fish state, vtable Ov015FishState2c_vtbl (0x2c bytes, ctor Ov015FishState2c_Ctor).
struct Ov015FishState2c : public Ov015FishState {
    s16 step;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0a;
    s32 unk_0c;
    s32 unk_10;
    bool unk_14;
    u8 unk_15;
    s16 unk_16;
    s32 unk_18;
    s16 unk_1c;
    u8 unk_1e[0x2];
    Ov015Fish *fish;
    u32 unk_24;
    u32 unk_28;
};
SIZE_ASSERT(Ov015FishState2c, 0x2c);

// Fish state, vtable Ov015FishState1c_vtbl (0x1c bytes; built in Ov015FishState2c_Update).
struct Ov015FishState1c : public Ov015FishState {
    s32 step;
    s32 timer;
    s32 unk_0c;
    s32 unk_10;
    s32 targetX;
    Ov015Fish *fish;
};
SIZE_ASSERT(Ov015FishState1c, 0x1c);

// Fish state, vtable Ov015FishState40_vtbl (0x40 bytes, ctor Ov015FishState40_Ctor).
struct Ov015FishState40 : public Ov015FishState {
    s32 step;
    u32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    Ov015Vec unk_1c;
    Ov015Vec unk_28;
    s32 unk_34;
    s32 unk_38;
    Ov015Fish *fish;
};
SIZE_ASSERT(Ov015FishState40, 0x40);

// Fish state, vtable Ov015FishState08_vtbl (8 bytes, ctor Ov015FishState08_Ctor).
struct Ov015FishState08 : public Ov015FishState {
    s32 step;
};
SIZE_ASSERT(Ov015FishState08, 0x8);

// Scene task, vtable Ov015Scene2a88_vtbl (0x58 bytes, built by Ov015Scene2a88_New).
struct Ov015Scene2a88 : public Task {
    Model *model;
    u8 unk_40;
    u8 unk_41[0x3];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
    s32 unk_54;
};
SIZE_ASSERT(Ov015Scene2a88, 0x58);

// Message box, vtable Ov015MsgBox_vtbl (0x2c bytes). Built by MsgBox_Init,
// opened by MsgBox_Open, torn down by MsgBox_Release.
struct Ov015MsgBox : public VObj {
    u32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    u8 unk_10;
    u8 unk_11[0x3];
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};
SIZE_ASSERT(Ov015MsgBox, 0x2c);

// Scene task, vtable Ov015Scene2a08_vtbl (0xb0 bytes, built by Ov015Scene2a08_New).
struct Ov015Scene2a08 : public Task {
    Ov015Ship *ship;
    Ov015Shadow *shadow;
    Ov015CamView camView;
    UiList *unk_80;
    Lo021cadcc *unk_84;
    UiList *unk_88;
    Ov015MsgBox *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    u8 unk_a4;
    u8 unk_a5[0x3];
    s32 frame;
    s32 unk_ac;
};
SIZE_ASSERT(Ov015Scene2a08, 0xb0);

// Scene task, vtable Ov015Scene2c08_vtbl (0x6c bytes, built by Ov015Scene2c08_New).
struct Ov015Scene2c08 : public Task {
    UiList *unk_3c;
    Lo021cadcc *unk_40;
    UiList *unk_44;
    Ov015UiNum *unk_48;
    void *unk_4c;
    Ov015MsgBox *unk_50;
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    u16 unk_68;
    u8 unk_6a;
    u8 unk_6b;
};
SIZE_ASSERT(Ov015Scene2c08, 0x6c);

// Scene task, vtable Ov015Scene2b88_vtbl (0x58 bytes, built by Ov015Scene2b88_New).
struct Ov015Scene2b88 : public Task {
    UiList *unk_3c;
    Lo021cadcc *unk_40;
    UiList *unk_44;
    Lo021cb0b8 *unk_48;
    Ov015MsgBox *unk_4c;
    s32 unk_50;
    u16 unk_54;
    u8 unk_56[0x2];
};
SIZE_ASSERT(Ov015Scene2b88, 0x58);
extern "C" void func_ov015_0220566c(Ov015Scene2b88 *self, s32 a);

// Scene task, vtable Ov015Scene2b08_vtbl (0x164 bytes, built by Ov015Scene2b08_New).
struct Ov015Scene2b08 : public Task {
    UiList *unk_3c;
    Ov015UiNum *unk_40;
    Lo021cadcc *unk_44;
    UiList *unk_48;
    Lo021cb0b8 *unk_4c;
    UiObj *unk_50; // 0xe8 object, vtables UiObj_vtbl -> Lo021cad50_vtbl
    s32 unk_54;
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    u8 textBuf[0x100]; // text buffer
};
SIZE_ASSERT(Ov015Scene2b08, 0x164);

// Event message task, vtable Ov015Msg_vtbl (0x144 bytes, ctor Ov015Msg_Ctor).
struct Ov015Msg : public VObj {
    u8 unk_04;
    u8 unk_05[0x3];
    s32 unk_08;
    u16 msgIdx;
    u8 unk_0e[0x2];
    struct MsgRes *msgRes;
    Model *model;
    TextWin *textWin;
    s32 posX;
    s32 posY;
    s32 posZ;
    Lo021cadcc *label;
    Ov015UiText *textBox;
    void *pages[0x20]; // message pages
    s32 pageCount; // page count
    s32 page;
    char text[0x80]; // text buffer
    s32 seq;
    s32 step;
    s32 timer;
};
SIZE_ASSERT(Ov015Msg, 0x144);

// Text window with a portrait model (0xb4 bytes, vtables UiObj_vtbl -> Ov015Vt_02212d3c_vtbl, init Ov015UiText_ClearText).
struct Ov015UiText : public UiObj {
    TextWin *unk_84; // deleted and rebuilt by Ov015UiText_LoadText
    char text[0x20]; // filled by func_ov015_02208bac
    s32 textId;
    s32 unk_ac;
    s32 unk_b0; // redraw countdown (the text is rebuilt when it reaches 7)
};
SIZE_ASSERT(Ov015UiText, 0xb4);

// Event message manager, vtable Ov015MsgMgr_vtbl (0x14 bytes, init Ov015MsgMgr_Init).
struct Ov015MsgMgr : public VObj {
    VObj *unk_04;
    union {
        u8 unk_08; // one bit per message already shown (Ov015MsgMgr_HandleEvent)
        struct {
            u8 unk_08_0 : 1;
            u8 unk_08_1 : 1;
            u8 unk_08_2 : 1;
            u8 unk_08_3 : 1;
            u8 unk_08_4 : 1;
            u8 unk_08_5 : 3;
        };
    };
    u8 unk_09;
    u8 unk_0a[0x2];
    s32 unk_0c;
    s32 unk_10;
};
SIZE_ASSERT(Ov015MsgMgr, 0x14);

// Result panel (0x64 bytes, vtable Ov015ResultPanel_vtbl, built by Ov015Result_Init and set up by
// func_ov015_0220e634).
struct Ov015ResultPanel : public VObj {
    Lo021cb3a8 *unk_04;
    UiObj *unk_08; // 0x100 bytes, vtable Ov000Vt_021ccb54_vtbl
    Ov015UiNum *unk_0c;
    Ov015UiNum *unk_10;
    UiList *unk_14;
    s32 state; // state
    s32 timer; // timer
    char name[0x40]; // name
    s32 mode; // mode
};
SIZE_ASSERT(Ov015ResultPanel, 0x64);

// Result sequence (0x14 bytes, vtable Ov015Result_vtbl, ctor Ov015Result_Ctor).
struct Ov015Result : public VObj {
    s32 state; // state
    s8 mode; // mode
    u8 unk_09[0x3];
    s32 unk_0c;
    Ov015ResultPanel *panel;
};
SIZE_ASSERT(Ov015Result, 0x14);

extern "C" {
Ov015Result *Ov015Result_Ctor(Ov015Result *self);
void *Ov015Result_Dtor(Ov015Result *self);
void *Ov015Result_DtorDelete(Ov015Result *self);
void Ov015Result_Init(Ov015Result *self);
void Ov015Result_DtorBase(Ov015Result *self);
BOOL Ov015Result_Update(Ov015Result *self);
void Ov015Result_Draw(Ov015Result *self);
}

// Fishing tackle object (0x290 bytes, vtable Ov015Obj290_vtbl, init Ov015Obj290_Reset), with
// its own animation and model; gOv015Obj290 points to it.
struct Ov015Obj290 : public VObj {
    s32 unk_04;
    s32 step;
    s32 unk_0c;
    s32 unk_10;
    Ov015Anim res;
    Ov015Model model;
    Ov015Vec unk_234;
    Ov015Vec unk_240;
    Ov015Mtx33 rot;
    Ov015Vec unk_270;
    Ov015Vec unk_27c;
    u16 yaw;
    u16 unk_28a;
    s32 animSpeed;
};
SIZE_ASSERT(Ov015Obj290, 0x290);

// Object holding a spawned effect (0x34 bytes, vtable Ov015Obj292c_vtbl, init Ov015Obj292c_Init).
struct Ov015Obj292c : public VObj {
    EffectObj *fx; // effect object
    struct ActorMarker *marker; // 0x08 (ov000/ActorMarker.h), made by Ov015Obj292c_Setup
    Ov015Vec pos; // position
    Ov015Vec scale; // scale
    Ov015Vec unk_24; // a found fish's position (func_ov015_021fffc4); Ov015Obj292c_Draw copies it to marker->unk_50
    s32 unk_30;
};
SIZE_ASSERT(Ov015Obj292c, 0x34);


// Model helpers shared by the ov015 HUD TUs (021fb758, 021fce4c, 0220f7a8).
static inline ModelPart *Ov015Model_GetPart(Model *self, int idx) {
    if (idx >= self->numParts) {
        return NULL;
    }
    return &self->parts[idx];
}

static inline void Ov015Model_PlayPart(Model *model, int idx, int flag) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)FLD(void *, NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx), 0xc));
    }
    TexObj_DrawCell(model, anim, part, flag);
}

static inline s32 Ov015c_Sin(s32 t) {
    return FX_SinCosTable_[(FX_Mul(t, 0x3fff000) >> 16) * 2];
}

static inline s32 Ov015c_SinIdx(s32 idx) {
    return FX_SinCosTable_[idx * 2];
}

static inline s32 Ov015c_Sin2(s32 t) {
    return Ov015c_SinIdx(FX_Mul(t, 0x3fff000) >> 16);
}

static inline void Ov015c_SetV(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Ov015c_Sub(s32 a, s32 b) {
    return a - b;
}

static inline void Ov015Model_SetPosV(Model *m, const VecFx32 *v) {
    m->x = v->x;
    m->y = v->y;
}

static inline void Ov015Model_SetPos(Model *m, s32 x, s32 y) {
    m->x = x;
    m->y = y;
}

#endif
