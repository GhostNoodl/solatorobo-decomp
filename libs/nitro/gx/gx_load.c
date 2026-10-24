#include "nitro/gx.h"
#include "nitro/gx_vramcnt.h"
#include "nitro/gx_bgcnt.h"
#include "nitro/mi.h"

#pragma force_active on

void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL wait);
void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL wait);
void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, void (*callback)(void *), void *arg, BOOL wait);
void MI_WaitDma(u32 dmaNo);

/* TWL-only NDMA functions (absolute symbols, see config/usa/arm9/abs_symbols.txt) */
void func_0228de80(u32 ndmaNo, const void *src, void *dest, u32 size);     /* MI_NDmaCopy */
void func_0228df34(u32 ndmaNo, const void *src, void *dest, u32 size, void (*callback)(void *), void *arg); /* MI_NDmaCopyAsync */
void func_0228dfb8(u32 ndmaNo);                                            /* MI_WaitNDma */

/* Static state of gx_load.c (.bss, still owned by the surrounding gap). */
typedef struct {
    u32 unk_00;
    u32 objExtPlttLCDCBlk;
    GXVRamOBJExtPltt objExtPltt;
    u32 unk_0c[3];
    GXVRamSubOBJExtPltt subObjExtPltt;
} GXLoadObjState;

typedef struct {
    u32 unk_00;
    u32 texLCDCBlk1;
    u32 texPlttLCDCBlk;
    GXVRamTexPltt texPltt;
    u32 unk_10;
    GXVRamTex tex;
    u32 texLCDCBlk2;
    u32 szTexBlk1;
} GXLoadTexState;

typedef struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} GXTexStartAddr;

extern GXLoadObjState data_0208eb10;
extern GXLoadTexState data_0208eb2c;
extern const GXTexStartAddr data_02075174[];  /* sTexStartAddrTable */
extern const u16 data_02075164[];  /* sTexPlttStartAddrTable */

#define GXi_DMA_NOT_USE ((u32)-1)

static inline void GXi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo != GXi_DMA_NOT_USE && size > 0x1c) {
        if (dmaNo > 3) {
            if ((((u32)src | (u32)dest | size) & 3) == 0) {
                func_0228de80(dmaNo - 4, src, dest, size);
            } else {
                MI_CpuCopy16(src, dest, size);
            }
        } else {
            MIi_DmaCopy16(dmaNo, src, dest, size, TRUE);
        }
    } else {
        MI_CpuCopy16(src, dest, size);
    }
}

static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo != GXi_DMA_NOT_USE && size > 0x30) {
        if (dmaNo > 3) {
            func_0228de80(dmaNo - 4, src, dest, size);
        } else {
            MIi_DmaCopy32(dmaNo, src, dest, size, TRUE);
        }
    } else {
        MI_CpuCopy32(src, dest, size);
    }
}

static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, void (*callback)(void *), void *arg)
{
    if (dmaNo != GXi_DMA_NOT_USE) {
        if (dmaNo > 3) {
            func_0228df34(dmaNo - 4, src, dest, size, callback, arg);
        } else {
            MIi_DmaCopy32Async(dmaNo, src, dest, size, callback, arg, TRUE);
        }
    } else {
        MI_CpuCopy32(src, dest, size);
    }
}

static inline void GXi_WaitDma(u32 dmaNo)
{
    if (dmaNo != GXi_DMA_NOT_USE) {
        if (dmaNo > 3) {
            func_0228dfb8(dmaNo - 4);
        } else {
            MI_WaitDma(dmaNo);
        }
    }
}

void GX_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_BG_PLTT + offset), szByte);
}

void GXS_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_DB_BG_PLTT + offset), szByte);
}

void GX_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_OBJ_PLTT + offset), szByte);
}

void GXS_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_DB_OBJ_PLTT + offset), szByte);
}

void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_OAM + offset), szByte);
}

void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_DB_OAM + offset), szByte);
}

void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_OBJ_VRAM + offset), szByte);
}

void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_DB_OBJ_VRAM + offset), szByte);
}

void GXS_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG3ScrPtr();
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((u32)ptr + offset), szByte);
}

