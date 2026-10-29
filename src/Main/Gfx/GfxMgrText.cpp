#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern int NNSi_G2dFontGetStringWidth(const void *pFont, int hSpace, const void *str, const void **pPos);
extern int NNSi_G2dFontGetTextHeight(const void *pFont, int vSpace, const void *txt);
extern void NNS_G2dCharCanvasInitForBG(void *canvas, void *charBase, int w, int h, int colorMode);
extern void NNS_G2dMapScrToCharText(void *scrBase, int w, int h, int left, int top, int pitch, int charNo, int pltt);
extern void *func_0203bb68(GfxSys *sys, BOOL main);
extern void func_0203b12c(GfxMgr *mgr, const char *str);
extern void func_0203b4ac(GfxMgr *mgr, int color);
extern void DC_FlushAll(void);

void func_0203aab0(GfxMgr *mgr, const char *str) {
    GfxFont *font;
    int pal;
    int width;
    int charNo;
    int top;
    int height;
    int color;
    int rows;
    const char *p;
    u8 *charBase;
    u8 type;
    font = mgr->fonts[mgr->unk_004];
    height = NNSi_G2dFontGetTextHeight(&font->res, mgr->unk_010, str);
    pal = 0;
    color = 0;
    type = mgr->fontHeights[mgr->unk_004];
    if (type == 1) {
        int v = mgr->unk_008;
        pal = v >> 4;
        color = v % 15 + 1;
    } else if (type == 2) {
        pal = (int)mgr->unk_008 / 5 + 1;
        color = ((int)mgr->unk_008 % 5) * 3 + 1;
    }
    if (mgr->unk_00e + height > mgr->unk_67a * 8) {
        mgr->unk_00e = mgr->unk_67a * 8 - height;
    }
    top = mgr->unk_00e >> 3;
    charNo = (s16)top * mgr->unk_678 + 1;
    rows = ((mgr->unk_00e + height + 7) >> 3) - top;
    charBase = (u8 *)func_0203bb68(data_02097d48, FALSE);
    NNS_G2dCharCanvasInitForBG(mgr->unk_684, charBase + charNo * 0x20, mgr->unk_678, rows, 4);
    NNS_G2dMapScrToCharText(func_0203bb68(data_02097d48, TRUE), mgr->unk_678, rows, 0, top, 0x20, charNo, pal + mgr->plttSlots[1]);
    func_0203b12c(mgr, str);
    func_0203b4ac(mgr, color);
    DC_FlushAll();
    p = str;
    while (p != NULL) {
        width = NNSi_G2dFontGetStringWidth(&font->res, 0, p, (const void **)&p);
    }
    mgr->unk_00c = mgr->unk_00c + (s16)width;
    mgr->unk_00e = mgr->unk_00e + (s16)(height - font->res->info[1]);
}

typedef struct GfxGlyphInfo {
    /* 0x0 */ u8 cellWidth;
    /* 0x1 */ u8 cellHeight;
    /* 0x2 */ u16 cellSize;
    /* 0x4 */ s8 baselinePos;
    /* 0x5 */ u8 maxCharWidth;
    /* 0x6 */ u8 bpp;
    /* 0x7 */ u8 flags;
    /* 0x8 */ u8 glyphTable[1];
} GfxGlyphInfo;

typedef struct GfxFontInfo {
    /* 0x0 */ u8 fontType;
    /* 0x1 */ s8 linefeed;
    /* 0x2 */ u16 alterCharIndex;
    /* 0x4 */ u8 defaultWidth[3];
    /* 0x7 */ u8 encoding;
    /* 0x8 */ GfxGlyphInfo *pGlyph;
} GfxFontInfo;

typedef struct GfxNnsFont {
    /* 0x0 */ GfxFontInfo *pRes;
    /* 0x4 */ u16 (*splitChar)(const void **str);
} GfxNnsFont;

typedef struct GfxCharWidths {
    /* 0x0 */ s8 left;
    /* 0x1 */ u8 glyphWidth;
    /* 0x2 */ s8 charWidth;
} GfxCharWidths;

typedef struct GfxOamTmp {
    u32 attr01;
    u16 attr2;
    u16 attr3;
} GfxOamTmp;

