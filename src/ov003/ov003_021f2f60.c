#include "types.h"
#include "nitro/fx.h"
#include "ov003/Blink.h"

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *func_ov000_0219bf90(void);
extern BOOL func_ov000_02191120(void *model);
extern char data_ov003_021fa2d2[];

extern void Ov000ActVt_021cc7cc_Start(void *self);
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern s32 Rand_PlusMinus(s32 max);
extern Ov003BlinkInfo *func_0206fef8(u16 id);
extern BOOL func_ov000_0218cea4(void *self);
extern BOOL func_ov000_021903b4(void *model);

static inline void Ov003_SetSqrtImm64(u64 param) {
    *(volatile u64 *)0x040002b8 = param;
}

static inline void Ov003_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    Ov003_SetSqrtImm64(param);
}

static inline void Ov003_WaitSqrt(void) {
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
}

static inline u32 Ov003_GetSqrtResult32(void) {
    return *(volatile u32 *)0x040002b4;
}

static inline s32 Ov003_Dist2D(s64 sq) {
    Ov003_SetSqrt64((u64)(sq << 2));
    Ov003_WaitSqrt();
    return (s32)(Ov003_GetSqrtResult32() + 1) >> 1;
}

static inline s32 Ov003_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov003_Dist2D(sq);
}

void func_ov003_021f3198(Ov003Blink *self);

void Ov003ActVt_021fa440_Start(Ov003Blink *self) {
    Ov000ActVt_021cc7cc_Start(self);
    self->u.blink.phase = 0;
    if (!((s16)self->pattern & 0xff00)) {
        self->u.blink.phase = 2;
    }
    func_ov003_021f3198(self);
    self->model->shadow = 0;
    self->u.blink.radius = self->unk_1e << 4;
}

void func_ov003_021f2fac(Ov003Blink *self) {
    Ov003BlinkTarget *t = func_ov000_0219bf90();
    switch (self->u.blink.phase) {
    case 0:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if (Ov003_DistXZ(&self->pos, &t->pos) < self->u.blink.radius) {
            self->u.blink.phase++;
            func_ov003_021f3198(self);
        }
        break;
    case 1:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if ((s16)self->pattern & 0xff) {
            self->u.blink.phase++;
            func_ov003_021f3198(self);
        } else {
            self->model->visible = 0;
            self->u.blink.phase = 10;
        }
        break;
    case 2:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if (Ov003_DistXZ(&self->pos, &t->pos) > self->u.blink.radius) {
            self->u.blink.phase++;
            func_ov003_021f3198(self);
        }
        break;
    case 3:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if ((s16)self->pattern & 0xff00) {
            self->u.blink.phase = 0;
            func_ov003_021f3198(self);
        } else {
            self->model->visible = 0;
            self->u.blink.phase = 10;
        }
        break;
    }
}
