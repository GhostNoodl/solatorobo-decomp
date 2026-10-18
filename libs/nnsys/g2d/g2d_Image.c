#include "nnsys/g2d/g2d_Image.h"
#include "nitro/gx.h"

void DC_FlushRange(const void *startAddr, u32 nBytes);
void GX_BeginLoadTex(void);
void GX_LoadTex(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTex(void);
void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);
void GX_BeginLoadOBJExtPltt(void);
void GX_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadOBJExtPltt(void);
void GX_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
void GXS_BeginLoadOBJExtPltt(void);
void GXS_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GXS_EndLoadOBJExtPltt(void);
void GXS_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte);
void GX_BeginLoadTexPltt(void);
void GX_LoadTexPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
void GX_EndLoadTexPltt(void);

#define REG_DISPCNT_ADDR    0x04000000
#define REG_DB_DISPCNT_ADDR 0x04001000
#define reg_GX_DISPCNT      (*(volatile u32 *)REG_DISPCNT_ADDR)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)REG_DB_DISPCNT_ADDR)
#define DISPCNT_OBJMAP_CH_MASK 0x00300010

#define GX_OBJVRAMMODE_CHAR_2D 0
#define GX_TEXFMT_PLTT16       3
#define GX_TEXPLTTCOLOR0_TRNS  1

static inline void GX_SetOBJVRamModeChar(int mode) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~DISPCNT_OBJMAP_CH_MASK) | mode;
}

static inline void GXS_SetOBJVRamModeChar(int mode) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~DISPCNT_OBJMAP_CH_MASK) | mode;
}

static inline void InitializeVRamLocation_(NNSG2dVRamLocation *pVramLocation) {
    int i;
    for (i = 0; i < NNS_G2D_VRAM_TYPE_MAX; i++) {
        pVramLocation->baseAddrOfVram[i] = NNS_G2D_VRAM_ADDR_NOT_INITIALIZED;
    }
}

static inline void SetVramLocation_(NNSG2dVRamLocation *pVramLocation, NNS_G2D_VRAM_TYPE type, u32 addr) {
    pVramLocation->baseAddrOfVram[type] = addr;
}

static inline u32 GetVramLocation_(const NNSG2dVRamLocation *pVramLocation, NNS_G2D_VRAM_TYPE type) {
    return pVramLocation->baseAddrOfVram[type];
}

static inline int GetPow_(u16 num) {
    switch (num) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 16:
        return 4;
    case 32:
        return 5;
    default:
        return 0;
    }
}

static inline void CopyCharDataToImageAttr_(const NNSG2dCharacterData *pSrc, NNSG2dImageAttr *pDst) {
    if (pSrc->mapingType == GX_OBJVRAMMODE_CHAR_2D) {
        pDst->sizeS = GetPow_(pSrc->W);
        pDst->sizeT = GetPow_(pSrc->H);
    } else {
        pDst->sizeS = pSrc->W;
        pDst->sizeT = pSrc->H;
    }

    pDst->fmt = pSrc->pixelFmt;
    pDst->bExtendedPlt = FALSE;
    pDst->plttUse = GX_TEXPLTTCOLOR0_TRNS;
    pDst->mappingType = pSrc->mapingType;
}

static inline void DoLoadingToVram_(const NNSG2dCharacterData *pSrcData, u32 baseAddr, NNS_G2D_VRAM_TYPE type) {
    DC_FlushRange(pSrcData->pRawData, pSrcData->szByte);
    switch (type) {
    case NNS_G2D_VRAM_TYPE_3DMAIN:
        GX_BeginLoadTex();
        GX_LoadTex((void *)pSrcData->pRawData, baseAddr, pSrcData->szByte);
        GX_EndLoadTex();
        break;
    case NNS_G2D_VRAM_TYPE_2DMAIN:
        GX_LoadOBJ((void *)pSrcData->pRawData, baseAddr, pSrcData->szByte);
        break;
    case NNS_G2D_VRAM_TYPE_2DSUB:
        GXS_LoadOBJ((void *)pSrcData->pRawData, baseAddr, pSrcData->szByte);
        break;
    default:
        break;
    }
}

static inline void SetOBJVRamModeCharacterMapping_(NNS_G2D_VRAM_TYPE vramType, int vramMode) {
    switch (vramType) {
    case NNS_G2D_VRAM_TYPE_3DMAIN:
        break;
    case NNS_G2D_VRAM_TYPE_2DMAIN:
        GX_SetOBJVRamModeChar(vramMode);
        break;
    case NNS_G2D_VRAM_TYPE_2DSUB:
        GXS_SetOBJVRamModeChar(vramMode);
        break;
    default:
        break;
    }
}

