#include "nitro/gx.h"
#include "nitro/gx_bgcnt.h"
#include "nitro/mi.h"

void GXi_NopClearFifo128_(register void *pDest);

void G3X_Init (void)
{
#ifdef SDK_DEBUG
    {
        GXPower power = GX_GetPower();
    }
#endif

    G3X_ClearFifo();
    G3_End();

    while ( G3X_IsGeometryBusy()) {
    }

    reg_G3X_DISP3DCNT = 0;
    reg_G3X_GXSTAT = 0;
    reg_G2_BG0OFS = 0;

    G3X_ResetListRamOverflow();
    G3X_ResetLineBufferUnderflow();
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);

    G3X_ResetMtxStackOverflow();
    G3X_SetFifoIntrCond(GX_FIFOINTR_COND_EMPTY);
    G3X_InitMtxStack();

    reg_G3X_CLEAR_COLOR = 0;
    reg_G3X_CLEAR_DEPTH = 0x7fff;
    reg_G3X_CLRIMAGE_OFFSET = 0;
    reg_G3X_FOG_COLOR = 0;
    reg_G3X_FOG_OFFSET = 0;

    G2_SetBG0Priority(0);
    G3X_InitTable();
    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_BACK, 0, 31, GX_POLYGON_ATTR_MISC_NONE);

    G3_TexImageParam(GX_TEXFMT_NONE,
                     GX_TEXGEN_NONE,
                     GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE, 0);

    G3_Direct1(G3OP_TEXPLTT_BASE, 0);
}

void G3X_Reset (void)
{
#ifdef SDK_DEBUG
    {
        GXPower power = GX_GetPower();

    }
#endif

    while (G3X_IsGeometryBusy()) {
    }

    G3X_ResetMtxStackOverflow();
    G3X_ResetListRamOverflow();
    G3X_ResetLineBufferUnderflow();
    G3X_ResetMtxStack();

    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_BACK, 0, 31,
                   GX_POLYGON_ATTR_MISC_NONE);

    G3_TexImageParam(GX_TEXFMT_NONE,
                     GX_TEXGEN_NONE,
                     GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE,
                     GX_TEXPLTTCOLOR0_USE, 0);

    G3_Direct1(G3OP_TEXPLTT_BASE, 0);
}

void G3X_ClearFifo (void)
{
    GXi_NopClearFifo128_((void *)&reg_G3X_GXFIFO);

    while (G3X_IsGeometryBusy()) {
    }
}

void G3X_InitMtxStack (void)
{
    s32 levelPV;
    s32 levelPJ;
#ifdef SDK_DEBUG
    {
        GXPower power = GX_GetPower();
    }
#endif
    G3X_ResetMtxStackOverflow();

    while (G3X_GetMtxStackLevelPV(&levelPV))
        ;

    while (G3X_GetMtxStackLevelPJ(&levelPJ))
        ;

    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_MtxMode(GX_MTXMODE_PROJECTION);

    if (levelPJ != 0) {
        G3_PopMtx(levelPJ);
    }

    G3_Identity();
    G3_MtxMode(GX_MTXMODE_POSITION_VECTOR);
    G3_PopMtx(levelPV);
    G3_Identity();
}

void G3X_ResetMtxStack (void)
{
    s32 levelPV;
    s32 levelPJ;
#ifdef SDK_DEBUG
    {
        GXPower power = GX_GetPower();
    }
#endif
    G3X_ResetMtxStackOverflow();

    while (G3X_GetMtxStackLevelPV(&levelPV))
        ;

    while (G3X_GetMtxStackLevelPJ(&levelPJ))
        ;

    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_MtxMode(GX_MTXMODE_PROJECTION);

    if (levelPJ != 0) {
        G3_PopMtx(levelPJ);
    }

    G3_MtxMode(GX_MTXMODE_POSITION_VECTOR);
    G3_PopMtx(levelPV);
    G3_Identity();

}

