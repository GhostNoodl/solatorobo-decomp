#ifndef NNSYS_G2D_LOAD_H
#define NNSYS_G2D_LOAD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem G2D binary resource loaders (NANR, NCER, NCGR, NCLR, NSCR).

#define NNS_G2D_UNPACK_OFFSET_PTR(ptr, base) (void *)((u32)(ptr) + (u32)(base))

#define NNS_G2D_BLKSIG_ANIMBANK            0x41424e4b // 'ABNK'
#define NNS_G2D_BLKSIG_CELLBANK            0x4345424b // 'CEBK'
#define NNS_G2D_BINBLK_SIG_CHARACTERDATA   0x43484152 // 'CHAR'
#define NNS_G2D_BINBLK_SIG_PALETTEDATA     0x504c5454 // 'PLTT'
#define NNS_G2D_BINBLK_SIG_PALETTECOMPINFO 0x50434d50 // 'PCMP'
#define NNS_G2D_BINBLK_SIG_SCRDATA         0x5343524e // 'SCRN'

typedef struct NNSG2dBinaryFileHeader {
    /* 0x0 */ u32 signature;
    /* 0x4 */ u16 byteOrder;
    /* 0x6 */ u16 version;
    /* 0x8 */ u32 fileSize;
    /* 0xc */ u16 headerSize;
    /* 0xe */ u16 dataBlocks;
} NNSG2dBinaryFileHeader; // size 0x10

typedef struct NNSG2dBinaryBlockHeader {
    /* 0x0 */ u32 kind;
    /* 0x4 */ u32 size;
} NNSG2dBinaryBlockHeader; // size 0x8

typedef struct NNSG2dUserExDataBlock {
    /* 0x0 */ u32 blkTypeID;
    /* 0x4 */ u32 blkSize;
} NNSG2dUserExDataBlock; // size 0x8

typedef struct NNSG2dUserExCellAttr {
    /* 0x0 */ u32 *pAttr;
} NNSG2dUserExCellAttr;

typedef struct NNSG2dUserExCellAttrBank {
    /* 0x0 */ u16 numCells;
    /* 0x2 */ u16 numAttribute;
    /* 0x4 */ NNSG2dUserExCellAttr *pCellAttrArray;
} NNSG2dUserExCellAttrBank;

typedef struct NNSG2dUserExAnimFrameAttr {
    /* 0x0 */ u32 *pAttr;
} NNSG2dUserExAnimFrameAttr;

typedef struct NNSG2dUserExAnimSequenceAttr {
    /* 0x0 */ u16 numFrames;
    /* 0x2 */ u16 pad16;
    /* 0x4 */ u32 *pAttr;
    /* 0x8 */ NNSG2dUserExAnimFrameAttr *pAnmFrmAttrArray;
} NNSG2dUserExAnimSequenceAttr; // size 0xc

typedef struct NNSG2dUserExAnimAttrBank {
    /* 0x0 */ u16 numSequences;
    /* 0x2 */ u16 numAttribute;
    /* 0x4 */ NNSG2dUserExAnimSequenceAttr *pAnmSeqAttrArray;
} NNSG2dUserExAnimAttrBank;

typedef struct NNSG2dAnimFrameData {
    /* 0x0 */ void *pContent;
    /* 0x4 */ u16 frames;
    /* 0x6 */ u16 pad16;
} NNSG2dAnimFrameData; // size 0x8

typedef struct NNSG2dAnimSequenceData {
    /* 0x0 */ u16 numFrames;
    /* 0x2 */ u16 loopStartFrameIdx;
    /* 0x4 */ u32 animType;
    /* 0x8 */ u32 playMode;
    /* 0xc */ NNSG2dAnimFrameData *pAnmFrameArray;
} NNSG2dAnimSequenceData; // size 0x10

typedef struct NNSG2dAnimBankData {
    /* 0x00 */ u16 numSequences;
    /* 0x02 */ u16 numTotalFrames;
    /* 0x04 */ NNSG2dAnimSequenceData *pSequenceArrayHead;
    /* 0x08 */ NNSG2dAnimFrameData *pFrameArrayHead;
    /* 0x0c */ void *pAnimContents;
    /* 0x10 */ void *pStringBank;
    /* 0x14 */ void *pExtendedData;
} NNSG2dAnimBankData; // size 0x18

typedef struct NNSG2dAnimBankDataBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dAnimBankData animBankData;
} NNSG2dAnimBankDataBlock;

typedef struct NNSG2dCellOAMAttrData {
    /* 0x0 */ u16 attr0;
    /* 0x2 */ u16 attr1;
    /* 0x4 */ u16 attr2;
} NNSG2dCellOAMAttrData; // size 0x6

typedef struct NNSG2dCellData {
    /* 0x0 */ u16 numOAMAttrs;
    /* 0x2 */ u16 cellAttr;
    /* 0x4 */ NNSG2dCellOAMAttrData *pOamAttrArray;
} NNSG2dCellData; // size 0x8

typedef struct NNSG2dCellBoundingRectS16 {
    /* 0x0 */ s16 maxX;
    /* 0x2 */ s16 maxY;
    /* 0x4 */ s16 minX;
    /* 0x6 */ s16 minY;
} NNSG2dCellBoundingRectS16;

typedef struct NNSG2dCellDataWithBR {
    /* 0x0 */ NNSG2dCellData cellData;
    /* 0x8 */ NNSG2dCellBoundingRectS16 boundingRect;
} NNSG2dCellDataWithBR; // size 0x10

