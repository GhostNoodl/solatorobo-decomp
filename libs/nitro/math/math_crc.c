#include "types.h"

typedef u16 MATHCRC16Context;

typedef struct MATHCRC16Table {
    u16 table[256];
} MATHCRC16Table;

void MATHi_CRC16InitTableRev(MATHCRC16Table *table, u16 poly) {
    u32 r, i, j;
    u16 *t = table->table;

    for (i = 0; i < 256; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 1) {
                r = (r >> 1) ^ poly;
            } else {
                r >>= 1;
            }
        }
        t[i] = (u16)r;
    }
}

void MATHi_CRC16UpdateRev(const MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length) {
    u32 r, i;
    const u16 *t = table->table;
    const u8 *data = (const u8 *)input;

    r = *context;
    for (i = 0; i < length; i++) {
        r = (r >> 8) ^ t[(r ^ *data) & 0xff];
        data++;
    }
    *context = (MATHCRC16Context)r;
}

u16 MATH_CalcCRC16(const MATHCRC16Table *table, const void *data, u32 dataLength) {
    MATHCRC16Context context = 0;
    MATHi_CRC16UpdateRev(table, &context, data, dataLength);
    return context;
}
