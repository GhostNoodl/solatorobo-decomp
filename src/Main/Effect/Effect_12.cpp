#include "Main/Effect/Effect.h"

extern "C" {

extern void func_02016e28(void *dst, u32 value, u32 size);
extern void func_02016cec(const void *src, void *dst, u32 size);
extern EffectPartHandler data_0208c948;
extern EffectPartHandler data_0208c950;
extern EffectPartHandler data_0208c958;
extern EffectPartHandler data_0208c960;
extern EffectPartHandler data_0208c968;
extern EffectPartHandler data_0208c970;
extern EffectPartHandler data_0208c978;

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
            func_02016cec(data, &s->slots[i], 0x30);
            ret = TRUE;
            s->slots[i].used = ret;
            break;
        }
    }
    return ret;
}

void func_0206a138(EffectPartSet *s) {
    func_02016e28(s->slots, 0, sizeof(s->slots));
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

extern void func_02012fb8(s32 scale, const EffectVec *dir, const EffectVec *base, EffectVec *out);
extern s32 func_02012d18(const EffectVec *v);
extern void func_02012d78(const EffectVec *v, EffectVec *out);

static inline void Effect_VecScale(const EffectVec *v, s32 s, EffectVec *out) {
    out->x = Effect_FxMul(v->x, s);
    out->y = Effect_FxMul(v->y, s);
    out->z = Effect_FxMul(v->z, s);
}

static inline void EffectPtcl_Accel(EffectPtcl *p, s32 rate, const EffectVec *acc) {
    EffectVec v;
    Effect_VecScale(&p->dir, p->speed, &v);
    func_02012fb8(rate, acc, &v, &v);
    p->speed = func_02012d18(&v);
    func_02012d78(&v, &p->dir);
}

BOOL func_0206a2ec(EffectPartSet *s, EffectPartSlot *slot) {
    EffectPtcl *p;
    for (p = s->ptcls; p != NULL; p = p->next) {
        EffectPtcl_Accel(p, slot->rate, &slot->vec);
    }
    return TRUE;
}

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


}
