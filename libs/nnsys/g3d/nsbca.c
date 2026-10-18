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

extern const u8 pivotUtil_[9][4];

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

void NNSi_G3dAnmObjInitNsBca (NNSG3dAnmObj * pAnmObj, void * pResAnm, const NNSG3dResMdl * pResMdl)
{
    u32 i;
    u16 * ofsArray;
    NNSG3dResJntAnm * jntAnm;
    const NNSG3dResNodeInfo * jnt;

    pAnmObj->resAnm = pResAnm;
    jntAnm = (NNSG3dResJntAnm *)pResAnm;
    jnt = NNS_G3dGetNodeInfo(pResMdl);
    pAnmObj->funcAnm = NNS_G3dFuncAnmJntNsBcaDefault;
    pAnmObj->numMapData = pResMdl->info.numNode;

    MI_CpuClear16(&pAnmObj->mapData[0], sizeof(u16) * pAnmObj->numMapData);

    ofsArray = (u16 *)((u8 *)jntAnm + sizeof(NNSG3dResJntAnm));

    for (i = 0; i < jntAnm->numNode; ++i)
    {
        NNSG3dResJntAnmSRTTag * pTag =
            (NNSG3dResJntAnmSRTTag *)((u8 *)jntAnm + ofsArray[i]);
        pAnmObj->mapData[i] = (u16)((pTag->tag >> NNS_G3D_JNTANM_SRTINFO_NODE_SHIFT) |
                                    NNS_G3D_ANMOBJ_MAPDATA_EXIST);
    }
}

void NNSi_G3dAnmCalcNsBca (NNSG3dJntAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{

    {
        fx32 frame;
        NNSG3dResJntAnm * anm = (NNSG3dResJntAnm *)(pAnmObj->resAnm);

        if (pAnmObj->frame >= (anm->numFrame << FX32_SHIFT))
            frame = (anm->numFrame << FX32_SHIFT) - 1;
        else if (pAnmObj->frame < 0)
            frame = 0;
        else
            frame = pAnmObj->frame;

        getJntSRTAnmResult_(anm, dataIdx, frame, pResult);
    }
}

void getMdlTrans_ (NNSG3dJntAnmResult * pResult)
{
    u32 idxNode;
    const NNSG3dResNodeData * pNd;

    idxNode = *(NNS_G3dRS->c + 1);
    pNd = NNS_G3dGetNodeDataByIdx(NNS_G3dRS->pResNodeInfo, idxNode);

    if (pNd->flag & NNS_G3D_SRTFLAG_TRANS_ZERO) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO;
    } else {
        const fx32 * p_fx32 = (const fx32 *)((const u8 *)pNd + sizeof(NNSG3dResNodeData));

        pResult->trans.x = *(p_fx32 + 0);
        pResult->trans.y = *(p_fx32 + 1);
        pResult->trans.z = *(p_fx32 + 2);
    }
}

void getMdlScale_ (NNSG3dJntAnmResult * pResult)
{
    u32 idxNode;
    const NNSG3dResNodeData * pNd;
    const u8 * p;

    idxNode = *(NNS_G3dRS->c + 1);

    pNd = NNS_G3dGetNodeDataByIdx(NNS_G3dRS->pResNodeInfo, idxNode);
    p = (const u8 *)pNd + sizeof(*pNd);

    if (!(pNd->flag & NNS_G3D_SRTFLAG_TRANS_ZERO)) {
        p += 3 * sizeof(fx32);
    }

    if (!(pNd->flag & NNS_G3D_SRTFLAG_ROT_ZERO)) {
        if (pNd->flag & NNS_G3D_SRTFLAG_PIVOT_EXIST) {
            p += 2 * sizeof(fx16);
        } else {
            p += 8 * sizeof(fx16);
        }
    }

    (*NNS_G3dRS->funcJntScale)(pResult, (const fx32 *)p, NNS_G3dRS->c, pNd->flag);
}