void GX_BeginLoadOBJExtPltt (void)
{
    data_0208eb10.objExtPltt = GX_ResetBankForOBJExtPltt();

    switch (data_0208eb10.objExtPltt) {
    case GX_VRAM_OBJEXTPLTT_NONE:
        break;
    case GX_VRAM_OBJEXTPLTT_0_F:
        data_0208eb10.objExtPlttLCDCBlk = HW_LCDC_VRAM_F;
        break;
    case GX_VRAM_OBJEXTPLTT_0_G:
        data_0208eb10.objExtPlttLCDCBlk = HW_LCDC_VRAM_G;
        break;
    }
}

void GX_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(data_0208eb10.objExtPlttLCDCBlk + destSlotAddr), szByte, NULL, NULL);
}

void GX_EndLoadOBJExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForOBJExtPltt(data_0208eb10.objExtPltt);
    data_0208eb10.objExtPltt = GX_VRAM_OBJEXTPLTT_NONE;
    data_0208eb10.objExtPlttLCDCBlk = 0;
}

void GXS_BeginLoadOBJExtPltt (void)
{
    data_0208eb10.subObjExtPltt = GX_ResetBankForSubOBJExtPltt();
}

void GXS_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(HW_LCDC_VRAM_I + destSlotAddr), szByte, NULL, NULL);
}

void GXS_EndLoadOBJExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForSubOBJExtPltt(data_0208eb10.subObjExtPltt);
    data_0208eb10.subObjExtPltt = GX_VRAM_SUB_OBJEXTPLTT_NONE;
}

void GX_BeginLoadTex (void)
{
    data_0208eb2c.tex = GX_ResetBankForTex();
    data_0208eb2c.texLCDCBlk1 = data_02075174[data_0208eb2c.tex].blk1 << 12;
    data_0208eb2c.texLCDCBlk2 = data_02075174[data_0208eb2c.tex].blk2 << 12;
    data_0208eb2c.szTexBlk1 = data_02075174[data_0208eb2c.tex].szBlk1 << 12;
}

void GX_LoadTex(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    void *pLCDC;

    if (data_0208eb2c.texLCDCBlk2 == 0) {
        pLCDC = (void *)(data_0208eb2c.texLCDCBlk1 + destSlotAddr);
    } else {
        if (destSlotAddr + szByte < data_0208eb2c.szTexBlk1) {
            pLCDC = (void *)(data_0208eb2c.texLCDCBlk1 + destSlotAddr);
        } else if (destSlotAddr >= data_0208eb2c.szTexBlk1) {
            pLCDC = (void *)(data_0208eb2c.texLCDCBlk2 + destSlotAddr - data_0208eb2c.szTexBlk1);
        } else {
            void *pLCDC2 = (void *)data_0208eb2c.texLCDCBlk2;
            u32 sz = data_0208eb2c.szTexBlk1 - destSlotAddr;
            pLCDC = (void *)(data_0208eb2c.texLCDCBlk1 + destSlotAddr);
            GXi_DmaCopy32(GXi_DmaId, pSrc, pLCDC, sz);
            GXi_DmaCopy32Async(GXi_DmaId, (const u8 *)pSrc + sz, pLCDC2, szByte - sz, NULL, NULL);
            return;
        }
    }
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, pLCDC, szByte, NULL, NULL);
}

void GX_EndLoadTex(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTex(data_0208eb2c.tex);
    data_0208eb2c.szTexBlk1 = 0;
    data_0208eb2c.texLCDCBlk2 = 0;
    data_0208eb2c.texLCDCBlk1 = 0;
    data_0208eb2c.tex = GX_VRAM_TEX_NONE;
}

void GX_BeginLoadTexPltt (void)
{
    data_0208eb2c.texPltt = GX_ResetBankForTexPltt();
    data_0208eb2c.texPlttLCDCBlk = data_02075164[data_0208eb2c.texPltt >> 4] << 12;
}

void GX_LoadTexPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(data_0208eb2c.texPlttLCDCBlk + destSlotAddr), szByte, NULL, NULL);
}

void GX_EndLoadTexPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTexPltt(data_0208eb2c.texPltt);
    data_0208eb2c.texPltt = GX_VRAM_TEXPLTT_NONE;
    data_0208eb2c.texPlttLCDCBlk = 0;
}
