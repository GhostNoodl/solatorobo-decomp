#include "ov000/ActorMgr.h"

extern "C" {

static inline Actor *Find0218d2e0(ActorMgr *mgr, u16 id) {
    Actor *res = NULL;
    ActorGroup *grp;
    ActorGroup *p;
    Actor *a;
    u16 g;
    if (id != 0xffff) {
        g = id & 0xf000;
        p = mgr->head;
        grp = NULL;
        if (g == 0xf000) {
            grp = p;
        } else {
            for (; p != NULL; p = p->next) {
                if (p->key == g) {
                    grp = p;
                    break;
                }
            }
        }
        if (grp != NULL) {
            for (a = grp->head; a != NULL; a = a->next) {
                if (id == a->id) {
                    res = a;
                    break;
                }
            }
        }
    }
    return res;
}

// The unk_44 block of the actor's target.
ActorSub44 *func_ov000_0218d2e0(Actor *self) {
    u16 id = self->target;
    ActorMgr *mgr = data_ov000_021ccd68;
    ActorSub44 *r = NULL;
    Actor *found;
    if (mgr != NULL) {
        found = Find0218d2e0(mgr, id);
    } else {
        found = NULL;
    }
    if (found != NULL) {
        r = found->unk_44;
    }
    return r;
}
}
