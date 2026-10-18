#include "ov003/Vec.h"

struct Ov003FxNode {
    u8 id;
    void *handle;
    Ov003FxNode *next;
};

struct Ov003FxList {
    Ov003FxNode *head;
};

struct Ov003HeapCtx {
    void *cur;
    u32 unk_04;
    void *alt;
};

struct Ov003VecP {
    s32 x;
    s32 y;
    s32 z;
};

extern "C" {

extern Ov003HeapCtx *data_02097dd0;
extern void *data_0214a420;
extern void *func_020657b0(void *mgr, void *handle);
extern void func_0203de1c(void *p);

static inline void Ov003_HeapDelete(void *p) {
    void *old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    if (p != NULL) {
        func_0203de1c(p);
    }
    data_02097dd0->cur = old;
}

void func_ov003_021dacfc(Ov003FxList *self) {
    Ov003FxNode *n = self->head;
    Ov003FxNode *prev = NULL;
    while (n != NULL) {
        if (func_020657b0(data_0214a420, n->handle) == NULL) {
            if (prev == NULL) {
                self->head = n->next;
                Ov003_HeapDelete(n);
                n = self->head;
            } else {
                prev->next = n->next;
                Ov003_HeapDelete(n);
                n = prev->next;
            }
        } else {
            prev = n;
            n = n->next;
        }
    }
}

Ov003VecP func_ov003_021dadc0(const Ov003Vec *a, const Ov003Vec *b) {
    Ov003VecP d;
    d.x = b->x - a->x;
    d.z = b->z - a->z;
    d.y = 0;
    func_02012d78((Ov003Vec *)&d, (Ov003Vec *)&d);
    return d;
}

}
