#ifndef MAIN_EFFECT_EFFECT_H
#define MAIN_EFFECT_EFFECT_H

#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResMgr.h"

// Effect system ("ef/effect3d"): timeline-driven 3D effects with sound cues.
// The vtables stay in asm.

typedef struct EffectVec {
    s32 x;
    s32 y;
    s32 z;
} EffectVec;

typedef struct EffectRot {
    u16 x;
    u16 y;
    u16 z;
} EffectRot;

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
    virtual void vf0c();
    virtual void SetScale(const EffectVec *scale);
    virtual void SetScaleXYZ(s32 x, s32 y, s32 z);
    virtual void SetPos(const EffectVec *pos);
    virtual void SetPosXYZ(s32 x, s32 y, s32 z);
    virtual void AddPos(const EffectVec *delta);
    virtual void AddPosXYZ(s32 x, s32 y, s32 z);
    virtual void vf28();
    virtual void vf2c();
    virtual void SetRot(const EffectRot *rot);
    virtual void SetRotXYZ(u16 x, u16 y, u16 z);
    virtual BOOL Load();
    virtual BOOL Setup();
    virtual BOOL Step();
    virtual void Loop();
    virtual void Draw();
    /* 0x04 */ u32 unk_04;
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
    /* 0x40 */ EffectVec scale;
    /* 0x4c */ s32 unk_4c;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ EffectVec pos;
    /* 0x64 */ EffectRot rot;
    /* 0x6c */ EffectVec *posPtr;
    /* 0x70 */ EffectVec offset;
    /* 0x7c */ s32 unk_7c;
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

// Minimal NitroSystem G3D types.
typedef struct EffectResDict {
    /* 0x0 */ u8 revision;
    /* 0x1 */ u8 numEntry;
    /* 0x2 */ u16 sizeDictBlk;
    /* 0x4 */ u16 unk_04;
    /* 0x6 */ u16 ofsEntry;
} EffectResDict;

typedef struct EffectResAnm {
    /* 0x0 */ u32 sig;
    /* 0x4 */ u16 numFrame;
} EffectResAnm;

typedef struct EffectAnmObj {
    /* 0x00 */ s32 frame;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ EffectResAnm *resAnm;
    /* 0x0c */ u8 unk_0c[0x74];
} EffectAnmObj; // size 0x80

typedef struct EffectRenderObj {
    /* 0x00 */ u8 unk_00[0x2c];
    /* 0x2c */ void *ptrUser;
    /* 0x30 */ u8 unk_30[0x24];
} EffectRenderObj; // size 0x54

typedef struct EffectFile {
    void *data;
} EffectFile;

// NNSG3dResTex.
typedef struct EffectResTex {
    /* 0x00 */ u8 header[8];
    /* 0x08 */ u32 texVramKey;
    /* 0x0c */ u8 unk_0c[0xc];
    /* 0x18 */ u32 tex4x4VramKey;
    /* 0x1c */ u8 unk_1c[0x10];
    /* 0x2c */ u32 plttVramKey;
    /* 0x30 */ u16 sizePltt;
    /* 0x32 */ u16 plttFlag;
    /* 0x34 */ u16 plttOfsDict;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u32 ofsPlttData;
    /* 0x3c */ EffectResDict dict;
} EffectResTex;

#define EFFECT_ANM_MAX 5

// 3D model effect loaded from an archive ("ef/effect3d" by default).
struct Effect3D : public EffectObj {
    /* 0x0f8 */ char arcName[0x20];
    /* 0x118 */ char mdlName[0x18];
    /* 0x130 */ char anmName[0x18];
    /* 0x148 */ EffectFile *mdlFile;
    /* 0x14c */ EffectFile *anmFiles;
    /* 0x150 */ void *resMdl;
    /* 0x154 */ void *resTex;
    /* 0x158 */ EffectAnmObj *anmObjs[EFFECT_ANM_MAX];
    /* 0x16c */ EffectRenderObj renderObj;
    /* 0x1c0 */ void (*initCallback)(void *rs);
};

struct EffectSetup;

// Effect group loaded from an "ef/effectsetup" script; children hang off the child chain.
struct EffectGroup : public EffectObj {
    /* 0x0f8 */ char arcName[0x20];
    /* 0x118 */ char name[0x18];
    /* 0x130 */ void *arc;
    /* 0x134 */ struct EffectSetup *setup;
};

