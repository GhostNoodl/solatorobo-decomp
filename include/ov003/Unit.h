#ifndef OV003_UNIT_H
#define OV003_UNIT_H

// The group node that Group_FindNode(data_ov000_021ccd64, Actor::unk_20) returns (an ov000
// GroupNode): the ov003 actors clear unk_a2_0 when they go; some stage objects set unk_a2_5 and
// clear unk_a2_6.

#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
    u8 unk_a2_1 : 4;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit;

#endif
