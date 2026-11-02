#include "Main/Effect/Effect.h"

extern "C" {

extern const u8 data_02082ba4[0x38];
extern EffectPtclHandler data_0208c908;
extern EffectPtclHandler data_0208c910;
extern EffectPtclHandler data_0208c918;
extern EffectPtclHandler data_0208c920;
extern EffectPtclHandler data_0208c928;
extern EffectPtclHandler data_0208c930;
extern EffectPtclHandler data_0208c938;
extern EffectPtclHandler data_0208c940;

void func_02068da8(EffectPtcl *p) {
    p->unk_58 = -1;
    MIi_CpuCopyFast(data_02082ba4, p->dl, sizeof(p->dl));
    p->tex = NULL;
    p->polyAttr = 0x21200000;
    p->texAddr = -1;
    p->unk_a0 = 0x3f;
    p->cmds = NULL;
    p->numCmds = 0;
    p->time = 0;
    p->unk_b4 = 0x1000;
    p->unk_b8 = -1;
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
    p->dir.x = 0;
    p->dir.y = 0;
    p->dir.z = 0;
    p->speed = 0;
    p->unk_14 = 0;
    p->unk_16 = 0;
    p->unk_18 = 0;
    p->rot.x = 0;
    p->rot.y = 0;
    p->rot.z = 0;
    p->scale.x = 0x1000;
    p->scale.y = 0x1000;
    p->scale.z = 0x1000;
    p->alpha = 0x1f;
    p->color = 0x7fff;
    p->unk_50 = 0;
    p->texIdx = 0;
    p->next = NULL;
    p->prev = NULL;
}

void func_02068e68(EffectPtcl *p, s32 type, MtxFx33 *mtx, s32 alphaScale) {
    MtxFx33 rz;
    MtxFx33 rot;
    VecFx32 trans;
    MtxFx33 tmp;
    VecFx32 scale;
    BOOL rotated;
    s32 alpha = Effect_FxMul(p->alpha << 12, alphaScale) >> 12;
    if (alpha == 0) {
        return;
    }
    if (p->tex != NULL) {
        NNS_G3dGeBufferOP_N(0x2a, (u32 *)&p->polyAttr, 1);
        NNS_G3dGeTexPlttBase((u32)p->texAddr, (GXTexFmt)((p->polyAttr & 0x1c000000) >> 26));
    } else {
        // A plain local, not NNS_G3dGeTexImageParam: its stack slot sits above the inlines' temporaries.
        u32 texParam = 0x21200000;
        NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    }
    NNS_G3dGePolygonAttr(0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, p->unk_a0, alpha, 0);
    NNS_G3dGeMtxMode(GX_MTXMODE_POSITION_VECTOR);
    rotated = FALSE;
    NNS_G3dGePushMtx();
    VEC_Set(&trans, p->pos.x, p->pos.y, p->pos.z);
    NNS_G3dGeTranslateVec(&trans);
    if (type == 1) {
        u16 a = p->rot.z;
        MTX_RotZ33(&rz, FX_SinIdx(a), FX_CosIdx(a));
        MTX_Concat33(&rz, mtx, &rz);
        NNS_G3dGeMultMtx33(&rz);
    } else if (type == 4) {
        NNS_G3dGeMultMtx33(mtx);
    } else {
        u16 rzz = p->rot.z;
        u16 ry = p->rot.y;
        u16 rx = p->rot.x;
        MTX_Identity33(&rot);
        if (rx != 0) {
            MTX_RotX33(&rot, FX_SinIdx(rx), FX_CosIdx(rx));
            rotated = TRUE;
        }
        if (ry != 0) {
            if (rotated) {
                MTX_RotY33(&tmp, FX_SinIdx(ry), FX_CosIdx(ry));
                MTX_Concat33(&tmp, &rot, &rot);
            } else {
                MTX_RotY33(&rot, FX_SinIdx(ry), FX_CosIdx(ry));
                rotated = TRUE;
            }
        }
        if (rzz != 0) {
            if (rotated) {
                MTX_RotZ33(&tmp, FX_SinIdx(rzz), FX_CosIdx(rzz));
                MTX_Concat33(&tmp, &rot, &rot);
            } else {
                MTX_RotZ33(&rot, FX_SinIdx(rzz), FX_CosIdx(rzz));
            }
        }
        NNS_G3dGeMultMtx33(&rot);
    }
    VEC_Set(&scale, p->scale.x, p->scale.y, p->scale.z);
    NNS_G3dGeScaleVec(&scale);
    NNS_G3dGeColor(p->color);
    NNS_G3dGeSendDL(p->dl, sizeof(p->dl));
    NNS_G3dGePopMtx(1);
}

}
