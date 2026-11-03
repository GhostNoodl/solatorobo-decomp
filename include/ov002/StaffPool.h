#ifndef OV002_STAFFPOOL_H
#define OV002_STAFFPOOL_H

#include "ov002/StaffRoll.h"

// The staff roll's .bss (0x021f0fa0..0x021f0fd0) as ov002_021ec6a8.cpp reaches it. The objects are
// defined one by one in ov002_021ecb90.cpp (which does not include this header). The ROM reaches
// all of them from ov002_021ec6a8.cpp's functions through the 0x021f0fa0 pool literal too, but
// that file is cut off from the TU by the unmatched Ov002StaffModel_Setup, so it declares the pool
// with this view.
typedef struct Ov002StaffPool {
    /* 0x00 */ Ov002StaffNode *head;     // data_ov002_021f0fa0: the run list
    /* 0x04 */ Ov002Staff *staff;        // data_ov002_021f0fa4
    /* 0x08 */ Ov002StaffNode *tail;     // data_ov002_021f0fa8
    /* 0x0c */ Ov002StaffNode *lists[9]; // data_ov002_021f0fac: the per-kind node lists
} Ov002StaffPool;

#ifdef __cplusplus
extern "C" {
#endif
extern Ov002StaffPool data_ov002_021f0fa0;
#ifdef __cplusplus
}
#endif

#endif
