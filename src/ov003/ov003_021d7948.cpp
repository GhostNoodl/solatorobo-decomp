#include "ov003/Vec.h"

struct Ov003Mover {
    u32 unk_00;
    u8 active : 1;
    u8 noSnap : 1;
    u8 done : 1;
    s32 speed;
    s32 dist;
    s32 maxDist;
    Ov003Vec pos;
    Ov003Vec target;
    Ov003Vec dir;
};

typedef struct Ov003FreeNode {
    struct Ov003FreeNode *next;
} Ov003FreeNode;

typedef struct {
    u8 active : 1;
    u16 elemSize;
    void *buf;
    void *end;
    Ov003FreeNode *freeList;
} Ov003Pool;

class Ov003PoolOwner {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
};

typedef struct {
    u16 id;
    void *next;
} Ov003Node8;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
} Ov003NodeSrc;

extern "C" {

extern u32 data_ov003_021f7d2c;
extern void *data_ov000_021ccd68;
extern void *func_ov003_021d0edc(void *p);
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *p);
extern void func_0203df0c(void *p);
extern void *func_ov000_0218e640(void *mgr, u16 id);

void func_ov003_021d7948(Ov003Pool *self) {
    if (self->active) {
        self->active = 0;
        func_0203df0c(self->buf);
        self->end = NULL;
        self->freeList = NULL;
    }
}

void *func_ov003_021d7980(Ov003Pool *self) {
    void *r = NULL;
    Ov003FreeNode *node;
    if (self->active && (node = self->freeList) != NULL) {
        self->freeList = node->next;
        r = node + 1;
    }
    return r;
}

void func_ov003_021d79ac(Ov003Pool *self, void *p) {
    if (self->active && p != NULL) {
        Ov003FreeNode *node = (Ov003FreeNode *)p - 1;
        node->next = self->freeList;
        self->freeList = node;
    }
}

Ov003PoolOwner *func_ov003_021d79d0(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->active = 0;
    return self;
}

Ov003PoolOwner *func_ov003_021d79ec(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->Release();
    return self;
}

Ov003PoolOwner *func_ov003_021d7a14(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->Release();
    func_0203de1c(self);
    return self;
}

BOOL func_ov003_021d7a44(Ov003Mover *self, const Ov003Vec *target, const Ov003Vec *start, s32 speed, s32 maxDist, u8 noSnap) {
    self->active = 1;
    self->noSnap = noSnap;
    self->done = 0;
    self->dist = 0;
    self->speed = speed;
    self->maxDist = maxDist;
    self->pos = *start;
    self->target = *target;
    self->dir.x = target->x - start->x;
    self->dir.y = target->y - start->y;
    self->dir.z = target->z - start->z;
    VEC_Normalize(&self->dir, &self->dir);
    return TRUE;
}

}
