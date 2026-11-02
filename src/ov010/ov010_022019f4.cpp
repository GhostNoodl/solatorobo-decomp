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

void Ov010TaskList_Release(Ov010TaskList *o) {
    if (!o->b0) {
        return;
    }
    Ov010TaskList_Clear(o);
    Ov003Pool_Release(o->pool);
    o->b0 = 0;
}

void Ov010TaskList_Update(Ov010TaskList *o) {
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
            n->obj->vfunc_08();
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

// The flags byte read through its own type, so MWCC does not merge it with an earlier o->b0 read.
static inline const Ov010TLFlags *Ov010TL_Flags(const Ov010TaskList *o) {
    return (const Ov010TLFlags *)((const u8 *)o + 4);
}

VObj *Ov010TaskList_Add(Ov010TaskList *o, VObj *(*fn)(void), u32 time) {
    VObj *obj = NULL;
    Ov010TaskNode *n;
    if (o->b0 && Ov010TL_Flags(o)->b0 && !Ov010TL_Flags(o)->b1) {
        obj = fn();
        n = Ov003Pool_Alloc(o->pool);
        n->obj = obj;
        n->time = time;
        n->next = NULL;
        o->head = Ov010TaskList_Push(o->head, n);
    }
    return obj;
}

void Ov010TaskList_Clear(Ov010TaskList *o) {
    Ov010TaskNode *next;
    Ov010TaskNode *n;
    void *saved;
    if (!o->b0) {
        return;
    }
    if (!Ov010TL_Flags(o)->b0 || Ov010TL_Flags(o)->b1) {
        return;
    }
    for (n = o->head; n != NULL; n = next) {
        next = n->next;
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (n->obj != NULL) {
            VObj *p = n->obj;
            if (p != NULL) {
                p->vfunc_04();
            }
            n->obj = NULL;
        }
        data_02097dd0->cur = saved;
        Ov003Pool_Free(o->pool, n);
    }
    o->head = NULL;
}

void Ov010TaskList_Run(Ov010TaskList *o) {
    if (!o->b0) {
        return;
    }
    if (!Ov010TL_Flags(o)->b0 || Ov010TL_Flags(o)->b1) {
        return;
    }
    if (o->head != NULL) {
        o->b1 = 1;
    }
}

}
