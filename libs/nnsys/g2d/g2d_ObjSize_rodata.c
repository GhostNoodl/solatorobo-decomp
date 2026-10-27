// The OBJ height and width in pixels for each shape (square, horizontal, vertical) and size
// (0-3), the [shape][size] tables g2d_MakeCellToOams.c and the game's sprite code read.
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c); this is C data in a read-only
// user section named ".text" (see libs/nitro/math/math_sha1_rodata.c).

typedef unsigned short u16;

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

// Heights: 8x8 16x16 32x32 64x64 / 16x8 32x8 32x16 64x32 / 8x16 8x32 16x32 32x64
const u16 data_02075614[3][4] = {
    { 8, 16, 32, 64 },
    { 8, 8, 16, 32 },
    { 16, 32, 32, 64 },
};

// Widths
const u16 data_0207562c[3][4] = {
    { 8, 16, 32, 64 },
    { 16, 32, 32, 64 },
    { 8, 8, 16, 32 },
};

#pragma section rodata_text end
