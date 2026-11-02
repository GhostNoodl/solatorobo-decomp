#ifndef MAIN_EFFECT_EFFECTINT_H
#define MAIN_EFFECT_EFFECTINT_H

// Types and helpers private to the effect TUs (src/Main/Effect).

#include "Main/Effect/Effect.h"
#include "Main/Gfx/G3dGlbSyms.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Res/ResArc.h"
#include "nnsys/g3d.h"
#include "nitro/mi.h"

// Minimal NitroSystem G3D types.
typedef struct EffectResDict {
    /* 0x0 */ u8 revision;
    /* 0x1 */ u8 numEntry;
    /* 0x2 */ u16 sizeDictBlk;
    /* 0x4 */ u16 unk_04;
    /* 0x6 */ u16 ofsEntry;
} EffectResDict;


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



// Parses an effect setup script and spawns its effects.
struct EffectSetup {
    virtual void Dtor();
    virtual void Delete();
    /* 0x04 */ u8 *data;
    /* 0x08 */ VecFx32 pos;
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
    /* 0x10 */ VecFx32 a;
    /* 0x1c */ VecFx32 b;
} EffectPtclCmd; // size 0x28

typedef struct EffectPtcl {
    virtual void Dtor();
    virtual void Delete();
    /* 0x04 */ VecFx32 dir;
    /* 0x10 */ s32 speed;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1c */ VecFx32 origin;
    /* 0x28 */ VecFx32 pos;
    /* 0x34 */ VecFx32 scale;
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
    /* 0x18 */ VecFx32 vec;
    /* 0x24 */ VecFx32 vec2;
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
    /* 0x00c */ VecFx32 pos;
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
    /* 0x1b4 */ MtxFx33 mtx;
}; // size 0x1d8

#ifdef __cplusplus
extern "C" {
#endif

// The effect TU's .bss: the polygon ID base and counter (Effect.cpp).
extern u8 data_0214a41c;
extern u8 data_0214a41d;

static inline s32 Effect_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline u8 Effect_NextPolyId(void) {
    u8 n = data_0214a41d++;
    return data_0214a41c + (u8)((s32)n % 16);
}

extern EffectFile *ResList_FindType4(void *arc, const char *name);
extern EffectFile *ResList_FindType6(void *arc, const char *name);
extern BOOL func_0203ed04(const char *name, void *data);
extern void Vram_FreeRes(void *data);
extern void *Heap_AllocHi(u32 size, u32 align);
extern void Heap_FreeHi(void *ptr);
extern void Heap_Free(void *ptr);
extern void *Heap_Alloc(u32 size);
extern char data_0208c330[];

extern char data_0208c33c[];

#ifdef __cplusplus
}
#endif

#endif
