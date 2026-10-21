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

extern s32 func_02040498(s32 max);

static inline void *Effect_ResDataByIdx(EffectResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->numEntry) {
        u16 *e = (u16 *)((u8 *)dict + dict->ofsEntry);
        return (u8 *)e + 4 + e[0] * idx;
    }
    return NULL;
}

static inline u32 *Effect_GetTexData(EffectResTex *tex, u32 idx) {
    if (tex != NULL) {
        return (u32 *)Effect_ResDataByIdx(&tex->dict, idx);
    }
    return NULL;
}

static inline u16 *Effect_GetPlttData(EffectResTex *tex, u32 idx) {
    if (tex != NULL && tex->plttOfsDict != 0) {
        return (u16 *)Effect_ResDataByIdx((EffectResDict *)((u8 *)tex + tex->plttOfsDict), idx);
    }
    return NULL;
}

#define EFFECT_TEXCOORD(s, t) ((u16)(s16)((s) >> 8) | ((u16)(s16)((t) >> 8) << 16))

static inline u32 Effect_GetTexImageParam(EffectResTex *tex, u32 idx) {
    u32 *data = Effect_GetTexData(tex, idx);
    u32 param = data[0];
    u16 key;
    if ((param & 0x1c000000) != 0x14000000) {
        key = tex->texVramKey;
    } else {
        key = tex->tex4x4VramKey;
    }
    return param + key;
}

static inline void EffectPtcl_SetPltt(EffectPtcl *p, s32 idx, u32 param) {
    u16 *pltt = Effect_GetPlttData(p->tex, idx);
    s32 w = 0x1000 << (((param & 0x700000) >> 20) + 3);
    s32 h = 0x1000 << (((param & 0x3800000) >> 23) + 3);
    p->texAddr = ((u16)p->tex->plttVramKey + pltt[0]) << 3;
    p->texIdx = idx;
    p->dl[3] = EFFECT_TEXCOORD(w, 0);
    p->dl[6] = EFFECT_TEXCOORD(0, 0);
    p->dl[9] = EFFECT_TEXCOORD(0, h);
    p->dl[11] = EFFECT_TEXCOORD(w, h);
}

static inline void EffectPtcl_SetTex(EffectPtcl *p, EffectResTex *tex) {
    p->tex = tex;
    if (tex != NULL) {
        u32 param = Effect_GetTexImageParam(tex, 0);
        p->polyAttr = param;
        EffectPtcl_SetPltt(p, p->texIdx, param);
    }
}


typedef struct EffectMtx43 {
    s32 m[4][3];
} EffectMtx43;

extern void MTX_RotX43_(EffectMtx43 *m, s32 s, s32 c);
extern void MTX_RotY43_(EffectMtx43 *m, s32 s, s32 c);
extern void MTX_RotZ43_(EffectMtx43 *m, s32 s, s32 c);
extern void MTX_Concat43(const EffectMtx43 *a, const EffectMtx43 *b, EffectMtx43 *ab);
extern void MTX_MultVec43(const EffectVec *v, const EffectMtx43 *m, EffectVec *out);
extern void MTX_MultVec33(const EffectVec *v, const EffectMtx33 *m, EffectVec *out);
extern void VEC_Normalize(const EffectVec *in, EffectVec *out);

#define EFFECT_DEG_TO_IDX(deg) ((u16)(((s64)(deg) * 0x28be60db9391LL + 0x80000000000LL) >> 44))

static inline s32 Effect_Abs(s32 x) {
    return x < 0 ? -x : x;
}

static inline s32 Effect_RandScale(const s32 &base, s32 range) {
    s32 r = Effect_Abs(func_02040528(range));
    return base - Effect_FxMul(base, r);
}

static inline void EffectPtcl_SetCmds(EffectPtcl *p, EffectPtclCmd *cmds, s32 num) {
    p->cmds = cmds;
    p->numCmds = num;
}

static inline void EffectPtcl_SetCmds2(EffectPtcl *p, EffectPtclCmd *cmds, s32 num) {
    p->numCmds = num;
    p->cmds = cmds;
}

