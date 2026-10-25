// sbc.c's read-only tables. Written as asm blocks so they land in main's .text with the other
// read-only data (see libs/msl/ctype.c).

// matColorMask_[i]: the material colour bits a 3-bit flag selects: bit 0 the diffuse colour
// (bits 0-14), bit 1 the ambient colour (bits 16-30), bit 2 the vertex-colour flag (bit 15).
#define MASK(i) ((((i) & 1) * 0x00007fff) | ((((i) >> 1) & 1) * 0x7fff0000) | ((((i) >> 2) & 1) * 0x00008000))

// pivotUtil_[p]: the 3x3 matrix elements left when row p / 3 and column p % 3 are removed, in
// row-major order (the 2x2 minor a pivot-compressed rotation fills).
// n + (n >= r), without the ?: the assembler lacks.
#define ROW(p, n) ((n) + ((n) + 3 - (p) / 3) / 3)
#define COL(p, n) ((n) + ((n) + 3 - (p) % 3) / 3)
#define B4(a, b, c, d) ((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))
#define PIVOT(p) \
    dcd B4((ROW(p, 0) * 3) + COL(p, 0), (ROW(p, 0) * 3) + COL(p, 1), \
           (ROW(p, 1) * 3) + COL(p, 0), (ROW(p, 1) * 3) + COL(p, 1))

#pragma force_active on

// const u32 matColorMask_[8]
void matColorMask_(void);
// const u8 pivotUtil_[9][4]
void pivotUtil_(void);

asm void matColorMask_(void) {
    dcd MASK(0)
    dcd MASK(1)
    dcd MASK(2)
    dcd MASK(3)
    dcd MASK(4)
    dcd MASK(5)
    dcd MASK(6)
    dcd MASK(7)
}

asm void pivotUtil_(void) {
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
