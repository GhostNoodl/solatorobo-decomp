#ifndef NNSYS_G2D_IMAGE_H
#define NNSYS_G2D_IMAGE_H

#include "types.h"
#include "nnsys/g2d/g2d_Load.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum NNS_G2D_VRAM_TYPE {
    NNS_G2D_VRAM_TYPE_3DMAIN = 0,
    NNS_G2D_VRAM_TYPE_2DMAIN = 1,
    NNS_G2D_VRAM_TYPE_2DSUB = 2,
    NNS_G2D_VRAM_TYPE_MAX = 3
} NNS_G2D_VRAM_TYPE;

#define NNS_G2D_VRAM_ADDR_NOT_INITIALIZED 0xFFFFFFFF

typedef struct NNSG2dVRamLocation {
    u32 baseAddrOfVram[NNS_G2D_VRAM_TYPE_MAX];
} NNSG2dVRamLocation;

typedef struct NNSG2dImageAttr {
    /* 0x00 */ int sizeS;
    /* 0x04 */ int sizeT;
    /* 0x08 */ int fmt;
    /* 0x0c */ BOOL bExtendedPlt;
    /* 0x10 */ int plttUse;
    /* 0x14 */ int mappingType;
} NNSG2dImageAttr;

typedef struct NNSG2dImageProxy {
    /* 0x00 */ NNSG2dVRamLocation vramLocation;
    /* 0x0c */ NNSG2dImageAttr attr;
} NNSG2dImageProxy; // size 0x24

typedef struct NNSG2dImagePaletteProxy {
    /* 0x0 */ int fmt;
    /* 0x4 */ BOOL bExtendedPlt;
    /* 0x8 */ NNSG2dVRamLocation vramLocation;
} NNSG2dImagePaletteProxy; // size 0x14

void NNS_G2dInitImageProxy(NNSG2dImageProxy *pImg);
void NNS_G2dSetImageLocation(NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type, u32 addr);
u32 NNS_G2dGetImageLocation(const NNSG2dImageProxy *pImg, NNS_G2D_VRAM_TYPE type);
void NNS_G2dInitImagePaletteProxy(NNSG2dImagePaletteProxy *pImg);
void NNS_G2dSetImagePaletteLocation(NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type, u32 addr);
u32 NNS_G2dGetImagePaletteLocation(const NNSG2dImagePaletteProxy *pImg, NNS_G2D_VRAM_TYPE type);
void NNS_G2dLoadImage1DMapping(const NNSG2dCharacterData *pSrcData, u32 baseAddr, NNS_G2D_VRAM_TYPE type, NNSG2dImageProxy *pImgProxy);
void NNS_G2dLoadPaletteEx(const NNSG2dPaletteData *pSrcData, const NNSG2dPaletteCompressInfo *pCmpInfo, u32 addr, NNS_G2D_VRAM_TYPE type, NNSG2dImagePaletteProxy *pPltProxy);

#ifdef __cplusplus
}
#endif

#endif
