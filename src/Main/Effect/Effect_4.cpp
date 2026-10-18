#include "Main/Effect/Effect.h"

extern "C" {

void func_02065eec(EffectMgr *m) {
    m->head2 = m->head;
    m->count2 = m->count;
    m->head = NULL;
    m->count = 0;
}

void func_02065f0c(EffectMgr *m) {
    EffectMgr_Clear(m);
    m->head = m->head2;
    m->count = m->count2;
    m->head2 = NULL;
    m->count2 = 0;
}

}
