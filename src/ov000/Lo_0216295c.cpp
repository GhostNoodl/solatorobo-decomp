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
void MTX_FrustumW(s32 t, s32 b, s32 l, s32 r, s32 n, s32 f, s32 scaleW, void *mtx);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);

void func_ov000_0216295c(u8 *self, const VecFx32 *v, s32 s) {
    s32 y = v->y;
    s32 x = v->x;
    LFLD(s32, self, 0x6a8) = x;
    LFLD(s32, self, 0x6ac) = y;
    LFLD(s32, self, 0x6b0) = v->z;
    LFLD(s32, self, 0x6b4) = s;
    MTX_FrustumW(LO_FX_MUL(y + 0xf5c, s), LO_FX_MUL(y - 0xf5c, s), LO_FX_MUL(x - 0x147b, s), LO_FX_MUL(x + 0x147b, s), 0x1000, 0x1e000, 0x1000, self + 0x668);
}


}
