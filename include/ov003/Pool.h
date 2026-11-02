#ifndef OV003_POOL_H
#define OV003_POOL_H

// The fixed-size block pool of ov003 021d7780 / 021d7948 (a free list over one buffer), its
// owner object, and the id nodes it hands out.

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

#endif
