#ifndef NNSYS_G2D_CELLANIMATION_H
#define NNSYS_G2D_CELLANIMATION_H

#include "types.h"
#include "nnsys/g2d/g2d_Animation.h"
#include "nnsys/g2d/g2d_SRTControl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NNS_G2D_INVALID_CELL_TRANSFER_STATE_HANDLE 0xFFFFFFFF

typedef enum NNSG2dAnimationElement {
    NNS_G2D_ANIMELEMENT_INDEX = 0,
    NNS_G2D_ANIMELEMENT_INDEX_SRT = 1,
    NNS_G2D_ANIMELEMENT_INDEX_T = 2
} NNSG2dAnimationElement;

typedef struct NNSG2dAnimDataSRT {
    /* 0x0 */ u16 index;
    /* 0x2 */ u16 rotZ;
    /* 0x4 */ fx32 sx;
    /* 0x8 */ fx32 sy;
    /* 0xc */ s16 px;
    /* 0xe */ s16 py;
} NNSG2dAnimDataSRT;

typedef struct NNSG2dAnimDataT {
    /* 0x0 */ u16 index;
    /* 0x2 */ u16 pad_;
    /* 0x4 */ s16 px;
    /* 0x6 */ s16 py;
} NNSG2dAnimDataT;

typedef struct NNSG2dCellAnimation {
    /* 0x00 */ NNSG2dAnimController animCtrl;
    /* 0x30 */ const NNSG2dCellData *pCurrentCell;
    /* 0x34 */ const NNSG2dCellDataBank *pCellDataBank;
    /* 0x38 */ u32 cellTransferStateHandle;
    /* 0x3c */ NNSG2dSRTControl srtCtrl;
} NNSG2dCellAnimation; // size 0x58

void NNS_G2dInitCellAnimation(NNSG2dCellAnimation *pCellAnim, const NNSG2dAnimSequence *pAnimSeq, const NNSG2dCellDataBank *pCellDataBank);
void NNS_G2dSetCellAnimationSequence(NNSG2dCellAnimation *pCellAnim, const NNSG2dAnimSequence *pAnimSeq);
void NNS_G2dTickCellAnimation(NNSG2dCellAnimation *pCellAnim, fx32 frames);

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte);

#ifdef __cplusplus
}
#endif

#endif