// Parses an effect setup script and spawns its effects.
struct EffectSetup {
    virtual void Dtor();
    virtual void Delete();
    /* 0x04 */ u8 *data;
    /* 0x08 */ EffectVec pos;
    /* 0x14 */ u8 *objChunk;
    /* 0x18 */ u8 *chunk18;
    /* 0x1c */ u8 *chunk1c;
    /* 0x20 */ u8 *chunk20;
    /* 0x24 */ u8 *chunk24;
};

// Entry of the setup script's object table.
typedef struct EffectDef {
    /* 0x00 */ char arcName[0x18];
    /* 0x18 */ char mdlName[0x10];
    /* 0x28 */ s32 type;
    /* 0x2c */ s32 delay;
    /* 0x30 */ s32 loopCount;
    /* 0x34 */ s32 cueId;
    /* 0x38 */ u8 unk_38;
    /* 0x3c */ s32 paramId;
    /* 0x40 */ char emitName[0x10];
    /* 0x50 */ u8 partIds[4];
} EffectDef;

typedef struct EffectPtmf {
    u32 func;
    u32 adj;
} EffectPtmf;

// Particle command: animates one property over [start, start + len).
typedef struct EffectPtclCmd {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 start;
    /* 0x08 */ s32 len;
    /* 0x0c */ s32 mode;
    /* 0x10 */ EffectVec a;
    /* 0x1c */ EffectVec b;
} EffectPtclCmd; // size 0x28

typedef struct EffectPtcl {
    virtual void Dtor();
    virtual void Delete();
    /* 0x04 */ EffectVec dir;
    /* 0x10 */ s32 speed;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1c */ EffectVec origin;
    /* 0x28 */ EffectVec pos;
    /* 0x34 */ EffectVec scale;
    /* 0x40 */ EffectRot rot;
    /* 0x48 */ s32 alpha;
    /* 0x4c */ u16 color;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 texIdx;
    /* 0x58 */ s32 unk_58;
    /* 0x5c */ u32 dl[14];
    /* 0x94 */ struct EffectResTex *tex;
    /* 0x98 */ s32 texAddr;
    /* 0x9c */ u32 polyAttr;
    /* 0xa0 */ s32 unk_a0;
    /* 0xa4 */ s32 depth;
    /* 0xa8 */ EffectPtclCmd *cmds;
    /* 0xac */ s32 numCmds;
    /* 0xb0 */ s32 time;
    /* 0xb4 */ s32 unk_b4;
    /* 0xb8 */ s32 unk_b8;
    /* 0xbc */ struct EffectPtcl *next;
    /* 0xc0 */ struct EffectPtcl *prev;
} EffectPtcl;

struct EffectEmitterSub;
typedef BOOL (EffectEmitterSub::*EffectPtclHandler)(EffectPtcl *ptcl, EffectPtclCmd *cmd);

struct EffectEmitterSub {
    virtual void Dtor();
    virtual void Delete();
    /* 0x04 */ EffectPtclHandler funcs[8];
};

typedef struct EffectPartSlot {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ s32 type;
    /* 0x08 */ s32 start;
    /* 0x0c */ s32 len;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ s32 rate;
    /* 0x18 */ EffectVec vec;
    /* 0x24 */ EffectVec vec2;
    /* 0x30 */ u8 used;
} EffectPartSlot; // size 0x34

struct EffectPartSet;
typedef BOOL (EffectPartSet::*EffectPartHandler)(EffectPartSlot *slot);

struct EffectPartSet {
    virtual void Dtor();
    virtual void Delete();
    virtual void vf08();
    virtual BOOL Step();
    /* 0x004 */ EffectPtcl *ptcls;
    /* 0x008 */ s32 time;
    /* 0x00c */ EffectVec pos;
    /* 0x018 */ EffectPartHandler funcs[7];
    /* 0x050 */ EffectPartSlot slots[4];
    /* 0x120 */ s32 localTime;
    /* 0x124 */ s32 period;
    /* 0x128 */ s32 duration;
};

typedef struct EffectEmitParams {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 duration;
    /* 0x14 */ u8 unk_14[0x20];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ u8 unk_38[0x18];
} EffectEmitParams; // size 0x50

// Particle emitter effect.
struct EffectEmitter : public EffectObj {
    /* 0x0f8 */ EffectDef *nameDef;
    /* 0x0fc */ void *arc;
    /* 0x100 */ EffectFile *file;
    /* 0x104 */ EffectDef *def;
    /* 0x108 */ EffectResTex *tex;
    /* 0x10c */ EffectPtcl *ptcls;
    /* 0x110 */ EffectPtclCmd *emitData;
    /* 0x114 */ s32 emitCount;
    /* 0x118 */ EffectEmitterSub sub;
    /* 0x15c */ EffectPartSet *parts;
    /* 0x160 */ EffectEmitParams params;
    /* 0x1b0 */ s32 emitTime;
    /* 0x1b4 */ s32 mtx[9];
}; // size 0x1d8

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EffectCamera {
    /* 0x00 */ EffectVec pos;
    /* 0x0c */ EffectVec target;
    /* 0x18 */ EffectVec up;
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
    /* 0x5c */ u8 proj[0x40];
} EffectMgr; // size 0x9c