static inline void Effect_VecSet(EffectVec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Effect_MtxRotXZ(EffectMtx43 *m, s32 ax, s32 az) {
    EffectMtx43 tmp;
    BOOL rotated = FALSE;
    MTX_Identity43_(m);
    if (ax != 0) {
        u16 i = EFFECT_DEG_TO_IDX(ax);
        MTX_RotX43_(m, FX_SinCosTable_[(i >> 4) * 2], FX_SinCosTable_[(i >> 4) * 2 + 1]);
        rotated = TRUE;
    }
    if (az != 0) {
        if (rotated) {
            u16 i = EFFECT_DEG_TO_IDX(az);
            MTX_RotZ43_(&tmp, FX_SinCosTable_[(i >> 4) * 2], FX_SinCosTable_[(i >> 4) * 2 + 1]);
            MTX_Concat43(&tmp, m, m);
        } else {
            u16 i = EFFECT_DEG_TO_IDX(az);
            MTX_RotZ43_(m, FX_SinCosTable_[(i >> 4) * 2], FX_SinCosTable_[(i >> 4) * 2 + 1]);
        }
    }
}

static inline void Effect_MtxRotYXZ(EffectMtx43 *m, s32 range) {
    EffectMtx43 tmp;
    u16 ry;
    u16 rx;
    u16 rz;
    BOOL rotated;
    rotated = FALSE;
    rx = func_02040528(range) >> 12;
    ry = func_02040528(range) >> 12;
    rz = func_02040528(range) >> 12;
    MTX_Identity43_(m);
    if (ry != 0) {
        MTX_RotY43_(m, FX_SinCosTable_[(ry >> 4) * 2], FX_SinCosTable_[(ry >> 4) * 2 + 1]);
        rotated = TRUE;
    }
    if (rx != 0) {
        if (rotated) {
            MTX_RotX43_(&tmp, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            MTX_Concat43(&tmp, m, m);
        } else {
            MTX_RotX43_(m, FX_SinCosTable_[(rx >> 4) * 2], FX_SinCosTable_[(rx >> 4) * 2 + 1]);
            rotated = TRUE;
        }
    }
    if (rz != 0) {
        if (rotated) {
            MTX_RotZ43_(&tmp, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
            MTX_Concat43(&tmp, m, m);
        } else {
            MTX_RotZ43_(m, FX_SinCosTable_[(rz >> 4) * 2], FX_SinCosTable_[(rz >> 4) * 2 + 1]);
        }
    }
}

void func_0206bab8(EffectEmitter *em, EffectPtcl *p) {
    u16 rx;
    u16 ry;
    u16 rz;
    s32 f;
    s32 range;

    EffectPtcl_SetTex(p, em->tex);
    p->unk_50 = 0;
    EffectPtcl_SetCmds(p, em->emitData, em->emitCount);
    p->origin = em->pos;
    EffectVec c = {0, 0, 0};
    EffectVec out = {0, 0, 0};
    switch (EFFECT_PARAM(em, 0x8)) {
    case 0: {
        EffectVec v;
        EffectMtx43 m;
        s32 a = func_02040498(0xffff);
        v.x = Effect_FxMul(EFFECT_PARAM(em, 0x30), FX_SinCosTable_[(a >> 4) * 2 + 1]);
        v.y = 0;
        v.z = Effect_FxMul(EFFECT_PARAM(em, 0x30), FX_SinCosTable_[(a >> 4) * 2]);
        f = Effect_RandScale(EFFECT_PARAM(em, 0x30), EFFECT_PARAM(em, 0x40) + 1);
        v.x = Effect_FxMul(v.x, f);
        v.y = Effect_FxMul(v.y, f);
        v.z = Effect_FxMul(v.z, f);
        Effect_MtxRotXZ(&m, EFFECT_PARAM(em, 0x48), EFFECT_PARAM(em, 0x4c));
        MTX_MultVec43(&v, &m, &out);
        break;
    }
    case 1:
        out.x = c.x + func_02040528(0x1000);
        out.y = c.y + func_02040528(0x1000);
        out.z = c.z + func_02040528(0x1000);
        VEC_Normalize(&out, &out);
        f = Effect_RandScale(EFFECT_PARAM(em, 0x30), EFFECT_PARAM(em, 0x40) + 1);
        out.x = Effect_FxMul(out.x, f);
        out.y = Effect_FxMul(out.y, f);
        out.z = Effect_FxMul(out.z, f);
        break;
    }
    p->pos = out;
    EffectVec dir = {0, 0, 0};
    EffectMtx43 m2;
    switch (EFFECT_PARAM(em, 0x4)) {
    case 0:
        dir.x = c.x - out.x;
        dir.y = c.y - out.y;
        dir.z = c.z - out.z;
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            dir.x = func_02040528(0x1000);
            dir.y = func_02040528(0x1000);
            dir.z = func_02040528(0x1000);
        }
        VEC_Normalize(&dir, &dir);
        break;
    case 1:
        dir.x = out.x - c.x;
        dir.y = out.y - c.y;
        dir.z = out.z - c.z;
        if (dir.x == 0 && dir.y == 0 && dir.z == 0) {
            dir.x = func_02040528(0x1000);
            dir.y = func_02040528(0x1000);
            dir.z = func_02040528(0x1000);
        }
        VEC_Normalize(&dir, &dir);
        break;
    case 2:
        VEC_Normalize((EffectVec *)&EFFECT_PARAM(em, 0x20), &dir);
        break;
    case 3:
        dir.x = func_02040528(0x1000);
        dir.y = func_02040528(0x1000);
        dir.z = func_02040528(0x1000);
        VEC_Normalize(&dir, &dir);
        break;
    case 4:
        dir.z = 0;
        dir.y = 0;
        dir.x = 0;
        break;
    }
    range = Effect_FxMul(EFFECT_PARAM(em, 0x38), 0x3fff000);
    Effect_MtxRotYXZ(&m2, range);
    MTX_MultVec43(&dir, &m2, &dir);
    MTX_MultVec33(&dir, (EffectMtx33 *)em->mtx, &dir);
    VEC_Normalize(&dir, &p->dir);
    p->speed = Effect_RandScale(EFFECT_PARAM(em, 0x2c), EFFECT_PARAM(em, 0x3c));
    if (EFFECT_PARAM(em, 0x34) < 0) {
        p->unk_b8 = -1;
    } else {
        p->unk_b8 = Effect_RandScale(EFFECT_PARAM(em, 0x34), EFFECT_PARAM(em, 0x44));
    }
    p->time = 0;
}

}
