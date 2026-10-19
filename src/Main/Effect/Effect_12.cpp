#include "Main/Effect/Effect.h"

extern "C" {

extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern EffectPartHandler data_0208c948;
extern EffectPartHandler data_0208c950;
extern EffectPartHandler data_0208c958;
extern EffectPartHandler data_0208c960;
extern EffectPartHandler data_0208c968;
extern EffectPartHandler data_0208c970;
extern EffectPartHandler data_0208c978;

extern void VEC_MultAdd(s32 scale, const EffectVec *dir, const EffectVec *base, EffectVec *out);
extern s32 VEC_Mag(const EffectVec *v);
extern void VEC_Normalize(const EffectVec *v, EffectVec *out);

static inline void Effect_VecSub(const EffectVec *a, const EffectVec *b, EffectVec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

static inline void Effect_VecSet(EffectVec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

extern s32 func_020404e0(void);

static inline u16 Effect_Rgb(s32 r, s32 g, s32 b) {
    return (r >> 12) | ((g >> 12) << 5) | ((b >> 12) << 10);
}

static inline s32 Effect_Vary(const s32 *v, s32 s) {
    s32 r = func_020404e0();
    s32 x = *v;
    return x - Effect_FxMul(x, Effect_FxMul(r, s));
}

BOOL func_02069f3c(EffectEmitterSub *sub, EffectPtcl *p, const EffectPtclCmd *cmd) {
    u16 color;
    switch (cmd->mode) {
    case 0:
        color = Effect_Rgb(cmd->a.x, cmd->a.y, cmd->a.z);
        break;
    case 2: {
        EffectVec out;
        EffectVec diff;
        s32 t = FX_Div(p->time - cmd->start, cmd->len);
        Effect_VecSub(&cmd->b, &cmd->a, &diff);
        VEC_MultAdd(t, &diff, &cmd->a, &out);
        color = Effect_Rgb(out.x, out.y, out.z);
        break;
    }
    case 3: {
        s32 s = cmd->b.x;
        color = Effect_Rgb(Effect_Vary(&cmd->a.x, s), Effect_Vary(&cmd->a.y, s), Effect_Vary(&cmd->a.z, s));
        break;
    }
    case 4: {
        s32 s = cmd->b.x;
        color = Effect_Rgb(Effect_Vary(&cmd->a.x, s), Effect_Vary(&cmd->a.y, s), Effect_Vary(&cmd->a.z, s));
        break;
    }
    }
    p->color = color;
    return TRUE;
}

void func_0206a0cc(EffectPartSet *s) {
    s->ptcls = NULL;
}

void func_0206a0d8(EffectPartSet *s) {
}

BOOL func_0206a0dc(EffectPartSet *s, const u8 *data) {
    BOOL ret = FALSE;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (!s->slots[i].used) {
            MIi_CpuCopy32(data, &s->slots[i], 0x30);
            ret = TRUE;
            s->slots[i].used = ret;
            break;
        }
    }
    return ret;
}

void func_0206a138(EffectPartSet *s) {
    MI_CpuFill8(s->slots, 0, sizeof(s->slots));
    s->localTime = 0;
    s->period = 0;
    s->duration = 0;
    s->pos.x = 0;
    s->pos.y = 0;
    s->pos.z = 0;
    s->funcs[0] = data_0208c948;
    s->funcs[1] = data_0208c950;
    s->funcs[2] = data_0208c958;
    s->funcs[3] = data_0208c960;
    s->funcs[4] = data_0208c968;
    s->funcs[5] = data_0208c970;
    s->funcs[6] = data_0208c978;
}

BOOL func_0206a218(EffectPartSet *s) {
    BOOL ret = TRUE;
    s32 i;
    EffectPartSlot *slot;
    if (s->duration > 0 && s->time > s->duration) {
        return FALSE;
    }
    s->localTime = s->period > 0 ? s->time % s->period : s->time;
    for (i = 0; i < 4 && s->slots[i].used; i++) {
        slot = &s->slots[i];
        if (s->localTime < slot->start) {
            ret = TRUE;
        } else if (s->localTime <= slot->start + slot->len) {
            ret = (s->*(s->funcs[slot->type]))(slot);
        }
    }
    return ret;
}

static inline void Effect_VecScale(const EffectVec *v, s32 s, EffectVec *out) {
    out->x = Effect_FxMul(v->x, s);
    out->y = Effect_FxMul(v->y, s);
    out->z = Effect_FxMul(v->z, s);
}

static inline void EffectPtcl_Accel(EffectPtcl *p, s32 rate, const EffectVec *acc) {
    EffectVec v;
    Effect_VecScale(&p->dir, p->speed, &v);
    VEC_MultAdd(rate, acc, &v, &v);
    p->speed = VEC_Mag(&v);
    VEC_Normalize(&v, &p->dir);
}

BOOL func_0206a2ec(EffectPartSet *s, EffectPartSlot *slot) {
    EffectPtcl *p;
    for (p = s->ptcls; p != NULL; p = p->next) {
        EffectPtcl_Accel(p, slot->rate, &slot->vec);
    }
    return TRUE;
}

extern void VEC_Add(const EffectVec *a, const EffectVec *b, EffectVec *out);

BOOL func_0206a3a4(EffectPartSet *s, const EffectPartSlot *slot) {
    EffectVec center;
    EffectVec pos;
    EffectVec rel;
    EffectPtcl *p;
    s32 mag;
    s32 spd;
    if (slot->unk_10 == 0) {
        VEC_Add(&slot->vec2, &s->pos, &center);
    } else if (slot->unk_10 == 1) {
        center = slot->vec2;
    } else {
        Effect_VecSet(&center, 0, 0, 0);
    }
    for (p = s->ptcls; p != NULL; p = p->next) {
        VEC_Add(&p->origin, &p->pos, &pos);
        Effect_VecSub(&pos, &center, &rel);
        mag = VEC_Mag(&rel);
        VEC_Normalize(&rel, &rel);
        spd = p->speed;
        if (mag < (spd < 0 ? -spd : spd) + 0x800) {
            p->unk_b8 = 0;
        } else {
            EffectPtcl_Accel(p, slot->rate, &rel);
        }
    }
    return TRUE;
}

BOOL func_0206a530(EffectPartSet *s, const EffectPartSlot *slot) {
    EffectVec center;
    EffectVec axis;
    EffectVec pos;
    EffectVec rel;
    EffectVec v;
    EffectPtcl *p;
    s32 d;
    s32 mag;
    s32 spd;
    if (slot->unk_10 == 0) {
        VEC_Add(&slot->vec2, &s->pos, &center);
    } else if (slot->unk_10 == 1) {
        center = slot->vec2;
    } else {
        Effect_VecSet(&center, 0, 0, 0);
    }
    axis = slot->vec;
    VEC_Normalize(&axis, &axis);
    for (p = s->ptcls; p != NULL; p = p->next) {
        VEC_Add(&p->origin, &p->pos, &pos);
        Effect_VecSub(&pos, &center, &rel);
        d = (s32)(((s64)rel.x * axis.x + (s64)rel.y * axis.y + (s64)rel.z * axis.z + 0x800) >> 12);
        VEC_MultAdd(-d, &axis, &rel, &v);
        mag = VEC_Mag(&v);
        VEC_Normalize(&v, &v);
        spd = p->speed;
        if (mag < (spd < 0 ? -spd : spd) + 0x800) {
            p->unk_b8 = 0;
        } else {
            EffectPtcl_Accel(p, slot->rate, &v);
        }
    }
    return TRUE;
}

BOOL func_0206a71c(EffectPartSet *s, const EffectPartSlot *slot) {
    EffectVec center;
    EffectVec rel;
    EffectVec pos;
    EffectVec w;
    s32 rate;
    EffectPtcl *p;
    s32 mag;
    s32 spd;
    s32 k;
    if (slot->unk_10 == 0) {
        VEC_Add(&slot->vec2, &s->pos, &center);
    } else if (slot->unk_10 == 1) {
        center = slot->vec2;
    } else {
        Effect_VecSet(&center, 0, 0, 0);
    }
    rate = slot->rate;
    for (p = s->ptcls; p != NULL; p = p->next) {
        VEC_Add(&p->origin, &p->pos, &pos);
        Effect_VecSub(&pos, &center, &rel);
        mag = VEC_Mag(&rel);
        VEC_Normalize(&rel, &rel);
        spd = p->speed;
        k = FX_Div(0x1000, mag) - FX_Div(0x1000, rate);
        Effect_VecScale(&p->dir, p->speed, &w);
        VEC_MultAdd(Effect_FxMul(Effect_FxMul(spd, spd), k), &rel, &w, &w);
        VEC_Normalize(&w, &w);
        VEC_Normalize(&w, &p->dir);
    }
    return TRUE;
}

BOOL func_0206a8d4(EffectPartSet *s, const EffectPartSlot *slot) {
    EffectVec axis;
    EffectVec center;
    EffectVec pos;
    EffectVec rel;
    EffectVec v;
    EffectVec w;
    s32 rate;
    EffectPtcl *p;
    s32 mag;
    s32 spd;
    s32 k;
    s32 d;
    if (slot->unk_10 == 0) {
        VEC_Add(&slot->vec2, &s->pos, &center);
    } else if (slot->unk_10 == 1) {
        center = slot->vec2;
    } else {
        Effect_VecSet(&center, 0, 0, 0);
    }
    VEC_Normalize(&slot->vec, &axis);
    rate = slot->rate;
    for (p = s->ptcls; p != NULL; p = p->next) {
        VEC_Add(&p->origin, &p->pos, &pos);
        Effect_VecSub(&pos, &center, &rel);
        d = (s32)(((s64)rel.x * axis.x + (s64)rel.y * axis.y + (s64)rel.z * axis.z + 0x800) >> 12);
        VEC_MultAdd(-d, &axis, &rel, &v);
        mag = VEC_Mag(&v);
        VEC_Normalize(&v, &v);
        spd = p->speed;
        k = FX_Div(0x1000, mag) - FX_Div(0x1000, rate);
        Effect_VecScale(&p->dir, p->speed, &w);
        VEC_MultAdd(Effect_FxMul(Effect_FxMul(spd, spd), k), &v, &w, &w);
        VEC_Normalize(&w, &w);
        VEC_Normalize(&w, &p->dir);
    }
    return TRUE;
}

}
