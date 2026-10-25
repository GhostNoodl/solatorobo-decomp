// sbc.c's .data: the per-scaling-rule and per-texture-matrix-mode function tables, the SBC command
// and material / shape tables, and the geometry command packets the PRJMAP, ENVMAP, BB and BBY
// commands fill in and send. A data-only file so the matched sbc.c is left as it is; it links
// right after sbc.c.
//
// MWCC sorts a file's .data objects by size; the definition order here gives the order of the
// equal-sized ones in the ROM.

#include <nnsys/g3d.h>

void NNSi_G3dSendJointSRTBasic(const NNSG3dJntAnmResult *);
void NNSi_G3dSendJointSRTMaya(const NNSG3dJntAnmResult *);
void NNSi_G3dSendJointSRTSi3d(const NNSG3dJntAnmResult *);
void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *, const fx32 *, const u8 *, u32);
void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *, const fx32 *, const u8 *, u32);
void NNSi_G3dGetJointScaleSi3d(NNSG3dJntAnmResult *, const fx32 *, const u8 *, u32);
void NNSi_G3dSendTexSRTMaya(const NNSG3dMatAnmResult *);
void NNSi_G3dSendTexSRTSi3d(const NNSG3dMatAnmResult *);
void NNSi_G3dSendTexSRT3dsMax(const NNSG3dMatAnmResult *);
void NNSi_G3dSendTexSRTXsi(const NNSG3dMatAnmResult *);

// The billboard packets: pop the matrix, switch to position-vector mode, load the billboard
// matrix (identity rotation, filled-in translation) and apply the joint's scale.
#define BB_CMD                                                                          \
    {                                                                                   \
        GX_PACK_OP(G3OP_MTX_POP, G3OP_MTX_MODE, G3OP_MTX_LOAD_4x3, G3OP_MTX_SCALE),    \
        1,                                                                              \
        GX_MTXMODE_POSITION_VECTOR,                                                     \
        FX32_ONE, 0, 0,                                                                 \
        0, FX32_ONE, 0,                                                                 \
        0, 0, FX32_ONE,                                                                 \
        0, 0, 0,                                                                        \
        0, 0, 0,                                                                        \
    }

NNSG3dGetJointScale NNS_G3dGetJointScale_FuncArray[NNS_G3D_FUNC_SENDJOINTSRT_MAX] = {
    NNSi_G3dGetJointScaleBasic,
    NNSi_G3dGetJointScaleMaya,
    NNSi_G3dGetJointScaleSi3d,
};

// [NNS_G3D_SCALINGRULE_*]
NNSG3dSendJointSRT NNS_G3dSendJointSRT_FuncArray[NNS_G3D_FUNC_SENDJOINTSRT_MAX] = {
    NNSi_G3dSendJointSRTBasic,
    NNSi_G3dSendJointSRTMaya,
    NNSi_G3dSendJointSRTSi3d,
};

NNSG3dFuncSbc_MatInternal NNS_G3dFuncSbcMatTable[NNS_G3D_SIZE_MAT_VTBL_NUM] = {
    NNSi_G3dFuncSbc_MAT_InternalDefault,
};

NNSG3dFuncSbc_ShpInternal NNS_G3dFuncSbcShpTable[NNS_G3D_SIZE_SHP_VTBL_NUM] = {
    NNSi_G3dFuncSbc_SHP_InternalDefault,
};

// [NNS_G3D_TEXMTXMODE_*]
NNSG3dSendTexSRT NNS_G3dSendTexSRT_FuncArray[NNS_G3D_FUNC_SENDTEXSRT_MAX] = {
    NNSi_G3dSendTexSRTMaya,
    NNSi_G3dSendTexSRTSi3d,
    NNSi_G3dSendTexSRT3dsMax,
    NNSi_G3dSendTexSRTXsi,
};

// TEXIMAGE_PARAM commands; the parameter is filled in. [0..1] for PRJMAP, [2..3] for ENVMAP.
u32 texImageParamCmd_[4] = {
    G3OP_TEXIMAGE_PARAM, 0,
    G3OP_TEXIMAGE_PARAM, 0,
};

// The projection-map texture matrix: texture coordinates are in 1/16 texel, and PRJMAP fills in
// the scale and offset from the texture size.
MtxFx44 prjMapMtx_ = {
    0, 0, 0,             0,
    0, 0, 0,             0,
    0, 0, FX32_ONE * 16, 0,
    0, 0, 0,             FX32_ONE * 16,
};

u32 bbCmd_[18] = BB_CMD;

u32 bbyCmd_[18] = BB_CMD;

// [NNS_G3D_SBC_*]
NNSG3dFuncSbc NNS_G3dFuncSbcTable[NNS_G3D_SBC_COMMAND_NUM] = {
    NNSi_G3dFuncSbc_NOP,
    NNSi_G3dFuncSbc_RET,
    NNSi_G3dFuncSbc_NODE,
    NNSi_G3dFuncSbc_MTX,
    NNSi_G3dFuncSbc_MAT,
    NNSi_G3dFuncSbc_SHP,
    NNSi_G3dFuncSbc_NODEDESC,
    NNSi_G3dFuncSbc_BB,
    NNSi_G3dFuncSbc_BBY,
    NNSi_G3dFuncSbc_NODEMIX,
    NNSi_G3dFuncSbc_CALLDL,
    NNSi_G3dFuncSbc_POSSCALE,
    NNSi_G3dFuncSbc_ENVMAP,
    NNSi_G3dFuncSbc_PRJMAP,
};

