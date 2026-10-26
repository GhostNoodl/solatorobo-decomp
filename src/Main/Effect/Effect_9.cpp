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

// Local copies of the NitroSDK/NitroSystem inlines used below (nnsys/g3d.h and nitro/fx.h
// clash with Effect.h). Writing the G3 commands through these, rather than raw
// NNS_G3dGeBufferOP_N calls, gives the target's registers and stack slots.
typedef struct MtxFx33 { s32 m[3][3]; } MtxFx33;
typedef struct VecFx32 { s32 x, y, z; } VecFx32;
extern const s16 FX_SinCosTable_[];
void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);
void NNS_G3dGeSendDL(const void *src, u32 szByte);
void MTX_RotX33_(MtxFx33 *m, s32 s, s32 c);
void MTX_RotY33_(MtxFx33 *m, s32 s, s32 c);
void MTX_RotZ33_(MtxFx33 *m, s32 s, s32 c);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
static inline s16 FX_SinIdx(int idx) { return FX_SinCosTable_[idx * 2]; }
static inline s16 FX_CosIdx(int idx) { return FX_SinCosTable_[idx * 2 + 1]; }
static inline void MTX_Identity33(MtxFx33 *pDst) { MTX_Identity33_(pDst); }
static inline void MTX_RotX33(MtxFx33 *pDst, s32 s, s32 c) { MTX_RotX33_(pDst, s, c); }
static inline void MTX_RotY33(MtxFx33 *pDst, s32 s, s32 c) { MTX_RotY33_(pDst, s, c); }
static inline void MTX_RotZ33(MtxFx33 *pDst, s32 s, s32 c) { MTX_RotZ33_(pDst, s, c); }
static inline void NNS_G3dGeMtxMode(int mode) { NNS_G3dGeBufferOP_N(0x10, (u32 *)&mode, 1); }
static inline void NNS_G3dGePushMtx(void) { NNS_G3dGeBufferOP_N(0x11, NULL, 0); }
static inline void NNS_G3dGePopMtx(int num) { NNS_G3dGeBufferOP_N(0x12, (u32 *)&num, 1); }
static inline void NNS_G3dGeMultMtx33(const MtxFx33 *m) { NNS_G3dGeBufferOP_N(0x1a, (const u32 *)&m->m[0][0], 9); }
static inline void NNS_G3dGeTranslateVec(const VecFx32 *vec) { NNS_G3dGeBufferOP_N(0x1c, (u32 *)vec, 3); }
static inline void NNS_G3dGeScaleVec(const VecFx32 *vec) { NNS_G3dGeBufferOP_N(0x1b, (u32 *)vec, 3); }
static inline void VEC_Set(VecFx32 *a, s32 x, s32 y, s32 z) { a->x = x; a->y = y; a->z = z; }
static inline void NNS_G3dGeColor(u16 rgb) { u32 tmp; tmp = (u32)rgb; NNS_G3dGeBufferOP_N(0x20, (u32 *)&tmp, 1); }
static inline void NNS_G3dGePolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    u32 tmp;
    tmp = (u32)((light) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16));
    NNS_G3dGeBufferOP_N(0x29, &tmp, 1);
}
static inline void NNS_G3dGeTexPlttBase(u32 addr, int texfmt) {
    u32 param = (u32)((addr) >> (4 - ((texfmt) == 2)));
    NNS_G3dGeBufferOP_N(0x2b, &param, 1);
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
        NNS_G3dGeTexPlttBase((u32)p->texAddr, (int)((p->polyAttr & 0x1c000000) >> 26));
    } else {
        // A plain local, not NNS_G3dGeTexImageParam: its stack slot sits above the inlines' temporaries.
        u32 texParam = 0x21200000;
        NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    }
    NNS_G3dGePolygonAttr(0, 0, 3, p->unk_a0, alpha, 0);
    NNS_G3dGeMtxMode(2);
    rotated = FALSE;
    NNS_G3dGePushMtx();
    VEC_Set(&trans, p->pos.x, p->pos.y, p->pos.z);
    NNS_G3dGeTranslateVec(&trans);
    if (type == 1) {
        u16 a = p->rot.z;
        MTX_RotZ33(&rz, FX_SinIdx(a >> 4), FX_CosIdx(a >> 4));
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
            MTX_RotX33(&rot, FX_SinIdx(rx >> 4), FX_CosIdx(rx >> 4));
            rotated = TRUE;
        }
        if (ry != 0) {
            if (rotated) {
                MTX_RotY33(&tmp, FX_SinIdx(ry >> 4), FX_CosIdx(ry >> 4));
                MTX_Concat33(&tmp, &rot, &rot);
            } else {
                MTX_RotY33(&rot, FX_SinIdx(ry >> 4), FX_CosIdx(ry >> 4));
                rotated = TRUE;
            }
        }
        if (rzz != 0) {
            if (rotated) {
                MTX_RotZ33(&tmp, FX_SinIdx(rzz >> 4), FX_CosIdx(rzz >> 4));
                MTX_Concat33(&tmp, &rot, &rot);
            } else {
                MTX_RotZ33(&rot, FX_SinIdx(rzz >> 4), FX_CosIdx(rzz >> 4));
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
