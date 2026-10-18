#include "nnsys/g2d/g2d_CellAnimation.h"
#include "nnsys/g2d/g2d_Image.h"

typedef BOOL (*VramTransferTaskRegisterFuncPtr)(int type, u32 dstAddr, void *pSrc, u32 szByte);

typedef struct NNSG2dCellTransferState {
    /* 0x00 */ NNSG2dVRamLocation dstVramLocation;
    /* 0x0c */ u32 szDst;
    /* 0x10 */ const void *pSrcNCGR;
    /* 0x14 */ const void *pSrcNCBR;
    /* 0x18 */ u32 szSrcData;
    /* 0x1c */ BOOL bActive;
    /* 0x20 */ u32 bDrawn;
    /* 0x24 */ u32 bTransferRequested;
    /* 0x28 */ u32 srcOffset;
    /* 0x2c */ u32 szByte;
} NNSG2dCellTransferState; // size 0x30

// The manager's .bss (state array pointer at +0x8) stays outside this file: its layout does not
// follow from the SDK declarations, so it is reached through the original symbol.
typedef struct CellTransferStateManagerBss_ {
    /* 0x0 */ u32 unk_00;
    /* 0x4 */ u32 unk_04;
    /* 0x8 */ NNSG2dCellTransferState *pCellStateArray;
} CellTransferStateManagerBss_;

extern CellTransferStateManagerBss_ data_020927ec;
#define s_pCellStateArray (data_020927ec.pCellStateArray)

static inline NNSG2dCellTransferState *GetValidCellTransferState_(u32 validHandle) {
    return &s_pCellStateArray[validHandle];
}

NNSG2dCellTransferState *NNSi_G2dGetCellTransferState(u32 handle) {
    return GetValidCellTransferState_(handle);
}

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte) {
    NNSG2dCellTransferState *pState = NNSi_G2dGetCellTransferState(handle);

    pState->bTransferRequested = 0xFFFFFFFF;
    pState->srcOffset = srcOffset;
    pState->szByte = szByte;
}

