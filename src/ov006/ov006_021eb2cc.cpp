#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/ov006.h"
#include "Main/Effect/Effect.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
BOOL func_ov000_02190cb0(Model0218fe1c *model, const char *name, s32 blend, s32 force);
void func_ov000_021911c8(Model0218fe1c *model, s16 b);
void func_ov000_021915a0(Model0218fe1c *model);
void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
BOOL func_ov000_0219aae8(Actor *a, Actor *b, u16 c, u8 d, u16 mask, const VecFx32 *ofs, Rot16 *rot,
                         s32 r, s32 rr, s16 h, s32 i);
void func_ov000_0218bed8(void *a, s32 b, Actor *actor);

void Ov006ActVt_021ec714_StateIdle(ActorEx *self) {
    BOOL any;
    int i;
    Rot16 rot;
    EffectObj *p;
    ActorSub40 *state = self->fsm;
    switch (state->st) {
    case 0:
        func_ov000_02190cb0(self->model, "act00", 0x1000, 0);
        self->unk_ce_u = 0;
        self->rot.y += 0x8000;
        self->fsm->st++;
        break;
    case 1:
        state->timer++;
        if (state->timer <= 30) {
            return;
        }
        func_ov000_02190cb0(self->model, "act01", 0x1000, 0);
        func_ov000_021911c8(self->model, 0x2800);
        func_ov000_021915a0(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 2:
        state->timer++;
        if (state->timer > 0xa8c || self->unk_ce_u >= 3) {
            p = func_02065f88(5, &self->pos);
            if (p != NULL) {
                p->SetScaleAll(0x5000);
            }
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_ov000_0219aae8(self, self, 1, 0x11, 0x80, NULL, NULL, 0x7800, 0, -1, 0x1000);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        any = FALSE;
        rot = self->rot;
        for (i = 0; i < 3; i++) {
            rot.z += 0x2aab;
            if (func_ov000_0219aae8(self, self, 1, 0x10, 0x80, NULL, &rot, 0x4400, 0x3c000, -1, 0x1000)) {
                any = TRUE;
            }
            rot.z += 0x2aab;
        }
        if (any) {
            self->unk_ce_u++;
        }
        break;
    }
}

}
