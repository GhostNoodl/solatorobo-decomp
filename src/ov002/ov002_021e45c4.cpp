#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e4578(const Vec2 *pos, const Vec2 *d, Ov002Shape *a, Ov002Shape *b) {
    Vec2 p;
    Vec2 out;
    p.x = pos->x + d->x;
    p.y = pos->y + d->y;
    return !func_ov002_021e3dac(&p, a, b, &out);
}

BOOL func_ov002_021e45c4(Obj021efeb8 *self, Obj021efeb8 *list, Ov002Shape *a2) {
    Vec2 p;
    Vec2 q;
    p.x = self->unk_54;
    p.y = self->unk_58;
    if (func_ov002_021e3dac(&p, a2, &self->shape, NULL)) {
        return TRUE;
    }
    for (; list != NULL; list = list->next) {
        if (list == self) {
            continue;
        }
        q.x = list->unk_54;
        q.y = list->unk_58;
        if (func_ov002_021e41cc(&p, &q, &self->shape, &list->shape, 0)) {
            return TRUE;
        }
    }
    return FALSE;
}

}
