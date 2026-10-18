#include "Main/Effect/Effect.h"

extern "C" {

BOOL func_0206b804(EffectEmitter *em) {
    s32 t = em->time;
    if (t < 0) {
        t = 0;
    }
    em->emitTime = t;
    return TRUE;
}

}
