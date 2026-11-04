#include "nnsys/g3d.h"

extern "C" {

void Obj021bb2b0_MatCallback(NNSG3dRS *rs);

// A render-object init callback (NNS_G3dRenderObjSetInitFunc): hooks Obj021bb2b0_MatCallback on the
// NNS_G3D_SBC_MAT command.
void Obj021bb2b0_RSInit(NNSG3dRS *rs) {
    NNS_G3dRSSetCallBack(rs, Obj021bb2b0_MatCallback, NNS_G3D_SBC_MAT, NNS_G3D_SBC_CALLBACK_TIMING_B);
}

}
