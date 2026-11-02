#include "nnsys/g3d.h"

extern "C" {

void func_ov000_0216bec8(NNSG3dRS *rs);

// Init callback of the effect made in func_ov000_0216c018: installs func_ov000_0216bec8 as the
// material callback (timing B).
void func_ov000_0216bf18(NNSG3dRS *rs) {
    rs->cbVecFunc[NNS_G3D_SBC_MAT] = func_ov000_0216bec8;
    rs->cbVecTiming[NNS_G3D_SBC_MAT] = NNS_G3D_SBC_CALLBACK_TIMING_B;
}

}
