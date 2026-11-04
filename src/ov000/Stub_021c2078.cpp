#include "nnsys/g3d.h"

extern "C" {

void Obj021c2114_JointCallback(NNSG3dRS *rs);

// A render-object init callback (NNS_G3dRenderObjSetInitFunc): hooks Obj021c2114_JointCallback on the
// NNS_G3D_SBC_NODEDESC command.
void Obj021c2114_RSInit(NNSG3dRS *rs) {
    NNS_G3dRSSetCallBack(rs, Obj021c2114_JointCallback, NNS_G3D_SBC_NODEDESC, NNS_G3D_SBC_CALLBACK_TIMING_B);
}

}
