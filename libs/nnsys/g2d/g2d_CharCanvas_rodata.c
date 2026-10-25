// g2d_CharCanvas.c's read-only data: the three canvas vtables (OBJ 2D rectangle, BG, OBJ 1D; the
// 2D one's init function is not linked), GetMaxObjectSize's table of the largest OBJ that fits a
// w x h character area, and OBJSizeToShape's table of the GXOamShape for each OBJ size.
//
// main keeps its read-only data inside .text (see libs/msl/ctype.c); this is C data in a read-only
// user section named ".text" (see libs/nitro/math/math_sha1_rodata.c).

typedef unsigned char u8;
typedef unsigned long u32;

struct NNSG2dCharCanvas;
struct NNSG2dFont;
struct NNSG2dGlyph;

typedef void (*NNSiG2dDrawGlyphFunc)(const struct NNSG2dCharCanvas *pCC, const struct NNSG2dFont *pFont, int x, int y, int cl, const struct NNSG2dGlyph *pGlyph);
typedef void (*NNSiG2dClearFunc)(const struct NNSG2dCharCanvas *pCC, int cl);
typedef void (*NNSiG2dClearAreaFunc)(const struct NNSG2dCharCanvas *pCC, int cl, int x, int y, int w, int h);

typedef struct NNSiG2dCharCanvasVTable {
    NNSiG2dDrawGlyphFunc pDrawGlyph;
    NNSiG2dClearFunc pClear;
    NNSiG2dClearAreaFunc pClearArea;
} NNSiG2dCharCanvasVTable;

void DrawGlyphLine(const struct NNSG2dCharCanvas *pCC, const struct NNSG2dFont *pFont, int x, int y, int cl, const struct NNSG2dGlyph *pGlyph);
void DrawGlyph1D(const struct NNSG2dCharCanvas *pCC, const struct NNSG2dFont *pFont, int x, int y, int cl, const struct NNSG2dGlyph *pGlyph);
void ClearContinuous(const struct NNSG2dCharCanvas *pCC, int cl);
void ClearLine(const struct NNSG2dCharCanvas *pCC, int cl);
void ClearAreaLine(const struct NNSG2dCharCanvas *pCC, int cl, int x, int y, int w, int h);
void ClearArea1D(const struct NNSG2dCharCanvas *pCC, int cl, int x, int y, int w, int h);

// Size in characters as log2: 0 = 8 px, 1 = 16, 2 = 32, 3 = 64
typedef struct ObjectSize {
    u8 widthShift;
    u8 heightShift;
} ObjectSize;

// GXOamShape: the shape (attr0 bits 14-15) and size (attr1 bits 30-31) fields of an OBJ
#define SHAPE(shape, size) (((u32)(shape) << 14) | ((u32)(size) << 30))
#define GX_OAM_SHAPE_8x8   SHAPE(0, 0)
#define GX_OAM_SHAPE_16x16 SHAPE(0, 1)
#define GX_OAM_SHAPE_32x32 SHAPE(0, 2)
#define GX_OAM_SHAPE_64x64 SHAPE(0, 3)
#define GX_OAM_SHAPE_16x8  SHAPE(1, 0)
#define GX_OAM_SHAPE_32x8  SHAPE(1, 1)
#define GX_OAM_SHAPE_32x16 SHAPE(1, 2)
#define GX_OAM_SHAPE_64x32 SHAPE(1, 3)
#define GX_OAM_SHAPE_8x16  SHAPE(2, 0)
#define GX_OAM_SHAPE_8x32  SHAPE(2, 1)
#define GX_OAM_SHAPE_16x32 SHAPE(2, 2)
#define GX_OAM_SHAPE_32x64 SHAPE(2, 3)
#define SHAPE_NONE         0 // no OBJ has this size

#pragma define_section rodata_text ".text" ".bss" ".text" abs32 R
#pragma section rodata_text begin

const NNSiG2dCharCanvasVTable data_02075660 = { DrawGlyphLine, ClearLine, ClearAreaLine };       // VTABLE_OBJ2DRECT
// MWCC emits these two in the opposite order to their definitions.
const NNSiG2dCharCanvasVTable data_02075678 = { DrawGlyph1D, ClearContinuous, ClearArea1D };     // VTABLE_OBJ1D
const NNSiG2dCharCanvasVTable data_0207566c = { DrawGlyphLine, ClearContinuous, ClearAreaLine }; // VTABLE_BG

// [log2 height][log2 width] in characters: the widest, then tallest, OBJ no larger than the area
const ObjectSize data_02075684[4][4] = {
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 0 } }, //  8: 8x8   16x8  32x8  32x8
    { { 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 1 } }, // 16: 8x16  16x16 32x16 32x16
    { { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 } }, // 32: 8x32  16x32 32x32 64x32
    { { 0, 2 }, { 1, 2 }, { 2, 3 }, { 3, 3 } }, // 64: 8x32  16x32 32x64 64x64
};

// [heightShift][widthShift]
const u32 data_020756a4[4][4] = {
    { GX_OAM_SHAPE_8x8,  GX_OAM_SHAPE_16x8,  GX_OAM_SHAPE_32x8,  SHAPE_NONE },
    { GX_OAM_SHAPE_8x16, GX_OAM_SHAPE_16x16, GX_OAM_SHAPE_32x16, SHAPE_NONE },
    { GX_OAM_SHAPE_8x32, GX_OAM_SHAPE_16x32, GX_OAM_SHAPE_32x32, GX_OAM_SHAPE_64x32 },
    { SHAPE_NONE,        SHAPE_NONE,         GX_OAM_SHAPE_32x64, GX_OAM_SHAPE_64x64 },
};

#pragma section rodata_text end
