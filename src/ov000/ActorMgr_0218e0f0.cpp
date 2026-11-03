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

void ActorMgr_Create(void) {
    ActorMgr *mgr;
    if (gActorMgr != NULL) {
        return;
    }
    mgr = (ActorMgr *)Heap_Alloc(sizeof(ActorMgr));
    if (mgr != NULL) {
        mgr = ActorMgr_Init(mgr);
    }
    gActorMgr = mgr;
}

}
