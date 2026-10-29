#include "ov000/VObj.h"
#include "ov000/HeapScope.h"

#define F(type, off) (*(type *)((u8 *)self + (off)))

#define HEAP_FREE(field)                                  \
    {                                                     \
        void *saved = data_02097dd0->current;             \
        data_02097dd0->current = data_02097dd0->unk_08;   \
        if ((field) != NULL) {                            \
            func_0203de1c(field);                         \
            (field) = 0;                                  \
        }                                                 \
        data_02097dd0->current = saved;                   \
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
void func_0203f864(void *p);
void func_ov000_021bd228(void *p);

// Shared body of the three destructor variants below.
#define DTOR_0218C3E0_BODY(self)                           \
    {                                                      \
    Link0218c3e0 *n;                                       \
    F(void *, 0) = data_ov000_021cc3b4;                    \
    n = F(Link0218c3e0 *, 0x2c);                           \
    while (n != NULL) {                                    \
        Link0218c3e0 *next = n->next;                      \
        n->unk_05 = 0;                                     \
        n->next = NULL;                                    \
        n = next;                                          \
    }                                                      \
    F(Link0218c3e0 *, 0x2c) = NULL;                        \
    HEAP_DELETE_FN(F(void *, 0x38), func_ov000_0218fee4);  \
    HEAP_DELETE_FN(F(void *, 0x34), func_ov000_0218ea20);  \
    HEAP_DELETE_VOBJ(F(VObj *, 0x3c));                     \
    HEAP_FREE(F(void *, 0x40));                            \
    HEAP_DELETE_FN(F(void *, 0x48), func_0203f2b8);        \
    HEAP_FREE(F(void *, 0x44));                            \
    HEAP_FREE(F(void *, 0x4c));                            \
    HEAP_FREE(F(void *, 0x50));                            \
    HEAP_FREE(F(void *, 0x54));                            \
    if (F(void *, 0x58) != NULL) {                         \
        func_0203f920(F(void *, 0x58));                    \
        HEAP_DELETE_FN(F(void *, 0x58), func_0203f864);    \
    }                                                      \
    HEAP_DELETE_FN(F(void *, 0x5c), func_ov000_021bd228);  \
    }

u8 *func_ov000_0218c3e0(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}

u8 *func_ov000_0218c680(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    func_0203de1c(self);
    return self;
}

u8 *func_ov000_0218c928(u8 *self) {
    DTOR_0218C3E0_BODY(self);
    return self;
}
}
