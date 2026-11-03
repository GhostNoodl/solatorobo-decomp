#ifndef MAIN_EFFECT_EFFECT_H
#define MAIN_EFFECT_EFFECT_H

#include "types.h"
#include "Main/Math/Rot16.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "Main/Sys/SysState.h"

// Effect system ("ef/effect3d"): timeline-driven 3D effects with sound cues. This is the part the
// overlays use (objects, groups, the manager and the API); the effect TUs' own types are in
// Main/Effect/EffectInt.h. The vtables stay in asm.

typedef Rot16 EffectRot;

typedef struct EffectSndCue {
    /* 0x0 */ s32 id;
    /* 0x4 */ s32 frame;
} EffectSndCue;

struct EffectObj;

typedef void (*EffectCallback)(struct EffectObj *obj);

struct EffectObj {
    virtual void Dtor();
    virtual void Delete();
    virtual void SetParam(s32 param);
    virtual void SetScaleAll(s32 scale); // EffectObj_SetScaleAll: SetScaleXYZ(scale, scale, scale)
    virtual void SetScale(const VecFx32 *scale);
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void SetPos(const VecFx32 *pos);
    virtual void SetPosXYZ(s32 x, s32 y, s32 z);
    virtual void AddPos(const VecFx32 *delta);
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
    virtual void SetOffset(const VecFx32 *offset);  // EffectObj_SetOffset
    virtual void SetOffsetXYZ(s32 x, s32 y, s32 z); // EffectObj_SetOffsetXYZ
    virtual void SetRot(const EffectRot *rot);
    virtual void SetRotXYZ(u16 x, u16 y, u16 z);
    virtual BOOL Load();
    virtual BOOL Setup();
    virtual BOOL Step();
    virtual void Loop();
    virtual void Draw();
    /* 0x04 */ s32 unk_04; // countdown kept by onUpdate callbacks (Ov010_DelayKillFxCallback compares it signed)
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ s32 state;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ u32 id;
    /* 0x28 */ u8 unk_28;
    /* 0x29 */ u8 unk_29;
    /* 0x2c */ s32 unk_2c;
    /* 0x30 */ s32 time;
    /* 0x34 */ u8 unk_34;
    /* 0x38 */ s32 prevTime;
    /* 0x3c */ s32 speed;
    /* 0x40 */ VecFx32 scale;
    /* 0x4c */ s32 unk_4c;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ VecFx32 pos;
    /* 0x64 */ EffectRot rot;
    /* 0x6c */ VecFx32 *posPtr;
    /* 0x70 */ VecFx32 offset;
    /* 0x7c */ s32 alpha; // 0..0x1000 (a group passes its own to its children)
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ EffectSndCue cues[8];
    /* 0xc4 */ u8 unk_c4;
    /* 0xc8 */ s32 loopCount;
    /* 0xcc */ s32 loopStart;
    /* 0xd0 */ u8 paused;
    /* 0xd4 */ s32 unk_d4;
    /* 0xd8 */ EffectCallback onStart;
    /* 0xdc */ EffectCallback onUpdate;
    /* 0xe0 */ EffectCallback onDraw;
    /* 0xe4 */ struct EffectObj *next;
    /* 0xe8 */ struct EffectObj *drawPrev;
    /* 0xec */ struct EffectObj *drawNext;
    /* 0xf0 */ struct EffectObj *child;
    /* 0xf4 */ struct EffectObj *parent;
};

typedef struct EffectFile {
    NNSG3dResFileHeader *data;
} EffectFile;

#define EFFECT_ANM_MAX 5

// 3D model effect loaded from an archive ("ef/effect3d" by default).
struct Effect3D : public EffectObj {
    /* 0x0f8 */ char arcName[0x20];
    /* 0x118 */ char mdlName[0x18];
    /* 0x130 */ char anmName[0x18];
    /* 0x148 */ EffectFile *mdlFile;
    /* 0x14c */ EffectFile *anmFiles;
    /* 0x150 */ NNSG3dResMdl *resMdl;
    /* 0x154 */ NNSG3dResTex *resTex;
    /* 0x158 */ NNSG3dAnmObj *anmObjs[EFFECT_ANM_MAX]; // 0x80 bytes each
    /* 0x16c */ NNSG3dRenderObj renderObj;
    /* 0x1c0 */ NNSG3dSbcCallBackFunc initCallback;
};

struct EffectSetup;

