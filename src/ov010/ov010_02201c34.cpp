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
extern void func_ov003_021d7858(void *p);
extern void func_ov003_021d7894(void *p, s32 a, s32 b);
extern void func_ov003_021d7948(void *p);
extern Ov010TaskNode *func_ov003_021d7980(void *p);
extern void func_ov003_021d79ac(void *p, Ov010TaskNode *n);
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
    func_0203de1c(o);
    return o;
}

void *func_ov010_02201c9c(void) {
    u8 *p = (u8 *)func_0203dd9c(0x24);
    if (p != NULL) {
        FLD(void *, p, 0) = data_ov010_0220fe08;
        FLD(Ov010Flags8, p, 4).b0 = 0;
    }
    return p;
}

}
