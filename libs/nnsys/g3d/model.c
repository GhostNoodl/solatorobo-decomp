#include <nnsys/g3d.h>

void NNSi_G3dModifyMatFlag (NNSG3dResMdl * pMdl, BOOL isOn, NNSG3dMatFlag flag)
{
    u32 numMat;
    u32 i;
    NNSG3dResMat * mat;

    numMat = pMdl->info.numMat;
    mat = NNS_G3dGetMat(pMdl);

    for (i = 0; i < numMat; ++i) {
        NNSG3dResMatData * data = NNS_G3dGetMatDataByIdx(mat, i);

        if (isOn) {
            data->flag = (u16)(data->flag | flag);
        } else {
            data->flag = (u16)(data->flag & ~flag);
        }
    }
}

void NNSi_G3dModifyPolygonAttrMask (NNSG3dResMdl * pMdl, BOOL isOn, u32 mask)
{
    u32 numMat;
    u32 i;
    NNSG3dResMat * mat;

    numMat = pMdl->info.numMat;
    mat = NNS_G3dGetMat(pMdl);

    for (i = 0; i < numMat; ++i) {
        NNSG3dResMatData * data = NNS_G3dGetMatDataByIdx(mat, i);

        if (isOn) {
            data->polyAttrMask |= mask;
        } else {
            data->polyAttrMask &= ~mask;
        }
    }
}

void NNS_G3dMdlSetMdlCullMode (NNSG3dResMdl * pMdl, u32 matID, GXCull cullMode)
{
    NNSG3dResMatData * data;

    data = NNS_G3dGetMatDataByIdx(NNS_G3dGetMat(pMdl), matID);

    data->polyAttr = (data->polyAttr & ~(REG_G3_POLYGON_ATTR_BK_MASK | REG_G3_POLYGON_ATTR_FR_MASK)) |
                     (cullMode << REG_G3_POLYGON_ATTR_BK_SHIFT);
}

void NNS_G3dMdlSetMdlPolygonID (NNSG3dResMdl * pMdl, u32 matID, int polygonID)
{
    NNSG3dResMatData * data;

    data = NNS_G3dGetMatDataByIdx(NNS_G3dGetMat(pMdl), matID);

    data->polyAttr = (data->polyAttr & ~REG_G3_POLYGON_ATTR_ID_MASK) |
                     (polygonID << REG_G3_POLYGON_ATTR_ID_SHIFT);
}

void NNS_G3dMdlSetMdlAlpha (NNSG3dResMdl * pMdl, u32 matID, int alpha)
{
    NNSG3dResMatData * data;

    data = NNS_G3dGetMatDataByIdx(NNS_G3dGetMat(pMdl), matID);

    data->polyAttr = (data->polyAttr & ~REG_G3_POLYGON_ATTR_ALPHA_MASK) |
                     (alpha << REG_G3_POLYGON_ATTR_ALPHA_SHIFT);
}

void NNS_G3dMdlSetMdlXLDepthUpdate (NNSG3dResMdl * pMdl, u32 matID, BOOL flag)
{
    NNSG3dResMatData * data;

    data = NNS_G3dGetMatDataByIdx(NNS_G3dGetMat(pMdl), matID);

    if (flag)
        data->polyAttr |= REG_G3_POLYGON_ATTR_XL_MASK;
    else
        data->polyAttr &= ~REG_G3_POLYGON_ATTR_XL_MASK;
}

void NNS_G3dMdlSetMdlCullModeAll (NNSG3dResMdl * pMdl, GXCull cullMode)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlCullMode(pMdl, matID, cullMode);
    }
}

void NNS_G3dMdlSetMdlPolygonIDAll (NNSG3dResMdl * pMdl, int polygonID)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlPolygonID(pMdl, matID, polygonID);
    }
}

void NNS_G3dMdlSetMdlXLDepthUpdateAll (NNSG3dResMdl * pMdl, BOOL flag)
{
    u32 matID;
    for (matID = 0; matID < pMdl->info.numMat; ++matID) {
        NNS_G3dMdlSetMdlXLDepthUpdate(pMdl, matID, flag);
    }
}
