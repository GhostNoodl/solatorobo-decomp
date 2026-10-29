#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010TaskNode {
    Ov010V *obj;
    u32 time;
    Ov010TaskNode *next;
};

struct Ov010TaskList {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u32 time;
    Ov010TaskNode *head;
    u8 pool[0x10];
};

extern "C" {

extern u8 data_ov010_0220fe1c[];
extern u8 data_ov010_0220fe08[];
extern Ov010Heap *data_02097dd0;
extern void func_ov003_021d7848(void *p);
extern void *func_ov003_021d7858(void *p);
extern BOOL func_ov003_021d7894(void *p, s32 a, s32 b);
extern void func_ov003_021d7948(void *p);
extern Ov010TaskNode *func_ov003_021d7980(void *p);
extern void func_ov003_021d79ac(void *p, Ov010TaskNode *n);
void func_ov010_02201b48(Ov010TaskList *o);

Ov010TaskList *func_ov010_02201914(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    func_ov003_021d7848(o->pool);
    o->b0 = 0;
    return o;
}

Ov010TaskList *func_ov010_02201944(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    ((Ov010V *)o)->v08();
    func_ov003_021d7858(o->pool);
    return o;
}

Ov010TaskList *func_ov010_02201974(Ov010TaskList *o) {
    o->vtbl = data_ov010_0220fe1c;
    ((Ov010V *)o)->v08();
    func_ov003_021d7858(o->pool);
    func_0203de1c(o);
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
BOOL func_ov010_022019ac(Ov010TaskList *o) {
    o->b0 = 1;
    o->b1 = 0;
    o->b2 = 0;
    o->time = 0;
    o->head = NULL;
    func_ov003_021d7894(o->pool, 0xc, 0x10);
    return TRUE;
}

}
