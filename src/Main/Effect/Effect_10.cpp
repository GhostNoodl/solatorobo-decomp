#include "Main/Effect/EffectInt.h"

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

void func_02069184(EffectEmitterSub *sub) {
    sub->funcs[0] = data_0208c908;
    sub->funcs[1] = data_0208c910;
    sub->funcs[2] = data_0208c918;
    sub->funcs[3] = data_0208c920;
    sub->funcs[4] = data_0208c928;
    sub->funcs[5] = data_0208c930;
    sub->funcs[6] = data_0208c938;
    sub->funcs[7] = data_0208c940;
}

void func_02069248(EffectEmitterSub *sub) {
}

BOOL func_0206924c(EffectEmitterSub *sub, EffectPtcl *p) {
    BOOL done = FALSE;
    EffectPtclCmd *cmds = p->cmds;
    s32 i;
    s32 n = p->numCmds;
    s32 t = p->time;
    BOOL ok = TRUE;
    EffectPtclCmd *cmd;
    for (i = 0; i < n; i++) {
        cmd = &cmds[i];
        if (t < cmd->start) {
            done = FALSE;
            break;
        }
        if (t >= cmd->start + cmd->len) {
            done = TRUE;
        } else {
            done = FALSE;
            ok = (sub->*(sub->funcs[cmd->type]))(p, cmd);
        }
    }
    return (ok && !done) ? TRUE : FALSE;
}

extern int Rand_PlusMinus(int range);

BOOL func_02069300(EffectEmitterSub *sub, EffectPtcl *p, const EffectPtclCmd *cmd) {
    switch (cmd->mode) {
    case 0:
        p->pos = cmd->a;
        break;
    case 1:
        VEC_Add(&cmd->a, &p->pos, &p->pos);
        break;
    case 2: {
        VecFx32 out;
        VecFx32 diff;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        diff.x = cmd->b.x - cmd->a.x;
        diff.y = cmd->b.y - cmd->a.y;
        diff.z = cmd->b.z - cmd->a.z;
        VEC_MultAdd(t, &diff, &cmd->a, &out);
        p->pos = out;
        break;
    }
    case 3: {
        s32 s = cmd->b.x;
        s32 z = Rand_PlusMinus(FX_Mul(cmd->a.z, s));
        s32 y = Rand_PlusMinus(FX_Mul(cmd->a.y, s));
        s32 x = Rand_PlusMinus(FX_Mul(cmd->a.x, s));
        p->pos.x = x;
        p->pos.y = y;
        p->pos.z = z;
        break;
    }
    case 4: {
        s32 r = Rand_PlusMinus(cmd->b.x);
        s32 y = FX_Mul(cmd->a.y, r);
        s32 z = FX_Mul(cmd->a.z, r);
        s32 x = FX_Mul(cmd->a.x, r);
        p->pos.x = x;
        p->pos.y = y;
        p->pos.z = z;
        break;
    }
    }
    return TRUE;
}

extern s32 Rand_Fx(void);

