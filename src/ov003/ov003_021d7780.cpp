#include "types.h"
#include "ov003/Actor.h"
#include "ov003/Pool.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

extern u32 data_ov003_021f7d2c;
extern void *data_ov000_021ccd68;
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *p);
extern void *ActorMgr_GetActor(void *mgr, u16 id);

void *Ov003ActVt_021f7c0c_Dtor(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *Ov003ActVt_021f7c0c_DtorDelete(void *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f7b60_Dtor(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *Ov003ActVt_021f7b60_DtorDelete(void *self) {
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

Ov003Node8 *Ov003NodeSrc_NewNode(Ov003NodeSrc *self) {
    u16 id = self->unk_0c;
    Ov003Node8 *node = (Ov003Node8 *)Heap_Alloc(8);
    node->id = id;
    node->next = NULL;
    return node;
}

void func_ov003_021d7800(void *p) {
    if (p != NULL) {
        Heap_Free(p);
    }
}

BOOL func_ov003_021d7814(u16 *self) {
    void *r;
    u16 id = *self;
    if (data_ov000_021ccd68 == NULL) {
        r = NULL;
    } else {
        r = ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return r != NULL;
}

void func_ov003_021d7848(Ov003Pool *self) {
    self->active = 0;
}

Ov003Pool *Ov003Pool_Dtor(Ov003Pool *self) {
    if (self->active) {
        self->active = 0;
        Heap_FreeHi(self->buf);
        self->end = NULL;
        self->freeList = NULL;
    }
    return self;
}

BOOL func_ov003_021d7894(Ov003Pool *self, s32 size, s32 count) {
    s32 pad = size % 4 == 0 ? 0 : 4 - size % 4;
    u32 stride;
    u8 *p;
    s32 i;
    if (pad != 0) {
        size = (u16)(size + pad);
    }
    stride = size + 4;
    self->elemSize = size;
    self->active = true;
    p = (u8 *)Heap_AllocHi(stride * count, 4);
    self->buf = p;
    self->end = p + stride * count;
    self->freeList = (Ov003FreeNode *)p;
    for (i = 0; i < count; i++) {
        BOOL last = (u32)i == count - 1;
        if (last) {
            ((Ov003FreeNode *)p)->next = NULL;
        } else {
            ((Ov003FreeNode *)p)->next = (Ov003FreeNode *)(p + stride);
        }
        p += stride;
    }
    return TRUE;
}

}
