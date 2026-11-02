// Built at optimization level 3: at the default level the manager and group
// pointers of the teardown loop swap registers.
#pragma optimization_level 3
#include "ov000/Actor.h"
#include "ov000/HeapScope.h"

extern "C" {

// Deletes the actor manager on the secondary heap: every group, with every
// actor in it, is unlinked and freed, then the manager itself.
void ActorMgr_Destroy(void) {
    Actor *aprev;
    Actor *anext;
    ActorGroup *gnext;
    ActorGroup *gprev;
    void *saved;
    ActorMgr *mgr;
    ActorGroup *group;
    Actor *actor;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    mgr = data_ov000_021ccd68;
    if (mgr != NULL) {
        if (mgr != NULL) {
            while (mgr->head != NULL) {
                group = mgr->head;
                gprev = group->prev;
                gnext = group->next;
                if (group != NULL) {
                    while ((actor = group->head) != NULL) {
                        anext = actor->next;
                        aprev = actor->prev;
                        if (actor != NULL) {
                            actor->vfunc_24();
                        }
                        if (aprev != NULL) {
                            aprev->next = anext;
                        } else {
                            group->head = anext;
                        }
                        if (anext != NULL) {
                            anext->prev = aprev;
                        } else {
                            group->tail = aprev;
                        }
                        group->count--;
                    }
                    group->serial = 1;
                    Heap_Free(group);
                }
                if (gprev != NULL) {
                    gprev->next = gnext;
                } else {
                    mgr->head = gnext;
                }
                if (gnext != NULL) {
                    gnext->prev = gprev;
                } else {
                    mgr->tail = gprev;
                }
                mgr->count--;
            }
            Heap_Free(mgr);
        }
        data_ov000_021ccd68 = NULL;
    }
    data_02097dd0->cur = saved;
}

}
