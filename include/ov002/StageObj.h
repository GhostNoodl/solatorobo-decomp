#ifndef OV002_STAGEOBJ_H
#define OV002_STAGEOBJ_H

#include "types.h"

// Base of the ov002 stage objects (0x4c; ctor func_ov002_021e4cd8, dtor func_ov002_021e4d4c).
// The ctor appends the object to the list in data_ov002_021f0f9c (head at 0xdc, tail at 0xe0,
// linked through next); an object can own up to eight others (children, each pointing back
// through owner).
struct Ov002Obj {
    void *vt;
    s32 unk_04; // kind, -1 until set
    s32 unk_08;
    s32 unk_0c; // 3 and above: loaded (func_ov015_0220e55c)
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    struct Ov002Obj *next;
    struct Ov002Obj *children[8];
    struct Ov002Obj *owner;
};
SIZE_ASSERT(Ov002Obj, 0x4c);

#endif
