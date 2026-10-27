#include <nnsys/g3d.h>

#pragma force_active on

void NNSi_G3dAnmCalcNsBca (NNSG3dJntAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx);
void getMdlTrans_ (NNSG3dJntAnmResult * pResult);
void getMdlScale_ (NNSG3dJntAnmResult * pResult);
void getMdlRot_ (NNSG3dJntAnmResult * pResult);
void getJntSRTAnmResult_(const NNSG3dResJntAnm * pJntAnm, u32 dataIdx, fx32 Frame, NNSG3dJntAnmResult * pResult);
void getTransData_(fx32 * pVal, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
void getTransDataEx_(fx32 * pVal, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
void getScaleData_(fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
void getScaleDataEx_(fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
void getRotData_(MtxFx33 * pRot, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
void getRotDataEx_(MtxFx33 * pRot, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm);
BOOL getRotDataByIdx_(MtxFx33 * pRot, const void * pArrayRot3, const void * pArrayRot5, NNSG3dJntAnmRIdx info);

extern const u8 data_02075728[9][4]; // nsbca.c's own pivotUtil_
#define pivotUtil_ data_02075728

#pragma thumb off

static inline void vecCross_ (const VecFx32 * a, const VecFx32 * b, VecFx32 * axb)
{
    fx32 x, y, z;

    x = (a->y * b->z - a->z * b->y) >> FX32_SHIFT;
    y = (a->z * b->x - a->x * b->z) >> FX32_SHIFT;
    z = (a->x * b->y - a->y * b->x) >> FX32_SHIFT;

    axb->x = x;
    axb->y = y;
    axb->z = z;
}

#pragma thumb reset

#define G3D_NORMALIZE_ROT_MTX

#ifdef G3D_NORMALIZE_ROT_MTX
    #define ROT_FILTER_SHIFT    0
#else
    #define ROT_FILTER_SHIFT    1
#endif


// Scale animation data stores each frame as a (scale, inverse scale) pair.
typedef struct { fx16 s, invs; } ScaleFx16;
typedef struct { fx32 s, invs; } ScaleFx32;

void getScaleData_ (fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const void * pArray = (const void *)((const u8 *)pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) * pData;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto SCALE_NONINTERP;
            } else {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1) {
                fx32 v, v_sub;
                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                    const ScaleFx16 * p = (const ScaleFx16 *)pArray;

                    v = p[idx].s;
                    v_sub = p[idx_sub].s;
                    *s_invs = (v + (v << 1) + v_sub) >> 2;

                    v = p[idx].invs;
                    v_sub = p[idx_sub].invs;
                    *(s_invs + 1) = (v + (v << 1) + v_sub) >> 2;
                } else {
                    const ScaleFx32 * p = (const ScaleFx32 *)pArray;

                    v = p[idx].s;
                    v_sub = p[idx_sub].s;
                    *s_invs = (fx32)(((fx64)v + v + v + v_sub) >> 2);

                    v = p[idx].invs;
                    v_sub = p[idx_sub].invs;
                    *(s_invs + 1) = (fx32)(((fx64)v + v + v + v_sub) >> 2);
                }
                return;
            } else {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }
SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const ScaleFx16 * p = (const ScaleFx16 *)pArray;
        *s_invs = p[idx].s;
        *(s_invs + 1) = p[idx].invs;
    } else {
        const ScaleFx32 * p = (const ScaleFx32 *)pArray;
        *s_invs = p[idx].s;
        *(s_invs + 1) = p[idx].invs;
    }
    return;
SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const ScaleFx16 * p = (const ScaleFx16 *)pArray;
        *s_invs = (p[idx].s + (p + idx + 1)->s) >> 1;
        *(s_invs + 1) = (p[idx].invs + (p + idx + 1)->invs) >> 1;
    } else {
        const ScaleFx32 * p = (const ScaleFx32 *)pArray;
        *s_invs = (p[idx].s + (p + idx + 1)->s) >> 1;
        *(s_invs + 1) = (p[idx].invs + (p + idx + 1)->invs) >> 1;
    }
    return;
}

void getScaleDataEx_ (fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    const void * pArray = (const void *)((const u8 *)pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) * pData;

    u32 last_interp;
    u32 idx;
    u32 idx_sub;
    fx32 remainder;
    int step;
    u32 step_shift;
    u32 frame;

    frame = (u32)FX_Whole(Frame);

    if (frame == pJntAnm->numFrame - 1) {

        if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
            idx = frame;
        } else if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
            idx = (frame >> 1) + (frame & 1);
        } else {
            idx = (frame >> 2) + (frame & 3);
        }

        if (pJntAnm->flag & NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION) {
            idx_sub = 0;
            goto SCALE_EX_0_1;
        } else {
            if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                const ScaleFx16 * p = (const ScaleFx16 *)pArray;
                *s_invs = p[idx].s;
                *(s_invs + 1) = p[idx].invs;
            } else {
                const ScaleFx32 * p = (const ScaleFx32 *)pArray;
                *s_invs = p[idx].s;
                *(s_invs + 1) = p[idx].invs;
            }
            return;
        }
    }

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        goto SCALE_EX_0;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frame >= last_interp) {
            idx = (last_interp >> 1);
            idx_sub = idx + 1;
            goto SCALE_EX_0_1;
        } else {
            idx = frame >> 1;
            idx_sub = idx + 1;
            remainder = Frame & (FX32_ONE * 2 - 1);
            step = 2;
            step_shift = 1;
            goto SCALE_EX;
        }
    } else {
        if (frame >= last_interp) {
            idx = (frame >> 2) + (frame & 3);
            idx_sub = idx + 1;
            goto SCALE_EX_0_1;
        } else {
            idx = frame >> 2;
            idx_sub = idx + 1;
            remainder = Frame & (FX32_ONE * 4 - 1);
            step = 4;
            step_shift = 2;
            goto SCALE_EX;
        }
    }
