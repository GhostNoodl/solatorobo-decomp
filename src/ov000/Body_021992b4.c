#include "types.h"
#include "ov000/Vec.h"

typedef struct {
    VecFx32 pos;
    VecFx32 prev;
    VecFx32 unk_18;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26[0xa];
    u32 unk_30;
    u32 unk_34;
    s32 unk_38;
    u8 unk_3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    VecFx32 offset;
    VecFx32 check;
    VecFx32 unk_74;
    VecFx32 normal;
    VecFx32 target;
    u16 unk_98;
    u16 unk_9a_0 : 3;
    u16 unk_9a_3 : 1;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
    u16 unk_9a_6 : 1;
    u16 unk_9a_7 : 1;
    u16 unk_9a_8 : 1;
    u16 unk_9a_9 : 1;
    u16 unk_9a_10 : 6;
} Body;

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
} ActorC;

typedef struct ActorMgr ActorMgr;

extern ActorMgr *data_ov000_021ccd68;

ActorC *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void func_01ffc9fc(VecFx32 *out, const VecFx32 *in, u32 angle);
void func_02012be8(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *offset, u32 angle);
u16 func_0201319c(s32 x, s32 z);
s32 func_02012ab8(s32 num, s32 den);
void func_02012fb8(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
void func_02012d78(const VecFx32 *src, VecFx32 *dst);
u16 func_02013330(s32 x);

static inline ActorC *FindActor(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline void VEC_Set(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Dot(const VecFx32 *a, const VecFx32 *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

typedef struct {
    s32 prev;
    s32 next;
} SortLink;

typedef struct {
    u8 unk_00[0x20];
    u16 owner;
} Part;

typedef struct ActorL {
    const void *vtbl;
    struct ActorL *prev;
    struct ActorL *next;
    u16 id;
    u16 kind;
    u8 unk_10[0x34];
    Part *part;
    u8 unk_48[0x28];
    VecFx32 pos;
} ActorL;

typedef struct GroupL {
    struct GroupL *prev;
    struct GroupL *next;
    u16 key;
    u16 unk_0a;
    ActorL *head;
} GroupL;

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
} Query;

typedef struct {
    Query *query;
} Finder;

GroupL *func_ov000_0218e4cc(ActorMgr *mgr, u16 key);
BOOL func_ov000_02199684(Finder *self, ActorL *actor);
ActorL *func_ov000_02199000(Finder *self, Query *q, ActorL *from);

static inline BOOL Query_MatchKind(Query *q, ActorL *a) {
    if (q->kind != 0xffff && q->kind != a->kind) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_021997e8(Finder *self, Part *part);
Part *func_ov000_021992b4(Finder *self, Query *q, Part *from);

static inline s32 Finder_FindAll(Finder *self, Query *q, ActorL **out, s32 max) {
    s32 n = 0;
    ActorL *actor;

    if (q != NULL) {
        actor = NULL;
        for (; n < max; n++) {
            actor = func_ov000_02199000(self, q, actor);
            if (actor == NULL) {
                break;
            }
            out[n] = actor;
        }
    }
    return n;
}

Part *func_ov000_021992b4(Finder *self, Query *q, Part *from) {
    u32 mask;
    GroupL *group;
    Part *part;
    ActorL *actor;

    if (q == NULL) {
        return NULL;
    }
    self->query = q;
    mask = q->mask;
    group = NULL;
    actor = NULL;
    if (mask == 0) {
        mask = 0xffff;
    }
    if (from != NULL) {
        {
            u16 id = from->owner;
            ActorMgr *mgr = data_ov000_021ccd68;
            if (mgr != NULL) {
                actor = (ActorL *)func_ov000_0218e640(mgr, id);
            }
        }
        if (actor != NULL) {
            group = func_ov000_0218e4cc(data_ov000_021ccd68, actor->id & 0xf000);
            actor = actor->next;
        }
        if (actor == NULL && group != NULL) {
            group = group->next;
        }
    } else {
        group = func_ov000_0218e4cc(data_ov000_021ccd68, 0xf000);
    }
    for (; group != NULL; group = group->next) {
        if (mask & (1 << (group->key >> 12))) {
            if (actor == NULL) {
                actor = group->head;
            }
            for (; actor != NULL; actor = actor->next) {
                if (Query_MatchKind(self->query, actor)) {
                    part = actor->part;
                    if (part != NULL && func_ov000_021997e8(self, part)) {
                        return part;
                    }
                }
            }
        }
    }
    return NULL;
}

s32 func_ov000_021993fc(Finder *self, Query *q, ActorL **out, s32 max) {
    s32 n;
    ActorL *actor;

    if (q == NULL) {
        return 0;
    }
    n = 0;
    actor = NULL;
    for (; n < max; n++) {
        actor = (ActorL *)func_ov000_021992b4(self, q, (Part *)actor);
        if (actor == NULL) {
            break;
        }
        out[n] = actor;
    }
    return n;
}

s32 func_ov000_02199454(Finder *self, Query *q, Part **list, s32 count) {
    Part *tmp[32];
    s32 n;
    s32 i;
    Part *part;
    ActorL *actor;

    if (q == NULL) {
        return 0;
    }
    n = 0;
    self->query = q;
    for (i = 0; i < count; i++) {
        part = list[i];
        if (part == NULL) {
            continue;
        }
        actor = (ActorL *)FindActor(part->owner);
        if (actor == NULL) {
            continue;
        }
        if (!Query_MatchKind(self->query, actor)) {
            continue;
        }
        if (!func_ov000_021997e8(self, part)) {
            continue;
        }
        tmp[n] = part;
        n++;
        if (n >= 32) {
            break;
        }
    }
    for (i = 0; i < n; i++) {
        list[i] = tmp[i];
    }
    return n;
}
