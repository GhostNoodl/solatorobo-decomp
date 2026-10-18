#include "ov000/Actor.h"

extern "C" {

BOOL func_ov000_0218d17c(Actor *self) {
    return self->state == 2;
}

void func_ov000_0218d190(Actor *self) {
    func_ov000_0218d398(self, 0xffff, 1, 1, 0, NULL);
}

void func_ov000_0218d1c0(Actor *self, u16 id, u16 kind, s32 arg) {
    ActorGroup *group;
    self->kind = kind;
    self->unk_10 = arg;
    group = ActorMgr_FindGroup(id);
    if (group == NULL) {
        return;
    }
    func_ov000_0218de6c(group, self);
    self->pause.parent = &group->pause;
}

Actor *func_ov000_0218d240(Actor *self) {
    return ActorMgr_FindActor(self->target);
}

}
