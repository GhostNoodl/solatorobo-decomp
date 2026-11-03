#ifndef OV002_BOARDREF_H
#define OV002_BOARDREF_H

#include "types.h"

struct Obj021efe7c;

// The board's selection (unk_00, an index into the mode menu; ov000's task 021ccc94 clears it when
// it starts) and its top object (Obj021efe7c_Create).
typedef struct Ov002BoardRef {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[0x3];
    /* 0x04 */ struct Obj021efe7c *top;
} Ov002BoardRef;

#ifdef __cplusplus
extern "C" {
#endif
extern Ov002BoardRef gOv002BoardRef;
#ifdef __cplusplus
}
#endif

#endif
