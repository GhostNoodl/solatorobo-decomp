#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

// Ov010TaskList is in ov010.h.

extern "C" {

extern u8 data_ov010_0220fe1c[];
extern u8 data_ov010_0220fe08[];
extern Ov010Heap *data_02097dd0;
extern void *Ov003Pool_Dtor(void *p);
extern void Ov003Pool_Release(void *p);
extern Ov010TaskNode *Ov003Pool_Alloc(void *p);
extern void Ov003Pool_Free(void *p, Ov010TaskNode *n);
void func_ov010_02201b48(Ov010TaskList *o);

#define OV010_TASKLIST_IDLE(o) ((o)->b0 && !(o)->b1)

static inline Ov010TaskNode *Ov010TaskList_Push(Ov010TaskNode *head, Ov010TaskNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

BOOL func_ov010_02201c34(Ov010TaskList *o) {
    if (o->b0 && !o->b1) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov010_02201c5c(Ov010TaskList *o) {
    if (o->b0 && o->b2) {
        return TRUE;
    }
    return FALSE;
}

void func_ov010_02201c84(void) {
}

void *func_ov010_02201c88(void *o) {
    Heap_Free(o);
    return o;
}

void *Ov010Vt_0220fe08_New(void) {
    u8 *p = (u8 *)Heap_Alloc(0x24);
    if (p != NULL) {
        FLD(void *, p, 0) = data_ov010_0220fe08;
        FLD(Ov010Flags8, p, 4).b0 = 0;
    }
    return p;
}

}
