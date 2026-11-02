#include "ov000/LoCommon.h"
#include "ov000/VObj.h"
#include "ov000/HeapScope.h"


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

typedef struct Link0218c3e0 {
    struct Link0218c3e0 *next;
    u8 unk_04;
    u8 unk_05;
} Link0218c3e0;

extern "C" {
extern u8 data_ov000_021cc3b4[];
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_0203f2b8(void *p);
void func_0203f920(void *p);
void HitMesh_Detach(void *p);
void func_ov000_021bd228(void *p);

// Shared body of the three destructor variants below.
#define DTOR_0218C3E0_BODY(self)                           \
    {                                                      \
    Link0218c3e0 *n;                                       \
    VOBJ_SET_VTABLE(self, data_ov000_021cc3b4);                    \
    n = LFLD(Link0218c3e0 *, self, 0x2c);                           \
    while (n != NULL) {                                    \
        Link0218c3e0 *next = n->next;                      \
        n->unk_05 = 0;                                     \
        n->next = NULL;                                    \
        n = next;                                          \
    }                                                      \
    LFLD(Link0218c3e0 *, self, 0x2c) = NULL;                        \
    HEAP_DELETE_FN(LFLD(void *, self, 0x38), func_ov000_0218fee4);  \
    HEAP_DELETE_FN(LFLD(void *, self, 0x34), func_ov000_0218ea20);  \
    HEAP_DELETE_VOBJ(LFLD(VObj *, self, 0x3c));                     \
    HEAP_FREE(LFLD(void *, self, 0x40));                            \
    HEAP_DELETE_FN(LFLD(void *, self, 0x48), func_0203f2b8);        \
    HEAP_FREE(LFLD(void *, self, 0x44));                            \
    HEAP_FREE(LFLD(void *, self, 0x4c));                            \
    HEAP_FREE(LFLD(void *, self, 0x50));                            \
    HEAP_FREE(LFLD(void *, self, 0x54));                            \
    if (LFLD(void *, self, 0x58) != NULL) {                         \
        func_0203f920(LFLD(void *, self, 0x58));                    \
        HEAP_DELETE_FN(LFLD(void *, self, 0x58), HitMesh_Detach);    \
    }                                                      \
    HEAP_DELETE_FN(LFLD(void *, self, 0x5c), func_ov000_021bd228);  \
    }

u8 *Actor_Dtor(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}

u8 *Actor_DtorDelete(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    Heap_Free(self);
    return self;
}

u8 *func_ov000_0218c928(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}
}
