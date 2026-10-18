#include <nnsys/g3d.h>

void NNS_G3dGlbInit (void)
{
    NNS_G3dGlb.cmd0 = GX_PACK_OP(G3OP_MTX_MODE, G3OP_MTX_LOAD_4x4, G3OP_MTX_MODE, G3OP_MTX_LOAD_4x3);
    NNS_G3dGlb.mtxmode_proj = GX_MTXMODE_PROJECTION;
    NNS_G3dGlb.mtxmode_posvec = GX_MTXMODE_POSITION_VECTOR;

    NNS_G3dGlb.cmd1 = GX_PACK_OP(G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR);
    NNS_G3dGlb.cmd2 = GX_PACK_OP(G3OP_DIF_AMB, G3OP_SPE_EMI, G3OP_POLYGON_ATTR, G3OP_VIEWPORT);
    NNS_G3dGlb.cmd3 = GX_PACK_OP(G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR);
    NNS_G3dGlb.cmd4 = GX_PACK_OP(G3OP_MTX_MULT_4x3, G3OP_MTX_SCALE, G3OP_TEXIMAGE_PARAM, G3OP_NOP);

    MTX_Identity43(&NNS_G3dGlb.cameraMtx);
    MTX_Identity44(&NNS_G3dGlb.projMtx);

    NNS_G3dGlb.lightVec[0] = GX_PACK_LIGHTVECTOR_PARAM(0, -FX16_SQRT1_3, -FX16_SQRT1_3, -FX16_SQRT1_3);
    NNS_G3dGlb.lightVec[1] = GX_PACK_LIGHTVECTOR_PARAM(1, -FX16_ONE, 0, 0);
    NNS_G3dGlb.lightVec[2] = GX_PACK_LIGHTVECTOR_PARAM(2, FX16_ONE - 1, 0, 0);
    NNS_G3dGlb.lightVec[3] = GX_PACK_LIGHTVECTOR_PARAM(3, 0, -FX16_ONE, 0);

    NNS_G3dGlb.prmMatColor0 = GX_PACK_DIFFAMB_PARAM(GX_RGB(16, 16, 16),
                                                    GX_RGB(16, 16, 16),
                                                    TRUE);
    NNS_G3dGlb.prmMatColor1 = GX_PACK_SPECEMI_PARAM(GX_RGB(16, 16, 16),
                                                    GX_RGB(16, 16, 16),
                                                    TRUE);

    NNS_G3dGlb.prmPolygonAttr = GX_PACK_POLYGONATTR_PARAM(0xf,
                                                          GX_POLYGONMODE_MODULATE,
                                                          GX_CULL_BACK,
                                                          0,
                                                          31,
                                                          GX_POLYGON_ATTR_MISC_NONE);

    NNS_G3dGlb.prmViewPort = GX_PACK_VIEWPORT_PARAM(0, 0, 255, 191);

    NNS_G3dGlb.lightColor[0] = GX_PACK_LIGHTCOLOR_PARAM(0, GX_RGB(31, 31, 31));
    NNS_G3dGlb.lightColor[1] = GX_PACK_LIGHTCOLOR_PARAM(1, GX_RGB(31, 0, 0));
    NNS_G3dGlb.lightColor[2] = GX_PACK_LIGHTCOLOR_PARAM(2, GX_RGB(0, 31, 0));
    NNS_G3dGlb.lightColor[3] = GX_PACK_LIGHTCOLOR_PARAM(3, GX_RGB(0, 0, 31));

    NNS_G3dGlb.prmBaseTrans.x = 0;
    NNS_G3dGlb.prmBaseTrans.y = 0;
    NNS_G3dGlb.prmBaseTrans.z = 0;

    MTX_Identity33(&NNS_G3dGlb.prmBaseRot);

    NNS_G3dGlb.prmBaseScale.x = FX32_ONE;
    NNS_G3dGlb.prmBaseScale.y = FX32_ONE;
    NNS_G3dGlb.prmBaseScale.z = FX32_ONE;
    NNS_G3dGlb.prmTexImageParam = 0;

    NNS_G3dGlb.flag = (NNSG3dGlbFlag) 0;

    NNS_G3dGlb.camPos.x = NNS_G3dGlb.camPos.y = NNS_G3dGlb.camPos.z = 0;
    NNS_G3dGlb.camUp.x = NNS_G3dGlb.camUp.z = 0;
    NNS_G3dGlb.camUp.y = FX32_ONE;
    NNS_G3dGlb.camTarget.x = NNS_G3dGlb.camTarget.y = 0;
    NNS_G3dGlb.camTarget.z = -FX32_ONE;
}

