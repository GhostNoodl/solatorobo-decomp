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

#define OV010_TASKLIST_IDLE(o) ((o)->b0 && !(o)->b1)

static inline Ov010TaskNode *Ov010TaskList_Push(Ov010TaskNode *head, Ov010TaskNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

BOOL Ov010TaskList_IsIdle(Ov010TaskList *o) {
    if (o->b0 && !o->b1) {
        return TRUE;
    }
    return FALSE;
}

BOOL Ov010TaskList_IsFinished(Ov010TaskList *o) {
    if (o->b0 && o->b2) {
        return TRUE;
    }
    return FALSE;
}

void func_ov010_02201c84(void) {
}

void *Ov010Vt_0220fe08_DtorDelete(void *o) {
    Heap_Free(o);
    return o;
}

Ov010Task *Ov010Vt_0220fe08_New(void) {
    Ov010Task *p = (Ov010Task *)Heap_Alloc(sizeof(Ov010Task));
    if (p != NULL) {
        p->vtbl = data_ov010_0220fe08;
        p->b0 = 0;
    }
    return p;
}

}
