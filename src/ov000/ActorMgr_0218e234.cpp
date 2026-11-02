#include "ov000/Actor.h"
#include "Main/Sys/SysState.h"

extern "C" {


void *Heap_Alloc(u32 size);
void Heap_Free(void *ptr);
void PauseNode_Init(PauseNode *node);
BOOL PauseNode_IsUpdatePaused(PauseNode *node, s32 a);
BOOL PauseNode_IsDrawPaused(PauseNode *node, s32 a);
void Actor_Tick(Actor *actor);
ActorMgr *ActorMgr_Init(ActorMgr *mgr);

static inline void ActorGroup_Delete(ActorGroup *group) {
    while (group->head != NULL) {
        ActorGroup_Remove(group, group->head);
    }
    group->serial = 1;
    Heap_Free(group);
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
    Heap_Free(mgr);
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

ActorMgr *ActorMgr_Init(ActorMgr *mgr) {
    s32 i;
    u16 key;
    ActorGroup *group;
    ActorGroup *tail;
    PauseNode_Init(&mgr->pause);
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
        group = (ActorGroup *)Heap_Alloc(sizeof(ActorGroup));
        if (group != NULL) {
            PauseNode_Init(&group->pause);
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

void ActorMgr_Update(ActorMgr *mgr) {
    ActorGroup *group;
    Actor *next;
    Actor *actor;
    if (PauseNode_IsUpdatePaused(&mgr->pause, 1)) {
        return;
    }
    mgr->frame++;
    for (group = mgr->head; group != NULL; group = group->next) {
        if (PauseNode_IsUpdatePaused(&group->pause, 1)) {
            continue;
        }
        for (actor = group->head; actor != NULL; actor = next) {
            next = actor->next;
            if (!PauseNode_IsUpdatePaused(&actor->pause, 1)) {
                Actor_Tick(actor);
            }
        }
    }
}

void ActorMgr_Draw(ActorMgr *mgr) {
    ActorGroup *group;
    Actor *actor;
    if (PauseNode_IsDrawPaused(&mgr->pause, 1)) {
        return;
    }
    for (group = mgr->head; group != NULL; group = group->next) {
        if (PauseNode_IsDrawPaused(&group->pause, 1)) {
            continue;
        }
        for (actor = group->head; actor != NULL; actor = actor->next) {
            if (!PauseNode_IsDrawPaused(&actor->pause, 1) && actor->state == 2) {
                actor->vfunc_00();
            }
        }
    }
}

BOOL ActorMgr_IsReady(ActorMgr *mgr) {
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

ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 id) {
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

void ActorMgr_ClearGroup(ActorMgr *mgr, u16 id) {
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

Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id) {
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

Actor *ActorMgr_FindKind(ActorMgr *mgr, u16 id, u16 kind) {
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

Actor *ActorMgr_FindKindNear(ActorMgr *mgr, u16 id, u16 kind, VecFx32 *pos, s32 dist) {
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

u16 ActorMgr_CountActors(ActorMgr *mgr, u16 id) {
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

void ActorMgr_DestroyAll(ActorMgr *mgr) {
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
            Actor_SendMsg(actor, 0xffff, 2, 1, 1, &buf);
        }
    }
}

}
