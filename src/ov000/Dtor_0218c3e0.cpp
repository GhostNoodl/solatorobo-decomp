#include "ov000/LoCommon.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ActorBase.h"
#include "ov000/ActorMarker.h"

#define HEAP_FREE(field)                                  \
    {                                                     \
        void *saved = gSysState->cur;             \
        gSysState->cur = gSysState->heapHi;   \
        if ((field) != NULL) {                            \
            Heap_Free(field);                         \
            (field) = 0;                                  \
        }                                                 \
        gSysState->cur = saved;                   \
    }

extern "C" {
extern u8 Actor_vtbl[];
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
void HitSphere_Unlink_0203f2b8(void *p);
void HitMesh_Unlink_0203f920(void *p);
void HitMesh_Detach(void *p);

// Shared body of the three destructor variants below.
#define DTOR_0218C3E0_BODY(self)                           \
    {                                                      \
    ActorMsg *n;                                           \
    VOBJ_SET_VTABLE(self, Actor_vtbl);            \
    n = (self)->msgs;                                      \
    while (n != NULL) {                                    \
        ActorMsg *next = n->next;                          \
        n->type = 0;                                       \
        n->next = NULL;                                    \
        n = next;                                          \
    }                                                      \
    (self)->msgs = NULL;                                   \
    HEAP_DELETE_FN((self)->model, Model0218fe1c_FreeAnims);    \
    HEAP_DELETE_FN((self)->unk_34, ResSet_ReleaseAll);   \
    HEAP_DELETE_VOBJ((self)->unk_3c);                      \
    HEAP_FREE((self)->fsm);                                \
    HEAP_DELETE_FN((self)->hit, HitSphere_Unlink_0203f2b8);            \
    HEAP_FREE((self)->unk_44);                             \
    HEAP_FREE((self)->targetObj);                          \
    HEAP_FREE((self)->hp);                                 \
    HEAP_FREE((self)->unk_54);                             \
    if ((self)->hitMesh != NULL) {                         \
        HitMesh_Unlink_0203f920((self)->hitMesh);                    \
        HEAP_DELETE_FN((self)->hitMesh, HitMesh_Detach);   \
    }                                                      \
    HEAP_DELETE_MARKER((self)->unk_5c);                    \
    }

Actor *Actor_Dtor(Actor *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}

Actor *Actor_DtorDelete(Actor *self) {
    DTOR_0218C3E0_BODY(self);
    Heap_Free(self);
    return self;
}

Actor *Actor_DtorBase(Actor *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}
}
