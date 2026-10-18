#ifndef OV000_ACTOR_H
#define OV000_ACTOR_H

#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct ActorMsg {
    struct ActorMsg *next;
    u8 unk_04;
    u8 type;
    u16 id;
    u8 data[0x30];
} ActorMsg;

class Actor;

typedef struct PauseNode {
    struct PauseNode *parent;
    u32 unk_04;
} PauseNode;

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

typedef struct {
    ActorGroup *head;
    ActorGroup *tail;
    u16 count;
    u16 frame;
    ActorMsg msgs[0x80];
    PauseNode pause;
} ActorMgr;

typedef struct {
    u8 unk_00[0x1c];
    u16 unk_1c;
} ActorSub4c;

class Actor : public VObj {
public:
    Actor *prev;
    Actor *next;
    u16 id;
    u16 kind;
    s32 unk_10;
    u8 state;
    u8 unk_15;
    u8 flags_0 : 1;
    u8 flags_1 : 1;
    u8 flags_2 : 6;
    u8 unk_17[0x9];
    u16 unk_20;
    u8 unk_22[0x2];
    PauseNode pause;
    ActorMsg *msgs;
    u32 msg_flags;
    u8 unk_34[0x4];
    void *unk_38;
    u8 unk_3c[0x4];
    void *unk_40;
    void *unk_44;
    u8 unk_48[0x4];
    ActorSub4c *unk_4c;
    u8 unk_50[0x14];
    s32 unk_64;
    u8 unk_68[0x8];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[0xe];
    u16 target;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 7;
    u8 unk_94[0x4];
    u16 unk_98;
    u8 unk_9a[0x2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

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

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

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
    u8 unk_00[0x4];
    u64 flags;
    u8 unk_0c[0x7];
    u8 unk_13;
} ActorSub40;

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

typedef struct {
    u8 unk_00[0x10];
    u16 unk_10;
} Rng02097dc8;

typedef struct {
    u8 unk_00[0x4];
    VecFx32 pos;
} Player021ccd54Sub;

typedef struct {
    u8 unk_00[0xf4];
    Player021ccd54Sub unk_f4;
} Player021ccd54;

extern "C" {
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void func_ov000_0218de6c(ActorGroup *group, Actor *actor);
void func_ov000_0218d398(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
u16 FX_Atan2(s32 x, s32 z);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_02190e98(void *a, u32 b, s32 c, s32 d);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void MI_Copy36B(const void *src, void *dst);
extern u8 data_ov000_021cc404[];
BOOL func_01ffc4ec(VecFx32 *v, s32 speed, s32 b);
s32 func_0203d434(void *rng, s32 range);
void func_ov000_0218dbe0(Actor *self, s32 turn);
extern Rng02097dc8 *data_02097dc8;
void func_ov000_0218bed8(void *a, s32 b, Actor *actor);
extern Player021ccd54 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
BOOL func_01ffc198(void *pos, void *target, s32 dist);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
}

#endif
