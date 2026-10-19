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

void func_ov010_022019f4(Ov010TaskList *o) {
    if (!o->b0) {
        return;
    }
    func_ov010_02201b48(o);
    func_ov003_021d7948(o->pool);
    o->b0 = 0;
}

void func_ov010_02201a28(Ov010TaskList *o) {
    u32 max;
    Ov010TaskNode *n;
    if (!o->b0) {
        return;
    }
    if (!o->b1) {
        return;
    }
    o->b2 = 0;
    n = o->head;
    max = n->time;
    for (; n != NULL; n = n->next) {
        if (n->time == o->time) {
            n->obj->v08();
            o->b2 = 1;
        }
        if (n->time > max) {
            max = n->time;
        }
    }
    if (o->time > max) {
        o->b1 = 0;
        o->time = 0;
    } else {
        o->time++;
    }
}

#define OV010_TASKLIST_IDLE(o) ((o)->b0 && !(o)->b1)

static inline Ov010TaskNode *Ov010TaskList_Push(Ov010TaskNode *head, Ov010TaskNode *n) {
    if (n != NULL) {
        n->next = head;
        head = n;
    }
    return head;
}

struct Ov010TLFlags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
};

struct Ov010TLView {
    void *vtbl;
    Ov010TLFlags f;
};

#define Ov010TL_V(o) (*(volatile u8 *)((u8 *)(o) + 4))
#define Ov010TL_B0(v) (((Ov010TLFlags *)&(v))->b0)
#define Ov010TL_B1(v) (((Ov010TLFlags *)&(v))->b1)

Ov010V *func_ov010_02201ad4(Ov010TaskList *o, Ov010V *(*fn)(void), u32 time) {
    Ov010V *obj = NULL;
    Ov010TaskNode *n;
    u8 v;
    if (o->b0 && (v = Ov010TL_V(o), Ov010TL_B0(v)) && !Ov010TL_B1(v)) {
        obj = fn();
        n = func_ov003_021d7980(o->pool);
        n->obj = obj;
        n->time = time;
        n->next = NULL;
        o->head = Ov010TaskList_Push(o->head, n);
    }
    return obj;
}

void func_ov010_02201b48(Ov010TaskList *o) {
    Ov010TaskNode *next;
    Ov010TaskNode *n;
    u32 saved;
    u8 v;
    if (!o->b0) {
        return;
    }
    v = Ov010TL_V(o);
    if (!Ov010TL_B0(v) || Ov010TL_B1(v)) {
        return;
    }
    for (n = o->head; n != NULL; n = next) {
        next = n->next;
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (n->obj != NULL) {
            Ov010V *p = n->obj;
            if (p != NULL) {
                p->v04();
            }
            n->obj = NULL;
        }
        data_02097dd0->cur = saved;
        func_ov003_021d79ac(o->pool, n);
    }
    o->head = NULL;
}

}