SCALE_EX_0:
    idx = frame;
    idx_sub = idx + 1;
SCALE_EX_0_1:
    remainder = Frame & (FX32_ONE - 1);
    step = 1;
    step_shift = 0;
SCALE_EX:
    {
        fx32 s0, s1, invs0, invs1;
        if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
            const ScaleFx16 * p = (const ScaleFx16 *)pArray;
            s0 = p[idx].s;
            invs0 = p[idx].invs;
            s1 = p[idx_sub].s;
            invs1 = p[idx_sub].invs;
        } else {
            const ScaleFx32 * p = (const ScaleFx32 *)pArray;
            s0 = p[idx].s;
            invs0 = p[idx].invs;
            s1 = p[idx_sub].s;
            invs1 = p[idx_sub].invs;
        }

        *s_invs = ((s0 * step) + (((s1 - s0) * remainder) >> FX32_SHIFT)) >> step_shift;
        *(s_invs + 1) = ((invs0 * step) + (((invs1 - invs0) * remainder) >> FX32_SHIFT)) >> step_shift;
    }
    return;
}

void getRotData_ (MtxFx33 * pRot, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const u16 * pArray = (const u16 *)((const u8 *)pJntAnm + *(pData + 1));
    const void * pArrayRot3 = (const void *)((const u8 *)pJntAnm + pJntAnm->ofsRot3);
    const void * pArrayRot5 = (const void *)((const u8 *)pJntAnm + pJntAnm->ofsRot5);
    NNSG3dJntAnmRInfo info = (NNSG3dJntAnmRInfo) * pData;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    if (!(info & NNS_G3D_JNTANM_RINFO_STEP_MASK)) {
        idx = frame;
        goto ROT_NONINTERP;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_RINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_RINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_RINFO_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto ROT_NONINTERP;
            } else {
                idx = frame >> 1;
                goto ROT_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto ROT_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto ROT_NONINTERP;
            }

            if (frame & 1) {
                MtxFx33 r;
                BOOL doCross = FALSE;

                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                doCross |= getRotDataByIdx_(pRot,
                                            pArrayRot3,
                                            pArrayRot5,
                                            (NNSG3dJntAnmRIdx)pArray[idx]);
                doCross |= getRotDataByIdx_(&r,
                                            pArrayRot3,
                                            pArrayRot5,
                                            (NNSG3dJntAnmRIdx)pArray[idx_sub]);

                pRot->_00 = (pRot->_00 * 3 + r._00) >> (2 * ROT_FILTER_SHIFT);
                pRot->_01 = (pRot->_01 * 3 + r._01) >> (2 * ROT_FILTER_SHIFT);
                pRot->_02 = (pRot->_02 * 3 + r._02) >> (2 * ROT_FILTER_SHIFT);
                pRot->_10 = (pRot->_10 * 3 + r._10) >> (2 * ROT_FILTER_SHIFT);
                pRot->_11 = (pRot->_11 * 3 + r._11) >> (2 * ROT_FILTER_SHIFT);
                pRot->_12 = (pRot->_12 * 3 + r._12) >> (2 * ROT_FILTER_SHIFT);

#ifdef G3D_NORMALIZE_ROT_MTX
                VEC_Normalize((VecFx32 *)(&pRot->_00), (VecFx32 *)(&pRot->_00));
                VEC_Normalize((VecFx32 *)(&pRot->_10), (VecFx32 *)(&pRot->_10));
#endif
                if (!doCross) {
                    pRot->_20 = (pRot->_20 * 3 + r._20) >> (2 * ROT_FILTER_SHIFT);
                    pRot->_21 = (pRot->_21 * 3 + r._21) >> (2 * ROT_FILTER_SHIFT);
                    pRot->_22 = (pRot->_22 * 3 + r._22) >> (2 * ROT_FILTER_SHIFT);
#ifdef G3D_NORMALIZE_ROT_MTX
                    VEC_Normalize((VecFx32 *)(&pRot->_20), (VecFx32 *)(&pRot->_20));
#endif
                } else {
                    vecCross_((const VecFx32 *)&pRot->_00,
                              (const VecFx32 *)&pRot->_10,
                              (VecFx32 *)&pRot->_20);
                }
                return;
            } else {
                idx = frame >> 2;
                goto ROT_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto ROT_NONINTERP;
        }
    }
