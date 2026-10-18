#ifndef NNSYS_G2D_OAM_H
#define NNSYS_G2D_OAM_H

#include "types.h"
#include "nitro/fx.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NNS_G2D_OAM_AFFINE_IDX_NONE 0xFFFE

typedef enum NNSG2dOamType {
    NNS_G2D_OAMTYPE_MAIN = 0,
    NNS_G2D_OAMTYPE_SUB,
    NNS_G2D_OAMTYPE_SOFTWAREEMULATION,
    NNS_G2D_OAMTYPE_INVALID,
    NNS_G2D_OAMTYPE_MAX
} NNSG2dOamType;

typedef struct GXOamAttr {
    u16 attr0;
    u16 attr1;
    u16 attr2;
    u16 _3;
} GXOamAttr;

typedef struct GXOamAffine {
    u16 _0[3];
    s16 PA;
    u16 _1[3];
    s16 PB;
    u16 _2[3];
    s16 PC;
    u16 _3[3];
    s16 PD;
} GXOamAffine;

typedef struct NNSG2dOAMManageArea {
    /* 0x0 */ u16 fromIdx;
    /* 0x2 */ u16 toIdx;
    /* 0x4 */ u16 currentIdx;
} NNSG2dOAMManageArea;

typedef struct NNSG2dOamManagerInstance {
    /* 0x00 */ NNSG2dOamType type;
    /* 0x04 */ NNSG2dOAMManageArea managedAttrArea;
    /* 0x0a */ NNSG2dOAMManageArea managedAffineArea;
    /* 0x10 */ u16 GUID;
    /* 0x14 */ BOOL bFastTransferEnable;
    /* 0x18 */ fx32 spriteZoffsetStep;
} NNSG2dOamManagerInstance;

void NNS_G2dInitOamManagerModule(void);
BOOL NNS_G2dGetNewOamManagerInstanceAsFastTransferMode(NNSG2dOamManagerInstance *pMan, u16 fromOBJ, u16 numOBJ, NNSG2dOamType type);
BOOL NNS_G2dEntryOamManagerOam(NNSG2dOamManagerInstance *pMan, const GXOamAttr *pOam, u16 num);
u16 NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx);
void NNS_G2dApplyOamManagerToHW(NNSG2dOamManagerInstance *pMan);
void NNS_G2dResetOamManagerBuffer(NNSG2dOamManagerInstance *pMan);
void NNS_G2dApplyAndResetOamManagerBuffer(NNSG2dOamManagerInstance *pMan);

#ifdef __cplusplus
}
#endif

#endif
