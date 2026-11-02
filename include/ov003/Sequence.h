#ifndef OV003_SEQUENCE_H
#define OV003_SEQUENCE_H

// A byte-coded sequence that the ov003 sequence objects (021d95e8, 021d969c, 021d9740) step
// through, one entry at a time.

#include "types.h"

typedef struct {
    u8 id;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
} Ov003SeqEntry;

typedef struct {
    u8 a;
    u8 b;
} Ov003BytePair;

typedef struct {
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pairA;
    u8 pairB;
    u16 unk_04;
    u16 index;
    u16 length;
    Ov003SeqEntry *entries;
} Ov003Sequence;

#endif
