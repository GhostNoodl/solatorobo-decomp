#include "Main/Gfx/GfxMgr.h"

extern "C" {


extern u8 data_02097ce4[];
extern const u8 data_02082798[0x60];

extern void *func_0203dec8(u32 size, int align);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void DC_FlushRange(const void *addr, u32 size);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
extern void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size);
extern u16 func_0203bdb0(GfxSys *obj, int a, int b);
extern void *func_0203bc20(GfxSys *obj, u32 size, int a);
extern void func_0203df40(void *ptr);
extern void func_020435e8(GfxPltt *src, void *dst, u32 size);


VramBlock *func_0203994c(GfxMgr *mgr, VramBlock *block) {
    VramBlock *prev;
    VramBlock *next;
    block->addr -= block->pad;
    ((u32 *)block)[4] = 0;
    prev = block->prev;
    if (prev != NULL && !prev->used) {
        VramBlock *old = block;
        if (block->next != NULL) {
            block->next->prev = prev;
        }
        block->prev->next = block->next;
        block->prev->size += block->size;
        block->size = 0;
        block = block->prev;
        old->addr = 0;
        old->prev = NULL;
        old->next = NULL;
    }
    next = block->next;
    if (next != NULL && !next->used) {
        if (next->next != NULL) {
            next->next->prev = block;
        }
        block->size += block->next->size;
        block->next->size = 0;
        next = block->next;
        block->next = next->next;
        next->addr = 0;
        next->prev = NULL;
        next->next = NULL;
    }
    return block->next;
}

void func_02039a34(GfxMgr *mgr) {
    int i;
    VramBlock *block;
    mgr->unk_004 = 0;
    mgr->unk_008 = 0;
    mgr->unk_00c = 0;
    mgr->unk_00e = 0;
    mgr->unk_010 = 0;
    mgr->unk_012 = 0;
    for (i = 0; i < 10; i++) {
        mgr->fonts[i] = NULL;
        mgr->fontHeights[i] = 0;
    }
    mgr->unk_046 = 0;
    mgr->unk_000 = -1;
    MI_CpuCopy8(data_02082798, data_02097ce4, 0x60);
    DC_FlushRange(data_02097ce4, 0x60);
    mgr->plttSlots[0] = func_0203bdb0(data_02097d48, 3, 4);
    GX_LoadBGPltt(data_02082798, mgr->plttSlots[0] << 5, 0x60);
    mgr->plttSlots[1] = func_0203bdb0(data_02097d48, 3, 5);
    GXS_LoadBGPltt(data_02082798, mgr->plttSlots[1] << 5, 0x60);
    mgr->plttSlots[2] = func_0203bdb0(data_02097d48, 3, 0);
    GX_LoadOBJPltt(data_02082798, mgr->plttSlots[2] << 5, 0x60);
    mgr->plttSlots[3] = func_0203bdb0(data_02097d48, 3, 2);
    GXS_LoadOBJPltt(data_02097ce4, mgr->plttSlots[3] << 5, 0x60);
    mgr->unk_658 = 0;
    mgr->unk_65c = 0;
    mgr->unk_650 = func_0203bc20(data_02097d48, 0x4000, 0);
    mgr->unk_654 = func_0203bc20(data_02097d48, 0x4000, 1);

    block = (VramBlock *)func_0203dec8(0x80 * sizeof(VramBlock), 4);
    MIi_CpuClearFast(0, block, 0x80 * sizeof(VramBlock));
    block->addr = 0x20;
    block->size = 0x4000 - 0x20;
    block->prev = NULL;
    block->next = NULL;
    ((u32 *)block)[4] = 0;
    mgr->pools[0].blocks = block;
    mgr->pools[0].alignShift = 2;
    mgr->pools[0].numBlocks = 0x80;

    block = (VramBlock *)func_0203dec8(0x80 * sizeof(VramBlock), 4);
    MIi_CpuClearFast(0, block, 0x80 * sizeof(VramBlock));
    block->addr = 0x20;
    block->size = 0x4000 - 0x20;
    block->prev = NULL;
    block->next = NULL;
    ((u32 *)block)[4] = 0;
    mgr->unk_678 = 0x14;
    mgr->pools[1].alignShift = 2;
    mgr->pools[1].blocks = block;
    mgr->pools[1].numBlocks = 0x80;
    mgr->unk_67c = NULL;
    mgr->unk_680 = 0;
    mgr->unk_67a = 0x16;
}

