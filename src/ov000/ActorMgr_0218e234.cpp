#include "ov000/Actor.h"

typedef struct {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

extern "C" {

extern HeapState *data_02097dd0;

void *func_0203dd9c(u32 size);
void func_0203de1c(void *ptr);
void func_0203db10(PauseNode *node);
BOOL func_0203dbb0(PauseNode *node, s32 a);
BOOL func_0203dc9c(PauseNode *node, s32 a);
void func_ov000_0218cbc8(Actor *actor);
ActorMgr *func_ov000_0218e234(ActorMgr *mgr);

static inline void ActorGroup_Delete(ActorGroup *group) {
    while (group->head != NULL) {
        ActorGroup_Remove(group, group->head);
    }
    group->serial = 1;
    func_0203de1c(group);
}

static inline void ActorMgr_RemoveGroup(ActorMgr *mgr, ActorGroup *group) {
    ActorGroup *prev = group->prev;
    ActorGroup *next = group->next;
    if (group != NULL) {
        ActorGroup_Delete(group);
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        mgr->head = next;
    }
    if (next != NULL) {
        next->prev = prev;
    } else {
        mgr->tail = prev;
    }
    mgr->count--;
}

static inline void ActorMgr_Delete(ActorMgr *mgr) {
    while (mgr->head != NULL) {
        ActorMgr_RemoveGroup(mgr, mgr->head);
    }
    func_0203de1c(mgr);
}

static inline void ActorGroup_Clear(ActorGroup *group) {
    while (group->head != NULL) {
        ActorGroup_Remove(group, group->head);
    }
    group->serial = 1;
}

static inline ActorGroup *FindGroup_e8ec(ActorMgr *mgr, u16 id) {
    ActorGroup *found = NULL;
    ActorGroup *group;
    id = (u16)(id & 0xf000);
    group = mgr->head;
    if (id == 0xf000) {
        found = group;
    } else {
        for (; group != NULL; group = group->next) {
            if (group->key == id) {
                found = group;
                break;
            }
        }
    }
    return found;
}

typedef struct {
    u32 unk_00;
    u8 unk_04;
    u8 unk_05[0x1f];
    u8 unk_24;
    u8 unk_25[0x17];
} Sub0218e9c4;

typedef struct {
    s16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    u32 unk_08;
    Sub0218e9c4 entries[5];
} Obj0218e9c4;

static inline void Sub0218e9c4_Init(Sub0218e9c4 *entry) {
    entry->unk_00 = 0;
    entry->unk_04 = 0;
    entry->unk_24 = 0;
}

ActorMgr *func_ov000_0218e234(ActorMgr *mgr) {
    s32 i;
    u16 key;
    ActorGroup *group;
    ActorGroup *tail;
    func_0203db10(&mgr->pause);
    mgr->head = NULL;
    mgr->tail = NULL;
    mgr->count = 0;
    mgr->frame = 0;
    for (i = 0; i < 0x80; i++) {
        mgr->msgs[i].next = NULL;
        mgr->msgs[i].unk_04 = i;
        mgr->msgs[i].type = 0;
    }
    if (data_ov000_021ccd54 != NULL) {
        mgr->pause.parent = (PauseNode *)((u8 *)data_ov000_021ccd54 + 8);
    }
    for (key = 1; key < 9; key++) {
        group = (ActorGroup *)func_0203dd9c(sizeof(ActorGroup));
        if (group != NULL) {
            func_0203db10(&group->pause);
            group->prev = NULL;
            group->next = NULL;
            group->key = 0xf000;
            group->head = NULL;
            group->tail = NULL;
            group->serial = 1;
            group->count = 0;
        }
        group->key = key << 12;
        group->pause.parent = &mgr->pause;
        tail = mgr->tail;
        if (tail != NULL) {
            tail->next = group;
        } else {
            mgr->head = group;
        }
        group->prev = tail;
        group->next = NULL;
        mgr->tail = group;
        mgr->count++;
    }
    return mgr;
}

void func_ov000_0218e338(ActorMgr *mgr) {
    ActorGroup *group;
    Actor *next;
    Actor *actor;
    if (func_0203dbb0(&mgr->pause, 1)) {
        return;
    }
    mgr->frame++;
    for (group = mgr->head; group != NULL; group = group->next) {
        if (func_0203dbb0(&group->pause, 1)) {
            continue;
        }
        for (actor = group->head; actor != NULL; actor = next) {
            next = actor->next;
            if (!func_0203dbb0(&actor->pause, 1)) {
                func_ov000_0218cbc8(actor);
            }
        }
    }
}

void func_ov000_0218e3d4(ActorMgr *mgr) {
    ActorGroup *group;
    Actor *actor;
    if (func_0203dc9c(&mgr->pause, 1)) {
        return;
    }
    for (group = mgr->head; group != NULL; group = group->next) {
        if (func_0203dc9c(&group->pause, 1)) {
            continue;
        }
        for (actor = group->head; actor != NULL; actor = actor->next) {
            if (!func_0203dc9c(&actor->pause, 1) && actor->state == 2) {
                actor->vfunc_00();
            }
        }
    }
}

BOOL func_ov000_0218e470(ActorMgr *mgr) {
    BOOL ret = TRUE;
    ActorGroup *group;
    Actor *actor;
    for (group = mgr->head; group != NULL; group = group->next) {
        for (actor = group->head; actor != NULL; actor = actor->next) {
            if (!actor->vfunc_0c()) {
                ret = FALSE;
            }
        }
    }
    return ret;
}

ActorGroup *func_ov000_0218e4cc(ActorMgr *mgr, u16 id) {
    ActorGroup *found = NULL;
    ActorGroup *group;
    id = (u16)(id & 0xf000);
    group = mgr->head;
    if (id == 0xf000) {
        found = group;
    } else {
        for (; group != NULL; group = group->next) {
            if (group->key == id) {
                found = group;
                break;
            }
        }
    }
    return found;
}

void func_ov000_0218e514(ActorMgr *mgr, u16 id) {
    ActorGroup *group;
    if (id == 0xf000) {
        for (group = mgr->head; group != NULL; group = group->next) {
            ActorGroup_Clear(group);
        }
        return;
    }
    group = ActorMgr_FindGroupIn(mgr, id);
    if (group == NULL) {
        return;
    }
    ActorGroup_Clear(group);
}

Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id) {
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

Actor *func_ov000_0218e6d0(ActorMgr *mgr, u16 id, u16 kind) {
    Actor *ret = NULL;
    ActorGroup *group = ActorMgr_FindGroupIn(mgr, id);
    Actor *actor;
    if (group != NULL) {
        for (actor = group->head; actor != NULL; actor = actor->next) {
            if (kind == actor->kind) {
                ret = actor;
                break;
            }
        }
    }
    return ret;
}

Actor *func_ov000_0218e750(ActorMgr *mgr, u16 id, u16 kind, VecFx32 *pos, s32 dist) {
    Actor *ret = NULL;
    ActorGroup *group = ActorMgr_FindGroupIn(mgr, id);
    Actor *actor;
    if (group != NULL) {
        for (actor = group->head; actor != NULL; actor = actor->next) {
            if (kind == 0xffff || kind == actor->kind) {
                if (func_01ffc198(&actor->pos, pos, dist + actor->unk_64)) {
                    ret = actor;
                    break;
                }
            }
        }
    }
    return ret;
}

u16 func_ov000_0218e808(ActorMgr *mgr, u16 id) {
    ActorGroup *group;
    u16 count = 0;
    if (id == 0xf000) {
        for (group = mgr->head; group != NULL; group = group->next) {
            count += group->count;
        }
    } else {
        group = ActorMgr_FindGroupIn(mgr, id);
        if (group != NULL) {
            count = group->count;
        }
    }
    return count;
}

void func_ov000_0218e894(ActorMgr *mgr) {
    ActorGroup *group;
    Actor *actor;
    Actor *next;
    for (group = mgr->head; group != NULL; group = group->next) {
        for (actor = group->head; actor != NULL; actor = next) {
            next = actor->next;
            actor->vfunc_10();
        }
        if (group->count == 0) {
            group->serial = 1;
        }
    }
}

static inline ActorGroup *FindGroupX(ActorMgr *mgr, u16 id) {
    u16 key = id & 0xf000;
    ActorGroup *group = mgr->head;
    ActorGroup *found = NULL;
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

void func_ov000_0218e8ec(void *self, u16 kind, s32 type) {
    ActorGroup *group = FindGroupX(data_ov000_021ccd68, (u16)(kind & 0xf000));
    Actor *actor;
    if (group == NULL || (actor = group->head) == NULL) {
        return;
    }
    for (; actor != NULL; actor = actor->next) {
        if (kind == 0xffff || kind == actor->kind) {
            u8 buf = type;
            func_ov000_0218d398(actor, 0xffff, 2, 1, 1, &buf);
        }
    }
}

}
