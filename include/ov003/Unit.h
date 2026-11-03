#ifndef OV003_UNIT_H
#define OV003_UNIT_H

// The group node that Group_FindNode(gGroup, Actor::unk_20) returns (an ov000
// GroupNode): the ov003 actors clear unk_a2_0 when they go; some stage objects set unk_a2_5 and
// clear unk_a2_6.

#include "types.h"

typedef struct {
    u8 unk_00[0x94];
    u16 unk_94; // read by the ov003 patrol actor (vtable 021f940c) as its start rot_x
    u8 unk_96[0xc];
    u8 unk_a2_0 : 1;
    u8 unk_a2_1 : 4;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit;

#endif
