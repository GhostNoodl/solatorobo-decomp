#include "nnsys/g3d.h"
#include "ov000/Bss021ccd74.h"
#include "nitro/mi.h"

extern "C" {

// The NODEDESC callback hooked by func_ov000_021c2078: applies the pending rotation and offset
// of data_ov000_021ccd74 to the joint, then unhooks itself.
void func_ov000_021c2090(NNSG3dRS *rs) {
    NNSG3dJntAnmResult *jnt = rs->pJntAnmResult;
    if (data_ov000_021ccd74.unk_08 != NULL) {
        jnt->flag &= ~NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO;
        MI_Copy36B(data_ov000_021ccd74.unk_08, &jnt->rot);
        data_ov000_021ccd74.unk_08 = NULL;
    }
    if (data_ov000_021ccd74.unk_10 != NULL) {
        jnt->flag &= ~NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO;
        VEC_Add(&jnt->trans, data_ov000_021ccd74.unk_10, &jnt->trans);
        data_ov000_021ccd74.unk_10 = NULL;
    }
    NNS_G3dRSResetCallBack(rs, NNS_G3D_SBC_NODEDESC);
}

}
