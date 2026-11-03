#include "ov000/VObj.h"

typedef struct ActorMgr ActorMgr;

extern "C" {

extern u8 data_ov000_021ca1f8[];
extern ActorMgr *gActorMgr;

void *ActorMgr_FindKind(ActorMgr *mgr, u16 id, u16 kind);

void *func_ov000_0219bf7c(void) {
    return data_ov000_021ca1f8;
}

s32 func_ov000_0219bf88(void) {
    return 0x14;
}

void *ActorMgr_FindPlayer(void) {
    ActorMgr *mgr = gActorMgr;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_FindKind(mgr, 0x1000, 0x1000);
}

}