void NNS_G3dGlbFlushP (void)
{
    static const u32 sz = (sizeof(NNS_G3dGlb.cmd0) +
                           sizeof(NNS_G3dGlb.mtxmode_proj) +
                           sizeof(NNS_G3dGlb.projMtx) +
                           sizeof(NNS_G3dGlb.mtxmode_posvec) +
                           sizeof(NNS_G3dGlb.cameraMtx) +
                           sizeof(NNS_G3dGlb.cmd1) +
                           sizeof(NNS_G3dGlb.lightVec[0]) * 4 +
                           sizeof(NNS_G3dGlb.cmd2) +
                           sizeof(NNS_G3dGlb.prmMatColor0) +
                           sizeof(NNS_G3dGlb.prmMatColor1) +
                           sizeof(NNS_G3dGlb.prmPolygonAttr) +
                           sizeof(NNS_G3dGlb.prmViewPort) +
                           sizeof(NNS_G3dGlb.cmd4) +
                           sizeof(NNS_G3dGlb.prmBaseTrans) +
                           sizeof(NNS_G3dGlb.prmBaseRot) +
                           sizeof(NNS_G3dGlb.prmBaseScale) +
                           sizeof(NNS_G3dGlb.prmTexImageParam) +
                           sizeof(NNS_G3dGlb.cmd3) +
                           sizeof(NNS_G3dGlb.lightColor[0]) * 4) / 4;

    NNS_G3dGeBufferData_N((u32 *)&NNS_G3dGlb.cmd0, sz);

    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_FLUSH_WVP;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_FLUSH_VP;

}

void NNS_G3dGlbFlushVP (void)
{
    static const u32 sz = (sizeof(NNS_G3dGlb.cmd1) +
                           sizeof(NNS_G3dGlb.lightVec[0]) * 4 +
                           sizeof(NNS_G3dGlb.cmd2) +
                           sizeof(NNS_G3dGlb.prmMatColor0) +
                           sizeof(NNS_G3dGlb.prmMatColor1) +
                           sizeof(NNS_G3dGlb.prmPolygonAttr) +
                           sizeof(NNS_G3dGlb.prmViewPort) +
                           sizeof(NNS_G3dGlb.cmd3) +
                           sizeof(NNS_G3dGlb.lightColor[0]) * 4 +
                           sizeof(NNS_G3dGlb.cmd4) +
                           sizeof(NNS_G3dGlb.prmBaseRot) +
                           sizeof(NNS_G3dGlb.prmBaseTrans) +
                           sizeof(NNS_G3dGlb.prmBaseScale) +
                           sizeof(NNS_G3dGlb.prmTexImageParam)) / 4;

    NNS_G3dGeBufferOP_N(GX_PACK_OP(G3OP_MTX_MODE, G3OP_MTX_LOAD_4x4, G3OP_NOP, G3OP_NOP),
                        (u32 *)&NNS_G3dGlb.mtxmode_proj,
                        (sizeof(NNS_G3dGlb.mtxmode_proj) +
                         sizeof(NNS_G3dGlb.projMtx)) / 4);

    NNS_G3dGeBufferOP_N((G3OP_MTX_MULT_4x3 << 0),
                        (u32 *)&NNS_G3dGlb.cameraMtx,
                        sizeof(NNS_G3dGlb.cameraMtx) / 4);

    NNS_G3dGeMtxMode(GX_MTXMODE_POSITION_VECTOR);
    NNS_G3dGeBufferOP_N(G3OP_MTX_IDENTITY, (u32 *)&NNS_G3dGlb.cmd1, sz);

    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_FLUSH_WVP;
    NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_FLUSH_VP;
}

