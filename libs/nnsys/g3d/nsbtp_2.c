#include <nnsys/g3d.h>

#pragma force_active on

void SetTexParamaters_ (const NNSG3dResTex * pTex, const NNSG3dResName * pTexName, NNSG3dMatAnmResult * pResult);

void SetPlttParamaters_ (const NNSG3dResTex * pTex, const NNSG3dResName * pPlttName, NNSG3dMatAnmResult * pResult)
{
    const NNSG3dResDictPlttData * pPlttData = NNS_G3dGetPlttDataByName(pTex, pPlttName);
    u16 plttBase = pPlttData->offset;
    u16 vramOffset = (u16)(NNS_GfdGetPlttKeyAddr(pTex->plttInfo.vramKey) >> 3);

    if (!(pPlttData->flag & 1)) {
        plttBase >>= 1;
        vramOffset >>= 1;
    }

    pResult->prmTexPltt = (u32)(plttBase + vramOffset);
}

void NNSi_G3dAnmCalcNsBtp (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    fx32 frame;
    const NNSG3dResTexPatAnm * pPatAnm = (const NNSG3dResTexPatAnm *)pAnmObj->resAnm;

    if (pAnmObj->frame >= (pPatAnm->numFrame << FX32_SHIFT))
        frame = (pPatAnm->numFrame << FX32_SHIFT) - 1;
    else if (pAnmObj->frame < 0)
        frame = 0;
    else
        frame = pAnmObj->frame;

    {
        const NNSG3dResTexPatAnmFV * pfv = NNSi_G3dGetTexPatAnmFV(pPatAnm, (u16)dataIdx, (u16)FX_Whole(frame));

        {
            const NNSG3dResName * pTexName = NNSi_G3dGetTexPatAnmTexNameByIdx(pPatAnm, pfv->idTex);
            SetTexParamaters_(pAnmObj->resTex, pTexName, pResult);
        }

        if (pfv->idPltt != 0xff) {
            const NNSG3dResName * pPlttName = NNSi_G3dGetTexPatAnmPlttNameByIdx(pPatAnm, pfv->idPltt);
            SetPlttParamaters_(pAnmObj->resTex, pPlttName, pResult);
        }
    }
}
