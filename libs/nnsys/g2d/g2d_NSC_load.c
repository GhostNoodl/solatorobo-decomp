#include "nnsys/g2d/g2d_Load.h"

BOOL NNS_G2dGetUnpackedScreenData(void *pNscrFile, NNSG2dScreenData **ppScrData) {
    {
        NNSG2dBinaryFileHeader *pBinFile = (NNSG2dBinaryFileHeader *)pNscrFile;
        {
            NNSG2dScreenDataBlock *pBinBlk =
                (NNSG2dScreenDataBlock *)NNS_G2dFindBinaryBlock(pBinFile, NNS_G2D_BINBLK_SIG_SCRDATA);
            if (pBinBlk) {
                *ppScrData = &(pBinBlk->screenData);
                return TRUE;
            } else {
                *ppScrData = NULL;
                return FALSE;
            }
        }
    }
}
