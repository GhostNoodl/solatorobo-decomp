#ifndef OV000_FIELDMGR_H
#define OV000_FIELDMGR_H

#include "types.h"
#include "nitro/fx.h"
#include "Main/Lang/LangData.h"
#include "Main/Sys/FieldId.h"
#include "ov000/ActorBase.h"

// The field manager data_ov000_021ccd6c and the records it loads. Main/Res/StageCmd.h declares the
// same global with an incomplete FieldMgr; the Main stage code includes this header for the members.

// The two data blocks of a field, as Main's Lang code reads them (LangBlockA / LangBlockB, declared
// locally in src/Main/Lang). Block A is FieldMgr::blockA (LangBlockA_GetData / 0206e180 / 0206e1bc return
// its three 0x18-byte entry lists); block B is FieldMgr::blockB (func_0206e230: the exits,
// LangBlockB_GetData: the start points, func_0206e2a4: the props, func_0206e2ec: the actor spawns).
typedef struct LangBlockA {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ LangSecFlags flags;
    /* 0x0a */ u8 count0;
    /* 0x0b */ u8 count1;
    /* 0x0c */ u8 count2;
    /* 0x0d */ u8 unk_0d[3];
    /* 0x10 */ u8 data[1];
} LangBlockA;

typedef struct LangBlockB {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ LangSecFlags flags;
    /* 0x0a */ u16 unk_0a; // the four TouchQuad_Init arguments (func_ov000_021b628c / 021b6c60)
    /* 0x0c */ u16 unk_0c;
    /* 0x0e */ u16 unk_0e;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ u8 count0; // exits
    /* 0x15 */ u8 count1; // start points
    /* 0x16 */ u8 count2; // props
    /* 0x17 */ u8 count3; // actor spawns
    /* 0x18 */ u8 count4;
    /* 0x19 */ u8 unk_19_0 : 1;
    /* 0x19 */ u8 unk_19_1 : 1;
    /* 0x19 */ u8 unk_19_2 : 1;
    /* 0x19 */ u8 unk_19_3 : 5;
    /* 0x1a */ u8 unk_1a[2];
    /* 0x1c */ u8 data[1];
} LangBlockB;

// An exit of the field (0x24 bytes, block B section 0). Entering its box (FieldMgr_Update) moves
// the player to field `dest` (0xff parts: the current field's) at exit `destExit` there;
// func_ov000_021b628c places the player at pos + offset of the exit it arrives at.
typedef struct FieldExit {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ s16 hx; // half size of the box (<< 4)
    /* 0x0e */ s16 hy;
    /* 0x10 */ s16 hz;
    /* 0x12 */ u16 rot; // box yaw
    /* 0x14 */ s16 ox; // arrival offset from pos (<< 4)
    /* 0x16 */ s16 oy;
    /* 0x18 */ s16 oz;
    /* 0x1a */ u16 dir; // arrival yaw
    /* 0x1c */ u16 unk_1c_0 : 1;
    /* 0x1c */ u16 unk_1c_1 : 1;
    /* 0x1c */ u16 type : 2; // func_ov000_021b65ec
    /* 0x1c */ u16 unk_1c_4 : 12;
    /* 0x1e */ u8 unk_1e[2];
    /* 0x20 */ FieldId dest;
    /* 0x23 */ u8 destExit;
} FieldExit;

// A start point of the field (0x10 bytes, block B section 1).
typedef struct FieldStart {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ u16 rot;
    /* 0x0e */ u8 unk_0e[2];
} FieldStart;

