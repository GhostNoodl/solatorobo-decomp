#include "ov003/Vec.h"
#include "ov003/Actor.h"
#include "ov003/Pool.h"

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

extern "C" {

extern u32 data_ov003_021f7d2c;
extern void *data_ov000_021ccd68;
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *p);
extern void Heap_FreeHi(void *p);
extern void *ActorMgr_GetActor(void *mgr, u16 id);

void Ov003Pool_Release(Ov003Pool *self) {
    if (self->active) {
        self->active = 0;
        Heap_FreeHi(self->buf);
        self->end = NULL;
        self->freeList = NULL;
    }
}

void *Ov003Pool_Alloc(Ov003Pool *self) {
    void *r = NULL;
    Ov003FreeNode *node;
    if (self->active && (node = self->freeList) != NULL) {
        self->freeList = node->next;
        r = node + 1;
    }
    return r;
}

void Ov003Pool_Free(Ov003Pool *self, void *p) {
    if (self->active && p != NULL) {
        Ov003FreeNode *node = (Ov003FreeNode *)p - 1;
        node->next = self->freeList;
        self->freeList = node;
    }
}

Ov003PoolOwner *Ov003Vt_021f7d2c_Ctor(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->active = 0;
    return self;
}

Ov003PoolOwner *Ov003Vt_021f7d2c_Dtor(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->Release();
    return self;
}

Ov003PoolOwner *Ov003Vt_021f7d2c_DtorDelete(Ov003PoolOwner *self) {
    *(void **)self = &data_ov003_021f7d2c;
    self->Release();
    Heap_Free(self);
    return self;
}

BOOL Ov003Mover_Start(Ov003Mover *self, const Ov003Vec *target, const Ov003Vec *start, s32 speed, s32 maxDist, u8 noSnap) {
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
