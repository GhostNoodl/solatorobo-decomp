#include "ov002/ov002.h"

extern "C" {

void Obj021eff10_Exit(Obj021eff10 *self, Obj021eff50 *other) {
    Obj021efe6c *board = other->board;
    s32 row = self->unk_28;
    Obj021efe4c *q = board->field;
    s32 col = self->unk_24;
    Ov002Cell *base;
    Ov002Cell *e;
    if (q == NULL || (base = board->cells) == NULL) {
        e = NULL;
    } else {
        e = &base[row * q->map->h + col];
    }
    if (e->unk_2 == 1) {
        Obj021efe9c *t = (Obj021efe9c *)e->obj;
        t->unk_cd = 0;
        t->unk_9c = 0xf85;
    }
    other->unk_28 = self->unk_24;
    other->unk_2c = self->unk_28;
    Obj021eff10_Release(self);
}

}
