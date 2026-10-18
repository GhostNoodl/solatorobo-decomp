#ifndef NNSYS_G2D_FONT_H
#define NNSYS_G2D_FONT_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NNS_G2D_GLYPH_INDEX_NOT_FOUND 0xFFFF

typedef enum NNSG2dFontMappingMethod {
    NNS_G2D_MAPMETHOD_DIRECT = 0,
    NNS_G2D_MAPMETHOD_TABLE = 1,
    NNS_G2D_MAPMETHOD_SCAN = 2
} NNSG2dFontMappingMethod;

typedef struct NNSG2dCharWidths {
    /* 0x0 */ s8 left;
    /* 0x1 */ u8 glyphWidth;
    /* 0x2 */ s8 charWidth;
} NNSG2dCharWidths;

typedef struct NNSG2dCMapScanEntry {
    u16 ccode;
    u16 index;
} NNSG2dCMapScanEntry;

typedef struct NNSG2dCMapInfoScan {
    u16 num;
    NNSG2dCMapScanEntry entries[1];
} NNSG2dCMapInfoScan;

typedef struct NNSG2dFontGlyph {
    /* 0x0 */ u8 cellWidth;
    /* 0x1 */ u8 cellHeight;
    /* 0x2 */ u16 cellSize;
    /* 0x4 */ s8 baselinePos;
    /* 0x5 */ u8 maxCharWidth;
    /* 0x6 */ u8 bpp;
    /* 0x7 */ u8 flags;
    /* 0x8 */ u8 glyphTable[1];
} NNSG2dFontGlyph;

typedef struct NNSG2dFontWidth {
    /* 0x0 */ u16 indexBegin;
    /* 0x2 */ u16 indexEnd;
    /* 0x4 */ struct NNSG2dFontWidth *pNext;
    /* 0x8 */ NNSG2dCharWidths widthTable[1];
} NNSG2dFontWidth;

typedef struct NNSG2dFontCodeMap {
    /* 0x0 */ u16 ccodeBegin;
    /* 0x2 */ u16 ccodeEnd;
    /* 0x4 */ u16 mappingMethod;
    /* 0x6 */ u16 reserved;
    /* 0x8 */ struct NNSG2dFontCodeMap *pNext;
    /* 0xc */ u16 mapInfo[1];
} NNSG2dFontCodeMap;

typedef struct NNSG2dFontInformation {
    /* 0x00 */ u8 fontType;
    /* 0x01 */ s8 linefeed;
    /* 0x02 */ u16 alterCharIndex;
    /* 0x04 */ NNSG2dCharWidths defaultWidth;
    /* 0x07 */ u8 encoding;
    /* 0x08 */ NNSG2dFontGlyph *pGlyph;
    /* 0x0c */ NNSG2dFontWidth *pWidth;
    /* 0x10 */ NNSG2dFontCodeMap *pMap;
} NNSG2dFontInformation;

typedef u16 (*NNSiG2dSplitCharCallback)(const void **ppChar);

typedef struct NNSG2dFont {
    /* 0x0 */ NNSG2dFontInformation *pRes;
    /* 0x4 */ NNSiG2dSplitCharCallback cbCharSpliter;
} NNSG2dFont;

typedef struct NNSG2dTextRect {
    int width;
    int height;
} NNSG2dTextRect;

BOOL NNSi_G2dGetUnpackedFont(void *pNftrFile, NNSG2dFontInformation **ppFont);

void NNS_G2dFontInitAuto(NNSG2dFont *pFont, void *pNftrFile);
u16 NNS_G2dFontFindGlyphIndex(const NNSG2dFont *pFont, u16 c);
const NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const NNSG2dFont *pFont, u16 idx);
int NNSi_G2dFontGetStringWidth(const NNSG2dFont *pFont, int hSpace, const void *str, const void **pPos);
int NNSi_G2dFontGetTextHeight(const NNSG2dFont *pFont, int vSpace, const void *txt);
int NNSi_G2dFontGetTextWidth(const NNSG2dFont *pFont, int hSpace, const void *txt);

static inline NNSiG2dSplitCharCallback NNSi_G2dFontGetSpliter(const NNSG2dFont *pFont) {
    return pFont->cbCharSpliter;
}

static inline int NNS_G2dFontGetLineFeed(const NNSG2dFont *pFont) {
    return pFont->pRes->linefeed;
}

static inline int NNS_G2dFontGetCharWidth(const NNSG2dFont *pFont, u16 c) {
    u16 iGlyph = NNS_G2dFontFindGlyphIndex(pFont, c);

    if (iGlyph == NNS_G2D_GLYPH_INDEX_NOT_FOUND) {
        iGlyph = pFont->pRes->alterCharIndex;
    }

    return NNS_G2dFontGetCharWidthsFromIndex(pFont, iGlyph)->charWidth;
}

#ifdef __cplusplus
}
#endif

#endif
