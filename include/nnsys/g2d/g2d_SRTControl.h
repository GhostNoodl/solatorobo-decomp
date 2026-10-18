#ifndef NNSYS_G2D_SRTCONTROL_H
#define NNSYS_G2D_SRTCONTROL_H

#include "types.h"
#include "nitro/fx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum NNSG2dSRTControlType {
    NNS_G2D_SRTCONTROLTYPE_SRT = 1
} NNSG2dSRTControlType;

#define NNS_G2D_AFFINEENABLE_NONE   0x0
#define NNS_G2D_AFFINEENABLE_SCALE  0x2
#define NNS_G2D_AFFINEENABLE_ROTATE 0x4
#define NNS_G2D_AFFINEENABLE_TRANS  0x8

typedef struct NNSG2dFVec2 {
    fx32 x;
    fx32 y;
} NNSG2dFVec2;

typedef struct NNSG2dSVec2 {
    s16 x;
    s16 y;
} NNSG2dSVec2;

typedef struct NNSG2dSRTData {
    /* 0x00 */ NNSG2dFVec2 scale;
    /* 0x08 */ NNSG2dSVec2 trans;
    /* 0x0c */ u16 rotZ;
    /* 0x0e */ u16 SRT_EnableFlag;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
} NNSG2dSRTData; // size 0x18

typedef struct NNSG2dSRTControl {
    /* 0x00 */ NNSG2dSRTControlType type;
    /* 0x04 */ NNSG2dSRTData srtData;
} NNSG2dSRTControl; // size 0x1c

static inline void NNSi_G2dSrtcAffineFlagON(NNSG2dSRTControl *pSRT, u16 newFlag) {
    pSRT->srtData.SRT_EnableFlag |= (u16)newFlag;
}

void NNSi_G2dSrtcSetTrans(NNSG2dSRTControl *pCtrl, s16 x, s16 y);
void NNSi_G2dSrtcSetSRTRotZ(NNSG2dSRTControl *pCtrl, u16 rotZ);
void NNSi_G2dSrtcSetSRTScale(NNSG2dSRTControl *pCtrl, fx32 x, fx32 y);
void NNSi_G2dSrtcInitControl(NNSG2dSRTControl *pCtrl, NNSG2dSRTControlType type);
void NNSi_G2dSrtcSetInitialValue(NNSG2dSRTControl *pCtrl);

#ifdef __cplusplus
}
#endif

#endif
