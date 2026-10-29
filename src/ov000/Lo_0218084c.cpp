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
BOOL func_ov000_02198360(void *a, s32 b, s32 c);

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

extern u8 data_0208ccc8[];

static inline BOOL LoTakeMode(void *self) {
    VObj *cur = LFLD(VObj *, data_ov000_021ccd34, 0xc);
    if (LFLD(LoTaskFlags, self, 0).st != 0) {
        if (cur != NULL) {
            LFLD(u32, cur, 4) |= 2;
        }
        if (LFLD(LoTaskFlags, self, 0).st == 1) {
            LFLD(s32, self, 4) = 5;
        } else {
            LFLD(s32, self, 4) = 7;
        }
        LFLD(LoTaskFlags, self, 0).st = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_02180900(void *self) {
    VObj *t;
    VObj *cur;
    u32 saved;
    VObj *next;
    if (LFLD(s32, self, 4) == 0) {
        return FALSE;
    }
    cur = LFLD(VObj *, data_ov000_021ccd34, 0xc);
    switch (LFLD(s32, self, 4)) {
    case 1:
        LFLD(s32, self, 4) = 2;
    case 2:
        LFLD(s32, self, 4) = 3;
    case 3:
        LFLD(s32, self, 0x4c) = 7;
        ((VObj *)((u8 *)self + 8))->vfunc_1c(LFLD(void *, data_0208ccc8, 0));
        LFLD(s32, self, 4) = 12;
        break;
    case 12:
        if (!LoTakeMode(self)) {
            if (LFLD(LoTaskFlags, self, 0).b0) {
                if (cur != NULL) {
                    cur->vfunc_0c(0);
                }
            } else {
                LFLD(u8, data_ov000_021ccd34, 0) = 0;
            }
        }
        break;
    case 5:
        LFLD(VObj *, self, 0x54)->vfunc_10();
        LFLD(s32, self, 4) = 6;
    case 6:
        if (!LFLD(VObj *, self, 0x54)->vfunc_14()) {
            break;
        }
        LFLD(s32, self, 4) = 7;
    case 7:
        if (cur != NULL) {
            break;
        }
        for (t = LFLD(VObj *, data_ov000_021ccd34, 8); t != NULL; t = next) {
            next = LFLD(VObj *, t, 0x38);
            if (LBIT(t, 4).b2) {
                if (LFLD(VObj *, t, 0x34) != NULL) {
                    LFLD(VObj *, LFLD(VObj *, t, 0x34), 0x38) = next;
                } else {
                    LFLD(VObj *, data_ov000_021ccd34, 8) = next;
                }
                if (LFLD(VObj *, t, 0x38) != NULL) {
                    LFLD(VObj *, LFLD(VObj *, t, 0x38), 0x34) = LFLD(VObj *, t, 0x34);
                }
                LFLD(VObj *, t, 0x34) = NULL;
                LFLD(VObj *, t, 0x38) = NULL;
                LO_HEAP_PUSH(saved);
                if (t != NULL) {
                    if (t != NULL) {
                        t->vfunc_04();
                    }
                }
                LO_HEAP_POP(saved);
            }
        }
        if (!LoTakeMode(self)) {
            if (LFLD(VObj *, self, 0x54) != NULL) {
                LFLD(VObj *, self, 0x54)->vfunc_50();
                LFLD(VObj *, self, 0x54)->vfunc_18();
                LFLD(VObj *, self, 0x54) = NULL;
                LFLD(s32, self, 4) = 12;
                break;
            }
            LFLD(s32, data_ov000_021ccd34, 4) = 0;
            LFLD(s32, self, 4) = 0;
            LFLD(LoTaskFlags, self, 0).b1 = 1;
            return FALSE;
        }
        break;
    }
    for (t = LFLD(VObj *, data_ov000_021ccd34, 8); t != NULL; t = next) {
        next = LFLD(VObj *, t, 0x38);
        t->vfunc_68();
    }
    return TRUE;
}

}