ROT_INTERP_2:
    {
        MtxFx33 r;
        BOOL doCross = FALSE;

        doCross |= getRotDataByIdx_(pRot,
                                    pArrayRot3,
                                    pArrayRot5,
                                    (NNSG3dJntAnmRIdx)pArray[idx]);
        doCross |= getRotDataByIdx_(&r,
                                    pArrayRot3,
                                    pArrayRot5,
                                    (NNSG3dJntAnmRIdx)*(pArray + idx + 1));

        pRot->_00 = (pRot->_00 + r._00) >> ROT_FILTER_SHIFT;
        pRot->_01 = (pRot->_01 + r._01) >> ROT_FILTER_SHIFT;
        pRot->_02 = (pRot->_02 + r._02) >> ROT_FILTER_SHIFT;
        pRot->_10 = (pRot->_10 + r._10) >> ROT_FILTER_SHIFT;
        pRot->_11 = (pRot->_11 + r._11) >> ROT_FILTER_SHIFT;
        pRot->_12 = (pRot->_12 + r._12) >> ROT_FILTER_SHIFT;

#ifdef G3D_NORMALIZE_ROT_MTX
        VEC_Normalize((VecFx32 *)(&pRot->_00), (VecFx32 *)(&pRot->_00));
        VEC_Normalize((VecFx32 *)(&pRot->_10), (VecFx32 *)(&pRot->_10));
#endif
        if (!doCross) {
            pRot->_20 = (pRot->_20 + r._20) >> ROT_FILTER_SHIFT;
            pRot->_21 = (pRot->_21 + r._21) >> ROT_FILTER_SHIFT;
            pRot->_22 = (pRot->_22 + r._22) >> ROT_FILTER_SHIFT;
#ifdef G3D_NORMALIZE_ROT_MTX
            VEC_Normalize((VecFx32 *)(&pRot->_20), (VecFx32 *)(&pRot->_20));
#endif
        } else {
            vecCross_((const VecFx32 *)&pRot->_00,
                      (const VecFx32 *)&pRot->_10,
                      (VecFx32 *)&pRot->_20);
        }
        return;
    }
