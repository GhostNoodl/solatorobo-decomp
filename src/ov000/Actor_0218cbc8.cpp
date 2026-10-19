#include "ov000/Actor.h"

typedef struct {
    u8 pad[0x9a];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 rest : 9;
} Body0218cbc8;

extern "C" {

void func_ov000_0218d77c(Actor *self);

static inline void Group_Remove(ActorGroup *group, Actor *actor) {
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

void func_ov000_0218cbc8(Actor *self) {
    switch (self->state) {
    case 1:
        if (!self->vfunc_0c()) {
            break;
        }
        self->state = 2;
        self->vfunc_28();
        if (self->state != 2) {
            break;
        }
    case 2:
        if (*(void **)((u8 *)self + 0x48) != NULL) {
            Body0218cbc8 *b = *(Body0218cbc8 **)((u8 *)self + 0x48);
            b->b3 = b->b0;
            b->b4 = b->b1;
            b->b5 = b->b2;
            b->b6 = 1;
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *s = (ActorSub44 *)self->unk_44;
            s->unk_22_1 = s->unk_22_0;
        }
        func_ov000_0218d77c(self);
        self->unk_94[0] = 0;
        switch (self->unk_15) {
        case 1:
            self->vfunc_34();
            break;
        case 2:
            self->vfunc_2c();
            break;
        case 3:
            self->vfunc_30();
            break;
        }
        self->vfunc_38();
        self->vfunc_3c();
        self->vfunc_40();
        self->vfunc_44();
        self->vfunc_48();
        break;
    case 3:
        Group_Remove(ActorMgr_FindGroup(self->id & 0xf000), self);
        break;
    }
    *(u32 *)((u8 *)self + 0x30) = 0;
}

}
