#ifndef OV003_TICKER_H
#define OV003_TICKER_H

// A frame ticker of the ov003 script objects (021d7ae8..021d8c60, 021f77d8): fires every
// interval frames, count times or looping.

#include "types.h"

typedef struct {
    u8 active : 1;
    u8 loop : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    s16 count;
    s16 interval;
    s16 timer;
    s16 next;
    s16 cur;
} Ov003Ticker;

#endif
