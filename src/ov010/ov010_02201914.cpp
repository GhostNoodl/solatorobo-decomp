#include "ov010/ov010.h"

// Ov010TaskList is in ov010.h.

extern "C" {

extern u8 data_ov010_0220fe1c[];
extern u8 data_ov010_0220fe08[];
extern void *Ov003Pool_Dtor(void *p);
extern void Ov003Pool_Release(void *p);
extern Ov010TaskNode *Ov003Pool_Alloc(void *p);
extern void Ov003Pool_Free(void *p, Ov010TaskNode *n);
void Ov010TaskList_Clear(Ov010TaskList *o);

Ov010TaskList *Ov010Vt_0220fe1c_Ctor(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    Ov003Pool_Deactivate(o->pool);
    o->b0 = 0;
    return o;
}

Ov010TaskList *Ov010Vt_0220fe1c_Dtor(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    ((VObj *)o)->vfunc_08();
    Ov003Pool_Dtor(o->pool);
    return o;
}

Ov010TaskList *Ov010Vt_0220fe1c_DtorDelete(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    ((VObj *)o)->vfunc_08();
    Ov003Pool_Dtor(o->pool);
    Heap_Free(o);
    return o;
}

#define OV010_TASKLIST_IDLE(o) ((o)->b0 && !(o)->b1)

static inline Ov010TaskNode *Ov010TaskList_Push(Ov010TaskNode *head, Ov010TaskNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}
BOOL Ov010TaskList_Init(Ov010TaskList *o) {
    o->b0 = 1;
    o->b1 = 0;
    o->b2 = 0;
    o->time = 0;
    o->head = NULL;
    Ov003Pool_Init(o->pool, 0xc, 0x10);
    return TRUE;
}

}
