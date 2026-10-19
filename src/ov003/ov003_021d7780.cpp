#include "types.h"

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
extern void func_ov003_021d0edc(void *p);
extern void *func_0203dd9c(u32 size);
extern void func_0203de1c(void *p);
extern void func_0203df0c(void *p);
extern void *func_0203de84(u32 size, s32 align);
extern void *func_ov000_0218e640(void *mgr, u16 id);

void *func_ov003_021d7780(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov003_021d7794(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021d77b0(void *self) {
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov003_021d77c4(void *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov003Node8 *func_ov003_021d77e0(Ov003NodeSrc *self) {
    u16 id = self->unk_0c;
    Ov003Node8 *node = (Ov003Node8 *)func_0203dd9c(8);
    node->id = id;
    node->next = NULL;
    return node;
}

void func_ov003_021d7800(void *p) {
    if (p != NULL) {
        func_0203de1c(p);
    }
}

BOOL func_ov003_021d7814(u16 *self) {
    void *r;
    u16 id = *self;
    if (data_ov000_021ccd68 == NULL) {
        r = NULL;
    } else {
        r = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return r != NULL;
}

void func_ov003_021d7848(Ov003Pool *self) {
    self->active = 0;
}

Ov003Pool *func_ov003_021d7858(Ov003Pool *self) {
    if (self->active) {
        self->active = 0;
        func_0203df0c(self->buf);
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
    p = (u8 *)func_0203de84(stride * count, 4);
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