extern u16 NNS_G2dFontFindGlyphIndex(const GfxNnsFont *font, u16 c);
extern const GfxCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const GfxNnsFont *font, u16 idx);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void *func_0203bbfc(GfxSys *sys, int which);
extern BOOL NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);
extern VramBlock *func_0203a408(GfxMgr *mgr, int width, int height, BOOL temporary);

// Draws a string as one 16x16 OBJ per glyph.
void func_0203acb8(GfxMgr *mgr, const char *str) {
    int shift;
    int i;
    int mask;
    int which;
    VramBlock *block;
    int color;
    int pal;
    int wc;
    int x;
    int y;
    u32 *dst;
    int bit;
    int row;
    u16 n;
    int h;
    u32 shape;
    u16 (*fn)(const void **str);
    u16 c;
    const GfxCharWidths *widths;
    GfxOamTmp buf[128];
    GfxNnsFont *font;
    u8 type;
    int h8;
    int w;
    GfxGlyphInfo *info;
    u8 *glyph;
    u16 idx;
    const char *p;
    u32 base;
    font = (GfxNnsFont *)&mgr->fonts[mgr->unk_004]->res;
    mgr->unk_65c = 0;
    pal = 0;
    color = pal;
    type = mgr->fontHeights[mgr->unk_004];
    if (type == 1) {
        int v = mgr->unk_008;
        pal = v >> 4;
        color = v % 15 + 1;
    } else if (type == 2) {
        pal = (int)mgr->unk_008 / 5 + 1;
        color = ((int)mgr->unk_008 % 5) * 3 + 1;
    }
    if (data_020827f8[mgr->unk_004].mode == 4) {
        pal += mgr->plttSlots[2];
        shift = mgr->pools[0].alignShift;
        base = 0x6400000;
        which = 0;
    } else {
        pal += mgr->plttSlots[3];
        shift = mgr->pools[1].alignShift;
        base = 0x6600000;
        which = 1;
    }
    p = str;
    x = mgr->unk_00c;
    h = font->pRes->pGlyph->cellHeight;
    n = 0;
    y = mgr->unk_00e;
    fn = font->splitChar;
    h8 = h >> 3;
    while ((c = fn((const void **)&p)) != 0 && n < 0x80) {
        if (c == '\n') {
            y += h;
            x = mgr->unk_00c;
            continue;
        }
        idx = NNS_G2dFontFindGlyphIndex(font, c);
        if (idx == 0xffff) {
            idx = font->pRes->alterCharIndex;
        }
        widths = NNS_G2dFontGetCharWidthsFromIndex(font, idx);
        info = font->pRes->pGlyph;
        glyph = info->glyphTable + idx * info->cellSize;
        w = widths->left + info->cellWidth;
        wc = w > 16 ? 16 : w;
        block = func_0203a408(mgr, w, h, TRUE);
        if ((w >> 3) != 0 && h8 != 0) {
            shape = 0x40000000;
        } else if ((w >> 3) == 0 && h8 != 0) {
            shape = 0x8000;
        } else if ((w >> 3) != 0 && h8 == 0) {
            shape = 0x4000;
        } else if ((w >> 3) == 0 && h8 == 0) {
            shape = 0;
        }
        dst = (u32 *)(base + block->addr);
        {
            u32 name = (block->addr >> 5) >> shift;
            buf[n].attr01 = shape | (y & 0xff) | ((u32)(x << 23) >> 7);
            buf[n].attr2 = name | (pal << 12);
        }
        if (block->temporary || !(block->temporary || block->unk_10_2)) {
            bit = 0;
            MIi_CpuClearFast(0, dst, 0x80);
            for (row = 0; row < h; row++) {
                mask = row & ((wc - 1) & 0xf8);
                for (i = widths->left; i < w; i++) {
                    int col = i >> 3;
                    int sh = (i * 4) & 0x1f;
                    if ((glyph[bit >> 3] >> (7 - (bit & 7))) & 1) {
                        dst[(col + (mask >> 3)) * 8] |= color << sh;
                    }
                    bit++;
                }
                dst++;
            }
            block->unk_10_2 = 1;
            block->unk_10_6 = x;
            block->unk_10_14 = y;
        }
        x += widths->charWidth;
        n++;
    }
    mgr->unk_00c = x;
    NNS_G2dEntryOamManagerOam(func_0203bbfc(data_02097d48, which), buf, n);
}

}
