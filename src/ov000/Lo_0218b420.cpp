#include "ov000/Group.h"

extern "C" {

// Rebuilds the spawn and despawn volumes around the node from the ranges and heights; without
// useRange / useHeight the spawn volume is unlimited on those axes.
void func_ov000_0218b420(GroupNode *self) {
    s32 na, a, nb, b, c, nc, y;
    if (!self->flags.useHeight) {
        na = 0x80000000;
        a = 0x7fffffff;
    } else {
        a = self->spawnHeight;
        na = -a;
    }
    if (!self->flags.useRange) {
        nb = 0x80000000;
        b = 0x7fffffff;
    } else {
        b = self->spawnRange;
        nb = -b;
    }
    self->spawnMin.y = na;
    self->spawnMax.y = a;
    self->spawnMin.x = nb;
    if (!self->flags.useHeight) {
        nc = 0x80000000;
        c = 0x7fffffff;
    } else {
        c = self->despawnHeight;
        nc = -c;
    }
    y = self->despawnRange;
    self->despawnMin.y = nc;
    self->spawnMin.z = nb;
    self->spawnMax.x = b;
    self->spawnMax.z = b;
    self->despawnMin.x = -y;
    self->despawnMin.z = -y;
    self->despawnMax.x = y;
    self->despawnMax.y = c;
    self->despawnMax.z = y;
}
}
