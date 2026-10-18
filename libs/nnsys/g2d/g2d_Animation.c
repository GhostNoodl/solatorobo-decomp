#include "nnsys/g2d/g2d_Animation.h"

int abs(int x);

static inline const NNSG2dAnimFrame *GetFrameBegin_(const NNSG2dAnimSequence *pSequence) {
    return pSequence->pAnmFrameArray;
}

static inline const NNSG2dAnimFrame *GetFrameEnd_(const NNSG2dAnimSequence *pSequence) {
    return pSequence->pAnmFrameArray + (pSequence->numFrames);
}

static inline const NNSG2dAnimFrame *GetFrameLoopBegin_(const NNSG2dAnimSequence *pSequence) {
    return pSequence->pAnmFrameArray + pSequence->loopStartFrameIdx;
}

static inline u16 GetCurrentFrameIdx_(const NNSG2dAnimController *pAnimCtrl) {
    return (u16)(((u32)pAnimCtrl->pCurrent - (u32)pAnimCtrl->pAnimSequence->pAnmFrameArray) /
                 sizeof(NNSG2dAnimFrameData));
}

static inline int GetAnimationPlayMode_(const NNSG2dAnimController *pAnimCtrl) {
    if (pAnimCtrl->overriddenPlayMode != NNS_G2D_ANIMATIONPLAYMODE_INVALID) {
        return pAnimCtrl->overriddenPlayMode;
    } else {
        return pAnimCtrl->pAnimSequence->playMode;
    }
}

static inline BOOL IsLoopAnimSequence_(const NNSG2dAnimController *pAnimCtrl) {
    {
        const int playMode = GetAnimationPlayMode_(pAnimCtrl);

        return (playMode == NNS_G2D_ANIMATIONPLAYMODE_FORWARD_LOOP ||
                playMode == NNS_G2D_ANIMATIONPLAYMODE_REVERSE_LOOP)
                   ? TRUE
                   : FALSE;
    }
}

static inline BOOL IsReversePlayAnim_(const NNSG2dAnimController *pAnimCtrl) {
    {
        const int playMode = GetAnimationPlayMode_(pAnimCtrl);

        return (playMode == NNS_G2D_ANIMATIONPLAYMODE_REVERSE || playMode == NNS_G2D_ANIMATIONPLAYMODE_REVERSE_LOOP)
                   ? TRUE
                   : FALSE;
    }
}

static inline BOOL IsAnimCtrlMovingForward_(const NNSG2dAnimController *pAnimCtrl) {
    return (pAnimCtrl->speed > 0) ^ (pAnimCtrl->bReverse) ? TRUE : FALSE;
}

static inline BOOL ShouldAnmCtrlMoveNext_(NNSG2dAnimController *pAnimCtrl) {
    if (pAnimCtrl->bActive && (pAnimCtrl->currentTime >= FX32_ONE * (int)pAnimCtrl->pCurrent->frames)) {
        return TRUE;
    }
    return FALSE;
}

static inline void CallbackFuncHandling_(const NNSG2dCallBackFunctor *pFunctor, u16 currentFrameIdx) {
    switch (pFunctor->type) {
    case NNS_G2D_ANMCALLBACKTYPE_SPEC_FRM:
        if (currentFrameIdx == pFunctor->frameIdx) {
            (*pFunctor->pFunc)(pFunctor->param, currentFrameIdx);
        }
        break;
    case NNS_G2D_ANMCALLBACKTYPE_EVER_FRM:
        (*pFunctor->pFunc)(pFunctor->param, currentFrameIdx);
        break;
    }
}

static inline BOOL IsReachStartEdge_(const NNSG2dAnimController *pAnimCtrl, const NNSG2dAnimFrame *pFrame) {
    return (pFrame <= (GetFrameLoopBegin_(pAnimCtrl->pAnimSequence) - 1)) ? TRUE : FALSE;
}

static inline BOOL IsReachEdge_(const NNSG2dAnimController *pAnimCtrl, const NNSG2dAnimFrame *pFrame) {
    if (IsAnimCtrlMovingForward_(pAnimCtrl)) {
        return (pFrame >= GetFrameEnd_(pAnimCtrl->pAnimSequence)) ? TRUE : FALSE;
    } else {
        return IsReachStartEdge_(pAnimCtrl, pFrame);
    }
}

static inline void MoveNext_(NNSG2dAnimController *pAnimCtrl) {
    pAnimCtrl->pCurrent = IsAnimCtrlMovingForward_(pAnimCtrl) ? pAnimCtrl->pCurrent + 1 : pAnimCtrl->pCurrent - 1;
}

static inline void SequenceEdgeHandleCommon_(NNSG2dAnimController *pAnimCtrl) {
    if (pAnimCtrl->callbackFunctor.type == NNS_G2D_ANMCALLBACKTYPE_LAST_FRM) {
        (*pAnimCtrl->callbackFunctor.pFunc)(pAnimCtrl->callbackFunctor.param, pAnimCtrl->currentTime);
    }

    if (!IsLoopAnimSequence_(pAnimCtrl)) {
        NNS_G2dStopAnimCtrl(pAnimCtrl);
    } else {
        NNS_G2dResetAnimCtrlState(pAnimCtrl);
    }
}

