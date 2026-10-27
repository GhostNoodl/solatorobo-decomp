#ifndef OV000_HEAPSCOPE_H
#define OV000_HEAPSCOPE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HeapState {
    void *current;
    void *unk_04;
    void *unk_08;
} HeapState;

struct Model;

extern HeapState *data_02097dd0;
void func_0203de1c(void *p);
void func_02041558(struct Model *model);
void func_02041278(void *p);

#ifdef __cplusplus
}
#endif

// Switches to the secondary heap, deletes `field` (a pointer of type T) with
// `dtor` (a statement using `p`), clears it, then restores the heap.
#define HEAP_DELETE(T, field, dtor)                       \
    {                                                     \
        void *saved = data_02097dd0->current;             \
        T p;                                              \
        data_02097dd0->current = data_02097dd0->unk_08;   \
        p = (T)(field);                                   \
        if (p != NULL) {                                  \
            if (p != NULL) {                              \
                dtor;                                     \
            }                                             \
            (field) = 0;                                  \
        }                                                 \
        data_02097dd0->current = saved;                   \
    }

#define MODEL_DELETE(p)                \
    func_02041558((struct Model *)(p)); \
    func_02041278((u8 *)(p) + 0x88);   \
    func_0203de1c(p)

#define HEAP_DELETE_MODEL(field) HEAP_DELETE(void *, field, MODEL_DELETE(p))
#define HEAP_DELETE_VOBJ(field) HEAP_DELETE(VObj *, field, p->vfunc_04())
#define HEAP_DELETE_FN(field, fn) HEAP_DELETE(void *, field, fn(p); func_0203de1c(p))

#endif
