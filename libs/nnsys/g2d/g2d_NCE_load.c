#include "nnsys/g2d/g2d_Load.h"

static void *GetPtrOamArrayHead_(NNSG2dCellDataBank *pCellBank) {
    if (NNSi_G2dCellBankHasBR(pCellBank)) {
        return (NNSG2dCellDataWithBR *)(pCellBank->pCellDataArrayHead) + pCellBank->numCells;
    } else {
        return pCellBank->pCellDataArrayHead + pCellBank->numCells;
    }
}

static void UnPackExtendedData_(void *pExData) {
    {
        NNSG2dUserExDataBlock *pBlk = (NNSG2dUserExDataBlock *)pExData;
        NNSG2dUserExCellAttrBank *pCellAttrBank = (NNSG2dUserExCellAttrBank *)(pBlk + 1);

        NNSi_G2dUnpackUserExCellAttrBank(pCellAttrBank);
    }
}

BOOL NNS_G2dGetUnpackedCellBank(void *pNcerFile, NNSG2dCellDataBank **ppCellBank) {
    {
        NNSG2dBinaryFileHeader *pBinFile = (NNSG2dBinaryFileHeader *)pNcerFile;
        {
            NNSG2dCellDataBankBlock *pBinBlk =
                (NNSG2dCellDataBankBlock *)NNS_G2dFindBinaryBlock(pBinFile, NNS_G2D_BLKSIG_CELLBANK);
            if (pBinBlk) {
                NNS_G2dUnpackNCE((void *)&pBinBlk->cellDataBank);
                *ppCellBank = &pBinBlk->cellDataBank;
                return TRUE;
            } else {
                *ppCellBank = NULL;
                return FALSE;
            }
        }
    }
}

const NNSG2dCellData *NNS_G2dGetCellDataByIdx(const NNSG2dCellDataBank *pCellData, u16 idx) {
    if (idx >= pCellData->numCells) {
        return NULL;
    }

    if (NNSi_G2dCellBankHasBR(pCellData)) {
        const NNSG2dCellDataWithBR *pCellBR = (const NNSG2dCellDataWithBR *)(pCellData->pCellDataArrayHead) + idx;
        return &pCellBR->cellData;
    } else {
        return pCellData->pCellDataArrayHead + idx;
    }
}

void NNS_G2dUnpackNCE(NNSG2dCellDataBank *pCellData) {
    {
        pCellData->pCellDataArrayHead = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pCellDataArrayHead, pCellData);
        {
            void *pHeadOfOAMData = GetPtrOamArrayHead_(pCellData);
            u16 i;
            NNSG2dCellData *pCell = NULL;

            for (i = 0; i < pCellData->numCells; i++) {
                pCell = (NNSG2dCellData *)(NNS_G2dGetCellDataByIdx(pCellData, i));
                pCell->pOamAttrArray = NNS_G2D_UNPACK_OFFSET_PTR(pCell->pOamAttrArray, pHeadOfOAMData);
            }
        }

        if (pCellData->pVramTransferData != NULL) {
            NNSG2dVramTransferData *pVramTsfmData;

            pCellData->pVramTransferData = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pVramTransferData, pCellData);
            pVramTsfmData = pCellData->pVramTransferData;
            pVramTsfmData->pCellTransferDataArray =
                NNS_G2D_UNPACK_OFFSET_PTR(pVramTsfmData->pCellTransferDataArray, pVramTsfmData);
            pCellData->pVramTransferData = pVramTsfmData;
        }

        if (pCellData->pExtendedData != NULL) {
            pCellData->pExtendedData = NNS_G2D_UNPACK_OFFSET_PTR(pCellData->pExtendedData, pCellData);
            UnPackExtendedData_(pCellData->pExtendedData);
        }
    }
}
