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

extern int FX_Div(int a, int b);
extern int func_02040528(int range);

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

BOOL func_02069300(EffectEmitterSub *sub, EffectPtcl *p, const EffectPtclCmd *cmd) {
    switch (cmd->mode) {
    case 0:
        p->pos = cmd->a;
        break;
    case 1:
        VEC_Add(&cmd->a, &p->pos, &p->pos);
        break;
    case 2: {
        EffectVec out;
        EffectVec diff;
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
        s32 z = func_02040528(FX_Mul(cmd->a.z, s));
        s32 y = func_02040528(FX_Mul(cmd->a.y, s));
        s32 x = func_02040528(FX_Mul(cmd->a.x, s));
        p->pos.x = x;
        p->pos.y = y;
        p->pos.z = z;
        break;
    }
    case 4: {
        s32 r = func_02040528(cmd->b.x);
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

extern s32 func_020404e0(void);

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
        EffectVec from;
        EffectVec out;
        EffectVec diff;
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
        EffectVec f;
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
        rz = func_020404e0();
        ry = func_020404e0();
        rx = func_020404e0();
        p->rot.x = ((x << 12) - FX_Mul(f.x, FX_Mul(rx, s))) >> 12;
        p->rot.y = ((y << 12) - FX_Mul(f.y, FX_Mul(ry, s))) >> 12;
        p->rot.z = ((z << 12) - FX_Mul(f.z, FX_Mul(rz, s))) >> 12;
        break;
    }
    case 4: {
        EffectVec f;
        s32 s;
        s32 r;
        x = cmd->a.x;
        y = cmd->a.y;
        z = cmd->a.z;
        f.x = x << 12;
        f.y = y << 12;
        f.z = z << 12;
        s = cmd->b.x;
        r = FX_Mul(func_020404e0(), s);
        p->rot.x = ((x << 12) - FX_Mul(f.x, r)) >> 12;
        p->rot.y = ((y << 12) - FX_Mul(f.y, r)) >> 12;
        p->rot.z = ((z << 12) - FX_Mul(f.z, r)) >> 12;
        break;
    }
    case 5:
        if (cmd->start == p->time) {
            EffectVec f;
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
            rz = func_020404e0();
            ry = func_020404e0();
            rx = func_020404e0();
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
        EffectVec out;
        EffectVec diff;
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
        s32 rz = func_020404e0();
        s32 az = cmd->a.z;
        s32 ry = func_020404e0();
        s32 ay = cmd->a.y;
        s32 rx = func_020404e0();
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
        r = FX_Mul(func_020404e0(), s);
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
        v = ((a << 12) - FX_Mul(a << 12, FX_Mul(func_020404e0(), b))) >> 12;
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

}
