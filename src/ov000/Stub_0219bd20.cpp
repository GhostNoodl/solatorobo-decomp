#include "ov000/Actor.h"

extern "C" {

ActorGroup *ActorMgr_GetGroup(ActorMgr *mgr, u16 kind);

void func_ov000_0219bd20(u16 kind, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    ActorGroup *group = ActorMgr_GetGroup(data_ov000_021ccd68, kind);
    Actor *actor;
    if (group == NULL || (actor = group->head) == NULL) {
        return;
    }
    for (; actor != NULL; actor = actor->next) {
        if (kind == actor->kind && id != actor->id) {
            Actor_SendMsg(actor, id, type, notify, size, data);
        }
    }
}

}
