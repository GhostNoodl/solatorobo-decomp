#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g2d/g2d_Font.h"

extern "C" {

extern VramBlock *func_02039844(GfxMgr *mgr, VramPool *pool, u32 size);
extern void func_0203aab0(GfxMgr *mgr, void *arg);
extern void func_0203acb8(GfxMgr *mgr, void *arg);

VramBlock *func_0203a408(GfxMgr *mgr, int width, int height, BOOL temporary) {
    VramBlock *block;
    u32 size = (((width + 7) >> 3) * ((height + 7) >> 3)) << 5;
    if (data_020827f8[mgr->unk_004].mode == 4) {
        block = func_02039844(mgr, &mgr->pools[0], size);
        block->kind = 4;
    } else {
        block = func_02039844(mgr, &mgr->pools[1], size);
        block->kind = 3;
    }
    block->temporary = temporary;
    block->unk_10_2 = 0;
    block->unk_10_29 = 1;
    block->unk_10_30 = 1;
    block->unk_14 = 0;
    return block;
}

GfxCell *func_0203a4a4(GfxMgr *mgr) {
    return &mgr->cells[mgr->unk_046++];
}

void *func_0203a4c0(GfxMgr *mgr) {
    return &mgr->fonts[mgr->unk_004]->res;
}

void func_0203a4d4(GfxMgr *mgr, void *arg) {
    mgr->unk_658 = (u32)arg;
}

void func_0203a4dc(GfxMgr *mgr, void *arg) {
    mgr->unk_65c = (u32)arg;
}

static inline bool GfxSys_IsFlag(GfxSys *sys) {
    return sys->unk_a30_4 ? TRUE : FALSE;
}

void func_0203a4e4(GfxMgr *mgr, void *arg) {
    switch (data_020827f8[mgr->unk_004].mode) {
    case 0:
        break;
    case 1:
        if (data_02097d48->state == 2 && !GfxSys_IsFlag(data_02097d48)) {
            break;
        }
        func_0203aab0(mgr, arg);
        break;
    case 2:
        if (data_02097d48->state == 2 && !data_02097d48->unk_a30_4) {
            func_0203aab0(mgr, arg);
        }
        break;
    case 3:
    case 4:
        if (data_02097d48->state == 1) {
            func_0203acb8(mgr, arg);
        }
        break;
    }
}

// Draws one glyph into a 16x16 OBJ and moves the cursor past it.
typedef struct GfxOamTmp {
    u32 attr01;
    u16 attr2;
    u16 attr3;
} GfxOamTmp;

extern u16 NNS_G2dFontFindGlyphIndex(const NNSG2dFont *pFont, u16 c);
extern const NNSG2dCharWidths *NNS_G2dFontGetCharWidthsFromIndex(const NNSG2dFont *pFont, u16 idx);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void *func_0203bbfc(GfxSys *sys, int which);
extern void NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);

void func_0203a5a4(GfxMgr *mgr, u16 c) {
    u8 type;
    int color;
    int pal;
    int x;
    NNSG2dFontGlyph *info;
    int mask;
    int row;
    u16 idx;
    int wc;
    int shift;
    u32 *dst;
    int h;
    int bit;
    int which;
    int w;
    u32 shape;
    VramBlock *block;
    u8 *glyph;
    const NNSG2dCharWidths *widths;
    GfxOamTmp oam;
    NNSG2dFont *font;
    u32 base;
    int mode;

    mode = data_020827f8[mgr->unk_004].mode;
    if (mode == 1 || mode == 2) {
        return;
    }
    font = (NNSG2dFont *)&mgr->fonts[mgr->unk_004]->res;
    block = (VramBlock *)mgr->unk_65c;
    pal = 0;
    color = 0;
    mgr->unk_65c = 0;
    type = mgr->fontHeights[mgr->unk_004];
    if (type == 1) {
        int v = mgr->unk_008;
        pal = v >> 4;
        color = v % 15 + 1;
    } else if (type == 2) {
        pal = (int)mgr->unk_008 / 5 + 1;
        color = ((int)mgr->unk_008 % 5) * 3 + 1;
    }
    if (mode == 4) {
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
    idx = NNS_G2dFontFindGlyphIndex(font, c);
    if (idx == 0xffff) {
        idx = font->pRes->alterCharIndex;
    }
    widths = NNS_G2dFontGetCharWidthsFromIndex(font, idx);
    info = font->pRes->pGlyph;
    h = info->cellHeight;
    glyph = info->glyphTable + idx * info->cellSize;
    w = widths->left + info->cellWidth;
    wc = w > 16 ? 16 : w;
    if (block == NULL) {
        block = (VramBlock *)func_0203a408(mgr, w, h, TRUE);
    }
    dst = (u32 *)(base + block->addr);
    if ((w >> 3) != 0 && (h >> 3) != 0) {
        shape = 0x40000000;
    } else if ((w >> 3) == 0 && (h >> 3) != 0) {
        shape = 0x8000;
    } else if ((w >> 3) != 0 && (h >> 3) == 0) {
        shape = 0x4000;
    } else if ((w >> 3) == 0 && (h >> 3) == 0) {
        shape = 0;
    }
    {
        s16 ox = mgr->unk_00c;
        s16 oy = mgr->unk_00e;
        oam.attr2 = ((block->addr >> 5) >> shift) | (pal << 12);
        oam.attr01 = shape | (oy & 0xff) | ((u32)(ox << 23) >> 7);
    }
    if (block->temporary || !(block->temporary || block->unk_10_2)) {
        bit = 0;
        MIi_CpuClearFast(0, dst, 0x80);
        for (row = 0; row < h; row++) {
            mask = row & ((wc - 1) & 0xf8);
            for (x = widths->left; x < w; x++) {
                int col = x >> 3;
                int sh = (x * 4) & 0x1f;
                if ((glyph[bit >> 3] >> (7 - (bit & 7))) & 1) {
                    dst[(col + (mask >> 3)) * 8] |= color << sh;
                }
                bit++;
            }
            dst++;
        }
        block->unk_14 = shape;
        block->unk_10_2 = 1;
        block->unk_10_6 = mgr->unk_00c;
        block->unk_10_14 = mgr->unk_00e;
    }
    NNS_G2dEntryOamManagerOam(func_0203bbfc(data_02097d48, which), &oam, 1);
    idx = NNS_G2dFontFindGlyphIndex(font, c);
    if (idx == 0xffff) {
        idx = font->pRes->alterCharIndex;
    }
    mgr->unk_00c = NNS_G2dFontGetCharWidthsFromIndex(font, idx)->charWidth + block->unk_10_6;
}

}
