#include "nnsys/g3d.h"

extern "C" {

void func_ov000_021bb248(NNSG3dRS *rs);

// A render-object init callback (NNS_G3dRenderObjSetInitFunc): hooks func_ov000_021bb248 on the
// NNS_G3D_SBC_MAT command.
void func_ov000_021bb298(NNSG3dRS *rs) {
    NNS_G3dRSSetCallBack(rs, func_ov000_021bb248, NNS_G3D_SBC_MAT, NNS_G3D_SBC_CALLBACK_TIMING_B);
}

}
