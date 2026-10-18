#include <nnsys/g3d.h>

BOOL NNSi_G3dAnmBlendMat (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 matID)
{
    BOOL rval = FALSE;

    if (pAnmObj) {
        const NNSG3dAnmObj * p = pAnmObj;
        do {
            if (matID < p->numMapData) {
                u32 dataIdx = p->mapData[matID];
                if ((dataIdx & (NNS_G3D_ANMOBJ_MAPDATA_EXIST |
                                NNS_G3D_ANMOBJ_MAPDATA_DISABLED)) ==
                    NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                    NNSG3dFuncAnmMat func = (NNSG3dFuncAnmMat)p->funcAnm;

                    if (func) {
                        (*func)(pResult,
                                p,
                                dataIdx & NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD);
                        rval = TRUE;
                    }
                }
            }
            p = p->next;
        } while (p);
    }

    return rval;
}

#pragma thumb off
static void blendScaleVec_ (VecFx32 * v0, const VecFx32 * v1, fx32 ratio, BOOL isV1One)
{
    if (isV1One) {

        v0->x += ratio;
        v0->y += ratio;
        v0->z += ratio;
    } else {
        v0->x += ratio * v1->x >> FX32_SHIFT;
        v0->y += ratio * v1->y >> FX32_SHIFT;
        v0->z += ratio * v1->z >> FX32_SHIFT;
    }
}
#pragma thumb reset

