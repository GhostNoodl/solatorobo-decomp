#include "ov000/Actor.h"

extern "C" {

void func_ov000_0218df68(ActorGroup *group, Actor *actor) {
    Actor *prev = actor->prev;
    Actor *next = actor->next;
    if (actor != NULL) {
        actor->vfunc_24();
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

u16 func_ov000_0218dfb4(ActorGroup *group, u16 kind) {
    Actor *actor = group->head;
    u16 n = 0;
    if (actor == NULL) {
        return n;
    }
    do {
        if (kind == actor->kind) {
            n++;
        }
        actor = actor->next;
    } while (actor != NULL);
    return n;
}

void func_ov000_0218dfe8(ActorGroup *group, u16 id, u8 type, BOOL notify, u32 size, const void *data) {
    Actor *actor = group->head;
    if (actor == NULL) {
        return;
    }
    do {
        func_ov000_0218d398(actor, id, type, notify, size, data);
        actor = actor->next;
    } while (actor != NULL);
}

void func_ov000_0218e044(ActorGroup *group, u16 kind, s32 value) {
    Actor *actor = group->head;
    u8 buf;
    if (actor == NULL) {
        return;
    }
    do {
        if (kind == 0xffff || kind == actor->kind) {
            buf = value;
            func_ov000_0218d398(actor, 0xffff, 2, 1, 1, &buf);
        }
        actor = actor->next;
    } while (actor != NULL);
}

void func_ov000_0218e0bc(ActorGroup *group) {
    Actor *actor = group->head;
    if (actor == NULL) {
        return;
    }
    do {
        actor->vfunc_1c();
        actor = actor->next;
    } while (actor != NULL);
}

}
