#include "nnsys/g2d/g2d_CellAnimation.h"

static inline NNSG2dAnimationElement NNSi_G2dGetAnimSequenceElementType(u32 animType) {
    return (NNSG2dAnimationElement)(animType & 0xFF);
}

static inline BOOL NNS_G2dCellDataBankHasVramTransferData(const NNSG2dCellDataBank *pCellBank) {
    return (BOOL)(pCellBank->pVramTransferData != NULL);
}

static inline BOOL NNSi_G2dIsCellAnimVramTransferHandleValid(const NNSG2dCellAnimation *pCellAnim) {
    return (BOOL)(pCellAnim->cellTransferStateHandle != NNS_G2D_INVALID_CELL_TRANSFER_STATE_HANDLE);
}

static inline const NNSG2dCellVramTransferData *NNSi_G2dGetCellVramTransferData(const NNSG2dCellDataBank *pCellBank, u16 cellIdx) {
    return &((const NNSG2dVramTransferData *)pCellBank->pVramTransferData)->pCellTransferDataArray[cellIdx];
}

static void ApplyCurrentAnimResult_(NNSG2dCellAnimation *pCellAnim) {
    const NNSG2dAnimDataSRT *pAnimResult = NULL;
    const NNSG2dCellDataBank *pCellBank = NULL;

    if (pCellAnim->animCtrl.pActiveCurrent->frames == 0) {
        return;
    }

    pAnimResult = (const NNSG2dAnimDataSRT *)NNS_G2dGetAnimCtrlCurrentElement(&pCellAnim->animCtrl);
    pCellBank = pCellAnim->pCellDataBank;

    pCellAnim->pCurrentCell = NNS_G2dGetCellDataByIdx(pCellBank, pAnimResult->index);

    {
        const NNSG2dAnimationElement elemType = NNSi_G2dGetAnimSequenceElementType(pCellAnim->animCtrl.pAnimSequence->animType);

        NNSi_G2dSrtcInitControl(&pCellAnim->srtCtrl, NNS_G2D_SRTCONTROLTYPE_SRT);

        if (elemType != NNS_G2D_ANIMELEMENT_INDEX) {
            if (elemType == NNS_G2D_ANIMELEMENT_INDEX_T) {
                const NNSG2dAnimDataT *pAnmResT = (const NNSG2dAnimDataT *)pAnimResult;
                NNSi_G2dSrtcSetTrans(&pCellAnim->srtCtrl, pAnmResT->px, pAnmResT->py);
            } else {
                NNSi_G2dSrtcSetSRTScale(&pCellAnim->srtCtrl, pAnimResult->sx, pAnimResult->sy);
                NNSi_G2dSrtcSetSRTRotZ(&pCellAnim->srtCtrl, pAnimResult->rotZ);
                NNSi_G2dSrtcSetTrans(&pCellAnim->srtCtrl, pAnimResult->px, pAnimResult->py);
            }
        }
    }

    if (NNS_G2dCellDataBankHasVramTransferData(pCellBank) && NNSi_G2dIsCellAnimVramTransferHandleValid(pCellAnim)) {
        const NNSG2dCellVramTransferData *pCellTransferData = NNSi_G2dGetCellVramTransferData(pCellBank, pAnimResult->index);

        NNS_G2dSetCellTransferStateRequested(pCellAnim->cellTransferStateHandle, pCellTransferData->srcDataOffset,
                                             pCellTransferData->szByte);
    }
}

static inline void InitCellAnimationImpl_(NNSG2dCellAnimation *pCellAnim, const NNSG2dAnimSequence *pAnimSeq,
                                          const NNSG2dCellDataBank *pCellDataBank, u32 cellTransferStateHandle) {
    pCellAnim->pCellDataBank = pCellDataBank;
    pCellAnim->cellTransferStateHandle = cellTransferStateHandle;

    NNSi_G2dSrtcInitControl(&pCellAnim->srtCtrl, NNS_G2D_SRTCONTROLTYPE_SRT);
    NNS_G2dInitAnimCtrl(&pCellAnim->animCtrl);
    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
}

void NNS_G2dInitCellAnimation(NNSG2dCellAnimation *pCellAnim, const NNSG2dAnimSequence *pAnimSeq, const NNSG2dCellDataBank *pCellDataBank) {
    InitCellAnimationImpl_(pCellAnim, pAnimSeq, pCellDataBank, NNS_G2D_INVALID_CELL_TRANSFER_STATE_HANDLE);
}

void NNS_G2dSetCellAnimationSequence(NNSG2dCellAnimation *pCellAnim, const NNSG2dAnimSequence *pAnimSeq) {
    NNS_G2dBindAnimCtrl(&pCellAnim->animCtrl, pAnimSeq);
    ApplyCurrentAnimResult_(pCellAnim);
}

void NNS_G2dTickCellAnimation(NNSG2dCellAnimation *pCellAnim, fx32 frames) {
    if (NNS_G2dTickAnimCtrl(&pCellAnim->animCtrl, frames)) {
        ApplyCurrentAnimResult_(pCellAnim);
    }
}
