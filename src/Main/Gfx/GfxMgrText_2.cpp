#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g2d/g2d_Font.h"

extern "C" {

extern void *func_0203dec8(u32 size, int align);
extern void func_0203df40(void *ptr);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);

// Renders a string into a 1/2/4/8 bpp bitmap buffer (mgr->unk_67c), growing the buffer as needed.
// The bit position is built in `pos` and multiplied in both of its uses, so the product is a
// temporary (`mul` takes bpp first); `pos` declared first and `b` after `cur` give the target's
// registers.
void func_0203b12c(GfxMgr *mgr, const char *str) {
    int pos;
    int srcSkip;
    u8 x;
    NNSG2dFont *nf;
    u8 y;
    const u8 *src;
    int width;
    u16 c;
    int height;
    int lw;
    int rowBits;
    u16 idx;
    const NNSG2dCharWidths *widths;
    u8 *buf;
    u32 sb;
    u8 *dst;
    NNSG2dFontGlyph *info;
    NNSiG2dSplitCharCallback fn;
    u8 bpp;
    int ch;
    int db;
    int row;
    int i;
    u32 cur;
    u32 b;
    const char *p;
    u32 size;

    nf = (NNSG2dFont *)&mgr->fonts[mgr->unk_004]->res;
    x = mgr->unk_00c & 7;
    y = mgr->unk_00e & 7;
    width = (x + NNSi_G2dFontGetTextWidth(nf, 0, str) + 7) & ~7;
    height = (y + NNSi_G2dFontGetTextHeight(nf, mgr->unk_010, str) + 7) & ~7;
    bpp = nf->pRes->pGlyph->bpp;
    buf = (u8 *)mgr->unk_67c;
    size = (((u32)(bpp * (width * height) + 7) >> 3) + 3) & ~3;
    if (buf == NULL || size > mgr->unk_680) {
        mgr->unk_69c[0] = 0;
        mgr->unk_69c[1] = 0;
        mgr->unk_69c[2] = 0;
        mgr->unk_69c[3] = 0;
        if (mgr->unk_67c != NULL) {
            func_0203df40(mgr->unk_67c);
            mgr->unk_67c = NULL;
        }
        mgr->unk_680 = 0;
        buf = (u8 *)func_0203dec8(size, 4);
        mgr->unk_67c = buf;
        mgr->unk_680 = size;
    }
    MIi_CpuClearFast(0, buf, size);
    fn = nf->cbCharSpliter;
    rowBits = width * bpp;
    p = str;
    while ((c = fn((const void **)&p)) != 0) {
        if (c == '\n') {
            x = mgr->unk_00c & 7;
            y += (u8)(mgr->unk_010 + nf->pRes->pGlyph->cellHeight);
            continue;
        }
        idx = NNS_G2dFontFindGlyphIndex(nf, c);
        if (idx == 0xffff) {
            idx = nf->pRes->alterCharIndex;
        }
        widths = NNS_G2dFontGetCharWidthsFromIndex(nf, idx);
        info = nf->pRes->pGlyph;
        lw = widths->glyphWidth * bpp;
        ch = info->cellHeight;
        pos = x + widths->left;
        pos += width * y;
        src = info->glyphTable + idx * info->cellSize;
        srcSkip = bpp * info->cellWidth;
        sb = 0;
        dst = buf + (((u16)bpp * pos) >> 3);
        db = ((u16)bpp * pos) & 7;
        for (row = 0; row < ch; row++) {
            cur = *dst;
            for (i = 0; i < lw; i++) {
                b = (*src >> (7 - sb)) & 1;
                sb++;
                if (sb >= 8) {
                    src++;
                    sb &= 7;
                }
                if (b) {
                    cur = (cur & ~(1 << (7 - db))) | (b << (7 - db));
                }
                db++;
                if (db >= 8) {
                    *dst = cur;
                    db &= 7;
                    cur = *++dst;
                }
            }
            sb += srcSkip - lw;
            src += sb >> 3;
            sb &= 7;
            if (db != 0) {
                *dst = cur;
                dst += db >> 3;
                db &= 7;
            }
            db += rowBits - lw;
            dst += db >> 3;
            db &= 7;
        }
        x += widths->charWidth;
    }
    mgr->unk_69c[0] = 0;
    mgr->unk_69c[1] = (u32)width;
    mgr->unk_69c[2] = (s16)width;
    mgr->unk_69c[3] = height;
}

