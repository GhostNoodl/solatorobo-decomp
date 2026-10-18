#ifndef NNSYS_G2D_ANIMATION_H
#define NNSYS_G2D_ANIMATION_H

#include "types.h"
#include "nitro/fx.h"
#include "nnsys/g2d/g2d_Load.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NNS_G2D_ANIMATIONPLAYMODE_INVALID      0
#define NNS_G2D_ANIMATIONPLAYMODE_FORWARD      1
#define NNS_G2D_ANIMATIONPLAYMODE_FORWARD_LOOP 2
#define NNS_G2D_ANIMATIONPLAYMODE_REVERSE      3
#define NNS_G2D_ANIMATIONPLAYMODE_REVERSE_LOOP 4

#define NNS_G2D_ANMCALLBACKTYPE_NONE     0
#define NNS_G2D_ANMCALLBACKTYPE_LAST_FRM 1
#define NNS_G2D_ANMCALLBACKTYPE_SPEC_FRM 2
#define NNS_G2D_ANMCALLBACKTYPE_EVER_FRM 3

typedef NNSG2dAnimFrameData NNSG2dAnimFrame;
typedef NNSG2dAnimSequenceData NNSG2dAnimSequence;

typedef void (*NNSG2dAnmCallBackPtr)(u32 param, fx32 currentFrame);

typedef struct NNSG2dCallBackFunctor {
    /* 0x0 */ int type;
    /* 0x4 */ u32 param;
    /* 0x8 */ NNSG2dAnmCallBackPtr pFunc;
    /* 0xc */ u16 frameIdx;
    /* 0xe */ u16 pad16;
} NNSG2dCallBackFunctor; // size 0x10

typedef struct NNSG2dAnimController {
    /* 0x00 */ const NNSG2dAnimFrame *pCurrent;
    /* 0x04 */ const NNSG2dAnimFrame *pActiveCurrent;
    /* 0x08 */ BOOL bReverse;
    /* 0x0c */ BOOL bActive;
    /* 0x10 */ fx32 currentTime;
    /* 0x14 */ fx32 speed;
    /* 0x18 */ int overriddenPlayMode;
    /* 0x1c */ const NNSG2dAnimSequence *pAnimSequence;
    /* 0x20 */ NNSG2dCallBackFunctor callbackFunctor;
} NNSG2dAnimController; // size 0x30

static inline void NNS_G2dStopAnimCtrl(NNSG2dAnimController *pAnimCtrl) {
    pAnimCtrl->bActive = FALSE;
}

void *NNS_G2dGetAnimCtrlCurrentElement(NNSG2dAnimController *pAnimCtrl);
BOOL NNS_G2dTickAnimCtrl(NNSG2dAnimController *pAnimCtrl, fx32 frames);
void NNS_G2dInitAnimCtrl(NNSG2dAnimController *pAnimCtrl);
void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *pCallBack);
void NNS_G2dResetAnimCtrlState(NNSG2dAnimController *pAnimCtrl);
void NNS_G2dBindAnimCtrl(NNSG2dAnimController *pAnimCtrl, const NNSG2dAnimSequence *pAnimSequence);
void NNS_G2dSetAnimCtrlCallBackFunctor(NNSG2dAnimController *pAnimCtrl, int type, u32 param,
                                       NNSG2dAnmCallBackPtr pFunc);

#ifdef __cplusplus
}
#endif

#endif
