#include "types.h"

typedef struct NNSiG2dBitReader {
    /* 0x0 */ const u8 *src;
    /* 0x4 */ s8 availableBits;
    /* 0x5 */ u8 bits;
} NNSiG2dBitReader;

static inline void BitReaderReload(NNSiG2dBitReader *reader) {
    reader->bits = *(reader->src)++;
    reader->availableBits = 8;
}

u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *reader, int nBits) {
    u32 val = reader->bits;
    int nAvlBits = reader->availableBits;

    if (nAvlBits < nBits) {
        int lack = nBits - nAvlBits;
        val <<= lack;
        BitReaderReload(reader);
        val |= NNSi_G2dBitReaderRead(reader, lack);
    } else {
        val >>= (nAvlBits - nBits);
        reader->availableBits = (s8)(nAvlBits - nBits);
    }

    val &= 0xFF >> (8 - nBits);
    return val;
}
