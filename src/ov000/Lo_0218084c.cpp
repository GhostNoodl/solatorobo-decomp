#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    u8 flags;
} Query;

typedef struct {
    Query *query;
} Finder;

typedef struct {
    Finder finder;
    Query q;
} FinderQuery;

extern "C" {
s32 func_ov000_021993fc(Finder *self, Query *q, void **out, s32 max);
s32 func_ov000_02199128(Finder *self, Query *q, void **out, s32 max);
void func_ov000_02198360(void *a, s32 b, s32 c);

void *func_ov000_0218084c(void *cur, s32 kind, s32 c) {
    s32 st;
    LFLD(u8, data_ov000_021ccd34, 0) = 1;
    LFLD(void *, cur, 0x54) = LoFindTask(kind);
    if (LFLD(void *, cur, 0x54) == NULL) {
        LoCreateFn fn = data_ov000_021c9c6c[kind];
        LFLD(void *, cur, 0x54) = fn != NULL ? fn() : NULL;
        LFLD(s32, LFLD(void *, cur, 0x54), 0xc) = c;
        LFLD(s32, LFLD(void *, cur, 0x54), 0x2c) = LFLD(s32, data_ov000_021ccd34, 0xc);
        st = 1;
    } else {
        st = 2;
    }
    if (LFLD(void *, cur, 0x54) != NULL) {
        LFLD(LoTaskFlags, cur, 0).st = st;
    }
    return LFLD(void *, cur, 0x54);
}

static inline Actor *MgrFind(ActorMgr *mgr, u16 id) {
    ActorGroup *group;
    Actor *actor;
    Actor *ret = NULL;
    if (id != 0xffff) {
        group = ActorMgr_FindGroupIn(mgr, id);
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

static inline Actor *FindActor2(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    return mgr != NULL ? MgrFind(mgr, id) : NULL;
}

}
