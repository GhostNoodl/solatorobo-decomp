// nsbca.c's own copy of the pivot table (pivotUtil_ in sbc_rodata.c): the 3x3 matrix elements
// left when row p / 3 and column p % 3 are removed, in row-major order. Written as an asm block
// so it lands in main's .text with the other read-only data (see libs/msl/ctype.c).

// n + (n >= r), without the ?: the assembler lacks.
#define ROW(p, n) ((n) + ((n) + 3 - (p) / 3) / 3)
#define COL(p, n) ((n) + ((n) + 3 - (p) % 3) / 3)
#define B4(a, b, c, d) ((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))
#define PIVOT(p) \
    dcd B4((ROW(p, 0) * 3) + COL(p, 0), (ROW(p, 0) * 3) + COL(p, 1), \
           (ROW(p, 1) * 3) + COL(p, 0), (ROW(p, 1) * 3) + COL(p, 1))

#pragma force_active on

// static const u8 pivotUtil_[9][4]
void data_02075728(void);

asm void data_02075728(void) {
    PIVOT(0)
    PIVOT(1)
    PIVOT(2)
    PIVOT(3)
    PIVOT(4)
    PIVOT(5)
    PIVOT(6)
    PIVOT(7)
    PIVOT(8)
}

#pragma force_active reset
