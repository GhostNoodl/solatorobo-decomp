#ifndef OV000_HEAPSCOPE_H
#define OV000_HEAPSCOPE_H

#include "types.h"
#include "Main/Sys/SysState.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Model;
struct PlttRes; // Main/Gfx/PlttRes.h

void Heap_Free(void *p);
void TexObj_Release(struct Model *model);
void PlttRes_Init_02041218(struct PlttRes *res);
void PlttRes_Release(struct PlttRes *res);

#ifdef __cplusplus
}
#endif

// Switches to the secondary heap, deletes `field` (a pointer of type T) with
// `dtor` (a statement using `p`), clears it, then restores the heap.
#define HEAP_DELETE(T, field, dtor)                       \
    {                                                     \
        void *saved = gSysState->cur;             \
        T p;                                              \
        gSysState->cur = gSysState->heapHi;   \
        p = (T)(field);                                   \
        if (p != NULL) {                                  \
            if (p != NULL) {                              \
                dtor;                                     \
            }                                             \
            (field) = 0;                                  \
        }                                                 \
        gSysState->cur = saved;                   \
    }

#define MODEL_DELETE(p)                \
    TexObj_Release((struct Model *)(p)); \
    PlttRes_Release((struct PlttRes *)((u8 *)(p) + 0x88)); \
    Heap_Free(p)

#define HEAP_DELETE_MODEL(field) HEAP_DELETE(void *, field, MODEL_DELETE(p))
#define HEAP_DELETE_VOBJ(field) HEAP_DELETE(VObj *, field, p->vfunc_04())
#define HEAP_DELETE_FN(field, fn) HEAP_DELETE(void *, field, fn(p); Heap_Free(p))

#endif
