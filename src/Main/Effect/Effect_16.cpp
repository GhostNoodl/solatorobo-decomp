#include "Main/Effect/Effect.h"

extern "C" {

BOOL func_0206b804(EffectEmitter *em) {
    s32 t = em->time;
    if (t < 0) {
        t = 0;
    }
    em->emitTime = t;
    return TRUE;
}

typedef struct EffectMtx33 {
    s32 m[3][3];
} EffectMtx33;

extern const s16 FX_SinCosTable_[];
extern u32 data_0208c840[];
extern s32 func_02040528(s32 range);
extern void func_02068da8(EffectPtcl *p);
extern void func_0206bab8(EffectEmitter *em, EffectPtcl *p);
extern void MTX_RotX33_(EffectMtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(EffectMtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(EffectMtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(const EffectMtx33 *a, const EffectMtx33 *b, EffectMtx33 *ab);

#define EFFECT_PARAM(em, off) (*(s32 *)((u8 *)&(em)->params + (off)))

static inline BOOL Effect_EmitDue(EffectEmitter *em, s32 t) {
    if (t == -1 && em->time == 0) {
        return TRUE;
    }
    if (em->prevTime < t << 12 && t << 12 <= em->time) {
        return TRUE;
    }
    return FALSE;
}

EffectPtcl *func_0206b81c(EffectEmitter *em) {
    EffectMtx33 tmp;
    s32 n;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL rotated;
    EffectPtcl *head;
    s32 i;
    EffectPtcl *p;
    if (em->loopCount != -2 && em->time > em->params.duration) {
        return NULL;
    }
    if (em->time < 0) {
        return NULL;
    }
    n = 0;
    switch (EFFECT_PARAM(em, 0xc)) {
    case 0: {
        s32 d = em->time - em->emitTime;
        s32 rate = FX_Div(em->params.duration, EFFECT_PARAM(em, 0x14));
        n = FX_Div(d, rate) >> 12;
        em->emitTime += rate * n;
        break;
    }
    case 1:
        if (Effect_EmitDue(em, em->emitTime >> 12)) {
            n = EFFECT_PARAM(em, 0x14) >> 12;
            em->emitTime += EFFECT_PARAM(em, 0x1c);
        }
        break;
    }
    rotated = FALSE;
    n += (func_02040528(Effect_FxMul(n << 12, EFFECT_PARAM(em, 0x18))) + 0x800) >> 12;
    ry = em->rot.y;
    rz = em->rot.z;
    rx = em->rot.x;
    MTX_Identity33_(em->mtx);
    if (ry != 0) {
        MTX_RotY33_((EffectMtx33 *)em->mtx, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
        rotated = TRUE;
    }
    if (rx != 0) {
        if (rotated) {
            MTX_RotX33_(&tmp, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            MTX_Concat33(&tmp, (EffectMtx33 *)em->mtx, (EffectMtx33 *)em->mtx);
        } else {
            MTX_RotX33_((EffectMtx33 *)em->mtx, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            rotated = TRUE;
        }
    }
    if (rz != 0) {
        if (rotated) {
            MTX_RotZ33_(&tmp, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
            MTX_Concat33(&tmp, (EffectMtx33 *)em->mtx, (EffectMtx33 *)em->mtx);
        } else {
            MTX_RotZ33_((EffectMtx33 *)em->mtx, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
        }
    }
    head = NULL;
    for (i = 0; i < n; i++) {
        p = (EffectPtcl *)func_0203dd9c(0xc4);
        if (p != NULL) {
            *(u32 **)p = data_0208c840;
            func_02068da8(p);
        }
        func_0206bab8(em, p);
        if (head != NULL) {
            p->prev = NULL;
            p->next = head;
            head->prev = p;
        }
        head = p;
    }
    return head;
}

}
