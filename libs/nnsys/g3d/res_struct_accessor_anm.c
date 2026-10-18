#include <nnsys/g3d.h>

#define NNS_G3D_SIZE_NNSG3DRESJNTANM    sizeof(NNSG3dResJntAnm)
#define NNS_G3D_SIZE_ROTMTX3            (3 * sizeof(u16))
#define NNS_G3D_SIZE_ROTMTX5            (5 * sizeof(u16))

void * NNS_G3dGetAnmByIdx (const void * pRes, u32 idx)
{

    if (pRes) {
        const NNSG3dResFileHeader * header;
        const NNSG3dResAnmSet * anmSet;
        const NNSG3dResDictAnmSetData * anmSetData;
        u32 * blks;

        header = (const NNSG3dResFileHeader *) pRes;
        blks = (u32 *)((u8 *)header + header->headerSize);

        anmSet = (const NNSG3dResAnmSet *)((u8 *)header + blks[0]);
        anmSetData = (const NNSG3dResDictAnmSetData *)NNS_G3dGetResDataByIdx(&anmSet->dict, idx);

        if (anmSetData) {
            return (void *)((u8 *)anmSet + anmSetData->offset);
        }
    }

    return NULL;
}

void * NNS_G3dGetAnmByName (const void * pRes, const NNSG3dResName * pName)
{

    if (pRes) {
        const NNSG3dResFileHeader * header;
        const NNSG3dResAnmSet * anmSet;
        const NNSG3dResDictAnmSetData * anmSetData;
        u32 * blks;
        header = (const NNSG3dResFileHeader *) pRes;
        blks = (u32 *)((u8 *)header + header->headerSize);

        anmSet = (const NNSG3dResAnmSet *)((u8 *)header + blks[0]);
        anmSetData = (const NNSG3dResDictAnmSetData *)NNS_G3dGetResDataByName(&anmSet->dict, pName);

        if (anmSetData) {
            return (void *)((u8 *)anmSet + anmSetData->offset);
        }
    }

    return NULL;
}

typedef fx32 (*FrameIdxValueAccessFuncPtr)(const void * pDataHead, u32 frameIdx, u32 step, u32 offset);

const NNSG3dResName * NNSi_G3dGetTexPatAnmTexNameByIdx (const NNSG3dResTexPatAnm * pPatAnm, u8 texIdx)
{

    if (pPatAnm && texIdx < pPatAnm->numTex) {
        const NNSG3dResName * pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsTexName);

        return &pNameArray[texIdx];
    }

    return NULL;
}

const NNSG3dResName * NNSi_G3dGetTexPatAnmPlttNameByIdx (const NNSG3dResTexPatAnm * pPatAnm, u8 plttIdx)
{

    if (pPatAnm && plttIdx < pPatAnm->numPltt) {
        const NNSG3dResName * pNameArray
            = (const NNSG3dResName *)((const u8 *)pPatAnm + pPatAnm->ofsPlttName);

        return &pNameArray[plttIdx];
    }

    return NULL;
}

const NNSG3dResTexPatAnmFV * NNSi_G3dGetTexPatAnmFV (const NNSG3dResTexPatAnm * pPatAnm, u32 idx, u32 frame)
{
    {
        const NNSG3dResDictTexPatAnmData * pAnmData =
            NNSi_G3dGetTexPatAnmDataByIdx(pPatAnm, idx);
        {

            const NNSG3dResTexPatAnmFV * pfvArray
                = (const NNSG3dResTexPatAnmFV *)((u8 *)pPatAnm + pAnmData->offset);

            const u32 fvIdx = (u32)((fx32)pAnmData->ratioDataFrame * frame >> FX32_SHIFT);

            {
                u32 realFvIdx = fvIdx;

                while (realFvIdx > 0 && pfvArray[ realFvIdx ].idxFrame >= frame) {
                    realFvIdx--;
                }

                while (realFvIdx + 1 < pAnmData->numFV && pfvArray[ realFvIdx + 1 ].idxFrame <= frame) {
                    realFvIdx++;
                }

                return &pfvArray[realFvIdx];
            }
        }
    }
}

const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx (const NNSG3dResTexPatAnm * pPatAnm, u32 idx)
{
    return (const NNSG3dResDictTexPatAnmData *)NNS_G3dGetResDataByIdx(&pPatAnm->dict, idx);
}
