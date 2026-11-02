#include "types.h"
#include "nitro/fx.h"
#include "ov003/Blink.h"
#include "ov003/Prop.h"

extern "C" {

extern void *data_ov003_021f738c[];
extern Ov003BlinkTarget *ActorMgr_FindPlayer(void);
extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern char data_ov003_021fa2d2[];

extern BOOL Model0218fe1c_SetAnim(void *model, const void *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(void *model);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 v);
extern s32 Rand_PlusMinus(s32 max);
extern Ov003BlinkInfo *Tbl_FindEntry_0206fef8(u16 id);
extern BOOL Model021903b4_Draw(void *model);

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

void Ov003PropBlink_Apply(Ov003PropBlink *self);

void Ov003ActVt_021fa440_Start(Ov003PropBlink *self) {
    Ov000ActVt_021cc7cc_Start(self);
    self->phase = 0;
    if (!(self->unk_18 & 0xff00)) {
        self->phase = 2;
    }
    Ov003PropBlink_Apply(self);
    self->model->boxTest = 0;
    self->radius = self->unk_1e << 4;
}

void Ov003ActVt_021fa440_RunState(Ov003PropBlink *self) {
    Ov003BlinkTarget *t = ActorMgr_FindPlayer();
    switch (self->phase) {
    case 0:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (Ov003_DistXZ(&self->pos, &t->pos) < self->radius) {
            self->phase++;
            Ov003PropBlink_Apply(self);
        }
        break;
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (self->unk_18 & 0xff) {
            self->phase++;
            Ov003PropBlink_Apply(self);
        } else {
            self->model->visible = 0;
            self->phase = 10;
        }
        break;
    case 2:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (Ov003_DistXZ(&self->pos, &t->pos) > self->radius) {
            self->phase++;
            Ov003PropBlink_Apply(self);
        }
        break;
    case 3:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (self->unk_18 & 0xff00) {
            self->phase = 0;
            Ov003PropBlink_Apply(self);
        } else {
            self->model->visible = 0;
            self->phase = 10;
        }
        break;
    }
}

} // extern "C"