#ifdef NONMATCHING
// func_0203b4ac: 11 register-masked / 51 raw (round qpA, honest_search scorer). The `base = canvas->charBase`
// read sits before the `nx < 0` return (the ROM loads it there), `rowStride` comes after `glyphBytes`, and
// `s` is set first in the loop body. Left: the prologue colouring (ROM: canvas r6, w r4, x r8, h ip,
// end/cx1 fp, nx sb) and the stack slots of srcStride and j; ramerge.py does not reproduce this graph.
// NNSG2dCharCanvas embedded in GfxMgr at 0x684.
typedef struct GfxTextCanvas {
    /* 0x00 */ u8 *charBase;
    /* 0x04 */ u32 areaWidth;
    /* 0x08 */ u32 areaHeight;
    /* 0x0c */ u8 dstBpp;
    /* 0x10 */ u32 param;
} GfxTextCanvas;

// Copies the 1bpp text mask at mgr->unk_67c into the 4bpp canvas, drawing set pixels in the given color.
void func_0203b4ac(GfxMgr *mgr, int color) {
    u8 *dst;
    int h;
    u32 *p;
    GfxTextCanvas *canvas;
    u32 charSize;
    int end;
    u32 *pend;
    int k;
    u8 *s;
    u32 cy1;
    int nx;
    u32 word;
    u32 glyphBytes;
    u32 cx0;
    u32 b;
    u32 rowStride;
    u8 glyphRaw;
    int x;
    int sh;
    u32 j;
    GfxFont *font;
    int srcOff;
    int wb;
    int w;
    int srcStride;
    u32 cx1;
    u8 *src;
    u8 *base;
    canvas = (GfxTextCanvas *)mgr->unk_684;
    w = mgr->unk_69c[1];
    x = mgr->unk_00c & ~7;
    font = mgr->fonts[mgr->unk_004];
    charSize = (canvas->dstBpp * 64) / 8;
    h = mgr->unk_69c[3];
    if (w == 0) {
        return;
    }
    end = x + w;
    if (end < 0) {
        return;
    }
    if (h < 0) {
        return;
    }
    cx0 = 0;
    if (x > 0) {
        cx0 = (u32)x >> 3;
    }
    cx1 = (u32)(end + 7) >> 3;
    if (canvas->areaWidth <= cx1) {
        cx1 = canvas->areaWidth;
    }
    cy1 = (u32)(h + 7) >> 3;
    if (canvas->areaHeight <= cy1) {
        cy1 = canvas->areaHeight;
    }
    nx = cx1 - cx0;
    base = canvas->charBase;
    if (nx < 0) {
        return;
    }
    if ((int)cy1 < 0) {
        return;
    }
    dst = base + charSize * cx0;
    glyphRaw = font->res->info[6];
    glyphBytes = (u32)(glyphRaw << 6) >> 6;
    rowStride = charSize * canvas->param;
    wb = w >> 3;
    srcStride = wb << 3;
    if (x < 0) {
        srcOff = -x >> 3;
    } else {
        srcOff = 0;
    }
    src = (u8 *)mgr->unk_67c + srcOff * glyphBytes;
    for (j = 0; j < cy1; j++) {
        s = src + j * srcStride;
        p = (u32 *)(dst + j * rowStride);
        pend = (u32 *)((u8 *)p + charSize * nx);
        k = 0;
        while (p < pend) {
            b = *s;
            if (b != 0) {
                word = *p;
                for (sh = 0; sh < 32 && b != 0; sh += 4, b = (u8)(b << 1)) {
                    if (b & 0x80) {
                        word = (word & ~(0xf << sh)) | (color << sh);
                    }
                }
                *p = word;
            }
            k++;
            s += wb;
            p++;
            if (k >= 8) {
                s -= srcStride - glyphRaw;
                k = 0;
            }
        }
    }
}
#endif

}
