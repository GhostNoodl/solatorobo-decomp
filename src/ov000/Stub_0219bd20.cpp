#include "ov000/Actor.h"

extern "C" {

ActorGroup *func_ov000_0218e4cc(ActorMgr *mgr, u16 kind);

void func_ov000_0219bd20(u16 kind, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    ActorGroup *group = func_ov000_0218e4cc(data_ov000_021ccd68, kind);
    Actor *actor;
    if (group == NULL || (actor = group->head) == NULL) {
        return;
    }
    for (; actor != NULL; actor = actor->next) {
        if (kind == actor->kind && id != actor->id) {
            func_ov000_0218d398(actor, id, type, notify, size, data);
        }
    }
}

}