typedef struct NNSG2dCellVramTransferData {
    /* 0x0 */ u32 srcDataOffset;
    /* 0x4 */ u32 szByte;
} NNSG2dCellVramTransferData;

typedef struct NNSG2dVramTransferData {
    /* 0x0 */ u32 szByteMax;
    /* 0x4 */ NNSG2dCellVramTransferData *pCellTransferDataArray;
} NNSG2dVramTransferData;

typedef struct NNSG2dCellDataBank {
    /* 0x00 */ u16 numCells;
    /* 0x02 */ u16 cellBankAttr;
    /* 0x04 */ NNSG2dCellData *pCellDataArrayHead;
    /* 0x08 */ int mappingMode;
    /* 0x0c */ void *pVramTransferData;
    /* 0x10 */ void *pStringBank;
    /* 0x14 */ void *pExtendedData;
} NNSG2dCellDataBank; // size 0x18

typedef struct NNSG2dCellDataBankBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dCellDataBank cellDataBank;
} NNSG2dCellDataBankBlock;

static inline BOOL NNSi_G2dCellBankHasBR(const NNSG2dCellDataBank *pCellBank) {
    return (pCellBank->cellBankAttr & 0x1);
}

typedef struct NNSG2dCharacterData {
    /* 0x00 */ u16 H;
    /* 0x02 */ u16 W;
    /* 0x04 */ int pixelFmt;
    /* 0x08 */ int mapingType;
    /* 0x0c */ u32 characterFmt;
    /* 0x10 */ u32 szByte;
    /* 0x14 */ void *pRawData;
} NNSG2dCharacterData; // size 0x18

typedef struct NNSG2dCharacterDataBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dCharacterData characterData;
} NNSG2dCharacterDataBlock;

typedef struct NNSG2dPaletteData {
    /* 0x0 */ int fmt;
    /* 0x4 */ BOOL bExtendedPlt;
    /* 0x8 */ u32 szByte;
    /* 0xc */ void *pRawData;
} NNSG2dPaletteData; // size 0x10

typedef struct NNSG2dPaletteDataBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dPaletteData paletteData;
} NNSG2dPaletteDataBlock;

typedef struct NNSG2dPaletteCompressInfo {
    /* 0x0 */ u16 numPalette;
    /* 0x2 */ u16 pad16;
    /* 0x4 */ void *pPlttIdxTbl;
} NNSG2dPaletteCompressInfo;

typedef struct NNSG2dPaletteCompressDataBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dPaletteCompressInfo plttCmpInfo;
} NNSG2dPaletteCompressDataBlock;

typedef struct NNSG2dScreenData {
    /* 0x0 */ u16 screenWidth;
    /* 0x2 */ u16 screenHeight;
    /* 0x4 */ u16 colorMode;
    /* 0x6 */ u16 screenFormat;
    /* 0x8 */ u32 szByte;
    /* 0xc */ u32 rawData[];
} NNSG2dScreenData;

typedef struct NNSG2dScreenDataBlock {
    /* 0x0 */ NNSG2dBinaryBlockHeader blockHeader;
    /* 0x8 */ NNSG2dScreenData screenData;
} NNSG2dScreenDataBlock;

NNSG2dBinaryBlockHeader *NNS_G2dFindBinaryBlock(NNSG2dBinaryFileHeader *pBinFileHeader, u32 signature);
void NNSi_G2dUnpackUserExCellAttrBank(NNSG2dUserExCellAttrBank *pCellAttrBank);

BOOL NNS_G2dGetUnpackedAnimBank(void *pNanrFile, NNSG2dAnimBankData **ppAnimBank);
void NNS_G2dUnpackNAN(NNSG2dAnimBankData *pData);
const NNSG2dAnimSequenceData *NNS_G2dGetAnimSequenceByIdx(const NNSG2dAnimBankData *pAnimBank, u16 idx);

BOOL NNS_G2dGetUnpackedCellBank(void *pNcerFile, NNSG2dCellDataBank **ppCellBank);
const NNSG2dCellData *NNS_G2dGetCellDataByIdx(const NNSG2dCellDataBank *pCellData, u16 idx);
void NNS_G2dUnpackNCE(NNSG2dCellDataBank *pCellData);

BOOL NNS_G2dGetUnpackedCharacterData(void *pNcgrFile, NNSG2dCharacterData **ppCharData);
void NNS_G2dUnpackNCG(NNSG2dCharacterData *pCharData);
BOOL NNS_G2dGetUnpackedBGCharacterData(void *pNcgrFile, NNSG2dCharacterData **ppCharData);
void NNS_G2dUnpackBGNCG(NNSG2dCharacterData *pCharData);

BOOL NNS_G2dGetUnpackedPaletteData(void *pNclrFile, NNSG2dPaletteData **ppPltData);
BOOL NNS_G2dGetUnpackedPaletteCompressInfo(void *pNclrFile, NNSG2dPaletteCompressInfo **ppPltCmpInfo);
void NNSi_G2dUnpackNCLCmpInfo(NNSG2dPaletteCompressInfo *pPlttCmpInfo);
void NNS_G2dUnpackNCL(NNSG2dPaletteData *pPlttData);

BOOL NNS_G2dGetUnpackedScreenData(void *pNscrFile, NNSG2dScreenData **ppScrData);

#ifdef __cplusplus
}
#endif

#endif
