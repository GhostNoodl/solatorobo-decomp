#ifndef MAIN_GFX_OBJPOOL_H
#define MAIN_GFX_OBJPOOL_H

#include "types.h"
#include "Main/Res/StageVars.h"
#include "nitro/fx.h"
#include "Main/Res/ResMgr.h"

// Fixed pool of 16 entries (point/sphere shapes with a color) linked into a list.
typedef struct ObjPoolParam {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s16 r;
    /* 0x08 */ s16 ry;
    /* 0x0a */ s16 rz;
} ObjPoolParam;

typedef struct ObjPoolEntry {
    /* 0x00 */ u16 active;
    /* 0x02 */ u16 id;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u32 kind;
    /* 0x0c */ s32 x;
    /* 0x10 */ s32 y;
    /* 0x14 */ s32 z;
    /* 0x18 */ s32 unk_18;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ void *obj;
    /* 0x28 */ u8 r;
    /* 0x29 */ u8 g;
    /* 0x2a */ u8 b;
    /* 0x2c */ struct ObjPoolEntry *next;
} ObjPoolEntry;

typedef struct ObjPool {
    /* 0x000 */ VecFx32 playerPos; // the robot's position, stored each frame by Robo021ca458_RunState
    /* 0x00c */ ObjPoolEntry *head;
    /* 0x010 */ ObjPoolEntry entries[16];
} ObjPool;



extern "C" {

// TU2's own .bss scalars (StageRes/StageCmd/ObjPool), laid out from 0x02149efc.
extern u32 data_02149efc;
extern void *gStageLastNode;
extern s32 gStageResSlotTail; // slot ring end
extern u32 gStageResBusy;
extern ObjPool *gStageObjPool;
extern void *gStageLastObj3D;
extern s32 gStageResSlotHead; // slot ring start
extern UnkSys *gSysState;
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *ptr);
extern void Heap_FreeHi(void *ptr);
extern void HitSphere_Unlink_0203f2b8(void *obj);
extern void HitMesh_Detach(void *obj);

void ObjPool_FreeEntry(ObjPool *pool, ObjPoolEntry *entry);

static inline s32 ObjPool_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void ObjPool_Init(ObjPool *pool) {
    int i;
    pool->playerPos.x = 0;
    pool->playerPos.y = 0;
    pool->playerPos.z = 0;
    for (i = 0; i < 16; i++) {
        pool->entries[i].active = 0;
        pool->entries[i].kind = 0;
        pool->entries[i].next = NULL;
    }
    pool->head = NULL;
}

static inline void ObjPool_Reset(ObjPool *pool) {
    ObjPoolEntry *e;
    ObjPoolEntry *next;
    data_02fe1534.unk_10 = 0xffff;
    if (pool->head == NULL) {
        return;
    }
    for (e = pool->head; e != NULL; e = next) {
        next = e->next;
        ObjPool_FreeEntry(pool, e);
    }
    ObjPool_Init(pool);
}

}

#endif