// A prop record (0x34 bytes, block B section 2), read by func_ov000_021b8014.
typedef struct FieldPropDef {
    /* 0x00 */ char path[0x18]; // resource path entry (ResMgr_Load, Path_SkipDir)
    /* 0x18 */ VecFx32 pos;
    /* 0x24 */ u16 rot[3];
    /* 0x2a */ s16 sx;
    /* 0x2c */ s16 sy;
    /* 0x2e */ s16 sz;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ u16 anim : 1; // the flags func_ov000_021b8014 turns into loader / model / prop flags
    /* 0x32 */ u16 loop : 1;
    /* 0x32 */ u16 hit : 1;
    /* 0x32 */ u16 tex : 1;
    /* 0x32 */ u16 fade : 1;
    /* 0x32 */ u16 boxTest : 1;
    /* 0x32 */ u16 lod : 1;
    /* 0x32 */ u16 addInvTrans : 1;
    /* 0x32 */ u16 unk_32_8 : 8;
} FieldPropDef;

// The resource loader of a prop (0x24 bytes, FieldProp::loader, stepped by func_ov000_021b6d28).
typedef struct FieldPropLoader {
    /* 0x00 */ union {
        const char *path;
        const FieldPropDef *def; // the path is the start of the prop record
    };
    /* 0x04 */ const char *name; // Path_SkipDir(path)
    /* 0x08 */ s16 state;
    /* 0x0a */ union {
        u16 flags;
        struct {
            u16 flag0 : 1; // load the archive
            u16 flag1 : 1; // archive requested (released by func_ov000_021b7a7c)
            u16 flag2 : 1; // model
            u16 flag3 : 1;
            u16 flag4 : 1; // texture (name + data_ov000_021cc84c)
            u16 flag5 : 1;
            u16 flag6 : 1; // animations
            u16 flag7 : 1;
            u16 flag8 : 1; // hit mesh
            u16 flag9 : 7;
        };
    };
    /* 0x0c */ u32 task0;
    /* 0x10 */ u32 task1;
    /* 0x14 */ void **mdl;
    /* 0x18 */ void **tex;
    /* 0x1c */ void **anm;
    /* 0x20 */ void **hit;
} FieldPropLoader;

// The model of a prop (0xc0 bytes, FieldProp::model; ctor func_ov000_021b6f94, set up by
// func_ov000_021b70c0, animated by FieldPropModel_UpdateAnim, drawn by func_ov000_021b75e0).
typedef struct FieldPropModel {
    /* 0x00 */ FieldPropLoader *res;
    /* 0x04 */ struct NNSG3dAnmObj_ *anm[5];
    /* 0x18 */ void *matBuf;
    /* 0x1c */ void *jntBuf;
    /* 0x20 */ struct NNSG3dRenderObj_ *rob; // robj or a sub model
    /* 0x24 */ struct NNSG3dRenderObj_ *sub[1]; // lower detail models (nsub)
    /* 0x28 */ u8 robj[0x54]; // NNSG3dRenderObj (bytes here, so that this header needs no nnsys/g3d.h)
    /* 0x7c */ VecFx32 trans;
    /* 0x88 */ MtxFx33 rot;
    /* 0xac */ VecFx32 scale;
    /* 0xb8 */ s16 speed; // animation step
    /* 0xba */ u8 nsub;
    /* 0xbb */ u8 cur; // shown model (0: robj)
    /* 0xbc */ u8 alpha;
    /* 0xbd */ union {
        u8 flags;
        struct {
            u8 on : 1;
            u8 loop : 1;
            u8 stop : 1;
            u8 invV : 1;
            u8 addInvTrans : 1;
            u8 boxTest : 1;
            u8 unk_bd_6 : 2;
        };
    };
} FieldPropModel;

