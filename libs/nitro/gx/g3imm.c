#include "nitro/gx.h"
#include "nitro/mi.h"

void GX_SendFifo48B(register const void *pSrc, register void *pDest);

static inline void GX_SendFifo36B(register const void *pSrc, register void *pDest) {
    MI_Copy36B(pSrc, pDest);
}

void G3_LoadMtx43(const MtxFx43 *m) {
    reg_G3X_GXFIFO = G3OP_MTX_LOAD_4x3;
    GX_SendFifo48B(&m->_00, (void *)&reg_G3X_GXFIFO);
}

void G3_MultMtx43(const MtxFx43 *m) {
    reg_G3X_GXFIFO = G3OP_MTX_MULT_4x3;
    GX_SendFifo48B(&m->_00, (void *)&reg_G3X_GXFIFO);
}

void G3_MultMtx33(const MtxFx33 *m) {
    reg_G3X_GXFIFO = G3OP_MTX_MULT_3x3;
    GX_SendFifo36B(&m->_00, (void *)&reg_G3X_GXFIFO);
}
