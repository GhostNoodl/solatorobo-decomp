#include "types.h"

// Population count of a 64-bit value.
u32 __msl_count_bits64(u64 x) {
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    x = x + (x >> 8);
    x = x + (x >> 16);
    x = x + (x >> 32);
    return (u32)x & 0xff;
}

int __signbitd(double x) {
    return (*((s32 *)&x + 1) & 0x80000000) != 0;
}

int __fpclassifyd(double x) {
    switch (*((s32 *)&x + 1) & 0x7ff00000) {
        case 0x7ff00000:
            if ((*((s32 *)&x + 1) & 0xfffff) || *(s32 *)&x) {
                return 1;
            } else {
                return 2;
            }
            break;
        case 0:
            if ((*((s32 *)&x + 1) & 0xfffff) || *(s32 *)&x) {
                return 5;
            } else {
                return 3;
            }
            break;
    }
    return 4;
}
