#include "ov000/VObj.h"
#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
    u8 b0, b1, b2, b3;
    u16 h4, h6, h8, ha;
    s32 wc;
} S0219bebc;
static inline void SetS(S0219bebc *p, S0219bebc v) {
    *p = v;
}

extern "C" {
void func_ov000_0215eab4(void *p);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);

struct Obj0216295c {
    u8 unk_00[0x668];
    MtxFx44 unk_668;
    s32 unk_6a8;
    s32 unk_6ac;
    s32 unk_6b0;
    s32 unk_6b4;
};

void func_ov000_0216295c(Obj0216295c *self, const VecFx32 *v, s32 s) {
    s32 y = v->y;
    s32 x = v->x;
    self->unk_6a8 = x;
    self->unk_6ac = y;
    self->unk_6b0 = v->z;
    self->unk_6b4 = s;
    MTX_FrustumW(LO_FX_MUL(y + 0xf5c, s), LO_FX_MUL(y - 0xf5c, s), LO_FX_MUL(x - 0x147b, s), LO_FX_MUL(x + 0x147b, s), 0x1000, 0x1e000, 0x1000, &self->unk_668);
}


}
