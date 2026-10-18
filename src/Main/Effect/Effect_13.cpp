#include "Main/Effect/Effect.h"

extern "C" {

BOOL func_0206aad4(EffectPartSet *s, EffectPartSlot *slot) {
    EffectPtcl *p;
    s32 rate = slot->rate;
    for (p = s->ptcls; p != NULL; p = p->next) {
        p->speed += rate;
    }
    return TRUE;
}

BOOL func_0206ab04(EffectPartSet *s, EffectPartSlot *slot) {
    return FALSE;
}

}