void G3X_SetFog (BOOL enable, GXFogBlend fogMode, GXFogSlope fogSlope, int fogOffset)
{
    if (enable) {

        reg_G3X_FOG_OFFSET = (u16)fogOffset;

        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT &
                                   ~(REG_G3X_DISP3DCNT_FOG_SHIFT_MASK
                                     | REG_G3X_DISP3DCNT_FMOD_MASK
                                     | REG_G3X_DISP3DCNT_RO_MASK
                                     | REG_G3X_DISP3DCNT_GO_MASK))
                                  | ((fogSlope << REG_G3X_DISP3DCNT_FOG_SHIFT_SHIFT)
                                     | (fogMode << REG_G3X_DISP3DCNT_FMOD_SHIFT)
                                     | (REG_G3X_DISP3DCNT_FME_MASK)));
    } else {
        reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_FME_MASK
                                     | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}

int G3X_GetClipMtx (MtxFx44 *m)
{

    if (G3X_IsGeometryBusy()) {
        return -1;
    } else {
        MI_Copy64B((void *)REG_CLIPMTX_RESULT_0_ADDR, &m->_00);
        return 0;
    }
}

int G3X_GetVectorMtx (MtxFx33 *m)
{

    if (G3X_IsGeometryBusy()) {
        return -1;
    } else {
        MI_Copy36B((void *)(REG_VECMTX_RESULT_0_ADDR), &m->_00);
        return 0;
    }
}

void G3X_SetEdgeColorTable (const GXRgb *rgb_8)
{
    MI_CpuCopy16(rgb_8, (void *)REG_EDGE_COLOR_0_L_ADDR, 16);
}

void G3X_SetFogTable (const u32 *fogTable)
{
    MI_Copy32B(&fogTable[0], (void *)REG_FOG_TABLE_0_ADDR);
}

void G3X_SetToonTable (const GXRgb *rgb_32)
{
    MI_CpuCopy16(rgb_32, (void *)REG_TOON_TABLE_0_L_ADDR, 64);
}

void G3X_SetClearColor (GXRgb rgb, int alpha, int depth, int polygonID, BOOL fog)
{
    u32 val;
    GXRGB_ASSERT(rgb);

    val = (u32)(rgb | (alpha << REG_G3X_CLEAR_COLOR_ALPHA_SHIFT) | (polygonID << REG_G3X_CLEAR_COLOR_POLYGONID_SHIFT));

    if (fog)
        val |= REG_G3X_CLEAR_COLOR_F_MASK;

    reg_G3X_CLEAR_COLOR = val;
    reg_G3X_CLEAR_DEPTH = (u16)depth;
}

void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL wait);
void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, void (*callback)(void *), void *arg, BOOL wait);
void func_0228de30(u32 ndmaNo, void *dest, u32 data, u32 size);  /* MI_NDmaFill (TWL only) */
void func_0228ded8(u32 ndmaNo, void *dest, u32 data, u32 size, void (*callback)(void *), void *arg);  /* MI_NDmaFillAsync */

void G3X_InitTable (void)
{
    int i;

    if (GXi_DmaId != (u32)-1) {
        if (GXi_DmaId > 3) {
            func_0228ded8(GXi_DmaId - 4, (void *)0x04000330, 0, 0x10, NULL, NULL);
            func_0228de30(GXi_DmaId - 4, (void *)0x04000360, 0, 0x60);
        } else {
            MIi_DmaFill32Async(GXi_DmaId, (void *)0x04000330, 0, 0x10, NULL, NULL, TRUE);
            MIi_DmaFill32(GXi_DmaId, (void *)0x04000360, 0, 0x60, TRUE);
        }
    } else {
        MI_CpuClear32((void *)0x04000330, 0x10);
        MI_CpuClear32((void *)0x04000360, 0x60);
    }

    for (i = 0; i < 32; i++) {
        *(vu32 *)0x040004d0 = 0;
    }
}
