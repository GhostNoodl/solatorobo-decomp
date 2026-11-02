#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "ov000/ActorMarker.h"

extern "C" {

void *ResSet_ReleaseAll(void *p);

void ActorMarker_Draw(ActorMarker *self) {
    ActorMarkerFn fn = self->draw;
    if (fn != NULL) {
        fn(self);
    }
}

void func_ov000_021bd7b8(ActorMarker *self) {
    s32 i;
    HEAP_DELETE_FN(self->res, ResSet_ReleaseAll);
    for (i = 0; i < 4; i++) {
        self->mdl[i] = NULL;
    }
    for (i = 4; i < 8; i++) {
        HEAP_DELETE_MODEL(self->mdl[i]);
    }
    self->step = 10;
    self->nextKind = -1;
    self->flags &= ~8;
}

}
