#include "nitro/gx_g3b.h"
#ifdef SDK_WIN32
    #else
            
    #endif

void G3B_PushMtx (GXDLInfo *info)
{
    G3BS_PushMtx(info);
    G3B_UpdateGXDLInfo(info, G3OP_MTX_PUSH_NPARAMS);
}

void G3B_PopMtx (GXDLInfo *info, int num)
{
    G3BS_PopMtx(info, num);
    G3B_UpdateGXDLInfo(info, G3OP_MTX_POP_NPARAMS);
}

void G3B_Scale (GXDLInfo *info, fx32 x, fx32 y, fx32 z)
{
    G3BS_Scale(info, x, y, z);
    G3B_UpdateGXDLInfo(info, G3OP_MTX_SCALE_NPARAMS);
}

void G3B_Translate (GXDLInfo *info, fx32 x, fx32 y, fx32 z)
{
    G3BS_Translate(info, x, y, z);
    G3B_UpdateGXDLInfo(info, G3OP_MTX_TRANS_NPARAMS);
}

void G3B_Color (GXDLInfo *info, GXRgb rgb)
{
    G3BS_Color(info, rgb);
    G3B_UpdateGXDLInfo(info, G3OP_COLOR_NPARAMS);
}

void G3B_TexCoord (GXDLInfo *info, fx32 s, fx32 t)
{
    G3BS_TexCoord(info, s, t);
    G3B_UpdateGXDLInfo(info, G3OP_TEXCOORD_NPARAMS);
}

void G3B_Vtx (GXDLInfo *info, fx16 x, fx16 y, fx16 z)
{
    G3BS_Vtx(info, x, y, z);
    G3B_UpdateGXDLInfo(info, G3OP_VTX_16_NPARAMS);
}

void G3B_VtxXY (GXDLInfo *info, fx16 x, fx16 y)
{
    G3BS_VtxXY(info, x, y);
    G3B_UpdateGXDLInfo(info, G3OP_VTX_XY_NPARAMS);
}

void G3B_Begin (GXDLInfo *info, GXBegin primitive)
{
    G3BS_Begin(info, primitive);
    G3B_UpdateGXDLInfo(info, G3OP_BEGIN_NPARAMS);
}

void G3B_End (GXDLInfo *info)
{
    G3BS_End(info);
    G3B_UpdateGXDLInfo(info, G3OP_END_NPARAMS);
}