#pragma thumb off
BOOL NNSi_G3dAnmBlendJnt (NNSG3dJntAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 nodeID)
{

    if (!pAnmObj) {
        return FALSE;
    }

    if (!pAnmObj->next) {
        u32 dataIdx;
        if (nodeID < pAnmObj->numMapData) {
            dataIdx = pAnmObj->mapData[nodeID];
            if ((dataIdx & (NNS_G3D_ANMOBJ_MAPDATA_EXIST |
                            NNS_G3D_ANMOBJ_MAPDATA_DISABLED)) ==
                NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                NNSG3dFuncAnmJnt func = (NNSG3dFuncAnmJnt)pAnmObj->funcAnm;

                if (func) {
                    (*func)(pResult,
                            pAnmObj,
                            dataIdx & NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD);
                    return TRUE;
                } else {
                    return FALSE;
                }
            } else {
                return FALSE;
            }
        } else {
            return FALSE;
        }
    } else {
        const NNSG3dAnmObj * p;
        NNSG3dJntAnmResult r;
        fx32 sumOfRatio = 0;
        const NNSG3dAnmObj * pLastAnmObj;
        int numBlend = 0;
        int i1 = 0;
        VecFx32 keepAxisX;
        VecFx32 keepAxisZ;

        p = pAnmObj;
        do {
            if (nodeID < p->numMapData) {
                u32 dataIdx = p->mapData[nodeID];
                if ((dataIdx & (NNS_G3D_ANMOBJ_MAPDATA_EXIST |
                                NNS_G3D_ANMOBJ_MAPDATA_DISABLED)) ==
                    NNS_G3D_ANMOBJ_MAPDATA_EXIST) {

                    if (p->ratio > FX32_ONE)
                        sumOfRatio += FX32_ONE;
                    else if (p->ratio > 0)
                        sumOfRatio += p->ratio;

                    pLastAnmObj = p;
                    ++numBlend;
                }
            }
            p = p->next;
        } while (p);

        if (sumOfRatio == 0) {
            return FALSE;
        }

        if (numBlend == 1) {
            NNSG3dFuncAnmJnt func = (NNSG3dFuncAnmJnt)pLastAnmObj->funcAnm;
            u32 dataIdx = pLastAnmObj->mapData[nodeID];

            if (func) {
                (*func)(pResult, pLastAnmObj, dataIdx & NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD);
                return TRUE;
            } else {
                return FALSE;
            }
        }

        MI_CpuClearFast(pResult, sizeof(*pResult));
        pResult->flag = (NNSG3dJntAnmResultFlag) - 1;

        p = pAnmObj;
        do {
            if (nodeID < p->numMapData) {
                u32 dataIdx = p->mapData[nodeID];
                if ((dataIdx & (NNS_G3D_ANMOBJ_MAPDATA_EXIST |
                                NNS_G3D_ANMOBJ_MAPDATA_DISABLED)) ==
                    NNS_G3D_ANMOBJ_MAPDATA_EXIST &&
                    (p->ratio > 0)) {
                    fx32 ratio;
                    NNSG3dFuncAnmJnt func = (NNSG3dFuncAnmJnt)p->funcAnm;

                    if (func) {
                        (*func)(&r, p, dataIdx & NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD);

                        if (i1 == 0) {
                            MI_CpuCopy32(&r.rot._00, &keepAxisX, sizeof(VecFx32));
                            MI_CpuCopy32(&r.rot._20, &keepAxisZ, sizeof(VecFx32));
                        }

                        if (sumOfRatio != FX32_ONE) {
                            ratio = FX_Div(p->ratio, sumOfRatio);
                        } else {
                            ratio = p->ratio;
                        }

                        blendScaleVec_(&pResult->scale,
                                       &r.scale,
                                       ratio,
                                       r.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE);

                        blendScaleVec_(&pResult->scaleEx0,
                                       &r.scaleEx0,
                                       ratio,
                                       r.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE);

                        blendScaleVec_(&pResult->scaleEx1,
                                       &r.scaleEx1,
                                       ratio,
                                       r.flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE);

                        if (!(r.flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO)) {
                            pResult->trans.x += (fx32)((fx64)ratio * r.trans.x >> FX32_SHIFT);
                            pResult->trans.y += (fx32)((fx64)ratio * r.trans.y >> FX32_SHIFT);
                            pResult->trans.z += (fx32)((fx64)ratio * r.trans.z >> FX32_SHIFT);
                        }

                        if (!(r.flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO)) {
                            pResult->rot._00 += ratio * r.rot._00 >> FX32_SHIFT;
                            pResult->rot._01 += ratio * r.rot._01 >> FX32_SHIFT;
                            pResult->rot._02 += ratio * r.rot._02 >> FX32_SHIFT;
                            pResult->rot._10 += ratio * r.rot._10 >> FX32_SHIFT;
                            pResult->rot._11 += ratio * r.rot._11 >> FX32_SHIFT;
                            pResult->rot._12 += ratio * r.rot._12 >> FX32_SHIFT;
                        } else {
                            pResult->rot._00 += ratio;
                            pResult->rot._11 += ratio;
                        }

                        pResult->flag &= r.flag;
                    }
                }
            }

            p = p->next;
            ++i1;

        } while (p);

        VEC_CrossProduct((VecFx32 *)&pResult->rot._00,
                         (VecFx32 *)&pResult->rot._10,
                         (VecFx32 *)&pResult->rot._20);

        if ((pResult->rot._00 == 0) &&
            (pResult->rot._01 == 0) &&
            (pResult->rot._02 == 0)) {

            MI_CpuCopy32(&keepAxisX, &pResult->rot._00, sizeof(VecFx32));
        } else {
            VEC_Normalize((VecFx32 *)&pResult->rot._00, (VecFx32 *)&pResult->rot._00);
        }

        if ((pResult->rot._20 == 0) &&
            (pResult->rot._21 == 0) &&
            (pResult->rot._22 == 0)) {

            MI_CpuCopy32(&keepAxisZ, &pResult->rot._20, sizeof(VecFx32));
        } else {
            VEC_Normalize((VecFx32 *)&pResult->rot._20, (VecFx32 *)&pResult->rot._20);
        }

        VEC_CrossProduct((VecFx32 *)&pResult->rot._20,
                         (VecFx32 *)&pResult->rot._00,
                         (VecFx32 *)&pResult->rot._10);

        return TRUE;
    }
}
#pragma thumb reset

BOOL NNSi_G3dAnmBlendVis (NNSG3dVisAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 nodeID)
{
    BOOL rval = FALSE;
    const NNSG3dAnmObj * p;
    NNSG3dVisAnmResult tmp;

    p = pAnmObj;
    pResult->isVisible = FALSE;
    do {
        if (nodeID < p->numMapData) {
            u32 dataIdx = p->mapData[nodeID];

            if ((dataIdx & (NNS_G3D_ANMOBJ_MAPDATA_EXIST |
                            NNS_G3D_ANMOBJ_MAPDATA_DISABLED)) ==
                NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                NNSG3dFuncAnmVis func = (NNSG3dFuncAnmVis)p->funcAnm;
                if (func) {
                    (*func)(&tmp, p, dataIdx & NNS_G3D_ANMOBJ_MAPDATA_DATAFIELD);
                    pResult->isVisible |= tmp.isVisible;
                    rval = TRUE;
                }
            }
        }
        p = p->next;
    } while (p);

    return rval;
}
