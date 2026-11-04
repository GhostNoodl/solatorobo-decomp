#include "Main/Gfx/GfxMgr.h"
#include "nnsys/g2d/g2d_Font.h"
#include "nitro/mi.h"

extern "C" {

extern VramBlock *GfxMgr_AllocPoolBlock(GfxMgr *mgr, VramPool *pool, u32 size);
extern void GfxMgr_PutStringBg(GfxMgr *mgr, void *arg);
extern void GfxMgr_PutStringOam(GfxMgr *mgr, void *arg);

VramBlock *GfxMgr_AllocCharBlock(GfxMgr *mgr, int width, int height, BOOL temporary) {
    VramBlock *block;
    u32 size = (((width + 7) >> 3) * ((height + 7) >> 3)) << 5;
    if (GfxMgr_FontTable[mgr->unk_004].mode == 4) {
        block = GfxMgr_AllocPoolBlock(mgr, &mgr->pools[0], size);
        block->kind = 4;
    } else {
        block = GfxMgr_AllocPoolBlock(mgr, &mgr->pools[1], size);
        block->kind = 3;
    }
    block->temporary = temporary;
    block->unk_10_2 = 0;
    block->unk_10_29 = 1;
    block->unk_10_30 = 1;
    block->unk_14 = 0;
    return block;
}

GfxCell *GfxMgr_NextCell(GfxMgr *mgr) {
    return &mgr->cells[mgr->unk_046++];
}

void *GfxMgr_GetFont(GfxMgr *mgr) {
    return &mgr->fonts[mgr->unk_004]->res;
}

void GfxMgr_SetOamCache(GfxMgr *mgr, void *arg) {
    mgr->unk_658 = (u32)arg;
}

void func_0203a4dc(GfxMgr *mgr, void *arg) {
    mgr->unk_65c = (u32)arg;
}

static inline bool GfxSys_IsFlag(GfxSys *sys) {
    return sys->unk_a30_4 ? TRUE : FALSE;
}

void GfxMgr_PutString(GfxMgr *mgr, void *arg) {
    switch (GfxMgr_FontTable[mgr->unk_004].mode) {
    case 0:
        break;
    case 1:
        if (gGfxSys->state == 2 && !GfxSys_IsFlag(gGfxSys)) {
            break;
        }
        GfxMgr_PutStringBg(mgr, arg);
        break;
    case 2:
        if (gGfxSys->state == 2 && !gGfxSys->unk_a30_4) {
            GfxMgr_PutStringBg(mgr, arg);
        }
        break;
    case 3:
    case 4:
        if (gGfxSys->state == 1) {
            GfxMgr_PutStringOam(mgr, arg);
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
extern void *GfxSys_GetOamMgr(GfxSys *sys, int which);
extern BOOL NNS_G2dEntryOamManagerOam(void *mgr, const void *oam, u16 num);

void GfxMgr_PutChar(GfxMgr *mgr, u16 c) {
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

    mode = GfxMgr_FontTable[mgr->unk_004].mode;
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
        block = (VramBlock *)GfxMgr_AllocCharBlock(mgr, w, h, TRUE);
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
    NNS_G2dEntryOamManagerOam(GfxSys_GetOamMgr(gGfxSys, which), &oam, 1);
    idx = NNS_G2dFontFindGlyphIndex(font, c);
    if (idx == 0xffff) {
        idx = font->pRes->alterCharIndex;
    }
    mgr->unk_00c = NNS_G2dFontGetCharWidthsFromIndex(font, idx)->charWidth + block->unk_10_6;
}

#ifdef NONMATCHING
// GfxMgr_DrawBlocksOam (0x12c bytes, draws the OBJs of glyph blocks drawn earlier by GfxMgr_PutChar; reached through the
// GfxMgr.cpp tail-call wrapper): 10 / 0 (raw / register-masked). This file's .text ends at 0x0203a984, so it goes
// here once it matches. Blocker: colouring of codegen temps only (the blocks[i] load and the (addr >> 5) >> shift
// temp). History: docs/MATCHING.md rounds raC, mainbig5, nmA, mtA (search "0203a984"); docs/UNMATCHED.md.
void GfxMgr_DrawBlocksOam(GfxMgr *mgr, VramBlock **blocks, u16 n) {
    int shift;
    int which;
    u16 i;
    GfxOamTmp buf[128];
    int mode;
    int pal;
    u8 type;
    VramBlock *b;
    mode = GfxMgr_FontTable[mgr->unk_004].mode;
    if (mode == 1 || mode == 2) {
        return;
    }
    type = mgr->fontHeights[mgr->unk_004];
    pal = 0;
    if (type == 1) {
        pal = (int)mgr->unk_008 >> 4;
    } else if (type == 2) {
        pal = (int)mgr->unk_008 / 5 + 1;
    }
    if (mode == 4) {
        pal += mgr->plttSlots[2];
        shift = mgr->pools[0].alignShift;
        which = 0;
    } else {
        pal += mgr->plttSlots[3];
        shift = mgr->pools[1].alignShift;
        which = 1;
    }
    for (i = 0; i < n; i++) {
        int ox;
        int nm;
        int oy;
        b = blocks[i];
        ox = b->unk_10_6;
        nm = (b->addr >> 5) >> shift;
        oy = b->unk_10_14;
        buf[i].attr01 = b->unk_14 | (oy & 0xff) | ((u32)(ox << 23) >> 7);
        buf[i].attr2 = nm | (pal << 12);
    }
    NNS_G2dEntryOamManagerOam(GfxSys_GetOamMgr(gGfxSys, which), buf, n);
}
#endif

}
