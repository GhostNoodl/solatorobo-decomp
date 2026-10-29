#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218cfc8(Actor *self) {
    BOOL busy;
    ActorGroup *group;
    u16 key;
    ActorGroup *g2;
    Actor *next;
    Actor *prev;
    if (!self->flags_0) {
        return;
    }
    busy = FALSE;
    if (self->unk_4c != NULL && self->unk_4c->unk_1c != 0xffff && self->unk_4c->unk_1c != self->id) {
        if (self->unk_20 != 0xffff || self->flags_1) {
            Actor *ret;
            u16 id = self->unk_4c->unk_1c;
            // FindActor with an early `return NULL` for a missing manager: each arm sets its own
            // NULL, and the post-RA head merge lifts the shared `mov r1, #0` above the test.
            if (data_ov000_021ccd68 == NULL) {
                ret = NULL;
            } else {
                ret = NULL;
                if (id != 0xffff) {
                    key = id & 0xf000;
                    g2 = NULL;
                    group = data_ov000_021ccd68->head;
                    if (key == 0xf000) {
                        g2 = group;
                    } else {
                        for (; group != NULL; group = group->next) {
                            if (group->key == key) {
                                g2 = group;
                                break;
                            }
                        }
                    }
                    if (g2 != NULL) {
                        for (prev = g2->head; prev != NULL; prev = prev->next) {
                            if (id == prev->id) {
                                ret = prev;
                                break;
                            }
                        }
                    }
                }
            }
            if (ret != NULL) {
                busy = TRUE;
            }
        }
    }
    if (busy) {
        return;
    }
    func_ov000_0218bed8(data_ov000_021ccd64, 2, self);
    group = ActorMgr_FindGroup(self->id & 0xf000);
    prev = self->prev;
    next = self->next;
    if (self != NULL) {
        self->vfunc_24();
    }
    if (prev != NULL) {
        prev->next = next;
    } else {
        group->head = next;
    }
    if (next != NULL) {
        next->prev = prev;
    } else {
        group->tail = prev;
    }
    group->count--;
}


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
