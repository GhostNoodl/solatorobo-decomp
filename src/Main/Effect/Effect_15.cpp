#include "Main/Effect/Effect.h"

extern "C" {

extern BOOL func_0206b1cc(EffectEmitter *em);
extern EffectPtcl *func_0206b81c(EffectEmitter *em);

void EffectEmitter_ResetParams(EffectEmitter *em) {
    MIi_CpuClear32(0, &em->params, sizeof(em->params));
    em->params.duration = 0;
    em->params.unk_34 = 0;
    em->emitTime = 0;
    MTX_Identity33_(&em->mtx);
}


static inline void EffectEmitter_AddPtcl(EffectEmitter *em, EffectPtcl *p) {
    if (p != NULL) {
        if (em->ptcls == NULL) {
            em->ptcls = p;
        } else {
            EffectPtcl *last = p;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = em->ptcls;
            em->ptcls->prev = last;
            em->ptcls = p;
        }
    }
}

BOOL MainVt_0208c8bc_Step(EffectEmitter *em) {
    BOOL ret;
    BOOL alive;
    EffectEmitter_AddPtcl(em, func_0206b81c(em));
    ret = em->loopCount == -2 ? TRUE : (em->time < em->params.duration ? TRUE : FALSE);
    alive = func_0206b1cc(em);
    return (ret | alive) != 0;
}

}