void NNS_G3dGlbSetBaseTrans (const VecFx32 * pTrans)
{

    if (pTrans) {
        NNS_G3dGlb.prmBaseTrans = *pTrans;
        NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVBASE_UPTODATE |
                             NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE |
                             NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE);
    }
}

void NNS_G3dGlbSetBaseScale (const VecFx32 * pScale)
{

    if (pScale) {
        NNS_G3dGlb.prmBaseScale = *pScale;
        NNS_G3dGlb.flag &= ~(NNS_G3D_GLB_FLAG_INVBASE_UPTODATE |
                             NNS_G3D_GLB_FLAG_INVBASECAMERA_UPTODATE |
                             NNS_G3D_GLB_FLAG_BASECAMERA_UPTODATE);
    }
}

void NNS_G3dGlbLightVector (GXLightId lightID, fx16 x, fx16 y, fx16 z)
{

    NNS_G3dGlb.lightVec[lightID] = GX_PACK_LIGHTVECTOR_PARAM(lightID, x, y, z);
}

void NNS_G3dGlbLightColor (GXLightId lightID, GXRgb rgb)
{
    GXRGB_ASSERT(rgb);

    NNS_G3dGlb.lightColor[lightID] = GX_PACK_LIGHTCOLOR_PARAM(lightID, rgb);
}

void NNS_G3dGlbMaterialColorDiffAmb (GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor)
{
    GXRGB_ASSERT(diffuse);
    GXRGB_ASSERT(ambient);

    NNS_G3dGlb.prmMatColor0 = GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor);
}

void NNS_G3dGlbMaterialColorSpecEmi (GXRgb specular, GXRgb emission, BOOL IsShininess)
{
    GXRGB_ASSERT(specular);
    GXRGB_ASSERT(emission);

    NNS_G3dGlb.prmMatColor1 = GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess);
}

void NNS_G3dGlbPolygonAttr (int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc)
{

    NNS_G3dGlb.prmPolygonAttr = GX_PACK_POLYGONATTR_PARAM(light,
                                                          polyMode,
                                                          cullMode,
                                                          polygonID,
                                                          alpha,
                                                          misc);
}

const MtxFx43 * NNS_G3dGlbGetInvV (void)
{
    if (!(NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE)) {
        s32 result = MTX_Inverse43(&NNS_G3dGlb.cameraMtx, &NNS_G3dGlb.invCameraMtx);
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE;
    }
    return &NNS_G3dGlb.invCameraMtx;
}

static void calcSrtCameraMtx_ (void)
{
    s32 result;

    MTX_Concat43((MtxFx43 *)&NNS_G3dGlb.prmBaseRot,
                 &NNS_G3dGlb.cameraMtx,
                 &NNS_G3dGlb.srtCameraMtx);
    MTX_ScaleApply43(&NNS_G3dGlb.srtCameraMtx,
                     &NNS_G3dGlb.srtCameraMtx,
                     NNS_G3dGlb.prmBaseScale.x,
                     NNS_G3dGlb.prmBaseScale.y,
                     NNS_G3dGlb.prmBaseScale.z);
    result = MTX_Inverse43(&NNS_G3dGlb.srtCameraMtx,
                           &NNS_G3dGlb.invSrtCameraMtx);
}

const MtxFx43 * NNS_G3dGlbGetWV (void)
{
    if (!(NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE)) {
        calcSrtCameraMtx_();
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE;
    }

    return &NNS_G3dGlb.srtCameraMtx;
}

const MtxFx43 * NNS_G3dGlbGetInvWV (void)
{
    if (!(NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE)) {
        calcSrtCameraMtx_();
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE;
    }

    return &NNS_G3dGlb.invSrtCameraMtx;
}