void func_02039c54(GfxMgr *mgr, int mode) {
    VramBlock *block;
    block = mgr->pools[0].blocks;
    do {
        if (block->used) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->unk_69c[0] = 0;
    mgr->unk_69c[1] = 0;
    mgr->unk_69c[2] = 0;
    mgr->unk_69c[3] = 0;
    if (mgr->unk_67c != NULL) {
        func_0203df40(mgr->unk_67c);
        mgr->unk_67c = NULL;
    }
    mgr->unk_680 = 0;
    DC_FlushRange(data_02097ce4, 0x60);
    mgr->plttSlots[0] = func_0203bdb0(data_02097d48, 3, 4);
    GX_LoadBGPltt(data_02082798, mgr->plttSlots[0] << 5, 0x60);
    mgr->plttSlots[1] = func_0203bdb0(data_02097d48, 3, 5);
    GXS_LoadBGPltt(data_02082798, mgr->plttSlots[1] << 5, 0x60);
    mgr->plttSlots[2] = func_0203bdb0(data_02097d48, 3, 0);
    GX_LoadOBJPltt(data_02082798, mgr->plttSlots[2] << 5, 0x60);
    mgr->plttSlots[3] = func_0203bdb0(data_02097d48, 3, 2);
    GXS_LoadOBJPltt(data_02097ce4, mgr->plttSlots[3] << 5, 0x60);
    mgr->unk_65c = 0;
    if (mode != 2) {
        mgr->unk_650 = func_0203bc20(data_02097d48, 0x4000, 0);
        mgr->unk_654 = func_0203bc20(data_02097d48, 0x4000, 1);
    }
    mgr->unk_650 = NULL;
    mgr->unk_654 = NULL;
}

void func_02039e0c(GfxMgr *mgr) {
    VramBlock *block;
    GfxPltt *pltt;
    int id;
    mgr->unk_046 = 0;
    mgr->unk_012 = 0;
    block = mgr->pools[0].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->pools[0].alignShift = ((int)(*(volatile u32 *)0x04000000 & 0x300010) >> 20) & 3;
    mgr->pools[1].alignShift = ((int)(*(volatile u32 *)0x04001000 & 0x300010) >> 20) & 3;
    pltt = &data_02097d48->pltt;
    id = pltt->id;
    if (mgr->unk_000 != id) {
        MI_CpuCopy8(data_02082798, data_02097ce4, 0x60);
        func_020435e8(pltt, data_02097ce4, 0x60);
        mgr->unk_000 = id;
        DC_FlushRange(data_02097ce4, 0x60);
        GX_LoadOBJPltt(data_02097ce4, mgr->plttSlots[2] << 5, 0x60);
    }
    mgr->unk_69c[0] = 0;
    mgr->unk_69c[1] = 0;
    mgr->unk_69c[2] = 0;
    mgr->unk_69c[3] = 0;
    if (mgr->unk_67c != NULL) {
        func_0203df40(mgr->unk_67c);
        mgr->unk_67c = NULL;
    }
    mgr->unk_680 = 0;
}

void func_02039f84(GfxMgr *mgr) {
    VramBlock *block;
    GfxPltt *pltt;
    int id;
    mgr->unk_046 = 0;
    mgr->unk_012 = 0;
    block = mgr->pools[0].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    block = mgr->pools[1].blocks;
    do {
        if (block->used && block->temporary == TRUE) {
            block = func_0203994c(mgr, block);
        } else {
            block = block->next;
        }
    } while (block != NULL);
    mgr->pools[0].alignShift = ((int)(*(volatile u32 *)0x04000000 & 0x300010) >> 20) & 3;
    mgr->pools[1].alignShift = ((int)(*(volatile u32 *)0x04001000 & 0x300010) >> 20) & 3;
    pltt = &data_02097d48->pltt;
    id = pltt->id;
    if (mgr->unk_000 != id) {
        MI_CpuCopy8(data_02082798, data_02097ce4, 0x60);
        func_020435e8(pltt, data_02097ce4, 0x60);
        mgr->unk_000 = id;
        DC_FlushRange(data_02097ce4, 0x60);
        GX_LoadOBJPltt(data_02097ce4, mgr->plttSlots[2] << 5, 0x60);
    }
}

// Draws a text canvas as 1D OBJs, or moves the OAM entries cached by an earlier draw.
typedef struct GfxCanvasVT {
    void (*drawGlyph)(void);
    void (*clear)(GfxCell *canvas, int cl);
} GfxCanvasVT;

typedef struct GfxOamBits {
    u32 y : 8;
    u32 unk_8 : 8;
    u32 x : 9;
    u32 unk_25 : 7;
    u32 charName : 10;
    u32 prio : 2;
    u32 pltt : 4;
    u32 unk_16 : 16;
} GfxOamBits;

typedef struct GfxOamCache {
    /* 0x0 */ u8 valid;
    /* 0x4 */ GfxOam *oams;
    /* 0x8 */ u16 unk_08;
    /* 0xa */ u16 count;
    /* 0xc */ s32 which;
} GfxOamCache;

extern void NNS_G2dCharCanvasInitForOBJ1D(GfxCell *canvas, void *charBase, int w, int h, int colorMode);
extern int NNS_G2dArrangeOBJ1D(GfxOam *oam, int w, int h, int x, int y, int color, int charName, int vramMode);
extern void *func_0203bbfc(GfxSys *sys, int which);
extern void NNS_G2dEntryOamManagerOam(void *mgr, const GfxOam *oam, u16 num);

static inline void GfxOam_SetX(GfxOam *oam, u16 x) { ((GfxOamBits *)oam)->x = x; }
static inline void GfxOam_SetY(GfxOam *oam, u16 y) { ((GfxOamBits *)oam)->y = y & 0x1ff; }
static inline s32 GfxOam_GetX(GfxOam *oam) {
    s32 x = ((GfxOamBits *)oam)->x;
    if (x > 0xff) {
        x |= ~0xff;
    }
    return x;
}

static inline s32 GfxOam_GetY(GfxOam *oam) {
    s32 y = ((GfxOamBits *)oam)->y;
    if (y > 0x7f) {
        y |= ~0xff;
    }
    return y;
}

void func_0203a0cc(GfxMgr *mgr, VramBlock *block, GfxCell *canvas, int width, int height, int pltt) {
    u32 base;
    int h;
    int which;
    GfxOam *oams;
    GfxOam buf[128];
    int shift;
    u32 a2;
    int i;
    u32 a0;
    int w;
    GfxOamCache *cache;
    int n;
    cache = (GfxOamCache *)mgr->unk_658;
    mgr->unk_658 = 0;
    if (cache == NULL || !cache->valid) {
        w = (width + 7) >> 3;
        h = (height + 7) >> 3;
        if (data_020827f8[mgr->unk_004].mode == 4) {
            pltt += mgr->plttSlots[2];
            shift = mgr->pools[0].alignShift;
            base = 0x6400000;
            which = 0;
        } else {
            pltt += mgr->plttSlots[3];
            shift = mgr->pools[1].alignShift;
            base = 0x6600000;
            which = 1;
        }
        NNS_G2dCharCanvasInitForOBJ1D(canvas, (void *)(base + block->addr), w, h, 4);
        if (!block->unk_10_2) {
            ((GfxCanvasVT *)((u32 *)canvas)[5])->clear(canvas, 0);
        }
        if (!block->unk_10_29) {
            return;
        }
        oams = cache != NULL ? cache->oams : buf;
        n = NNS_G2dArrangeOBJ1D(oams, w, h, mgr->unk_00c, mgr->unk_00e, 0, (block->addr >> 5) >> shift, shift);
        if (cache != NULL) {
            cache->which = which;
            cache->count = n;
            cache->valid = 1;
        }
        {
            s16 prio = mgr->unk_012;
            u32 dis = block->unk_10_30 ? 0 : 0x200;
            u32 mode = block->unk_10_31 ? 1 : 0;
            a2 = (prio << 10) | (pltt << 12);
            a0 = dis | (mode << 10);
        }
        for (i = 0; i < n; i++) {
            oams[i].attr01 = (oams[i].attr01 & 0xc1ffe0ff) | a0;
            oams[i].attr2 = (oams[i].attr2 & ~0xfc00) | a2;
        }
        NNS_G2dEntryOamManagerOam(func_0203bbfc(data_02097d48, which), oams, n);
    } else {
        GfxOam *oam = cache->oams;
        s32 dx;
        s32 dy;
        u16 j;
        if (!block->unk_10_29) {
            return;
        }
        dx = mgr->unk_00c - GfxOam_GetX(oam);
        dy = mgr->unk_00e - GfxOam_GetY(oam);
        for (j = 0; j < cache->count; j++, oam++) {
            s32 x = GfxOam_GetX(oam);
            s32 y;
            x += dx;
            GfxOam_SetX(oam, x);
            y = GfxOam_GetY(oam);
            y += dy;
            GfxOam_SetY(oam, y);
            ((GfxOamBits *)oam)->pltt = pltt & 0xf;
        }
        {
            void *om = func_0203bbfc(data_02097d48, cache->which);
            NNS_G2dEntryOamManagerOam(om, cache->oams, cache->count);
        }
    }
}

}
