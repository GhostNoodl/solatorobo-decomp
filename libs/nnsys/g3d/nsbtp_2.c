#include <nnsys/g3d.h>

#pragma force_active on

void SetTexParamaters_ (const NNSG3dResTex * pTex, const NNSG3dResName * pTexName, NNSG3dMatAnmResult * pResult)
{
    const NNSG3dResDictTexData * pData = NNS_G3dGetTexDataByName(pTex, pTexName);

    {
        const u32 vramOffset = ((pData->texImageParam & NNS_G3D_TEXIMAGE_PARAM_TEXFMT_MASK) != (GX_TEXFMT_COMP4x4 << NNS_G3D_TEXIMAGE_PARAM_TEXFMT_SHIFT)) ?
                               NNS_GfdGetTexKeyAddr(pTex->texInfo.vramKey) >> NNS_GFD_TEXKEY_ADDR_SHIFT :
                               NNS_GfdGetTexKeyAddr(pTex->tex4x4Info.vramKey) >> NNS_GFD_TEXKEY_ADDR_SHIFT;

        pResult->prmTexImage &= 0xc00f0000;
        pResult->prmTexImage |= pData->texImageParam + vramOffset;
    }

    pResult->origWidth = (u16)((pData->extraParam & NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_MASK) >> NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_SHIFT);
    pResult->origHeight = (u16)((pData->extraParam & NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_MASK) >> NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_SHIFT);

    {
        u32 w = (pData->extraParam & NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_MASK) >> NNS_G3D_TEXIMAGE_PARAMEX_ORIGW_SHIFT;
        u32 h = (pData->extraParam & NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_MASK) >> NNS_G3D_TEXIMAGE_PARAMEX_ORIGH_SHIFT;

        pResult->magW = (w != pResult->origWidth) ? FX_Div((fx32)(w << FX32_SHIFT), (fx32)(pResult->origWidth << FX32_SHIFT)) : FX32_ONE;
        pResult->magH = (h != pResult->origHeight) ? FX_Div((fx32)(h << FX32_SHIFT), (fx32)(pResult->origHeight << FX32_SHIFT)) : FX32_ONE;
    }
}

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
