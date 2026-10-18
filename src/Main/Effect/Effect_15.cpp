#include "Main/Effect/Effect.h"

extern "C" {

extern void MTX_Identity33_(void *mtx);
extern BOOL func_0206b1cc(EffectEmitter *em);
extern EffectPtcl *func_0206b81c(EffectEmitter *em);

void func_0206b744(EffectEmitter *em) {
    MIi_CpuClear32(0, &em->params, sizeof(em->params));
    em->params.duration = 0;
    em->params.unk_34 = 0;
    em->emitTime = 0;
    MTX_Identity33_(em->mtx);
}

}
