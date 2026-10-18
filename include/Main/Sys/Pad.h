#ifndef MAIN_SYS_PAD_H
#define MAIN_SYS_PAD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Pad {
    /* 0x00 */ u8 repeatDelay;
    /* 0x01 */ u8 repeatRate;
    /* 0x02 */ u8 counters[12];
    /* 0x0e */ u16 prev;
    /* 0x10 */ u16 cur;
    /* 0x12 */ u16 trig;
    /* 0x14 */ u16 release;
    /* 0x16 */ u16 repeat;
    /* 0x18 */ u16 forced;
    /* 0x1a */ u8 useForced;
} Pad; // size 0x1c

extern Pad *data_02097dc8;

#ifdef __cplusplus
}
#endif

#endif
