#ifndef MAIN_GFX_OBJPOOL_H
#define MAIN_GFX_OBJPOOL_H

#include "types.h"
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
    /* 0x000 */ u32 unk_00;
    /* 0x004 */ u32 unk_04;
    /* 0x008 */ u32 unk_08;
    /* 0x00c */ ObjPoolEntry *head;
    /* 0x010 */ ObjPoolEntry entries[16];
} ObjPool;

typedef struct ObjPoolGlobals {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u8 unk_04[4];
    /* 0x08 */ s32 slotEnd;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ ObjPool *pool;
    /* 0x14 */ u8 unk_14[4];
    /* 0x18 */ s32 slotStart;
} ObjPoolGlobals;

typedef struct ObjPoolShared {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u8 unk_12[0x22];
    /* 0x34 */ u16 posFlags;
    /* 0x36 */ s16 posX;
    /* 0x38 */ s16 posY;
    /* 0x3a */ s16 posZ;
    /* 0x3c */ u16 unk_3c;
    /* 0x3e */ u16 unk_3e;
    /* 0x40 */ u16 unk_40;
    /* 0x42 */ u16 unk_42;
    /* 0x44 */ u16 unk_44;
    /* 0x46 */ u16 r;
    /* 0x48 */ u16 g;
    /* 0x4a */ u16 b;
    /* 0x4c */ u8 unk_4c[0x24];
    /* 0x70 */ u16 unk_70;
    /* 0x72 */ u8 unk_72[0xe];
    /* 0x80 */ u16 unk_80;
} ObjPoolShared;

extern "C" {

extern ObjPoolGlobals data_02149efc;
extern ObjPoolShared data_02fe1534;
extern UnkSys *data_02097dd0;
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *ptr);
extern void func_0203df0c(void *ptr);
extern void func_0203f2b8(void *obj);
extern void func_0203f864(void *obj);

void func_020599f4(ObjPool *pool, ObjPoolEntry *entry);

static inline s32 ObjPool_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void ObjPool_Init(ObjPool *pool) {
    int i;
    pool->unk_00 = 0;
    pool->unk_04 = 0;
    pool->unk_08 = 0;
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
        func_020599f4(pool, e);
    }
    ObjPool_Init(pool);
}

}

#endif
