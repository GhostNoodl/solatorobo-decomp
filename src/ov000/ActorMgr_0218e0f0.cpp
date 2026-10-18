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

void func_ov000_0218e0f0(void) {
    ActorMgr *mgr;
    if (data_ov000_021ccd68 != NULL) {
        return;
    }
    mgr = (ActorMgr *)func_0203dd9c(sizeof(ActorMgr));
    if (mgr != NULL) {
        mgr = func_ov000_0218e234(mgr);
    }
    data_ov000_021ccd68 = mgr;
}

}
