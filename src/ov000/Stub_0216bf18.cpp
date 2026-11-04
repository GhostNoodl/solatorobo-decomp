#include "nnsys/g3d.h"

extern "C" {

void LoTicker_MatCallback(NNSG3dRS *rs);

// Init callback of the effect made in LoTicker_AddPending: installs LoTicker_MatCallback as the
// material callback (timing B).
void LoTicker_RSInit(NNSG3dRS *rs) {
    rs->cbVecFunc[NNS_G3D_SBC_MAT] = LoTicker_MatCallback;
    rs->cbVecTiming[NNS_G3D_SBC_MAT] = NNS_G3D_SBC_CALLBACK_TIMING_B;
}

}