ROT_NONINTERP:
    if (getRotDataByIdx_(pRot,
                         pArrayRot3,
                         pArrayRot5,
                         (NNSG3dJntAnmRIdx)pArray[idx])) {
        vecCross_((const VecFx32 *)&pRot->_00,
                  (const VecFx32 *)&pRot->_10,
                  (VecFx32 *)&pRot->_20);
    } else {
#ifdef G3D_NORMALIZE_ROT_MTX
        VEC_Normalize((VecFx32 *)(&pRot->_20), (VecFx32 *)(&pRot->_20));
#endif
    }
    return;
}


void getRotDataEx_ (MtxFx33 * pRot, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    const void * pArray = (const void *)((const u8 *)pJntAnm + *(pData + 1));
    const void * pArrayRot3 = (const void *)((const u8 *)pJntAnm + pJntAnm->ofsRot3);
    const void * pArrayRot5 = (const void *)((const u8 *)pJntAnm + pJntAnm->ofsRot5);
    NNSG3dJntAnmRInfo info = (NNSG3dJntAnmRInfo) * pData;

    u32 last_interp;
    u32 idx0, idx1;
    fx32 remainder;
    int step;
    u32 step_shift;
    u32 frame;
    const u16 * p = (const u16 *)pArray;

    frame = (u32)FX_Whole(Frame);

    if (frame == pJntAnm->numFrame - 1) {

        if (!(info & NNS_G3D_JNTANM_RINFO_STEP_MASK)) {
            idx0 = frame;
        } else if (info & NNS_G3D_JNTANM_RINFO_STEP_2)   {
            idx0 = (frame >> 1) + (frame & 1);
        } else {
            idx0 = (frame >> 2) + (frame & 3);
        }

        if (pJntAnm->flag & NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION) {
            idx1 = 0;
            goto ROT_EX_0_1;
        } else {

            if (getRotDataByIdx_(pRot,
                                 pArrayRot3,
                                 pArrayRot5,
                                 (NNSG3dJntAnmRIdx)p[idx0])) {
                vecCross_((const VecFx32 *)&pRot->_00,
                          (const VecFx32 *)&pRot->_10,
                          (VecFx32 *)&pRot->_20);
            } else {
#ifdef G3D_NORMALIZE_ROT_MTX
                VEC_Normalize((VecFx32 *)(&pRot->_20), (VecFx32 *)(&pRot->_20));
#endif
            }
            return;
        }
    }

    if (!(info & NNS_G3D_JNTANM_RINFO_STEP_MASK)) {
        goto ROT_EX_0;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_RINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_RINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_RINFO_STEP_2) {
        if (frame >= last_interp) {
            idx0 = (last_interp >> 1);
            idx1 = idx0 + 1;
            goto ROT_EX_0_1;
        } else {
            idx0 = frame >> 1;
            idx1 = idx0 + 1;
            remainder = Frame & (FX32_ONE * 2 - 1);
            step = 2;
            step_shift = 1;
            goto ROT_EX;
        }
    } else {
        if (frame >= last_interp) {
            idx0 = (frame >> 2) + (frame & 3);
            idx1 = idx0 + 1;
            goto ROT_EX_0_1;
        } else {
            idx0 = frame >> 2;
            idx1 = idx0 + 1;
            remainder = Frame & (FX32_ONE * 4 - 1);
            step = 4;
            step_shift = 2;
            goto ROT_EX;
        }
    }
ROT_EX_0:
    idx0 = (u32)frame;
    idx1 = idx0 + 1;
ROT_EX_0_1:
    remainder = Frame & (FX32_ONE - 1);
    step = 1;
    step_shift = 0;
ROT_EX:
    {
        MtxFx33 r0, r1;
        BOOL doCross = FALSE;
        doCross |= getRotDataByIdx_(&r0,
                                    pArrayRot3,
                                    pArrayRot5,
                                    (NNSG3dJntAnmRIdx)p[idx0]);
        doCross |= getRotDataByIdx_(&r1,
                                    pArrayRot3,
                                    pArrayRot5,
                                    (NNSG3dJntAnmRIdx)p[idx1]);

        pRot->_00 = ((r0._00 * step) + (((r1._00 - r0._00) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
        pRot->_01 = ((r0._01 * step) + (((r1._01 - r0._01) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
        pRot->_02 = ((r0._02 * step) + (((r1._02 - r0._02) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
        pRot->_10 = ((r0._10 * step) + (((r1._10 - r0._10) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
        pRot->_11 = ((r0._11 * step) + (((r1._11 - r0._11) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
        pRot->_12 = ((r0._12 * step) + (((r1._12 - r0._12) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);

#ifdef G3D_NORMALIZE_ROT_MTX
        VEC_Normalize((VecFx32 *)(&pRot->_00), (VecFx32 *)(&pRot->_00));
        VEC_Normalize((VecFx32 *)(&pRot->_10), (VecFx32 *)(&pRot->_10));
#endif

        if (!doCross) {
            pRot->_20 = ((r0._20 * step) + (((r1._20 - r0._20) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
            pRot->_21 = ((r0._21 * step) + (((r1._21 - r0._21) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);
            pRot->_22 = ((r0._22 * step) + (((r1._22 - r0._22) * remainder) >> FX32_SHIFT)) >> (step_shift * ROT_FILTER_SHIFT);

#ifdef G3D_NORMALIZE_ROT_MTX
            VEC_Normalize((VecFx32 *)(&pRot->_20), (VecFx32 *)(&pRot->_20));
#endif
        } else {
            vecCross_((const VecFx32 *)&pRot->_00,
                      (const VecFx32 *)&pRot->_10,
                      (VecFx32 *)&pRot->_20);
        }
        return;
    }
}

BOOL getRotDataByIdx_ (MtxFx33 * pRot, const void * pArrayRot3, const void * pArrayRot5, NNSG3dJntAnmRIdx info)
{
    if (info & NNS_G3D_JNTANM_RIDX_PIVOT) {
        const fx16 * data;
        fx32 A, B;
        u32 idxPivot;

        pRot->_00 = pRot->_01 = pRot->_02 =
        pRot->_10 = pRot->_11 = pRot->_12 =
        pRot->_20 = pRot->_21 = pRot->_22 = 0;

        data = (const fx16 *)pArrayRot3 + ((info & NNS_G3D_JNTANM_RIDX_IDXDATA_MASK) * 3);
        A = *(data + 1);
        B = *(data + 2);
        idxPivot = (u32)((*data & NNS_G3D_JNTANM_PIVOTINFO_IDXPIVOT_MASK) >>
                         NNS_G3D_JNTANM_PIVOT_INFO_IDXPIVOT_SHIFT);

        pRot->a[idxPivot] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_MINUS) ? -FX32_ONE : FX32_ONE;

        pRot->a[pivotUtil_[idxPivot][0]] = A;
        pRot->a[pivotUtil_[idxPivot][1]] = B;

        pRot->a[pivotUtil_[idxPivot][2]] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVC) ? -B : B;
        pRot->a[pivotUtil_[idxPivot][3]] =
            (*data & NNS_G3D_JNTANM_PIVOTINFO_SIGN_REVD) ? -A : A;

        return FALSE;
    } else {
        const fx16 * data = (fx16 *)pArrayRot5 +
                            ((info & NNS_G3D_JNTANM_RIDX_IDXDATA_MASK) * 5);
        fx16 _12;

        _12 = (fx16)(data[4] & 7);
        pRot->_11 = (data[4] >> 3);

        _12 = (fx16)((_12 << 3) | (data[0] & 7));
        pRot->_00 = (data[0] >> 3);

        _12 = (fx16)((_12 << 3) | (data[1] & 7));
        pRot->_01 = (data[1] >> 3);

        _12 = (fx16)((_12 << 3) | (data[2] & 7));
        pRot->_02 = (data[2] >> 3);

        _12 = (fx16)((_12 << 3) | (data[3] & 7));
        pRot->_10 = (data[3] >> 3);

        pRot->_12 = ((fx16)(_12 << 3) >> 3);

        return TRUE;
    }
}

