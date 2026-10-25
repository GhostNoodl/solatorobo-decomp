// anm.c's .data: the default animation calculate / blend functions and the table of animation
// formats NNS_G3dInitAnmObj looks up by resource category, with the five built-in formats.
// A data-only file so the matched anm.c is left as it is; it links right after anm.c.

#include <nnsys/g3d.h>

#define NNS_G3D_ANMFMT_BUILTIN 5

void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
void NNSi_G3dAnmCalcNsBva(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);

// MWCC sorts a file's .data objects by size; this order gives the ROM order of the equal-sized ones.
NNSG3dFuncAnmBlendMat NNS_G3dFuncBlendMatDefault = NNSi_G3dAnmBlendMat;
NNSG3dFuncAnmBlendJnt NNS_G3dFuncBlendJntDefault = NNSi_G3dAnmBlendJnt;
NNSG3dFuncAnmBlendVis NNS_G3dFuncBlendVisDefault = NNSi_G3dAnmBlendVis;
NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBmaDefault = NNSi_G3dAnmCalcNsBma;
NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBtpDefault = NNSi_G3dAnmCalcNsBtp;
NNSG3dFuncAnmMat NNS_G3dFuncAnmMatNsBtaDefault = NNSi_G3dAnmCalcNsBta;
NNSG3dFuncAnmJnt NNS_G3dFuncAnmJntNsBcaDefault = NNSi_G3dAnmCalcNsBca;
NNSG3dFuncAnmVis NNS_G3dFuncAnmVisNsBvaDefault = NNSi_G3dAnmCalcNsBva;
u32 NNS_G3dAnmFmtNum = NNS_G3D_ANMFMT_BUILTIN;
NNSG3dAnmObjInitFunc NNS_G3dAnmObjInitFuncArray[NNS_G3D_ANMFMT_MAX] = {
    { 'M', 0, 'MA', NNSi_G3dAnmObjInitNsBma }, // material colour (nsbma)
    { 'M', 0, 'TP', NNSi_G3dAnmObjInitNsBtp }, // texture pattern (nsbtp)
    { 'M', 0, 'TA', NNSi_G3dAnmObjInitNsBta }, // texture SRT (nsbta)
    { 'V', 0, 'VA', NNSi_G3dAnmObjInitNsBva }, // visibility (nsbva)
    { 'J', 0, 'CA', NNSi_G3dAnmObjInitNsBca }, // joint (nsbca)
};
