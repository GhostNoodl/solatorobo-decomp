#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern Actor *func_ov000_0219be1c(s32 kind, const VecFx32 *pos, const void *rot, u16 owner, u16 target);
extern void func_ov000_0218d46c(Actor *p, u16 id, s32 v);

void func_ov003_021d6868(Ov003Actor *self, u16 color) {
    Model0218fe1c *a = self->model;
    s32 i;
    a->color = color;
    a->color2 = color;
    a->blend = 2;
    a->blendMax = 1;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->models[i];
        if (a != NULL) {
            a->color = color;
            a->color2 = color;
            a->blend = 2;
            a->blendMax = 1;
        }
    }
}

void func_ov003_021d68e0(Ov003Actor *self, u16 color, u16 color2, u16 frames) {
    Model0218fe1c *a = self->model;
    s32 i;
    a->color = color;
    a->color2 = color2;
    a->blend = frames + 1;
    a->blendMax = frames;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->models[i];
        if (a != NULL) {
            a->color = color;
            a->color2 = color2;
            a->blend = frames + 1;
            a->blendMax = frames;
        }
    }
}

void func_ov003_021d6954(Ov003Actor *self, u8 alpha) {
    Model0218fe1c *a = self->model;
    s32 i;
    a->alpha = alpha;
    if (self->unk_d0 == NULL) {
        return;
    }
    if (self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        a = self->unk_d0->models[i];
        if (a != NULL) {
            a->alpha = alpha;
        }
    }
}

Actor *func_ov003_021d69a0(Actor *self, s32 kind, s32 v) {
    Actor *p = func_ov000_0219be1c(kind, &self->pos, &self->rot_x, 0xffff, 0xffff);
    if (p != NULL && v != 0) {
        func_ov000_0218d46c(p, self->id, v);
    }
    return p;
}

Actor *func_ov003_021d69f0(Ov003Actor *self, s32 kind, const VecFx32 *pos, const void *rot, Actor *other) {
    u16 o = 0xffff;
    Actor *p;
    if (other != NULL) {
        o = other->id;
    }
    p = func_ov000_0219be1c(kind, pos, rot, self->id, o);
    if (p != NULL) {
        self->target_id = p->id;
    }
    return p;
}

}