BOOL func_020694a4(EffectEmitterSub *sub, EffectPtcl *p, const EffectPtclCmd *cmd) {
    s32 x;
    s32 y;
    s32 z;
    switch (cmd->mode) {
    case 0: {
        x = cmd->a.x;
        y = cmd->a.y;
        z = cmd->a.z;
        p->rot.x = x;
        p->rot.y = y;
        p->rot.z = z;
        break;
    }
    case 1: {
        u16 ux = cmd->a.x;
        u16 uy = cmd->a.y;
        u16 uz = cmd->a.z;
        p->rot.x += ux;
        p->rot.y += uy;
        p->rot.z += uz;
        break;
    }
    case 2: {
        VecFx32 from;
        VecFx32 out;
        VecFx32 diff;
        s32 t;
        s32 bx;
        s32 by;
        s32 bz;
        z = cmd->a.z << 12;
        y = cmd->a.y << 12;
        x = cmd->a.x << 12;
        from.x = x;
        from.y = y;
        from.z = z;
        bz = cmd->b.z;
        by = cmd->b.y;
        bx = cmd->b.x;
        t = FX_Div(p->time - cmd->start, cmd->len);
        diff.x = (bx << 12) - from.x;
        diff.y = (by << 12) - from.y;
        diff.z = (bz << 12) - from.z;
        VEC_MultAdd(t, &diff, &from, &out);
        x = out.x >> 12;
        y = out.y >> 12;
        z = out.z >> 12;
        p->rot.x = x;
        p->rot.y = y;
        p->rot.z = z;
        break;
    }
    case 3: {
        VecFx32 f;
        s32 s;
        s32 rz;
        s32 ry;
        s32 rx;
        x = cmd->a.x;
        y = cmd->a.y;
        z = cmd->a.z;
        f.x = x << 12;
        f.y = y << 12;
        f.z = z << 12;
        s = cmd->b.x;
        rz = Rand_Fx();
        ry = Rand_Fx();
        rx = Rand_Fx();
        p->rot.x = ((x << 12) - FX_Mul(f.x, FX_Mul(rx, s))) >> 12;
        p->rot.y = ((y << 12) - FX_Mul(f.y, FX_Mul(ry, s))) >> 12;
        p->rot.z = ((z << 12) - FX_Mul(f.z, FX_Mul(rz, s))) >> 12;
        break;
    }
    case 4: {
        VecFx32 f;
        s32 s;
        s32 r;
        x = cmd->a.x;
        y = cmd->a.y;
        z = cmd->a.z;
        f.x = x << 12;
        f.y = y << 12;
        f.z = z << 12;
        s = cmd->b.x;
        r = FX_Mul(Rand_Fx(), s);
        p->rot.x = ((x << 12) - FX_Mul(f.x, r)) >> 12;
        p->rot.y = ((y << 12) - FX_Mul(f.y, r)) >> 12;
        p->rot.z = ((z << 12) - FX_Mul(f.z, r)) >> 12;
        break;
    }
    case 5:
        if (cmd->start == p->time) {
            VecFx32 f;
            s32 s;
            s32 rz;
            s32 ry;
            s32 rx;
            x = cmd->a.x;
            y = cmd->a.y;
            z = cmd->a.z;
            f.x = x << 12;
            f.y = y << 12;
            f.z = z << 12;
            s = cmd->b.x;
            rz = Rand_Fx();
            ry = Rand_Fx();
            rx = Rand_Fx();
            p->unk_14 = ((x << 12) - FX_Mul(f.x, FX_Mul(rx, s))) >> 12;
            p->unk_16 = ((y << 12) - FX_Mul(f.y, FX_Mul(ry, s))) >> 12;
            p->unk_18 = ((z << 12) - FX_Mul(f.z, FX_Mul(rz, s))) >> 12;
        }
        break;
    }
    return TRUE;
}

BOOL func_02069824(EffectEmitterSub *sub, EffectPtcl *p, const EffectPtclCmd *cmd) {
    switch (cmd->mode) {
    case 0:
        p->scale = cmd->a;
        break;
    case 1:
        VEC_Add(&cmd->a, &p->scale, &p->scale);
        break;
    case 2: {
        VecFx32 out;
        VecFx32 diff;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        diff.x = cmd->b.x - cmd->a.x;
        diff.y = cmd->b.y - cmd->a.y;
        diff.z = cmd->b.z - cmd->a.z;
        VEC_MultAdd(t, &diff, &cmd->a, &out);
        p->scale = out;
        break;
    }
    case 3: {
        s32 s = cmd->b.x;
        s32 rz = Rand_Fx();
        s32 az = cmd->a.z;
        s32 ry = Rand_Fx();
        s32 ay = cmd->a.y;
        s32 rx = Rand_Fx();
        s32 ax = cmd->a.x;
        p->scale.x = ax - FX_Mul(ax, FX_Mul(rx, s));
        p->scale.y = ay - FX_Mul(ay, FX_Mul(ry, s));
        p->scale.z = az - FX_Mul(az, FX_Mul(rz, s));
        break;
    }
    case 4: {
        s32 r;
        s32 z;
        s32 y;
        s32 x;
        s32 s;
        s = cmd->b.x;
        r = FX_Mul(Rand_Fx(), s);
        z = cmd->a.z - FX_Mul(cmd->a.z, r);
        y = cmd->a.y - FX_Mul(cmd->a.y, r);
        x = cmd->a.x - FX_Mul(cmd->a.x, r);
        p->scale.x = x;
        p->scale.y = y;
        p->scale.z = z;
        break;
    }
    }
    return TRUE;
}

