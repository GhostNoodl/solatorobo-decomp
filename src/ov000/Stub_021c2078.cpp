#include "nnsys/g3d.h"

extern "C" {

void func_ov000_021c2090(NNSG3dRS *rs);

// A render-object init callback (NNS_G3dRenderObjSetInitFunc): hooks func_ov000_021c2090 on the
// NNS_G3D_SBC_NODEDESC command.
void func_ov000_021c2078(NNSG3dRS *rs) {
    NNS_G3dRSSetCallBack(rs, func_ov000_021c2090, NNS_G3D_SBC_NODEDESC, NNS_G3D_SBC_CALLBACK_TIMING_B);
}

}