// Effect group loaded from an "ef/effectsetup" script; children hang off the child chain.
struct EffectGroup : public EffectObj {
    /* 0x0f8 */ char arcName[0x20];
    /* 0x118 */ char name[0x18];
    /* 0x130 */ void *arc;
    /* 0x134 */ struct EffectSetup *setup;
};


#ifdef __cplusplus
extern "C" {
#endif

typedef struct EffectCamera {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ VecFx32 target;
    /* 0x18 */ VecFx32 up;
} EffectCamera;

typedef struct EffectMgr {
    /* 0x00 */ u8 task[8];
    /* 0x08 */ s32 state;
    /* 0x0c */ u32 nextId;
    /* 0x10 */ u8 drawFilter;
    /* 0x14 */ s32 loadStep;
    /* 0x18 */ void *arc3d;
    /* 0x1c */ void *arcSetup;
    /* 0x20 */ struct EffectObj *head;
    /* 0x24 */ s32 count;
    /* 0x28 */ struct EffectObj *head2;
    /* 0x2c */ s32 count2;
    /* 0x30 */ struct EffectObj *drawHead;
    /* 0x34 */ u8 useCamera;
    /* 0x38 */ EffectCamera camera;
    /* 0x5c */ MtxFx44 proj;
} EffectMgr; // size 0x9c

// The effect manager (Effect.cpp .bss).
extern EffectMgr *data_0214a420;


// Effect API used by the overlays (defined in Effect.cpp, Effect_4.cpp and Effect_5.cpp).
EffectObj *Effect_SpawnId(s32 id, const VecFx32 *pos);
EffectObj *Effect_Find_020657b0(EffectMgr *m, u32 id);
BOOL EffectMgr_Contains(EffectMgr *m, EffectObj *obj);
void EffectMgr_Kill(EffectMgr *m, u32 id);
void EffectMgr_StopLoop(EffectMgr *m, u32 id);
void EffectMgr_FreeAll(EffectMgr *m);
EffectObj *EffectMgr_FindByKey(EffectMgr *m, s32 v);
void EffectMgr_Update(EffectMgr *m);
struct Effect3D *Effect3D_Create(const char *arc, const char *mdl, const char *anm, const VecFx32 *pos);
struct Effect3D *Effect3D_NewAt(const char *arc, const char *mdl, const char *anm, const VecFx32 *pos);
struct EffectGroup *EffectGroup_Create(const char *arc, const char *name, const VecFx32 *pos);
// Fixed screen effects (Effect_5.cpp: EffectHud_Create with a built-in archive/model name).
struct Effect3D *EffectHud_New2710(void);
struct Effect3D *EffectHud_New2711(void);
struct Effect3D *EffectHud_New2712(void);
struct Effect3D *EffectHud_New2713(void);
struct Effect3D *EffectHud_New2715(void);
struct Effect3D *EffectHud_New2716(void);
void EffectMgr_SaveList(EffectMgr *m);
void EffectMgr_RestoreList(EffectMgr *m);
void EffectObj_AddSndCue(EffectObj *obj, s32 id, s32 frame);

void EffectObj_UpdateSndCues(struct EffectObj *obj);
BOOL func_020637d0(struct EffectObj *obj);
void func_02063954(struct EffectObj *obj);
void EffectObj_StopLoop(struct EffectObj *obj);

#define EFFECT_DELETE(obj) \
    { \
        void *saved_ = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->heapHi; \
        if ((obj) != NULL) { \
            if ((obj) != NULL) { \
                (obj)->Delete(); \
            } \
        } \
        data_02097dd0->cur = saved_; \
    }

static inline void Effect_Delete(EffectObj *o) {
    EFFECT_DELETE(o);
}

static inline void EffectMgr_Clear(EffectMgr *m) {
    EffectObj *o;
    EffectObj *next;
    for (o = m->head; o != NULL; o = next) {
        next = o->next;
        Effect_Delete(o);
    }
    m->head = NULL;
    m->count = 0;
}

static inline struct EffectObj *Effect_Find(EffectMgr *mgr, u32 id) {
    struct EffectObj *obj;
    for (obj = mgr->head; obj != NULL; obj = obj->next) {
        if (id == obj->id) {
            return obj;
        }
    }
    for (obj = mgr->head2; obj != NULL; obj = obj->next) {
        if (id == obj->id) {
            return obj;
        }
    }
    return NULL;
}


#ifdef __cplusplus
}
#endif

#endif