BOOL func_02069a2c(EffectEmitterSub *sub, EffectPtcl *p, EffectPtclCmd *cmd) {
    s32 v;
    switch (cmd->mode) {
    case 0:
        v = *(s8 *)&cmd->a.x;
        if (v <= 0) {
            v = 0;
        }
        p->alpha = v;
        if (v >= 0x1f) {
            v = 0x1f;
        }
        p->alpha = v;
        break;
    case 1:
        v = p->alpha + *(s8 *)&cmd->a.x;
        if (v <= 0) {
            v = 0;
        }
        p->alpha = v;
        if (v > 0x1f) {
            v = 0x1f;
        }
        p->alpha = v;
        break;
    case 2: {
        s32 to = cmd->b.x;
        s32 from = cmd->a.x;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        v = from + (FX_Mul((to - from) << 12, t) >> 12);
        if (v <= 0) {
            v = 0;
        }
        p->alpha = v;
        if (v >= 0x1f) {
            v = 0x1f;
        }
        p->alpha = v;
        break;
    }
    case 3:
    case 4: {
        s32 b = cmd->b.x;
        s32 a = cmd->a.x;
        v = ((a << 12) - FX_Mul(a << 12, FX_Mul(Rand_Fx(), b))) >> 12;
        if (v <= 0) {
            v = 0;
        }
        p->alpha = v;
        if (v >= 0x1f) {
            v = 0x1f;
        }
        p->alpha = v;
        break;
    }
    }
    return TRUE;
}

#ifdef NONMATCHING
// func_02069b3c (0x2c8 bytes, the texture-index particle command): 44 / 4 (raw / register-masked). This file's
// .text ends at 0x02069b3c, so it goes here once it matches. Blocker: the param + key sum of the inlined
// Effect_GetTexImageParam (a codegen temp) is coloured and scheduled differently. The inlines are the matched
// Effect_16.cpp ones. History: docs/MATCHING.md rounds mainfresh1-4, fresh6, mainJ, rgB, cvA; docs/UNMATCHED.md.
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

static inline u32 *Effect_GetTexData(EffectResTex *tex, u32 idx) {
    if (tex != NULL) {
        return (u32 *)Effect_ResDataByIdx(&tex->dict, idx);
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

static inline void EffectPtcl_SetTexImage(EffectPtcl *p, s32 idx) {
    if (p->tex != NULL) {
        u32 param = Effect_GetTexImageParam(p->tex, idx);
        p->polyAttr = param;
        EffectPtcl_SetPltt(p, p->texIdx, param);
    }
}

BOOL func_02069b3c(EffectEmitterSub *sub, EffectPtcl *p, EffectPtclCmd *cmd) {
    s32 idx;
    if (cmd->mode == 2) {
        s32 to = cmd->b.x;
        s32 from = cmd->a.x;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        idx = from + (FX_Mul((to - from) << 12, t) >> 12);
        EffectPtcl_SetTexImage(p, idx);
        p->unk_50 = idx;
    } else {
        s32 i = *(s8 *)&cmd->a.x;
        EffectPtcl_SetTexImage(p, i);
        p->unk_50 = i;
    }
    return TRUE;
}
#endif

}
