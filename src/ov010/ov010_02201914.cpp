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

Ov010TaskList *Ov010Vt_0220fe1c_Ctor(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    func_ov003_021d7848(o->pool);
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
    func_ov003_021d7894(o->pool, 0xc, 0x10);
    return TRUE;
}

}
