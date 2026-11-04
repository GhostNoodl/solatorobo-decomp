#include "nnsys/g3d.h"

extern "C" {

void ActorMarker_MatCallback0b(NNSG3dRS *rs);

// A render-object init callback (NNS_G3dRenderObjSetInitFunc): hooks ActorMarker_MatCallback0b on the
// NNS_G3D_SBC_MAT command.
void ActorMarker_RSInit0b(NNSG3dRS *rs) {
    NNS_G3dRSSetCallBack(rs, ActorMarker_MatCallback0b, NNS_G3D_SBC_MAT, NNS_G3D_SBC_CALLBACK_TIMING_B);
}

}
