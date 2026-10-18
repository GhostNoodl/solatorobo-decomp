#include "nnsys/g2d/g2d_Load.h"
#include "nnsys/g2d/g2d_Font.h"

#define NNS_G2D_BINFILE_SIG_FONTDATA  0x4e465452 // 'NFTR'
#define NNS_G2D_BINBLK_SIG_FINFDATA   0x46494e46 // 'FINF'
#define NNS_G2D_BINBLK_SIG_CGLPDATA   0x43474c50 // 'CGLP'
#define NNS_G2D_BINBLK_SIG_CWDHDATA   0x43574448 // 'CWDH'
#define NNS_G2D_BINBLK_SIG_CMAPDATA   0x434d4150 // 'CMAP'
#define NNS_G2D_NFTR_VER              0x0102
#define NNS_G2D_NFTR_PREV_VER         0x0101
#define NNS_G2D_NFTR_OLD_VER          0x0100

// Called where the SDK's OS_Panic is compiled out for the final ROM.
void func_0201adf4(void);

void NNSi_G2dUnpackNFT(NNSG2dBinaryFileHeader *pHeader);

static inline BOOL NNSi_G2dIsBinFileSignatureValid(const NNSG2dBinaryFileHeader *pBinFile, u32 binFileSig) {
    if (pBinFile != NULL) {
        if ((pBinFile->signature == binFileSig)) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL NNSi_G2dIsBinFileVersionValid(const NNSG2dBinaryFileHeader *pBinFile, u16 version) {
    if (pBinFile != NULL) {
        if (pBinFile->version >= version) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL NNS_G2dIsBinFileValid(const NNSG2dBinaryFileHeader *pBinFile, u32 binFileSig, u16 version) {
    if (pBinFile != NULL) {
        {
            return NNSi_G2dIsBinFileSignatureValid(pBinFile, binFileSig) && NNSi_G2dIsBinFileVersionValid(pBinFile, version);
        }
    }
    return FALSE;
}

BOOL NNSi_G2dGetUnpackedFont(void *pNftrFile, NNSG2dFontInformation **ppRes) {
    BOOL isOldVer = FALSE;

    if (!NNS_G2dIsBinFileValid((NNSG2dBinaryFileHeader *)pNftrFile, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_VER)) {
        if (!NNS_G2dIsBinFileValid((NNSG2dBinaryFileHeader *)pNftrFile, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_PREV_VER)) {
            if (!NNS_G2dIsBinFileValid((NNSG2dBinaryFileHeader *)pNftrFile, NNS_G2D_BINFILE_SIG_FONTDATA, NNS_G2D_NFTR_OLD_VER)) {
                func_0201adf4();
            }
            isOldVer = TRUE;
        }
    }

    {
        NNSG2dBinaryFileHeader *pBinFile = (NNSG2dBinaryFileHeader *)pNftrFile;
        NNSG2dBinaryBlockHeader *pBinBlock;

        NNSi_G2dUnpackNFT(pBinFile);

        pBinBlock = NNS_G2dFindBinaryBlock(pBinFile, NNS_G2D_BINBLK_SIG_FINFDATA);

        if (pBinBlock == NULL) {
            *ppRes = NULL;
            return FALSE;
        }

        *ppRes = (NNSG2dFontInformation *)((u8 *)pBinBlock + sizeof(*pBinBlock));
        if (isOldVer) {
            (*ppRes)->pGlyph->flags = 0;
        }
    }

    return TRUE;
}

static inline void ResolveOffset(void **ppOffset, void *pBase) {
    *ppOffset = (void *)(*(u32 *)ppOffset + (u32)pBase);
}

void NNSi_G2dUnpackNFT(NNSG2dBinaryFileHeader *pHeader) {
    NNSG2dBinaryBlockHeader *pBlock;
    NNSG2dFontInformation *pInfo = NULL;

    {
        int nBlocks = 0;
        pBlock = (NNSG2dBinaryBlockHeader *)((u8 *)pHeader + pHeader->headerSize);

        while (nBlocks < pHeader->dataBlocks) {
            switch (pBlock->kind) {
            case NNS_G2D_BINBLK_SIG_FINFDATA: {
                pInfo = (NNSG2dFontInformation *)((u8 *)pBlock + sizeof(*pBlock));

                ResolveOffset((void **)&(pInfo->pGlyph), pHeader);

                if (pInfo->pWidth != NULL) {
                    ResolveOffset((void **)&(pInfo->pWidth), pHeader);
                }
                if (pInfo->pMap != NULL) {
                    ResolveOffset((void **)&(pInfo->pMap), pHeader);
                }
            } break;
            case NNS_G2D_BINBLK_SIG_CGLPDATA: {
                NNSG2dFontGlyph *pGlyph = (NNSG2dFontGlyph *)((u8 *)pBlock + sizeof(*pBlock));
            } break;
            case NNS_G2D_BINBLK_SIG_CWDHDATA: {
                NNSG2dFontWidth *pWidth = (NNSG2dFontWidth *)((u8 *)pBlock + sizeof(*pBlock));

                if (pWidth->pNext != NULL) {
                    ResolveOffset((void **)&(pWidth->pNext), pHeader);
                }
            } break;
            case NNS_G2D_BINBLK_SIG_CMAPDATA: {
                NNSG2dFontCodeMap *pMap = (NNSG2dFontCodeMap *)((u8 *)pBlock + sizeof(*pBlock));

                if (pMap->pNext != NULL) {
                    ResolveOffset((void **)&(pMap->pNext), pHeader);
                }
            } break;
            default:
                break;
            }

            pBlock = (NNSG2dBinaryBlockHeader *)((u8 *)pBlock + pBlock->size);
            nBlocks++;
        }
    }
}