static inline void SequenceEdgeHandleReverse_(NNSG2dAnimController *pAnimCtrl) {
    pAnimCtrl->bReverse = pAnimCtrl->bReverse ^ TRUE;

    if (IsReachStartEdge_(pAnimCtrl, pAnimCtrl->pCurrent)) {
        SequenceEdgeHandleCommon_(pAnimCtrl);
    }
}

static inline void SequenceEdgeHandleNormal_(NNSG2dAnimController *pAnimCtrl) {
    SequenceEdgeHandleCommon_(pAnimCtrl);
}

static inline void ValidateAnimFrame_(NNSG2dAnimController *pAnimCtrl, const NNSG2dAnimFrame **pFrame) {
    if (*pFrame > GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1) {
        *pFrame = GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1;
    } else if (*pFrame < GetFrameBegin_(pAnimCtrl->pAnimSequence)) {
        *pFrame = GetFrameBegin_(pAnimCtrl->pAnimSequence);
    }
}

static void SequenceEdgeHandle_(NNSG2dAnimController *pAnimCtrl) {
    if (IsReversePlayAnim_(pAnimCtrl)) {
        SequenceEdgeHandleReverse_(pAnimCtrl);
    } else {
        SequenceEdgeHandleNormal_(pAnimCtrl);
    }

    ValidateAnimFrame_(pAnimCtrl, &pAnimCtrl->pCurrent);
}

void *NNS_G2dGetAnimCtrlCurrentElement(NNSG2dAnimController *pAnimCtrl) {
    return (void *)pAnimCtrl->pActiveCurrent->pContent;
}

BOOL NNS_G2dTickAnimCtrl(NNSG2dAnimController *pAnimCtrl, fx32 frames) {
    BOOL bChangeFrame = FALSE;

    if (pAnimCtrl->bActive != TRUE) {
        return FALSE;
    }

    pAnimCtrl->currentTime += abs(FX_Mul(pAnimCtrl->speed, frames));

    while (ShouldAnmCtrlMoveNext_(pAnimCtrl)) {
        bChangeFrame = TRUE;

        pAnimCtrl->currentTime -= FX32_ONE * (int)pAnimCtrl->pCurrent->frames;

        MoveNext_(pAnimCtrl);

        if (IsReachEdge_(pAnimCtrl, pAnimCtrl->pCurrent)) {
            SequenceEdgeHandle_(pAnimCtrl);
        }

        if (pAnimCtrl->pCurrent->frames != 0) {
            pAnimCtrl->pActiveCurrent = pAnimCtrl->pCurrent;
        }

        if (pAnimCtrl->callbackFunctor.type != NNS_G2D_ANMCALLBACKTYPE_NONE) {
            CallbackFuncHandling_(&pAnimCtrl->callbackFunctor, GetCurrentFrameIdx_(pAnimCtrl));
        }
    }

    return bChangeFrame;
}

void NNS_G2dInitAnimCtrl(NNSG2dAnimController *pAnimCtrl) {
    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->callbackFunctor);

    pAnimCtrl->pCurrent = NULL;
    pAnimCtrl->pActiveCurrent = NULL;

    pAnimCtrl->bReverse = FALSE;
    pAnimCtrl->bActive = TRUE;

    pAnimCtrl->currentTime = 0;
    pAnimCtrl->speed = FX32_ONE;

    pAnimCtrl->overriddenPlayMode = NNS_G2D_ANIMATIONPLAYMODE_INVALID;
    pAnimCtrl->pAnimSequence = NULL;
}

void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *pCallBack) {
    pCallBack->type = NNS_G2D_ANMCALLBACKTYPE_NONE;
    pCallBack->param = 0x0;
    pCallBack->pFunc = NULL;
    pCallBack->frameIdx = 0;
}

void NNS_G2dResetAnimCtrlState(NNSG2dAnimController *pAnimCtrl) {
    if (IsAnimCtrlMovingForward_(pAnimCtrl)) {
        pAnimCtrl->pCurrent = GetFrameLoopBegin_(pAnimCtrl->pAnimSequence);
    } else {
        pAnimCtrl->pCurrent = GetFrameEnd_(pAnimCtrl->pAnimSequence) - 1;
    }

    pAnimCtrl->pActiveCurrent = pAnimCtrl->pCurrent;
    pAnimCtrl->currentTime = 0;

    NNS_G2dTickAnimCtrl(pAnimCtrl, 0);
}

void NNS_G2dBindAnimCtrl(NNSG2dAnimController *pAnimCtrl, const NNSG2dAnimSequence *pAnimSequence) {
    pAnimCtrl->pAnimSequence = pAnimSequence;
    NNS_G2dResetAnimCtrlState(pAnimCtrl);
}

void NNS_G2dSetAnimCtrlCallBackFunctor(NNSG2dAnimController *pAnimCtrl, int type, u32 param,
                                       NNSG2dAnmCallBackPtr pFunc) {
    pAnimCtrl->callbackFunctor.pFunc = pFunc;
    pAnimCtrl->callbackFunctor.param = param;
    pAnimCtrl->callbackFunctor.type = type;
    pAnimCtrl->callbackFunctor.frameIdx = 0;
}