// A prop of the field (0x114 bytes, ctor func_ov000_021b79f4, dtor func_ov000_021b7a7c), in the list
// FieldMgr::head / tail. func_ov000_021b8014 sets it up from its record, func_ov000_021b7f0c loads
// it, func_ov000_021b7b50 updates it and func_ov000_021b7e34 tests whether it is drawn.
typedef struct FieldProp {
    /* 0x000 */ struct FieldProp *prev;
    /* 0x004 */ struct FieldProp *next;
    /* 0x008 */ FieldPropLoader loader;
    /* 0x02c */ FieldPropModel model;
    /* 0x0ec */ void *hitMesh; // a HitMesh (0x98 bytes)
    /* 0x0f0 */ s32 unk_f0;
    /* 0x0f4 */ u8 unk_f4;
    /* 0x0f5 */ u8 state;
    /* 0x0f6 */ union {
        u8 unk_f6;
        struct {
            u8 fade : 1; // fades out with the camera distance
            u8 lod : 1; // switches to the sub models with the distance
            u8 visible : 1;
            u8 keepHit : 1; // hit mesh stays linked
            u8 unk_f6_4 : 4;
        };
    };
    /* 0x0f8 */ s32 viewScale; // func_ov000_021b7e60
    /* 0x0fc */ VecFx32 viewMin; // box around the camera the prop is updated in
    /* 0x108 */ VecFx32 viewMax;
} FieldProp;

struct FieldMgr;
typedef void (FieldMgr::*FieldMgrFn)();

// The field manager (0x294 bytes, ctor func_ov000_021b5054, made by func_ov000_021b4eec, deleted by
// func_ov000_021b4f28): data_ov000_021ccd6c. FieldMgr_UpdateLoad loads the field's blocks and props,
// FieldMgr_Update updates them and tests the exits, func_ov000_021b53a8 draws,
// func_ov000_021b53f4 unloads, func_ov000_021b628c places the player at the exit it arrives at.
struct FieldMgr {
    /* 0x000 */ PauseNode pause;
    /* 0x008 */ u8 state; // FieldMgr_UpdateLoad load steps (0xff: done)
    /* 0x009 */ u8 curExit; // the exit the player arrived at (0xff: none)
    /* 0x00a */ u8 destExit; // FieldExit::destExit of the exit taken
    /* 0x00b */ u8 exit; // the exit taken (0xff: none)
    /* 0x00c */ void *unk_0c;
    /* 0x010 */ LangBlockA *blockA;
    /* 0x014 */ LangBlockB *blockB;
    /* 0x018 */ FieldExit *exits;
    /* 0x01c */ FieldProp *head;
    /* 0x020 */ FieldProp *tail;
    /* 0x024 */ VecFx32 playerPos; // written by the robot each frame
    /* 0x030 */ u16 ids[0x20]; // actors placed relative to group node unk_1f0 (func_ov000_021b6b4c)
    /* 0x070 */ VecFx32 vecs[0x20];
    /* 0x1f0 */ u16 unk_1f0;
    /* 0x1f2 */ s16 unk_1f2;
    /* 0x1f4 */ u8 hitMesh[0x98]; // HitMesh_Init
    /* 0x28c */ FieldMgrFn step;
};

#ifdef __cplusplus
extern "C" {
#endif

extern FieldMgr *data_ov000_021ccd6c;

void func_ov000_021b4eec(void);
void func_ov000_021b4f28(void);
FieldMgr *func_ov000_021b5054(FieldMgr *self);
void FieldMgr_Update(FieldMgr *self);
void func_ov000_021b53a8(FieldMgr *self);
void func_ov000_021b53f4(FieldMgr *self);
BOOL FieldMgr_UpdateLoad(FieldMgr *self);
void func_ov000_021b5dc0(FieldMgr *self);
void func_ov000_021b628c(FieldMgr *self);
void func_ov000_021b65ec(FieldMgr *self);
FieldExit *FieldMgr_FindExitAt(FieldMgr *self, VecFx32 *pos);
void func_ov000_021b6994(FieldMgr *self, u8 all);
void func_ov000_021b6b4c(FieldMgr *self, u16 id, const VecFx32 *v);
void func_ov000_021b6be4(FieldMgr *self);
void func_ov000_021b6c60(FieldMgr *self);

#ifdef __cplusplus
}
#endif

#endif