static inline void SetupImageProxyPrams_(const NNSG2dCharacterData *pSrcData, u32 baseAddr, NNS_G2D_VRAM_TYPE type, NNSG2dImageProxy *pImgProxy) {
    CopyCharDataToImageAttr_(pSrcData, &pImgProxy->attr);
    NNS_G2dSetImageLocation(pImgProxy, type, baseAddr);
}

static inline void DoLoadingPalette_(const NNSG2dPaletteData *pSrcData, u32 srcOffset, u32 addr, u32 szByte, NNS_G2D_VRAM_TYPE type) {
    const void *pSrcRawData = (const void *)((const u8 *)pSrcData->pRawData + srcOffset);

    DC_FlushRange(pSrcData->pRawData, pSrcData->szByte);

    switch (type) {
    case NNS_G2D_VRAM_TYPE_2DMAIN:
        if (pSrcData->bExtendedPlt) {
            GX_BeginLoadOBJExtPltt();
            GX_LoadOBJExtPltt(pSrcRawData, addr, szByte);
            GX_EndLoadOBJExtPltt();
        } else {
            GX_LoadOBJPltt(pSrcRawData, addr, szByte);
        }
        break;
    case NNS_G2D_VRAM_TYPE_2DSUB:
        if (pSrcData->bExtendedPlt) {
            GXS_BeginLoadOBJExtPltt();
            GXS_LoadOBJExtPltt(pSrcRawData, addr, szByte);
            GXS_EndLoadOBJExtPltt();
        } else {
            GXS_LoadOBJPltt(pSrcRawData, addr, szByte);
        }
        break;
    case NNS_G2D_VRAM_TYPE_3DMAIN:
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(pSrcRawData, addr, szByte);
        GX_EndLoadTexPltt();
        break;
    default:
        break;
    }
}

static inline u32 CalcSizePerOnePltt_(const NNSG2dPaletteData *pSrcData) {
    if (pSrcData->fmt == GX_TEXFMT_PLTT16) {
        return 16 * sizeof(u16);
    } else {
        return 256 * sizeof(u16);
    }
}

static inline u16 GetCompressedPlttOriginalIndex_(const NNSG2dPaletteCompressInfo *pCmpInfo, u16 idx) {
    return *(((u16 *)pCmpInfo->pPlttIdxTbl) + idx);
}

static inline void DoLoadingPaletteEx_(const NNSG2dPaletteData *pSrcData, const NNSG2dPaletteCompressInfo *pCmpInfo, u32 addr, NNS_G2D_VRAM_TYPE type) {
    u16 i;
    u32 offsetAddr;
    const u32 szOnePltt = CalcSizePerOnePltt_(pSrcData);
    const u32 numIdx = pCmpInfo->numPalette;

    for (i = 0; i < numIdx; i++) {
        offsetAddr = GetCompressedPlttOriginalIndex_(pCmpInfo, i) * szOnePltt;
        DoLoadingPalette_(pSrcData, szOnePltt * i, addr + offsetAddr, szOnePltt, type);
    }
}

void NNS_G2dInitImageProxy(NNSG2dImageProxy *pImg) {
    InitializeVRamLocation_(&pImg->vramLocation);
}

void NNS_G2dSetImageLocation(NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type, u32 addr) {
    SetVramLocation_(&pImg->vramLocation, type, addr);
}

u32 NNS_G2dGetImageLocation(const NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type) {
    return GetVramLocation_(&pImg->vramLocation, type);
}

void NNS_G2dInitImagePaletteProxy(NNSG2dImagePaletteProxy *pImg) {
    InitializeVRamLocation_(&pImg->vramLocation);
}

void NNS_G2dSetImagePaletteLocation(NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type, u32 addr) {
    SetVramLocation_(&pImg->vramLocation, type, addr);
}

u32 NNS_G2dGetImagePaletteLocation(const NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type) {
    return GetVramLocation_(&pImg->vramLocation, type);
}

void NNS_G2dLoadImage1DMapping(const NNSG2dCharacterData *pSrcData, u32 baseAddr, NNS_G2D_VRAM_TYPE type, NNSG2dImageProxy *pImgProxy) {
    SetOBJVRamModeCharacterMapping_(type, pSrcData->mapingType);

    DoLoadingToVram_(pSrcData, baseAddr, type);

    SetupImageProxyPrams_(pSrcData, baseAddr, type, pImgProxy);
}

void NNS_G2dLoadPaletteEx(const NNSG2dPaletteData *pSrcData, const NNSG2dPaletteCompressInfo *pCmpInfo, u32 addr, NNS_G2D_VRAM_TYPE type, NNSG2dImagePaletteProxy *pPltProxy) {
    DoLoadingPaletteEx_(pSrcData, pCmpInfo, addr, type);

    pPltProxy->fmt = pSrcData->fmt;
    pPltProxy->bExtendedPlt = pSrcData->bExtendedPlt;

    NNS_G2dSetImagePaletteLocation(pPltProxy, type, addr);
}
