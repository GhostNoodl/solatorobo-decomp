#ifndef OV003_FXLIST_H
#define OV003_FXLIST_H

// A list of effect handles by id (ov003 021da788, 021dacfc).

#include "types.h"

struct Ov003FxNode {
    u8 id;
    void *handle;
    Ov003FxNode *next;
};

struct Ov003FxList {
    Ov003FxNode *head;
};

#endif
