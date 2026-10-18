#include <nnsys/g3d.h>


void NNS_G3dGetCurrentMtx(MtxFx43 *m, MtxFx33 *n) {
    NNS_G3dGeFlushBuffer();

    G3_MtxMode(GX_MTXMODE_PROJECTION);
    G3_PushMtx();
    G3_Identity();

    if (m) {
        MtxFx44 tmp;
        while (G3X_GetClipMtx(&tmp))
            ;
        MTX_Copy44To43(&tmp, m);
    }

    if (n) {
        while (G3X_GetVectorMtx(n))
            ;
    }

    G3_PopMtx(1);
    G3_MtxMode(GX_MTXMODE_POSITION_VECTOR);
}

void NNS_G3dInit(void) {
    G3X_Init();

    NNS_G3dGlbInit();

    G3X_SetFifoIntrCond(GX_FIFOINTR_COND_EMPTY);
}
