#include "ov010/ov010.h"
#include "nnsys/g3d.h"

struct Ov010Beam {
    u8 on;
    u8 unk_01[0xd];
    s16 len;
    u16 rx;
    u16 ry;
    s32 alpha;
    u8 unk_18[4];
    VecFx32 pos;
};

extern "C" {

extern u8 *data_02097d48;
u32 func_02043d48(void *p);

void func_ov010_02200a00(Ov010Beam *self) {
    MtxFx33 m;
    VecFx32 v;
    MtxFx33 rx;
    MtxFx33 ry;
    VecFx32 s;
    u32 alpha;
    if (self->on == 0) {
        return;
    }
    alpha = (self->alpha >> 12) & 0xff;
    if (alpha == 0) {
        return;
    }
    MTX_Identity33(&m);
    NNS_G3dGlbSetBaseRot(&m);
    VEC_Set(&v, 0, 0, 0);
    NNS_G3dGlbSetBaseTrans(&v);
    VEC_Set(&v, FX32_ONE, FX32_ONE, FX32_ONE);
    NNS_G3dGlbSetBaseScale(&v);
    NNS_G3dGlbFlushVP();
    NNS_G3dGeMtxMode(GX_MTXMODE_POSITION_VECTOR);
    NNS_G3dGePushMtx();
    NNS_G3dGeIdentity();
    NNS_G3dGeTranslateVec(&self->pos);
    MTX_RotX33(&rx, FX_SinIdx(self->rx), FX_CosIdx(self->rx));
    MTX_RotY33(&ry, FX_SinIdx(self->ry), FX_CosIdx(self->ry));
    NNS_G3dGeMultMtx33(&ry);
    NNS_G3dGeMultMtx33(&rx);
    VEC_Set(&s, FX32_ONE, FX32_ONE, FX_Mul(self->len, 0xf000));
    NNS_G3dGeScaleVec(&s);
    NNS_G3dGePolygonAttr(0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, func_02043d48(data_02097d48 + 0x8b0), alpha, 0);
    NNS_G3dGeTexImageParam(GX_TEXFMT_NONE, GX_TEXGEN_NONE, GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_TRNS, 0);
    NNS_G3dGeBegin(GX_BEGIN_TRIANGLES);
    NNS_G3dGeColor(GX_RGB(31, 0, 0));
    NNS_G3dGeVtx(0, 0, 0);
    NNS_G3dGeVtxXY(0, 0);
    NNS_G3dGeVtx(0, 0, FX16_ONE);
    NNS_G3dGeEnd();
    NNS_G3dGePopMtx(1);
    NNS_G3dGeFlushBuffer();
}

}
