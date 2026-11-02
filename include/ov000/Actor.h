#ifndef OV000_ACTOR_H
#define OV000_ACTOR_H

#include "ov000/ActorBase.h"
#include "ov000/Vec.h"
#include "Main/Sys/Pad.h"
#include "Main/Sys/Field.h"
#include "nitro/fx.h" // REG_SQRTCNT, REG_SQRT_PARAM, REG_SQRT_RESULT

typedef struct ActorGroup {
    struct ActorGroup *prev;
    struct ActorGroup *next;
    u16 key;
    u16 unk_0a;
    Actor *head;
    Actor *tail;
    u16 serial;
    u16 count;
    PauseNode pause;
} ActorGroup;

typedef struct ActorMgr {
    ActorGroup *head;
    ActorGroup *tail;
    u16 count;
    u16 frame;
    ActorMsg msgs[0x80];
    PauseNode pause;
} ActorMgr;

extern "C" {
extern ActorMgr *data_ov000_021ccd68;
}

static inline void ActorGroup_Remove(ActorGroup *group, Actor *actor);

static inline ActorGroup *ActorMgr_FindGroupIn(ActorMgr *mgr, u16 id) {
    ActorGroup *found = NULL;
    ActorGroup *group = mgr->head;
    u16 key = id & 0xf000;
    if (key == 0xf000) {
        found = group;
    } else {
        for (; group != NULL; group = group->next) {
            if (group->key == key) {
                found = group;
                break;
            }
        }
    }
    return found;
}

static inline ActorGroup *ActorMgr_FindGroup(u16 id) {
    ActorGroup *found = NULL;
    u16 key = id & 0xf000;
    ActorGroup *group = data_ov000_021ccd68->head;
    if (key == 0xf000) {
        found = group;
    } else {
        for (; group != NULL; group = group->next) {
            if (group->key == key) {
                found = group;
                break;
            }
        }
    }
    return found;
}

static inline Actor *ActorMgr_FindActor(u16 id) {
    ActorGroup *group;
    Actor *actor;
    Actor *ret = NULL;
    if (data_ov000_021ccd68 != NULL && id != 0xffff) {
        group = ActorMgr_FindGroup(id);
        if (group != NULL) {
            for (actor = group->head; actor != NULL; actor = actor->next) {
                if (id == actor->id) {
                    ret = actor;
                    break;
                }
            }
        }
    }
    return ret;
}

#define ABS(x) ((x) < 0 ? -(x) : (x))

static inline void CP_SetSqrtImm64_NS_(u64 param) {
    REG_SQRT_PARAM = param;
}

static inline void CP_SetSqrt64(u64 param) {
    REG_SQRTCNT = 1;
    CP_SetSqrtImm64_NS_(param);
}

static inline void CP_WaitSqrt(void) {
    while (REG_SQRTCNT & 0x8000) {
    }
}

static inline u32 CP_GetSqrtResult32(void) {
    return REG_SQRT_RESULT;
}

static inline s32 Dist2D(s64 sq) {
    CP_SetSqrt64((u64)(sq << 2));
    CP_WaitSqrt();
    return (s32)(CP_GetSqrtResult32() + 1) >> 1;
}

static inline s32 DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    return Dist2D((s64)dx * dx + (s64)dz * dz);
}

static inline void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

static inline void ActorGroup_Remove(ActorGroup *group, Actor *actor) {
    Actor *next = actor->next;
    Actor *prev = actor->prev;
    if (actor != NULL) {
        actor->vfunc_24();
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        group->head = next;
    }
    if (next != NULL) {
        next->prev = prev;
    } else {
        group->tail = prev;
    }
    group->count--;
}

typedef struct {
    u8 unk_00[0x78];
    VecFx32 unk_78;
    u8 unk_84[0x30];
} ActorSub38;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 14;
} ActorSub44;

typedef struct {
    void *unk_08;
    s16 unk_0c;
    u8 unk_0e;
} MsgData4;

typedef struct {
    u8 unk_08;
    u8 unk_09;
    s16 unk_0a;
    u8 unk_0c;
} MsgData5;

typedef struct {
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_1a[0x2];
    s32 unk_1c;
} MsgData7;

typedef struct {
    u8 unk_08[0x24];
    VecFx32 unk_2c;
} MsgData8;


extern "C" {
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void ActorGroup_Add(ActorGroup *group, Actor *actor);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_02190e98(void *a, u32 b, s16 c, u8 d);
// Model_02190a30.cpp defines it as (Model0218fe1c *, const char *, s16 blend, u8 force); callers
// here pass the model untyped and the last two as words.
BOOL func_ov000_02190cb0(void *model, const char *name, s32 blend, s32 force);
void func_ov000_021915a0(void *a);
extern char data_ov000_021cc404[];
BOOL func_01ffc4ec(VecFx32 *v, s32 speed, s32 b);
u16 Pad_LookupDir(void *rng, s32 range);
void Actor_Move(Actor *self, s32 turn);
void func_ov000_0218bed8(void *a, s32 b, Actor *actor);
extern void *data_ov000_021ccd64;
BOOL func_01ffc198(VecFx32 *pos, VecFx32 *target, fx32 dist);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, u16 b);
}

#endif