typedef struct EffectGlobal {
    /* 0x0 */ u8 polyIdBase;
    /* 0x1 */ u8 polyIdCounter;
    /* 0x4 */ EffectMgr *mgr;
} EffectGlobal;

extern EffectGlobal data_0214a41c;
extern SndMgr *data_02097e4c;

extern s32 FX_Div(s32 a, s32 b);
extern void MIi_CpuClear32(u32 value, void *dst, u32 size);
extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049f44(SndMgr *mgr, s32 id, void *pos, s32 arg);
extern BOOL func_0204a118(SndMgr *mgr, s32 id);
extern void func_02049de8(SndMgr *mgr, s32 id);

static inline s32 Effect_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline u8 Effect_NextPolyId(void) {
    u8 n = data_0214a41c.polyIdCounter++;
    return data_0214a41c.polyIdBase + (u8)((s32)n % 16);
}

void func_02063cac(struct EffectObj *obj);
BOOL func_020637d0(struct EffectObj *obj);
void func_02063954(struct EffectObj *obj);
void func_02063a14(struct EffectObj *obj);

#define EFFECT_DELETE(obj) \
    { \
        void *saved_ = data_02097dd0->cur; \
        data_02097dd0->cur = data_02097dd0->unk_08; \
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

extern void *NNS_G3dGetMdlSet(void *file);
extern void *NNS_G3dGetTex(void *file);
extern void *NNS_G3dGetAnmByName(void *set, void *name);
extern void NNS_G3dAnmObjInit(EffectAnmObj *anmObj, void *resAnm, void *resMdl, void *resTex);
extern void NNS_G3dRenderObjInit(EffectRenderObj *renderObj, void *resMdl);
extern void NNS_G3dRenderObjAddAnmObj(EffectRenderObj *renderObj, EffectAnmObj *anmObj);
extern void NNS_G3dRenderObjSetInitFunc(EffectRenderObj *renderObj, void (*func)(void *rs));
extern void func_020359d0(const char *arc, s32 b, s32 c);
extern BOOL func_02035b90(const char *arc, s32 b);
extern void *func_02035d5c(const char *arc);
extern EffectFile *func_02034ec0(void *arc, const char *name);
extern EffectFile *func_02034ff8(void *arc, const char *name);
extern void func_02036838(ResMgr *mgr, const char *arc, s32 c, s32 d);
extern void func_0203ed04(const char *name, void *data);
extern void func_0203f0b4(void *data);
extern void *func_0203de84(u32 size, u32 align);
extern void func_0203df0c(void *ptr);
extern void func_0203de1c(void *ptr);
extern void *func_0203dd9c(u32 size);
extern void VEC_Add(const EffectVec *a, const EffectVec *b, EffectVec *out);
extern void VEC_MultAdd(s32 a, const EffectVec *v1, const EffectVec *v2, EffectVec *out);
extern char data_0208c330[];

typedef struct EffectGlb {
    /* 0x000 */ u8 unk_00[0xfc];
    /* 0x0fc */ u32 flags;
    /* 0x100 */ u8 unk_100[0x140];
    /* 0x240 */ EffectVec camPos;
    /* 0x24c */ EffectVec camUp;
    /* 0x258 */ EffectVec camTarget;
} EffectGlb; // NNSG3dGlb

extern EffectGlb NNS_G3dGlb;
extern u8 data_02092800[];
extern u8 data_02092844[];
extern u8 data_020928b4[];
extern void MI_Copy64B(const void *src, void *dst);
extern void MI_Copy48B(const void *src, void *dst);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_OrthoW(int t, int b, int l, int r, int n, int f, int scaleW, void *mtx);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void MTX_Identity43_(void *mtx);
extern void MTX_Identity33_(void *mtx);
extern void NNS_G3dGlbSetBaseTrans(const EffectVec *trans);
extern void NNS_G3dGlbSetBaseScale(const EffectVec *scale);
extern void NNS_G3dGlbFlushP(void);
extern void NNS_G3dDraw(EffectRenderObj *renderObj);
extern char data_0208c33c[];

#ifdef __cplusplus
}
#endif

#endif
