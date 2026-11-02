#include "ov000/LoCommon.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ActorBase.h"
#include "ov000/ActorMarker.h"

#define HEAP_FREE(field)                                  \
    {                                                     \
        void *saved = data_02097dd0->cur;             \
        data_02097dd0->cur = data_02097dd0->heapHi;   \
        if ((field) != NULL) {                            \
            Heap_Free(field);                         \
            (field) = 0;                                  \
        }                                                 \
        data_02097dd0->cur = saved;                   \
    }

extern "C" {
extern u8 data_ov000_021cc3b4[];
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_0203f2b8(void *p);
void func_0203f920(void *p);
void HitMesh_Detach(void *p);

// Shared body of the three destructor variants below.
#define DTOR_0218C3E0_BODY(self)                           \
    {                                                      \
    ActorMsg *n;                                           \
    VOBJ_SET_VTABLE(self, data_ov000_021cc3b4);            \
    n = (self)->msgs;                                      \
    while (n != NULL) {                                    \
        ActorMsg *next = n->next;                          \
        n->type = 0;                                       \
        n->next = NULL;                                    \
        n = next;                                          \
    }                                                      \
    (self)->msgs = NULL;                                   \
    HEAP_DELETE_FN((self)->model, func_ov000_0218fee4);    \
    HEAP_DELETE_FN((self)->unk_34, func_ov000_0218ea20);   \
    HEAP_DELETE_VOBJ((self)->unk_3c);                      \
    HEAP_FREE((self)->fsm);                                \
    HEAP_DELETE_FN((self)->hit, func_0203f2b8);            \
    HEAP_FREE((self)->unk_44);                             \
    HEAP_FREE((self)->targetObj);                          \
    HEAP_FREE((self)->hp);                                 \
    HEAP_FREE((self)->unk_54);                             \
    if ((self)->hitMesh != NULL) {                         \
        func_0203f920((self)->hitMesh);                    \
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

Actor *func_ov000_0218c928(Actor *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}
}
