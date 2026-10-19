#include "Main/Effect/Effect.h"

extern "C" {

extern int FX_Div(int a, int b);

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

static inline void *Effect_ResDataByIdx(EffectResDict *dict, u32 idx) {
    if (dict != NULL && idx < dict->numEntry) {
        u16 *e = (u16 *)((u8 *)dict + dict->ofsEntry);
        return (u8 *)e + 4 + e[0] * idx;
    }
    return NULL;
}

static inline u16 *Effect_GetPlttData(EffectResTex *tex, u32 idx) {
    if (tex != NULL && tex->plttOfsDict != 0) {
        return (u16 *)Effect_ResDataByIdx((EffectResDict *)((u8 *)tex + tex->plttOfsDict), idx);
    }
    return NULL;
}

static inline void EffectPtcl_SetPlttIdx(EffectPtcl *p, s32 idx) {
    u16 *pltt = Effect_GetPlttData(p->tex, idx);
    p->texAddr = (pltt[0] + (u16)p->tex->plttVramKey) << 3;
    p->texIdx = idx;
}

BOOL func_02069e04(EffectEmitterSub *sub, EffectPtcl *p, EffectPtclCmd *cmd) {
    if (cmd->mode == 2) {
        s32 to = cmd->b.x;
        s32 from = cmd->a.x;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        EffectPtcl_SetPlttIdx(p, from + (FX_Mul((to - from) << 12, t) >> 12));
    } else {
        EffectPtcl_SetPlttIdx(p, *(s8 *)&cmd->a.x);
    }
    return TRUE;
}

}
